###############################################################
# Program:
#     Week 01, Vector
#     Brother Ercanbrack, CS235
# Author:
#     Jordan Jarvis
# Summary:
#     This assignment we had to build a vector class
#     which includes the functionality of the standard vector
#     class.
# Time:
#     3.5 hrs
###############################################################

##############################################################
# The main rule
##############################################################
a.out: vector.h week01.o
	g++ -o a.out week01.o -std=c++11
	tar -cf week01.tar vector.h week01.cpp makefile

##############################################################
# The individual components
#      week01.o     : the driver program
##############################################################
week01.o: vector.h week01.cpp 
	g++ -c week01.cpp -std=c++11


