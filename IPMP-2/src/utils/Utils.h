/*
 * Utils.h
 *
 *  Created on: 2015年9月17日
 *      Author: syq
 */

#ifndef UTILS_UTILS_H_
#define UTILS_UTILS_H_
#include<iconv.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "univer.h"

class Utils {
public:
	Utils();
	virtual ~Utils();
	/**
	 * 编码格式转换 gb2312->utf-8
	 */
	  int gb2312toutf8(char *sourcebuf,size_t source_len,char *destbuf,size_t destlen);
	 /**
	  * 获取当前时间
	  */
	 char* GetCurrentTime();
	 /**
	  * 添加单引号
	  */
	 static string AddSingleQuoteMark(string words);


};

#endif /* UTILS_UTILS_H_ */
