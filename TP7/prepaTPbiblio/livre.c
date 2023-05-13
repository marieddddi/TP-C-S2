#include "livre.h"


void saisirLivre(T_livre * ptrL)
{
    lireChaine("TITRE :", (ptrL->titre), MAX_TITRE );
    lireChaine("AUTEUR :", (ptrL->auteur ), MAX);
    lireChaine("CODE :", (ptrL->code), K_MaxCode);
    printf("ANNEE :");
    scanf("%d",&(ptrL->annee));
    getchar();
    lireChaine("EDITEUR :", (ptrL->editeur), K_MaxEdit);
    strcpy(ptrL->emprunteur.nomemprunteur,"\0");
}




void afficherLivre(const T_livre *ptrL)
{
    char jour[13],mois[13];
    printf("\n");
    afficherChaine("TITRE :", (ptrL->titre));
    printf(" - ");
    afficherChaine("AUTEUR :", (ptrL->auteur ));
    printf(" - ");
    afficherChaine("CODE:", (ptrL->code ));
    printf(" - ");
    printf("ANNEE :%d",ptrL->annee);
    printf(" - ");
    afficherChaine("EDITEUR :", (ptrL->editeur ));
    printf(" - ");
    afficherChaine("EMPRUNTEUR :", (ptrL->emprunteur.nomemprunteur));
    printf(" \n- ");
    

    switch(ptrL->emprunteur.lejour)
    {
        case 0 :  strcpy(jour,"lundi");break;
        case 1 :  strcpy(jour,"mardi");break;
        case 2 :  strcpy(jour,"mercredi");break;
        case 3 :  strcpy(jour,"jeudi");break;
        case 4 :  strcpy(jour,"vendredi");break;
        case 5 :  strcpy(jour,"samedi");break;
        case 6 :  strcpy(jour,"dimanche");break;

        default : strcpy(jour,"jour inconnu");break;
    }
    printf("%s ",jour);

    printf("%d ",ptrL->emprunteur.ledate);


    switch(ptrL->emprunteur.lemois)
    {
        case 0 :  strcpy(mois,"janvier");break;
        case 1 :  strcpy(mois,"fevrier");break;
        case 2 :  strcpy(mois,"mars");break;
        case 3 :  strcpy(mois,"avril");break;
        case 4 :  strcpy(mois,"mai");break;
        case 5 :  strcpy(mois,"juin");break;
        case 6 :  strcpy(mois,"juillet");break;
        case 7 :  strcpy(mois,"aout");break;
        case 8 :  strcpy(mois,"septembre");break;
        case 9 :  strcpy(mois,"octobre");break;
        case 10 :  strcpy(mois,"novembre");break;
        case 11 :  strcpy(mois,"decembre");break;

        default : strcpy(jour,"mois inconnu");break;
    }
    printf("%s ",mois);

    printf("%d ",ptrL->emprunteur.lannee);
    printf("\n\n");
}






void lireDateSysteme(T_Emp *E)
{
    char j[9],m[10],h[9],mer[11],vir[2];
    int d,a;

    system("date > ladate"	);
    FILE * fic=NULL;  // pointeur de fichier
    fic=fopen("ladate","r"); //fileOpen en mode 'r'EAD

    //ici , si fic vaut NULL, alors le fopen a indiqué
    //que le fichier ladate n'est pas accessible
    if (fic!=NULL)
    {
        while(!feof(fic))	
        {
            fscanf(fic,"%s %d %s %d %s %s %s",j,&d,m,&a,vir,h,mer);		
            if (!feof(fic)) 
                printf("\n-->LU : %s- %d- %s- %d- %s- %s",j,d,m,a,h,mer);		

        }
        fclose(fic);
        
        if (strcmp(j,"lundi")==0) E->lejour=lundi;
        else if (strcmp(j,"mardi")==0) E->lejour=mardi;
        else if (strcmp(j,"mercredi")==0) E->lejour=mercredi;
        else if (strcmp(j,"jeudi")==0) E->lejour=jeudi;
        else if (strcmp(j,"vendredi")==0) E->lejour=vendredi;
        else if (strcmp(j,"samedi")==0) E->lejour=samedi;
        else if (strcmp(j,"dimanche")==0) E->lejour=dimanche;

        E->ledate=d;

        if (strcmp(m,"janvier")==0) E->lemois=janvier;
        else if (strcmp(m,"fevrier")==0) E->lemois=fevrier;
        else if (strcmp(m,"mars")==0) E->lemois=mars;
        else if (strcmp(m,"avril")==0) E->lemois=avril;
        else if (strcmp(m,"mai")==0) E->lemois=mai;
        else if (strcmp(m,"juin")==0) E->lemois=juin;
        else if (strcmp(m,"juillet")==0) E->lemois=juillet;
        else if (strcmp(m,"aout")==0) E->lemois=aout;
        else if (strcmp(m,"septembre")==0) E->lemois=septembre;
        else if (strcmp(m,"octobre")==0) E->lemois=octobre;
        else if (strcmp(m,"novembre")==0) E->lemois=novembre;
        else if (strcmp(m,"decembre")==0) E->lemois=decembre;


        E->lannee=a;
    }
    else
    {
        printf("n souci avec la date systeme !!");
            
        //on range une date irréelle 
        E->lejour=dimanche;
        E->ledate=99;
        E->lemois=decembre;
        E->lannee=-999;

    }

}
