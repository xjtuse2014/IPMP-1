create table meet(meet_id varchar(50) primary key,
                meet_title varchar(200),
                meet_content varchar(300),
                start_time date,
                end_time date,
                meet_num int(4),
                meet_appoitment int(1),
                meetroom_id varchar(50));


create table meetroom(meetroom_id varchar(50) primary key,
                meetroom_name varchar(50),
                meetroom_addr varchar(100),
                available_state varchar(4),
              
                meet_num varchar(8));


create table facility(facility_id varchar(50) primary key,
                facility_name varchar(200),
               
                available_state varchar(4),
                meetroom_id varchar(50));


create table user(u_id varchar(50) primary key,
                u_name varchar(50),
                u_department varchar(100),
                u_phone varchar(50),
                u_gender varchar(4));


create table file(file_id varchar(50) primary key,
                file_size float,
                file_name varchar(100),
                file_formate varchar(10),
                file_path varchar(100),
                u_id varchar(50));

create table history(history_id varchar(50) primary key,
                u_id varchar(50),
                meet_id varchar(50));

create table admin(a_id varchar(50)primary key,
		   a_name varchar(50),
		   a_psd varchar(50),
		   a_priority varchar(4));


