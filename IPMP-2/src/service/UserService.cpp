/*
 * UserService.cpp
 *
 *  Created on: 2015年9月20日
 *      Author: syq
 */

#include "UserService.h"

UserService::UserService() {
	// TODO Auto-generated constructor stub

}

UserService::~UserService() {
	// TODO Auto-generated destructor stub
}

string UserService::SelectSignle(string u_id){
	DBConn db;
	string sql=SELECT_SINGLE_USER_SQL+Utils::AddSingleQuoteMark(u_id);
	string res=db.Query_single_mysql(sql);
	db.Close_mysql();
	return res;
}

User UserService::GetParasFRomJson(string json){
		Json::Reader reader;
		Json::Value root;
		User user;
		if(reader.parse(json,root)){
//			cout<<"json parser for user:"<<json<<endl;
			 user.setOp(root["m_op"].asString());
			 user.setId(root["u_id"].asString());
			 user.setDepartment(root["u_department"].asString());
			 user.setGender(root["u_gender"].asString());
			 user.setName(root["u_name"].asString());
			 user.setPhone(root["u_phone"].asString());
	    }

		return user;
}

int UserService::Add(User user){

	int tmp=this->SelectUserExist(user.getId());
	if(tmp==0){
		string sql="insert into user(u_id,u_name,u_department,u_phone,u_gender)values('"+ user.getId() + "','" +user.getName()+ "','" + user.getDepartment() +
						"','"+user.getPhone() +"','"+user.getGender()+ "')";
			DBConn db;
			if(db.Execute_mysql(sql)==0){
				db.Close_mysql();
				return 200; //添加成功
			}
			db.Close_mysql();
			return 201;//添加失败
	}else{
		return 202;//添加失败：ID重复
	}


}
string UserService::SelectAll(){
	DBConn db;
	string res=db.Query_all_mysql(SELECT_ALL_USER_SQL,"Users");
	db.Close_mysql();
	return res;
}
int UserService::Update(User user){

	string sql = "update user set u_name='"+ user.getName() + "',u_phone='" + user.getPhone() + "',u_department='"+ user.getDepartment() + "',u_gender='"+user.getGender()+"' where u_id='"+user.getId()+"'";
	cout<<"update sql:"<<sql<<endl;
	DBConn db;
	if(db.Execute_mysql(sql)==0){
		db.Close_mysql();
		return 0;
	}else{

		db.Close_mysql();
		return -1;
	}
}

int UserService::DeleteSignle(string u_id){
	string sql="delete from user where u_id="+Utils::AddSingleQuoteMark(u_id);
	DBConn db;
	if(db.Execute_mysql(sql)==0){
		db.Close_mysql();
			return 400;
	}else{
		db.Close_mysql();
			return 401;
	}

}

int UserService::SelectUserExist(string u_id){
	DBConn db;
	string sql="select u_name from user where u_id='"+u_id+"'";
	string res=db.Query_mysql(sql);
	if(res.empty()==true){
		cout<<"无重复，可插入！"<<endl;
		return 0;
	}
	cout<<"重复，不可插入！"<<endl;
	return -1;
}
