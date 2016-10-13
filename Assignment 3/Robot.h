//
//  Robot.h
//  Assignment 3
//
//  Created by Axel Garcia on 10/13/16.
//  Copyright © 2016 Axel Garcia. All rights reserved.
//

#ifndef Robot_h
#define Robot_h

class Arena;

class Robot
{
public:
    // Constructor
    Robot(Arena* ap, int r, int c);
    
    // Accessors
    int  row() const;
    int  col() const;
    
    // Mutators
    void move();
    bool takeDamageAndLive();
    
private:
    Arena* m_arena;
    int    m_row;
    int    m_col;
    int    m_damage;
    
};

#endif /* Robot_h */
