CC      = g++ -g
CFLAGS  = -std=c++14 #-Wall #-Wextra -pedantic
INCLUDE = ./include/tact/
COMPILE = $(CC) $(CFLAGS) -I$(INCLUDE) -c
BUILD   = $(CC) $(CFLAGS) -I$(INCLUDE)
OUTBIN     = ./bin/tactical_rpg_demo.out
LINKSFML= -lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio
LINKSTT = -L$(LIBDIR)
# source directories
SOURCE	= ./src/
TACTSRC	= $(SOURCE)tact/

# library directories
LIBSRC  = ./libsrc/
LIBDIR  = ./lib/
STTLIB	= $(LIBDIR)libgame.a
CRDLIBPATH = $(LIBDIR)libcoordinate.a

# object files
TACTOBJ	= $(TACTSRC)obj/
SRCOBJ	= $(SOURCE)obj/

# execution dependencies
OUTBINDEPS	= $(SRCOBJ)main.o  $(SRCOBJ)Music.o
LIBDEP	= $(TACTOBJ)Selector.o $(TACTOBJ)Game.o $(TACTOBJ)Exception.o $(TACTOBJ)MainMenu.o $(TACTOBJ)Menu.o $(TACTOBJ)CoolText.o $(TACTOBJ)SpawnPoint.o $(TACTOBJ)Player.o $(TACTOBJ)Ninja.o $(TACTOBJ)CharacterMap.o $(TACTOBJ)Sidebar.o $(TACTOBJ)Sprite.o $(TACTOBJ)VertexMap.o $(TACTOBJ)Mage.o $(TACTOBJ)Tank.o $(TACTOBJ)Character.o
LIBCORD = $(SRCOBJ)Coordinate.o $(SRCOBJ)Cursor.o

.PHONY : clean all run

# Rule to create the primary executable
$(OUTBIN) : $(OUTBINDEPS) $(STTLIB) $(CRDLIBPATH)
	$(BUILD) $(OUTBINDEPS) $(LINKSFML) $(STTLIB) $(CRDLIBPATH) -o $(OUTBIN)
	@echo './bin/somethingTactics.out' is built!

$(CRDLIBPATH) : $(LIBCORD)
	ar r $(CRDLIBPATH) $(LIBCORD)

$(STTLIB) : $(LIBDEP)
	ar r $(STTLIB) $(LIBDEP)

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

$(SRCOBJ)Music.o : $(SOURCE)Music.cpp
	$(COMPILE) $(SOURCE)Music.cpp -o $(SRCOBJ)Music.o

$(TACTOBJ)Exception.o : $(TACTSRC)Exception.cpp
	$(COMPILE) $(TACTSRC)Exception.cpp -o $(TACTOBJ)Exception.o

clean :
	@rm -f $(SRCOBJ)*.o
	@rm -f $(LIBOBJ)*.o
	@rm -f $(TACTSRC)/obj/*.o
	@rm -f $(STTLIB)
	@rm -f $(CRDLIBPATH)
	@rm -f $(OUTBIN)

all : clean $(OUTBIN)

run : $(OUTBIN)
	@$(OUTBIN) #run program
