//
// Created by michael on 2/7/20.
//

#include "../../include/tact/Sidebar.h"
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
Sidebar::Sidebar(std::string texture_filename, std::string font_filename){
    if(!this->background.loadFromFile(texture_filename, sf::IntRect(0, 0, 256, 704)))
        std::cout << "Could not open: " + texture_filename << std::endl;
    if(!font.loadFromFile(font_filename))
        std::cout << "Could not open: " + font_filename << std::endl;
    sidebar.setTexture(background);
    sidebar.setPosition(1024,0);
    text.resize(10);
    for(int i = 0; i < text.size(); i++) {
		text[i].setFont(font);
		text[i].setFillColor(sf::Color::White);
		text[i].setCharacterSize(12);
		if(i == 0) {
		    text[i].setString("Player_ turn");
            int pw = 1024 + 168 / 2 - text[i].getLocalBounds().width / 2;
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
		else {
            int pw = 1160;
            text[i].setPosition(sf::Vector2f(pw, (i - 3) * 32));

        }
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
void Sidebar::update_statbar(Character* character){
        text[1].setString("LV." + std::to_string(character->get_level()));
        text[2].setString("EXP." + std::to_string(character->get_experience()));
        text[3].setString("HP." + std::to_string(character->get_hit_points()));
        text[4].setString("MP." + std::to_string(character->get_mana_points()));
        text[5].setString("ATK." + std::to_string(character->get_attack()));
        text[6].setString("DEF." + std::to_string(character->get_defense()));
        text[7].setString("SPD." + std::to_string(character->get_speed()));
        text[8].setString("S.ATK." + std::to_string(character->get_special_attack()));
        text[9].setString("S.DEF." + std::to_string(character->get_special_defense()));
}
//void Sidebar::setTurn(std::string turn){
//    this->turn.setString(turn);
//}
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
    for (auto i = 0; i < text.size(); i++){
        text[i].setString("");
    }
}
void Sidebar::drawStat(sf::RenderTarget &window) {
	for(int i =0; i < text.size(); i++)
		window.draw(text[i]);
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