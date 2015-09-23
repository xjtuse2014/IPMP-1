/*
 * UserService.h
 *
 *  Created on: 2015年9月20日
 *      Author: syq
 */

#ifndef SERVICE_USERSERVICE_H_
#define SERVICE_USERSERVICE_H_
#include "../utils/univer.h"
#include "../utils/constant.h"
#include "../utils/Utils.h"
#include "../dao/DBConn.h"
#include "../bean/User.h"
#include "../utils/json/json.h"
class UserService{
private:
	User user;
public:
	/**
	 * @return User
	 * 解析JSON 获取对象属性
	 */
	User GetParasFRomJson(string jsonString);
	/**
	 * 增加一条记录
	 */
	 int Add(User user);
	/**
	 * 更新一条记录
	 */
	 int Update(User user);
	/**
	 * 删除一条记录
	 */
	 int DeleteSignle(string u_id);
	/**
	 * 增加多条记录
	 */
	 int DeleteAll();
		/**
		 *return a string like this:(User)
		 *{
		 *		"num": int
		 *		"Users":[{
		 *			"u_id":
		 *			"u_name":
		 *		},
		 *		{
		 *			"u_id":
		 *			"u_name":
		 *		},
		 *		{
		 *			"u_id":
		 *			"u_name":
		 *		}
		 *		]
		 *}
		 */
	 string SelectAll();
	/**
	 * 查询一条记录
	 *
	 */

	 string SelectSignle(string u_id);
	 /**
	  *查询记录是否存在
	  *@return -1：存在 0：不存在
	  */
	 int SelectUserExist(string u_id);
public:
	UserService();
	virtual ~UserService();

	const User& getUser() const {
		return user;
	}

	void setUser(const User& user) {
		this->user = user;
	}
};

#endif /* SERVICE_USERSERVICE_H_ */
