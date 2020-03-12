CC      = g++
CFLAGS  = -std=c++17 -Wall -Wextra -pedantic
INCLUDE = ./include/tact/
COMPILE = $(CC) $(CFLAGS) -I$(INCLUDE) -c
BUILD   = $(CC) $(CFLAGS) -I$(INCLUDE)
OUTBIN     = ./bin/somethingTactics.out
LINKSFML= -lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio
LINKSTT = -L$(LIBDIR)
# source directories
SOURCE	= ./src/
TACTSRC	= $(SOURCE)tact/

# library directories
LIBSRC  = ./libsrc/
LIBDIR  = ./lib/
STTLIB	= $(LIBDIR)libgame.a
CRDLIBPATH = $(LIBDIR)libselector.a

# object files
TACTOBJ	= $(TACTSRC)obj/
SRCOBJ	= $(SOURCE)obj/

# execution dependencies
OUTBINDEPS	= $(SRCOBJ)main.o $(TACTOBJ)Game.o
LIBDEP	= $(TACTOBJ)Menu.o $(TACTOBJ)CoolText.o $(TACTOBJ)Fortress.o $(TACTOBJ)Player.o $(TACTOBJ)Ninja.o $(TACTOBJ)CharacterMap.o $(TACTOBJ)Sidebar.o $(TACTOBJ)Sprite.o $(TACTOBJ)VertexMap.o $(TACTOBJ)Knight.o $(TACTOBJ)Mage.o  $(TACTOBJ)Spell.o $(TACTOBJ)Tank.o $(TACTOBJ)Character.o
LIBCORD = $(TACTOBJ)Selector.o $(TACTOBJ)Coordinate.o $(TACTOBJ)Cursor.o

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

$(TACTOBJ)Coordinate.o : $(TACTSRC)Coordinate.cpp
	$(COMPILE) $(TACTSRC)Coordinate.cpp -o $(TACTOBJ)Coordinate.o

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

$(TACTOBJ)Fortress.o : $(TACTSRC)Fortress.cpp
	$(COMPILE) $(TACTSRC)Fortress.cpp -o $(TACTOBJ)Fortress.o
	
$(TACTOBJ)Spell.o : $(TACTSRC)Spell.cpp
	$(COMPILE) $(TACTSRC)Spell.cpp -o $(TACTOBJ)Spell.o
	
$(TACTOBJ)Tank.o : $(TACTSRC)Tank.cpp
	$(COMPILE) $(TACTSRC)Tank.cpp -o $(TACTOBJ)Tank.o

$(TACTOBJ)Sprite.o : $(TACTSRC)Sprite.cpp
	$(COMPILE) $(TACTSRC)Sprite.cpp -o $(TACTOBJ)Sprite.o

$(TACTOBJ)Cursor.o : $(TACTSRC)Cursor.cpp
	$(COMPILE) $(TACTSRC)Cursor.cpp -o $(TACTOBJ)Cursor.o

$(TACTOBJ)Sidebar.o : $(TACTSRC)Sidebar.cpp
	$(COMPILE) $(TACTSRC)Sidebar.cpp -o $(TACTOBJ)Sidebar.o

$(TACTOBJ)CharacterMap.o : $(TACTSRC)CharacterMap.cpp
	$(COMPILE) $(TACTSRC)CharacterMap.cpp -o $(TACTOBJ)CharacterMap.o

$(TACTOBJ)CoolText.o : $(TACTSRC)CoolText.cpp
	$(COMPILE) $(TACTSRC)CoolText.cpp -o $(TACTOBJ)CoolText.o

$(TACTOBJ)Speaker.o : $(TACTSRC)Speaker.cpp
	$(COMPILE) $(TACTSRC)Speaker.cpp -o $(TACTOBJ)Speaker.o

$(TACTOBJ)Game.o : $(TACTSRC)Game.cpp
	$(COMPILE) $(TACTSRC)Game.cpp -o $(TACTOBJ)Game.o

clean :
	@rm -f $(SRCOBJ)main.o
	@rm -f $(LIBOBJ)*.o
	@rm -f $(TACTSRC)/obj/*.o
	@rm -f $(STTLIB)
	@rm -f $(OUTBIN)

all : clean $(OUTBIN)

run : $(OUTBIN)
	@$(OUTBIN) #run program
