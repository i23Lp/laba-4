#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
using namespace sf;

int main()
{
    RenderWindow window1(VideoMode(800, 600), "Многоугольники");

    int sides1 = 5;
    float radius1 = 50.f;
    ConvexShape polygon1;
    polygon1.setPointCount(sides1);
    for (int i = 0; i < sides1; i++)
    {
        float angle = 2.f * 3.14 * i / sides1 - 3.14 / 2.f;
        polygon1.setPoint(i, Vector2f(cos(angle) * radius1, sin(angle) * radius1));
    }
    polygon1.setFillColor(Color::Green);
    polygon1.setPosition(window1.getSize().x / 4.f, window1.getSize().y / 2.f);

    Vector2f velocity1(0.015f,0.015f);
    bool moveRight = true;

    while (window1.isOpen())
    {
        Event event;
        while (window1.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window1.close();
        }

        polygon1.move(velocity1.x, velocity1.y);
        if (moveRight && polygon1.getPosition().x + polygon1.getGlobalBounds().width > window1.getSize().x)
        {
            moveRight = false;
            velocity1.x *= -1;
        }
        else if (!moveRight && polygon1.getPosition().x < 0)
        {
            moveRight = true;
            velocity1.x *= -1;
        }

        if (polygon1.getPosition().y + polygon1.getGlobalBounds().height > window1.getSize().y || polygon1.getPosition().y < 0)
        {
            velocity1.y *= -1;
        }

        
        window1.clear();
        window1.draw(polygon1);
        window1.display();
    }

    return 0;
}
