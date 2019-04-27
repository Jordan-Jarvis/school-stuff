###############################################################
# Program:
#     Project 07, Moon Lander
#     Brother Cook, CS165
# Author:
#     Jordan Jarvis
# Summary:
#     Finished the project, made the lander work better. 
# Above and Beyond
#     I added a function to check when the fuel is below 50
#     It will give a warning when the fuel is low. 
#     I also changed where the lander starts so that it will 
#     never start in an area where the ground is.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main Moon Lander game
###############################################################
a.out: driver.o ground.o game.o uiInteract.o uiDraw.o point.o velocity.o lander.o 
	g++ driver.o ground.o game.o uiInteract.o uiDraw.o point.o velocity.o lander.o  $(LFLAGS)
	tar -j -cf moonLander.tar makefile *.h *.cpp

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h point.h lander.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h point.h lander.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h lander.h
	g++ -c point.cpp

ground.o: ground.cpp ground.h lander.h
	g++ -c ground.cpp

game.o: game.h game.cpp uiDraw.h uiInteract.h point.h ground.h lander.h 
	g++ -c game.cpp

driver.o: driver.cpp game.h uiInteract.h lander.h
	g++ -c driver.cpp

#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################
lander.o: lander.cpp lander.h point.h velocity.h uiDraw.h uiInteract.h ground.h
	g++ -c lander.cpp
   
velocity.o: velocity.cpp velocity.h
	g++ -c velocity.cpp

###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o *.tar
