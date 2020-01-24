CC      = g++
FCLAGS  = -std=c++20  -Wall   -Wextra -pedantic
INCLUDE = ./include
COMPILE = $(CC) $(CFLAGS) -I$(INCLUDE) -c
BUILD   = $(CC) $(CFLAGS) -I$(INCLUDE)
EXE     = ./bin/something.out
LINKSFML= -lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio
LINKSTT = -L$(LIBDIR) -lactors
DSRC    = ./src/tct

LIBSRC  = ./libsrc/
LIBDIR  = ./lib/
STTLIB  = $(DRCOBJ)Menu.o : $(DRCSRC)Menu.cpp $(DRCINC)Menu.h
	$(COMPILE) $(DRCSRC)Menu.cpp -o $(DRCOBJ)Menu.o
	
clean :
	@rm -f $(SRCOBJ)main.o
	@rm -f $(LIBOBJ)*.o
	@rm -f $(DSRC)*/obj/*.o
	@rm -f $(STTLIB)
	@rm -f $(EXE)
	
all : clean $(EXE)

run : $(EXE)
        @$(EXE) #run program
