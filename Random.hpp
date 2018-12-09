#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <iostream>
#include <random>
#include "Game.hpp"

class Random
{
public:
	Random();
	void Randomize(Game &);
};
#endif // RANDOM_HPP
