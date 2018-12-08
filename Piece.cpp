#include "Piece.hpp"
Piece::Piece(int x, int y, int pos_x, int pos_y, int num)
{
	this->x_ = x;
	this->y_ = y;
	this->posX_ = pos_x;
	this->posY_ = pos_y;
	this->num_ = num;
}

Piece::Piece()
{
}
