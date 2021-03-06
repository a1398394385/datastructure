select distinct a.Num as ConsecutiveNums
from Logs as a,Logs as b,Logs as c
where a.Num=b.Num and b.Num=c.Num and a.id=b.id-1 and b.id=c.id-1;


select distinct Num as ConsecutiveNums
from (
    select Num, if((@pre = (@pre:=Num)), @a := @a+1, @a:=1) as n
    from Logs, (select @a:=0, @pre:='a') t
    ) as temp
where n >= 3
order by Num desc;


select distinct Num as ConsecutiveNums
from (
  select Num, 
    case 
      when @prev = Num then @count := @count + 1
      when (@prev := Num) is not null then @count := 1
    end as CNT
  from Logs, (select @prev := null,@count := null) as t
) as temp
where temp.CNT >= 3
