#include "Random.hpp"

Random::Random()
{
  srand(time(NULL));
}

void Random::Randomize(Game & ag)
{
  ag.GetEmptyPiece();
  int rnd_buf = rand() % 4;
    if(rnd_buf == 0) {
      if (ag.emptyPieceI_ != 3) {
	ag.Swap(ag.myMap_[ag.emptyPieceI_+1][ag.emptyPieceJ_]);
      }
    } else if(rnd_buf == 1) {
      if (ag.emptyPieceI_ != 0) {
	ag.Swap(ag.myMap_[ag.emptyPieceI_-1][ag.emptyPieceJ_]);
      }
    } else if(rnd_buf == 2) {
      if (ag.emptyPieceJ_ != 3) {
	ag.Swap(ag.myMap_[ag.emptyPieceI_][ag.emptyPieceJ_+1]);
      }
    } else if(rnd_buf == 3)	{
      if (ag.emptyPieceJ_ != 0) {
	ag.Swap(ag.myMap_[ag.emptyPieceI_][ag.emptyPieceJ_-1]);
      }
    }
}
