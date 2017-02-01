#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow app_window(sf::VideoMode(1920, 1080), "QueenGame");
	sf::CircleShape shape(100.f);

	shape.setFillColor(sf::Color::Yellow);

	while (app_window.isOpen()) {
		
		sf::Event event;
		while (app_window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				app_window.close();
			}

		}

		app_window.clear();
		app_window.draw(shape);
		app_window.display();

	}
		
	return 0;
}
