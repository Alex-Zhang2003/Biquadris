CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = test
OBJECTS = TEST.o object.o iobject.o jobject.o sobject.o zobject.o tobject.o oobject.o singleobject.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}