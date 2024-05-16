#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window1(sf::VideoMode(800, 600), "Многоугольники");
    int sides1 = 5;
    float radius1 = 50.f;
    sf::ConvexShape polygon1;
    polygon1.setPointCount(sides1);
    for (int i = 0; i < sides1; i++)
    {
        float angle = 2.f * 3.14 * i / sides1 - 3.14 / 2.f;
        polygon1.setPoint(i, sf::Vector2f(cos(angle) * radius1, sin(angle) * radius1));
    }
    polygon1.setFillColor(sf::Color::Green);
    polygon1.setPosition(window1.getSize().x / 4.f, window1.getSize().y / 2.f);

    sf::Vector2f velocity1(5.f, 5.f); // Скорость полигона
    bool moveRight = true; // Направление движения

    while (window1.isOpen())
    {
        sf::Event event;
        while (window1.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window1.close();
        }
    }
    polygon1.move(velocity1.x, velocity1.y);
    if (moveRight && polygon1.getPosition().x + polygon1.getGlobalBounds().width > window1.getSize().x)
    {
        moveRight = false;
        velocity1.x *= -1; // Изменение направления при столкновении с правой границей
    }
    else if (!moveRight && polygon1.getPosition().x < 0)
    {
        moveRight = true;
        velocity1.x *= -1; // Изменение направления при столкновении с левой границей
    }
    if (polygon1.getPosition().y + polygon1.getGlobalBounds().height > window1.getSize().y || polygon1.getPosition().y < 0)
    {
        velocity1.y *= -1; // Изменение направления при столкновении с вертикальными границами
    }
}
