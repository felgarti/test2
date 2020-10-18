#include "primitives.h"
 // -----------------MAIN---------------------//

   void main()
{
    /*declarations*/
lieu *liste_lieu;
int menu;
     listeh *liste_hopitaux;
    listep *liste_patients;
    listeq *liste_quarantaine;
    //initialisations des listes //


    liste_patients=(listep*)malloc(sizeof(listep));
    liste_patients->cell=NULL;
    liste_patients->suiv=NULL;
    liste_patients->prec=NULL;

    liste_hopitaux=(listeh*)malloc(sizeof(listeh));
    liste_hopitaux->cell=NULL;
    liste_hopitaux->suiv=NULL;
    liste_hopitaux->prec=NULL;

    liste_quarantaine=(listeq*)malloc(sizeof(listeq));
    liste_quarantaine->cell=NULL;
    liste_quarantaine->suiv=NULL;
    liste_quarantaine->prec=NULL;

 //le menu utilisateur //


           printf("  1) inserer lieu \n "
                  " 2) ajouter hopital\n "
                  " 3) ajouter patient \n " //et l'affecter//
                  " 4) ajouter personne en quarantaine\n "
                  " 5) afficher la liste d'hopitaux\n "
                  " 6) rechercher hopital \n "
                  " 7) afficher la liste des personnes confinées\n "
                  " 8) rechercher un ou plusieurs patients\n "
                  " 9) supprimer un patient par nom\n "
                  " 10) supprimer les personnes dont la date de fin de confinement est aujourd'hui\n "
                  " 11) modifier etat d'un patient \n "
                  " 12) supprimer hopital\n "
                  " 13) afficher liste lieu \n "
                  " 14) supprimer une personne en quarantaine par nom \n "
                  " 15) quitter \n ");
                  choix:
                  printf("\n entrez votre choix : -->          ");

                       scanf("%d",&menu);

if(menu==1) { liste_lieu=inserer_lieu(liste_lieu);printf("\n") ;afficher_lieu(liste_lieu);                }
if(menu==2) { ajouter_hopital(liste_hopitaux);                               }
if(menu==3) { if(liste_hopitaux->cell!=NULL)        affecter_patient(creer_patient(),liste_hopitaux);
else printf("\n la liste d'hopitaux est vide ,veuillez ajouter un hopital . ")       ;     }

if(menu==4) {  ajouter_patient_quarantaine(liste_quarantaine,liste_lieu); }
if(menu==5) {
     if(liste_hopitaux==NULL || liste_hopitaux->cell==NULL  ) printf(" \nla liste d hopitaux est vide .");
     else {  do {
             afficher_hopital(liste_hopitaux->cell);
           if(liste_hopitaux->suiv!=NULL)  liste_hopitaux=liste_hopitaux->suiv;}while(liste_hopitaux->suiv!=NULL);
             while(liste_hopitaux->prec!=NULL) liste_hopitaux=liste_hopitaux->prec; }
}
if(menu==6) {
   afficher_hopital(rechercher_hopital(liste_hopitaux));
}
if(menu==7) {
     do {
             afficher_quarantaine(liste_quarantaine->cell);
             liste_quarantaine=liste_quarantaine->suiv;}while(liste_quarantaine->suiv!=NULL);
             while(liste_quarantaine->prec!=NULL) liste_quarantaine=liste_quarantaine->prec;
}
if(menu==8) { liste_patients= rechercher_patients (  (rechercher_hopital(liste_hopitaux))->patients ); }
if(menu==9) {  supprimer_patient_liste((rechercher_hopital(liste_hopitaux))->patients);}
if(menu==10) { if(liste_quarantaine->cell!=NULL) {supprimer_patient_quarantaine_21jr(liste_quarantaine);}
else printf("La liste des personnes en quarantaine est vide");}
if(menu==11) { modifieretat_patient((rechercher_hopital(liste_hopitaux))->patients ) ; }
if(menu==12) { if(liste_hopitaux->cell!=NULL)supprimer_hopital_liste(liste_hopitaux);
else printf("La liste des hopitaux est vide "); }
if(menu==13) { if(liste_lieu!=NULL) afficher_lieu(liste_lieu);
else printf("\n La liste des lieux est vide "); }
if(menu==14) {     if(liste_quarantaine->cell!=NULL) {supprimer_patient_quarantaine_parnom (liste_quarantaine);}
else printf("La liste des personnes en quarantaine est vide"); }
if (menu!=15) goto choix ;

//fin du menu//
}


