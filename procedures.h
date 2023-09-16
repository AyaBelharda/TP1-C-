#ifndef PROCEDURES_H_INCLUDED
#define PROCEDURES_H_INCLUDED
///Declaration de la structure de données utilisée
// définir un nouveau type d'enregistrement

struct jury{
 char membre1[20];
char  membre2[20];
};
struct date {
  char j[20];
  char h[20];
};

typedef struct soutenances soutenances ;
struct soutenances
{
    char  ID[10]; //ce champs sert à affichier ID d'un soutnance
    char  etudiants[256]; //ce champs sert à affichier le nom et le prenom  d'un soutnance
    char titre[256];//ce champs sert à affichier le titre du memoire  du soutnance
    struct date DATE ;//ce champs sert à affichier la date et l'heur de la presentation
    struct jury JURY ;//ce champs sert à affichier les jurys
    soutenances* adr ; //un champs qui sauvegarde l'adresse du maillon suivant
};

typedef soutenances* ptr;
ptr salle[4];


//les prototypes des procedures
void Allouer(ptr* p);
void Liberer (ptr p);
char* ID(ptr p);
ptr Suivant (ptr p);
void Aff_adr(ptr p, ptr q);
void AffichLLC (ptr L);
void substring(char str[10],char substrg[10],int a,int b );
void affichage_date();
void affichage_salle();
void affichage_specialite();
void affichage_jury();
int jury_disponible(char nom[100],char prenom[100],char date[20],char heure[20]);
int exist_soutenance(int sa,char date[20],char heure[20]);
#endif // PROCEDURES_H_INCLUDED
