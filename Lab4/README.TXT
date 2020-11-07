Vlaescu Adrian-Cristian

Laborator 4 - APP - MPI

ex2.c: am calculat numarul de elemente din vector
ce trebuie distribuite catre fiecare proces. Ultimul
proces poate avea un numar mai mare sau mai mic fata de restul.
Am trimis de pe master la celelalte numarul de elemente si vectorul
principal. In celelalte procese am primit aceste doua send-uri si 
am calculat suma acelor elemente, dupa care am trimis catre master
suma partiala.

ex3.c: ce e diferit fata de ex2 este faptul ca de pe master fac un Broadcast
cu acel coeficient, iar in celelalte procese primesc acea valoare folosind tot
broadcast.