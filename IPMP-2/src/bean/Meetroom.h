/*
 * Meetroom.h
 *
 *  Created on: 2015年9月21日
 *      Author: syq
 */

#ifndef BEAN_MEETROOM_H_
#define BEAN_MEETROOM_H_
#include "../utils/univer.h"
class Meetroom {
private:
private:
	string meetroom_id;
	string meetroom_name;
	string meetroom_addr;
	string available_state;
	string now_state;
	string meet_num;
public:
	Meetroom();
	virtual ~Meetroom();
};

#endif /* BEAN_MEETROOM_H_ */
