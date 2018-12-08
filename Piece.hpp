#ifndef PIECE_HPP
#define PIECE_HPP

class Piece
{
public:
	Piece(int x, int y, int posX, int posY, int num);
	Piece();
	void GetSize(int field_x, int field_y);

	int x_, y_, posX_, posY_, sizeX_, sizeY_, num_;
};

#endif
