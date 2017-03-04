#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <iostream>
#include <string>
#include "../includes/gagner.h"
#include "../includes/briques.h"
#include "../includes/fin.h"

void gagner(sf::RenderWindow &window, int** brique, int nbLignes, int nbColonnes,int &niveau,int &scoreMax){
    int score = 0;
    for (int o = 1; o < nbLignes; o++ ) {
        for (int l = 1; l < nbColonnes; l++) {
            if (brique[o][l] == 0){
                score++;
            }
        }
    }
    if(score == scoreMax && niveau < 3){
        sf::RenderWindow gagner(sf::VideoMode(1000, 800), "GAGNE");
        menugagner(window,gagner,brique);
        score=0;
        niveau++;
    }

    else{
         if(score == scoreMax){
            niveau ++;
            score = 0;
            }
    }
    if(niveau == 4){
        sf::RenderWindow generique(sf::VideoMode(1000, 800), "GENERIQUE");
        fin(generique,window);
    }
}

void menugagner (sf::RenderWindow &window,sf::RenderWindow &gagner,int** brique){ // On cr�e une fonction "menuGagner" pour lancer une fen�tre avec des boutons niveau suivant & quitter lorsque l'on a gagn�


    sf::Texture level; // On cr�e une premi�re texture pour notre bouton "Niveau_Suivant"
    sf::Texture fara; // on cr�e une seconde texture pour notre bouton "quitter"
    sf::Sprite niveausuiv; // On cr�e notre premier sprite pour notre bouton "niveau Suivant" que l'on associera � notre texture "restart"
    sf::Sprite lasciare; // On cr�e notre second sprite pour notre bouton "quitter" que l'on associera � notre texture "leave"
    level.loadFromFile("images\\niveau_suivant.jpg"); //Charge l'image "Niveau Suivant"
    fara.loadFromFile("images\\quitter.jpg"); //charge l'image "quitter"
    niveausuiv.setTexture(level); // On associe notre premi�re texture nomm�e "level" � notre premier sprite "niveausuiv"
    lasciare.setTexture(fara);// On associe notre seconde texture nomm�e "fara" � notre second sprite "lasciare"
    niveausuiv.setPosition(sf::Vector2f(240,100)); // On associe � notre bouton "Niveau_Suivant" une position � 240 pixel sur notre axe X & � 100 sur notre axe Y
    lasciare.setPosition(sf::Vector2f(300,300)); // On associe � notre bouton "quitter" une position � 300 pixel sur notre axe X & � 300 sur notre axe Y
    niveausuiv.move(sf::Vector2f(10,10));
    lasciare.move(sf::Vector2f(10,10));

    sf::Event evento; // On cr�e un evenement
    gagner.clear(sf::Color(103,154,198)); //affecte une couleur bleut� en fond de notre menu
    gagner.draw(niveausuiv); // On dessine notre sprite "niveauSuiv" pour afficher notre bouton "recommencer"
    gagner.draw(lasciare); // On dessine notre sprite "lasciare" pour afficher notre bouton "quitter"
    gagner.display();

    bool enda = false; // On cr�e un bool�en pour laisser notre fenetre de menu ouverte (tant qu'on n'a pas fait d'evenement)
    while (! enda) { // Boucle while pour laisser la fenetre ouverte

        while (gagner.pollEvent(evento)) // Boucle while , qui prend en compte notre fenetre nomm�e winwin (appel�e lors du main) & notre evenement
        {

            if (evento.type == sf::Event::Closed) // Si on appuie sur la croix
            {
                return; //la page se ferme
            }
            if (evento.type == sf::Event::MouseButtonPressed) { // Si on clique sur un bouton de notre souris.
                float X=evento.mouseButton.x; // On r�cup�re les coordonn�es de notre souris sur l'axe X
                float Y=evento.mouseButton.y; // On r�cup�re les coordonn�es de notre souris sur l'axe Y


                if (evento.mouseButton.button == sf::Mouse::Left && niveausuiv.getGlobalBounds().contains(X, Y)) { // Si on fait un clic gauche et que les coordonn�es de notre souris coincident avec notre sprite "verlassen"

                    initialisationBrique(brique, 5, 16);
                    enda = true;// La fenetre "Perdu" se ferme et le jeu se relance

                }
                if (evento.mouseButton.button == sf::Mouse::Left && lasciare.getGlobalBounds().contains(X, Y)){ // Si on fait un clic gauche et que les coordon�es de notre souris coincident avec notre sprite "rejour"

                        window.close();
                        return; // La page se ferme et donc on quitte le jeu


                }
            }
        }

    }
    return;
}
