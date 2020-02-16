//
// Created by michael on 2/7/20.
//

#include "../../include/tact/Sidebar.h"


Sidebar::Sidebar(std::string filename){
    if(!this->background.loadFromFile(filename, sf::IntRect(0,0,256,704))) {
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
	if(font.loadFromFile(filename)) {
		std::cout << "Could not open: " + filename << std::endl;
	}
	
	std::string stat_name[MAX_NUM_STAT_ITEMS] = {"Player Red", "HP", "MP"};
	int wordHeight = 40;
	
	for(int i = 0; i < MAX_NUM_STAT_ITEMS; i++) {
		int pw = 1024 + 20 - stat[i].getLocalBounds().width/2;
		
		stat[i].setFont(font);
		stat[i].setFillColor(sf::Color::Red);
		stat[i].setString(stat_name[i]);
		stat[i].setCharacterSize(32);
		stat[i].setPosition(sf::Vector2f(pw, height/4 + i * wordHeight));
	}
}

void Sidebar::drawStat(sf::RenderTarget &window) {
	for(int i =0; i < MAX_NUM_STAT_ITEMS; i++)
		window.draw(stat[i]);
}