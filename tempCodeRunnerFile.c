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