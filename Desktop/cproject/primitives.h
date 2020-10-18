
#include "structures.h"


// Prototypes de fonctions primitives//
quarantaine* affecter_patient_lieu (quarantaine *p, lieu* tete); // //
adresse saisir_adresse (void);// //
hopital*  creer_hopital (void); // //
void affecter_patient(patient *p,listeh *l_hopitaux ); // //
void ajouter_hopital (listeh  * l_hopitaux); // //
void ajouter_patient (listep * l_patients); // //
maladie * ajouter_maladie (void); //  //
personne * ajouter_personne(void);// //
patient* creer_patient (void);// //
void supprimer_patient(patient *pat);// //
void supprimer_patient_liste (listep *pa); // //
void supprimer_hopital(hopital *h); // //
void supprimer_hopital_liste (listeh *l_hopitaux);// //
date saisir_date( void); // //
void afficher_date(date *d); // //
quarantaine* creer_patient_quarantaine(lieu* tete); // //
void ajouter_patient_quarantaine (listeq *l_quarantaine, lieu* tete); // //
void supprimer_patient_quarantaine_parnom (listeq *l_quarantaine);////
void supprimer_patient_quarantaine_21jr(listeq *l_quarantaine);////
void modifieretat_patient (listep *l_pa); // //
lieu* inserer_lieu (lieu *tete);// //
void affecter_personne_quarantaine ( patient *pat,listeq * l_quarantaine, lieu* tete); // //
listep* rechercher_patients(listep *l_patient); // //
void afficher_personne(personne *p);//
void afficher_patient(patient *p); //
void afficher_adresse (adresse *d); // //
void afficher_lieu(lieu* tete); // //
void afficher_quarantaine(quarantaine *q); // //
void afficher_hopital(hopital *h); // //
hopital* rechercher_hopital(listeh *h);// //










