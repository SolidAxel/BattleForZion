//
//  Player.cpp
//  Assignment 3
//
//  Created by Axel Garcia on 10/13/16.
//  Copyright © 2016 Axel Garcia. All rights reserved.
//

#include <stdio.h>
#include "Arena.h"
#include "Player.h"
#include <iostream>

Player::Player(Arena* ap, int r, int c)
{
    if (ap == nullptr)
    {
        std::cout << "***** The player must be in some Arena!" << std::endl;
        exit(1);
    }
    if (r < 1  ||  r > ap->rows()  ||  c < 1  ||  c > ap->cols())
    {
        std::cout << "**** Player created with invalid coordinates (" << r
        << "," << c << ")!" << std::endl;
        exit(1);
    }
    m_arena = ap;
    m_row = r;
    m_col = c;
    m_age = 0;
    m_dead = false;
}

int Player::row() const
{
    return m_row;
}

int Player::col() const
{
    
    return m_col;
}

int Player::age() const
{
    return m_age;
}

std::string Player::takeComputerChosenTurn()
{
    // TODO:  Replace this implementation:
    stand();
    return "Stood";
    // Your replacement implementation should do something intelligent
    // and return a string that describes what happened.  When you've
    // decided what action to take, take it by calling move, shoot, or stand.
    // This function must return one of the following four strings:
    //     "Moved."
    //     "Shot and hit!"
    //     "Shot and missed!"
    //     "Stood."
    
    // Here's one possible strategy:
    //   If moving in some direction would put me in less immediate danger
    //     than standing, then move in that direction.
    //   else shoot in the direction of the nearest robot I can hit.
    
    // A more aggressive strategy is possible, where you hunt down robots.
}

void Player::stand()
{
    m_age++;
}

void Player::move(int dir)
{
    m_age++;
    switch (dir)
    {
        case UP:
            // TODO:  Move the player up one row if possible.
            break;
        case DOWN:
        case LEFT:
        case RIGHT:
            // TODO:  Implement the other movements.
            break;
    }
}

bool Player::shoot(int dir)
{
    m_age++;
    
    if (rand() % 3 == 0)  // miss with 1/3 probability
        return false;
    
    // TODO:  Damage the nearest robot in direction dir, returning
    // true if a robot is hit and damaged, false if not hit.
    return false;  // This implementation compiles, but is incorrect.
}

bool Player::isDead() const
{
    
    if(m_dead == true)
        return true;
    else
        return false;
}

void Player::setDead()
{
    m_dead = true;
}

