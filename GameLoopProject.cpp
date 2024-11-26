#include <SFML/Graphics.hpp>
#include <iostream> 

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Game Loop Example");

    
    sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));  
    player.setFillColor(sf::Color::Green);
    player.setPosition(375.0f, 275.0f);  // Starting position

    
    sf::Clock clock;

    while (window.isOpen()) {

        sf::Time deltaTime = clock.restart();

        
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();  
            }
        }

        // Input handling (keyboard)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            player.move(0.0f, -400.0f * deltaTime.asSeconds());  // Faster movement up
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            player.move(0.0f, 400.0f * deltaTime.asSeconds());  // Faster movement down
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            player.move(-400.0f * deltaTime.asSeconds(), 0.0f);  // Faster movement left
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            player.move(400.0f * deltaTime.asSeconds(), 0.0f);  // Faster movement right
        }

        
        if (player.getPosition().x < 0) player.setPosition(0, player.getPosition().y);  
        if (player.getPosition().y < 0) player.setPosition(player.getPosition().x, 0);  
        if (player.getPosition().x + player.getSize().x > window.getSize().x)  
            player.setPosition(window.getSize().x - player.getSize().x, player.getPosition().y);
        if (player.getPosition().y + player.getSize().y > window.getSize().y)  
            player.setPosition(player.getPosition().x, window.getSize().y - player.getSize().y);

        window.clear(sf::Color(200, 200, 200));  
        window.draw(player);  
        window.display();  
    }

    return 0;  
}
