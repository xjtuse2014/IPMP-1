/*
 * DBConn.cpp
 *
 *  Created on: Aug 14, 2015
 *      Author: syq
 */

#include "DBConn.h"

DBConn::DBConn() {
	Init_mysql();
	Connect_mysql();
}

DBConn::DBConn(MYSQL mysql) {
	this->mysql = mysql;
	Init_mysql();
	Connect_mysql();
}

DBConn::~DBConn() {

}

void DBConn::Init_mysql() {
	mysql_init(&mysql);
}

int DBConn::Connect_mysql() {
	if (!mysql_real_connect(&mysql, "localhost", "root", "123456", "ipmp", 0,NULL, 0)) {
		printf("Connect failed!\n");
		cout << mysql_errno(&mysql) << endl;
		cout << mysql_error(&mysql) << endl;
		return -1;
	}
	return 0;
}

/**
 * @return a string ,usual means user's password or name and so on
 */
string DBConn::Query_mysql(string querySQL) {
	string result;
	if (mysql_real_query(&mysql, querySQL.c_str(),(unsigned int) strlen(querySQL.c_str())) == 0) {
		res = mysql_store_result(&mysql);
		while (row = mysql_fetch_row(res)) {
			for (t = 0; t < mysql_num_fields(res); t++) {
				result = row[t];
			}
		}
		return result;
	} else {
		printf("query failed\n");
		cout << mysql_errno(&mysql) << endl;
		cout << mysql_error(&mysql) << endl;
		return "failed";
	}
}

/**
 * @return json string
 * eg:
 *
 * {
 * 		"userNum":3,
 * 		"Users":
 * 		[
 * 			{
 * 				"m_strUserName":"syq",
 * 				"m_strUserPhone":"15237872320",
 * 				"m_strUserDepartment":"software college"
 * 			},
 * 			{
 * 				"m_strUserName":"claire",
 * 				"m_strUserPhone":"15237872320",
 * 				"m_strUserDepartment":"software college"
 * 			}
 * 		]
 * }
 *
 */
string DBConn::Query_all_mysql(string sql, string ObjectName) {
	Json::Value root;
	Json::Value arrayObj;
	Json::Value item;
	int t = mysql_real_query(&mysql, sql.c_str(),
			(unsigned int) strlen(sql.c_str()));
	if (t == -1) {
		cout << "query failed:%s\n" << mysql_errno(&mysql)
				<< mysql_error(&mysql) << endl;
	} else {
		res = mysql_store_result(&mysql); //返回查询的全部结果集
		//获取表的列数
		//int numb=mysql_num_fields(res);
		//printf("name: %s   count: %d\n", namebuf[i], rows);

		//获取并输出表头
		field = mysql_fetch_fields(res);
		//int length=mysql_fetch_lengths(res);
		int length = mysql_num_rows(res);
		int userNum = 0;
		int i = 1;
		while (row = mysql_fetch_row(res)) {	//mysql_fetch_row取结果集的下一行
			for (t = 0; t < mysql_num_fields(res); t++) {	//结果集的列的数量
				item[field[t].name] = Json::Value(row[t]);
			}
			arrayObj.append(item);
			item.clear();
			userNum++;
		}
		root["Num"] = Json::Value(userNum);
		root[ObjectName] = arrayObj;
		return root.toStyledString();
	}
}

void DBConn::Close_mysql() {
	mysql_close(&mysql);
}

//SQL语句执行成功返回0，出错返回非0。
int DBConn::Insert_mysql(string sql) {
	if (!mysql_query(&mysql, sql.c_str())) {
		return 0;
	} else {
		cout << mysql_errno(&mysql) << endl;
						cout << mysql_error(&mysql) << endl;
		return -1;
	}
}
/**
 * 执行SQL
 */int DBConn::Execute_mysql(string sql) {
	if (mysql_query(&mysql, sql.c_str())!=-1) {
		cout << mysql_errno(&mysql) << endl;
		cout << mysql_error(&mysql) << endl;
		return 0;
	} else {
		cout << mysql_errno(&mysql) << endl;
		cout << mysql_error(&mysql) << endl;
		return -1;
	}
}
/**
 * @params id table
 * @return  a user's all parameters of the Json format
 */
string DBConn::Query_single_mysql(string sql) {

	Json::Value item;
	int t = mysql_real_query(&mysql, sql.c_str(),
			(unsigned int) strlen(sql.c_str()));
	if (t == -1) {
		cout << "query failed:" << mysql_errno(&mysql) << mysql_error(&mysql)
				<< endl;
	} else {
		res = mysql_store_result(&mysql);	//返回查询的全部结果集
		field = mysql_fetch_fields(res);
		while (row = mysql_fetch_row(res)) {	//mysql_fetch_row取结果集的下一行
			for (t = 0; t < mysql_num_fields(res); t++) {	//结果集的列的数量
				item[field[t].name] = Json::Value(row[t]);
			}
		}
		return item.toStyledString();
	}
}

/**
 * select * from t1;
 * create table t2(name char(15),age int);
 * insert into t1(name,age) values ('zhang',32);
 * delete from t1 where age=20;
 * update t1 set age=100 where name='wa';
 * alter table tablename drop columnname;
 * 创建:
 mysql>create table cc(id int auto_increment,name varchar(20),primary key(id));
 修改:
 mysql> alter table cc change id id int primary key auto_increment;
 show columns from 表名;
  alter table 表名 modify column 字段名 类型;
  alter table e_down add soft_version1 varchar(50) ／／z增加一个字段
 */

