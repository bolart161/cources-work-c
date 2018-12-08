#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <iostream>
#include <random>       /* time */
#include "Game.hpp"

class Random
{
public:
	Random();
	void Randomize(Game &);
};
#endif
