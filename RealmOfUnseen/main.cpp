#include<SFML/Graphics.hpp>
#include<iostream>

int main() {

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Realm of unseen", sf::Style::Default, settings);
	
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	if (playerTexture.loadFromFile("Assets/Player/Texture/PlayerSpriteSheet.png")) {
		std::cout << "image loaded \n";
		playerSprite.setTexture(playerTexture);
		playerSprite.setTextureRect(sf::IntRect(0, 0, 40, 37));
		playerSprite.scale(sf::Vector2f(4, 4));
	}
	else {
		std::cout << "image not loaded \n";
	}
	

	//Game loop
	while (window.isOpen()) {
		/*----------------------------- Update --------------------------------*/

		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		
		sf::Vector2f position = playerSprite.getPosition();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			playerSprite.setPosition(position + sf::Vector2f(0, -1));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			playerSprite.setPosition(position + sf::Vector2f(-1, 0));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			playerSprite.setPosition(position + sf::Vector2f(0, 1));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			playerSprite.setPosition(position + sf::Vector2f(1, 0));
		
		/*----------------------------- Update --------------------------------*/

		/*----------------------------- Draw --------------------------------*/
		window.clear();
		window.draw(playerSprite);
		window.display();
		/*----------------------------- Draw --------------------------------*/
	}
	return 0;
}