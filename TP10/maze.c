// IG2I / SDD 
// 2021-11-17
// Vincent Liard - P Kubiak

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


// Labyrinthe en anglais : maze.

// Représente un chemin sous la forme d'une chaîne de caractères
// composée des lettres u (up), d (down), l (left), r (right).
typedef char* path_t; 


typedef struct {
    int valeur;
    bool visited;
    char direction; // u d r ou l 
    int nbDirections;// ou nbrVoisins : c'est à dire le nb de cases utiles dans directionsPossibles et QuatreVoisins
    char directionsPossibles[5];
    int QuatreVoisins[4];// valeur des 4(ou-) voisins 
} T_cellule;


typedef struct {
  //  v________ 
  // |   ______| ^
  // | |_____  | |
  // |  _|   | | |
  // |_|  _| | | row(6)
  // | __|___  | |
  // |_______|v| v
  // <--col(5)->

  // Le labyrinthe comporte row lignes-couloirs horizontaux
  // (est-ouest) et col colonnes-couloirs verticaux (nord-sud).
  
  // Il y a implicitement des murs tout autour du labyrinthe.

  // L'entrée se trouve dans la cellule supérieure gauche
  // (nord-ouest), la sortie se trouve dans la cellule inférieure
  // droite (sud-est).

  // wallh[i][j] et wallv[i][j] encodent pour la cellule (i,j) le fait
  // qu'elle comporte un mur horizontal au dessous ou vertical à
  // droite (respectivement).

  // Nombre de lignes
  int row;
  // Nombre de colonnes
  int col;
  int num;
  // table de booléens murs horizontaux '_'
  bool *wallh;
  // table de booléens murs verticaux '|'
  bool *wallv;
  T_cellule *cells;
  
} maze_t;

bool *wall_under(maze_t *m, int row, int col);
bool *wall_right(maze_t *m, int row, int col);
maze_t *init_maze(int row, int col);
void free_maze(maze_t *m);
void print_maze_raw(maze_t const *m);

//void print_maze(maze_t const *m,char *udlr,int t[200][2],int n);

void print_maze(maze_t const *m);

maze_t *compartmentalized_maze(int row, int col);

//void printValeurs(maze_t *);




void printValeurs(maze_t *m)


{
    
   int i,j;
   for(i=0;i<m->row;i++)
   {
       printf("\n");
       for(j=0;j<m->col;j++)
           printf("%3d|",m->cells[i*m->col+j].valeur);
   }     
    printf("\n");printf("\n");
    
}


int main(void) {  /////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\MAIN
   /*int wh[5 * 5] = {1,1,1,1,1, 
                    1,1,1,1,1, 
                    1,1,1,1,1, 
                    1,1,1,1,1,
                    1,1,1,1,1}; 
   int wv[6 * 4] = {1,1,1,1, 
                    1,1,1,1, 
                    1,1,1,1, 
                    1,1,1,1, 
                    1,1,1,1, 
                    1,1,1,1}; 
  
   maze_t *m = init_maze(6, 5); 
   if (!m) { 
     printf("Echec d'allocation mémoire pour le labyrinthe.\n"); 
     return 0; 
   } 
   memcpy(m->wallh, wh, 25 * sizeof(int)); 
   memcpy(m->wallv, wv, 24 * sizeof(int)); */

  int NL,NC,tot;
  int haz,i,hazbool,j;
  int finBoucle=0;
  int compteur=0;
  

  printf("\n quel sera le nombre de lignes de votre labyrinthe ? ");scanf("%d",&NL);
  printf("\n quel sera le nombre de colonnes de votre labyrinthe ? ");scanf("%d",&NC);
  maze_t *m = compartmentalized_maze(NL, NC); 
  tot=(NL*NC)-1;
  int casser=2*NL*NC-NC-NL;

printf("casser %d",casser);
  do{

  int x=rand() % (NL); //rand() renvoie une grande valeur mais celle ci est divisée par 100 et le reste de cette division est rangée dans haz (on a donc : 0<=haz<100)
  printf("x: %d\n ",x);
  int y=rand() % (NC); //rand() renvoie une grande valeur mais celle ci est divisée par 100 et le reste de cette division est rangée dans haz (on a donc : 0<=haz<100)
  printf("y: %d\n ",y);
  
  if((*wall_right(m, x, y)==1)&&(*wall_under(m,x,y)==1)){ //vertical
    hazbool=rand() % 2;
    if(hazbool==0 && m->cells[x*(m->col+y)].valeur!=m->cells[x*(m->col+y+1)].valeur ){//vertical
      *wall_right(m, x, y) = 0;
      m->cells[x*(m->col+y+1)].valeur= m->cells[x*(m->col+y)].valeur;
      compteur++;
   
  
    }
        else if(hazbool==1 && m->cells[x*(m->col+y)].valeur!=m->cells[(x+1)*(m->col+y)].valeur){//hor
      *wall_under(m, x, y) = 0;
      m->cells[(x+1)*(m->col+y)].valeur= m->cells[x*(m->col+y)].valeur;
      compteur++;
    }
  }
  else {
  if((*wall_right(m, x, y)==1)&&(*wall_under(m,x,y)==0)){
    *wall_right(m, x, y) = 0;
    m->cells[(x)*(m->col+y+1)].valeur= m->cells[x*(m->col+y)].valeur;
    compteur++;
    
  }else{
    *wall_under(m, x, y) = 0;
    m->cells[(x+1)*(m->col+y)].valeur= m->cells[x*(m->col+y)].valeur;
    compteur++;
    
  }
  }
for(i=0;i<NL-1;i++)
{
  for(j=0;j<NC-1;j++)
  {
    if(m->cells[i*(m->col+j)].valeur==m->cells[x*(m->col+y)].valeur)
        m->cells[i*(m->col+j)].valeur=m->cells[x*(m->col+y)].valeur;
  }
   print_maze(m);
    printValeurs(m);
}
printf("compteur %d",compteur);
  
  



  
   
  }while(compteur!=casser);
  printValeurs(m);
  //print_mazePLEIN(m); 
   print_maze(m);
  //prendre un nomre aléatoire 
  
  free_maze(m);
  
  
  return 0;
}


