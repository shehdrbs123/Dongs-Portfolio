create table characters(
	id INT auto_increment primary key ,
    user_id INT NOT NULL,
    name varchar(50) NOT NULL,
    level INT default 1,
    experience INT default 0    
);