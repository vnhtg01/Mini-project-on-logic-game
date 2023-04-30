#include <stdio.h>
#include <stdlib.h>
#include "dimacs.h"

Fnc lecture_dimacs(char* nf){
  
  Fnc dim;
  char *line = NULL;
  size_t len = 0;
  size_t read;
  FILE* f = NULL;
  int i,j;
  int coef = 1;
  int pos = 0;
  int nc, nl;
  int k = 0;

  f = fopen(nf, "r");
  if (f == NULL) {
    printf("erreur lors de l'ouverture du fichier DIMACS : ");
  }
  else{
    i=0;
    while (( read = getline(&line, &len, f)) != -1){
      
	

	if (line[0] == 'p'){
	  pos = 0;
     //recuperer le nbre de clauses et lit
	  nl = lire_int(line, &pos);
	  nc = lire_int(line, &pos);
    //reserver de l espace memoire pour la fnc dim avec nc(nbre de clauses) et nl (nbre de lit)
	  init_fnc(&dim, nc, nl);
	  for(j=0; j<nc; j++){
       //initialisation de l espace memoire pour la clause de taille nl 
	    init_clause(&(dim.clauses[j]), nl);
	  }
	
	}else{

	  j=0;
	  pos = 0;
     //lecture des literaux
	  while ((coef = lire_int(line, &pos)) != 0){
      //tableau de coef
	    dim.clauses[i].coef[j] = coef;
      //inserer literal dans une clause
      //les literaux 
	    inserer_literau(&dim, coef, &k);
	    j++;
	  }
     //le nbre de literaux dans la clause
	  dim.clauses[i].nb_lit = j;
	  i++;
	}
      
    }
    
    free(line);
    fclose(f);
  }
  
  return dim;
  
}



//nf = fichier de sortie
int ecrire_dimacs(char* nf, Fnc g){
  
  int i, j;
  FILE* f = NULL;
  
  f = fopen(nf, "w+");
  if (f == NULL){
    printf(" erreur lors de la création du fichier DIMACS : ");

    return 0;
  }
  
  //on affiche le nombre totale des literaux et le nombre totale des clauses qui correspond a chaque grille generer 
  fprintf(f, "p cnf %d %d \n", g.nb_lit, g.nb_clse);
  
  
  for (i=0; i<g.nb_clse; i++){
    for (j=0; j<g.clauses[i].nb_lit; j++){
      fprintf(f, " %d", g.clauses[i].coef[j]);
    }
    fputs(" 0 \n", f);
  }
  fclose(f);
  return 1;
}




//comparer 2 entier 
int comparer (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

//insere un literale dans une clause
void inserer_literau(Fnc* g, int a, int* n){

  /* recherche de la valeur */

  int* lit = NULL;
  int* litm = NULL;
  int key = -a;
  
  //cherche la valeur key(literal) dans le tableau de lit (g->lit) ds la pos n en la comparant avec toute les valeurs du tableau  
  //elle renvoie un bol pour indiquer si trouver ou pas 
  lit = (int*) bsearch(&key, g->lit, *n, sizeof (int), comparer);
  litm= (int*) bsearch(&a, g->lit, *n, sizeof(int), comparer); 


  if (lit == NULL && litm == NULL){
    g->lit[*n] = abs(a);
    *n = *n + 1;

    // tri du tableau
    qsort(g->lit, *n, sizeof(int), comparer);
  }

}


