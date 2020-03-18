//
// Created by michael on 2/7/20.
//

#ifndef CIS29GROUP2GAME_SIDEBAR_H
#define CIS29GROUP2GAME_SIDEBAR_H

#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <iostream>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Menu.h"

namespace tact {
    class Sidebar;
}

class tact::Sidebar : public sf::Drawable, public sf::Transformable {
private:
    sf::Texture background;
    sf::Sprite sidebar;
	sf::Font font;
	sf::Font battle_Log_font;
	sf::Text turn;
	std::deque<sf::Text> battle_Log;
	std::vector<sf::Text> text;
	//sf::Text HPtext;
    Menu menu;
	sf::Sprite character_Face;
public:
    Sidebar(std::string, std::string, std::string);
    sf::Texture get_Background() const { return this->background; }
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void create_Stat(float const width, float const height, std::string filename);
	void update_statbar(Character*, Coordinate, int, int);
	void update_battle_Log(std::string newlog);
    void update_sidebar(Coordinate, int, int);
    void draw_Stat(sf::RenderTarget &window);
	void draw_Battle_Log(sf::RenderTarget &window);
    void set_Turn(std::string);
    void clear();

    Menu& get_menu() { return this->menu; }

	void update_battle_Log(std::string newlog, sf::Color color);
};
#endif //CIS29GROUP2GAME_SIDEBAR_H
