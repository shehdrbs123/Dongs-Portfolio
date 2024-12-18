-- 추가 되지 않는 데이터
-- insert into characters (user_id,name)
-- values 
-- 	(4,'트랜들');
--     

delete from characters where user_id=3 and name='트랜들';
-- 추가되는 데이터    
insert into characters (user_id,name)
values 
	(3,'트랜들');

select * from characters