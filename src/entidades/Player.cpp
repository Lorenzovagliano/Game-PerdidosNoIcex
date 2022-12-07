#include "Player.hpp"

Player::Player(float cordX, float cordY){
    this->_sprite.setPosition(sf::Vector2f(cordX * 64, cordY * 64));
    this->_up = false;
    this->_down = false;
    this->_right = false;
    this->_left = false;
    this->_movimentos = 0;
}

void Player::drawTo(sf::RenderWindow &window){
    window.draw(this->_sprite);
}

void Player::processEvents(sf::Keyboard::Key key, bool checkPressed){
    if (checkPressed == true){
        if(key == sf::Keyboard::W)
            this->_up = true;
        if(key == sf::Keyboard::S)
            this->_down = true;
        if(key == sf::Keyboard::D)
            this->_right = true;
        if(key == sf::Keyboard::A)
            this->_left = true;
    }
    if(checkPressed == false){
        this->_up = false;
        this->_down = false;
        this->_right = false;
        this->_left = false;
    }
}

void Player::update(GameWorld& map)
{
    sf::Vector2f movement;
    if(this->_up)
        movement.y -= 64;
    if(this->_down)
        movement.y += 64;
    if(this->_right){
        movement.x += 64;
    }
    if(this->_left)
        movement.x -= 64;

    sf::Vector2f nextPlayerPosition = this->_sprite.getPosition() + movement;
    for(int i = 0; i < map.get_gridLenght(); i++){
        for(int j = 0; j < map.get_gridLenght(); j++){
            for(int k = 0; k < map.get_objetos().size(); k++){
                sf::Vector2f nextObjectPosition = map.get_objetos()[k]->_sprite.getPosition() + movement;
                //Caso o jogador queira ocupar a posição de um tile
                if(nextPlayerPosition == map.get_tiles()[i][j]->_sprite.getPosition()){
                    //Caso o jogador queira ocupar a posição de um tile não passável
                    if(map.get_tiles()[i][j]->_isPassable == false){
                        return;
                    }
                }

                //Caso o jogador queira ocupar a posição de um objeto
                if(nextPlayerPosition == map.get_objetos()[k]->_sprite.getPosition()){
                    //Caso o jogador queira ocupar a posição do objetivo
                    if(map.get_objetos()[k]->_isExit == true){
                        this->_movimentos++;
                        this->_sprite.move(movement);
                        map.ganhou = true;
                        return;
                    }

                    //Caso o jogador queira ocupar a posição da caixa
                    if(map.get_objetos()[k]->get_id() == 3){ //id = 3 é a caixa
                        if(nextObjectPosition == map.get_tiles()[i][j]->_sprite.getPosition()){
                            //Caso o jogador queira ocupar a posição da caixa e ele está em um armadilha
                            for(int l = 0; l<map.get_objetos().size(); l++){
                                if(this->_sprite.getPosition() == map.get_objetos()[l]->_sprite.getPosition()){
                                    if(map.get_objetos()[l]->get_id() == 4){
                                        this->_movimentos++;
                                    }
                                }
                            }
                            //Caso a caixa queira ocupar a posição de um Tile não passável
                            if(map.get_tiles()[i][j]->_isPassable == false){
                                this->_movimentos++;
                                map.get_objetos()[k]->_isPassable == true;
                                map.get_objetos()[k]->setUpSprite("images/invisible.png");
                                map.get_objetos()[k]->_sprite.setPosition(i*1333, j*1333);
                                return;
                            }
                            //Caso a caixa queira ocupar a posição de um Tile passável
                            if(map.get_tiles()[i][j]->_isPassable == true){
                                this->_movimentos++;
                                map.get_objetos()[k]->_sprite.move(movement);
                                return;
                            }
                        }

                        //Caso a caixa queira ocupar a posição de outro objeto
                        for(int l = 0; l<map.get_objetos().size(); l++){
                            if(nextObjectPosition == map.get_objetos()[l]->_sprite.getPosition()){
                                //Caso a caixa queira ocupar a posição de uma armadilha
                                if(map.get_objetos()[l]->get_id() == 4){ //id = 4 é a armadilha
                                    this->_movimentos++;
                                    map.get_objetos()[k]->_isPassable == true;
                                    map.get_objetos()[k]->setUpSprite("images/invisible.png");
                                    map.get_objetos()[k]->_sprite.setPosition(i*1333, j*1333);
                                    return;
                                }

                                //Caso a caixa queira ocupar a posição de um objeto não passável
                                if(map.get_objetos()[l]->_isPassable == false){
                                    this->_movimentos++;
                                    map.get_objetos()[k]->_isPassable == true;
                                    map.get_objetos()[k]->setUpSprite("images/invisible.png");
                                    map.get_objetos()[k]->_sprite.setPosition(i*1333, j*1333);
                                    return;
                                }
                            }
                        }
                    }

                    //Caso o jogador queira ocupar a posição da pedra
                    if(map.get_objetos()[k]->get_id() == 2){
                        if(nextObjectPosition == map.get_tiles()[i][j]->_sprite.getPosition()){
                            for(int l = 0; l<map.get_objetos().size(); l++){
                                //Caso o jogador queira ocupar a posição da pedra e o jogador está em um armadilha
                                if(this->_sprite.getPosition() == map.get_objetos()[l]->_sprite.getPosition()){
                                    if(map.get_objetos()[l]->get_id() == 4){
                                        this->_movimentos++;
                                    }
                                }
                                //Caso a pedra queira ocupar a posição de outro objeto
                                if(nextObjectPosition == map.get_objetos()[l]->_sprite.getPosition()){
                                    //Caso a pedra queira ocupar a posição de um objeto passável
                                    if(map.get_objetos()[l]->_isPassable == true){
                                        this->_movimentos++;
                                        map.get_objetos()[k]->_sprite.move(movement);
                                        return;
                                    }

                                    //Caso a pedra queira ocupar a posição de um objeto não passável
                                    if(map.get_objetos()[l]->_isPassable == false){
                                        return;
                                    }
                                }
                            }
                            
                            //Caso a pedra queira ocupar a posição de um Tile não passável
                            if(map.get_tiles()[i][j]->_isPassable == false){
                                return;
                            }
                            //Caso a pedra queira ocupar a posição de um Tile passável
                            if(map.get_tiles()[i][j]->_isPassable == true){
                                this->_movimentos++;
                                map.get_objetos()[k]->_sprite.move(movement);
                                return;
                            }
                        }   
                    }
                    //Caso o jogador queira ocupar a posição de uma armadilha
                    if(map.get_objetos()[k]->get_id() == 4){
                        if(nextObjectPosition == map.get_tiles()[i][j]->_sprite.getPosition()){
                            for(int l = 0; l<map.get_objetos().size(); l++){
                                //Caso não haja uma pedra em cima da armadilha
                                if(map.get_objetos()[k]->_sprite.getPosition() == map.get_objetos()[l]->_sprite.getPosition()){
                                    if((map.get_objetos()[l]->get_id() != 2) && (map.get_objetos()[l]->get_id() != 3)){
                                        this->_movimentos = this->_movimentos + 2;
                                        this->_sprite.move(movement);
                                        return;
                                    }
                                    //Caso haja uma pedra em cima da armadilha
                                    else{
                                        this->_movimentos = this->_movimentos + 2;
                                        map.get_objetos()[l]->_sprite.move(movement);
                                        return;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    //Caso o jogador queira ocupar a posição de um tile passável
    this->_movimentos++;
    this->_sprite.move(movement);
}