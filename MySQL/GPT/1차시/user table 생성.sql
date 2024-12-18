create table users(
	id INT auto_increment primary key,
    username varchar(50) not null,
    email varchar(100) not null,
    created_at timestamp default current_timestamp
);
    
