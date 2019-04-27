###############################################################
# Program:
#     Week 09, Binary Search Tree
#     Brother Ercanbrack, CS235
# Author:
#     Jordan Jarvis
# Summary:
#     Binary search tree thingy
# Time:
#     13hrs
###############################################################

##############################################################
# The main rule
##############################################################
a.out: week09.o
	g++ -o a.out week09.o -std=c++11 -g
	tar -cf week09.tar *.h *.cpp makefile

##############################################################
# The individual components
#      lesson08.o     : the driver program
##############################################################
week09.o: bnode.h bst.h stack.h week09.cpp sortBinary.h
	g++ -c week09.cpp -std=c++11 -g

