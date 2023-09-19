#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "procedures.h"
#include "conio.c"
#include "keyboard.h"

int main()
{

    ptr p,q;
    int i=0;

   /*remplir la liste a partir du fichier */

   FILE *ptf = fopen ("programme.txt","r");
   char ch[256],ch2[256],ch3[10],ch6[256];
   char ch4[256],ch5[256];
   if (ptf == NULL)
{
    printf ("ce fichier n'existe pas");
    exit (1);

}
//*****************************************INITIALISATION DES DONNEES *******************************************//
char f[100],ju[100];
void TriBullesLLCin (ptr L)   // cette procedure sert à trier les listes initiales par ordre chronologique
{

    ptr p,q = NULL;
    int perm ;
     ptr g;
     soutenances temp;
    perm =1 ;
    while (perm ==1)
    {

        perm = 0;         // Mettre permut à faux au début de chaque passage
        p = L;

        while (Suivant(p)!= q)
         {


             g=Suivant(p);
            substring(g->DATE.h,f,0,2);
            substring(p->DATE.h,ju,0,2);
          if (strcmp(p->DATE.j,g->DATE.j)==0)
          {


            if ( atoi(ju) > atoi(f))
            {


        strcpy(temp.ID,(*p).ID);

        temp.DATE=p->DATE;
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
          }
            p = Suivant(p);

        }
         q=p;
    }  // Mettre à jour la limite supérieure pour le prochain passage


    } // S’arrêter quand il n’y a plus de permutations
void INITIALISATION_DES_DONNEES()// Cette procedure sert à initialiser les données (remplir les listes) et les triées
{
fscanf(ptf,"%s",ch);

while(!feof(ptf))// on repete jusqu'au on arive a la fin du fichier
    {
for (i=0 ;i<4;i++ ) // créer un tableau de listes
{
// remplir le premier mallion
//******************************************************************************************
 Allouer(&p);

     salle[i]=p;
     q = p;
     fscanf (ptf,"%s",ch);
     fscanf (ptf,"%s %s ",ch,(*p).DATE.j);
     fscanf (ptf,"%s %s",ch,(*p).DATE.h);
     fscanf (ptf,"%s %s",ch,(*p).ID);
     fscanf (ptf,"%s",ch);
     if (strcmp(ch,"Titre:")==0)
    {
     strcpy((*p).titre,"");

    strcpy (ch3," ");
    strcpy(ch2,"");
    while (strcmp(ch2,"Etudiant: ")!=0)
       {
        strcat((*p).titre,ch2);
        fscanf (ptf,"%s",ch2);
        strcat(ch2,ch3);
       };
     }
        strcpy(ch2,"");
        strcpy((*p).etudiants,"");
      while (strcmp(ch2,"Jury: ")!=0)
      {
         strcat((*p).etudiants,ch2);
         fscanf (ptf,"%s",ch2);
          strcpy(ch6,ch2);
         strcat(ch2,ch3);
      }


      fscanf(ptf,"%s %s %s %s %s",ch2,ch3,ch,ch4,ch5);
       strcpy (ch6," ");
       strcat(ch2,ch6);
       strcat(ch2,ch3);
      strcpy((*p).JURY.membre1,ch2);

       strcpy (ch,ch5);
       strcat(ch4,ch6);
       strcat(ch4,ch5);
       strcpy((*p).JURY.membre2,ch4);
       fscanf(ptf,"%s",ch);
//*************************************************************************************
// remplir les autres mallions

     while (strcmp(ch,"Salle:")!=0 && !feof(ptf))
      {
     Allouer(&p);
     fscanf (ptf,"%s",(*p).DATE.j);
     fscanf (ptf,"%s %s",ch,(*p).DATE.h) ;
     fscanf (ptf,"%s %s",ch,(*p).ID);
     fscanf (ptf,"%s",ch);
     char ch3[256];

     if (strcmp(ch,"Titre:")==0)
    {
     strcpy((*p).titre,"");

    strcpy (ch3," ");
    strcpy(ch2,"");
    while (strcmp(ch2,"Etudiant: ")!=0)
       {
        strcat((*p).titre,ch2);
        fscanf (ptf,"%s",ch2);
        strcat(ch2,ch3);

       };
     }

        strcpy(ch2,"");
        strcpy((*p).etudiants,"");
      while (strcmp(ch2,"Jury: ")!=0)
      {
         strcat((*p).etudiants,ch2);
         fscanf (ptf,"%s",ch2);
         strcat(ch2,ch3);
      }

    fscanf(ptf,"%s %s %s %s %s",ch2,ch3,ch,ch4,ch5);
       strcpy (ch6," ");
       strcat(ch2,ch6);
       strcat(ch2,ch3);
       strcpy((*p).JURY.membre1,ch2);
       strcat(ch4,ch6);
       strcat(ch4,ch5);
       strcpy((*p).JURY.membre2,ch4);
       fscanf(ptf,"%s",ch);
        Aff_adr (q, p);
        q = p;
      }
     }
    }
     fclose(ptf);
     for (i=0;i<4;i++){

      TriBullesLLCin(salle[i]);
      }



}

void PARCOURS_DES_LISTES()    //cette procédure permet d'afficher le planning selon le mode selectionné
{

 int  reponse=0;
 textcolor(12);
        printf("\n choisissez une option:");
        printf("\n  \t \t > 1.Affichage des soutenances a patir d'une salle donnee");
        printf("\n  \t \t > 2.Affichage des soutenances dans une date");
        printf("\n  \t \t > 3.Affichage des soutenances supervisees par un membre du jury");
        printf("\n  \t \t > 4.Affichage des soutenances a patir d'une specialite donnee \n  \t > ");

    scanf(" \n %d",&reponse);
    switch (reponse)
    {
    case 1 : affichage_salle();
    break;
    case 2 : affichage_date();
    break;
    case 3 : affichage_jury();
    break;
    case 4 : affichage_specialite();
    break;
    default: printf("Vous avez entré un caractère non valide, veuillez réessayer");
    }

}
void modif_jury(){
int s=0,o=0;
char h[20]="",d[30]="",p[60]="",n[100]="";
ptr po=NULL,prec=NULL;

printf("\n-----------------------------------------------changement des jurys-----------------------------------------------\n\n");
do{
printf("\tIndiquez le numero de la salle dans laquelle vous voulez effectuer un changement CP[1..4]?\t");
printf("\n\n\t1.Salle CP1");
printf("\n\t2.Salle CP2");
printf("\n\t3.Salle CP3");
printf("\n\t4.Salle CP4");
while(s<1 || s>4){
printf("\n\n\tChoisissez une option: ");
scanf("%d",&s);
if(s<1 || s>4){
printf("\n\tOption inexistante veuillez entrer une option disponible:\n");
}
}
s--;
printf("\n\t Selectionnez la date pendant laquelle vous voulez effectuer un changement:\t");
printf("\n \n \t 1.10/04/2022");
printf("\n \t 2.11/04/2022");
printf("\n \t 3.12/04/2022");
printf("\n \t 4.13/04/2022");
printf("\n \t 5.14/04/2022");
while (o<1 || o>5){
printf("\n\n \t Choisissez une option:\t");
scanf("%d",&o);
if (o<1 || o>5)
printf("\n\tOption inexistante veuillez reessayer\n");
}
switch (o)
    {
    case 1: strcpy(d,"10/04/2022");
    break;
    case 2: strcpy(d,"11/04/2022");
    break;
    case 3: strcpy(d,"12/04/2022");
    break;
    case 4: strcpy(d,"13/04/2022");
    break;
    case 5: strcpy(d,"14/04/2022");
    break;
    }
o=0;
printf("\n\tSelectionnez l'heure pendant laquelle vous voulez effectuer un changement:");
printf("\n\n\t1.09:00");
printf("\n\t2.10:30");
printf("\n\t3.13:00");
printf("\n\t4.14:30");
while (o<1 || o>4){
printf("\n\n\tChoisissez une option:\t");
scanf("%d",&o);
if (o<1 || o>4)
     textcolor(6);
printf("\n\t Option inexistante veuillez reessayer\n");
}
switch (o)
    {
    case 1: strcpy(h,"09:00");
    break;
    case 2: strcpy(h,"10:30");
    break;
    case 3: strcpy(h,"13:00");
    break;
    case 4: strcpy(h,"14:30");
    break;

    }}
while (exist_soutenance(s,d,h)==0);
 textcolor(6);
do{
printf("\n\t Entrez le nom du jury que vous voulez remplacer avec:  ");
scanf("%s",n);
printf("\n\tEntrez le prenom du jury que vous voulez remplacer avec:  ");
scanf("%s",p);
if (jury_disponible(n,p,d,h)==0) printf("\n\tOoooups il parait que Mr/Mme %s %s est occupe maintenant veuillez entrer un autre choix\n",n,p);
}while(jury_disponible(n,p,d,h)==0);


printf("\n\tLes encadrants de cette soutenance sont:");
//chercher l'adresse ou se trouve le membre
int trouv=0;
po=salle[s];//po reçoit la tete de la liste de la salle séléctionnée

while (po!=NULL && trouv==0){
    if(strcmp(po->DATE.h,h)==0 && strcmp(po->DATE.j,d)==0){
        printf("\n\n\t1.Le premier membre: %s",po->JURY.membre1);
        printf("\n\t2.Le deuxieme membre: %s\n",po->JURY.membre2);
        trouv=1;
        prec=po;//on sauvegarde l'adresse pour ne pas le perdre dans la boucle
    }
        po=Suivant(po);
}

strcat(n," ");
strcat(strupr(n),strupr(p));
printf("\n\t Choisissez une option");
printf("\n\n\t1.Changer le premier membre ");
printf("\n\t2.Changer le deuxieme membre ");
o=0;
while (o<1 || o>2){
printf("\n\n\tEntrez votre choix: ");
scanf("%d",&o);
if (o<1 || o>2)
printf("\n\tOption inexistante veuillez reessayer\n");
}

 if (o==1){
        strcpy(prec->JURY.membre1,n);
        printf("\n\n\tvotre modification a bien ete enregistree\n\t");
         AffichLLC(salle[s]);
  }
  else {
        strcpy(prec->JURY.membre2,n);
        printf("\n\n\tvotre modification a bien ete enregistree\n\t");
         AffichLLC(salle[s]);
  }
        }
ptr SIQ,SIT,SIL;
void SpicialSIQ()
{
int m=0;
ptr s,p,r;
p=salle[0];
do
{
p=Suivant(p);
} while(p->ID[2]!='Q');

Allouer(&s);
r=s;
CpyMaillon(p,s);
SIQ=s;
 p=Suivant(p);
while (p!=NULL)
{
if (p->ID[2]=='Q')
{
          Allouer(&s);
          CpyMaillon(p,s);
         Aff_adr(r,s);
         r=s;
}
p=Suivant(p);
}
for(m=1;m<4;m++)
{
  p=salle[m];
   while (p!=NULL)
{
       if (p->ID[2]=='Q')
        {
          Allouer(&s);
          CpyMaillon(p,s);
          Aff_adr(r,s);
         r=s;
}
p=Suivant(p);
}
}
}



void SpicialSIT()
{
int m=0;
ptr s,p,r;
p=salle[0];
do
{
p=Suivant(p);
} while(p->ID[2]!='T');

Allouer(&s);
r=s;
CpyMaillon(p,s);
SIT=s;
 p=Suivant(p);
while (p!=NULL)
{
if (p->ID[2]=='T')
{
          Allouer(&s);
          CpyMaillon(p,s);
         Aff_adr(r,s);
         r=s;
}
p=Suivant(p);
}
for(m=1;m<4;m++)
{
  p=salle[m];
   while (p!=NULL)
{
       if (p->ID[2]=='T')
        {
          Allouer(&s);
          CpyMaillon(p,s);
          Aff_adr(r,s);
         r=s;
}
p=Suivant(p);
}
}
}

void SpicialSIL()
{
int m=0;
ptr s,p,r;
p=salle[0];
do
{
p=Suivant(p);
} while(p->ID[2]!='L');

Allouer(&s);
r=s;
CpyMaillon(p,s);
SIL=s;
 p=Suivant(p);
while (p!=NULL)
{
if (p->ID[2]=='L')
{
          Allouer(&s);
          CpyMaillon(p,s);
         Aff_adr(r,s);
         r=s;
}
p=Suivant(p);
}
for(m=1;m<4;m++)
{
  p=salle[m];
   while (p!=NULL)
{
        if (p->ID[2]=='L')
        {
           Allouer(&s);
           CpyMaillon(p,s);
           Aff_adr(r,s);
         r=s;
        }
p=Suivant(p);
}
}
}

void TRI_DES_LISTES()
{
    int am=0;
    textcolor(5);
  printf("\n choiser la specialite : ");
  printf("\n \t > 1.SIQ " );
  printf("\n \t > 2.SIT  " );
  printf("\n \t > 3.SIL \n  \t \t > " );

   scanf("  %d",&am);
   switch(am)
   {
   case (1) :
       printf("\n LA LISTES DES SOUTENANNCES DU  SPICIALITE SIQ : \n ");
       SpicialSIQ(SIQ);
       TriBullesLLC(SIQ);
       AffichLLC(SIQ);
       break;
   case (2) :
       printf("\n LA LISTES DES SOUTENANNCES DU  SPICIALITE SIT : \n ");
       SpicialSIT(SIT);
       TriBullesLLC(SIT);
       AffichLLC(SIT);
    break;
   case (3) :
        printf("\n LA LISTES DES SOUTENANNCES DU  SPICIALITE SIL : \n ");
        SpicialSIL(SIL);
        TriBullesLLC(SIL);
        AffichLLC(SIL);
    break;
   default :
      printf(" cette specialite n'existe pas ");
       }


}
void spic()
{
    SpicialSIQ();
    TriBullesLLC(SIQ);
    SpicialSIT();
    TriBullesLLC(SIT);
    SpicialSIL();
    TriBullesLLC(SIL);
}

int heure_occupee(ptr l,char date[200]){//cette fonction retourne le nombre des heures prises dans une journée
    int z=0,cpt=0;
    ptr po=NULL;

po=l;
while (po!=NULL && z==0){
    if (strcmp(po->DATE.j,date)==0){
        cpt=cpt+1;}
        else{
         z=1;
        }
        po=Suivant(po);
    }
    return cpt;
}
void modif_salle_date(){//cette procédure nous permet d'effectuer des modifications concernant les salles, les dates (systématiquement les heures) des soutenances
    char fname[100]="",lname[100]="",sauvn[150]="",d[50]="",h[20]="";
    int n=0,x=0,b=0,i=0;
    ptr p=NULL,q=NULL,t=NULL,tt=NULL;
    printf("\n---------------------------------------------Changement de salle/date----------------------------------------------\n\n");
    do{ //on répète la lecture du nom et du prénom jusqu'à ce qu'il soit valide et existant
    printf("\n\n\tEntrez le nom de l'etudiant: ");
    scanf("%s",&fname);
    printf("\n\tEntrez le prenom de l'etudiant: ");
    scanf("%s",&lname);
    strcpy(sauvn,strupr(fname));
    strcat(sauvn," ");
    strcat(sauvn,strupr(lname));
    strcat(sauvn," ");

   //accéder au maillon par valeur (nom/prénom)
   printf("\t \t dans quelle salle ce trouve cet etudiant :");
   scanf("%d",&i);
   i--;
        p=salle[i];//p reçoit la tete de la liste de la i+1 ème salle
        while(p!=NULL && b==0){
            if (strcmp(strupr(p->etudiants),sauvn)==0){
                b=1;
            }
            else{
                q=p;
                p=Suivant(p);}}


                if (p==NULL) printf("\n\tCet etudiant ne figure pas sur les listes veuillez entrer un nom valide:");
        }while(p==NULL);


     printf("\n\n\t1.Changement de la salle et de la date et de l'heure?\n\t2.Changement de la date et de l'heure\n\n\tEntrez votre choix: ");
     while (x<1 || x>2){
    scanf("\t%d",&x);
    if (x<1 || x>2) printf("\n\tOption indisponible veuillez reessayer: ");
     }
    if (x==1){ //le cas ou on veut changer la salle aussi ce qui va engendrer celui de la date

    printf("\n\tl'etudiant(e) %s est dans la salle CP%d\n",sauvn,i+1);
    printf("\n\tSelectionnez la salle destination CP[1..4]\n\n\tN'oubliez pas de ne pas selectionner la salle dans laquelle il se trouve deja ");
    printf("\n\n\tEntrez votre choix:  ");
    while(n<1 || n>4){
    scanf("\t%d",&n);//on lit le noméro de la salle
    if (n<1 || n>4) printf("\n\toption indisponible veuillez reessayer: ");
    }
    n--;//on le décrémente pour notre tableau[0..3]
    x=0;
    printf("\n\tSelectionnez la date pendant laquelle vous voulez reprogrammer la soutenance:");
    printf("\n\n\t1.10/04/2022");
    printf("\n\t2.11/04/2022");
    printf("\n\t3.12/04/2022");
    printf("\n\t4.13/04/2022");
    printf("\n\t5.14/04/2022");
    while (x<1 || x>5){
    printf("\n\n\tChoisissez une option:\t");
    scanf("%d",&x);
    if (x<1 || x>5)
    printf("\n\tOption inexistante veuillez reessayer\n");
}
switch (x)
    {
    case 1: strcpy(d,"10/04/2022");
    break;
    case 2: strcpy(d,"11/04/2022");
    break;
    case 3: strcpy(d,"12/04/2022");
    break;
    case 4: strcpy(d,"13/04/2022");
    break;
    case 5: strcpy(d,"14/04/2022");
    break;
    }

x=0;
t=salle[n];// t reçoit la tete de la liste de la salle n+1
while (t!=NULL && x==0){ //chercher l'existance de la date indiquée et t contiendra l'adresse du premier maillon dans la date indiquée
    if (strcmp(d,t->DATE.j)==0){
     x=1;
     }
else t=Suivant(t);
}
tt=t;
if (x==0){//toutes les horaires sont disponibles
 printf("\n\tSelectionnez l'heure pendant laquelle vous voulez effectuer un changement:");
printf("\n\n\t1.09:00");
printf("\n\t2.10:30");
printf("\n\t3.13:00");
printf("\n\t4.14:30");
while (x<1 || x>4){
printf("\n\n\tChoisissez une option:\t");
scanf("%d",&x);
if (x<1 || x>4)
printf("\n\tOption inexistante veuillez reessayer\n");
}
switch (x){
    case 1: strcpy(h,"09:00");
    break;
    case 2: strcpy(h,"10:30");
    break;
    case 3: strcpy(h,"13:00");
    break;
    case 4: strcpy(h,"14:30");
    break;}
strcpy(p->DATE.j,d);//effectuer les changements de date dans le maillon
strcpy(p->DATE.h,h);//effectuer les changements de l'heure dans le maillon

}
else{//chercher quelles sont les horaires libres ou s'il existe au moins une heure libre sinon indiquer que la salle est saturée pendant cette date là
x=heure_occupee(t,d);


    if (x==4){printf("\n\n\tSalle saturee pendant le %s, veuillez reessayer \n\n",d);}
 else{
        printf("\n\tles horaires occupees sont:");
        tt=t;
    while (t!=NULL && strcmp(d,t->DATE.j)==0){
     printf("\n\t%s ",t->DATE.h);
 t=Suivant(t);
    }

printf("\n\t Selectionnez l'heure pendant laquelle vous voulez effectuer un changement:");
printf("\n\n \t 1.09:00");
printf("\n\t \t  2.10:30");
printf("\n\t \t 3.13:00");
printf("\n\t \t 4.14:30");
t=tt;
x=0;
while (x<1 || x>4 ){
printf("\n\n\tChoisissez une option:\t");
scanf("%d",&x);
if (x<1 || x>4 )
printf("\n\tOption inexistante veuillez reessayer\n");
}
}
switch (x){
    case 1: strcpy(h,"09:00");
    break;
    case 2: strcpy(h,"10:30");
    break;
    case 3: strcpy(h,"13:00");
    break;
    case 4: strcpy(h,"14:30");
    break;}
    strcpy(p->DATE.j,d);//effectuer les changements de date dans le maillon
    strcpy(p->DATE.h,h);//effectuer les changements de l'heure dans le maillon
 }

 //la supression du maillon
    if(q==NULL){
        salle[i]=Suivant(p);
    }
    else{
        Aff_adr(q,Suivant(p));
    }
     AffichLLC(salle[i]);
//l'insersion du maillon
//on insère depuis le début de la liste qui contient la salle
/*Aff_adr(p,tt);
if (strcmp("10/04/2022",d)==0){//insertion depuis la tete de la liste
 salle[i]=p;
}
else Aff_adr(q,p);
 AffichLLC(salle[i]);*/

    }




else{//quand on veut seulement changer la date et l'heure
x=0;
    printf("\n\t Selectionnez la date pendant laquelle vous voulez reprogrammer la soutenance:");
    printf("\n\n\t1.10/04/2022");
    printf("\n\t2.11/04/2022");
    printf("\n\t3.12/04/2022");
    printf("\n\t4.13/04/2022");
    printf("\n\t5.14/04/2022");
    while (x<1 || x>5){
    printf("\n\n\tChoisissez une option:\t");
    scanf("%d",&x);
    if (x<1 || x>5)
    printf("\n\tOption inexistante veuillez reessayer\n");
}
switch (x)
    {
    case 1: strcpy(d,"10/04/2022");
    break;
    case 2: strcpy(d,"11/04/2022");
    break;
    case 3: strcpy(d,"12/04/2022");
    break;
    case 4: strcpy(d,"13/04/2022");
    break;
    case 5: strcpy(d,"14/04/2022");
    break;}
x=0;
i--;
t=salle[i];// t reçoit la tete de la liste de la salle n+1
while (t!=NULL && x==0){ //chercher l'existance de la date indiquée et t contiendra l'adresse du premier maillon dans la date indiquée
    if (strcmp(d,t->DATE.j)==0){
     x=1;
     }
else t=Suivant(t);
}

if (x==0){//toutes les horaires sont disponibles
 printf("\n\tSelectionnez l'heure pendant laquelle vous voulez effectuer un changement:");
printf("\n\n\t1.09:00");
printf("\n\t2.10:30");
printf("\n\t3.13:00");
printf("\n\t4.14:30");
while (x<1 || x>4){
printf("\n\n\tChoisissez une option:\t");
scanf("%d",&x);
if (x<1 || x>4)
printf("\n\tOption inexistante veuillez reessayer\n");
}
switch (x){
    case 1: strcpy(h,"09:00");
    break;
    case 2: strcpy(h,"10:30");
    break;
    case 3: strcpy(h,"13:00");
    break;
    case 4: strcpy(h,"14:30");
    break;}
strcpy(p->DATE.j,d);//effectuer les changements de date dans le maillon
strcpy(p->DATE.h,h);//effectuer les changements de l'heure dans le maillon

}
else{//chercher quelles sont les horaires libres ou s'il existe au moins une heure libre sinon indiquer que la salle est saturée pendant cette date là
x=heure_occupee(t,d);


    if (x==4){printf("\n\n\tSalle saturee pendant le %s, veuillez reessayer\n\n",d);}
 else{
        printf("\n\tles horaires occupees sont:");
    while (t!=NULL && strcmp(d,t->DATE.j)==0){
     printf("\n\t%s ",t->DATE.h);
 t=Suivant(t);
    }

printf("\n\tSelectionnez l'heure pendant laquelle vous voulez effectuer un changement:");
printf("\n\n\t1.09:00");
printf("\n\t2.10:30");
printf("\n\t3.13:00");
printf("\n\t4.14:30");
t=tt;
x=0;
while (x<1 || x>4 ){
printf("\n\n\tChoisissez une option:\t");
scanf("%d",&x);
if (x<1 || x>4 )
printf("\n\tOption inexistante veuillez reessayer\n");
}
}
switch (x){
    case 1: strcpy(h,"09:00");
    break;
    case 2: strcpy(h,"10:30");
    break;
    case 3: strcpy(h,"13:00");
    break;
    case 4: strcpy(h,"14:30");
    break;}
    strcpy(p->DATE.j,d);//effectuer les changements de date dans le maillon
    strcpy(p->DATE.h,h);//effectuer les changements de l'heure dans le maillon

    //la supression du maillon
    if(q==NULL){
        salle[i]=Suivant(p);
    }
    else{
        Aff_adr(q,Suivant(p));
        AffichLLC(salle[i]);
    }
//l'insersion du maillon
//on insère depuis le début de la liste qui contient la salle
/*Aff_adr(p,t);
if (strcmp("10/04/2022",d)==0){//insertion depuis la tete de la liste
 salle[i]=p;
}
else Aff_adr(q,p);
 AffichLLC(salle[i]);*/
}
}
}

void INSERT_SUPPR_MISJOUR()
{
    int vu;
   printf("choisissez une oppsion");
   textcolor(6);
   printf(" \n \t \t  > 1.MODIFIER UN MEMBRE DU JURY");
   textcolor(8);
   printf(" \n \t \t  > 2.MODIFER UNE SALLE OU UNE DATE \n \t \t \t >");
   scanf("%d",&vu);
   switch(vu)
   {
   case (1):
       modif_jury();
    break;
   case (2):
       modif_salle_date();
    break;
   default:
    printf("entrez un autre choix");
   }
}
void  SauvgardResult(ptr SIQ,ptr SIT,ptr SIL)
{


FILE *fic=fopen("resultats.txt","w");
if (fic==NULL)
{
    fputs("hello",fic);
}
p=SIQ;
fprintf(fic,"Specialite: SIQ\n\n");
while (p!=NULL)
{
 fprintf(fic,"Date: %s \nHeure: %s\nID: %s \nTitre: %s\nEtudiant: %s \nJury: %s ; %s\n",p->DATE.j,p->DATE.h,p->ID,p->titre,p->etudiants,p->JURY.membre1,p->JURY.membre2);
p=Suivant(p);

}
fprintf(fic,"\n");
p=SIT;
fprintf(fic,"Specialite: SIT\n\n");
while (p!=NULL)
{
 fprintf(fic,"Date: %s \nHeure: %s\nID: %s \nTitre: %s\nEtudiant: %s \nJury: %s ; %s\n",p->DATE.j,p->DATE.h,p->ID,p->titre,p->etudiants,p->JURY.membre1,p->JURY.membre2);
p=Suivant(p);

}
fprintf(fic,"\n");
p=SIL;
fprintf(fic,"Specialite: SIL\n\n");
while (p!=NULL)
{
 fprintf(fic,"Date: %s \nHeure: %s\nID: %s \nTitre: %s\nEtudiant: %s \nJury: %s ; %s\n",p->DATE.j,p->DATE.h,p->ID,p->titre,p->etudiants,p->JURY.membre1,p->JURY.membre2);
p=Suivant(p);

}

fclose(fic);
}




//****************************************LE MENU PRINCIPAL****************************************************//

void programme()
{
    textcolor(6);
printf("***************************BIENVENU DANS NOTRE APPLICATION 'GESTION DES SOUTENANCES'*********************************\n");
textcolor(14); // procedure sert à changer les couleurs

        int answer;
    printf("\n \t entrer votre choix");
    printf(" \n \t \t > 1.INITIALISATION DES STRUCTURES DE DONNEES");
    printf(" \n \t \t > 2.PARCOURS DES LISTES");
    printf(" \n \t \t > 3.INSERTION/SUPPRESSION/MISE À JOUR D’ÉLÉMENTS  ");
    printf(" \n \t \t > 4.TRI DES LISTES ");
    printf(" \n \t \t > 5.SAUVEGARDE DES RÉSULTATS \n \t \t \t > ");
    scanf("%d",&answer);
    switch(answer)
    {

     case (1):

        INITIALISATION_DES_DONNEES();
         int i=0;
         for (i=0;i<4;i++)
            {
          printf(" Salle: CP%d\n",i+1);
          AffichLLC(salle[i]);
            }
        break;
     case (2):
        INITIALISATION_DES_DONNEES();
        PARCOURS_DES_LISTES();
        break;
     case (3):
         INITIALISATION_DES_DONNEES();
         INSERT_SUPPR_MISJOUR();
         break;
     case (4):
          INITIALISATION_DES_DONNEES();
          TRI_DES_LISTES();
        break;
     case (5):
          INITIALISATION_DES_DONNEES();
        spic();
        SauvgardResult(SIQ,SIT,SIL);
        printf("\n \t \t voici votre fichier");
         break;
     default :
        printf("\n entrer un autre choix");
    }
}

  programme();



    return 0;
}

