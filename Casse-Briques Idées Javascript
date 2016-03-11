                            Exemple d'un début de programmation Casse-Briques en Java (Processing) 
                                               Quelques idées importantes !


int x = int(random(25,775)); // Position initiale de la balle sur l'axe x 
int y = 350 ; // Position initiale de la balle sur l'axe y 
int speedx = 5 ; // Vitesse initiale sur l'axe x 
int speedy = 5 ; // Vitesse initiale sur l'axe y
int score = 0 ; // Score initial
int n = 1 ; // Niveau initial
PImage bg ; // Image de fond 
int bonus = 0 ; // Bonus initial
int[] niveau = {1,2,3,4,5,6,7,8,9,10}; // Liste des niveaux
int[] vitesse = {5,7,9,10,11,12,13,14,15,16}; // Liste des différentes vitesses
int[][] briques = new int [5][15] ; // Liste de brique [Nombre de lignes][Nombre de colonnes] (5 et 15 étant des exemples)
int lifes = 3 ; // Nombre initial de vies
boolean clic=false; //Le clique de la souris est déclarée comme faux 
PImage restart ; // Image de restart
PImage nextlvl ; // Image de niveau suivant

void setup() {
    for (int i = 0; i < 5; i = i + 1) {  // Setup des lignes de briques
      for (int j = 0; j < 15 ; j = j + 1) { // Setup des colonnes de briques
          briques[i][j] = 1 ; // Hop Hop 
       }
  }
  size (800, 600) ; // Taille de la fenêtre 
  bg = loadImage("espace.jpg") ; // Image de fond 
}
void draw() {
 
  fill (1002, 1002, 1002) ; // Couleur de la balle et de la barre (
  background (bg) ; // Image de fond 
  ellipse (x, y, 25, 25) ; // Création de la balle (coordonnée x, coordonnée y, rayons de l'ellipse)
  textSize (20); // On définit la taille des prochains textes qui vont apparaître sur la fenêtre de jeu
  text ("LEVEL " + n, 360, 30) ; // Affichage du niveau (en fonction de la variable "n")
  text ("lives = " + lifes, 20, 70) ; // Affichage du nombre de vies
  x = x+speedx ; // Mouvement de la balle sur l'axe x
  y = y+speedy ; // Mouvement de la balle sur l'axe y 
  rect(mouseX, 575, 150, 20) ; // Le déplacement de la barre dépend de celui de la souris (coordonnée x, coorodnnée y, longueur, largeur)
  text ("score = " + score, 20, 30) ; // Affichage du score (en fonction de la variable "score") (20 et 30 étant des coordonnées)
  
  for (int i = 2; i < 5; i = i + 1) { // Création de lignes de briques (numérotées de 2 à 4)
      for (int j = 1; j < 15; j = j + 1) {  // Création de colonnes de briques (numérotées de 1 à 14)
          fill (1000,1000,1000) ;  // Couleur des briques (blanc)
          if (briques[i][j] == 1) {  
            rect (j*50, i*60, 45, 30) ; // Modélisation des briques
             // Nous pouvons prendre différentes valeurs initiales et finales pour i et j selon la façon que nous voulons créer les briques et ainsi créer une boucle allant de i = 1 à i = 2 puis une autre de 4 à 5 
          } 
       }
  }
  
  if (x>=50 && x<=95){
        if (briques[4][1] == 1){ // Si il y a une brique, sur la 3éme ligne et sur la 1ére colonne
        if (y+25<=300 && y+25>=260){ 
          briques[4][1] = 0; // Disparition de la brique
          speedy = -speedy; // La balle rebondit
          score = score + 1; // Augmentation du score
    }
        } //Un exemple de façon afin de faire disparaître une brique si les coordonnées de la balle sont à un endroit précis (il faudrait normalement utiliser la même sorte de boucle afin de ne pas répéter ces conditions autant de fois qu'il y a de briques (et donc remplacer les constantes par les valeurs des boucles i et j))
  
  if (y>=560) { //La condition ci-dessous est appliquée ssi la balle se trouve être au dessus la barre que contrôle le joueur
    if (x>=mouseX && x<=mouseX+150) { // Si la balle heurte la barre 
     speedy = -speedy ; // Alors la balle rebondit 
  } 

  }

  if (y>=575) { // Si la balle dépasse 575 en ordonnée, donc si la balle se trouve être en dessous de la barre par rapport aux coordonnées en ordonnée
    lifes = lifes - 1 ; // Le nombre de vies diminue 
    x = int(random(25,775)); // Position réapparition balle sur X (On peut aussi la faire réapparaître au centre de la raquette, l'immobiliser et lui redonner un mouvement ssi le joueur le décide en cliquant (cf après pour le clique de la souris)
    y=350 ; // Position réapparition balle sur Y (patati patata pareil)
  }
  
  if (x>=800) { // Si la balle heurte le côté droit 
    speedx = -speedx ; // Alors la balle change de direction
  }
  if (y<=0) { // Si la balle heurte le haut 
    speedy = -speedy ; // Alors la balle change de direction 
  }
 if (x<=0) {  // Si la balle heurte le côté gauche
    speedx = -speedx ; // Alors la balle change de direction
  }
  if (lifes==0) { // Quand on a perdu toutes les vies
     text ("GAME OVER", 340, 220) ; // Afficher "GAME OVER"
     lifes = 0 ; // Reset des vies
     x=-1000 ; // La balle disparaît de l'écran car on ne savait pas faire autrement que de l'envoyer dans l'espace temps
     y=-1000 ; // IDEM
     score = 0; // Reset du score
     restart = loadImage("restart21.jpg"); // Load l'image servant de bouton restart
     for (int i = 2; i < 5; i = i + 1) { // Boucle correspondant aux lignes de briques (numérotées de 2 à 4)
            for (int j = 1; j < 15; j = j + 1) { // Boucle correspondant aux colonnes de briques (numérotées de 1 à 14)
              briques[i][j] = 0; // Disparition de toutes les briques 
            }
     }
     image(restart,315, 320); // Pop de l'image aux coordonnées 315 320
      if (clic==true){ // Si on a cliqué dans la zone où se trouve l'image (cf la fin du programme)
          for (int i = 2; i < 5; i = i + 1) { // Création de lignes de briques (numérotées de 2 à 4)
            for (int j = 1; j < 15; j = j + 1) { // Création de colonnes de briques (numérotées de 1 à 14)
              fill (1000,1000,1000) ; // Couleur des briques (blanc)
              briques[i][j] = 1; // Reset des briques 
          if (briques[i][j] == 1) {  
            rect (j*50, i*60, 45, 30) ; // Modélisation des briques 
          }  
       }
  }
        x = int(random(25,775)); // Position réapparition balle sur X (Pareil qu'avant si on veut la faire réapparaître sur la barre)
        y=350 ; // Position réapparition balle sur Y
        lifes = lifes+3 ; // Remise des vies 
        clic = false; // Une fois qu'on a cliqué, on remet le clique comme non existant sinon la condition reste vraie h24
  }
  }
  

if (score==42){ // Si on a cassé toutes les briques
       text ("Congratulations, YOU WIN", 285, 220) ; // Afficher "Congratulations, YOU WIN" AMAZING
     x=-1000 ; // La balle disparaît de l'écran
     y=-1000 ;
     nextlvl = loadImage("nextlvl.png"); 
     nextlvl.resize(100, 125) ; // Redimensionnement de l'image
     image(nextlvl,360, 320); // Bouton pour passer au niveau suivant aux coordonnées 360 320
      if (clic==true){ // Si on clique sur le bouton (même histoire qu'avant)
      n = n + 1 ; // Niveau supérieur
          for (int i = 2; i < 5; i = i + 1) { // Création de lignes de briques (numérotées de 2 à 4)
            for (int j = 1; j < 15; j = j + 1) { // Création de colonnes de briques (numérotées de 1 à 14)
              fill (1000,1000,1000) ; // Couleur des briques (blanc)
              briques[i][j] = 1; // Reset des briques 
          if (briques[i][j] == 1) {  
            rect (j*50, i*60, 45, 30) ; // Modélisation des briques
          }  
       }
  }
        x = int(random(25,775)); // Position réapparition balle sur X
        y=350 ; // Position réapparition balle sur Y
        score = 0; // Reset du score 
        clic = false;
  }
}
if (niveau[n] == n){ //Par exemple si nous sommes au niveau 2 alors speedx et speedy prendront comme valeur la deuxième valeur de la liste vitesse[]
   speedx = vitesse[n]; // Augmentation de la vitesse en fonction des niveaux
   speedy = vitesse[n] ;
  }
  
        
  
}

void mousePressed(){
    
    if ((mouseX>330) && (mouseX<507) && (mouseY>320) && (mouseY<400)) // Zone dans laquelle le clic est effectif (si notre souris se trouve dans cette zone)
      if(clic==false) { // si on clique (alors que nous sommes dans cette zone)
        clic=true; // alors voilà.
      } 
      
    
  } 
