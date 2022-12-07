#ifndef LEVELMENU_H
#define LEVELMENU_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>


class LevelMenu
{   
    private:
        int pos;
        bool pressed, mouseselect;

        sf::RenderWindow * window;
        sf::Sprite * background;
        sf::Sprite * back;
        sf::Sprite * select;
        sf::Sprite * level;
        sf::Sprite * rightarrow;
        sf::Sprite * leftarrow;

        sf::Vector2i pos_mouse;
        sf::Vector2f mouse_coord;

        std::vector<sf::Texture> textures;
        std::vector<sf::Texture> levels;
        std::vector<sf::Vector2f> coords;
        std::vector<sf::RectangleShape> option_box;
        std::vector<sf::Vector2f> box_sizes;

    protected:
        void set_values();
       
        int loop_events();
       
        void draw_all();

    public:
        LevelMenu(sf::RenderWindow &w);

        ~LevelMenu();
    
        int run_menu();

};

#endif