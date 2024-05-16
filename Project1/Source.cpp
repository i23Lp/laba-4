#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <random>
using namespace sf;
using namespace std;

int main()
{
    RenderWindow window1(VideoMode(800, 600), "Многоугольники");

    
    sf::RectangleShape rectangle(sf::Vector2f(100, 50));  
    rectangle.setPosition(window1.getSize().x / 4.f, window1.getSize().y / 2.f);
    rectangle.setFillColor(Color::Yellow);

    
    sf::CircleShape circle(50);  
    circle.setPosition(window1.getSize().x / 2.f, window1.getSize().y / 4.f);
    circle.setFillColor(Color::Red);

    Vector2f velocity1(2.5f, 2.5f);  
    Vector2f velocity2(-2.5f, -2.5f);  
    bool moveRight = true;

    
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, 2);

    while (window1.isOpen())
    {
        Event event;
        while (window1.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window1.close();
        }

       
        rectangle.move(velocity1.x, velocity1.y);
        if (moveRight && rectangle.getPosition().x + rectangle.getSize().x > window1.getSize().x)
        {
            moveRight = false;
            velocity1.x *= -1;
        }
        else if (!moveRight && rectangle.getPosition().x < 0)
        {
            moveRight = true;
            velocity1.x *= -1;
        }

        if (rectangle.getPosition().y + rectangle.getSize().y > window1.getSize().y || rectangle.getPosition().y < 0)
        {
            velocity1.y *= -1;
        }

      
        circle.move(velocity2.x, velocity2.y);

         
        if (rectangle.getGlobalBounds().intersects(circle.getGlobalBounds())) {
           
            if (distribution(generator) == 1) {
                velocity1.x = -velocity1.x;
            }
            else {
                velocity2.x = -velocity2.x;
            }
        }

        
        window1.clear();
        window1.draw(rectangle);
        window1.draw(circle); 
        window1.display();
    }

    return 0;
}
