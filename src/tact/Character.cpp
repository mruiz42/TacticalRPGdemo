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
    is_walking = false;
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
    is_walking = false;
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
    is_walking = false;
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
    is_walking = false;
    for(int i = 0;i<4;++i)
    {
        move[i] = false;
    }
}

void Character::set_coordinate(int x, int y) {
    this->xy.set_x(x);
    this->xy.set_y(y);
}

void Character::startwalking(Coordinate final_xy)
{  
    //for the setter function to set the nextspot
    int temp_x =0;
    int temp_y =0;
    //gets the character's orgin
    Coordinate org_xy = this->get_coordinate();
    if(is_walking = false)
    {
        //move left
        if(org_xy.get_x() > final_xy.get_x())
        {
            //32 is the tilesize
            temp_x = org_xy.get_x() - 32;
            nextspot.set_x(temp_x);
            move[LEFT] = true;
            is_walking = true;
        }
    

        //move right
        if(org_xy.get_x() < final_xy.get_x())
        {
            //32 is the tile size
            temp_x = org_xy.get_x() + 32;
            nextspot.set_x(temp_x);
            move[RIGHT] = true;
            is_walking = true;
        }
    
        //move down
        if(org_xy.get_y() > final_xy.get_y())
        {
            //32 is the tile size
            temp_y = org_xy.get_y() + 32;
            nextspot.set_y(temp_y);
            move[DOWN] = true;
            is_walking = true;
        }
    }
}

void Character::walking()
{
    Coordinate curr_pos = this->get_coordinate();
    if (is_walking == true)
    {
        if(move[UP]==true)
        {
            curr_pos.set_y(curr_pos.get_y()-movespeed);
            if(curr_pos.get_y() <= nextspot.get_y())
            {
                curr_pos.set_y(nextspot.get_y());
                is_walking = false;
                move[UP] = false;
            }
        }

        if(move[DOWN]==true)
        {
            curr_pos.set_y(curr_pos.get_y()+movespeed);
            if(curr_pos.get_y() >= nextspot.get_y())
            {
                curr_pos.set_y(nextspot.get_y());
                is_walking = false;
                move[UP] = false;
            }
        }

        if(move[LEFT]==true)
        {
            curr_pos.set_y(curr_pos.get_y()-movespeed);
            if(curr_pos.get_y() <= nextspot.get_y())
            {
                curr_pos.set_y(nextspot.get_y());
                is_walking = false;
                move[UP] = false;
            }
        }
    }
}


