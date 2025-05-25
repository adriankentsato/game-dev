#include <iostream>
#include <optional>

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"

int main(int argc, char * argv[]) {
    std::cout << "Creating window" << "\n";
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(800, 600)), "SFML Application");
    sf::Clock clock;

    window.setFramerateLimit(60);

    if (!ImGui::SFML::Init(window)) {
        return -1;
    }

    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();
        float dt = deltaTime.asSeconds();

        while (const std::optional event = window.pollEvent()) {
            ImGui::SFML::ProcessEvent(window, event.value());

            if (event->is<sf::Event::Closed>()) {
                std::cout << "Destroying window" << "\n";
                window.close();
            }
        }

        ImGui::SFML::Update(window, deltaTime);

        // Create ImGui window
        ImGui::Begin("Controls");
        static float sliderValue = 0.0f;
        ImGui::SliderFloat("Value", &sliderValue, 0.0f, 1.0f);
        if (ImGui::Button("Click Me")) {
            // Handle button click
        }
        ImGui::End();

        window.clear();
        ImGui::SFML::Render(window);
        window.display();
    }

    std::cout << "Closing..." << "\n";

    return 0;
}
