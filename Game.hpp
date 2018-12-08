#ifndef GAME_HPP
#define GAME_HPP

#include "Piece.hpp"

class Game
{
public:
	Game();
	void GetEmptyPiece();
	void Swap(Piece &);

	Piece myMap_[4][4];
	int emptyPieceJ_;
	int emptyPieceI_;
};
#endif
