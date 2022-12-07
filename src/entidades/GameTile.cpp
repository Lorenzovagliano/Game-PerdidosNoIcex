#include "GameTile.hpp"

GameTile::GameTile(int id, float cordX, float cordY){
    if(id == 0){
        this->_id = 0;
        this->_textureName = "tiles/chao.png";
        this->_isPassable = true;
        this->_isExit = false;
    }
    else if (id == -1){
        this->_id = -1;
        this->_textureName = "tiles/paredebottom.png";
        this->_isPassable = false;
        this->_isExit = false;
    }
    else if (id == -2) {
        this->_id = -2;
        this->_textureName = "tiles/paredetop.png";
        this->_isPassable = false;
        this->_isExit = false;
    }
    else if (id == -3) {
        this->_id = -3;
        this->_textureName = "tiles/leftwall.png";
        this->_isPassable = false;
        this->_isExit = false;
    }
    else if (id == -4) {
        this->_id = -4;
        this->_textureName = "tiles/rightwall.png";
        this->_isPassable = false;
        this->_isExit = false;
    } else if (id == -5) {
        this->_id = -5;
        this->_textureName = "tiles/invisible.png";
        this->_isPassable = false;
        this->_isExit = false;
    }
    else if(id == 1){
        this->_id = 1;
        this->_textureName = "tiles/wall.png";
        this->_isPassable = false;
        this->_isExit = false;
    }
    else if(id == 2){
        this->_id = 2;
        this->_textureName = "tiles/mesa.png";
        this->_isPassable = false;
        this->_isExit = false;
    }
    else if(id == 3){
        this->_id = 3;
        this->_textureName = "tiles/box.png";
        this->_isPassable = false;
        this->_isExit = false;
    }
    else if(id == 4){
        this->_id = 4;
        this->_textureName = "tiles/ghost.png";
        this->_isPassable = true;
        this->_isExit = false;
    }
    else if(id == 5){
        this->_id = 5;
        this->_textureName = "tiles/controle.png";
        this->_isPassable = false;
        this->_isExit = true;
    }
    else if(id == 6){
        this->_id = 6;
        this->_textureName = "tiles/tesoura.png";
        this->_isPassable = true;
        this->_isExit = false;
    }
    else if(id == 7){
        this->_id = 7;
        this->_textureName = "tiles/teia.png";
        this->_isPassable = false;
        this->_isExit = false;
    }
    else{
        this->_id = 1;
        this->_textureName = "tiles/error.png";
        this->_isPassable = true;
        this->_isExit = false;
    }
    if(!setUpSprite(this->_textureName)){
        return;
    }

    this->_pos = sf::Vector2f(cordX, cordY);
    this->_sprite.setPosition(this->_pos);
}

int GameTile::get_id(){
    return this->_id;
}

std::string GameTile::get_textureName(){
    return this->_textureName;
}

bool GameTile::get_isPassable(){
    return this->_isPassable;
}

bool GameTile::setUpSprite(std::string textureName){
    if(!this->_texture.loadFromFile(textureName)){
        return false;
    }

    this->_texture.setSmooth(true);
    this->_sprite.setTexture(this->_texture);
    this->_sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));

    return true;
}
