/*********************************************************************
 * File: game.h
 * Description: Defines the game class for Asteroids
 *
 *********************************************************************/

#ifndef GAME_H
#define GAME_H
/*************************************************************
 * File: game.h
 * Author: Br. Burton
 *
 * Description: The game of Skeet. This class holds each piece
 *  of the game (birds, bullets, rifle, score). It also has
 *  methods that make the game happen (advance, interact, etc.)
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 *************************************************************/


#include <vector>

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"
#include "rocks.h"
#include "bullet.h"
#include "ship.h"
#include "flyingObject.h"



 #define CLOSE_ENOUGH 15

/*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Game
{
public:
   /*********************************************
    * Constructor
    * Initializes the game
    *********************************************/
   Game(Point tl, Point br);
   ~Game();
   
   /*********************************************
    * Function: handleInput
    * Description: Takes actions according to whatever
    *  keys the user has pressed.
    *********************************************/
   void handleInput(const Interface & ui);
   float getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const;
   /*********************************************
    * Function: advance
    * Description: Move everything forward one
    *  step in time.
    *********************************************/
   void advance();

   /*********************************************
    * Function: dSraw
    * Description: draws everything for the game.
    *********************************************/
   void draw(const Interface & ui);
   
private:
   // The coordinates of the screen
   Point topLeft;
   Point bottomRight;
   
   int score;
   int points;
   Ship ship;
   bool gameOver;
   std::vector<Bullet> bullets;
   std::vector<Rock*> rocks;
   // TODO: declare your bird here (e.g., "Bird * bird;")
   int wait;
   int type;
   bool justDied;
   Point rockPoint;
   Velocity rockVelocity;
   int up;
   /*************************************************
    * Private methods to help with the game logic.
    *************************************************/
   bool isOnScreen(const Point & point);
   void advanceBullets();
   void advanceRock();
   void advanceShip(); 
   void createRock(int rockType);
   
   void handleCollisions();
   void cleanUpZombies();
};

#endif /* GAME_H */
