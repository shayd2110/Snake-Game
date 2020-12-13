
/* 
 * File:   Apple.h
 * Author: shayd2110
 *
 * Created on 3 ינואר 2018, 00:04
 */
#include "misc.h"
#include "Position.h"
#ifndef APPLE_H
#define APPLE_H

typedef struct Apple* Apple;

/******************* Constructor  ****************/
Apple   CreateApple(int x,int y);
/******************* Destructor  ****************/
void    DeleteApple(Apple apple);
/******************* Getters  ****************/
int      getApple_Position_X(Apple apple);
int      getApple_Position_Y(Apple apple);
Position    getApplePos(Apple apple);
/******************* Setters  ****************/
void setApple_Position_X(Apple apple,int x);
void setApple_Position_Y(Apple apple,int y);

#endif /* APPLE_H */

