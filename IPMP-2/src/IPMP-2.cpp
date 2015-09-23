//============================================================================
// Name        : IPMP-1.cpp
// Author      : syq
// Version     :
// Copyright   : xjtu
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "./utils/constant.h"
#include "./utils/Utils.h"
#include "./Job/Job.h"
#include "./dao/DBConn.h"
#include "./service/UserService.h"
using namespace std;

int main() {


	Job* job=new Job();
	job->StartJob();

//	DBConn db,db1;
//	db.Query_mysql("select u_name from user where u_id='3434'");

//	User user;
//	UserService us;
//	user.setDepartment("software");
//	user.setGender("man");
//	user.setId("xxxxxxxxxx");
//	user.setName("syq");
//	user.setPhone("2222222");
//
//	int t=us.Add(user);

//	string sql="insert into user(u_id,u_name,u_department,u_phone,u_gender)values('"+ user.getId() + "','" +user.getName()+ "','" + user.getDepartment() +
//			"','"+user.getPhone() +"','"+user.getGender()+ "')";
//
//	int t=db.Execute_mysql(sql);

//	cout<<t<<endl;
	return 0;
}