//déclarations de fonctions //
//------------------------------------------------------------------------------------------------------------------//
personne* ajouter_personne()
{

    personne *x;

     x=(personne*)malloc(sizeof(personne));

printf("\n entrez nom de la personne :"); scanf("%s",x->nom);
    printf("\n entrez prenom de la personne :"); scanf("%s",x->prenom);
    printf(" \nentrez age : "); scanf("%d",&x->age);
    printf(" \nentrez genre : "); scanf("%s",&x->genre);
    printf("\n est ce que la contamination est locale ? ( o ou n) :"); scanf("%s",&x->cont_loc);
    printf("\n entrez adresse de la personne :");  x->adresse=saisir_adresse();
    x->suiv=NULL;
return x;
}
//------------------------------------------------------------------------------------------------------------------//
adresse saisir_adresse (void)
{
    adresse a;
    char ad[60];
    fflush(stdin);
    printf("\n entrez l'adresse (numero rue quartier code postal): "); gets(ad);
    fflush(stdin);
    sscanf(ad,"%d %s %s %d",&a.numero,a.rue,a.quartier,&a.code_postal);

    return a;
}

//------------------------------------------------------------------------------------------------------------------//
patient* creer_patient (void)

{
    personne *aip ;
maladie *aim ;
       int nbper=0,nbmal=0 ,i;
    patient *p;
    p=(patient*)malloc(sizeof(patient));
    printf(" \nentrez nom : "); scanf("%s",p->nom);
    printf(" \nentrez prenom : "); scanf("%s",p->prenom);
    printf(" \nentrez age : "); scanf("%d",&(p->age));
    printf(" \nentrez genre : "); scanf("%s",&(p->genre));
   p->adresse=saisir_adresse();

    printf("\n est ce que la contamination est locale ? ( o ou n ) :"); scanf("%s",&(p->cont_loc));
    printf(" \nentrez etat (critique ou stable) : "); scanf("%s",p->etat);
    printf("\n Entrez nombre de personnes en contact avec le patient : ");scanf("%d",&nbper);
    aip=p->personne;
    for(i=0;i<nbper;i++)
    {
        printf("\npersonne N° %d :\n",i+1);
       aip=ajouter_personne();
        aip=(aip)->suiv ;
    }
    printf("\n entrez le nombre de maladies chroniques : ");scanf("%d",&nbmal);
    aim=p->maladie;
    for(i=0;i<nbmal;i++)
    {
        printf("\nmaladie N° %d :\n",i+1);
      aim=  ajouter_maladie();
  aim=aim->suiv;
    }
    return p ;
}

