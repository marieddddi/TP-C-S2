
// TP GESTION D'UNE BIBLIOTHEQUE 
#include "biblio.h"



int menu()
{
	int choix;
// au programme du TP7 :
	printf("\n\n 1 - ajouter un nouveau livre dans la bibliotheque "); 
	printf("\n 2 - afficher tous les livres de la bibliotheque "); 
	printf("\n 3 - rechercher un livre (par son titre)");  // il peut y avoir plusieurs livres de même titre. Dans ce cas, indiquez le nombre d'exemplaires disponibles
	printf("\n 4 - rechercher et afficher tous les livres d'un auteur");
	printf("\n 5 - supprimer un livre de la bibliotheque");
// si les 5 choix ci dessus sont bien codés, modifiez votre structure T_Livre et passez à 5 champs (avec code,editeur et annee)


// au programme du TP8 :
// ajouter le champ emprunteur à votre structure T_Livre
	printf("\n 6 - emprunter un livre de la bibliotheque");
	printf("\n 7 - restituer/rendre un livre de la bibliotheque");
	printf("\n 8 - trier les livres (par titre)");
	printf("\n 9 - trier les livres (par auteur)");
	printf("\n 10 - trier les livres (par annee)");

// si les 5 choix (6-10) sont bien codés, changez le type T_Emp et remplacez-le par la structure T_Emp visible dans livre.h
// vous pourrez alors faire les menus 11,12,etc...
printf("\n 11- lister les livres disponibles "); 
printf("\n 12 - lister les emprunts en retard "); //on suppose qu'un emprunt dure 7 jours.
printf("\n 13 - combien de livres une personne a emprunté ?");

	printf("\n 0 - QUITTER");
	printf("\n Votre choix : ");
	scanf("%d[^\n]",&choix);getchar();
	return choix;
}



int main()
{
	int reponse,chx;
	T_Bibliotheque B; 
	init( &B );
	T_Titre titre;
	T_Aut auteur;
	int a;
	T_Emp emp;
	T_livre livre;
	
	
	
	
	do
	{
		chargement(&B);
		chx= menu();
		switch(chx)
		{
			
			case 1 : printf("\n");
					 reponse = ajouterLivre(&B);
					 if (reponse==1) printf(" ajout reussi !!");
					 else printf("impossible d ajouter (bibliotheque pleine)");
					 break;
					 
			case 2 : printf("\n");
					 reponse=afficherBibliotheque(&B);
					 if (reponse==0)	
					 printf("La bibliotheque est vide");
					 break;
					
			case 3 : printf("\n");
					 lireChaine("quel titre ?\n", titre, MAX_TITRE );
					 a=rechercherLivre(&B,titre);
					 if(a==0)printf("le livre n'y est pas\n");
					 else printf("le livre est présent %d fois \n",a);
					 break;
					
			case 4 : printf("\n");
					 lireChaine("quel auteur ?\n", auteur, K_MaxAut );
					 AffRechAuteur(&B,auteur);
					 break;
					
			case 5 : printf("\n");
					 lireChaine("quel auteur souhaitez-vous supprimer ?\n", livre.auteur, K_MaxAut );
					 lireChaine("quel titre de cet auteur souhaitez-vous supprimer ?\n", livre.titre, MAX_TITRE );
					 a=SuppLivre(&B,&livre);
					 if(a==0)printf("le livre n'y est pas\n");
					 else printf("le livre est bien supprimé\n");
					 break;	
					 
			case 6 : printf("\n");
					 lireChaine("quel titre souhaitez vous emprunter ?", livre.titre, MAX_TITRE);	
					 lireChaine("quel est son code ?", livre.code, MAX_CODE);
					 printf("quel est votre nom ?\n");
					 lire(emp.nomemprunteur, MAX);	
					 a=Emprunter(&B,&livre,&emp);
					 if(a==0)printf("le livre est déjà emprunté ou il n'existe pas \n");
					 else printf("vous avez bein emprunté ce livre \n");
					 break;	
					 
		    case 7 : printf("\n");
					 lireChaine("quel titre souhaitez vous rendre ?", livre.titre, MAX_TITRE);	
					 lireChaine("quel est son code ?", livre.code, MAX_CODE);
					 printf("quel est votre nom ?\n");
					 lire(emp.nomemprunteur, MAX);	
					 a=RendreLivre(&B,&livre,&emp);
					 if(a==0)printf("le livre n'est pas à vous\n");
					 else printf("le livre est bien rendu merci \n");
					 break;	

			case 8 : printf("\n");
					 TriTitre(&B);
					 printf("voici la bibliotheque triée par titre :\n");
					 afficherBibliotheque(&B);
					 break;	

			case 9 : printf("\n");
					 TriAut(&B);
					 printf("voici la bibliotheque triée par auteur :\n");
					 afficherBibliotheque(&B);	
					 break;	

			case 10 : printf("\n");
					  TriAnnee(&B);
					  printf("voici la bibliotheque triée par année :\n");
					  afficherBibliotheque(&B);
					  break;	

			case 11 : printf("\n");
					  printf("voici la liste des livres disponibles :\n");
					  listerLivreDispo(&B);
					  break;	

			case 12 : printf("\n");	
					  printf("voici la liste des livres en retard :\n");
					  listerRetard(&B) ;
					  break;
					

			case 13 : printf("\n");
					  printf("quel est votre nom ?\n");
					  lire(emp.nomemprunteur, MAX);	
					  a=NbLivresEmpruntes(&B,&emp);
					  printf("Vous avez emprunté %d livre(s) \n",a);
					  printf("\n");	
					  break;
					
			
		}
		sauvegarde(&B);

	}
	while(chx!=0);
	return 0;

}