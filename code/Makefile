CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = biquadris
OBJECTS = main.o command.o cmdl.o game.o object.o iobject.o jobject.o lobject.o sobject.o zobject.o tobject.o oobject.o singleobject.o level.o levelzero.o levelone.o leveltwo.o levelthree.o levelfour.o absplayer.o player.o cell.o absdisplay.o textdisplay.o graphdisplay.o window.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}