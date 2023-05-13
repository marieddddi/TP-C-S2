#include "file.h" 


void initFile(T_File *ptrF) //mettre Tete et Queue à -1
{
    ptrF->Tete=-1 ;
    ptrF->Queue=-1 ;
}

int  retirer(T_File *ptrF,T_Elt *ptrE) //si pas vide, en tete de file
{
    if(fileVide(ptrF)==1){
        printf("file vide, peut pas retirer ! \n");
        return 0 ;
    }
    
    if((ptrF->Tete)==(ptrF->Queue)) {
        printf("testinit");
        initFile(ptrF);
        return 1;
    }

    *ptrE=(ptrF->Elts[ptrF->Tete]);
    printf("ok");
    (ptrF->Tete)=(ptrF->Tete)+1 ;
    return 1;
   
    
    
    
}

int ajouter(T_File *ptrF,T_Elt *ptrE) // si espace libre, ajout en queue
{
    if(filePleine(ptrF)==1){
        printf("file pleine, ajout impossible ! \n");
        return 0;
    }
    else {
        if((ptrF->Queue)!=(MAX-1)){
        ptrF->Queue=(ptrF->Queue)+1 ;
        ptrF->Elts[ptrF->Queue]=*ptrE;
        return 1 ;
        }
        else {
            printf("la");
            ptrF->Queue=0;
            ptrF->Elts[ptrF->Queue]=*ptrE;
            return 1 ;
        }
    }
} 

int fileVide(const  T_File *prtF) // qd Tete == -1 
{
    if((prtF->Queue)==-1) return 1;
    else return 0;
}


int filePleine(const  T_File *ptrF) // qd MAX elts dans la file 
{
   
    if(((ptrF->Queue)-(ptrF->Tete)==(MAX-1))||((ptrF->Queue)-(ptrF->Tete)==-1)){
        return 1 ;
    }
    else return 0;
}






T_Elt premier(T_File *ptrF) //valeur en tete de file
{
    T_Elt premier ;
    premier = ptrF->Tete;
    printf("voici le premier element de la file ! \n");
    return premier;
}

void afficherFile(T_File *ptrF)
{
    int i ;
    if((ptrF->Tete)>(ptrF->Queue)){

        for (i=(ptrF->Tete) ; i<MAX ;i++){
            printf("<%d>", ptrF->Elts[i]);
        }
        for (i=0 ; i<=ptrF->Queue ;i++){
            printf("<%d>", ptrF->Elts[i]);
        }
    }
    if((ptrF->Tete)<(ptrF->Queue)){
        for (i=((ptrF->Tete)) ; i<=(ptrF->Queue) ;i++){
            printf("<%d>", ptrF->Elts[i]);
        }
    }
    if(ptrF->Tete==ptrF->Queue) printf("%d \n", ptrF->Elts[ptrF->Queue]);
    if (fileVide(ptrF))printf ("file vide ! \n");
}






void testFile(T_File *mafile)
{
    int chx;
    int menu()
    {

        int choix;
        printf("\n\n\n Test de la file ! ");
        printf("\n\n\n 1 : initialiser la file ");
        printf("\n 2 : retirer un element de la file");
        printf("\n 3 : ajouter un element à la file");
        printf("\n 4 : tester si la file est vide ");
        printf("\n 5 : tester si la file est pleine  ");
        printf("\n 6 : afficher la valeur de la tete  ");
        printf("\n 7 : afficher la file  ");
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
        T_Elt emf;
        switch (chx)
        {
            case 1 :  
            initFile(mafile);
            break;

            case 2 :
            a=retirer(mafile,&emf);
            if(a==1)printf("L'entier a été retiré");
            else printf("L'entier n'a pas été retiré");
            break;

            case 3 :
           
            printf("Entrez un entier à ajouter à la file : ");
            scanf("%d",&emf);
            getchar();
             a=ajouter(mafile,&emf);
            if(a==1)printf("L'entier a été ajouté");
            else printf("L'entier n'a pas été ajouté");
            break;

            case 4 :
            a=fileVide(mafile);
            if(a==1)printf("La file est vide");
            else printf("La file n'est pas vide");
            break;

            case 5 :
            a=filePleine(mafile);
            if(a==1)printf("La file est pleine");
            else printf("La file n'est pas pleine");
            break;

            case 6 :
           printf("La valeur de la tete est %d",premier(mafile));
            break;

            case 7 :
            afficherFile(mafile);
            break;

        }
    }while(chx!=0);

    printf("\test fini\n");
   

}

