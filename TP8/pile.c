#include "pile.h"



void initPile( T_Pile * P)
{
    P->nbElts=0;
}


int pilepleine(const  T_Pile *P)
{
    if(P->nbElts==MAX) return 1;
return 0;
}



int pilevide(const  T_Pile *P)
{
    if(P->nbElts==0)return 1;
return 0;
}



int empiler( T_Pile *P, T_Elt e) //renvoie 0 si pile pleine, sinon 1
{
    if(!pilepleine(P)){
        P->nbElts++;
        P->Elts[P->nbElts]=e;
        return 1;
    }
return 0;
}



int depiler( T_Pile *P, T_Elt *pelt)  //renvoie 0 si pile vide, sinon 1
{
    if(!pilevide(P)){
        *pelt=P->Elts[P->nbElts];
        P->nbElts--;
        
        return 1;
    }
return 0;
}



T_Elt sommet(const  T_Pile *P)
{
    return P->Elts[P->nbElts];
}



int hauteur(const  T_Pile *P)
{
    return P->nbElts;
}



void afficherPile(  T_Pile *P)
{
    int i;
    T_Pile T;
    int a; 
    int f;
    
    initPile(&T);
    if(pilevide(P)){
        printf("La pile est vide");
        
    }
    else{
        f=P->nbElts;
        for(i=0;i<=f;i++){
            empiler(&T,sommet(P));
            depiler(P, &a);
            printf("<%d>", a);
    }
    for (i=0;i<T.nbElts;i++){
        empiler(P,sommet(&T));
        depiler(&T,&a);
    }
    }
}



void testPile(T_Pile *mapile)
{
    int chx;
    int menu()
    {

        int choix;
        printf("\n\n\n Test de la pile ! ");
        printf("\n\n\n 1 : initialiser la pile ");
        printf("\n 2 : Tester pile pleine");
        printf("\n 3 : Tester pile vide");
        printf("\n 4 : empiler ");
        printf("\n 5 :  dépiler  ");
        printf("\n 6 :  Voir le sommet  ");
        printf("\n 7 :  Quelle est la hauteur  ");
        printf("\n 8 :  Afficher la pile  ");
        printf("\n 0 :  Quitter  ");
        printf("\n votre choix ?  ");
        scanf("%d",&choix);
        getchar();
        return choix;
    }

    do
    {
        chx=menu();
        int a;
        T_Elt emp;
        switch (chx)
        {
            case 1 :  
            initPile(mapile);
            break;

            case 2 :
            a=pilepleine(mapile);
            if(a==1)printf("La pile est pleine");
            else printf("La pile n'est pas pleine");
            break;

            case 3 :
            a=pilevide(mapile);
            if(a==1)printf("La pile est vide");
            else printf("La pile n'est pas vide");
            break;

            case 4 :
            printf("Entrez un entier à empiler");
            scanf("%d",&emp);
            getchar();
            a=empiler(mapile,emp);
            if(a==1)printf("L'entier a été empilé");
            else printf("L'entier n'a pas été empilé");
            break;

            case 5 :
            a=depiler(mapile,&emp);
            if(a==1)printf("L'entier a été dépiler");
            else printf("L'entier n'a pas été dépiler");
            break;

            case 6 :
            printf("Le sommet de la pile est %d",sommet(mapile));
            break;

            case 7 :
            printf("La hauteur de la pile est %d",hauteur(mapile));
            break;

            case 8 :
            afficherPile(mapile);
            break;
        }
    }while(chx!=0);

    printf("\test fini\n");
    
    


}




