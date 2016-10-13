//
//  Arena.cpp
//  Assignment 3
//
//  Created by Axel Garcia on 10/13/16.
//  Copyright © 2016 Axel Garcia. All rights reserved.
//

#include <stdio.h>
#include "Arena.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>
#include "globals.h"


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
    // TODO:  Delete the player and all remaining dynamically allocated robots.
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
{
    // TODO:  Return the number of robots at row r, column c.
    return 0;  // This implementation compiles, but is incorrect.
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
    
    // Indicate each robot's position
    // TODO:  If one robot is at some grid point, set the char to 'R'.
    //        If it's 2 though 8, set it to '2' through '8'.
    //        For 9 or more, set it to '9'.
    
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
    // If MAXROBOTS have already been added, return false.  Otherwise,
    // dynamically allocate a new robot at coordinates (r,c).  Save the
    // pointer to the newly allocated robot and return true.
    
    // TODO:  Implement this.
    return false;  // This implementation compiles, but is incorrect.
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
}

bool Arena::moveRobots()
{
    for (int k = 0; k < m_nRobots; k++)
    {
        // TODO:  Have the k-th robot in the arena make one move.
        //        If that move results in that robot being in the same
        //        position as the player, the player dies.
    }
    
    // return true if the player is still alive, false otherwise
    return ! m_player->isDead();
}

