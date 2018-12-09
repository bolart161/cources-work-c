#include "Random.hpp"

// Generate random with dependence of the time
Random::Random()
{
  srand(time(NULL));
}

void Random::Randomize(Game & ag)
{
  ag.GetEmptyPiece();
  // Generate digit (0 to 3) for swap (0-Left, 1-Right, 2-Up, 3-Down)
  int rnd_buf = rand() % 4;
    if (rnd_buf == 0) {
      if (ag.emptyPieceJ_ != 3) {
        ag.Swap(ag.myMap_[ag.emptyPieceI_][ag.emptyPieceJ_+1]);
      }
    } else if(rnd_buf == 1)	{
      if (ag.emptyPieceJ_ != 0) {
        ag.Swap(ag.myMap_[ag.emptyPieceI_][ag.emptyPieceJ_-1]);
      }
    } else if (rnd_buf == 2) {
      if (ag.emptyPieceI_ != 3) {
      	ag.Swap(ag.myMap_[ag.emptyPieceI_+1][ag.emptyPieceJ_]);
      }
    } else if(rnd_buf == 3) {
      if (ag.emptyPieceI_ != 0) {
      	ag.Swap(ag.myMap_[ag.emptyPieceI_-1][ag.emptyPieceJ_]);
      }
    }
}
