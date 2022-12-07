#include "menu.hpp"

 Menu::Menu(sf::RenderWindow &w)
        {
            window = &w;
            font = new sf::Font();
            image = new sf::Texture();
            background = new sf::Sprite();

            set_values();
        }

Menu::~Menu()
        {
            delete window;
            delete font;
            delete image;
            delete background;
        }
 void Menu::set_values()
        {
            pos = -1;
            pressed = false;
            mouseselect = false;
            font->loadFromFile("./data/IsaacGame.ttf");
            image->loadFromFile("./data/icexmenu.png");

            background->setTexture(*image);

            pos_mouse = {0,0};
            mouse_coord = {0, 0};

            options = {"Play", "Options", "Credits", "Quit"};
            texts.resize(4);
            points.resize(4);
            option_box.resize(4);
            coords = {{640, 191}, {610, 282}, {610, 370}, {642, 457}};
            p_coords = {{760, 230}, {760, 310}, {760, 398}, {760, 493}};
            box_sizes = {{150, 60}, {170, 48}, {170, 48}, {140, 56}};
            sizes = {52, 40, 40, 48};

            for(std::size_t i{}; i < texts.size(); ++i){
                texts[i].setFont(*font);
                texts[i].setString(options[i]);
                texts[i].setCharacterSize(sizes[i]);
                texts[i].setOutlineColor(sf::Color::Black);
                texts[i].setPosition(coords[i]);
                texts[i].setOutlineThickness(4);
            } 

            for (std::size_t i{}; i < texts.size(); ++i)
            {
                points[i].setRadius(3);
                points[i].setPosition(p_coords[i]);
                points[i].setFillColor(sf::Color::White);
                points[i].setOutlineColor(sf::Color::White);
                points[i].setOutlineThickness(0);
            }

            for (int i = 0; i < 4; i++)
            {
                option_box[i].setSize(box_sizes[i]);
                option_box[i].setPosition(coords[i]);
                option_box[i].setFillColor(sf::Color::Transparent);
            }

            points[0].setOutlineThickness(2);

            pos = 0;

        }

int Menu::loop_events()
        {
            sf::Event event;
            while(window->pollEvent(event))
            {
                if( event.type == sf::Event::Closed){
                    window->close();
                    return -1;
                }

                pos_mouse = sf::Mouse::getPosition(*window);
                mouse_coord = window->mapPixelToCoords(pos_mouse);
                
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed)
                {
                    if( pos < 3)
                    {
                        pos++;
                        pressed = true;
                        texts[pos].setPosition(coords[pos].x - 30, coords[pos].y);
                        points[pos].setOutlineThickness(2);
                        texts[pos-1].setPosition(coords[pos-1]);
                        points[pos-1].setOutlineThickness(0); 
                        pressed = false;
                        mouseselect = true;
                    }
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed)
                {
                    if( pos > 0)
                    {
                        pos--;
                        pressed = true;
                        texts[pos].setPosition(coords[pos].x - 30, coords[pos].y);
                        points[pos].setOutlineThickness(2);
                        texts[pos+1].setPosition(coords[pos + 1]);
                        points[pos+1].setOutlineThickness(0);
                        pressed = false;
                        mouseselect = true;
                    }
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !pressed && !mouseselect)
                {   
                    pressed == true;
                    if(pos == 3){
                        window->close();
                        return -1;
                    }
                    if(pos == 0)
                        return 1;
                }
                if(option_box[0].getGlobalBounds().contains(mouse_coord)) {
                    mouseselect = true;
                    texts[pos].setPosition(coords[pos]);
                    points[pos].setOutlineThickness(0);
                    pos = 0;
                    texts[0].setPosition(coords[pos].x - 30, coords[pos].y);
                    points[0].setOutlineThickness(2);
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        return 1;
                }
                if(option_box[1].getGlobalBounds().contains(mouse_coord)) {
                    mouseselect = true;
                    texts[pos].setPosition(coords[pos]);
                    points[pos].setOutlineThickness(0);
                    pos = 1;
                    texts[1].setPosition(coords[pos].x - 30, coords[pos].y);
                    points[1].setOutlineThickness(2);
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        return 2;
                }
                if(option_box[2].getGlobalBounds().contains(mouse_coord)) {
                    mouseselect = true;
                    texts[pos].setPosition(coords[pos]);
                    points[pos].setOutlineThickness(0);
                    pos = 2;
                    texts[2].setPosition(coords[pos].x - 30, coords[pos].y);
                    points[2].setOutlineThickness(2);
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        return 3;
                }
                if(option_box[3].getGlobalBounds().contains(mouse_coord)) {
                    mouseselect = true;
                    texts[pos].setPosition(coords[pos]);
                    points[pos].setOutlineThickness(0);
                    pos = 3;
                    texts[3].setPosition(coords[pos].x - 30, coords[pos].y);
                    points[3].setOutlineThickness(2);
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        window->close();
                    return -1;
                    }
                }
            }
            return 0;
        }

 void Menu::draw_all()
        {
            window->clear();
            window->draw(*background);
            for(auto t : texts) {
                window->draw(t);
            }
            for(auto p : points) {
                window->draw(p);
            }
            window->display();
        }

int Menu::run_menu()
        {
            while(window->isOpen()) {
                int decision = loop_events();
                draw_all();
                if(decision != 0)
                    return decision;
            }
        }