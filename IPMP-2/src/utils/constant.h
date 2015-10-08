/*
 * constant.h
 *
 *  Created on: 2015年9月20日
 *      Author: syq
 */

#ifndef UTILS_CONSTANT_H_
#define UTILS_CONSTANT_H_
/**
 * user
 * m_op
 */
#define ADD_USER "addUser"
#define DELETE_USER "deleteUser"
#define UPDATE_USER "updateUser"
#define SELECT_SINGLE_USER "selectSUser"
#define SELECT_ALL_USER "selectUser"

/**
 *admin
 * m_op
 */
#define ADD_ADMIN "addAdmin"
#define DELETE_ADMIN "deleteAdmin"
#define UPDATE_ADMIN "updateAdmin"
#define SELECT_SINGLE_ADMIN "selectSAdmin"
#define SELECT_ALL_ADMIN "selectAdmin"
#define LOGIN "login"

/**
 *meetroom
 * m_op
 */
#define ADD_MEETROOM "addMeetroom"
#define DELETE_MEETROOM "deleteMeetroom"
#define UPDATE_MEETROOM "updateMeetroom"
#define SELECT_SINGLE_MEETROOM "selectSMeetroom"
#define SELECT_ALL_MEETROOM "selectMeetroom"

/**
 *facility
 * m_op 0
 */
#define UPDATE_FACILITY_FOR_ROOM "updateFMR"
#define ADD_FACILITY "addFacility"
#define DELETE_FACILITY "deleteFacility"
#define UPDATE_FACILITY "updateFacility"
#define SELECT_SINGLE_FACILITY "selectSFacility"
#define SELECT_ALL_FACILITY "selectFacility"


 /**
 * table: user
 */
#define SELECT_SINGLE_USER_SQL "select * from user where u_id="
#define SELECT_ALL_USER_SQL "select * from user"
#define DELETE_ALL_USER_SQL "delete from user"
#define DELETE_SINGLE_USER_SQL "delete from user where u_id="
#define ADD_USER_SQL "insert into user(u_id,u_name,u_department,u_phone,u_gender)values"

/**
 * table: meetroom
 */
#define SELECT_SINGLE_MR_SQL "select * from meetroom where meetroom_id="
#define SELECT_SINGLE_MR_FACILITY_SQL "select * from facility where meetroom_id="
#define SELECT_ALL_MR_SQL "select * from meetroom"
#define DELETE_ALL_MR_SQL "delete from meetroom"
#define DELETE_SINGLE_MR_SQL "delete from meetroom where meetroom_id="
#define ADD_MR_SQL "insert into meetroom(meetroom_id,meetroom_name,meetroom_addr,available_state,meetroom_size)values('"
#define SELECT_MR_ID_SQL "select meetroom_id from meetroom where meetroom_id="
#define SELECT_MR_ADD_FACILITY_SQL "select facility_id from facility where meetroom_id=''"
/**
 *  string str="{0}hello,{1},welcome to CHINA!";
 *  str=String,Format(str,"claire","deal");
 */


#endif /* UTILS_CONSTANT_H_ */
