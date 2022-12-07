CC=g++
CFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
TARGET=PerdidosNoIcex.exe

BUILD_DIR = ./build
SRC_DIR = ./src
INCLUDE_DIR = ./include
ENT_DIR = ./src/entidades

${TARGET}:  ${BUILD_DIR}/GameTile.o ${BUILD_DIR}/GameWorld.o ${BUILD_DIR}/levelmenu.o ${BUILD_DIR}/menu.o ${BUILD_DIR}/Player.o ${BUILD_DIR}/main.o

	${CC} ${BUILD_DIR}/main.o -o ${TARGET} ${BUILD_DIR}/GameTile.o ${BUILD_DIR}/GameWorld.o ${BUILD_DIR}/levelmenu.o ${BUILD_DIR}/menu.o ${BUILD_DIR}/Player.o ${CFLAGS}


${BUILD_DIR}/GameTile.o: ${INCLUDE_DIR}/GameTile.hpp ${ENT_DIR}/GameTile.cpp

	${CC} -I ${INCLUDE_DIR}/ -c ${ENT_DIR}/GameTile.cpp -o ${BUILD_DIR}/GameTile.o ${CFLAGS}

${BUILD_DIR}/GameWorld.o: ${INCLUDE_DIR}/GameWorld.hpp ${ENT_DIR}/GameWorld.cpp 

	${CC} -I ${INCLUDE_DIR}/ -c ${ENT_DIR}/GameWorld.cpp -o ${BUILD_DIR}/GameWorld.o ${CFLAGS}

${BUILD_DIR}/levelmenu.o: ${INCLUDE_DIR}/levelmenu.hpp ${ENT_DIR}/levelmenu.cpp  

	${CC} -I ${INCLUDE_DIR}/ -c ${ENT_DIR}/levelmenu.cpp -o ${BUILD_DIR}/levelmenu.o ${CFLAGS}

${BUILD_DIR}/menu.o: ${INCLUDE_DIR}/menu.hpp ${ENT_DIR}/menu.cpp 

	${CC} -I ${INCLUDE_DIR}/ -c ${ENT_DIR}/menu.cpp -o ${BUILD_DIR}/menu.o ${CFLAGS}

${BUILD_DIR}/Player.o: ${INCLUDE_DIR}/Player.hpp ${ENT_DIR}/Player.cpp 

	${CC} -I ${INCLUDE_DIR}/ -c ${ENT_DIR}/Player.cpp -o ${BUILD_DIR}/Player.o ${CFLAGS}

${BUILD_DIR}/main.o: ${INCLUDE_DIR}/GameTile.hpp ${INCLUDE_DIR}/GameWorld.hpp ${INCLUDE_DIR}/levelmenu.hpp ${INCLUDE_DIR}/menu.hpp ${INCLUDE_DIR}/Player.hpp ${SRC_DIR}/main.cpp

	${CC} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o ${CFLAGS}

clean:
	rm -f ${BUILD_DIR}/*