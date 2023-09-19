#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "procedures.h"

// Procedure qui Alloue un espace memoire pour le maillon
void Allouer(ptr* p)
{
    *p = (ptr)malloc(sizeof(soutenances));
}
// Procédure qui détruit le maillon pointé par p.
void Liberer (ptr p)
{
    free(p);
}
// Procédure qui affecte q dans le champ (adr) du maillon pointé par p.
void Aff_adr(ptr p, ptr q)
{
    p->adr = q ;     // (p->adr) est l'équivalent de (*p.adr)
}
// Fonction qui retourne le contenu du champ (adr) du maillon pointé par p.
ptr Suivant (ptr p)
{
    return p->adr; // retourner l'adresse de maillon suivant
}
// procedure qui etourne ID de participant
char* ID(ptr p)
{
    return p->ID;
}
void AFF_id(ptr p, char  N[10])
{
    *p->ID = N ;// (p->NoteP) est l'équivalent de (*p.NoteP)
}
void AffichLLC (ptr L)
{
    ptr p = L;
    char chaine[256]="";
    while(p != NULL)
    {
        printf(" \n Date:  %s ", dat(p,chaine));
        printf(" \n Heure: %s ", heur(p,chaine));
        printf(" \n ID: %s ", ValId(p,chaine));
        printf("  \n Titre: %s",Tit(p,chaine));
        printf(" \n Etudiant: %s ", etud(p,chaine));
        printf(" \n Jury: %s ;", jury1(p,chaine));
        printf(" %s", jury2(p,chaine));
        printf(" \n \n");
        p = Suivant(p);

    }
    printf(" \n");
}

