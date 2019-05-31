###############################################################
# Program:
#     Milestone 06, Moon Lander
#     Brother Dudley, CS165
# Author:
#     Drazen Lucic
# Summary:
#     This is the first milestone of the Moon Lander project.
#     It provides the code to compile and draw a lander on the screen.
# Above and Beyond
#     When you submit your final project (not for milestones),
#     list anything here that you did to go above and beyond
#     the base requirements for your project.
###############################################################


TARFILE = moonLanderMS.tar

ifeq ($(OS), Windows_NT)
	LFLAGS =  -lopengl32 -lglew32 -lfreeglut -lglu32
	OUTPUT = a.exe
	DEL = del
else
	LFLAGS = -lglut -lGLU -lGL
	OUTPUT = a.out
	DEL = rm -f
endif

###############################################################
# Build the main Moon Lander game
###############################################################
$(OUTPUT): driver.o ground.o game.o uiInteract.o uiDraw.o point.o lander.o
	g++ driver.o ground.o game.o uiInteract.o uiDraw.o point.o lander.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
#    lander.o      Handles the lander (display, thrust, flight status)
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h point.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h point.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

ground.o: ground.cpp ground.h uiDraw.h point.h
	g++ -c ground.cpp

game.o: game.h game.cpp uiDraw.h uiInteract.h point.h ground.h lander.h
	g++ -c game.cpp

driver.o: driver.cpp game.h uiInteract.h
	g++ -c driver.cpp

lander.o: lander.cpp lander.h velocity.h point.h uiDraw.h
	g++ -c lander.cpp

###############################################################
# General rules
###############################################################
clean:
	$(DEL) $(OUTPUT) *.o *.tar

tar:
	tar -cvf $(TARFILE) *.cpp *.h makefile

submit:
	/mnt/local/submit/submit.pl $(TARFILE)
