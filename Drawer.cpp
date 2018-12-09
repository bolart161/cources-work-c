#include "Drawer.hpp"

const int WINDOW_WIDTH = 400,
          WINDOW_HEIGHT = 400;
const char* NAME_OF_GAME = "15";

// Class for drawing maps and cells
Drawer::Drawer()
{
  // Set textures for cells
  for (int i = 0; i < 16; i++) {
    sf::Texture texture;
    texture.loadFromFile("sprites/" + std::to_string(i) + ".png");
    pieceTextures_.push_back(texture);
  }
  // Set status of the game
  isOverGame_ = false;
}
// Methods drawing game process
void Drawer::DrawField(Game & ag)
{
  sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), NAME_OF_GAME);
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
      // Handler press keyboard event
      if (event.type == sf::Event::KeyPressed) {
        ag.GetEmptyPiece();
        if (event.key.code == sf::Keyboard::Left && ag.emptyPieceJ_ != 3) {  // Left
          ag.Swap(ag.myMap_[ag.emptyPieceI_][ag.emptyPieceJ_+1]);
        } else if (event.key.code == sf::Keyboard::Right && ag.emptyPieceJ_ != 0) { // Right
          ag.Swap(ag.myMap_[ag.emptyPieceI_][ag.emptyPieceJ_-1]);
        } else if (event.key.code == sf::Keyboard::Up && ag.emptyPieceI_ != 3) { // Up
          ag.Swap(ag.myMap_[ag.emptyPieceI_+1][ag.emptyPieceJ_]);
        } else if (event.key.code == sf::Keyboard::Down && ag.emptyPieceI_ != 0) { // Down
          ag.Swap(ag.myMap_[ag.emptyPieceI_-1][ag.emptyPieceJ_]);
        }
      }
    }
    // Check Over Game
    isOverGame_ = true;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if ((ag.myMap_[i][j].num_ != (i*4) + j + 1) && (((i * 4) + j + 1) != 16))   {
          isOverGame_ = false;
        }
      }
    }
    if (isOverGame_) {
      // Create text
      sf::Text text;
      sf::Font font;
      if (!font.loadFromFile("fonts/OpenSans-Bold.ttf")){
        std::cout << "Fonts not founded!";
        window.close();
      }
      text.setFont(font);
      text.setString(std::string("Winner!!!"));
      text.setCharacterSize(32);
      text.setFillColor(sf::Color::Red);
      text.setStyle(sf::Text::Bold);
      text.setPosition(160, 160);
      window.clear();
      window.draw(text);
      window.display();
      sf::Time time = sf::seconds(1);
      sleep(time); // Delay for display text
      window.close();
    } else {
      sf::Sprite temp;
      window.clear();
      // Drawing map
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          temp.setTexture(pieceTextures_[ag.myMap_[i][j].num_]);
          temp.setPosition(ag.myMap_[i][j].posX_, ag.myMap_[i][j].posY_);
	        window.draw(temp);
        }
      }
      window.display();
    }
  }
}
