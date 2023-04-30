# Mini-project-on-logic-game
Squaro Game

# Compilation :
To compile all the programs of the project :   make all
    
# Use : 
the code usage is as follows: 

  * Step 1 : 
 ./random_generation <grid size> <file.txt>
 
 exemple :  ./random_generatione 5 release1.txt 
  result :
    
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


          
          
  * step 2 : 
 ./release_dimacs <file.txt> <file.fnc>
 
 exemple : ./release_dimacs release1.txt release1.fnc
  résultat : a dimacs format file (res1.fnc)
  
  
   * step 3 : 
 minisat <file.fnc> <file.txt>
 
 exemple :  minisat res1.fnc sat.txt
  result :
    
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


   * step 4 : 
  ./solution_display <file.txt> <file.txt>
 
 exemple :  ./solution_display release1.txt sat.txt
  result :
        The grid is solvable :
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


  
  
 
