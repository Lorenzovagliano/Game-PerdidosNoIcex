#include <SFML/Graphics.hpp>
#include "GameTile.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>

#ifndef GAMEWORLD_H
#define GAMEWORLD_H


/**
 *  Classe responsável por representar uma fase
 */
class GameWorld{
    private:
        /**
         *  id que representa a fase
         */
        int _idFase;

        /**
         *  Tamanho das laterais da matriz que gera o GameWorld
         */
        int _gridLenght;

        /**
         *  Coleção que armazena os tiles de fundo do GameWorld
         */
        std::vector<std::vector<GameTile*>> _tiles;

        /**
         *  Coleção que armazena os objetos a serem mostrados acima dos tiles de fundo do GameWorld
         */
        std::vector<GameTile*> _objetos;

        /**
         *  Método que inicia o estado inicial da fase
         *  @param idFase O id da fase
         */
        void setUpInitialState(int idFase);
        
        /**
         *  Método que inicia os objetos na fase
         *  @param idFase O id da fase
         */
        void setUpEnemyPositions(int idFase);

        /**
         *  Método que inicia os tiles na fase
         *  @param idFase O id da fase
         */
        void setUpTiles(int idFase);

    public:
        /**
         *  Variável do tipo bool que define se o level foi vencido pelo jogador
         */
        bool ganhou;

        /**
         *  Número máximo de movimentos permitido pela fase
         */
        int _maxMovements;

        /**
         *  Coordenada x inicial do player na fase
         */
        int _initialPlayerPosX;

        /**
         *  Coordenada y inicial do player na fase
         */
        int _initialPlayerPosY;

        /**
         *  Construtor de GameWorld
         */
        GameWorld(int idFase);

        /**
         *  Destrutor de GameWorld
         */
        ~GameWorld();

        /**
         *  Método getter para o atributo gridlenght
         */
        int get_gridLenght();

        /**
         *  Método getter para o atributo _tiles
         */
        std::vector<std::vector<GameTile*>> get_tiles();

        /**
         *  Método getter para o atributo _objetos
         */
        std::vector<GameTile*> get_objetos();
     
};

#endif