#include "levelmenu.hpp"

LevelMenu::LevelMenu(sf::RenderWindow &w)
        {
            window = &w;
            background = new sf::Sprite();
            back = new sf::Sprite();
            select = new sf::Sprite();
            level = new sf::Sprite();
            rightarrow = new sf::Sprite();
            leftarrow = new sf::Sprite();

            set_values();
        }

LevelMenu:: ~LevelMenu(){
            delete window;
            delete background;
            delete back;
            delete select;
            delete level;
            delete rightarrow;
            delete leftarrow;
        
}
void LevelMenu::set_values()
        {
            pos = -1;
            pressed = false;
            mouseselect = false;
            
            textures.resize(8);
            textures[0].loadFromFile("data/LevelMenu2.png");
            textures[1].loadFromFile("data/back.png");
            textures[2].loadFromFile("data/select.png");
            textures[3].loadFromFile("data/leftarrow.png");
            textures[4].loadFromFile("data/rightarrow.png");

            background->setTexture(textures[0]);
            back->setTexture(textures[1]);
            select->setTexture(textures[2]);
            rightarrow->setTexture(textures[3]);
            leftarrow->setTexture(textures[4]);

            levels.resize(8);
            levels[0].loadFromFile("data/isaac1f.png");
            levels[1].loadFromFile("data/isaac2f.png");
            levels[2].loadFromFile("data/isaac3f.png");
            levels[3].loadFromFile("data/isaac4f.png");
            levels[4].loadFromFile("data/isaac5f.png");
            levels[5].loadFromFile("data/isaac6f.png");
            levels[6].loadFromFile("data/isaac7f.png");
            levels[7].loadFromFile("data/isaac8f.png");

            pos_mouse = {0,0};
            mouse_coord = {0, 0};

            option_box.resize(4);
            coords = {{631, 59}, {463, 446}, {166, 359}, {351, 359}};
            box_sizes = {{92, 40}, {143, 76}, {44, 33}, {44, 33}};

            back->setPosition(coords[0]);
            select->setPosition(coords[1]);
            rightarrow->setPosition(coords[2]);
            leftarrow->setPosition(coords[3]);

            for (int i = 0; i < 4; i++)
            {
                option_box[i].setSize(box_sizes[i]);
                option_box[i].setPosition(coords[i]);
                option_box[i].setFillColor(sf::Color::Transparent);
            }

            pos = 0;

            level->setPosition(sf::Vector2f(152, 201));
            level->setTexture(levels[0]);
        }

int LevelMenu::loop_events()
        {
            sf::Event event;
            while(window->pollEvent(event))
            {
                if( event.type == sf::Event::Closed){
                    window->close();
                    return -2;
                }

                pos_mouse = sf::Mouse::getPosition(*window);
                mouse_coord = window->mapPixelToCoords(pos_mouse);

                if (!(option_box[0].getGlobalBounds().contains(mouse_coord))
                & !(option_box[1].getGlobalBounds().contains(mouse_coord))
                & !(option_box[2].getGlobalBounds().contains(mouse_coord))
                & !(option_box[3].getGlobalBounds().contains(mouse_coord))
                & (mouseselect == true)){
                    back->setScale(1.f, 1.f);
                    select->setScale(1.f, 1.f);
                    rightarrow->setScale(1.f, 1.f);
                    leftarrow->setScale(1.f, 1.f);
                        
                    back->setPosition(coords[0]);
                    select->setPosition(coords[1]);
                    rightarrow->setPosition(coords[2]);
                    leftarrow->setPosition(coords[3]);

                    mouseselect == false;
                }
                
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !pressed)
                {
                    if( pos < 7)
                    {
                        pressed = true;
                        pos++;
                        level->setTexture(levels[pos]); 
                        pressed = false;
                    }
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !pressed)
                {
                    if( pos > 0)
                    {   
                        pressed = true;
                        pos--;
                        level->setTexture(levels[pos]); 
                        pressed = false;
                    }
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !pressed)
                {   
                    pressed == true;
                    return (pos + 1);
                }
                if(option_box[0].getGlobalBounds().contains(mouse_coord)) {
                    mouseselect = true;
                    back->setScale(1.1f, 1.1f);
                    back->setPosition(coords[0].x - 4, coords[0].y -2);
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        return -1;
                }
                if(option_box[1].getGlobalBounds().contains(mouse_coord)) {
                    mouseselect = true;
                    select->setScale(1.1f, 1.1f);
                    select->setPosition(coords[1].x - 7, coords[1].y -3);
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        return (pos + 1);
                }
                if(option_box[2].getGlobalBounds().contains(mouse_coord)) {
                    mouseselect = true;
                    rightarrow->setScale(1.1f, 1.1f);
                    rightarrow->setPosition(coords[2].x - 2, coords[2].y -1);
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && pos > 0) {
                        pressed = true;
                        pos--;
                        level->setTexture(levels[pos]); 
                        pressed = false;
                    }
                }
                if(option_box[3].getGlobalBounds().contains(mouse_coord)) {
                    mouseselect = true;
                    leftarrow->setScale(1.1f, 1.1f);
                    leftarrow->setPosition(coords[3].x - 2, coords[3].y -1);
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && pos < 7) {
                        pressed = true;
                        pos++;
                        level->setTexture(levels[pos]); 
                        pressed = false;
                    }
                }
            }
            return 0;
        }

void LevelMenu::draw_all()
        {
            window->clear();
            window->draw(*background);
            window->draw(*back);
            window->draw(*select);
            window->draw(*level);
            window->draw(*rightarrow);
            window->draw(*leftarrow);
            window->display();
        }
 int LevelMenu::run_menu()
        {
            while(window->isOpen()) {
                int decision = loop_events();
                draw_all();
                if(decision != 0)
                    return decision;
            }
        }

