# Mini-project-on-logic-game
Squaro Game

# Compilation :
Pour compiler l'ensemble des programmes du projet :   
    $ make all
    
# Utilisation : 
l'utilisation du code se fait comme suit : 


  * étape 1 : 
 ./generation_aleatoire <taille grille> <fichier.txt>
 
 exemple :  ./generation_aleatoire 5 sortie1.txt 
  résultat :
            O---O---O---O---O---O
            | 0 | 1 | 3 | 3 | 2 |
            O---O---O---O---O---O
            | 1 | 2 | 2 | 2 | 2 |
            O---O---O---O---O---O
            | 2 | 2 | 1 | 0 | 0 |
            O---O---O---O---O---O
            | 3 | 2 | 1 | 0 | 0 |
            O---O---O---O---O---O
            | 3 | 2 | 1 | 1 | 2 |
            O---O---O---O---O---O


          
          
  * étape 2 : 
 ./sortie_dimacs <fichier.txt> <fichier.fnc>
 
 exemple : ./sortie_dimacs sortie1.txt res1.fnc
  résultat : un fichier format dimacs (res1.fnc)
  
  
   * étape 3 : 
 minisat <fichier.fnc> <fichier.txt>
 
 exemple :  minisat res1.fnc sat.txt
  résultat :
  ============================[ Problem Statistics ]=============================
|                                                                             |
|  Number of variables:            36                                         |
|  Number of clauses:             183                                         |
|  Parse time:                   0.00 s                                       |
|  Eliminated clauses:           0.00 Mb                                      |
|  Simplification time:          0.00 s                                       |
|                                                                             |
============================[ Search Statistics ]==============================
| Conflicts |          ORIGINAL         |          LEARNT          | Progress |
|           |    Vars  Clauses Literals |    Limit  Clauses Lit/Cl |          |
===============================================================================
===============================================================================
restarts              : 1
conflicts             : 0              (-nan /sec)
decisions             : 1              (0.00 % random) (inf /sec)
propagations          : 22             (inf /sec)
conflict literals     : 0              (-nan % deleted)
Memory used           : 12.00 MB
CPU time              : 0 s

SATISFIABLE


   * étape 4 : 
  ./affichage_solution <fichier.txt> <fichier.txt>
 
 exemple :  ./affichage_solution sortie1.txt sat.txt
  résultat :
        La grille est resoluble :
          O---X---X---X---X---O
          | 2 | 3 | 3 | 3 | 1 |
          O---X---O---X---O---O
          | 2 | 1 | 2 | 3 | 1 |
          X---O---O---X---X---O
          | 2 | 1 | 3 | 3 | 2 |
          X---O---X---X---O---X
          | 3 | 3 | 3 | 2 | 3 |
          X---X---X---O---X---X
          | 2 | 2 | 1 | 1 | 3 |
          O---O---O---O---O---X


  
  
 
