# Tactical RPG demo

![alt text](https://i.imgur.com/iqKZzW5.png)

## CIS 29 Group 2 (Winter 2020)
* Michael Ruiz (Group lead)
* Lai Chi (Lychee) C. 
* Michael E.
* Casey N.

## About
A simple turn based tactical rpg game. The point of the game is to eliminate the opposing team's units to claim victory.

## Controls
#### Keyboard:
`WSAD - move cursor`
`Enter - select`
`Backspace - back`

#### Controller:
`DPad - move cursor`
`A - select`
`B - back`

## Getting started
#### Mac OS & Linux
##### Requirements:
* SFML
>official download: https://www.sfml-dev.org/tutorials/2.5/
><br>Mac OS: `brew install sfml`</br>
><br>Ubuntu: `apt-get install sfml-dev`</br>
><br>Arch Linux: `pacman -S sfml`</br>
* GCC & GNU Make
>Mac OS: `brew install gcc`
><br>Ubuntu: `apt-get install build-essential`</br>
><br>Arch Linux: `pacman -S base-devel`</br>

##### How to run:
`make && make run`
#### Windows
Due to the annoying nature of developing on windows, it is not officially supported. 
However, it should run fine if you are able to get `gcc make` on some sort of windows bash shell or compile the source files yourself.
##### Requirements:
 * SFML https://www.sfml-dev.org/tutorials/2.5/
 * GCC & GNU make (probably using cygwin)

 ## Credit
 * Music / Sprite / Art credits here
 * SFML
 https://www.sfml-dev.org/index.php
 
##### Explanation of makefile
CC      = g++                                           # Compiler command
CFLAGS  = -g -std=c++14 #-Wall #-Wextra -pedantic       # Extra flags
INCLUDE = ./include/tact/                               # Include directory
COMPILE = $(CC) $(CFLAGS) -I$(INCLUDE) -c               # Compile command used
BUILD   = $(CC) $(CFLAGS) -I$(INCLUDE)                  # Build command
OUTBIN     = ./bin/tactical_rpg_demo.out                # Binary output directory and filename
LINKSFML= -lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio      # Linked SFML Libraries
LINKSTT = -L$(LIBDIR)                                                   # Library linking option variable
# source directories
SOURCE	= ./src/                                        # Main source directory
TACTSRC	= $(SOURCE)tact/                                # Game source directory

# library directories
LIBDIR  = ./lib/                                        # Main library directory
STTLIB	= $(LIBDIR)libgame.a                            # Game library file
CRDLIBPATH = $(LIBDIR)libcoordinate.a                   # Coordinate library file

# object files
TACTOBJ	= $(TACTSRC)obj/                                # Directory for game object files
SRCOBJ	= $(SOURCE)obj/                                 # Directory for main object files

# execution object dependencies to be compiled
OUTBINDEPS	= $(SRCOBJ)main.o
LIBDEP	= $(TACTOBJ)Selector.o $(TACTOBJ)Game.o $(TACTOBJ)Exception.o $(TACTOBJ)MainMenu.o $(TACTOBJ)Menu.o $(TACTOBJ)CoolText.o $(TACTOBJ)SpawnPoint.o $(TACTOBJ)Player.o $(TACTOBJ)Ninja.o $(TACTOBJ)CharacterMap.o $(TACTOBJ)Sidebar.o $(TACTOBJ)Sprite.o $(TACTOBJ)VertexMap.o $(TACTOBJ)Mage.o $(TACTOBJ)Tank.o $(TACTOBJ)Character.o
LIBCORD = $(SRCOBJ)Coordinate.o $(SRCOBJ)Cursor.o

# PHONY commands
.PHONY : clean all run

# Rule to create the primary executable
$(OUTBIN) : $(OUTBINDEPS) $(STTLIB) $(CRDLIBPATH)
	$(BUILD) $(OUTBINDEPS) $(LINKSFML) $(STTLIB) $(CRDLIBPATH) -o $(OUTBIN)
	@echo './bin/somethingTactics.out' is built!

# Linking the coordinate library using ar
$(CRDLIBPATH) : $(LIBCORD)
	ar r $(CRDLIBPATH) $(LIBCORD)
	
# Linking the game library using ar
$(STTLIB) : $(LIBDEP)
	ar r $(STTLIB) $(LIBDEP)

# Compile source code into objects files
$(SRCOBJ)main.o : $(SOURCE)main.cpp
	$(COMPILE) $(SOURCE)main.cpp -o $(SRCOBJ)main.o

$(TACTOBJ)Selector.o : $(TACTSRC)Selector.cpp
	$(COMPILE) $(TACTSRC)Selector.cpp -o $(TACTOBJ)Selector.o

$(TACTOBJ)Menu.o : $(TACTSRC)Menu.cpp
	$(COMPILE) $(TACTSRC)Menu.cpp -o $(TACTOBJ)Menu.o

$(TACTOBJ)Player.o : $(TACTSRC)Player.cpp
	$(COMPILE) $(TACTSRC)Player.cpp -o $(TACTOBJ)Player.o

$(TACTOBJ)VertexMap.o : $(TACTSRC)VertexMap.cpp
	$(COMPILE) $(TACTSRC)VertexMap.cpp -o $(TACTOBJ)VertexMap.o

$(TACTOBJ)Character.o : $(TACTSRC)Character.cpp
	$(COMPILE) $(TACTSRC)Character.cpp -o $(TACTOBJ)Character.o

$(TACTOBJ)Knight.o : $(TACTSRC)Knight.cpp
	$(COMPILE) $(TACTSRC)Knight.cpp -o $(TACTOBJ)Knight.o

$(TACTOBJ)Mage.o : $(TACTSRC)Mage.cpp
	$(COMPILE) $(TACTSRC)Mage.cpp -o $(TACTOBJ)Mage.o

$(TACTOBJ)Ninja.o : $(TACTSRC)Ninja.cpp
	$(COMPILE) $(TACTSRC)Ninja.cpp -o $(TACTOBJ)Ninja.o

$(TACTOBJ)SpawnPoint.o : $(TACTSRC)SpawnPoint.cpp
	$(COMPILE) $(TACTSRC)SpawnPoint.cpp -o $(TACTOBJ)SpawnPoint.o

$(TACTOBJ)Tank.o : $(TACTSRC)Tank.cpp
	$(COMPILE) $(TACTSRC)Tank.cpp -o $(TACTOBJ)Tank.o

$(TACTOBJ)Sprite.o : $(TACTSRC)Sprite.cpp
	$(COMPILE) $(TACTSRC)Sprite.cpp -o $(TACTOBJ)Sprite.o

$(TACTOBJ)Sidebar.o : $(TACTSRC)Sidebar.cpp
	$(COMPILE) $(TACTSRC)Sidebar.cpp -o $(TACTOBJ)Sidebar.o

$(TACTOBJ)CharacterMap.o : $(TACTSRC)CharacterMap.cpp
	$(COMPILE) $(TACTSRC)CharacterMap.cpp -o $(TACTOBJ)CharacterMap.o

$(TACTOBJ)CoolText.o : $(TACTSRC)CoolText.cpp
	$(COMPILE) $(TACTSRC)CoolText.cpp -o $(TACTOBJ)CoolText.o

$(TACTOBJ)Game.o : $(TACTSRC)Game.cpp
	$(COMPILE) $(TACTSRC)Game.cpp -o $(TACTOBJ)Game.o

$(TACTOBJ)MainMenu.o : $(TACTSRC)MainMenu.cpp
	$(COMPILE) $(TACTSRC)MainMenu.cpp -o $(TACTOBJ)MainMenu.o

$(SRCOBJ)Coordinate.o : $(SOURCE)Coordinate.cpp
	$(COMPILE) $(SOURCE)Coordinate.cpp -o $(SRCOBJ)Coordinate.o

$(SRCOBJ)Cursor.o : $(SOURCE)Cursor.cpp
	$(COMPILE) $(SOURCE)Cursor.cpp -o $(SRCOBJ)Cursor.o

$(TACTOBJ)Exception.o : $(TACTSRC)Exception.cpp
	$(COMPILE) $(TACTSRC)Exception.cpp -o $(TACTOBJ)Exception.o

# clean phony command to remove all generated files and libraries.
clean :
	@rm -f $(SRCOBJ)*.o
	@rm -f $(LIBOBJ)*.o
	@rm -f $(TACTSRC)/obj/*.o
	@rm -f $(STTLIB)
	@rm -f $(CRDLIBPATH)
	@rm -f $(OUTBIN)

all : clean $(OUTBIN)
# Execute the command
run : $(OUTBIN)
	@$(OUTBIN) #run program

