void menu(sf::RenderWindow &winwin)
{
    sf::Texture texture;
    sf::Texture regle;
    sf::Sprite sprite;
    sf::Sprite sprite2;
    texture.loadFromFile("C:\\Users\\PC\\Desktop\\Camille\\L1\\code\\coucou\\Image\\start.jpg"); //Charge l'image "commencer"
    regle.loadFromFile("C:\\Users\\PC\\Desktop\\Camille\\L1\\code\\coucou\\Image\\regles.jpg");
    sprite.setTexture(texture);
    sprite2.setTexture(regle);
    sprite.setPosition(sf::Vector2f(400,100));
    sprite2.setPosition(sf::Vector2f(400,300));
    sprite.move(sf::Vector2f(10,10));
    sprite2.move(sf::Vector2f(10,10));

    sf::Event Event;
    winwin.clear(sf::Color(103,154,198)); //affecte une couleur bleuté en fond de notre menu
    winwin.draw(sprite);
    winwin.draw(sprite2);
    winwin.display();

    bool finished = false;
    while (! finished) {

        while (winwin.pollEvent(Event))
        {

            if (Event.type == sf::Event::Closed)
            {
                return;
            }
            if (Event.type == sf::Event::MouseButtonPressed) {
                float X=Event.mouseButton.x;
                float Y=Event.mouseButton.y;


                if (Event.mouseButton.button == sf::Mouse::Left && sprite.getGlobalBounds().contains(X, Y)) {
                    finished = true;
                }
            }
        }

    }
    return;
}
