###############################################################
# Program:
#     Week 08, Binary Tree
#     Brother Ercanbrack, CS235
# Author:
#     Jordan Jarvis
# Summary:
#     a tree of linked nodes that can create a huffman code
# Time:
#     12 hr
###############################################################

##############################################################
# The main rule
##############################################################
a.out: week08.o huffman.o 
	g++ -o a.out week08.o huffman.o -g -std=c++11 -g
	tar -cf week08.tar *.h *.cpp makefile

##############################################################
# The individual components
#      week08.o     : the driver program
#      huffman.o      : the logic for the huffman code program
##############################################################
week08.o: bnode.h huffman.h week08.cpp
	g++ -c week08.cpp -g -std=c++11 -g

huffman.o: bnode.h huffman.h huffman.cpp
	g++ -c huffman.cpp -g -std=c++11 -g

