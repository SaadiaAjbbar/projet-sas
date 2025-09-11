#include <stdio.h>
#include<string.h>
//declaration des variables necessaires
typedef struct{
    int id;
    char nom[50];
    char prenom[50];
    int numeroMaillot;
    char poste[50];
    int age;
    int buts;
}Joueur;
//declration de tableau des joueur
Joueur Equipe[100];
//initialiser le nombre courant des joueures par 0 au debut et sera incrementer dans l'ajout des joueur
int nbC=0;

//fonction saisir un contact return un joueur
Joueur SaisirJoueur(){
    Joueur J;
    J.id=nbC+1;//automatique id icrement dans chaque saisie
    printf("entrer le nom de joueur: ");
    fgets(J.nom,sizeof(J.nom),stdin);
    printf("entrer le prenom de joueur: ");
    fgets(J.prenom,sizeof(J.prenom),stdin);
    printf("entrer le numero de maillot de joueur: ");
    scanf("%d",&J.numeroMaillot);
    getchar();
    printf("entrer le poste soit:gardien, defenseur, milieu OU attaquant: ");
        fgets(J.poste,sizeof(J.poste),stdin);
        //supprimer la \n de fin dans post mnin kandir entrer apres
        int taillePost = strlen(J.poste);
         if(taillePost > 0 && J.poste[taillePost-1] == '\n'){
            J.poste[taillePost-1] = '\0';
        }
    while(strcmp(J.poste,"gardien")!=0 && strcmp(J.poste,"defenseur")!=0 && strcmp(J.poste,"milieu")!=0 && strcmp(J.poste,"attaquant")!=0){
        printf("le poste doit etre :gardien, defenseur, milieu OU attaquant!!!!!");
        fgets(J.poste,sizeof(J.poste),stdin);
        //supprimer la \n de fin dans post mnin kandir entrer apres
        taillePost = strlen(J.poste);
        if(taillePost > 0 && J.poste[taillePost-1] == '\n'){
        J.poste[taillePost-1] = '\0';
        }
    }
        


    
   
    printf("entrer l'age de joueur: ");
    scanf("%d",&J.age);
    getchar();
    printf("entrer le nombre des buts de joueur: ");
    scanf("%d",&J.buts);
    getchar();
    
    return J;
}

//declrer la fonction AjoutJouers()prend n saisi par user
void AjoutJoueurs(int n){
    for(int i=0;i<n;i++){
        Equipe[nbC]=SaisirJoueur();
        nbC++;
    }
}

//declrer la fonction AfficheJoueur qui affiche un seul joueur
void AfficheJoueur(Joueur J){
    printf("id:%d,nom:%s,prenom:%s,maillot:%d,poste:%s,age:%d,buts:%d \n",J.id,J.nom,J.prenom,J.numeroMaillot,J.poste,J.age,J.buts);
}
//la fonction AfficheJouerAge affiche tous les joueurs trie par age a laide de fonction afficheJoueur
void AfficheJouerAge(){
    //trie a bulles
    for(int i=0;i<nbC-1;i++){
        for(int j=0;j<nbC-i-1;j++){
            //comparer les ages de toute les elements dequipe
            if(Equipe[j].age>Equipe[j+1].age){
                //changer si superieur les places des elements par indices
                Joueur tmp=Equipe[j];
                Equipe[j]=Equipe[j+1];
                Equipe[j+1]=tmp;
            }
        }
        
    }
    //boucler sur tous lequipe et affichage par age
    for(int i=0;i<nbC;i++){
        AfficheJoueur(Equipe[i]);
    }
}