void   ValId (ptr p,char ch[256])
{
    strcpy(ch,(*p).ID);
}
void   Tit (ptr p,char ch[256])
{
    strcpy(ch, (*p).titre);
}
void  jury1(ptr p,char ch[256] )
{
    strcpy(ch,(*p).JURY.membre1);

}
void  jury2(ptr p,char ch[256] )
{
    strcpy(ch,(*p).JURY.membre2);
}
void   dat(ptr p,char* ch[20])
{
    strcpy(ch, (*p).DATE.j);
}
void  heur(ptr p , char* ch[20])
{
    strcpy(ch,(*p).DATE.h);
}
//la procedure pour retourner le nom et le prenom du soutenance//
void   etud (ptr p, char ch[256])
{
    strcpy(ch ,(*p).etudiants);

}
void CpyMaillon(ptr p,ptr q)
{

 strcpy((*q).DATE.j,(*p).DATE.j);
 strcpy((*q).DATE.h,(*p).DATE.h);
  strcpy((*q).ID,(*p).ID);
 strcpy((*q).titre,(*p).titre);
 strcpy((*q).etudiants,(*p).etudiants);
 strcpy((*q).JURY.membre1,(*p).JURY.membre1);
 strcpy((*q).JURY.membre2,(*p).JURY.membre2);

};
void substring(char str[10],char substrg[10],int a,int b )
{
    int y=0;
    while (y<b)
    {
        substrg[y]= str[y+a];
        y++;
    }
    substrg[b]='\0';
}
void affichage_salle() // Afficher le programme des soutenances d’une salle donnée.
{
    int rep=0; //rep contient le numero de la salle CP
    printf("**********************************************Affichage par salle:**********************************************\n\n");
    textcolor(3);
    printf("\n choisissez une salle:\n\n");
        printf("\n1.Salle CP1");
        printf("\n2.Salle CP2");
        printf("\n3.Salle CP3");
        printf("\n4.Salle CP4\n");
        printf("\nVeuillez enter votre reponse :  ");

scanf("%d",&rep);
    switch (rep)
    {
    case 1: AffichLLC(salle[0]);
    break;
    case 2: AffichLLC(salle[1]);
    break;
    case 3: AffichLLC(salle[2]);
    break;
    case 4: AffichLLC(salle[3]);
    break;
    default: printf("Vous avez entre un caractere non valide, veuillez reessayer");
    }
    }
    void affichage_date() //Afficher le programme des soutenances dans une date donnée
    {
    int r=0,j=0; //r contiendra la reponse et j+1 le numero de la salle
    ptr p=NULL;
    textcolor(7);
    printf("**********************************************Affichage par date:**********************************************\n\n");
    printf("\nchoisissez une date:\n\n");


        printf("\n 1 > 10/04/2022");
        printf("\n 2 > 11/04/2022");
        printf("\n 3 > 12/04/2022");
        printf("\n 4 > 13/04/2022");
        printf("\n 5 > 14/04/2022");
    printf("\n Veuillez enter votre reponse :  ");

scanf("%d",&r);
    switch (r)
    {
    case 1: {
       for(j=0;j<4;j++){
            p=salle[j];
            while (p!=NULL){
        if (strcmp((*p).DATE.j,"10/04/2022")==0){
            AffichMaillon(p);
        }
            p=Suivant(p);
        }
       }
    }
    break;
    case 2:{
       for(j=0;j<4;j++){
            p=salle[j];
            while (p!=NULL){
        if (strcmp((*p).DATE.j,"11/04/2022")==0){
            AffichMaillon(p);
        }
            p=Suivant(p);
        }
       }
    }
    break;
    case 3: {
       for(j=0;j<4;j++){
            p=salle[j];
            while (p!=NULL){
        if (strcmp((*p).DATE.j,"12/04/2022")==0){
            AffichMaillon(p);
        }
            p=Suivant(p);
        }
       }
    }
    break;
    case 4:{
       for(j=0;j<4;j++){
            p=salle[j];
            while (p!=NULL){
        if (strcmp((*p).DATE.j,"13/04/2022")==0){
            AffichMaillon(p);
        }
            p=Suivant(p);
        }
       }
    }
    break;
    case 5: {
       for(j=0;j<4;j++){
            p=salle[j];
            while (p!=NULL){
        if (strcmp((*p).DATE.j,"14/04/2022")==0){
            AffichMaillon(p);
        }
            p=Suivant(p);
        }
       }
    }
    break;
    default: printf("Vous avez entre une caractere non valide, veuillez reessayer");
    }
}
void affichage_specialite(){ //cette procédure affiche les soutenances selon une spécialité sélectionnée
        int answer=0,m=0; //answer contiendra le numéro associé à chaque spécialité
        ptr p,q=NULL;
  textcolor(3);
printf("**********************************************Affichage par specialite:**********************************************\n\n");
printf("\n choisissez une specialite:\n\n");
        printf("\n 1 > SIQ");
        printf("\n 2 > SIT");
        printf("\n 3 > SIL");
        printf("\n Veuillez entrer votre reponse : ");

scanf("%d",&answer);
    switch (answer)
    {
    case 1:{
        for(m=0;m<4;m++){
            p=salle[m];
            while (p!=NULL){

        if (p->ID[2]=='Q'){
            AffichMaillon(p);
        }
            p=Suivant(p);
        }
       }

    }
    break;
    case 2:{
        for(m=0;m<4;m++){
            q=salle[m];
            while (q!=NULL){
        if ((*q).ID[2]=='T'){
            AffichMaillon(q);
        }
            q=Suivant(q);
        }
       }

    }
    break;
    case 3:{
        for(m=0;m<4;m++)
        {
            q=salle[m];
            while (q!=NULL)
            {
        if ((*q).ID[2]=='L')
        {
            AffichMaillon(q);
        }
            q=Suivant(q);
        }
       }

    }
    break;

    default: printf("Vous avez entre un caractere non valide, veuillez reessayer");
    }
    }
    void affichage_jury()//Afficher toutes les soutenances d’une spécialité donnée (SIL, SIT ou SIQ).
    {
char fn[100]="",ln[100]="";
int e=0;                            //indice de parcours des salles
ptr pointeur=NULL;
printf("entrez le nom: ");
scanf("%s",fn);
printf("entrez le prenom: ");
scanf("%s",ln);
strcat(fn," ");
strcat(fn,ln);
strcpy(fn,strupr(fn));
for(e=0;e<4;e++){
        pointeur=salle[e];
    while (pointeur!=NULL){
        if (strcmp(strupr(pointeur->JURY.membre1),strupr(fn))==0 || strcmp(strupr(pointeur->JURY.membre2),strupr(fn))==0 ){
            AffichMaillon(pointeur);
        }
     pointeur=Suivant(pointeur);
    }
    }
    }
    void AffichMaillon (ptr p)// cette procedure sert à affichier un seule mallion
{



        printf(" \n Date:  %s ", p->DATE.j);
        printf(" \n Heure: %s ", p->DATE.h);
        printf(" \n ID: %s ", p->ID);
        printf(" \n Titre: %s",p->titre);
        printf(" \n Etudiant: %s ", p->etudiants);
        printf(" \n Jury: %s ;", p->JURY.membre1);
        printf("%s", p->JURY.membre2);
        printf(" \n \n");
        printf(" \n");
}
int jury_disponible(char nom[100],char prenom[100],char date[20],char heure[20]){ //chercher si le jury choisi est libre dans une date et heure précises et retourner 1 si oui,0 sinon
    int i=0,v=1;//on suppose que le jury est libre jusqu'à preuve du contraire
    ptr pp=NULL;
    char sauvn[200]="";
    strcpy(sauvn,nom);
    strcat(sauvn," ");
    strcat(sauvn,prenom);
    strcpy(sauvn,strupr(sauvn));

    for(i=0;i<4;i++){
    pp=salle[i];
        while (pp!=NULL && v==1){

      if ((strcmp(sauvn,strupr(pp->JURY.membre1))==0 || strcmp(sauvn,strupr(pp->JURY.membre2))==0) && strcmp(pp->DATE.h,heure)==0 && strcmp(pp->DATE.j,date)==0){
           v=0;
        }
            pp=Suivant(pp);
        }
      }
 return v;
}


