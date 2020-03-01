//
// Created by michael on 1/21/20.
//

#include "../../include/tact/Character.h"


Character::Character() : xy(0,0) {
    name = "";
    level = 0;
    attack_on = false;
    moved = false;
    defending = false;
    experience = 0;
    hit_points = 0;
    mana_points = 0;
    attack = 0;
    defense = 0;
    speed = 0;
    special_attack = 0;
    special_defense = 0;

    //newly added vars
    movespeed = 50/32.0;
    walking = false;
    for(int i = 0;i<4;++i)
    {
        move[i] = false;
    }
}

Character::Character(Coordinate xy) : xy(xy) {
    name = "";
    level = 0;
    attack_on = false;
    moved = false;
    defending = false;
    experience = 0;
    hit_points = 0;
    mana_points = 0;
    attack = 0;
    defense = 0;
    speed = 0;
    special_attack = 0;
    special_defense = 0;

    movespeed = 100/32.0;
    walking = false;
    for(int i = 0;i<4;++i)
    {
        move[i] = false;
    }
}

Character::Character(int x, int y) : xy(x, y) {
    name = "";
    level = 0;
    attack_on = false;
    moved = false;
    defending = false;
    experience = 0;
    hit_points = 0;
    mana_points = 0;
    attack = 0;
    defense = 0;
    speed = 0;
    special_attack = 0;
    special_defense = 0;
    
    movespeed = 64/32.0;//walking 2 pixels
    walking = false;
    for(int i = 0;i<4;++i)
    {
        move[i] = false;
    }
}

Character::Character(std::string filename){
    texture.loadFromFile(filename);
    sidebar_sprite.setTexture(texture);
    map_sprite.setTexture(texture);
    name = "";
    attack_on = false;
    moved = false;
    defending = false;
    level = 0;
    experience = 0;
    hit_points = 0;
    mana_points = 0;
    attack = 0;
    defense = 0;
    speed = 0;
    special_attack = 0;
    special_defense = 0;

    movespeed = 100/(32.0);
    walking = false;
    for(int i = 0;i<4;++i)
    {
        move[i] = false;
    }
}

void Character::set_coordinate(int x, int y) {
    this->xy.set_x(x);
    this->xy.set_y(y);
}

bool Character::startwalking(Coordinate final_xy)
{
//    Coordinate delta_pos = get_delta_pos(final_xy);
//    float x = delta_pos.get_map_x();
//    float y = delta_pos.get_map_y();
//    float x_chunk = x / 1000, y_chunk = y / 1000;
//    if (xy == final_xy) {
//        return false;
//    }
//    else {
//        std::cout<<"moving " ;
//        this->map_sprite.move(x_chunk, y_chunk);
//
//        return true;
//    }
    //for the setter function to set the nextspot
//    int temp_x =0;
//    int temp_y =0;
//    //gets the character's orgin
//    Coordinate org_xy = this->get_coordinate();
//    if(!walking)
//    {
//        //move left
//        if(org_xy.get_x() > final_xy.get_x())
//        {
//            //32 is the tilesize
//            temp_x = org_xy.get_x() - 32;
//            nextspot.set_x(temp_x);
//            move[LEFT] = true;
//            walking = true;
//        }
//
//
//        //move right
//        if(org_xy.get_x() < final_xy.get_x())
//        {
//            //32 is the tile size
//            temp_x = org_xy.get_x() + 32;
//            nextspot.set_x(temp_x);
//            move[RIGHT] = true;
//            walking = true;
//        }
//
//        //move down
//        if(org_xy.get_y() > final_xy.get_y())
//        {
//            //32 is the tile size
//            temp_y = org_xy.get_y() + 32;
//            nextspot.set_y(temp_y);
//            move[DOWN] = true;
//            walking = true;
//        }
//    }
}

Coordinate Character::walk(Coordinate chunk)
{

//    Coordinate curr_pos = this->get_coordinate();
//    while (walking)
//    {
//        std::cout << "walking ... " << std::endl;
//        if(move[UP])
//        {
//            curr_pos.set_y(curr_pos.get_y()-movespeed);
//            if(curr_pos.get_y() <= nextspot.get_y())
//            {
//                curr_pos.set_y(nextspot.get_y());
//                walking = false;
//                move[UP] = false;
//            }
//        }
//
//        if(move[DOWN])
//        {
//            curr_pos.set_y(curr_pos.get_y()+movespeed);
//            if(curr_pos.get_y() >= nextspot.get_y())
//            {
//                curr_pos.set_y(nextspot.get_y());
//                walking = false;
//                move[UP] = false;
//            }
//        }
//
//        if(move[LEFT])
//        {
//            curr_pos.set_x(curr_pos.get_x()-movespeed);
//            if(curr_pos.get_x() <= nextspot.get_x())
//            {
//                curr_pos.set_x(nextspot.get_x());
//                walking = false;
//                move[UP] = false;
//            }
//        }
//
//        if(move[RIGHT])
//        {
//            curr_pos.set_x(curr_pos.get_x()+movespeed);
//            if(curr_pos.get_x() <= nextspot.get_x())
//            {
//                curr_pos.set_x(nextspot.get_x());
//                walking = false;
//                move[UP] = false;
//            }
//        }
//    }
}


void Character::draw(sf::RenderTarget& target, sf::RenderStates states) const {
//    float x = nextspot.get_map_x();
//    float y = nextspot.get_map_y();
//    target.draw(this->map_sprite, states);
}
