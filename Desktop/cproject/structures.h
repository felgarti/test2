#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
typedef struct
{
    int numero ;
    char rue[20] ;
    char quartier[50];
    int code_postal;
}adresse;
typedef struct maladie {
    char mal[50];
    struct maladie *suiv;
}maladie;

typedef struct {
int j;
 int m;
 int a ;
 }date;

typedef struct personne {
char nom[12];
char prenom[12];
int age ;
char genre ;
char cont_loc ;
adresse adresse ;
struct personne *suiv ;
}personne;

typedef struct {
    char nom[12];
    char prenom[12];
    adresse adresse ;
    int age ;
    char genre ;
    char cont_loc ;
    char etat[20];
maladie *maladie ;
personne *personne;
} patient ;


typedef struct listep
{
    patient *cell ;
    struct listep *suiv ;
    struct listep *prec;
}listep;


typedef struct
{
    patient *patient;
    date debut ;
    date fin ;
    adresse lieu ;
    char chezlui ;
}quarantaine;
typedef struct listeq
{
 quarantaine  *cell ;
    struct listeq *suiv ;
    struct listeq *prec;
} listeq;

typedef struct {
char *nom;
adresse adresse ;
int lit_dispo ;
int medecin ;
int paramed ;
 listep *patients ;
int nb_patients;
}hopital;

typedef struct listeh
{
    hopital *cell ;
    struct listeh *suiv ;
    struct listeh *prec;
} listeh;

typedef struct lieu
{
    adresse adresse;
    char nom[50];
    int dispo ;
    listeq *quarantaine;
    int nb_patients;
    struct lieu *suiv ;

} lieu ;

