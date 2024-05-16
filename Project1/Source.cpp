#include <SFML/Graphics.hpp>

int main()
{
    // Создаем первое окно для зеленого пятиугольника
    sf::RenderWindow window1(sf::VideoMode(800, 600), "Многоугольники");

    // Зеленый пятиугольник
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
    sf::Vector2f velocity1(5.f, 5.f);

    // Создаем второе окно для желтого круга
    sf::RenderWindow window2(sf::VideoMode(800, 600), "Круги");

    // Желтый круг
    sf::CircleShape circle;
    circle.setRadius(50.f);
    circle.setFillColor(sf::Color::Yellow);
    circle.setPosition(window2.getSize().x / 4.f, window2.getSize().y / 2.f);
    sf::Vector2f velocity2(5.f, 5.f);
    bool circleStartedMoving = false; // Переменная для контроля начала движения круга

    sf::Clock clock;

    // Цикл для окна с пятиугольником
    while (window1.isOpen())
    {
        sf::Event event;
        while (window1.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window1.close();
                circleStartedMoving = true; // Начинаем движение круга сразу после закрытия окна с пятиугольником
            }
        }

        // Движение зеленого пятиугольника в первом окне
        polygon1.move(velocity1 * 0.01f);
        if (polygon1.getPosition().x - radius1 < 0 || polygon1.getPosition().x + radius1 > window1.getSize().x)
            velocity1.x = -velocity1.x;
        if (polygon1.getPosition().y - radius1 < 0 || polygon1.getPosition().y + radius1 > window1.getSize().y)
            velocity1.y = -velocity1.y;

        // Очистка и отрисовка окна
        window1.clear();
        window1.draw(polygon1);
        window1.display();
    }

    // Цикл для окна с кругом, начинаем движение круга сразу после закрытия окна с пятиугольником
    while (window2.isOpen())
    {
        sf::Event event;
        while (window2.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window2.close();
        }

        // Движение желтого круга во втором окне, если круг начал движение
        if (circleStartedMoving)
        {
            circle.move(velocity2 * 0.01f);

            // Логика отскока для круга
            if (circle.getPosition().x - circle.getRadius() < 0 || circle.getPosition().x + circle.getRadius() > window2.getSize().x)
                velocity2.x *= -1; // Меняем направление по оси X
            if (circle.getPosition().y - circle.getRadius() < 0 || circle.getPosition().y + circle.getRadius() > window2.getSize().y)
                velocity2.y *= -1; // Меняем направление по оси Y
        }

        // Очистка и отрисовка окна
        window2.clear();
        window2.draw(circle);
        window2.display();
    }

    return 0;
}
