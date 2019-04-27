/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *
 *********************************************************************/



/*************************************************************
 * File: game.cpp
 * Author: Br. Burton
 *
 * Description: Contains the implementations of the
 *  method bodies for the game class.
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 *************************************************************/

#include "game.h"
#include <limits>
#include <algorithm>
#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "flyingObject.h"
#include <vector>
using namespace std;

#define OFF_SCREEN_BORDER_AMOUNT 5 


/***************************************
 * GAME CONSTRUCTOR
 ***************************************/
Game :: Game(Point tl, Point br)
 : topLeft(tl), bottomRight(br)
{
   // Set up the initial conditions of the game
   score = 0;
   wait = 0;
   type = 1;
   gameOver = 1;
   justDied = 0;
   up = 0;
   createRock(type);
   createRock(type);
   createRock(type);
   createRock(type);
   createRock(type);
   
}

/****************************************
 * GAME DESTRUCTOR
 ****************************************/
Game :: ~Game()
{
   
}

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
   advanceBullets();
   advanceRock();
   advanceShip();
   handleCollisions();
   cleanUpZombies();
}

/***************************************
 * GAME :: ADVANCE BULLETS
 * Go through each bullet and advance it.
 ***************************************/
void Game :: advanceBullets()
{
   // Move each of the bullets forward if it is alive
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         bullets[i].advance();
      }
   }
}


float Game :: getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const
{
   // find the maximum distance traveled
   float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
   dMax = max(dMax, abs(obj2.getVelocity().getDx()));
   dMax = max(dMax, abs(obj2.getVelocity().getDy()));
   dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.
   
   float distMin = std::numeric_limits<float>::max();
   for (float i = 0.0; i <= dMax; i++)
   {
      Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
                     obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
      Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
                     obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));
      
      float xDiff = point1.getX() - point2.getX();
      float yDiff = point1.getY() - point2.getY();
      
      float distSquared = (xDiff * xDiff) +(yDiff * yDiff);
      
      distMin = min(distMin, distSquared);
   }
   
   return sqrt(distMin);
}

/**************************************************************************
 * GAME :: ADVANCE BIRD
 *
 * 1. If there is no bird, create one with some probability
 * 2. If there is a bird, and it's alive, advance it
 * 3. Check if the bird has gone of the screen, and if so, "kill" it
 **************************************************************************/
void Game :: advanceRock()
{
   
   if (gameOver != 0)
   {
   if(justDied == 1)
      switch(type)
      {
         case 1:
         up = 1;
         createRock(2);
         up = -1;
         createRock(2);
         up = 2;
         createRock(3);
         break;
         case 2:
         up = 3;
         createRock(3);
         up = -3;
         createRock(3);
         break;
         case 3:
         break;
      }
      justDied = 0;
         
   for (int i = 0; i < rocks.size(); i++)
   {

      // we have a bird, make sure it's alive
      if (rocks[i]->isAlive())
      {
         rocks[i]->advance();
         // check if the bird has gone off the screen
      }
   }
   }
}

void Game :: advanceShip()
{
   if (gameOver != 0)
   {     
      ship.advance();
   }
}

/**************************************************************************
 * GAME :: CREATE BIRD
 * Create a bird of a random type according to the rules of the game.
 **************************************************************************/
void Game :: createRock(int rockType)
{
   Rock* newRock = NULL;
   switch(rockType)
   {
      case 3:
      newRock = new SmallRock(rockPoint, rockVelocity, up);
      break;
      
      case 2:
      newRock = new MediumRock(rockPoint, rockVelocity, up);
      break;
       
      case 1:
      newRock = new BigRock();
      break;
   }
    
      
   rocks.push_back(newRock);
}

/**************************************************************************
 * GAME :: IS ON SCREEN
 * Determines if a given point is on the screen.
 **************************************************************************/
