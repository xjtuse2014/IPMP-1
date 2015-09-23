/*
 * Job.cpp
 *
 *  Created on: 2015年9月20日
 *      Author: syq
 */

#include "Job.h"
#include "../utils/constant.h"
#include "../bean/User.h"
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
	case 1:
	{
		User user;
		UserService us;
		user=us.GetParasFRomJson(receive);
//		cout<<"user:"<<user.getPhone()<<endl;
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
/*
	if (op == "login") {
		DBConn* conn = new DBConn();
		string s1 = "select m_psd from ipmp_user where m_name='" + name + "'";
		string res = conn->Query_mysql(s1);
		conn->Close_mysql();
		if (conn != NULL) {
			delete conn;
			conn = NULL;
		}
		cout << "res:" << res << endl;
		if (res == psd) {
			//login succeed
			send(conn_fd, "100\n", 52, 0);
			cout << "return:100" << endl;
		} else {
			//login failed
			send(conn_fd, "101\n", 52, 0);
			cout << "return:101" << endl;
		}
	} else if (op == "addUser") {
		DBConn conn;
		string s1 =
				"insert into ipmp_user(m_name,m_psd,m_department,m_phone)values('"
						+ name + "','" + psd + "','" + department + "','"
						+ phone + "')";
		// check if the new user exists
		cout << "addUser sql:" << s1 << endl;
		int r = conn.Insert_mysql(s1);
		if (r == 0) {
			send(conn_fd, "200", 52, 0);
		} else {
			send(conn_fd, "201", 52, 0);
		}
		conn.Close_mysql();
	} else if (op == "selectUser") {
		DBConn db;
		string sql = "select u_id,u_nameu from user ";
		string result = db.Query_all_mysql(sql);
		cout << "result:" << result << endl;
		db.Close_mysql();
		cout << "length:" << (unsigned int) strlen(result.c_str()) << endl;
		send(conn_fd, result.c_str(), (unsigned int) strlen(result.c_str()), 0);
	} else if (op == "updateUser") {
		DBConn db;
		// update t1 set age=100 where name='wa';
		string sql = "update ipmp_user set m_phone='"+ phone + "',m_authority='" + authority + "',m_department='"+ department + "' where m_name='"+name+"'";
		cout<<"updateUser sql:"<<sql<<endl;
		int rc = db.Execute_mysql(sql);
		if (rc == 0) {
			//更新成功
			send(conn_fd, "300", 26, 0);
		} else {
			//更新失败
			send(conn_fd, "301", 26, 0);
		}
	} else if (op == "deleteUser") {
		DBConn db;
		// update t1 set age=100 where name='wa';
		string sql = "delete from ipmp_user where m_name='" + name + "'";
		int rc = db.Execute_mysql(sql);
		if (rc == 0) {
			//更新成功
			send(conn_fd, "400", 26, 0);
			cout << "删除了一个用户：" << endl;
		} else {
			//更新失败
			send(conn_fd, "401", 26, 0);
		}
	}else if(op=="selectSUser"){
		DBConn db;
		string result = db.Query_single_mysql(name);
		send(conn_fd, result.c_str(), (unsigned int) strlen(result.c_str()), 0);
		cout<<"selectSUser:"<<result<<endl;
		db.Close_mysql();
	}
	*/
}
