//
// Created by michael on 3/10/20.
//

#ifndef CIS29GROUP2GAME_SPEAKER_H
#define CIS29GROUP2GAME_SPEAKER_H
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <string>

const std::string menu_voice_path = "";
const std::string cursor_voice_path = "";

class Speaker {
private:
    sf::SoundBuffer buffer;
    sf::Sound menu_voice;
    sf::Sound cursor_voice;
public:
    Speaker();
    void play_menu_voice();
    void play_cursor_voice();
};


#endif //CIS29GROUP2GAME_SPEAKER_H
