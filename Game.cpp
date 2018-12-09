#include "Game.hpp"

Game::Game()
{
  // Set map for start game
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if ((i*4 + j) != 15){
        Piece buffer(1,1,(i * 4) + j + 1);
        myMap_[i][j] = buffer;
      } else {
        Piece buffer(1,1,0);
	      myMap_[i][j] = buffer;
      }
    }
  }
  // Give coordinates
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
  	myMap_[i][j].posX_ = j * 100;
  	myMap_[i][j].posY_ = i * 100;
    }
  }
}

// Get Piece with number = 0
void Game::GetEmptyPiece()
{
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if(myMap_[i][j].num_ == 0) {
      	emptyPieceI_ = i;
      	emptyPieceJ_ = j;
      	break;
      }
    }
  }
}

// Swap piece with number 0,  with piece, which needed
void Game::Swap(Piece & toBeSwaped)
{
  Piece buffer(0,0,0);
  buffer.num_ = toBeSwaped.num_;
  toBeSwaped.num_ = myMap_[emptyPieceI_][emptyPieceJ_].num_;
  myMap_[emptyPieceI_][emptyPieceJ_].num_ = buffer.num_;
}
