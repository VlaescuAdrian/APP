Nume: Vlaescu Adrian-Cristian
Grupa: 342C2

Laborator 1 APP:
	Am atasat poze cu fiecare fisier rulat si timpul de executie al acestuia, inclusiv pentru cele care calculeaza valoarea matematica a lui pi.
Am rezolvat in ex1, ex1-1, ex2-serial si ex2 exercitiile cerute in pdf -ul de aici https://curs.upb.ro/mod/folder/view.php?id=39324

Nu am mai variat numarul de threaduri la fiecare rulare, dar acest lucru se poate face intern (in fisierul respectiv) sau prin comanda in consola:
export OMP_NUM_THREADS=4. Intern se face prin omp_set_num_threads( NUM_THREADS ), unde NUM_THREADS este numarul de threaduri dorit.