###############################################################
# Program:
#     Week 12, Hash
#     Brother Ercanbrack, CS235
# Author:
#     Jordan Jarvis
# Summary:
#     Hash class with a spell checker on the end
###############################################################

##############################################################
# The main rule
##############################################################
a.out: week12.o spellCheck.o
	g++ -o a.out week12.o spellCheck.o -g -std=c++11
	tar -cf week12.tar *.h *.cpp makefile

##############################################################
# The individual components
#      week12.o     : the driver program
#      spellCheck.o   : the spell-check program and driver
##############################################################
week12.o: hash.h week12.cpp
	g++ -c week12.cpp -g -std=c++11 -g

spellCheck.o: hash.h spellCheck.h spellCheck.cpp
	g++ -c spellCheck.cpp -g -std=c++11 -g

