//
//  Player.cpp
//  Assignment 3
//
//  Created by Axel Garcia on 10/13/16.
//  Copyright © 2016 Axel Garcia. All rights reserved.
//

#include "Arena.h"
#include "Player.h"
#include <iostream>
class Arena;
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
    std::string message;
    if (m_arena -> nRobotsAt(row()-1, col()) >= 1 ||m_arena -> nRobotsAt(row()+1, col()) >=1||m_arena -> nRobotsAt(row(), col()-1) >=1||m_arena -> nRobotsAt(row(), col()+1) >=1) {
        if (m_arena -> nRobotsAt(row()-1, col()) >= 1) {
            if (row() != m_arena -> rows()) {
                move(DOWN);
                message = "Moved.";
            }
            else{
                if(shoot(UP) == true){
                    message = "Shot and hit!";
                }
                else
                    message ="Shot and missed!";
            }
        }
        else if (m_arena -> nRobotsAt(row()+1, col()) >=1){
            if (row() != (m_arena -> rows()!=0)) {
                move(UP);
                message = "Moved.";
            }
            else{
                if(shoot(DOWN) == true){
                    message = "Shot and hit!";
                }
                else
                    message ="Shot and missed!";
            }
        }
        else if (m_arena -> nRobotsAt(row(), col()-1) >=1){
            if (col() != m_arena -> cols()) {
                move(RIGHT);
                message = "Moved.";
            }
            else{
                if(shoot(LEFT) == true){
                    message = "Shot and hit!";
                }
                else
                    message ="Shot and missed!";
            }
        }
        else if (m_arena -> nRobotsAt(row(), col()+1) >=1){
            if (col() != (m_arena -> cols()!=0)) {
                move(LEFT);
                message = "Moved.";
            }
            else{
                if(shoot(RIGHT) == true){
                    message = "Shot and hit!";
                }
                else
                    message ="Shot and missed!";
            }
        }
    }
    else{
        for (int i = 2; i <= MAXSHOTLEN; i++) {      //i initialized to two so computer only takes shot if robots is at least two spaces away.
            if (m_arena -> nRobotsAt(row()+i, col()) >= 1||m_arena -> nRobotsAt(row()-i, col()) >= 1||m_arena -> nRobotsAt(row(), col()+i) >= 1||m_arena -> nRobotsAt(row(), col()-i) >= 1) {
                if (m_arena -> nRobotsAt(row()+i, col()) >= 1) {
                    if(shoot(DOWN) == true){
                        message = "Shot and hit!";
                        
                        }
                        else
                            message = "Shot and missed!";
                        break;
                    }
                    else if (m_arena -> nRobotsAt(row()-i, col()) >= 1) {
                        if(shoot(UP) == true){
                            message = "Shot and hit!";
                        }
                        else
                            message = "Shot and missed!";
                        break;
                    }
                    else if (m_arena -> nRobotsAt(row(), col()+i) >= 1) {
                        if(shoot(RIGHT) == true){
                            message = "Shot and hit!";
                        }
                        else
                            message = "Shot and missed!";
                        break;
                    }
                    else if (m_arena -> nRobotsAt(row(), col()-i) >= 1) {
                        if(shoot(LEFT) == true){
                            message = "Shot and hit!";
                        }
                        else
                            message = "Shot and missed!";
                        break;
                    }
            }
            else{
                move(rand() % 4);
                message = "Moved.";
            }
        }
    }
        return message;
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
            if (row() != (m_arena -> rows()!=0)) {
                m_row = m_row-1;
            }
            break;
        case DOWN:
            if (row() != m_arena -> rows()) {
                m_row = m_row+1;
            }
            break;
        case LEFT:
            if (col() != (m_arena -> cols()!=0)) {
                m_col = m_col-1;
            }
            break;
        case RIGHT:
            if (col() != m_arena -> cols()) {
                m_col = m_col+1;
            }
            break;
    }
}

bool Player::shoot(int dir)
{
    m_age++;
    bool flag =false;
    
    if (rand() % 3 == 0)  // miss with 1/3 probability
        flag = false;
    
    // TODO:  Damage the nearest robot in direction dir, returning
    // true if a robot is hit and damaged, false if not hit.
     if (dir == 0) {
        for (int i = 1; i <= MAXSHOTLEN; i++) {
            if (m_arena -> nRobotsAt(row()-i, col()) >= 1) {
                m_arena -> damageRobotAt(row()-i, col());
                flag= true;
                break;
            }
        }
        
    }
    else if (dir == 1) {
        for (int i = 1; i <= MAXSHOTLEN; i++) {
            if (m_arena -> nRobotsAt(row()+i, col()) >= 1) {
                m_arena -> damageRobotAt(row()+i, col());
                flag= true;
                break;
            }
        }
        
    }
    else if (dir == 2) {
        for (int i = 1; i <= MAXSHOTLEN; i++) {
            if (m_arena -> nRobotsAt(row(),col()-i) >= 1) {
                m_arena -> damageRobotAt(row(), col()-i);
                flag = true;
                break;
            }
        }
        
    }
    else if (dir == 3) {
        for (int i = 1; i <= MAXSHOTLEN; i++) {
            if (m_arena -> nRobotsAt(row(), col()+i) >= 1) {
                m_arena -> damageRobotAt(row(), col()+i);
                flag= true;
                break;
            }
        }
    }
    return flag;
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

