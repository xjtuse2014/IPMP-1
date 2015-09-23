/*
 * AdminService.cpp
 *
 *  Created on: 2015年9月22日
 *      Author: syq
 */

#include "AdminService.h"

AdminService::AdminService() {
	// TODO Auto-generated constructor stub

}

AdminService::~AdminService() {
	// TODO Auto-generated destructor stub
}
/**
 * return 100;//登录成功
 * return 101;//登录失败 ：密码错误
 * return 102;//登录失败：ID不存在
 */
int AdminService::LoginSys(string a_id,string a_psd){
	DBConn db;
	string sql="select a_psd from admin where a_id="+Utils::AddSingleQuoteMark(a_id);
	string res=db.Query_mysql(sql);
	if(res.empty()==true){
		return 102;
	}else if(res==a_psd){
		return 100;
	}else{
		return 101;
	}
}

Admin AdminService::GetParasFRomJson(string jsonString){
	Json::Reader reader;
		Json::Value root;
		Admin admin;
		if(reader.parse(jsonString,root)){
			admin.setOp(root["m_op"].asString());
			admin.setPsd(root["a_psd"].asString());
			admin.setId(root["a_id"].asString());
			admin.setPriority(root["a_priority"].asString());
			admin.setName(root["a_name"].asString());
		}
		return admin;
}

int AdminService::AddAdmin(Admin admin){
	string sql="insert into admin(a_id,a_name,a_psd,a_priority)values('"+admin.getId()+"','"+admin.getName()+"','"+admin.getPsd()+"','"+admin.getPriority()+"')";
}
