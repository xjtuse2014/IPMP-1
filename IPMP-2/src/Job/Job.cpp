/*
 * Job.cpp
 *
 *  Created on: 2015年9月20日
 *      Author: syq
 */

#include "Job.h"

Job::Job() {
	// TODO Auto-generated constructor stub

}

Job::~Job() {
	// TODO Auto-generated destructor stub

}

int Job::StartJob(){
	signal(SIGCHLD, SIG_IGN);
		if((sockfd = socket(AF_INET, SOCK_STREAM, 0))==-1){
			perror("1:建立socke失败！\n");
			exit(1);
		}
//		printf("建立服务器socket成功!\n");
		my_addr.sin_family = AF_INET;
		my_addr.sin_port = htons(8000);
		inet_aton("202.117.10.82", &my_addr.sin_addr);
//		bzero(&(my_addr.sin_zero),8);
		if(bind(sockfd, (struct sockaddr*) &my_addr, sizeof(my_addr))==-1){
			perror("2：绑定失败!\n");
			exit(1);
		}
//		printf("绑定成功！\n");
		if( listen(sockfd, 10 ) == -1){
			perror("监听失败！\n");
			exit(1);
		}
//		printf("监听成功！\n");
		while (true) {
			socklen_t len;
			if((client_fd = accept(sockfd, (struct sockaddr*) &remote_addr, &len)) == -1){
				perror("accept error!\n");
				exit(1);
			}else{
				pthread_t thread_id;
				len = sizeof(remote_addr);
				printf("somebody connected:%d,IP:%s, PORT:%u\n", client_fd,inet_ntoa(remote_addr.sin_addr),ntohs(remote_addr.sin_port));
				pthread_create(&thread_id, NULL, WorkThread, &client_fd);
				cout<<"thread_id:"<<thread_id<<endl;
				pthread_join(thread_id, NULL);
			}
		}
	return 0;
}

void* Job::WorkThread(void* connect_fd){
	cout << "connect..." << endl;
	int conn_fd = *(int*) connect_fd;
	char buff[4096],utf8buff[4096];
	int n = recv(conn_fd, buff, 4096, 0);
	buff[n] = '\0';
	printf("recv msg from client: %s\n", buff);
	Utils util;
	util.gb2312toutf8(buff, n, utf8buff, 4096);
	printf("recv msg from client: %s\n", utf8buff);
	string receive(utf8buff);
	Json::Reader reader;
	Json::Value value;

	int object;
	if (reader.parse(receive, value)) {
		object = value["m_object"].asInt();
	}

	switch(object)
	{
	case 0:{
		Facility fac;
		FacilityService fs;
		fac=fs.GetParasFRomJson(receive);
		if(fac.getOp()=="selectFacility"){
			string res=fs.SelectAll();
			send(conn_fd, res.c_str(), (unsigned int) strlen(res.c_str()), 0);
			cout<<"the res is :"<<res<<endl;
		}
	}
	break;
	case 1:
	{
		User user;
		UserService us;
		user=us.GetParasFRomJson(receive);
		if(user.getOp()==SELECT_ALL_USER){
			string res=us.SelectAll();
			send(conn_fd, res.c_str(), (unsigned int) strlen(res.c_str()), 0);
		}else if(user.getOp()==SELECT_SINGLE_USER){
			string res=us.SelectSignle(user.getId());
			send(conn_fd, res.c_str(), (unsigned int) strlen(res.c_str()), 0);
		}else if(user.getOp()==UPDATE_USER){
			if(us.Update(user)==0){
				send(conn_fd, "300", 26, 0);
			}else{
				send(conn_fd, "301", 26, 0);
			}
		}else if(user.getOp()==DELETE_USER){
			int res=us.DeleteSignle(user.getId());
			char buff[20];
			memset(buff,0,20);
			sprintf(buff,"%d",res);
			send(conn_fd, buff, 26, 0);
		}else if(user.getOp()==ADD_USER){
			int res=us.Add(user);
			char buff[20];
			memset(buff,0,20);
			sprintf(buff,"%d",res);
			send(conn_fd, buff, 26, 0);
		}
	}
		break;

	case 2:
	{
		AdminService as;
		Admin admin;
		admin=as.GetParasFRomJson(receive);
		if(admin.getOp()==LOGIN){
			char buff[20];
			memset(buff,0,20);
			int res=as.LoginSys(admin.getId(),admin.getPsd());
			sprintf(buff,"%d",res);
			send(conn_fd, buff, 26, 0);//重复
		}
	}
		break;
}
}
