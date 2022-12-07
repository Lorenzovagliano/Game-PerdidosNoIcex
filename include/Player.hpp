#include "SFML/Graphics.hpp"
#include "GameWorld.hpp"

#ifndef PLAYER_H
#define PLAYER_H

/**
 * classe responsável por controlar os movimentos do player e estabelecer suas características
 */

class Player{
    private:
    /**
 * variável do tipo bool que confirma se o player mexerá para cima
 */
        bool _up;
         /**
 * variável do tipo bool que confirma se o player mexerá para baixo
 */
        bool _down;
         /**
 * variável do tipo bool que confirma se o player mexerá para a direita
 */
        bool _right;
         /**
 * variável do tipo bool que confirma se o player mexerá para a esquerda
 */
        bool _left;
          /**
 * variável do tipo bool que confirma se o player possui ou não o item tesoura
 */
        bool possuiTesoura;

    protected:
        /**
 * @brief Essa função é responsável por realizar a interação entre player e mesa
 * 
 * @param nMesa:índice da mesa
 * @param &map:parâmetro do tipo Gameworld, que é o level em si
 * @param nextObjectPosition:coordenada da próxima posição do objeto empurrado
 * @param movement:vetor que indica as coordenadas do player
 * @retval none
 */
        void interagirMesa(int nMesa, GameWorld &map, sf::Vector2f nextObjectPosition, sf::Vector2f movement);
        /**
 * @brief Essa função é responsável por realizar a interação entre player e caixa
 * 
 * @param nCaixa:índice da caixa
 * @param &map:parâmetro do tipo Gameworld, que é o level em si
 * @param nextObjectPosition:coordenada da próxima posição do objeto empurrado
 * @param movement:vetor que indica as coordenadas do player
 * @retval none
 */
        void interagirCaixa(int nCaixa, GameWorld &map, sf::Vector2f nextObjectPosition, sf::Vector2f movement);
        /**
 * @brief Essa função é responsável por realizar a interação entre player e fantasma
 * 
 * @param nFantasma:índice do fantasma
 * @param &map:parâmetro do tipo Gameworld, que é o level em si
 * @param movement:vetor que indica as coordenadas do player
 * @param interagiu:indica se o player interagiu ou não com o fantasma
 * @retval none
 */
        void interagirFantasma(int nFantasma, GameWorld &map, sf::Vector2f movement, bool interagiu);
          /**
 * @brief Essa função é responsável por realizar a interação entre player e controle
 * @param &map:parâmetro do tipo Gameworld, que é o level em si
 * @param movement:vetor que indica as coordenadas do player
 * @retval none
 */
        void interagirControle(GameWorld &map, sf::Vector2f movement);
         /**
 * @brief Essa função é responsável por realizar a interação entre player e tesoura
 * 
 * @param nTesoura:índice da tesoura
 * @param &map:parâmetro do tipo Gameworld, que é o level em si
 * @param movement:vetor que indica as coordenadas do player
 * @retval none
 */
        void interagirTesoura(int nTesoura, GameWorld &map, sf::Vector2f movement);
           /**
 * @brief Essa função é responsável por realizar a interação entre player e teia
 * 
 * @param nTeia:índice da tesoura
 * @param &map:parâmetro do tipo Gameworld, que é o level em si
 * @param movement:vetor que indica as coordenadas do player
 * @retval none
 */

        void interagirTeia(int nTeia, GameWorld &map, sf::Vector2f movement);

    public:
      /**
 * variável do tipo int que contabiliza o número de movimentos do player
 */
        int _movimentos;
          /**
 * nome do sprite que será do player
 */
        sf::Sprite _sprite;
  /**
 * construtor de Player
 */
        Player(float cordX, float cordY);
  /**
 * @brief Essa função é responsável por desenhar o player na window
 * 
 * @param &window:janela onde o player será desenhado
 * @retval none
 */
        void drawTo(sf::RenderWindow &window);
        /**
 * @brief Essa função é responsável por checar se uma key foi pressionada ou não 
 * 
 * @param key:teclas do teclado
 * @param checkPressed:checa se uma tecla foi apertada ou não
 * @retval none
 */
        void processEvents(sf::Keyboard::Key key, bool checkPressed);
            /**
 * @brief Essa função é responsável por a partir da função processevents determinar o movimento do player
 * 
 * @param map: parâmetro do tipo Gameworld, que é o level em si
 * @retval none
 */
        void update(GameWorld& map);
};

#endif
