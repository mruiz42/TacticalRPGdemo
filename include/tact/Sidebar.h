//
// Created by michael on 2/7/20.
//

#ifndef CIS29GROUP2GAME_SIDEBAR_H
#define CIS29GROUP2GAME_SIDEBAR_H
#define MAX_NUM_STAT_ITEMS 3
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

class Sidebar : public sf::Drawable, public sf::Transformable {
private:
    sf::Texture background;
    sf::Sprite sidebar;
	
	sf::Font font;
	sf::Text stat[MAX_NUM_STAT_ITEMS];
	
	
public:
    Sidebar(std::string);
    sf::Texture getBackground() const { return this->background; }
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void createStat(float const width, float const height, std::string filename);
	void drawStat(sf::RenderTarget &window);
	
};


#endif //CIS29GROUP2GAME_SIDEBAR_H
