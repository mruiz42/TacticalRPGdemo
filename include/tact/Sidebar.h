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
#include "./Character.h"

const int MAX_NUM_STAT_ITEMS = 10;

class Sidebar : public sf::Drawable, public sf::Transformable {
private:
    sf::Texture background;
    sf::Sprite sidebar;

	sf::Font font;
	sf::Text stat[MAX_NUM_STAT_ITEMS];
	sf::Text stats[MAX_NUM_STAT_ITEMS-1];


public:
    Sidebar(std::string);
    sf::Texture getBackground() const { return this->background; }
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void createStat(float const width, float const height, std::string filename);
	void drawStat(sf::RenderTarget &window);

	void setStats(Character &c1, float const width, float const height, std::string filename);
	void drawStats(sf::RenderTarget &window);

};


#endif //CIS29GROUP2GAME_SIDEBAR_H
