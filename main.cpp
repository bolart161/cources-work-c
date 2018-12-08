#include <iostream>
#include <vector>
#include "Game.hpp"
#include "Drawer.hpp"
#include "Random.hpp"

int main()
{
    Game g;
    Drawer d;
    Random r;
    for (int i = 0; i < 500; i++)
    {
      r.Randomize(g);
    }
    d.DrawField(g);
    return 0;
}
