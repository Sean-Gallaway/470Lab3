#Define which C Compiler to use
CC = gcc

#compile flags
CFLAGS = -Wall -g

# set name of the executables
RR = rr.c
SJF = sjf.c

# define two targets
all: roundrobin shortestjob

# first target
roundrobin:
	$(CC) $(RR) util.c -o rr

#second target
shortestjob:
	$(CC) $(SJF) util.c -o sjf
