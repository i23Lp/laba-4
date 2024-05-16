#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
using namespace sf;

int main()
{
    RenderWindow window1(VideoMode(800, 600), "Многоугольники");

    // Создание прямоугольника
    sf::RectangleShape rectangle(sf::Vector2f(100, 50)); // Размер прямоугольника
    rectangle.setPosition(window1.getSize().x / 4.f, window1.getSize().y / 2.f);

    sf::CircleShape circle(50); // Радиус круга
    circle.setPosition(window1.getSize().x / 2.f, window1.getSize().y / 4.f);
    circle.setFillColor(Color::Yellow);

    Vector2f velocity1(0.05f, 0.05f);
    Vector2f velocity2(-0.05f, -0.05f);
    bool moveRight = true;

    // Установка цвета прямоугольника в желтый
    rectangle.setFillColor(Color::Yellow);

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

        // Отрисовка
        window1.clear();
        window1.draw(rectangle);
        window1.display();
    }

    return 0;
}
