alter table characters
add constraint fk_user_id
foreign key (user_id) references users(id)
	ON delete cascade
    on update cascade;