//
// Created by lychee on 2/18/20.
//

#ifndef CIS29GROUP2GAME_SOUND_H
#define CIS29GROUP2GAME_SOUND_H

#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <string>

class Sound {
private:
	std::string filename;
	sf::SoundBuffer buffer; // add sound effect (pre-load small audio file to memory for fast response)
	sf::Sound sound;
public:
    Sound();
    Sound(std::string a);
	std::string name() const;
	void raiseVolume();
	void lowerVolume();

};


#endif 
