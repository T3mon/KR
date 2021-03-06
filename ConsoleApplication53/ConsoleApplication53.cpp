#include <iostream>
#include "stdafx.h"
#include <SFML/Graphics.hpp>


using namespace std;
using namespace sf;

class Ded {
public:

	Texture ded_texture;
	Sprite ded_sprite;

	Texture text_texture;
	Sprite text_sprite;

	Texture present_texture;
	Sprite present_sprite;

	int direction1, direction2, pos1, pos2;

	Ded() {


		ded_texture.loadFromFile("img/santa.png");
		text_texture.loadFromFile("img/text.png");
		present_texture.loadFromFile("img/present.png");

		ded_sprite.setTexture(ded_texture);
		text_sprite.setTexture(text_texture);
		present_sprite.setTexture(present_texture);

		ded_sprite.setTextureRect(IntRect(0, 0, 250, 200));
		text_sprite.setTextureRect(IntRect(0, 0, 800, 700));
		present_sprite.setTextureRect(IntRect(0, 0, 200, 500));

		ded_sprite.setPosition(700, 300);
		text_sprite.setPosition(20, 20);
		present_sprite.setPosition(830, 310);


	}
	void Throw(int direction1, int direction2, int pos1, int pos2) {
		present_sprite.move(direction1, direction2);
		present_sprite.setPosition(pos1, pos2);


	}
};
class Beard {
public:
	int x, y;
	Texture beard_texture;
	Sprite beard_sprite;

	Beard() {
		x = 700;
		y = 300;
		beard_texture.loadFromFile("img/beard.png");
		beard_sprite.setTexture(beard_texture);
		beard_sprite.setTextureRect(IntRect(0, 0, 700, 800));

		beard_sprite.setPosition(x, y);
	}
};



int main()
{
	sf::RenderWindow window(sf::VideoMode(1800, 900), "Santa");
	setlocale(LC_ALL, "rus");
	Ded ded;
	Beard beard;



	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if ((Keyboard::isKeyPressed(Keyboard::Left)) || (Keyboard::isKeyPressed(Keyboard::A))) {

			//window.draw(ded.present_sprite);
			//ded.Throw(0, -1, 750 - i, 370);
	
			//ded.present_sprite.setPosition(750, 370);
			ded.present_sprite.move(-0.1, 0);

		}
		if ((Keyboard::isKeyPressed(Keyboard::Right)) || (Keyboard::isKeyPressed(Keyboard::D))) {

			//ded.Throw(0, -1, 900, 370);
			ded.present_sprite.move(0.1, 0);

		}
		if ((Keyboard::isKeyPressed(Keyboard::Down)) || (Keyboard::isKeyPressed(Keyboard::S))) {

			//ded.Throw(0, -1, 830, 490);
			ded.present_sprite.move(0, 0.1);


		}
		if ((Keyboard::isKeyPressed(Keyboard::Up)) || (Keyboard::isKeyPressed(Keyboard::W))) {

			//ded.Throw(0, -1, 830, 230);
			ded.present_sprite.move(0, -0.1);
		}
	
		if (Keyboard::isKeyPressed(Keyboard::R)) {
			ded.ded_sprite.setColor(Color::Red);
		}
		if (Keyboard::isKeyPressed(Keyboard::G)) {
			ded.ded_sprite.setColor(Color::Green);
		}
		if (Keyboard::isKeyPressed(Keyboard::B)) {
			ded.ded_sprite.setColor(Color::Blue);
		}
		if (Keyboard::isKeyPressed(Keyboard::Num1)) { beard.beard_sprite.setScale(1, 1.1); }
		if (Keyboard::isKeyPressed(Keyboard::Num2)) { beard.beard_sprite.setScale(1, 1.2); }
		if (Keyboard::isKeyPressed(Keyboard::Num3)) { beard.beard_sprite.setScale(1, 1.3); }
		if (Keyboard::isKeyPressed(Keyboard::Num4)) { beard.beard_sprite.setScale(1, 1.4); }
		if (Keyboard::isKeyPressed(Keyboard::Num5)) { beard.beard_sprite.setScale(1, 1.5); }
		if (Keyboard::isKeyPressed(Keyboard::Num6)) { beard.beard_sprite.setScale(1, 1.6); }
		if (Keyboard::isKeyPressed(Keyboard::Num7)) { beard.beard_sprite.setScale(1, 1.7); }
		if (Keyboard::isKeyPressed(Keyboard::Num8)) { beard.beard_sprite.setScale(1, 1.8); }
		if (Keyboard::isKeyPressed(Keyboard::Num9)) { beard.beard_sprite.setScale(1, 1.9); }
		

		window.clear();
		window.draw(ded.text_sprite);
		window.draw(ded.ded_sprite);
		window.draw(ded.present_sprite);
		window.draw(beard.beard_sprite);
		window.display();
	}

	return 0;
}