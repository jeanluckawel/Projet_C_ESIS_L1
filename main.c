#include <stdio.h>
#include <string.h>

typedef struct Personne {
    char nomPersonne[31];
    char telPersonne[11];
}Personne;

// Fonction Aquisition
int Acquisition (char *nom, char *num) {

    if (strlen(nom)<=30 && strlen(num) == 10 ) {
        if (num[0] == '0' && (num[1] == '8' || num[1] == '9'))
            return 1;
    }
    else
        return 0;
    return 0;
}

//Fonction Ajoute
void Ajoute(Personne Annuaire[], char *nom, char *numero , int *nombre_personne)
{
    if(Acquisition(nom, numero))
    {
        strcpy(Annuaire[*nombre_personne].nomPersonne, nom);
        strcpy(Annuaire[*nombre_personne].telPersonne, numero);
        *nombre_personne += 1;

        printf("nobre de personne: %d", *nombre_personne);
        //printf("Nom: %s Num: %s \n", Annuaire[*nombre_personne].nomPersonne, Annuaire[*nombre_personne].telPersonne );
    }
    else
        printf("Ajoute impossible ! \n");
}

// Fonction Affiche
void Affiche(Personne *Annuaire, const int *nombre_personne){

    for(int i = 0; i < *nombre_personne; i++) {

        if(strlen(Annuaire[i].nomPersonne) > 0)
            printf("NOM :%s  TEL: %s\n", Annuaire[i].nomPersonne, Annuaire[i].telPersonne);
        }
    }

void RechercheTel(Personne Annuaire[], const int *nombre_personne){

    char nomPers[31];
    int i;

    printf("taper le nom    : ");
    scanf("%s",nomPers);
    for (i = 0; i < *nombre_personne; i++)
    {
        if (strcmp(Annuaire[i].nomPersonne,nomPers) == 0)
            printf("Voici votre : numero %s", Annuaire[i].telPersonne);
    }
}
//rechercheNom

void RechercheNom(Personne Annuaire[],const int *nombre_personne){
    char tel[10];

    printf("taper votre numeros");
    scanf("%s", tel);

    int i, pasDeNum=0;
    for (i = 0; i < *nombre_personne; i++) {
        if (strcmp(Annuaire[i].telPersonne,tel) == 0)
        {
            printf("NOM: %s", Annuaire[i].nomPersonne);
            pasDeNum++;
        }
    }

    if (pasDeNum == 0){
        printf(" pas ce numéro dans l'annuaire!");
    }
}

//Efface


void supprimer(Personne *rep, const int *taille, char *nom)
{
    int i,j;
    Personne t={"",0};
    printf("Entrer le nom a supprimer");
    scanf("%s",nom);
    for ( i = 0; i < *taille; i++)
    {
        if (strcmp(rep[i].nomPersonne,nom) == 0)
        {
            for ( j = 1; j < *taille; j++)
            {
                rep[j] = rep[j + 1];
            }
            rep[*taille -1 ] = t;
            break;
        }

    }


}


int main (void){
    int nombre_personne = 0;
    Personne Annuaire[100];
    int choix = 0 , Programme = 1;
    char nom[31], num[11];

    while(Programme){
        printf("\n##########  Menu Principal  ##########\n1.Ajouter l'Annuaire \n "
               "2.Afficher une personne\n "
               "3.supprimer une personne\n "
               "4.rechercher un numero de telephone\n "
               "5.trouver a qui appartient un certain numero\n "
               "6. sortir du programme\n");

        printf("Taper votre choix   :");
        scanf("%d",&choix);

        switch (choix) {
            case 1:
                printf("\n#######[IDENTIFIANT]#######\n");

                printf("Nom\t:");
                scanf("%s",nom);

                printf("Numeros\t:");
                scanf("%s",num);

                Ajoute(Annuaire, nom, num, &nombre_personne);

                break;

            case 2:
                Affiche(Annuaire, &nombre_personne);
                break;
            case 3:

                supprimer(Annuaire,&nombre_personne,nom);

                break;
            case 4:
                RechercheTel(Annuaire,&nombre_personne);
                break;
            case 5:
                RechercheNom(Annuaire,&nombre_personne);
                break;
            case 6:
                printf("Fin de la partie :)");
                Programme = 0 ;
                break;
            default:
                printf("Mauvaise entree!");
        }
    }

    return 0;
}