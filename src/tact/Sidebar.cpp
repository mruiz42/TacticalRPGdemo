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

void Sidebar::hp_raise(int &HP, int const HP_MAX, int const HP_RAISE, float const width, float const height, std::string filename, sf::RenderTarget &window) {
	if(!font.loadFromFile(filename)) {
		std::cout << "Could not open: " + filename << std::endl;
	}
	
	int pw = 1024 + 20 - 1024/2 + 30;
	HPtext.setFont(font);
	HPtext.setFillColor(sf::Color::Black);
	HPtext.setOutlineColor(sf::Color::Yellow);
	HPtext.setCharacterSize(32);
	HPtext.setPosition(sf::Vector2f(pw, height/4 + 3 * 40));
	std::stringstream ss;

	for(int i = 0; i <= HP_RAISE && HP <= HP_MAX; i++, HP++) {
		ss << HP;
		HPtext.setString(ss.str());
		window.draw(HPtext);
		std::cout << "HP" << HP << std::endl;
	}
}