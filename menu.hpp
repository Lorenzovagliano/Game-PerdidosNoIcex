#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>


class Menu
{   
    private:
        /**
         *  Opção do menu selecionada
         */
        int pos;
        /**
         *  Botão do mouse ou teclado apertado
         */
        bool pressed;
        /**
         *  Opção selecionada com mouse
         */
        bool mouseSelect;

        /**
         *  Janela em que será desenhada e exibida a parte gráfica do jogo
         */
        sf::RenderWindow * window;
        /**
         *  Fonte dos textos ddo menu
         */
        sf::Font * font;
        /**
         *  Textura da imagem de fundo do menu
         */
        sf::Texture * image;
        /**
         *  Sprite que representa a imagem de fundo do menu
         */
        sf::Sprite * background;

        /**
         *  Posição do mouse na janela em pixels
         */
        sf::Vector2i posMouse;
        /**
         *  Posição do mouse na tela
         */
        sf::Vector2f mouseCoord;

        /**
         *  Vetor que armazena as strings das opções
         */
        std::vector<const char*> options;
        /**
         *  Vetor que as coordenadas das opções
         */
        std::vector<sf::Vector2f> coords;
        /**
         *  Vetor que armazena as coordenadas dos pontos das opções
         */
        std::vector<sf::Vector2f> pCoords;
        /**
         *  Vetor que armazena os objetos textos das opções
         */
        std::vector<sf::Text> texts;
        /**
         *  Vetor que armazena pontos que identificam a opção selecionada
         */
        std::vector<sf::CircleShape> points;
        /**
         *  Vetor que armazena as áreas em que as opções podem ser selecionadas
         */
        std::vector<sf::RectangleShape> optionBox;
        /**
         *  Vetor que armazena os tamanhos das áreas de seleção das opções
         */
        std::vector<sf::Vector2f> boxSizes;
        /**
         *  Vetor que armazena os tamanhos dos textos das opções
         */
        std::vector<std::size_t> sizes;

    protected:
        /**
         *  Método que atribui valores às variáveis e monta o estágio inicial do menu
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
        Menu(sf::RenderWindow &w);

        /**
         *  Método destrutor
         */
         ~Menu();

        /**
         *  Método chamado pela main para rodar o menu
         */
        int runMenu();
        
};

#endif