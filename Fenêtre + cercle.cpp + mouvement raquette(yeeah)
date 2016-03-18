
#include <SFML/Graphics.hpp>

int main()
{
  float x = 600;
  float y = 800;
    sf::RenderWindow window(sf::VideoMode(1200, 900), "Fenetre");
    sf::CircleShape circle(7.f);
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(110,10));
    rectangle.setFillColor(sf::Color::Cyan);
    rectangle.setPosition(600,850);
    circle.setPosition(x,y);
    circle.setFillColor(sf::Color::Magenta);
    circle.setOutlineThickness(1);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
                
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            		rectangle.move(10,0);
        	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            		rectangle.move(-10,0);
        }

        window.clear();
        window.draw(circle);
	window.draw(rectangle);
        window.display();
    }

    return 0;
}
