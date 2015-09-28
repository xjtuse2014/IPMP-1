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
	string meet_num;
public:
	Meetroom();
	virtual ~Meetroom();

	const string& getAvailableState() const {
		return available_state;
	}

	void setAvailableState(const string& availableState) {
		available_state = availableState;
	}

	const string& getMeetNum() const {
		return meet_num;
	}

	void setMeetNum(const string& meetNum) {
		meet_num = meetNum;
	}

	const string& getMeetroomAddr() const {
		return meetroom_addr;
	}

	void setMeetroomAddr(const string& meetroomAddr) {
		meetroom_addr = meetroomAddr;
	}

	const string& getMeetroomId() const {
		return meetroom_id;
	}

	void setMeetroomId(const string& meetroomId) {
		meetroom_id = meetroomId;
	}

	const string& getMeetroomName() const {
		return meetroom_name;
	}

	void setMeetroomName(const string& meetroomName) {
		meetroom_name = meetroomName;
	}
};

#endif /* BEAN_MEETROOM_H_ */
