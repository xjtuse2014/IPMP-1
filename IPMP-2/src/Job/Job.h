/*
 * Job.h
 *
 *  Created on: 2015年9月20日
 *      Author: syq
 */

#ifndef JOB_H_
#define JOB_H_
#include "../utils/univer.h"
#include "../utils/Utils.h"
#include "../utils/constant.h"
#include "../bean/User.h"
#include "../bean/Admin.h"
#include "../bean/Facility.h"
#include "../utils/json/json.h"

#include "../service/UserService.h"
#include "../service/AdminService.h"
#include "../service/FacilityService.h"
#include "../service/MeetroomService.h"
class Job {
private:
	int sockfd;
	int client_fd;
	struct sockaddr_in my_addr,remote_addr;
	socklen_t len;
	int sin_size;
	int r;
public:
	/**
	 * 开始工作
	 * @return    0 :success    -1: fail
	 */
	int StartJob();
	/**
	 * 工作线程
	 */
	static void* WorkThread(void* arg);
public:
	Job();
	virtual ~Job();
};

#endif /* JOB_H_ */
