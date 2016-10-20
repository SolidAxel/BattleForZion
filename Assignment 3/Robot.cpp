//
//  Robot.cpp
//  Assignment 3
//
//  Created by Axel Garcia on 10/13/16.
//  Copyright © 2016 Axel Garcia. All rights reserved.
//
#ifndef Robot_cpp
#define Robot_cpp

#include <cstdlib>
#include <iostream>
#include "Robot.h"
#include "globals.h"
#include "Arena.h"

Robot::Robot(Arena* ap, int r, int c)
{
    if (ap == nullptr)
    {
        std::cout << "***** A robot must be in some Arena!" << std::endl;
        exit(1);
    }
    if (r < 1  ||  r > ap->rows()  ||  c < 1  ||  c > ap->cols())
    {
        std::cout << "***** Robot created with invalid coordinates (" << r << ","
        << c << ")!" << std::endl;
        exit(1);
    }
    m_arena = ap;
    m_row = r;
    m_col = c;
}

int Robot::row() const
{
    return m_row;
}

int Robot::col() const
{
    return m_col;
}

void Robot::move()
{
    // Attempt to move in a random direction; if we can't move, don't move
    switch (rand() % 4)
    {
        case UP:
            // TODO:  Move the robot up one row if possible.
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
            // TODO:  Implement the other movements.
            if (col() != m_arena -> cols()) {
                m_col = m_col+1;
            }
            break;

    }
}

bool Robot::takeDamageAndLive()
{
    // TODO:  If the robot has been hit once before, return false (since a
    // second hit kills a robot).  Otherwise, return true (since the robot
    // survived the damage).
    m_damage++;
    if(m_damage > 1)
        return false;
    else
        return true;
}
#endif
