#ifndef LEVELMENU_H
#define LEVELMENU_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>


class LevelMenu
{   
    private:
        /**
         *  Fase selecionada
         */
        int pos;
        /**
         *  Botão do mouse ou menu apertado
         */
        bool pressed
        /**
         *  Opção selecionada com mouse
         */
        bool mouseSelect;

        /**
         *  Janela de exibição gráfica
         */
        sf::RenderWindow * window;
        /**
         *  Sprite da imagem de fundo do level menu
         */
        sf::Sprite * background;
        /**
         *  Sprite da opção de 'back'
         */
        sf::Sprite * back;
        /**
         *  Sprite da opção 'select'
         */
        sf::Sprite * select;
        /**
         *  Sprite da imagem, texto e dificuldade exibida ao selecionar cada fase
         */
        sf::Sprite * level;
        /**
         *  Sprite da seta para direita
         */
        sf::Sprite * rightArrow;
        /**
         *  Sprite da seta para esquerda
         */
        sf::Sprite * leftArrow;

        /**
         *  Posição do mouse em pixels na janela
         */
        sf::Vector2i posMouse;
        /**
         *  Coordenadas da posição do mouse na tela
         */
        sf::Vector2f mouseCoord;

        /**
         *  Vetor que armazena as texturas das opções
         */
        std::vector<sf::Texture> textures;
        /**
         *  Vetor que armazena as texturas das imagens atribuidas às fases
         */
        std::vector<sf::Texture> levels;
        /**
         *  Vetor que armazena as coordenadas das opções
         */
        std::vector<sf::Vector2f> coords;
        /**
         *  Vetor que armazena as áreas de seleção das opções
         */
        std::vector<sf::RectangleShape> optionBox;
        /**
         *  Vetor que armazena os tamanhos das áreas de seleção das opções
         */
        std::vector<sf::Vector2f> boxSizes;

    protected:
        /**
         *  Método que atribui valores às variáveis e monta o estágio inicial do level menu
         */
        void setValues();
       
        /**
         *  Método que analisa os eventos realizado pelo usuário e retorna a resposta adequada à ele
         */
        int loopEvents();
       
        /**
         *  Método que desenha tudo na janela a cada loop de eventos
         */
        void drawAll();

    public:
        /**
         *  Método construtor
         *  @param w janela de exibição gráfica
         */
        LevelMenu(sf::RenderWindow &w);

        /**
         *  Método destrutor
         */
        ~LevelMenu();

        /**
         *  Método chamado pela main para rodar o level menu
         */
        int runMenu();

};

#endif