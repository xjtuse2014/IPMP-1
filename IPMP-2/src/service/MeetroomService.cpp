/*
 * MeetroomService.cpp
 *
 *  Created on: 2015年9月28日
 *      Author: syq
 */

#include "MeetroomService.h"

MeetroomService::MeetroomService() {
	// TODO Auto-generated constructor stub

}

MeetroomService::~MeetroomService() {
	// TODO Auto-generated destructor stub
}


string MeetroomService::SelectSignle(string mr_id){
	DBConn db;
	string sql=SELECT_SINGLE_MR_SQL+Utils::AddSingleQuoteMark(mr_id);
	string res=db.Query_single_mysql(sql);
	db.Close_mysql();
	return res;
}

Meetroom MeetroomService::GetParasFRomJson(string json){
		Json::Reader reader;
		Json::Value root;
		Meetroom mr;
		if(reader.parse(json,root)){
				mr.setAvailableState(root["available_state"].asString());
				mr.setMeetNum(root["meet_num"].asString());
				mr.setMeetroomAddr(root["meetroom_addr"].asString());
				mr.setMeetroomId(root["meetroom_id"].asString());
				mr.setMeetroomName(root["meetroom_name"].asString());
	    }
		return mr;
}

int MeetroomService::Add(Meetroom mr){

	int tmp=this->SelectMeetroomExist(mr.getMeetroomId());
	if(tmp==0){
		string sql=ADD_MR_SQL+ mr.getMeetroomId() + "','" +mr.getMeetroomName()+ "','" +mr.getMeetroomAddr() +
						"','"+mr.getAvailableState() +"','"+mr.getMeetNum()+ "')";
			DBConn db;
			if(db.Execute_mysql(sql)==0){
				db.Close_mysql();
				return 400; //添加成功
			}
			db.Close_mysql();
			return 402;//添加失败
	}else{
		return 401;//ID重复
	}


}
string MeetroomService::SelectAll(){
	DBConn db;
	string res=db.Query_all_mysql(SELECT_ALL_MR_SQL,"Meetrooms");
	db.Close_mysql();
	return res;
}
int MeetroomService::Update(Meetroom mr){

	string sql = "update meetroom set meetroom_name='"+ mr.getMeetroomName() + "',meetroom_addr='" + mr.getMeetroomAddr() + "',available_state='"+ mr.getAvailableState() + "',meet_num='"+mr.getMeetNum()+"' where meetroom_id='"+mr.getMeetroomId()+"'";
	cout<<"update sql:"<<sql<<endl;
	DBConn db;
	if(db.Execute_mysql(sql)==0){
		db.Close_mysql();
		return 420;
	}else{
		db.Close_mysql();
		return 421;
	}
}

int MeetroomService::DeleteSignle(string mr_id){
	string sql="delete from meetroom where meetroom_id="+Utils::AddSingleQuoteMark(mr_id);
	DBConn db;
	if(db.Execute_mysql(sql)==0){
		db.Close_mysql();
			return 410;
	}else{
		db.Close_mysql();
			return 411;
	}

}

int MeetroomService::SelectMeetroomExist(string mr_id){
	DBConn db;
	string sql=SELECT_MR_ID_SQL+Utils::AddSingleQuoteMark(mr_id);
	string res=db.Query_mysql(sql);
	if(res.empty()==true){
		cout<<"无重复，可插入！"<<endl;
		return 0;
	}
	cout<<"重复，不可插入！"<<endl;
	return -1;
}
