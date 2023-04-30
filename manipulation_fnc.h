#ifndef MANIPULATION_FNC
#define MANIPULATION_FNC

#include <string.h>
#include <math.h>


/* la structure clause contient le nombre de littéraux (nb_lit) et les coef associés (coef)*/
typedef struct{
  int nb_lit;
  int* coef;
}Clause;


/*la structure Fnc représente une forme normale conjonctive elle contient le nombre 
de clauses le nombre de litéraux un tableau de literaux et un tableau de clauses*/
typedef struct{
  int nb_clse;
  int nb_lit;
  int* lit;
  Clause* clauses;
}Fnc;



void init_clause(Clause*, int);
void init_fnc(Fnc*, int, int);
void del_clause(Clause*);
void del_fnc(Fnc*);






#endif
