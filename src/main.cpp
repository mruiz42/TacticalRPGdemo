#include "../include/tact/Game.h"
//const int HP_MAX = 200;
//const int HP_MIN = 0;
//const int HP_RAISE = 5;
//const int HP_DROP = 10;
//static int HP = 100;

int main()
{
    // Create window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tactical RPG demo");
    window.setSize(sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT));
    tact::Game game;
    game.play_game(window);
    return 0;
}