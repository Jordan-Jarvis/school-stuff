###############################################################
# Program:
#     Project 09, Skeet
#     Brother Cook, CS165
# Author:
#     Jordan Jarvis
# Summary:
#     This is a game of skeet
# Above and Beyond
#     I added gravity to the birds, they will slowly fall over
#     the course of being on screen. I also added a max shots
#     of ten per bird, after that the gun will not fire.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o rifle.o bird.o bullet.o velocity.o
	g++ driver.o game.o uiInteract.o uiDraw.o point.o rifle.o bird.o bullet.o velocity.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h point.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

game.o: game.cpp uiDraw.h uiInteract.h point.h rifle.h bullet.h bird.h
	g++ -c game.cpp

driver.o: game.h uiInteract.h driver.cpp
	g++ -c driver.cpp

rifle.o: rifle.h point.h uiDraw.h rifle.cpp
	g++ -c rifle.cpp

#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################
bullet.o: bullet.cpp bullet.h point.h velocity.h uiDraw.h rifle.h
	g++ -c bullet.cpp

bird.o: bird.h point.h bird.cpp velocity.h uiDraw.h
	g++ -c bird.cpp
   
velocity.o: velocity.cpp velocity.h
	g++ -c velocity.cpp

   
###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
