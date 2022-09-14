SELECT distinct(t1.num) as ConsecutiveNums 
FROM logs t1, logs t2 , logs t3
WHERE t1.id=t2.id+1 AND t2.id=t3.id+1 AND t1.num=t2.num AND t2.num=t3.num