CC = g++
OPT = -O3
#OPT = -g
WARN = -Wall
CFLAGS = $(OPT) $(WARN) $(INC) $(LIB)

# List all your .cc files here (source files, excluding header files)
SIM_SRC = main.cpp src/smith.cpp src/bimodal.cpp src/gshare.cpp src/hybrid.cpp

# List corresponding compiled object files here (.o files)
SIM_OBJ = main.o src/smith.o src/bimodal.o src/gshare.o src/hybrid.o
 
#################################

# default rule

all: sim
	@echo "my work is done here..."


# rule for making sim

sim: $(SIM_OBJ)
	$(CC) -o sim $(CFLAGS) $(SIM_OBJ) -lm
	@echo "-----------DONE WITH SIM-----------"


# generic rule for converting any .cc file to any .o file
 
.cc.o:
	$(CC) $(CFLAGS)  -c $*.cc


# type "make clean" to remove all .o files plus the sim_cache binary

clean:
	rm -f *.o sim 
	cd src
	rm -f *.o bimodal
	rm -f *.o gshare
	rm -f *.o smith
	rm -f *.o hybrid
	cd ..


# type "make clobber" to remove all .o files (leaves sim_cache binary)

clobber:
	rm -f *.o
