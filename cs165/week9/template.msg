/***********************************************************************
* Program:
*    Checkpoint 00,
*    Brother Cook, CS165
************************************************************************/

Undefined referenceeference to `Lander::setFuel(int)'
game.o: In function `Game::justLanded() const':
game.cpp:(.text+0x4f): undefined reference to `Lander::getPoint() const'
game.cpp:(.text+0x9a): undefined reference to `Lander::getPoint() const'
game.cpp:(.text+0x14f): undefined reference to `Lander::getVelocity() const'
game.cpp:(.text+0x16d): undefined reference to `Velocity::getDx()'
game.cpp:(.text+0x195): undefined reference to `Lander::getVelocity() const'
game.cpp:(.text+0x1b4): undefined reference to `Velocity::getDy()'
game.o: In function `Game::advance()':
game.cpp:(.text+0x21e): undefined reference to `Lander::isAlive()'
game.cpp:(.text+0x232): undefined reference to `Lander::isLanded()'
game.cpp:(.text+0x265): undefined reference to `Lander::applyGravity(float)'
game.cpp:(.text+0x275): undefined reference to `Lander::advance()'
game.cpp:(.text+0x285): undefined reference to `Lander::getPoint() const'
game.cpp:(.text+0x2c5): undefined reference to `Lander::setAlive(bool)'
game.cpp:(.text+0x2ea): undefined reference to `Lander::setLanded(bool)'
game.o: In function `Game::handleInput(Interface const&)':
game.cpp:(.text+0x30c): undefined reference to `Lander::isAlive()'
game.cpp:(.text+0x320): undefined reference to `Lander::isLanded()'
game.cpp:(.text+0x35c): undefined reference to `Lander::applyThrustBottom()'
game.cpp:(.text+0x381): undefined reference to `Lander::applyThrustLeft()'
game.cpp:(.text+0x3a6): undefined reference to `Lander::applyThrustRight()'
game.o: In function `Game::draw(Interface const&)':
game.cpp:(.text+0x3cd): undefined reference to `Lander::draw()'
game.cpp:(.text+0x3dd): undefined reference to `Lander::isLanded()'
