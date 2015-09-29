/*
 * Facility.h
 *
 *  Created on: 2015年9月21日
 *      Author: syq
 */

#ifndef BEAN_FACILITY_H_
#define BEAN_FACILITY_H_
#include "../utils/univer.h"
class Facility {
private:
	string facility_id;
	string facility_name;

	string available_state;//
	string meetroom_id;
	string facility_ip;
	string m_op;
public:
	Facility();
	virtual ~Facility();

	const string& getAvailableState() const {
		return available_state;
	}

	void setAvailableState(const string& availableState) {
		available_state = availableState;
	}

	const string& getFacilityId() const {
		return facility_id;
	}

	void setFacilityId(const string& facilityId) {
		facility_id = facilityId;
	}

	const string& getFacilityIp() const {
		return facility_ip;
	}

	void setFacilityIp(const string& facilityIp) {
		facility_ip = facilityIp;
	}

	const string& getFacilityName() const {
		return facility_name;
	}

	void setFacilityName(const string& facilityName) {
		facility_name = facilityName;
	}

	const string& getMeetroomId() const {
		return meetroom_id;
	}

	void setMeetroomId(const string& meetroomId) {
		meetroom_id = meetroomId;
	}



	const string& getOp() const {
		return m_op;
	}

	void setOp(const string& op) {
		m_op = op;
	}
};

#endif /* BEAN_FACILITY_H_ */