//------------------------------------------------------------------------------------------------------------------//
maladie * ajouter_maladie (void)
{
    maladie *x;

                  x=(maladie*) malloc(sizeof(maladie));
                  printf("\n entre nom de la maladie "); scanf("%s",x->mal);
                  x->suiv=NULL;
         return x;
}
//------------------------------------------------------------------------------------------------------------------//
void ajouter_patient (listep * l_patients) // utilisée lors de la création d'un hopital//
{
    listep *l=l_patients;
        if(l->cell==NULL){ l->cell=creer_patient(); }
      else {
            while(l->suiv!=NULL) { l=l->suiv; }
        l->suiv=(listep*)malloc(sizeof(listep));
        l->suiv->cell=creer_patient();
         l->suiv->prec=l;
         l->suiv->suiv=NULL;
      }
}
//------------------------------------------------------------------------------------------------------------------//
void affecter_patient(patient *p,listeh *l_hopitaux ) //affecter un patient à un hopital déjà existant //
{
    listeh *x=l_hopitaux;
    listep *lp;

    while((((p->adresse).code_postal)!= (((x->cell)->adresse).code_postal) || ((x->cell)->lit_dispo)<0 )&& x->suiv!=NULL)
        x=x->suiv;
        if(  ((p->adresse).code_postal)== (((x->cell)->adresse).code_postal) && ((x->cell)->lit_dispo)>0)

    {
        printf("le patient %s %s a ete affecte a l'hopital %s ",p->nom,p->prenom,(x->cell)->nom);
        lp=((x->cell)->patients);
        ((x->cell)->lit_dispo)-- ;
        ((x->cell)->nb_patients)++;
      if(lp!=NULL){ while (lp->suiv!=NULL) {lp=lp->suiv;}
        lp->suiv=(listep*)malloc(sizeof(listep));
        (lp->suiv)->cell=p;}
        else  {
            lp=(listep*)malloc(sizeof(listep));
        lp->cell=p;
        }
    }
}

//------------------------------------------------------------------------------------------------------------------//
hopital*  creer_hopital (void)
{  hopital *h;
 int i;
 h=(hopital*)malloc(sizeof(hopital));
 h->nom=(char*)malloc(20*sizeof(char));
   printf("\n entrez nom de l'hopital : ");scanf("%s",(h->nom));
   printf("\n entrez adresse : ");  h->adresse=saisir_adresse();
   printf("\n entrez nombre de lit disponibles : "); scanf("%d",&h->lit_dispo);
   printf("\n entrez nombre de medecins : ");scanf("%d",&h->medecin);
   printf("\n entrez nombre de paramedicaux : ");scanf("%d",&h->paramed);
   printf("\n entrez nombre de patients : "); scanf("%d",&h->nb_patients);
   h->patients=(listep*)malloc(sizeof(listep));
   h->patients->cell=NULL;
   h->patients->suiv=NULL;
   h->patients->prec=NULL;
   for(i=0;i<h->nb_patients;i++)
   {
       ajouter_patient(h->patients);
   }
   return h;
}
//------------------------------------------------------------------------------------------------------------------//
void ajouter_hopital (listeh * l_hopitaux)
{
    listeh *l=l_hopitaux;
    if(l->cell==NULL)
    {
        (l->cell)=creer_hopital();

    }
    else {
        while(l->suiv!=NULL) { l=l->suiv; }
        l->suiv=(listeh*)malloc(sizeof(listeh));
        (l->suiv->cell)=creer_hopital();
         l->suiv->prec=l;
         l->suiv->suiv=NULL;
    }
}


