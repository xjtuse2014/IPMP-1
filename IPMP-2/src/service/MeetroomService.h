/*
 * MeetroomService.h
 *
 *  Created on: 2015年9月28日
 *      Author: syq
 */

#ifndef SRC_SERVICE_MEETROOMSERVICE_H_
#define SRC_SERVICE_MEETROOMSERVICE_H_
#include "../utils/univer.h"
#include "../utils/constant.h"
#include "../utils/Utils.h"
#include "../dao/DBConn.h"
#include "../bean/Meetroom.h"
#include "../utils/json/json.h"
class MeetroomService {
public:
	/**
		 * @return Meetroom
		 * 解析JSON 获取对象属性
		 */
		Meetroom GetParasFRomJson(string jsonString);
		/**
		 * 增加一条记录
		 */
		 int Add(Meetroom mr);
		/**
		 * 更新一条记录
		 */
		 int Update(Meetroom mr);
		/**
		 * 删除一条记录
		 */
		 int DeleteSignle(string mr_id);
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

		 string SelectSignle(string mr_id);
		 /**
		  *查询记录是否存在
		  *@return -1：存在 0：不存在
		  */
		 int SelectMeetroomExist(string mr_id);
public:
	MeetroomService();
	virtual ~MeetroomService();
};

#endif /* SRC_SERVICE_MEETROOMSERVICE_H_ */
