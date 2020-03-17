#include "../include/Music.h"
#include <iostream>

std::string Music::name() const
{
    std::string classname = typeid(*this).name();
    classname = classname.substr(classname.find_first_not_of("0123456789"));
    return classname;
}

Music::Music(std::string a){
	filename = a;
	if(!music.openFromFile(filename)){
		std::cout << "Error: " << this->name() << std::endl;
		exit(-1);
	}
	music.setVolume(100);
	music.play();
	music.setLoop(true);
}

void Music::raiseVolume(){
	music.setVolume(music.getVolume() + 10); /// range 0 - 100
	if (music.getVolume() >= 100){
		music.setVolume(100);
	}
}

void Music::lowerVolume(){
	music.setVolume(music.getVolume() - 10); /// range 0 - 100
	if (music.getVolume() <= 0){
		music.setVolume(0);
	}
}

void Music::stop(){
	music.stop();
}