//------------------------------------------------------------------------------------------------------------------//
void supprimer_patient(patient *pat)
{
    maladie *m=pat->maladie->suiv;
    personne *p=pat->personne;
    while(m!=NULL)
    {
        free(pat->maladie);
        pat->maladie=m;
        m=m->suiv;

    }
    while(p!=NULL)
    {
        free(pat->personne);
        pat->personne=p;
        p=p->suiv;

    }
    free(pat);
printf(" \n le patient a ete supprime avec succes . ");
}
//------------------------------------------------------------------------------------------------------------------//
void supprimer_patient_liste (listep *pa)
{
listep *l=pa;
    char n[20],p[20];
    printf("\n entrez nom du patient :"); scanf("%s",n);
     printf("\n entrez prenom du patient :"); scanf("%s",p);
    while( ((strcmp(n,l->cell->nom))!=0 || (strcmp(p,l->cell->prenom))!=0) || l->suiv!=NULL  ) { l=l->suiv; }
    if((strcmp(n,l->cell->nom))==0 && (strcmp(p,l->cell->prenom))==0) {
      if(l->prec!=NULL && l->suiv!=NULL) { l->prec->suiv=l->suiv;
        l->suiv->prec=l->prec; }
        if(l->prec==NULL) { pa=l->suiv; pa->prec=NULL; }
        if(l->suiv==NULL) { l->prec->suiv=NULL;}
        supprimer_patient(l->cell);
          free(l);
    }
}
//------------------------------------------------------------------------------------------------------------------//
void supprimer_hopital(hopital *h)
{
    int i;
    listep *t=(h->patients->suiv) , *s=h->patients;

    for(i=0;i<h->nb_patients;i++)
    {
        supprimer_patient(s->cell);
        s=t;
        t=t->suiv;
    }

}
//------------------------------------------------------------------------------------------------------------------//
void supprimer_hopital_liste (listeh *l_hopitaux)
{

listeh *hospi=l_hopitaux;
    char n[20];
    printf("\n entrez nom hopital: "); scanf("%s",n);
    while((strcmp(n, ((hospi->cell)->nom) ))!=0 || hospi->suiv!=NULL  ) { hospi=hospi->suiv; }
    if((strcmp(n,(hospi->cell)->nom))==0 ) {
      if(hospi->prec!=NULL && hospi->suiv!=NULL) { hospi->prec->suiv=hospi->suiv;
        hospi->suiv->prec=hospi->prec; }
        if(hospi->prec==NULL && hospi->suiv!=NULL) { l_hopitaux=hospi->suiv; l_hopitaux->prec=NULL; }
        if(hospi->suiv==NULL && hospi->prec!=NULL) { hospi->prec->suiv=NULL;}

        supprimer_hopital(hospi->cell);
           if(hospi->suiv==NULL && hospi->prec==NULL) {l_hopitaux->cell=NULL;}
           else free(hospi);
    }
}

//------------------------------------------------------------------------------------------------------------------//

date  saisir_date(void)
{   date d;
char da[20];
    printf("\n jj/mm/aaaa : "); scanf("%s",da);
     sscanf(da," %d/%d/%d",&(d.j),&(d.m),&(d.a));
     return d;
}
//------------------------------------------------------------------------------------------------------------------//
quarantaine* creer_patient_quarantaine( lieu* tete)
{

    quarantaine *q;
    q=(quarantaine*)malloc(sizeof(quarantaine));
    q->patient=creer_patient();

    printf("\n entrez date debut confinement : ");(q->debut)= saisir_date();
    printf("\n entrez date fin confinement : ");(q->fin)= saisir_date();
    printf("\n est ce que le patient est confiné chez lui ? (o ou n) : "); scanf("%s",&q->chezlui);
    // si le patient est chez lui on a déjà son adresse //
    if(q->chezlui=='n' && tete!=NULL) {

       affecter_patient_lieu (q,tete);
    printf("\n on vous affecte à l'adresse : numero %d rue %s quartier %s code postal %d ",(q->lieu).numero,(q->lieu).rue,(q->lieu).quartier,(q->lieu).code_postal);
    }
   else  printf(" \n lieu indisponible ,verifiez si la liste est pleine ainsi que la disponibilité des hotels ");

    return q ;
}

//------------------------------------------------------------------------------------------------------------------//

