#include "SFML/Graphics.hpp"
#include "GameWorld.hpp"

#ifndef PLAYER_H
#define PLAYER_H

class Player{
    private:
        bool _up;
        bool _down;
        bool _right;
        bool _left;

    public:
        int _movimentos;
        sf::Sprite _sprite;

        Player(float cordX, float cordY);

        void drawTo(sf::RenderWindow &window);
        void processEvents(sf::Keyboard::Key key, bool checkPressed);
        void update(GameWorld& map);
};

#endif