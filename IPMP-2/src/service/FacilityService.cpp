/*
 * FacilityService.cpp
 *
 *  Created on: 2015年9月23日
 *      Author: syq
 */

#include "FacilityService.h"

FacilityService::FacilityService() {
	// TODO Auto-generated constructor stub

}

FacilityService::~FacilityService() {
	// TODO Auto-generated destructor stub
}

Facility FacilityService::GetParasFRomJson(string json){
			Json::Reader reader;
			Json::Value root;
			Facility facility;
			if(reader.parse(json,root)){
				facility.setOp(root["m_op"].asString());
				facility.setFacilityId(root["facility_id"].asString());
				facility.setAvailableState(root["available_state"].asString());
				facility.setFacilityIp(root["facility_ip"].asString());
				facility.setMeetroomId(root["meetroom_id"].asString());
				facility.setFacilityName(root["facility_name"].asString());
			}
			return facility;
}

int FacilityService::Add(Facility fac){
	string sql="insert into facility(facility_id,facility_name,available_state,meetroom_id,facility_ip)values('"+fac.getFacilityId()+"','"+fac.getFacilityName()+"','"+fac.getAvailableState()+"','"+fac.getMeetroomId()+"','"+fac.getFacilityIp();
	int check=this->SelectFacilityExist(fac.getFacilityId(),fac.getFacilityIp());
	DBConn db;
	if(check==500){
		db.Execute_mysql(sql);
		return 500;
	}else if(check==501){
		return 501;
	}else{
		return 502;
	}
}
string FacilityService::SelectAll(){
	DBConn db;
	string sql="select * from facility";
	string res=db.Query_all_mysql(sql,"Facility");
	return res;
}
int FacilityService::SelectFacilityExist(string id,string ip){
	string sql="select  facility_name from facility where facility_id="+Utils::AddSingleQuoteMark(id);
	string sql1="select  facility_id from facility where facility_ip="+Utils::AddSingleQuoteMark(ip);
	DBConn db;
	string res_name=db.Query_mysql(sql);
	string res_id=db.Query_mysql(sql1);
	db.Close_mysql();
	if(res_id.empty()==false){//查看该IP是否被占用
		if(res_name.empty()==true){//查看该ID是否存在
			return 500;//可以添加
		}else{
			return 502;//该ID已存在
		}
	}else{
		return 501;//IP被占用
	}
}

int FacilityService::Update(Facility fac){
	string sql="";
	return 0;
}
