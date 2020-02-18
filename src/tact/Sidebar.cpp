//
// Created by michael on 2/7/20.
//

#include "../../include/tact/Sidebar.h"

Sidebar::Sidebar(std::string filename){
    if(!this->background.loadFromFile(filename, sf::IntRect(0, 0, 256, 704))) {
        std::cout << "Could not open: " + filename << std::endl;
    }
    sidebar.setTexture(background);
    sidebar.setPosition(1024,0);
}

void Sidebar::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // apply the transform
    states.transform *= getTransform();
    // apply the tileset texture
    states.texture = &background;
    // draw the vertex array
    target.draw(sidebar, states);
}

void Sidebar::createStat(float const width, float const height, std::string filename) {
	if(!font.loadFromFile(filename)) {
		std::cout << "Could not open: " + filename << std::endl;
	}
	
	std::string stat_name[MAX_NUM_STAT_ITEMS] = {"- P1 Turn -", "LV", "EXP", "HP", "MP", "ATK", "DEF", "SPD", "S.ATK", "S.DEF"};

	for(int i = 0; i < MAX_NUM_STAT_ITEMS; i++) {
		stat[i].setFont(font);
		stat[i].setFillColor(sf::Color::White);
		stat[i].setOutlineColor(sf::Color::Red);
		stat[i].setString(stat_name[i]);
		stat[i].setCharacterSize(12);
		if(i == 0) {
            int pw = 1024 + 256 / 2 - stat[i].getLocalBounds().width / 2;
            stat[i].setPosition(sf::Vector2f(pw, 10));
        }
		else if ( i != 0 && i < 5) {
            int pw = 1160;
            stat[i].setPosition(sf::Vector2f(pw, i * 32));
        }
		else if( i >= 5 && i < 8 ){
		    int pw = 1046;
            stat[i].setPosition(sf::Vector2f(pw, i * 32));
        }
		else {
            int pw = 1160;
            stat[i].setPosition(sf::Vector2f(pw, (i-3) * 32));

        }
	}
}

void Sidebar::drawStat(sf::RenderTarget &window) {
	for(int i =0; i < MAX_NUM_STAT_ITEMS; i++)
		window.draw(stat[i]);
}

void Sidebar::setStats(Character &c1, float const width, float const height, std::string filename) {
	if(!font.loadFromFile(filename)) {
		std::cout << "Could not open: " + filename << std::endl;
	}
	for(int i = 0; i < MAX_NUM_STAT_ITEMS-1; i++) {
		stats[i].setFont(font);
		stats[i].setFillColor(sf::Color::Black);
		stats[i].setOutlineColor(sf::Color::Yellow);
		stats[i].setCharacterSize(12);
		if (i < 5) {
            int pw = 1240;
            stats[i].setPosition(sf::Vector2f(pw, (i+1) * 32));
        }
		else if( i >= 5 && i < 8 ){
		    int pw = 1126;
            stats[i].setPosition(sf::Vector2f(pw, (i) * 32));
        }
		else {
            int pw = 1240;
            stats[i].setPosition(sf::Vector2f(pw, (i-2) * 32));
        }
		std::stringstream ss;
		if (i == 0) ss << c1.get_level();
		else if (i == 1) ss << c1.get_experience();
		else if (i == 2) ss << c1.get_hit_points();
		else if (i == 3) ss << c1.get_mana_points();
		else if (i == 4) ss << c1.get_attack();
		else if (i == 5) ss << c1.get_defense();
		else if (i == 6) ss << c1.get_speed();
		else if (i == 7) ss << c1.get_special_attack();
		else if (i == 8) ss << c1.get_special_defense();
		stats[i].setString(ss.str());
	}
}

void Sidebar::drawStats(sf::RenderTarget &window) {
	for(int i =0; i < MAX_NUM_STAT_ITEMS-1; i++)
		window.draw(stats[i]);
}