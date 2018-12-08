#include "Drawer.hpp"

Drawer::Drawer()
{
  for (int i = 0; i < 16; i++) {
    sf::Texture texture;
    texture.loadFromFile("sprites/" + std::to_string(i) + ".png");
    pieceTextures_.push_back(texture);
  }
  isOverGame_ = false;
}

void Drawer::DrawField(Game& ag)
{
  sf::RenderWindow window(sf::VideoMode(400, 400), "15");
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
 	window.close();
      }

      if (event.type == sf::Event::KeyPressed) {
	ag.GetEmptyPiece();
	if (event.key.code == sf::Keyboard::Left && ag.emptyPieceJ_ != 3) {
          ag.Swap(ag.myMap_[ag.emptyPieceI_][ag.emptyPieceJ_+1]);
	} else if (event.key.code == sf::Keyboard::Right && ag.emptyPieceJ_ != 0) {
	  ag.Swap(ag.myMap_[ag.emptyPieceI_][ag.emptyPieceJ_-1]);
	} else if (event.key.code == sf::Keyboard::Up && ag.emptyPieceI_ != 3) {
	  ag.Swap(ag.myMap_[ag.emptyPieceI_+1][ag.emptyPieceJ_]);
	} else if (event.key.code == sf::Keyboard::Down && ag.emptyPieceI_ != 0) {
	  ag.Swap(ag.myMap_[ag.emptyPieceI_-1][ag.emptyPieceJ_]);
	}
      }
    }

    isOverGame_ = true;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if ((ag.myMap_[i][j].num_ != (i*4) + j + 1) && (((i * 4) + j + 1) != 16))   {
	  isOverGame_ = false;
	}
      }
    }
    if (isOverGame_) {
      sf::Text text;
      sf::Font font;
      if (!font.loadFromFile("fonts/OpenSans-Bold.ttf")){
        std::cout << "Fonts not founded!";
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
      sleep(time);
      window.close();
    } else {
      sf::Sprite temp;
      window.clear();
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