void ajouter_patient_quarantaine (listeq *l_quarantaine, lieu* tete)
{
    listeq *quar=l_quarantaine;

        if(quar->cell==NULL){ quar->cell=creer_patient_quarantaine(tete); }
      else {
            while(quar->suiv!=NULL) { quar=quar->suiv; }
        quar->suiv=(listeq*)malloc(sizeof(listeq));
        quar->suiv->cell=creer_patient_quarantaine(tete);
         quar->suiv->prec=quar;
         quar->suiv->suiv=NULL; quar=quar->suiv;
      }
      if(quar->cell->patient->personne!=NULL) {affecter_personne_quarantaine ( quar->cell->patient,l_quarantaine,tete);}
}
//------------------------------------------------------------------------------------------------------------------//
void afficher_date(date *d)
{
    printf("    %d / %d / %d ",d->j,d->m,d->a);
}
//------------------------------------------------------------------------------------------------------------------//
void afficher_adresse (adresse *d)
{
    printf(" N° %d rue %s quartier %s code postale %d",d->numero,d->rue,d->quartier,d->code_postal);
}
//------------------------------------------------------------------------------------------------------------------//
void supprimer_patient_quarantaine_parnom (listeq *l_quarantaine)
{
    listeq *l=l_quarantaine;
    char n[20],p[20];
    printf("\n entrez nom du patient :"); scanf("%s",n);
     printf("\n entrez prenom du patient :"); scanf("%s",p);
    while((strcmp(n,(((l->cell)->patient)->nom)))!=0 && l->suiv!=NULL && (strcmp(p,l->cell->patient->prenom))!=0 ) { l=l->suiv; }
    if((strcmp(n,((l->cell)->patient)->nom))==0 && (strcmp(p,((l->cell)->patient)->prenom))==0) {
      if(l->prec!=NULL && l->suiv!=NULL) { l->prec->suiv=l->suiv;
        l->suiv->prec=l->prec; }
        if(l->prec==NULL) { l_quarantaine=l->suiv; l_quarantaine->prec=NULL; }
        if(l->suiv==NULL) { l->prec->suiv=NULL;}
        supprimer_patient((l->cell)->patient);
        free(l->cell);
          free(l);
    }

}
//------------------------------------------------------------------------------------------------------------------//
void supprimer_patient_quarantaine_21jr(listeq *l_quarantaine)
{    listeq *l=l_quarantaine,*aide;
    date auj,df;
    printf("\n entrez date d'aujourd'hui : ");
  auj=  saisir_date();



    while (l!=NULL){


   df=((l->cell)->fin);
        if(df.j==auj.j && df.m==auj.m && df.a==auj.a ) {
                aide=l ;
      if(aide->prec!=NULL && aide->suiv!=NULL) { aide->prec->suiv=aide->suiv;
       aide->suiv->prec=aide->prec; }
        if(aide->prec==NULL) { l_quarantaine=aide->suiv; l_quarantaine->prec=NULL; }
        if(aide->suiv==NULL) { aide->prec->suiv=NULL;}
        supprimer_patient((aide->cell)->patient);
        free(aide->cell);
          free(aide);
    }
    l=l->suiv;
    }
}
//------------------------------------------------------------------------------------------------------------------//
void modifieretat_patient (listep *l_pa) // avec option de supression si le patient est gueri //
{
    listep *l=l_pa;
    char n[20],p[20];
    printf("\n entrez nom du patient :"); scanf("%s",n);
     printf("\n entrez prenom du patient :"); scanf("%s",p);
    while((strcmp(n,l->cell->nom))!=0 && l->suiv!=NULL && (strcmp(p,l->cell->prenom))!=0 ) { l=l->suiv; }
    if((strcmp(n,l->cell->nom))==0 && (strcmp(p,l->cell->prenom))==0)
    {
        printf("\n etat du patient : "); scanf("%s",((l->cell)->etat));
        if(strcmp("gueri",(l->cell)->etat)==0)
        {

      if(l->prec!=NULL && l->suiv!=NULL) { l->prec->suiv=l->suiv;
        l->suiv->prec=l->prec; }
        if(l->prec==NULL) { l_pa=l->suiv; l_pa->prec=NULL; }
        if(l->suiv==NULL) { l->prec->suiv=NULL;}
        supprimer_patient(l->cell);
          free(l);
          printf("\n le patient gueri a ete supprime ");

        }
    }
}
//------------------------------------------------------------------------------------------------------------------//
lieu* inserer_lieu (lieu* tete)
{   int i;
    lieu *l,*aide=tete;
     l=(lieu*)malloc(sizeof(lieu));
     l->suiv=NULL;
     printf("\n entrez nom du lieu : "); fflush(stdin); gets(l->nom); fflush(stdin);
     printf(" \n entrez nombre de places disponibles : "); scanf("%d",&l->dispo);
    l->adresse=saisir_adresse();
    l->quarantaine=(listeq*)malloc(sizeof(listeq));
    l->quarantaine->prec=NULL;
    l->quarantaine->suiv=NULL;
    (l->quarantaine)->cell=NULL;
    printf("\nentrez le nombre de patients pour initialiser votre liste  : "); scanf("%d",&l->nb_patients);
    l->quarantaine=(listeq*)malloc(sizeof(listeq));
    l->quarantaine->cell=NULL;
    l->quarantaine->suiv=NULL;
    l->quarantaine->prec=NULL;
    for(i=0;i<l->nb_patients;i++)
    {
    ajouter_patient_quarantaine(l->quarantaine,tete);
    }


    if(tete==NULL) { tete=(lieu*)malloc(sizeof(lieu));
        *tete=*l;  }

    else {
            while(aide->suiv!=NULL)     aide=aide->suiv;
         aide->suiv=(lieu*)malloc(sizeof(lieu));
   * (aide->suiv)=*l;          }
return tete;
}
//------------------------------------------------------------------------------------------------------------------//
quarantaine* affecter_patient_lieu (quarantaine *p, lieu* tete)
{
    listeq *lp;
    lieu *l=tete;
    if(l!=NULL){
     while(   l->suiv!=NULL && ((((p->patient)->adresse).code_postal)!= ((l->adresse).code_postal) || (l->dispo)<0 ))
       {

        l=l->suiv;  }
        if( l!=NULL &&(((p->patient)->adresse).code_postal)== ((l->adresse).code_postal) && (l->dispo)>0)

    {
        strcpy(p->lieu.rue,l->adresse.rue);
        strcpy(p->lieu.quartier,l->adresse.quartier);
          p->lieu.numero=l->adresse.numero;
          p->lieu.code_postal=l->adresse.code_postal;
        printf("\n nom du lieu le plus proche  : %s",l->nom);
        lp=(l->quarantaine);
        (l->dispo)-- ;
        (l->nb_patients)++;
     if(lp->cell!=NULL)  { while (lp->suiv!=NULL) {lp=lp->suiv;}
        lp->suiv=(listeq*)malloc(sizeof(listeq));
        (lp->suiv)->cell=p;}
        else  {
lp->cell=p;
        } return p;
    }}
    else  printf("\n liste des lieux vide ,veuillez y inserer un lieu d'abord .") ;
return NULL;

}

