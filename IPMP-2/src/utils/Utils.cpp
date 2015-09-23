/*
 * Utils.cpp
 *
 *  Created on: 2015年9月17日
 *      Author: syq
 */

#include "Utils.h"

Utils::Utils() {
	// TODO Auto-generated constructor stub

}

Utils::~Utils() {
	// TODO Auto-generated destructor stub
}

 int Utils::gb2312toutf8(char *sourcebuf,size_t source_len,char *destbuf,size_t destlen){
	iconv_t cd;
	if((cd=iconv_open("utf-8","gb2312"))==0){
			return -1;
	}
	memset(destbuf,0,destlen);
	 char **source=&sourcebuf;
	char **dest=&destbuf;
	if(iconv(cd,source,&source_len,dest,&destlen)==-1){
			return -1;
	}
	iconv_close(cd);
	return 0;
}

 char* Utils::GetCurrentTime(){
	 time_t time;
//	 time(&time);
	 return ctime(&time);
 }

 string Utils::AddSingleQuoteMark(string words){
	 return "'"+words+"'";
 }
