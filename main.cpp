#include <iostream>
#include <vector>
#include "Game.hpp"
#include "Drawer.hpp"
#include "Random.hpp"

int main()
{
    Game g; // Create Game
    Drawer d; // Create Drawer
    Random r; // Create Random
    // Swopped pieces 500 times for start game
    for (int i = 0; i < 500; i++)
    {
      r.Randomize(g);
    }
    // Draw map and start game
    d.DrawField(g);
    return 0;
}
