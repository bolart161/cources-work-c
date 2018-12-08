#ifndef DRAWER_HPP
#define DRAWER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "Game.hpp"

class Drawer
{
public:
	Drawer();
	void DrawField(Game &);

	bool isOverGame_;
	sf::RenderWindow window;
	std::vector<sf::Texture> pieceTextures_;
};

#endif
