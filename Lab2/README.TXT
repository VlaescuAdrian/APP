Vlaescu Adrian-Cristian
342C2

Ex1:
	Modificand modul de scheduling din dynamic in static, pentru un numar de 6 threaduri 
timpul(pe masina mea virtuala) scade de la aprox. 0.4 sec la 0.15 sec. Scade timpul deoarece
cu modul static, se imparte uniform munca intre threaduri, in timp ce pe modul dinamic munca 
era preluata in principal de cateva threaduri din cele 6.

Ex2:
	Folosind reduction, timpul a scazut de la aprox. 0.25 sec la 0.005 sec deoarece 
s-a reusit sa se imparta calculul integralei la toate threadurile.

Ex3:
	Am creat files[][] pentru a retine cele 100 de nume de fisier. Pentru calculul dimensiunii
unui fisier am folosit fseek si ftell. Pentru paralelism, am folosit tot reduction, ca la exercitiul 2
Timpul s-a redus de la aprox. 0.015 la 0.005 sec.