CXX = g++
CXXFLAGS = -g -Wall -std=c++20

CC = gcc
CFLAGS = -g -Wall -std=gnu11

CXX_SRCS = money.cpp money_tests.cpp
C_SRCS = tctest.c

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $*.cpp -o $*.o

%.o : %.c
	$(CC) $(CFLAGS) -c $*.c -o $*.o

money_tests : money.o money_tests.o tctest.o
	$(CXX) -o $@ $+

.PHONY: depend
depend :
	$(CXX) $(CXXFLAGS) -M $(CXX_SRCS) > depend.mak
	$(CC) $(CFLAGS) -M $(C_SRCS) >> depend.mak

depend.mak :
	touch $@

clean :
	rm -f *.o money_tests depend.mak

include depend.mak
