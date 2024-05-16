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
}
