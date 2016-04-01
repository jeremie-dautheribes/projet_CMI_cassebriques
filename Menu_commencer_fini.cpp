void menu(sf::RenderWindow &winwin)
{
    sf::Texture texture;
    sf::Sprite sprite;
    texture.loadFromFile("C:\\Users\\PC\\Desktop\\Camille\\L1\\code\\Casse_Briques\\obj\\start.png"); //Charge l'image "commencer"
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(400,250));
    sprite.move(sf::Vector2f(10,10));

    sf::Event Event;
    winwin.clear(sf::Color(138,104,158)); //affecte une couleur violine en fond de notre menu
    winwin.draw(sprite);
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
