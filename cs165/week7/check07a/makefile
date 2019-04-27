###############################################################
# Program:
#     Checkpoint 07a, Static
#     Brother Cook, CS165
# Author:
#     Jordan Jarvis
# Summary:
#     Summaries are not necessary for checkpoint assignments.
###############################################################


a.out : salesTax.o icecream.o check07a.o 
	g++ salesTax.o icecream.o check07a.o

icecream.o : icecream.h icecream.cpp salesTax.h
	g++ -c icecream.cpp

salesTax.o : salesTax.h salesTax.cpp 
	g++ -c salesTax.cpp

check07a.o : icecream.h salesTax.h check07a.cpp
	g++ -c check07a.cpp

clean :
	rm *.o
	rm a.out
