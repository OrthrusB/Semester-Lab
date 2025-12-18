create database db1;
use db1;

#Numeric Functions
select abs(-22);
select mod(10,4)as remainder;
select power(4,2)as power;
select sqrt(4)as squareroot;
#now same goes for greatest, least,

select truncate(22.897,1);
#round off ni xa arko function

#Table create 
#Student Table

create table students
(stu_id int primary key,
stu_name varchar(25),
age int, gender char(1),doa date, city varchar(20));

insert into students values
(101,"babin",22,"M","2003-09-14","dhangadhi");

select * from students;