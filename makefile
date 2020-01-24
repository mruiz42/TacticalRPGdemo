CC      = g++
FCLAGS  = -std=c++20  -Wall   -Wextra -pedantic
INCLUDE = ./include/
COMPILE = $(CC) $(CFLAGS) -I $(INCLUDE) -c
BUILD   = $(CC) $(CFLAGS) -I $(INCLUDE)
OUTBIN     = ./bin/somethingTactics.out
LINKSFML= -lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio
LINKSTT = -L $(LIBDIR) -l
# source directories
SOURCE	= ./src/
TACTSRC	= $(SOURCE)tact/

# library directories
LIBSRC  = ./libsrc/
LIBDIR  = ./lib/
STTLIB	= $(LIBDIR)libgame.a

# object files
TACTOBJ	= $(TACTSRC)obj/
SRCOBJ	= ./src/obj/

# execution dependencies
OUTBINDEPS	= $(SRCOBJ)main.o
# library dependencies
LIBDEP	= $(TACTOBJ)VertexMap.o $(TACTOBJ)Castle.o $(TACTOBJ)Character.o $(TACTOBJ)Knight.o $(TACTOBJ)Mage.o $(TACTOBJ)Ninja.o $(TACTOBJ)Player.o $(TACTOBJ)Spell.o $(TACTOBJ)Tank.o
	
.PHONY : clean all run

# Rule to create the primary executable
$(OUTBIN) : $(OUTBINDEPS) $(STTLIB) 
	$(BUILD) $(OUTBINDEPS) $(LINKSFML) $(LINKSTT) -o $(OUTBIN)
	@echo './bin/somethingTactics.out' is built!
	
$(STTLIB) : $(LIBDEP)
	ar r $(STTLIB) $(LIBDEP)
	
$(SRCOBJ)main.o : ./src/main.cpp
	$(COMPILE) ./src/main.cpp -o $(SRCOBJ)main.o
	
$(TACTOBJ)VertexMap.o : $(TACTSRC)VertexMap.o
	$(COMPILE) $(TACTSRC)VertexMap.cpp -o $(TACTOBJ)VertexMap.o
	
$(TACTOBJ)Castle.o : $(TACTSRC)Castle.o
	$(COMPILE) $(TACTSRC)Castle.cpp -o $(TACTOBJ)Castle.o
	
$(TACTOBJ)Character.o : $(TACTSRC)Character.o
	$(COMPILE) $(TACTSRC)Character.cpp -o $(TACTOBJ)Character.o

$(TACTOBJ)Knight.o : $(TACTSRC)Knight.o
	$(COMPILE) $(TACTSRC)Knight.cpp -o $(TACTOBJ)Knight.o

$(TACTOBJ)Mage.o : $(TACTSRC)Mage.o
	$(COMPILE) $(TACTSRC)Mage.cpp -o $(TACTOBJ)Mage.o
	
$(TACTOBJ)Ninja.o : $(TACTSRC)Ninja.o
	$(COMPILE) $(TACTSRC)Ninja.cpp -o $(TACTOBJ)Ninja.o
	
$(TACTOBJ)Player.o : $(TACTSRC)Player.o
	$(COMPILE) $(TACTSRC)Player.cpp -o $(TACTOBJ)Player.o
	
$(TACTOBJ)Spell.o : $(TACTSRC)Spell.o
	$(COMPILE) $(TACTSRC)Spell.cpp -o $(TACTOBJ)Spell.o
	
$(TACTOBJ)Tank.o : $(TACTSRC)Tank.o
	$(COMPILE) $(TACTSRC)Tank.cpp -o $(TACTOBJ)Tank.o

clean :
	@rm -f $(SRCOBJ)main.o
	@rm -f $(LIBOBJ)*.o
	@rm -f $(TACTSRC)*/obj/*.o
	@rm -f $(STTLIB)
	@rm -f $(OUTBIN)
	
all : clean $(OUTBIN)

run : $(OUTBIN)
	@$(OUTBIN) #run program
