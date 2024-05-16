#include <SFML/Graphics.hpp>

int main()
{
    // ������� ������ ���� ��� �������� �������������
    sf::RenderWindow window1(sf::VideoMode(800, 600), "��������������");

    // ������� ������������
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

    // ������� ������ ���� ��� ������� �����
    sf::RenderWindow window2(sf::VideoMode(800, 600), "�����");

    // ������ ����
    sf::CircleShape circle;
    circle.setRadius(50.f);
    circle.setFillColor(sf::Color::Yellow);
    circle.setPosition(window2.getSize().x / 4.f, window2.getSize().y / 2.f);
    sf::Vector2f velocity2(5.f, 5.f);
    bool circleStartedMoving = false; // ���������� ��� �������� ������ �������� �����

    sf::Clock clock;

    // ���� ��� ���� � ��������������
    while (window1.isOpen())
    {
        sf::Event event;
        while (window1.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window1.close();
                circleStartedMoving = true; // �������� �������� ����� ����� ����� �������� ���� � ��������������
            }
        }

        // �������� �������� ������������� � ������ ����
        polygon1.move(velocity1 * 0.01f);
        if (polygon1.getPosition().x - radius1 < 0 || polygon1.getPosition().x + radius1 > window1.getSize().x)
            velocity1.x = -velocity1.x;
        if (polygon1.getPosition().y - radius1 < 0 || polygon1.getPosition().y + radius1 > window1.getSize().y)
            velocity1.y = -velocity1.y;

        // ������� � ��������� ����
        window1.clear();
        window1.draw(polygon1);
        window1.display();
    }

    // ���� ��� ���� � ������, �������� �������� ����� ����� ����� �������� ���� � ��������������
    while (window2.isOpen())
    {
        sf::Event event;
        while (window2.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window2.close();
        }

        // �������� ������� ����� �� ������ ����, ���� ���� ����� ��������
        if (circleStartedMoving)
        {
            circle.move(velocity2 * 0.01f);

            // ������ ������� ��� �����
            if (circle.getPosition().x - circle.getRadius() < 0 || circle.getPosition().x + circle.getRadius() > window2.getSize().x)
                velocity2.x *= -1; // ������ ����������� �� ��� X
            if (circle.getPosition().y - circle.getRadius() < 0 || circle.getPosition().y + circle.getRadius() > window2.getSize().y)
                velocity2.y *= -1; // ������ ����������� �� ��� Y
        }

        // ������� � ��������� ����
        window2.clear();
        window2.draw(circle);
        window2.display();
    }

    return 0;
}
