//
// Created by michael on 2/7/20.
//

#include <thread>
#include <chrono>
#include "../../include/tact/Sidebar.h"

using namespace tact;

Sidebar::Sidebar(std::string texture_filename, std::string font_filename, std::string battle_Log_font_filename) : menu(font_filename) {
    if(!this->background.loadFromFile(texture_filename, sf::IntRect(0, 0, 256, 704)))
        std::cout << "Could not open: " + texture_filename << std::endl;
    if(!font.loadFromFile(font_filename))
        std::cout << "Could not open: " + font_filename << std::endl;
	if(!battle_Log_font.loadFromFile(battle_Log_font_filename))
        std::cout << "Could not open: " + battle_Log_font_filename << std::endl;
    sidebar.setTexture(background);
    sidebar.setPosition(1024,0);
    text.resize(13);
	
    for(int i = 0; i < text.size(); i++) {
		text[i].setFont(font);
		text[i].setFillColor(sf::Color::White);
		text[i].setCharacterSize(12);
		if(i == 0) {
		    text[i].setString("Player_ turn");
            int pw = 1024 + 224 / 2 - text[i].getLocalBounds().width / 2;
            text[i].setPosition(sf::Vector2f(pw, 10));
        }
		else if ( i != 0 && i < 6) {
            int pw = 1160;
            text[i].setPosition(sf::Vector2f(pw, i * 32));
        }
		else if( i >= 6 && i < 9 ){
		    int pw = 1046;
            text[i].setPosition(sf::Vector2f(pw, i * 32));
        }
		else if (i >=9 && i < 11){
            int pw = 1160;
            text[i].setPosition(sf::Vector2f(pw, (i - 3) * 32));
        }
        else if (i == 11) {
            int pw = 1046;
            int py = 674;
            text[i].setPosition(sf::Vector2f(pw, py));
        }
        else {
            int pw = 1160;
            int py = 674;
            text[i].setPosition(sf::Vector2f(pw, py));
        }
    }
	battle_Log.resize(8);
	for(int i = 0; i < battle_Log.size(); i++) {
		battle_Log[i].setFont(battle_Log_font);
		battle_Log[i].setFillColor(sf::Color::Black);
		battle_Log[i].setCharacterSize(15);
		int pw = 1040;
		battle_Log[i].setPosition(sf::Vector2f(pw, (i + 11) * 26));
    }
}
void Sidebar::set_Turn(std::string turn){
    this->text[0].setString(turn);
}

void Sidebar::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // apply the transform
    states.transform *= getTransform();
    // apply the tileset texture
    states.texture = &background;
    // draw the vertex array
    target.draw(sidebar, states);
}

void Sidebar::update_sidebar(Coordinate coordinate, int turn, int player_id) {
    text[0].setString("Player" + std::to_string(player_id + 1));
    text[11].setString("TURN." + std::to_string(turn));
    text[12].setString("(" + std::to_string(coordinate.get_x()) + "," + std::to_string(coordinate.get_y()) + ")");
}

void Sidebar::update_battle_Log(std::string newlog) {
	int pw = 1040;
	std::cout << "BL Update" <<  battle_Log.size() << std::endl;
	battle_Log.push_back(battle_Log.front());
	battle_Log.pop_front();
	for(int i = 0; i < battle_Log.size(); i++) {
		pw = 1040;
		battle_Log[i].setPosition(sf::Vector2f(pw, (i + 11) * 26));
    }
	battle_Log.back().setString(newlog);
}

void Sidebar::update_battle_Log(std::string newlog, sf::Color color) {
    std::cout << "BL Update" <<  battle_Log.size() << std::endl;
    int pw = 1040;
    battle_Log.push_back(battle_Log.front());
    battle_Log.pop_front();
    auto it = battle_Log.end() - 1;
    it->setFillColor(color);
    for(int i = 0; i < battle_Log.size(); i++) {
        pw = 1040;
        battle_Log[i].setPosition(sf::Vector2f(pw, (i + 11) * 26));
    }
    battle_Log.back().setString(newlog);
}


void Sidebar::update_statbar(Character* character, Coordinate coordinate, int turn, int player_id) {
        text[0].setString("Player" + std::to_string(player_id + 1));
        text[1].setString(character->get_name());
        text[2].setString("LV." + std::to_string(character->get_level()));
        text[3].setString("EXP." + std::to_string(character->get_experience()));
        text[4].setString("HP." + std::to_string(character->get_hit_points()));
        text[5].setString("MP." + std::to_string(character->get_mana_points()));
        text[6].setString("ATK." + std::to_string(character->get_attack()));
        text[7].setString("DEF." + std::to_string(character->get_defense()));
        text[8].setString("SPD." + std::to_string(character->get_speed()));
        text[9].setString("S.ATK." + std::to_string(character->get_special_attack()));
        text[10].setString("S.DEF." + std::to_string(character->get_special_defense()));
        text[11].setString("TURN." + std::to_string(turn));
        text[12].setString("(" + std::to_string(coordinate.get_x()) + "," + std::to_string(coordinate.get_y()) + ")");
		if(player_id == 0){
			character_Face = character->get_character_Face1();
			character_Face.setPosition(sf::Vector2f(1046, 35));
			character_Face.scale(sf::Vector2f(1.5, 1.5));
		}
		else {
			character_Face = character->get_character_Face2();
			character_Face.setPosition(sf::Vector2f(1046, 35));
			character_Face.scale(sf::Vector2f(1.5, 1.5));
		}
}


void Sidebar::create_Stat(float const width, float const height, std::string filename) {
	if(!font.loadFromFile(filename)) {
		std::cout << "Could not open: " + filename << std::endl;
	}
}

void Sidebar::clear() {
    for (auto i = 1; i < text.size() - 2; i++){
        text[i].setString("");
    }
	sf::Sprite newCF;
	character_Face = newCF;
}

void Sidebar::draw_Stat(sf::RenderTarget &window) {
	for(int i =0; i < text.size(); i++)
		window.draw(text[i]);
	window.draw(character_Face);
}

void Sidebar::draw_Battle_Log(sf::RenderTarget &window) {
	//std::cout << "BL draw" << std::endl;
	for(int i =0; i < battle_Log.size(); i++) {
		window.draw(battle_Log[i]);
		std::string thisS = battle_Log[i].getString();
	}
	//std::this_thread::sleep_for(std::chrono::milliseconds(200));
}