//------------------------------------------------------------------------------------------------------------------//
void affecter_personne_quarantaine ( patient *pat,listeq * l_quarantaine, lieu* tete)
{
    listeq *quar=l_quarantaine;
    int nbmal,nbper,i=0;
    personne *p=pat->personne ;
    quarantaine *q;
    if(p!=NULL) {
            while (p->suiv!=NULL){
                    printf("\n personne N° %d \n",i+1);
                     i=i+1;
    q=(quarantaine*)malloc(sizeof(quarantaine));
    (q->patient)=(patient*)malloc(sizeof(patient));
    strcpy(((q->patient)->nom),p->nom);
    strcpy(((q->patient)->prenom),p->prenom);
    (q->patient)->adresse=p->adresse ;
    (q->patient)->genre=p->genre;
    (q->patient)->age=p->age;
    (q->patient)->cont_loc=p->cont_loc;
    printf(" \nentrez etat (critique ou stable) : "); scanf("%s",(q->patient)->etat);
    printf("\n Entrez nombre de personnes en contact avec le patient : ");scanf("%d",&nbper);
    ((q->patient)->personne)=NULL;
    for(i=0;i<nbper;i++)
    {
       (q->patient)->personne= ajouter_personne();
    }
    printf("\n entrez le nombre de maladies chroniques : ");scanf("%d",&nbmal);
    (q->patient)->maladie=NULL;
    for(i=0;i<nbmal;i++)
    {
       (q->patient)->maladie= ajouter_maladie();
    }

    printf("\n entrez date debut confinement : ");(q->debut)= saisir_date();
    printf("\n entrez date fin confinement : "); (q->fin)=saisir_date();
    printf("\n est ce que le patient est confiné chez lui ? (o ou n) : "); scanf("%c",&q->chezlui);
    // si le patient est chez lui on a déjà son adresse //
    if(q->chezlui=='n') {
        affecter_patient_lieu (q,tete);
    printf("\n on vous affecte au lieu : %d %s %s %d ",(q->lieu).numero,(q->lieu).rue,(q->lieu).quartier,(q->lieu).code_postal);}

        if(quar->cell==NULL){ quar->cell=q; }
      else {
            while(quar->suiv!=NULL) { quar=quar->suiv; }
        quar->suiv=(listeq*)malloc(sizeof(listeq));
        quar->suiv->cell=q;
         quar->suiv->prec=quar;
         quar->suiv->suiv=NULL;
      }
  p=p->suiv; }
}
}

