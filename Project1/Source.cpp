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

}
