//
// Created by michael on 2/7/20.
//

#ifndef CIS29GROUP2GAME_SIDEBAR_H
#define CIS29GROUP2GAME_SIDEBAR_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>

const int MAX_NUM_STAT_ITEMS = 10;
const int WORDHEIGHT = 40;

class Sidebar : public sf::Drawable, public sf::Transformable {
private:
    sf::Texture background;
    sf::Sprite sidebar;
	
	sf::Font font;
	sf::Text stat[MAX_NUM_STAT_ITEMS];
	sf::Text HPtext;
	
	
public:
    Sidebar(std::string);
    sf::Texture getBackground() const { return this->background; }
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	void createStat(float const width, float const height, std::string filename);
	void drawStat(sf::RenderTarget &window);

	void hp_raise(int &HP, int const HP_MAX, int const HP_RAISE, float const width, float const height, std::string filename, sf::RenderTarget &window);
	
};


#endif //CIS29GROUP2GAME_SIDEBAR_H
