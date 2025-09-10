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
    printf("les joueurs:\n id:%d,nom:%s,prenom:%s,maillot:%d,poste:%s,age:%d,buts:%d \n",J.id,J.nom,J.prenom,J.numeroMaillot,J.poste,J.age,J.buts);
}
//la fonction AfficheJoueurs affiche tous les joueurs a laide de fonction afficheJoueur
void AfficheJoueurs(){
    for(int i=0;i<nbC;i++){
        AfficheJoueur(Equipe[i]);
    }
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
;             if(n+nbC>100){
                 printf("l'equipe est plein entrer un nombre inferieur");
             }else{
                 AjoutJoueurs(n);
             }
             break;
             case 2:AfficheJoueurs();
             break;
             case 3:printf("choisir depuis le menu!!!");
             break;
             case 4:printf("choisir depuis le menu!!!");
             break;
             case 5:printf("choisir depuis le menu!!!");
             break;
             case 6:printf("choisir depuis le menu!!!");
             break;
             default :printf("choisir depuis le menu!!!");
             break;
             
         }
        
    }while(choix!=0);
    
    
    return 0;
}