//la fonction AfficheJouerOrdreNoms affiche tous les joueurs trie par age a laide de fonction afficheJoueur
void AfficheJouerOrdreNoms(){
    //trie a bulles
    for(int i=0;i<nbC-1;i++){
        for(int j=0;j<nbC-i-1;j++){
            //comparer les noms de toute les elements dequipe
            if(strcmp(Equipe[j].nom,Equipe[j+1].nom)>0){
                //changer si superieur les places des elements par indices
                Joueur tmp=Equipe[j];
                Equipe[j]=Equipe[j+1];
                Equipe[j+1]=tmp;
            }
        }
        
    }
     //boucler sur tous lequipe et affichage par age
      printf("les joueurs:\n ");
    for(int i=0;i<nbC;i++){
        AfficheJoueur(Equipe[i]);
    }
}
//fonction RechercheJoueurId retourne lindice de joueur avec id recherche
  int RechercheJoueurId(int id){
      for(int i=0;i<nbC;i++){
          if(Equipe[i].id==id){
              return i;
          }
      }
      return -1;
  }
  //fonction RetourRechercheJoueurId affiche si joueur avec id recherche existe
  void RetourRechercheJoueurId(int id){
      int resultatrechId=RechercheJoueurId(id);
      if(resultatrechId==-1){
          printf("pas de joueur avec cette id");
      }else {
        AfficheJoueur(Equipe[resultatrechId]);
    }
  }
  
  //fonction SupprimerJoueurId supprimer le joueur avec id recherche
  void SupprimerJoueurId(int id){
      int resultat=RechercheJoueurId(id);
      if(resultat==-1){
          printf("pas de joueur avec cette id");
      }
      for(int i=resultat;i<nbC;i++){
          Equipe[i]=Equipe[i+1];
      }
      nbC--;
      printf("le joueur avec id:%d a ete supprime!\n",id);
      
  }
 
//************main*********8
int main() {
    int choix;
    int n;
    //afficher le menu des choix disponnible
    do{
         printf("********** menu *********\n");
         printf("1 pour Ajouter un joueur\n");
         printf("2 pour Afficher tous les les joueurs\n");
         printf("3 pour modifier un joueur\n");
         printf("4 pour Rechercher un joueur\n");
         printf("5 pour supprimer un joueur\n");
         printf("6 pour afficher les statistiques\n");
         printf("0 pour quitter  :\n" );
         scanf("%d",&choix);
         getchar();
         //appeler les fonctions selon le choix d'utilisateur
         switch(choix){
             case 1:
             printf("entrer le nombre des joueurs que tu veux ajouter: ");
             scanf("%d",&n);
             getchar();
            if(n+nbC>100){
                 printf("l'equipe est plein entrer un nombre inferieur");
             }else{
                 AjoutJoueurs(n);
             }
             break;
             case 2://************** case2  afficher****
             {
             //AfficheJoueurs();
             int choixAfichage;
             printf("choisir :\n");
             printf("1:pour afficher les joueurs par postes\n");
             printf("2:pour afficher les joueurs par ordre alphabitique des noms\n");
             printf("3:pour afficher les joueurs par ages\n");
             scanf("%d",&choixAfichage);
             getchar();
             if(choixAfichage==1){
                printf("pas encore je difine cette foncontion");
             }else if(choixAfichage==2){
                AfficheJouerOrdreNoms();
             }else if(choixAfichage==3){
                AfficheJouerAge();
             }else{
                printf("le choix doit etre 1,2 ou 3!!");
             }
             break;
            }//***************fin case 2 afficher*********** 
            
             case 3:printf("choisir depuis le menu!!!");
             break;
             case 4:int choixId_Nom;
             printf("tapez: 1 Rechercher un joueur par Identifiant \n 2 Rechercher un joueur par Nom: ");
             scanf("%d",&choixId_Nom);
             getchar();
             while(choixId_Nom!=1 && choixId_Nom!=2){
                 printf("entrer choix soit 1 ou 2");
                 scanf("%d",&choixId_Nom);
                 getchar();
             }
             if(choixId_Nom==1){
                 int id;
                 printf("entrer lidentifant");
                 scanf("%d",&id);
                 getchar();
                 RetourRechercheJoueurId(id);
             }else if(choixId_Nom==2){
                 printf("fonction pas encore declare");
             }
             break;
             case 5:int id;
               printf("entrer id de joueur a supprime");
               scanf("%d",&id);
                getchar();
                SupprimerJoueurId(id);
                
             break;
             case 6:printf("choisir depuis le menu!!!");
             break;
             default :printf("choisir depuis le menu!!!");
             break;

             
         }
        
    }while(choix!=0);
    
    
    return 0;
}
