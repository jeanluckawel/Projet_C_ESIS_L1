#include <stdio.h>
#include <string.h>

typedef struct Personne{
    char nomPersonne[30];
    char telPersonne[10];
}Personne;
// Fonction Aquisition
int Acquisition (Personne Pers[]) {
    printf("Entrer le nom");
    scanf("%s",Pers->nomPersonne);
    printf("Entrer le numero");
    scanf("%s",Pers->telPersonne);

    if (strlen(*Pers->nomPersonne)<=30 && strlen(Pers->telPersonne)==10 && Pers->telPersonne[0]=='0' && (Pers->telPersonne[1]=='8' ||  Pers->telPersonne[1]=='9' ))
        return 1;
    else
        return 0;
}
//Fonction Ajoute
void Ajoute(Personne Annuaire[],Personne Pers){
    int PasDePersonne=-1;
    int i;
    for (i = 0; i < 7; i++) {
        if (strcmp(Annuaire[i].nomPersonne,Pers.nomPersonne)==0)
            PasDePersonne=i;
    }
    if (PasDePersonne==-1){
        Annuaire[0]=Pers;
    }
    else
        Annuaire [PasDePersonne]=Pers;
}
// Fonction Affiche
void Affiche(Personne *Annuaire){
    int i;
    for (i = 0; i < 7; i++)
    printf("%s NOM : %s TEL\n", Annuaire[i].nomPersonne, Annuaire[i].telPersonne);
}
void RechercheTel(Personne Annuaire[]){
    char nomPers[30];
    printf("taper le nom");
    scanf("%s",nom);
    int i;
    for (i = 0; i < 7; i++) {
        if (strcmp(Annuaire[i].nomPersonne,nom))
            printf("Voici votre : numero %s", Annuaire->telPersonne);
    }
}
//rechercheNom

void RechercheNom(Personne Annuaire[]){
    char tel[10];
    printf("taper votre nom");
    scanf("%s",tel);
    int i;
    for (i = 0; i < 7; i++) {
        if (strcmp(Annuaire[i].telPersonne,tel))
            printf("Voici votre : numero %s", Annuaire->telPersonne);

    }
    int pasDeNum=0;
    if (pasDeNum != 1){
        printf(" pas ce numéro dans l'annuaire!");
    }
}

//Efface


int main (void){
    Personne Annuaire[7];
    printf("##########  Menu Principal  ##########\n1.Ajouter une personne a l'annuaire\n2.fficher le contenu de l'annuaire dans l'ordre alphabétique");
    int choix;
    printf("Taper votre choix------------:>");
    scanf("%d",&choix);
    switch (choix) {
        case 1:
            printf("bonjour");
            break;
    }
    return 0;
}