bool Game :: isOnScreen(const Point & point)
{
   return (point.getX() >= topLeft.getX() - OFF_SCREEN_BORDER_AMOUNT
      && point.getX() <= bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT
      && point.getY() >= bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT
      && point.getY() <= topLeft.getY() + OFF_SCREEN_BORDER_AMOUNT);
}

/**************************************************************************
 * GAME :: HANDLE COLLISIONS
 * Check for a collision between a bird and a bullet.
 **************************************************************************/
void Game :: handleCollisions()
{
   int closestDistance = 0;
   int shipradius = 0;
   int rockradius = 0;
   //getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const
   // now check for a hit (if it is close enough to any live bullets)
   for (int j = 0; j < rocks.size(); j++)
   {
      for (int i = 0; i < bullets.size(); i++)
      {
         if (bullets[i].isAlive())
         {
         // this bullet is alive, see if its too close
            
         // check if the bird is at this point (in case it was hit)
            if (rocks[j]->isAlive())
            {
               
               rockradius = rocks[j]->getRadius();
               closestDistance = getClosestDistance( *rocks[j], bullets[i]);
            // BTW, this logic could be more sophisiticated, but this will
            // get the job done for now...
               if (closestDistance <= rockradius)
               {
   
                  rockPoint = rocks[j]->getPoint();
                  rockVelocity = rocks[j]->getVelocity();
                  int points = rocks[j]->hit();
                  score += points;
                  bullets[i].kill();
                  type = rocks[j]->kill();
                  justDied = 1;
               }
            }
         } // if bullet is alive
      }
   }
   for (int i = 0; i < rocks.size(); i++)
   {
      int shipradius = 0;
   int rockradius = 0;
            if (rocks[i] != NULL && rocks[i]->isAlive())
            {
               shipradius = ship.getRadius();
               rockradius = rocks[i]->getRadius();
               closestDistance = getClosestDistance( *rocks[i], ship);
               if (closestDistance < shipradius + rockradius)
               {
                  drawText(Point(), "You have crashed! GAME OVER");
                  ship.kill();
                  gameOver = 0;
               }
            }
   }
}


/**************************************************************************
 * GAME :: CLEAN UP ZOMBIES
 * Remove any dead objects (take bullets out of the list, deallocate bird)
 **************************************************************************/
void Game :: cleanUpZombies()
{

   vector<Bullet>::iterator bulletIt = bullets.begin();
   while (bulletIt != bullets.end())
   {
      Bullet bullet = *bulletIt;
      // Asteroids Hint:
      // If we had a list of pointers, we would need this line instead:
      //Bullet* pBullet = *bulletIt;
      
      if (!bullet.isAlive())
      {
         bulletIt = bullets.erase(bulletIt);
      }
      else
      {
         bulletIt++; // advance
      }
   }
   vector<Rock*>::iterator rockIt = rocks.begin();
   while (rockIt != rocks.end())
   {
      Rock* rock = *rockIt;
      // Asteroids Hint:
      
      if (!rock->isAlive())
      {
         rockIt = rocks.erase(rockIt);
      }
      else
      {
         rockIt++; // advance
      }
   }
   
}

/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
   // Change the direction of the rifle
   if (ui.isLeft())
   {
      ship.rotateLeft();
   }
   
   if (ui.isRight())
   {
      ship.rotateRight();
   }
   if (ui.isDown())
   {
      ship.applyThrust();
   }
   
   // Check for "Spacebar
   if (ui.isSpace())
   {
         Bullet newBullet;
         newBullet.fire(ship.getPoint(), ship.getAngle());
         bullets.push_back(newBullet);
   }
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
   
   for (int i = 0; i < rocks.size(); i++)
   {
      if (rocks[i]->isAlive())
         rocks[i]->draw();
   }   
   wait++;
   ship.draw();
   
   // draw the bullets, if they are alive
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         bullets[i].draw();
      }
   }
   
   // Put the score on the screen
   Point scoreLocation;
   scoreLocation.setX(topLeft.getX() + 5);
   scoreLocation.setY(topLeft.getY() - 5);
   
   drawNumber(scoreLocation, score);

}

