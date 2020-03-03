//
// Created by michael on 2/7/20.
//

#include "../../include/tact/Sidebar.h"
#include <thread>
#include <chrono>

/*	sf::Text turn;
    sf::Text lv;
    sf::Text exp;
    sf::Text mp;
    sf::Text atk;
    sf::Text def;
    sf::Text spd;
    sf::Text satk;
    sf::Text sdef;
	sf::Text hp;*/
Sidebar::Sidebar(std::string texture_filename, std::string font_filename, std::string battleLog_font_filename) : menu(font_filename) {
    if(!this->background.loadFromFile(texture_filename, sf::IntRect(0, 0, 256, 704)))
        std::cout << "Could not open: " + texture_filename << std::endl;
    if(!font.loadFromFile(font_filename))
        std::cout << "Could not open: " + font_filename << std::endl;
	if(!battleLog_font.loadFromFile(battleLog_font_filename))
        std::cout << "Could not open: " + battleLog_font_filename << std::endl;
    sidebar.setTexture(background);
    sidebar.setPosition(1024,0);
    text.resize(13);
	
    for(int i = 0; i < text.size(); i++) {
		text[i].setFont(font);
		text[i].setFillColor(sf::Color::White);
		text[i].setCharacterSize(12);
		if(i == 0) {
		    text[i].setString("Player_ turn");
            int pw = 1024 + 174 / 2 - text[i].getLocalBounds().width / 2;
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
	battleLog.resize(8);
	for(int i = 0; i < battleLog.size(); i++) {
		battleLog[i].setFont(battleLog_font);
		battleLog[i].setFillColor(sf::Color::White);
		battleLog[i].setCharacterSize(15);
		int pw = 1040;
		battleLog[i].setPosition(sf::Vector2f(pw, (i + 11) * 26));
    }
}
void Sidebar::setTurn(std::string turn){
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
    text[0].setString("Player" + std::to_string(player_id + 1) +" turn");
    text[11].setString("TURN." + std::to_string(turn));
    text[12].setString("(" + std::to_string(coordinate.get_x()) + "," + std::to_string(coordinate.get_y()) + ")");
}

void Sidebar::update_battleLog(std::string newlog) {
	std::cout << "BL Update" <<  battleLog.size() << std::endl;
	battleLog.push_back(battleLog.front());
	battleLog.pop_front();
	for(int i = 0; i < battleLog.size(); i++) {
		int pw = 1040;
		battleLog[i].setPosition(sf::Vector2f(pw, (i + 11) * 26));
    }
	battleLog.back().setString(newlog);
}

void Sidebar::update_statbar(Character* character, Coordinate coordinate, int turn, int player_id) {
        text[0].setString("Player" + std::to_string(player_id + 1) +" turn");
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
		if(player_id == 0)
		{
			charFace = character->get_charFace1();
			charFace.setPosition(sf::Vector2f(1046, 35));
			charFace.scale(sf::Vector2f(1.5, 1.5));
		}
		else
		{
			charFace = character->get_charFace2();
			charFace.setPosition(sf::Vector2f(1046, 35));
			charFace.scale(sf::Vector2f(1.5, 1.5));
		}
}

void Sidebar::createStat(float const width, float const height, std::string filename) {
	if(!font.loadFromFile(filename)) {
		std::cout << "Could not open: " + filename << std::endl;
	}

//	std::string stat_name[MAX_NUM_STAT_ITEMS] = {"- P1 Turn -", "LV", "EXP", "HP", "MP", "ATK", "DEF", "SPD", "S.ATK", "S.DEF"};

//	for(int i = 0; i < MAX_NUM_STAT_ITEMS; i++) {
//		stat[i].setFont(font);
//		stat[i].setFillColor(sf::Color::White);
//		stat[i].setOutlineColor(sf::Color::Red);
//		stat[i].setString(stat_name[i]);
//		stat[i].setCharacterSize(12);
//		if(i == 0) {
//            int pw = 1024 + 256 / 2 - stat[i].getLocalBounds().width / 2;
//            stat[i].setPosition(sf::Vector2f(pw, 10));
//        }
//		else if ( i != 0 && i < 5) {
//            int pw = 1160;
//            stat[i].setPosition(sf::Vector2f(pw, i * 32));
//        }
//		else if( i >= 5 && i < 8 ){
//		    int pw = 1046;
//            stat[i].setPosition(sf::Vector2f(pw, i * 32));
//        }
//		else {
//            int pw = 1160;
//            stat[i].setPosition(sf::Vector2f(pw, (i-3) * 32));
//
//        }
//	}
}
void Sidebar::clear() {
    for (auto i = 1; i < text.size() - 2; i++){
        text[i].setString("");
    }
	sf::Sprite newCF;
	charFace = newCF;
}

void Sidebar::drawStat(sf::RenderTarget &window) {
	for(int i =0; i < text.size(); i++)
		window.draw(text[i]);
	window.draw(charFace);
}

void Sidebar::drawBattleLog(sf::RenderTarget &window) {
	//std::cout << "BL draw" << std::endl;
	for(int i =0; i < battleLog.size(); i++) {
		window.draw(battleLog[i]);
		std::string thisS = battleLog[i].getString();
		std::cout << "drawing " << thisS  << std::endl;
	}
	//std::this_thread::sleep_for(std::chrono::milliseconds(200));
}
//void Sidebar::hp_raise(int &HP, int const HP_MAX, int const HP_RAISE, float const width, float const height, std::string filename, sf::RenderTarget &window) {
//	if(!font.loadFromFile(filename)) {
//		std::cout << "Could not open: " + filename << std::endl;
//	}
//
//	int pw = 1024 + 20 - 1024/2 + 30;
//	HPtext.setFont(font);
//	HPtext.setFillColor(sf::Color::Black);
//	HPtext.setOutlineColor(sf::Color::Yellow);
//	HPtext.setCharacterSize(32);
//	HPtext.setPosition(sf::Vector2f(pw, height/4 + 3 * 40));
//	std::stringstream ss;
//
//	for(int i = 0; i <= HP_RAISE && HP <= HP_MAX; i++, HP++) {
//		ss << HP;
//		HPtext.setString(ss.str());
//		window.draw(HPtext);
//		std::cout << "HP" << HP << std::endl;
//	}
//}