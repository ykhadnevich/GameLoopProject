#include <SFML/Graphics.hpp>
#include <iostream> // For debugging

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game Loop Example");

    // Define the player's shape (a larger green rectangle)
    sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));  // 100x100 rectangle
    player.setFillColor(sf::Color::Green);
    player.setPosition(375.0f, 275.0f);  // Starting position

    // Create a clock to track delta time
    sf::Clock clock;

    // Game loop
    while (window.isOpen()) {
        // Calculate deltaTime
        sf::Time deltaTime = clock.restart();

        // Handle events (like closing the window)
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();  // Close the window if the close button is pressed
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

        // Prevent the player from going out of bounds
        if (player.getPosition().x < 0) player.setPosition(0, player.getPosition().y);  // Left bound
        if (player.getPosition().y < 0) player.setPosition(player.getPosition().x, 0);  // Top bound
        if (player.getPosition().x + player.getSize().x > window.getSize().x)  // Right bound
            player.setPosition(window.getSize().x - player.getSize().x, player.getPosition().y);
        if (player.getPosition().y + player.getSize().y > window.getSize().y)  // Bottom bound
            player.setPosition(player.getPosition().x, window.getSize().y - player.getSize().y);

        // Rendering
        window.clear(sf::Color(200, 200, 200));  // Light gray background for contrast
        window.draw(player);  // Draw the player (green rectangle)
        window.display();  // Display the updated window contents
    }

    return 0;  // Return success
}
