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
	return 0;
}
