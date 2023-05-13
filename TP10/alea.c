#include <time.h>
#include <stdio.h>
#include <stdlib.h>


//programme qui tire 30 nombres au hasard
int main()
{

srand(time(NULL)); //initialisation du generateur de nombre aleatoire 
int haz,i;


for(i=0;i<30;i++)
{  
 haz=rand() % 100; //rand() renvoie une grande valeur mais celle ci est divisée par 100 et le reste de cette division est rangée dans haz (on a donc : 0<=haz<100)
 printf("%d ",haz);
}

return 0;
}


  /*
    if(hazbool==1 && m->cells[haz+1].valeur!=m->cells[haz].valeur ) {
      
      m->wallv[haz]=0;
      (m->cells[haz+1].valeur)=m->cells[haz].valeur;
      compteur=compteur+1;
    }
    for (i=NC-1;i<tot;i++NC)
    {
    if(haz==i) compteur=compteur-1;
    }
    

   

    if (hazbool==0 && (m->cells[haz+NL].valeur!=m->cells[haz].valeur )){
      m->wallh[haz]=0;
      m->cells[haz+NL].valeur=m->cells[haz].valeur;
      compteur=compteur+1;
      printf("2\n");
    }
    for (i=(NL*NC-NL);i<tot;i++)
    {
    if(haz==i)compteur=compteur-1;
    }
    printf("compteur:%d",compteur);
  */