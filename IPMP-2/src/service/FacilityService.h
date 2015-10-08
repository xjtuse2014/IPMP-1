/*
 * FacilityService.h
 *
 *  Created on: 2015年9月23日
 *      Author: syq
 */

#ifndef SRC_SERVICE_FACILITYSERVICE_H_
#define SRC_SERVICE_FACILITYSERVICE_H_
#include "../utils/univer.h"
#include "../bean/Facility.h"
#include "../utils/Utils.h"
#include "../dao/DBConn.h"
class FacilityService {
public:
	/**
		 * @return Facility
		 * 解析JSON 获取对象属性
		 */
		Facility GetParasFRomJson(string jsonString);
		/**
		 * 增加一条记录
		 */
		 int Add(Facility facility);
		/**
		 * 更新一条记录
		 */
		 int Update(Facility facility);
		 int UpdateForRoom(string facility_id,string mr_id);
		/**
		 * 删除一条记录
		 */
		 int DeleteSignle(string facility_id);
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

		 string SelectSignle(string facility_id);
		 /**
		  *查询记录是否存在
		  */
		 int SelectFacilityExist(string facility_id);
		 int SelectFacilityExist(string facility_id,string facility_ip);
		 int SelectFacilityExist(string facility_id,string facility_ip,string meetroom_id);
public:
	FacilityService();
	virtual ~FacilityService();
};

#endif /* SRC_SERVICE_FACILITYSERVICE_H_ */
