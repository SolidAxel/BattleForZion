//
//  Arena.cpp
//  Assignment 3
//
//  Created by Axel Garcia on 10/13/16.
//  Copyright © 2016 Axel Garcia. All rights reserved.
//

#include "Arena.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>
#include "globals.h"
#include "Robot.h"

Arena::Arena(int nRows, int nCols)
{
    if (nRows <= 0  ||  nCols <= 0  ||  nRows > MAXROWS  ||  nCols > MAXCOLS)
    {
        std::cout << "***** Arena created with invalid size " << nRows << " by "
        << nCols << "!" << std::endl;
        exit(1);
    }
    m_rows = nRows;
    m_cols = nCols;
    m_player = nullptr;
    m_nRobots = 0;
}

Arena::~Arena()
{
    for (int i = 0; i < m_nRobots; i++)
    {
        delete m_robots[i];
    }

    delete m_player;
   
}

int Arena::rows() const
{
    return m_rows;
}
int Arena::cols() const
{
    return m_cols;
}

Player* Arena::player() const
{
    return m_player;
}

int Arena::robotCount() const
{
    return m_nRobots;
}

int Arena::nRobotsAt(int r, int c) const
{   int counter = 0;
    for (int i = 1; i< m_nRobots; i++) {
        for (int j=1; j< m_nRobots; j++) {
            if (m_robots[i] -> row() == r && m_robots[j] -> row() == r && m_robots[i] -> col() == c && m_robots[j] -> col() == c)
            {
                    counter++;
            }
        }
    }
    return counter;
}

void Arena::display(std::string msg) const
{
    // Position (row,col) in the arena coordinate system is represented in
    // the array element grid[row-1][col-1]
    char grid[MAXROWS][MAXCOLS];
    int r, c;
    
    // Fill the grid with dots
    for (r = 0; r < rows(); r++)
        for (c = 0; c < cols(); c++)
            grid[r][c] = '.';
    
    for (int i = 0; i < m_nRobots; i++) {
        if (m_robots[i] != nullptr) {
            char& gridChar = grid[m_robots[i]->row()-1][m_robots[i]->col()-1];
            if (gridChar == '.')
                gridChar = 'R';
            else if(gridChar == 'R'){
                gridChar = '2';
            }
            else if (gridChar == '2'){
                gridChar = '3';
            }
            else if (gridChar == '3'){
                gridChar = '4';
            }
            else if (gridChar == '4'){
                gridChar = '5';}
            else if (gridChar== '5'){
                gridChar = '6';}
            else if (gridChar == '6'){
                gridChar ='7';}
            else if (gridChar == '7'){
                gridChar ='8';}
            else
                gridChar = '9';

    }
}
    
    
    // Indicate player's position
    if (m_player != nullptr)
    {
        // Set the char to '@', unless there's also a robot there,
        // in which case set it to '*'.
        char& gridChar = grid[m_player->row()-1][m_player->col()-1];
        if (gridChar == '.')
            gridChar = '@';
        else
            gridChar = '*';
    }
    
    // Draw the grid
    clearScreen();
    for (r = 0; r < rows(); r++)
    {
        for (c = 0; c < cols(); c++)
            std::cout << grid[r][c];
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    // Write message, robot, and player info
    std::cout << std::endl;
    if (msg != "")
        std::cout << msg << std::endl;
    std::cout << "There are " << robotCount() << " robots remaining." << std::endl;
    if (m_player == nullptr)
        std::cout << "There is no player." << std::endl;
    else
    {
        if (m_player->age() > 0)
            std::cout << "The player has lasted " << m_player->age() << " steps." << std::endl;
        if (m_player->isDead())
            std::cout << "The player is dead." << std::endl;
    }
}

bool Arena::addRobot(int r, int c)
{
    if (m_nRobots == MAXROBOTS) {
        return false;
    }
    else{
        m_robots[m_nRobots] = new Robot(this, r, c);
        m_nRobots++;
        return true;
    }
    
}
bool Arena::addPlayer(int r, int c)
{
    // Don't add a player if one already exists
    if (m_player != nullptr)
        return false;
    
    // Dynamically allocate a new Player and add it to the arena
    m_player = new Player(this, r, c);
    return true;
}

void Arena::damageRobotAt(int r, int c)
{
    // TODO:  Damage one robot at row r, column c if at least one is there.
    // If the robot does not survive the damage, destroy it.
    for (int i = 0 ; i < m_nRobots; i++) {
        if (m_robots[i] -> row() == r && m_robots[i] -> col() == c) {
            m_robots[i] -> takeDamageAndLive();
            if(m_robots[i] -> takeDamageAndLive() == false){
                m_robots[i] = nullptr;
            }
        }
    }
}

bool Arena::moveRobots()
{
    for (int k = 0; k < m_nRobots; k++)
    {
        m_robots[k] -> move();
        if (m_robots[k] -> row() == m_player -> row() && m_robots[k] -> col() == m_player -> col()) {
            m_player -> setDead();
        }
    }
    
    // return true if the player is still alive, false otherwise
    return ! m_player->isDead();
}

