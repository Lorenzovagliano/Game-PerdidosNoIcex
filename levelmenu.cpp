#include "levelmenu.hpp"

LevelMenu::LevelMenu(sf::RenderWindow &w)
        {
            window = &w;
            background = new sf::Sprite();
            back = new sf::Sprite();
            select = new sf::Sprite();
            level = new sf::Sprite();
            rightArrow = new sf::Sprite();
            leftArrow = new sf::Sprite();

            setValues();
        }

LevelMenu:: ~LevelMenu(){
            delete window;
            delete background;
            delete back;
            delete select;
            delete level;
            delete rightArrow;
            delete leftArrow;
        
}
void LevelMenu::setValues()
        {
            pos = -1;
            pressed = false;
            mouseSelect = false;
            
            textures.resize(8);
            textures[0].loadFromFile("data/LevelMenu2.png");
            textures[1].loadFromFile("data/back.png");
            textures[2].loadFromFile("data/select.png");
            textures[3].loadFromFile("data/leftArrow.png");
            textures[4].loadFromFile("data/rightArrow.png");

            background->setTexture(textures[0]);
            back->setTexture(textures[1]);
            select->setTexture(textures[2]);
            rightArrow->setTexture(textures[3]);
            leftArrow->setTexture(textures[4]);

            levels.resize(8);
            levels[0].loadFromFile("data/isaac1f.png");
            levels[1].loadFromFile("data/isaac2f.png");
            levels[2].loadFromFile("data/isaac3f.png");
            levels[3].loadFromFile("data/isaac4f.png");
            levels[4].loadFromFile("data/isaac5f.png");
            levels[5].loadFromFile("data/isaac6f.png");
            levels[6].loadFromFile("data/isaac7f.png");
            levels[7].loadFromFile("data/isaac8f.png");

            posMouse = {0,0};
            mouseCoord = {0, 0};

            optionBox.resize(4);
            coords = {{631, 59}, {463, 446}, {166, 359}, {351, 359}};
            boxSizes = {{92, 40}, {143, 76}, {44, 33}, {44, 33}};

            back->setPosition(coords[0]);
            select->setPosition(coords[1]);
            rightArrow->setPosition(coords[2]);
            leftArrow->setPosition(coords[3]);

            for (int i = 0; i < 4; i++)
            {
                optionBox[i].setSize(boxSizes[i]);
                optionBox[i].setPosition(coords[i]);
                optionBox[i].setFillColor(sf::Color::Transparent);
            }

            pos = 0;

            level->setPosition(sf::Vector2f(152, 201));
            level->setTexture(levels[0]);
        }

int LevelMenu::loopEvents()
        {
            sf::Event event;
            while(window->pollEvent(event))
            {
                if( event.type == sf::Event::Closed){
                    window->close();
                    return -2;
                }

                posMouse = sf::Mouse::getPosition(*window);
                mouseCoord = window->mapPixelToCoords(posMouse);

                if (!(optionBox[0].getGlobalBounds().contains(mouseCoord))
                & !(optionBox[1].getGlobalBounds().contains(mouseCoord))
                & !(optionBox[2].getGlobalBounds().contains(mouseCoord))
                & !(optionBox[3].getGlobalBounds().contains(mouseCoord))
                & (mouseSelect == true)){
                    back->setScale(1.f, 1.f);
                    select->setScale(1.f, 1.f);
                    rightArrow->setScale(1.f, 1.f);
                    leftArrow->setScale(1.f, 1.f);
                        
                    back->setPosition(coords[0]);
                    select->setPosition(coords[1]);
                    rightArrow->setPosition(coords[2]);
                    leftArrow->setPosition(coords[3]);

                    mouseSelect == false;
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
                if(optionBox[0].getGlobalBounds().contains(mouseCoord)) {
                    mouseSelect = true;
                    back->setScale(1.1f, 1.1f);
                    back->setPosition(coords[0].x - 4, coords[0].y -2);
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        return -1;
                }
                if(optionBox[1].getGlobalBounds().contains(mouseCoord)) {
                    mouseSelect = true;
                    select->setScale(1.1f, 1.1f);
                    select->setPosition(coords[1].x - 7, coords[1].y -3);
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        return (pos + 1);
                }
                if(optionBox[2].getGlobalBounds().contains(mouseCoord)) {
                    mouseSelect = true;
                    rightArrow->setScale(1.1f, 1.1f);
                    rightArrow->setPosition(coords[2].x - 2, coords[2].y -1);
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && pos > 0) {
                        pressed = true;
                        pos--;
                        level->setTexture(levels[pos]); 
                        pressed = false;
                    }
                }
                if(optionBox[3].getGlobalBounds().contains(mouseCoord)) {
                    mouseSelect = true;
                    leftArrow->setScale(1.1f, 1.1f);
                    leftArrow->setPosition(coords[3].x - 2, coords[3].y -1);
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

void LevelMenu::drawAll()
        {
            window->clear();
            window->draw(*background);
            window->draw(*back);
            window->draw(*select);
            window->draw(*level);
            window->draw(*rightArrow);
            window->draw(*leftArrow);
            window->display();
        }
 int LevelMenu::runMenu()
        {
            while(window->isOpen()) {
                int decision = loopEvents();
                drawAll();
                if(decision != 0)
                    return decision;
            }
        }
