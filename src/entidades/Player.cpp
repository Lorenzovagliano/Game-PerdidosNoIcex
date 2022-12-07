#include "Player.hpp"


Player::Player(float cordX, float cordY){
    this->_sprite.setPosition(sf::Vector2f(cordX * 64, cordY * 64));
    this->_up = false;
    this->_down = false;
    this->_right = false;
    this->_left = false;
    this->_movimentos = 0;
    this->possuiTesoura = false;
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
    if(this->_right)
        movement.x += 64;
    if(this->_left)
        movement.x -= 64;


    //VERIFICANDO SE O JOGADOR NÃO QUER SE MOVER PARA UMA PAREDE
    sf::Vector2f nextPlayerPosition = this->_sprite.getPosition() + movement;
    if(map.get_tiles()[nextPlayerPosition.x / 64][nextPlayerPosition.y / 64]->_isPassable == false)
            return;

    //ITERANDO PELOS OBJETOS VERIFICANDO SE UM OU MAIS DELES ESTÃO NO TILE PARA O QUAL O JOGADOR SE MOVE
    bool interagiu = false;
    for(int o = 0; o < map.get_objetos().size(); o++)
    {
        sf::Vector2f nextObjectPosition = map.get_objetos()[o]->_sprite.getPosition() + movement;

        if(map.get_objetos()[o]->_sprite.getPosition() == nextPlayerPosition) 
        {
            switch (map.get_objetos()[o]->get_id())
            {
            case 2:
                interagirMesa(o, map, nextObjectPosition, movement);
                interagiu = true;
                break;
            
            case 3:
                interagirCaixa(o, map, nextObjectPosition, movement);
                interagiu = true;
                break;

            case 4:
                interagirFantasma(o, map, movement, interagiu);
                interagiu = true;
                break;

            case 5:
                interagirControle(map, movement);
                interagiu = true;
                break;

            case 6:
                interagirTesoura(o, map, movement);
                break;

            case 7:
                interagirTeia(o, map, movement);
                interagiu = true;
                break;

            }
        }
    }

    if(interagiu == true)
        return;

    //não havia obstaculos no tile que o jogador tentou se mover
    this->_movimentos++;
    this->_sprite.move(movement);

}



void Player::interagirMesa(int nMesa, GameWorld &map, sf::Vector2f nextObjectPosition, sf::Vector2f movement)
{
    //CASO O JOGADOR INTERAJA COM A MESA ESTANDO SOB UM FANTASMA
    for(int o = 0; o<map.get_objetos().size(); o++)
        if(_sprite.getPosition() == map.get_objetos()[o]->_sprite.getPosition() && map.get_objetos()[o]->get_id() == 4)
            this->_movimentos++;

    //CASO A MESA QUERIA OCUPAR A POSIÇÃO DE UMA PAREDE
    if(map.get_tiles()[nextObjectPosition.x / 64][nextObjectPosition.y / 64]->_isPassable == false)
        return;

    //CASO A MESA QUEIRA OCUPAR A POSIÇÃO DE OUTRO OBJETO
    for(int o = 0; o<map.get_objetos().size(); o++)
    {
        if(nextObjectPosition == map.get_objetos()[o]->_sprite.getPosition() && map.get_objetos()[o]->get_id() == 4)
        {
            this->_movimentos++;
            map.get_objetos()[nMesa]->_sprite.move(movement);
            return;
        }
        if(nextObjectPosition == map.get_objetos()[o]->_sprite.getPosition())
            return;
    }

    //PODEMOS EMPURRAR A MESA
    this->_movimentos++;
    map.get_objetos()[nMesa]->_sprite.move(movement);
              
}                             
                           


void Player::interagirCaixa(int nCaixa, GameWorld &map, sf::Vector2f nextObjectPosition, sf::Vector2f movement){
    
    //CASO O JOGADOR INTERAJA COM A CAIXA ESTANDO SOB UM FANTASMA
    for(int o = 0; o<map.get_objetos().size(); o++)
        if(_sprite.getPosition() == map.get_objetos()[o]->_sprite.getPosition() && map.get_objetos()[o]->get_id() == 4)
            this->_movimentos++;

    //CASO A CAIXA QUEIRA OCUPAR A POSIÇÃO DE UMA PAREDE
    if(map.get_tiles()[nextObjectPosition.x / 64][nextObjectPosition.y / 64]->_isPassable == false)
    {
        this->_movimentos++;
        map.get_objetos()[nCaixa]->_isPassable == true;
        map.get_objetos()[nCaixa]->setUpSprite("tiles/invisible.png");
        map.get_objetos()[nCaixa]->_sprite.setPosition(-9999, -9999);
        return;
    }

    //CASO A CAIXA QUEIRA OCUPAR A POSIÇÃO DE OUTRO OBJETO
    for(int o = 0; o<map.get_objetos().size(); o++)
    {
        if((nextObjectPosition == map.get_objetos()[o]->_sprite.getPosition()) && (map.get_objetos()[o]->get_id() == 4))
        {
            this->_movimentos++;
            map.get_objetos()[nCaixa]->_isPassable == true;
            map.get_objetos()[nCaixa]->setUpSprite("tiles/invisible.png");
            map.get_objetos()[nCaixa]->_sprite.setPosition(-9999, -9999);
            return;
        }
        if((nextObjectPosition == map.get_objetos()[o]->_sprite.getPosition()) && (map.get_objetos()[o]->_isPassable == false))
        {
            this->_movimentos++;
            map.get_objetos()[nCaixa]->_isPassable == true;
            map.get_objetos()[nCaixa]->setUpSprite("tiles/invisible.png");
            map.get_objetos()[nCaixa]->_sprite.setPosition(-9999, -9999);
            return;
        }
        if((nextObjectPosition == map.get_objetos()[o]->_sprite.getPosition()) && (map.get_objetos()[o]->_isPassable == true))
            return;
    }

    //PODEMOS EMPURRAR A CAIXA
    this->_movimentos++;
    map.get_objetos()[nCaixa]->_sprite.move(movement);
                          
}



void Player::interagirFantasma(int nFantasma, GameWorld &map, sf::Vector2f movement, bool jaInteragiu)
{
    if(jaInteragiu == true)
        return;
    
    for(int o = 0; o<map.get_objetos().size(); o++)
    {
        if(map.get_objetos()[nFantasma]->_sprite.getPosition() == map.get_objetos()[o]->_sprite.getPosition())
        {
            if((map.get_objetos()[o]->get_id() != 2) && (map.get_objetos()[o]->get_id() != 3))
            {
                this->_movimentos = this->_movimentos + 2;
                this->_sprite.move(movement);
                return;
            }
        }
    }
}



void Player::interagirControle(GameWorld &map, sf::Vector2f movement)
{
    this->_movimentos++;
    this->_sprite.move(movement);
    map.ganhou = true;
}



void Player::interagirTesoura(int nTesoura, GameWorld &map, sf::Vector2f movement)
{
    this->possuiTesoura = true;
    map.get_objetos()[nTesoura]->setUpSprite("tiles/invisible.png");
    map.get_objetos()[nTesoura]->_sprite.setPosition(-9999, -9999);
}



void Player::interagirTeia(int nTeia, GameWorld &map, sf::Vector2f movement){
   if(possuiTesoura == true) {
        _movimentos++;
        map.get_objetos()[nTeia]->_isPassable == true;
        map.get_objetos()[nTeia]->setUpSprite("tiles/invisible.png");
        map.get_objetos()[nTeia]->_sprite.setPosition(-9999, -9999);
        this->_sprite.move(movement);
        return;
   }
}
