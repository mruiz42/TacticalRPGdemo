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
#include "Menu.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
namespace tact {
    class Sidebar;
}
class tact::Sidebar : public sf::Drawable, public sf::Transformable {
private:
    sf::Texture background;
    sf::Sprite sidebar;
	sf::Font font;
	sf::Font battleLog_font;
	sf::Text turn;
	std::deque<sf::Text> battleLog;
	std::vector<sf::Text> text;
	//sf::Text HPtext;
    Menu menu;
	sf::Sprite charFace;
public:
    Sidebar(std::string, std::string, std::string);
    sf::Texture getBackground() const { return this->background; }
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void createStat(float const width, float const height, std::string filename);
	void update_statbar(Character*, Coordinate, int, int);
	void update_battleLog(std::string newlog);
    void update_sidebar(Coordinate, int, int);
    void drawStat(sf::RenderTarget &window);
	void drawBattleLog(sf::RenderTarget &window);
    void setTurn(std::string);
    void clear();

    Menu& get_menu() { return this->menu; }

	void update_battleLog(std::string newlog, sf::Color color);
};
#endif //CIS29GROUP2GAME_SIDEBAR_H
