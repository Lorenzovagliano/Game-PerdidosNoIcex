CC=g++
CFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
TARGET=PerdidosNoIcex.exe

BUILD_DIR = ./build
SRC_DIR = ./src
INCLUDE_DIR = ./include
ENT_DIR = ./src/entidades

${TARGET}:  ${BUILD_DIR}/GameTile.o ${BUILD_DIR}/GameWorld.o ${BUILD_DIR}/LevelMenu.o ${BUILD_DIR}/Menu.o ${BUILD_DIR}/Player.o ${BUILD_DIR}/main.o

	${CC} ${BUILD_DIR}/main.o -o ${TARGET} ${BUILD_DIR}/GameTile.o ${BUILD_DIR}/GameWorld.o ${BUILD_DIR}/LevelMenu.o ${BUILD_DIR}/Menu.o ${BUILD_DIR}/Player.o ${CFLAGS}


${BUILD_DIR}/GameTile.o: ${INCLUDE_DIR}/GameTile.hpp ${ENT_DIR}/GameTile.cpp

	${CC} -I ${INCLUDE_DIR}/ -c ${ENT_DIR}/GameTile.cpp -o ${BUILD_DIR}/GameTile.o ${CFLAGS}

${BUILD_DIR}/GameWorld.o: ${INCLUDE_DIR}/GameWorld.hpp ${ENT_DIR}/GameWorld.cpp 

	${CC} -I ${INCLUDE_DIR}/ -c ${ENT_DIR}/GameWorld.cpp -o ${BUILD_DIR}/GameWorld.o ${CFLAGS}

${BUILD_DIR}/LevelMenu.o: ${INCLUDE_DIR}/LevelMenu.hpp ${ENT_DIR}/LevelMenu.cpp  

	${CC} -I ${INCLUDE_DIR}/ -c ${ENT_DIR}/LevelMenu.cpp -o ${BUILD_DIR}/LevelMenu.o ${CFLAGS}

${BUILD_DIR}/Menu.o: ${INCLUDE_DIR}/Menu.hpp ${ENT_DIR}/Menu.cpp 

	${CC} -I ${INCLUDE_DIR}/ -c ${ENT_DIR}/Menu.cpp -o ${BUILD_DIR}/Menu.o ${CFLAGS}

${BUILD_DIR}/Player.o: ${INCLUDE_DIR}/Player.hpp ${ENT_DIR}/Player.cpp 

	${CC} -I ${INCLUDE_DIR}/ -c ${ENT_DIR}/Player.cpp -o ${BUILD_DIR}/Player.o ${CFLAGS}

${BUILD_DIR}/main.o: ${INCLUDE_DIR}/GameTile.hpp ${INCLUDE_DIR}/GameWorld.hpp ${INCLUDE_DIR}/LevelMenu.hpp ${INCLUDE_DIR}/Menu.hpp ${INCLUDE_DIR}/Player.hpp ${SRC_DIR}/main.cpp

	${CC} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o ${CFLAGS}

clean:
	rm -f ${BUILD_DIR}/*