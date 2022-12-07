#include <SFML/Graphics.hpp>

#ifndef GAMETILE_H
#define GAMETILE_H

class GameTile{
    private:
        /**
         *  id que representa que tipo de tile será criado
         */
        int _id;

        /**
         *  Posição 2D do GameTile
         */
        sf::Vector2f _pos;

        /**
         *  Textura a ser utilizada pelo GameTile
         */
        sf::Texture _texture;

        /**
         *  Nome da textura a ser utilizada pelo GameTile
         */
        std::string _textureName;

    public:
        /**
         *  Variável do tipo bool que define se o GameTile é o objetivo
         */
        bool _isExit;
        /**
         *  Variável do tipo bool que define se é possível passar por cimda do GameTile
         */
        bool _isPassable;
        /**
         *  Variável do tipo bool que define se o GameTile quebra caixas caso ele ocupe sua posição
         */
        bool _quebraCaixa;
        /**
         *  Sprite da biblioteca SFML que é utilizado para desenhar a textura do GameTile na tela
         */
        sf::Sprite _sprite;

        /**
         *  Construtor de GameTile
         */
        GameTile(int id, float cordX, float cordY);

        /**
         *  Metódo getter para o atributo _id de GameTile
         */
        int get_id();

        /**
         *  Metódo getter para o atributo _textureName de GameTile
         */
        std::string get_textureName();

        /**
         *  Metódo getter para o atributo _isPassable de GameTile
         */
        bool get_isPassable();

        /**
         *  Método de GameTile responsável por assinalar a textura do GameTile ao seu sprite
         *  @param textura Textura do GameTile
         */
        bool setUpSprite(std::string textura);
        
};

#endif
