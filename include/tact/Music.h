//
// Created by lychee on 2/18/20.
//

#ifndef CIS29GROUP2GAME_MUSIC_H
#define CIS29GROUP2GAME_MUSIC_H

#include <SFML/Audio/Music.hpp>
#include <string>

class Music {
private:
	std::string filename;
	sf::Music music; /// to stream music directly from file
public:
    Music();
    Music(std::string a);
	std::string name() const;
	void raiseVolume();
	void lowerVolume();
	void stop();
};


#endif 
