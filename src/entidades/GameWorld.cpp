#include "GameWorld.hpp"

GameWorld::GameWorld(int idFase){
    setUpInitialState(idFase);
}

GameWorld::~GameWorld(){
    //Deleta Tiles
    for(int i = 0; i < this->get_gridLenght(); i++){
        this->_tiles[i].resize(get_gridLenght());
        for(int j = 0; j < this->get_gridLenght(); j++){
            delete this->_tiles[i][j];
        }
    }

    //Deleta Objetos
    for(int i = 0; i < this->_objetos.size(); i++){
        delete this->_objetos[i];
    }
    std::cout << "Deletado o gameWorld\n";
}

int GameWorld::get_gridLenght(){
    return this->_gridLenght;
}

std::vector<std::vector<GameTile*>> GameWorld::get_tiles(){
    return this->_tiles;
}

std::vector<GameTile*> GameWorld::get_objetos(){
    return this->_objetos;
}

void GameWorld::setUpInitialState(int idFase){
    ganhou = false;
    setUpEnemyPositions(idFase);
    setUpTiles(idFase);
}

void GameWorld::setUpEnemyPositions(int idFase){
    this->_objetos.clear();

    std::ifstream newFile;
    if(idFase == 1){
        newFile.open("levels/level1Objetos.txt");
        if(newFile.fail()) {
            std::cout << "Unable to open file";
            return;
        } 
    }
    else if(idFase == 2){
        newFile.open("levels/level2Objetos.txt");
        if(newFile.fail()) {
            std::cout << "Unable to open file";
            return;
        } 
    }
    else if(idFase == 3){
        newFile.open("levels/level3Objetos.txt");
        if(newFile.fail()) {
            std::cout << "Unable to open file";
            return;
        } 
    }
    else if(idFase == 4){
        newFile.open("levels/level4Objetos.txt");
        if(newFile.fail()) {
            std::cout << "Unable to open file";
            return;
        } 
    }
    else{
        std::cout << "Level not available\n";
        return;
    }

    int id;
    int cordX;
    int cordY;
    newFile >> this->_gridLenght;
    newFile >> this->_initialPlayerPosX;
    newFile >> this->_initialPlayerPosY;
    newFile >> this->_maxMovements;
    while(newFile.good()){
        newFile >> id;
        newFile >> cordX;
        newFile >> cordY;
        this->_objetos.push_back(new GameTile(id, cordX * 64, cordY * 64));
    }

    newFile.close();

}

void GameWorld::setUpTiles(int idFase){
    this->_tiles.clear();

    std::ifstream newFile;
    if(idFase == 1){
        newFile.open("levels/level1.txt");
        if(newFile.fail()) {
            std::cout << "Unable to open file";
            return;
        } 
    }
    else if(idFase == 2){
        newFile.open("levels/level2.txt");
        if(newFile.fail()) {
            std::cout << "Unable to open file";
            return;
        } 
    }
    else if(idFase == 3){
        newFile.open("levels/level3.txt");
        if(newFile.fail()) {
            std::cout << "Unable to open file";
            return;
        } 
    }
    else if(idFase == 4){
        newFile.open("levels/level4.txt");
        if(newFile.fail()) {
            std::cout << "Unable to open file";
            return;
        } 
    }
    else{
        std::cout << "Level not available\n";
        return;
    }

    int id;
    this->_tiles.resize(get_gridLenght());
    while(newFile.good()){
        for(int i = 0; i < this->get_gridLenght(); i++){
            this->_tiles[i].resize(get_gridLenght());
            for(int j = 0; j < this->get_gridLenght(); j++){
                newFile >> id;
                this->_tiles[i][j] = new GameTile(id, i*64, j*64);
            }
        }
    }
    newFile.close();
}