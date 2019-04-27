###############################################################
# Program:
#     week 13, Genealogy
#     Brother Ercanbrack, CS235
# Author:
#     Jordan Jarvis
# Summary:
#     Geneology search and parse from ged files. Does not use
#     standard template libraries.
###############################################################

##############################################################
# The main rule
##############################################################
a.out: main.o 
	g++ -o a.out main.o -g
	tar -cf week13.tar *.h *.cpp makefile

main.o: main.cpp
	g++ -c main.cpp -g
   
clean:
	rm a.out *.o *.tar
all : a.out