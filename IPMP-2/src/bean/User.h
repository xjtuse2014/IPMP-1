/*
 * User.h
 *
 *  Created on: 2015年9月20日
 *      Author: syq
 */

#ifndef BEAN_USER_H_
#define BEAN_USER_H_
#include "../utils/univer.h"
class User {
private:
	string u_id;
	string u_name;
	string u_department;
	string u_phone;
	string u_gender;
	string m_op;
public:
	User();

	virtual ~User();



	const string& getDepartment() const {
		return u_department;
	}

	void setDepartment(const string& department) {
		u_department = department;
	}



	const string& getId() const {
		return u_id;
	}

	void setId(const string& id) {
		u_id = id;
	}

	const string& getName() const {
		return u_name;
	}

	void setName(const string& name) {
		u_name = name;
	}

	const string& getPhone() const {
		return u_phone;
	}

	void setPhone(const string& phone) {
		u_phone = phone;
	}



	const string& getOp() const {
		return m_op;
	}

	void setOp(const string& op) {
		m_op = op;
	}

	const string& getGender() const {
		return u_gender;
	}

	void setGender(const string& gender) {
		u_gender = gender;
	}
};

#endif /* BEAN_USER_H_ */