int exist_soutenance(int sa,char date[20],char heure[20]){ //chercher si le jury choisi est libre dans une date et heure précises et retourner 1 si oui,0 sinon
    int v=0;//on suppose que la soutenance n'existe pas
    ptr q = NULL;
    q=salle[sa];
    while (q!=NULL && v==0){
      if (strcmp(q->DATE.h,heure)==0 && strcmp(q->DATE.j,date)==0){
           v=1;
        }
            q=Suivant(q);
        }

 return v;
}
void TriBullesLLC (ptr L)   // trier les listes des soutenances par ID
{
    char f[100],ju[100];
    ptr p,g,q = NULL;
    int perm ;
     struct soutenances temp;
    perm =1 ;
    while (perm == 1)
    {
        perm = 0;         // Mettre permut à faux au début de chaque passage
        p = L;

        while (Suivant(p)!= q)
        {
             g=Suivant(p);
            substring(g->ID,f,3,3);
            substring(p->ID,ju,3,3);
             char se[10];
       if ( atoi(ju) > atoi(f))
            {

       strcpy(temp.ID , (*p).ID);
       temp.DATE = p->DATE;
        strcpy(temp.etudiants,p->etudiants);
        strcpy(temp.titre,p->titre);
       temp.JURY=p->JURY;

        strcpy(p->ID,g->ID);
       p->DATE=g->DATE;
       strcpy(p->etudiants,g->etudiants);
        strcpy(p->titre,g->titre);
       p->JURY=g->JURY;


        strcpy(g->ID,temp.ID);
        g->DATE=temp.DATE;
        strcpy(g->etudiants,temp.etudiants);
        strcpy(g->titre,temp.titre);
        g->JURY=temp.JURY;

            perm = 1;
            }
            p = Suivant(p);

        }
       q=p;                   // Mettre à jour la limite supérieure pour le prochain passage
    }    // S’arrêter quand il n’y a plus de permutations
}




