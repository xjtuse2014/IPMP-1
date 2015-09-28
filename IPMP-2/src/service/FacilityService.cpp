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

Facility FacilityService::GetParasFRomJson(string json) {
	Json::Reader reader;
	Json::Value root;
	Facility facility;
	if (reader.parse(json, root)) {
		facility.setOp(root["m_op"].asString());
		facility.setFacilityId(root["facility_id"].asString());
		facility.setAvailableState(root["available_state"].asString());
		facility.setFacilityIp(root["facility_ip"].asString());
		facility.setMeetroomId(root["meetroom_id"].asString());
		facility.setFacilityName(root["facility_name"].asString());
	}
	return facility;
}

int FacilityService::Add(Facility fac) {
	string sql =
			"insert into facility(facility_id,facility_name,available_state,meetroom_id,facility_ip)values('"
					+ fac.getFacilityId() + "','" + fac.getFacilityName()
					+ "','" + fac.getAvailableState() + "','"
					+ fac.getMeetroomId() + "','" + fac.getFacilityIp() + "')";
	cout << "addFac sql:" << sql << endl;
	int check = this->SelectFacilityExist(fac.getFacilityId(),
			fac.getFacilityIp(), fac.getMeetroomId());
	cout << "check res is :" << check << endl;
	DBConn db;
	if (check == 300) {
		db.Execute_mysql(sql);
		db.Close_mysql();
		return 300;
	} else if (check == 301) {
		db.Close_mysql();
		return 301;
	} else {
		db.Close_mysql();
		return 302;
	}
}
string FacilityService::SelectAll() {
	DBConn db;
	string sql = "select * from facility";
	string res = db.Query_all_mysql(sql, "Facility");
	return res;
}
/**
 *查询同一个会议室的IP是否有重
 */
int FacilityService::SelectFacilityExist(string id, string ip, string mr_id) {
	string sql = "select  facility_id from facility where facility_id=" + Utils::AddSingleQuoteMark(id);
	cout << "check sql:" << sql << endl;
	string sql1 = "select  meetroom_id from facility where facility_ip="	+ Utils::AddSingleQuoteMark(ip);
	cout << "check sql:" << sql1 << endl;
	DBConn db;
	string facility_id = db.Query_mysql(sql);
	db.Close_mysql();

	if (ip.empty() || mr_id.empty()) {//用户增加一个设备仅填写ID的情况
		cout << "SelectFacilityExist ip.empty() || mr_id.empty()" << endl;
		if (facility_id.empty()) {
			cout<<"SelectFacilityExist():500"<<"facility_id.empty():"<<facility_id.empty()<<endl;
			return 300;
		} else {
			cout<<"SelectFacilityExist():501"<<endl;
			return 301; //ID已存在
		}
	} else {
		cout << "SelectFacilityExist() ----------------------" << endl;
		if (facility_id.empty()) {
			DBConn db;
			string meetroom_id = db.Query_mysql(sql1);
			db.Close_mysql();
			if (meetroom_id == mr_id) {
				cout<<"SelectFacilityExist():502"<<endl;
				return 302; //IP重复
			} else {
				cout<<"SelectFacilityExist():500"<<endl;
				return 300;
			}
		} else {
			return 301; //ID已存在
		}
	}
	/*
	 string sql="select  facility_id from facility where facility_id="+Utils::AddSingleQuoteMark(id);
	 cout<<"check sql:"<<sql<<endl;
	 string sql1="select  meetroom_id from facility where facility_ip="+Utils::AddSingleQuoteMark(ip);
	 cout<<"check sql:"<<sql1<<endl;

	 DBConn db;
	 string facility_id=db.Query_mysql(sql);
	 string res_id=db.Query_mysql(sql1);
	 db.Close_mysql();
	 if(facility_id.empty()){
	 if(res_id!=mr_id){
	 return 500;//同一个会议室内无重复IP，可以插入
	 }else{
	 return 501;//IP 重复
	 }
	 }else{
	 return 502;//ID被用
	 }*/
}

int FacilityService::SelectFacilityExist(string id, string ip) {
	string sql = "select  facility_name from facility where facility_id=" + Utils::AddSingleQuoteMark(id);
	cout << "check sql:" << sql << endl;
	string sql1 = "select  facility_id from facility where facility_ip=" + Utils::AddSingleQuoteMark(ip);
	cout << "check sql:" << sql1 << endl;

	DBConn db;
	string res_name = db.Query_mysql(sql);
	string res_id = db.Query_mysql(sql1);
	db.Close_mysql();
	if (res_id.empty()) { //查看该IP是否被占用
		if (res_name.empty()) { //查看该ID是否存在
			return 300; //可以添加
		} else {
			return 302; //该ID已存在
		}
	} else {
		return 301; //IP被占用
	}
}

//更新设备成功 700 失败701
int FacilityService::Update(Facility fac) {
	string sql = "update facility set facility_name='" + fac.getFacilityName()
			+ "',available_state='" + fac.getAvailableState()
			+ "',meetroom_id='" + fac.getMeetroomId() + "',facility_ip='"
			+ fac.getFacilityIp() + "'where facility_id="+Utils::AddSingleQuoteMark(fac.getFacilityId());
	cout << "update Facility sql:" << sql << endl;
	DBConn db;
	if (db.Execute_mysql(sql) == 0) {
		db.Close_mysql();
		return 320;
	} else
		db.Close_mysql();
	return 321;
}

string FacilityService::SelectSignle(string id) {
	string sql = "select * from facility where facility_id="
			+ Utils::AddSingleQuoteMark(id);
	DBConn db;
	string res = db.Query_single_mysql(sql);
	return res;
}
//删除facility成功600 失败601
int FacilityService::DeleteSignle(string id) {
	string sql = "delete from facility where facility_id="
			+ Utils::AddSingleQuoteMark(id);
	DBConn db;
	if (db.Execute_mysql(sql) == 0) {
		db.Close_mysql();
		return 310;
	} else {
		db.Close_mysql();
		return 311;
	}

}