// Accès (en lecture et écriture) au mur vertical à droite de la
// cellule row, col du labyrinthe m
bool *wall_right(maze_t *m, int row, int col) {
  if (row > m->row || col > m->col - 1)
    return NULL;
  return &(m->wallv[row * (m->col - 1) + col]);
}

// Accès (en lecture et écriture) au mur horizontal au dessous de la
// cellule row, col du labyrinthe m
bool *wall_under(maze_t *m, int row, int col) {
  if (row > m->row - 1 || col > m->col)
    return NULL;
  return &(m->wallh[row * m->col + col]);
}


// Retourne un pointeur sur un maze_t complètement initialisé ou NULL
// si l'allocation a échoué.
maze_t *init_maze(int row, int col) {
  maze_t *m;
  m = malloc(sizeof(maze_t));
  if (!m)   
    return NULL;
  m->row = row;
  m->col = col;
  
  m->wallh = malloc((row - 1) * (col    ) * sizeof(int));
  m->wallv = malloc((row    ) * (col - 1) * sizeof(int));
  m->cells = malloc((row    ) * (col) * sizeof(T_cellule));
  if (!m->wallh || !m->wallv || !m->cells   )
    return NULL;
  return m;
}

void free_maze(maze_t *m) {
  free(m->wallv);
  free(m->wallh);
  free(m);
}

// « Labyrinthe dans lequel toutes les cellules sont fermées.
// Exemple : Le « labyrinthe » compartimenté 6 lignes, 5 colonnes
// ._________.
// |_|_|_|_|_|
// |_|_|_|_|_|
// |_|_|_|_|_|
// |_|_|_|_|_|
// |_|_|_|_|_|
// |_|_|_|_|_|
maze_t *compartmentalized_maze(int row, int col) {
  maze_t *m;
  if (!(m = init_maze(row, col)))
    return NULL;
  //print_maze_raw(m);
  // Lignes et colonnes internes
  for (int i = 0; i < m->row - 1; ++i)
    for (int j = 0; j < m->col - 1; ++j) {
      *wall_under(m, i, j) = 1;
      *wall_right(m, i, j) = 1;
    }
  // Dernière colonne (murs horizontaux) :
  for (int i = 0; i < m->row - 1; ++i)
    *wall_under(m, i, m->col - 1) = 1;
  // Dernière ligne (murs verticaux) :
  for (int j = 0; j < m->col - 1; ++j)
    *wall_right(m, m->row - 1, j) = 1;

  for (int i = 0; i < m->row ; ++i)
  
    for (int j = 0; j < m->col ; ++j)
        m->cells[i*col +j].valeur = i*col +j;
  return m;
}
  

void print_maze_raw(maze_t const *m) {
  printf("row : %d, col : %d\n", m->row, m->col);
  printf("wallh %d lignes x %d colonnes :\n", m->row - 1, m->col);
  for (int i = 0; i < m->row - 1; ++i) {
    for (int j = 0; j < m->col; ++j)
      printf("%d ", m->wallh[i * m->col + j]);
    printf("\n");
  }

  printf("wallv %d lignes x %d colonnes :\n", m->row, m->col - 1);
  for (int i = 0; i < m->row; ++i) {
    for (int j = 0; j < m->col - 1; ++j)
      printf("%d ", m->wallv[i * (m->col - 1) + j]);
    printf("\n");
  }
}
  
  

void print_maze(maze_t const *m) {
  print_maze_raw(m);
  
  //Mur supérieur
  printf(" v");
  for (int i = 0; i < m->col - 1; ++i)
    printf("__");
  printf(" \n");

  
  for (int i = 0; i < m->row - 1; ++i) {
    printf("|");
    for (int j = 0; j < m->col - 1; ++j) {
            printf(m->wallh[i * m->col + j] ? "_" : " ");
      
      printf(m->wallv[i * (m->col - 1) + j] ? "|" : " ");
    }
    printf("%s|\n", m->wallh[(i + 1) * m->col - 1] ? "_" : " ");
    // "|" : m->wallh[(i + 1) * m->col + j] ? "_" : " "
  }
  
  // Mur inférieur
  printf("|");
  for (int i = 0; i < m->col - 1; ++i)
    printf(m->wallv[(m->row - 1) * (m->col - 1) + i] ? "_|" : "__");
  printf("v|\n");
}







