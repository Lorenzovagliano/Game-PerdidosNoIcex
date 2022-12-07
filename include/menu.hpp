#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>


class Menu
{   
    private:
        int pos;
        bool pressed, mouseselect, keyboardselects;

        sf::RenderWindow * window;
        sf::Font * font;
        sf::Texture * image;
        sf::Sprite * background;

        sf::Vector2i pos_mouse;
        sf::Vector2f mouse_coord;

        std::vector<const char*> options;
        std::vector<sf::Vector2f> coords;
        std::vector<sf::Vector2f> p_coords;
        std::vector<sf::Text> texts;
        std::vector<sf::CircleShape> points;
        std::vector<sf::RectangleShape> option_box;
        std::vector<sf::Vector2f> box_sizes;
        std::vector<std::size_t> sizes;

    protected:
        void set_values();
        
        int loop_events();
        
        void draw_all();

    public:
        Menu(sf::RenderWindow &w);

         ~Menu();

        int run_menu();
        
};

#endif