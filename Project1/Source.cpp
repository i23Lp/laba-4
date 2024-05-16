#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <random>
using namespace sf;

int main()
{
    RenderWindow window1(VideoMode(800, 600), "Многоугольники");

    // Создание прямоугольника
    sf::RectangleShape rectangle(sf::Vector2f(100, 50)); // Размер прямоугольника
    rectangle.setPosition(window1.getSize().x / 4.f, window1.getSize().y / 2.f);
    rectangle.setFillColor(Color::Yellow);

    // Создание круга
    sf::CircleShape circle(50); // Радиус круга
    circle.setPosition(window1.getSize().x / 2.f, window1.getSize().y / 4.f);
    circle.setFillColor(Color::Red);

    Vector2f velocity1(2.5f, 2.5f); // Уменьшенная скорость
    Vector2f velocity2(-2.5f, -2.5f); // Скорость круга
    bool moveRight = true;

    // Генератор случайных чисел
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

        // Обновление положения прямоугольника
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

        // Обновление положения круга
        circle.move(velocity2.x, velocity2.y);

        // Проверка столкновения и изменение скорости
        if (rectangle.getGlobalBounds().intersects(circle.getGlobalBounds())) {
            // Случайное изменение направления одного из объектов
            if (distribution(generator) == 1) {
                velocity1.x = -velocity1.x;
            }
            else {
                velocity2.x = -velocity2.x;
            }
        }

        // Отрисовка
        window1.clear();
        window1.draw(rectangle);
        window1.draw(circle); // Рисуем круг
        window1.display();
    }

    return 0;
}
