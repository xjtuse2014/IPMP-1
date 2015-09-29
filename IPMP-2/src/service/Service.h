/*
 * Service.h
 *
 *  Created on: 2015年9月29日
 *      Author: syq
 */

#ifndef SRC_SERVICE_SERVICE_H_
#define SRC_SERVICE_SERVICE_H_
#include "../utils/univer.h"
class Service {
public:
	/**
	 * 增加单个元素
	 */
	virtual int Add(void* arg)=0;
	/**
	 * 删除单个元素
	 */
	virtual int DeleteSingle(void *arg)=0;
	/**
	 *查询所有元素
	 */
	virtual string SelectAll(void *arg)=0;
	/**
	 *查询单个元素
	 */
	virtual string SelectSingle(void *arg)=0;
public:
	Service();
	virtual ~Service();
};

#endif /* SRC_SERVICE_SERVICE_H_ */
