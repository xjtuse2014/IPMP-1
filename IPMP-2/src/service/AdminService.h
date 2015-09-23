/*
 * AdminService.h
 *
 *  Created on: 2015年9月22日
 *      Author: syq
 */

#ifndef SERVICE_ADMINSERVICE_H_
#define SERVICE_ADMINSERVICE_H_
#include "../utils/univer.h"
#include "../utils/constant.h"
#include "../utils/Utils.h"
#include "../dao/DBConn.h"
#include "../bean/Admin.h"
#include "../utils/json/json.h"

class AdminService {
public:
	/**
	 * 添加管理员
	 */
	int AddAdmin(Admin admin);
	/**
	 * 管理员登录
	 */
	int LoginSys(string a_id,string a_psd);
	/**
	 * @return Admin
	 * 解析JSON 获取对象属性
	 */
	Admin GetParasFRomJson(string jsonString);


public:
	AdminService();
	virtual ~AdminService();
};

#endif /* SERVICE_ADMINSERVICE_H_ */