//------------------------------------------------------------------------------------------------------------------//
listep* rechercher_patients(listep *l_patient)
{
    listep *finale=NULL,*l=l_patient;
     char n[20],p[20],genre;
    int menu=0,age;

    printf("\n Selon quels critères voulez vous faire la recherche ?"
           "\n1) nom et prénom \n2) genre \n3)age \n4) etat stable \n5) etat critique\n entrez votre choix : ---> ");
           scanf("%d",&menu);
           //1-nom & prenom //
           if(menu==1){
    printf("\n entrez nom du patient :"); scanf("%s",n);
     printf("\n entrez prenom du patient :"); scanf("%s",p);
    while(((strcmp(n,l->cell->nom))!=0  || (strcmp(p,l->cell->prenom))!=0 )&& l->suiv!=NULL) { l=l->suiv; }
    if((strcmp(n,l->cell->nom))==0 && (strcmp(p,l->cell->prenom))==0)
        {
            afficher_patient(l->cell);
            finale=(listep*)malloc(sizeof(listep));
    finale->prec=NULL;
    finale->suiv=NULL;
            finale->cell=l->cell;

        }


    }
    //2-genre//
    if(menu==2) {
            printf("\n entrez genre : "); scanf("%c",&genre);
        while(l->suiv!=NULL){
            if((l->cell)->genre==genre){
                    afficher_patient(l->cell);
          if(finale==NULL) { finale=(listep*)malloc(sizeof(listep));
    finale->prec=NULL;
    finale->suiv=NULL;
            finale->cell=l->cell;}

    else { finale->suiv=(listep*)malloc(sizeof(listep));
    finale->suiv->prec=finale;
    finale=finale->suiv;
    finale->suiv=NULL;
            finale->cell=l->cell ;}
            }

        }
        while(finale->prec!=NULL) finale=finale->prec;

    }
    //3-age//
    if(menu==3) {
            printf("\n entrez age : "); scanf("%d",&age);
        while(l->suiv!=NULL){
            if((l->cell)->age==age){
                    afficher_patient(l->cell);
          if(finale==NULL) { finale=(listep*)malloc(sizeof(listep));
    finale->prec=NULL;
    finale->suiv=NULL;
            finale->cell=l->cell;}

    else { finale->suiv=(listep*)malloc(sizeof(listep));
    finale->suiv->prec=finale;
    finale=finale->suiv;
    finale->suiv=NULL;
            finale->cell=l->cell ;}
            }

        }
        while(finale->prec!=NULL) finale=finale->prec;


    }
    //4- etat stable //
      if(menu==4) {
        while(l->suiv!=NULL){
            if(strcmp(((l->cell)->etat),"stable")==0){
                    afficher_patient(l->cell);
          if(finale==NULL) { finale=(listep*)malloc(sizeof(listep));
    finale->prec=NULL;
    finale->suiv=NULL;
            finale->cell=l->cell;}

    else { finale->suiv=(listep*)malloc(sizeof(listep));
    finale->suiv->prec=finale;
    finale=finale->suiv;
    finale->suiv=NULL;
            finale->cell=l->cell ;}
            }

        }
        while(finale->prec!=NULL) finale=finale->prec;


    }

    //5-etat critique //
      if(menu==5) {

        while(l->suiv!=NULL){
            if(strcmp(((l->cell)->etat),"critique")==0){
                    afficher_patient(l->cell);
          if(finale==NULL) { finale=(listep*)malloc(sizeof(listep));
    finale->prec=NULL;
    finale->suiv=NULL;
            finale->cell=l->cell;}

    else { finale->suiv=(listep*)malloc(sizeof(listep));
    finale->suiv->prec=finale;
    finale=finale->suiv;
    finale->suiv=NULL;
            finale->cell=l->cell ;}
            }

        }
        while(finale->prec!=NULL) finale=finale->prec;


    }
    return finale;

}
//------------------------------------------------------------------------------------------------------------------//
void afficher_patient(patient *p)
{
    maladie *mal= p->maladie ;
    personne *pers=p->personne;
printf(" \n nom : %s",p->nom);
    printf(" \n prenom : %s",p->prenom);
    printf(" \n age : %d",p->age);
    if(p->genre=='f') printf(" \n genre : femme");
    else printf(" \n genre : homme");
    printf(" \nadresse : ");afficher_adresse(&(p->adresse));
    if(p->cont_loc=='o')printf("\n la contamination est locale ");
    else printf("\n la contamination n'est pas locale ");
    printf(" \netat (critique ou stable) : %s",p->etat);
    while(pers!=NULL){
        afficher_personne(pers);
        pers=pers->suiv;
    }
    while(mal!=NULL)
    {
        printf("\n maladie : %s",mal->mal);
    }
}
//------------------------------------------------------------------------------------------------------------------//
void afficher_personne(personne *p)
{
    printf(" \n nom : %s",p->nom);
    printf(" \n prenom : %s",p->prenom);
    printf(" \n age : %d",p->age);
    printf(" \n genre : %c",p->genre);
    printf(" \nadresse : ");afficher_adresse(&(p->adresse));
    if(p->cont_loc=='o')printf("\n la contamination est locale ");
    else printf("\n la contamination n'est pas locale ");
}
//-------------------------------------------------------------------------------------------------------------//
void afficher_lieu(lieu* tete)
{   lieu* l=tete;

        while(l!=NULL) {
            printf("\n nom du lieu :%s",l->nom);printf("\nadresse : ");
            afficher_adresse(&(l->adresse));
            printf("\n disponibilite du lieu : %d",l->dispo);
            printf("\n nombre de personnes confinées : %d",l->nb_patients);
            l=l->suiv;
        }

}
//------------------------------------------------------------------------------------------------------------------//
void afficher_quarantaine(quarantaine *q)
{
    afficher_patient(q->patient);
    printf("\n date debut confinement :"); afficher_date(&(q->debut));
    printf("\n date fin confinement :"); afficher_date(&(q->fin));
    if(q->chezlui=='o') printf("\n la personne est confinee chez elle ");
    else printf("la personne est confinee a l'adresse "); afficher_adresse(&(q->lieu));
}
//------------------------------------------------------------------------------------------------------------------//
void afficher_hopital(hopital *h)
{
    int i;
     listep *aide=h->patients;
     printf("\nom de l'hopital : %s",h->nom);
    printf("\n son adresse :  ") ;afficher_adresse(&(h->adresse));
     printf("\n nombre de lit disponibles : %d",h->lit_dispo);
     printf("\n nombre de medecins : %d",h->medecin);
     printf("\n nombre de paramedicaux : %d",h->paramed);
     printf("\n nombre de patients : %d",h->nb_patients);
     for(i=0;i<h->nb_patients;i++)
     {
         afficher_patient(aide->cell);
         aide=aide->suiv;
     }
}
//------------------------------------------------------------------------------------------------------------------//
hopital* rechercher_hopital(listeh *lh)
{    listeh* h=lh;
    char nom[50];
    printf("\n entrez nom de l'hopital :");scanf("%s",nom);
    while(h->suiv!=NULL)
    {
        if(strcmp(h->cell->nom,nom)==0) {return h->cell;}
        h=h->suiv;
    }
    if(strcmp(h->cell->nom,nom)==0) {return h->cell;}
    else {
            printf("\n cet hopital ne figure pas dans la liste ");  return NULL;
    }
}
