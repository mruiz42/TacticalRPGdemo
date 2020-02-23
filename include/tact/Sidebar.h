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
#include "Character.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include <vector>

class Sidebar : public sf::Drawable, public sf::Transformable {
private:
    sf::Texture background;
    sf::Sprite sidebar;
	sf::Font font;
	sf::Text turn;
	std::vector<sf::Text> text;
	sf::Sprite charFace;
	//sf::Text HPtext;
public:
    Sidebar(std::string, std::string);
    sf::Texture getBackground() const { return this->background; }
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void createStat(float const width, float const height, std::string filename);
	void update_statbar(Character*, Coordinate, int, int);
    void update_sidebar(Coordinate, int, int);
    void drawStat(sf::RenderTarget &window);
    void setTurn(std::string);
    void clear();
	void hp_raise(int &HP, int const HP_MAX, int const HP_RAISE, float const width, float const height, std::string filename, sf::RenderTarget &window);

};
#endif //CIS29GROUP2GAME_SIDEBAR_H
