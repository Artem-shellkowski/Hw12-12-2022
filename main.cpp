#include  <SFML/Graphics.hpp>
using namespace sf;

int main() {
    RenderWindow window(VideoMode(800, 600), "lesson-2-2");

    CircleShape C1;
    // Установка радиуса
    C1.setRadius(25);

    // Установка позиции
    C1.setPosition(375, 275);

    float ballSpeedX = 1.f;
    float ballSpeedY = 1.f;

    while (window.isOpen()) {
        // Конструктор обработчика событий
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (C1.getPosition().x <= 0 ||
                C1.getPosition().x >= 400)
            {
                ballSpeedX = 0;
            }
            if (C1.getPosition().y <= 0 ||
                C1.getPosition().y >=300)
            {
                ballSpeedY = 0;
            }

        }
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            C1.move(0.f, -ballSpeedY);
        }
        else if (Keyboard::isKeyPressed(Keyboard::Down)) {
            C1.move(0.f, ballSpeedY);
        }
            if (Keyboard::isKeyPressed(Keyboard::Left)) {
                C1.move(-ballSpeedX, 0.f);
            }
            else if (Keyboard::isKeyPressed(Keyboard::Right)) {
                C1.move(ballSpeedX, 0.f);
            }
            // Вызовы функций
            window.clear();
            window.draw(C1);
            window.display();
        }
        return 0;
    }
