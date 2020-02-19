//
// Created by lychee on 2/18/20.
//

#include "../../include/tact/Sound.h"
#include <iostream>

std::string Sound::name() const
{
    std::string classname = typeid(*this).name();
    classname = classname.substr(classname.find_first_not_of("0123456789"));
    return classname;
}

Sound::Sound(std::string a){
	filename = a;
	if(!buffer.loadFromFile(filename)){
		std::cout << "Error: " << this->name() << std::endl;
		exit(-1);
	}
	sound.setBuffer(buffer);
	sound.setVolume(50);
}

void Sound::raiseVolume(){
	sound.setVolume(sound.getVolume() + 10); /// range 0 - 100
	if (sound.getVolume() >= 100){
		sound.setVolume(100);
		///changeVolSoundEffect.setVolume(100);
	}
	sound.play();
}

void Sound::lowerVolume(){
	sound.setVolume(sound.getVolume() - 10); /// range 0 - 100
	if (sound.getVolume() <= 0){
		sound.setVolume(0);
	}
	sound.play();
}