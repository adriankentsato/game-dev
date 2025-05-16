#include <iostream>
#include <optional>

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics.hpp>

int main(int argc, char * argv[]) {
    std::cout << "Creating window" << "\n";
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(800, 600)), "SFML Application");

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                std::cout << "Destroying window" << "\n";
                window.close();
            }
        }

        window.clear();
        window.display();
    }

    std::cout << "Closing..." << "\n";

    return 0;
}
