#include "Game.hpp"

Game::Game()
{
  // Заполнение карты
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if ((i*4 + j) != 15){    
        Piece buffer(1,1,1,1,(i * 4) + j + 1);
        myMap_[i][j] = buffer;
      } else {
        Piece buffer(1,1,1,1,0);
	myMap_[i][j] = buffer;
      }
    }
  }
  //Give coordinates
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
	myMap_[i][j].posX_ = j * 100;
	myMap_[i][j].posY_ = i * 100;
    }
  }
}

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

void Game::Swap(Piece & toBeSwaped) // Pass pointer on piece we want to move
{
  Piece buffer(0,0,0,0,0);
  buffer.num_ = toBeSwaped.num_;
  toBeSwaped.num_ = myMap_[emptyPieceI_][emptyPieceJ_].num_;
  myMap_[emptyPieceI_][emptyPieceJ_].num_ = buffer.num_;
}
