#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

#include "menu.hpp"
#include "levelmenu.hpp"
#include "Player.hpp"
#include "GameTile.hpp"
#include "GameWorld.hpp"


int main()
{   
    sf::RenderWindow window;
    window.create(sf::VideoMode(794, 591), "Perdidos no Icex");
    window.setPosition(sf::Vector2i(300,50));
    Menu * menu = new Menu(window);

    int decision = 0;
    while (decision != -1)
    {//LOOP DO MENU PRINCIPAL E JOGO ABERTO

        sf::Music musicaMenu;
        if(!musicaMenu.openFromFile("data/sample4.ogg")) exit(1);
            musicaMenu.play();

        decision = menu->run_menu();
        if (decision == 1)
        {//CLIQUEI EM JOGAR E FUI PARA MENU DE FASES

            int fase = 0;
            while (fase > -1)
            {//LOOP DO MENU DE FASES

                LevelMenu * levelMenu = new LevelMenu(window);
                int fase = levelMenu->run_menu();
                if (fase > -1) 
                {//CLIQUEI EM JOGAR ALGUMA FASE 

                    bool tentandofase = true;
                    while (tentandofase == true)
                    {//LOOP DA FASE

                        musicaMenu.stop();
                        GameWorld gameWorld = GameWorld(fase);
                        float windowHeight = gameWorld.get_gridLenght() * 64;
                        float windowWidth = gameWorld.get_gridLenght() * 64;

                        std::vector<sf::Text> help;
                        std::vector<std::string> texts;
                        std::vector<sf::Vector2f> coords;

                        texts = {"Para se mover,\n use o WASD", "Aperte 'R' para \n reinicar a fase", "Aperte 'ESC' para\n voltar ao menu", "Movimentos\n restantes:", "25"};
                        coords ={{windowWidth + 10, 5}, {windowWidth + 10, 85}, {windowWidth + 10, 165}, {windowWidth + 20, 300}, {windowWidth + 45, 370}};

                        sf::Font font;
                        font.loadFromFile("data/IsaacGame.ttf");

                        help.resize(5);
                        for(int i = 0; i < 5; i++) {
                            help[i].setFont(font);
                            help[i].setString(texts[i]);
                            help[i].setCharacterSize(24);
                            help[i].setPosition(coords[i]);
                        }

                        Player player(gameWorld._initialPlayerPosX, gameWorld._initialPlayerPosY);
                        sf::Texture playerTexture;
                        playerTexture.loadFromFile("tiles/player.png");
                        player._sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
                        player._sprite.setTexture(playerTexture);

                        help[3].setCharacterSize(28);
                        help[4].setString(std::to_string(gameWorld._maxMovements - player._movimentos));
                        help[4].setCharacterSize(80);

                        sf::Music music;
                        if(!music.openFromFile("Music_pds2.ogg")) return EXIT_FAILURE;
                        music.play();

                        while(window.isOpen() && tentandofase == true)
                        {//LOOP DE EVENTOS
                            if(player._movimentos == 0) { //RECONSTRUIR FASE APÓS RESTART
                                window.clear();
                            
                                for(int i = 0; i < gameWorld.get_gridLenght(); i++)
                                    for(int j = 0; j < gameWorld.get_gridLenght(); j++)
                                        window.draw(gameWorld.get_tiles()[i][j]->_sprite);

                                for(int i = 0; i < gameWorld.get_objetos().size(); i++)
                                    window.draw(gameWorld.get_objetos()[i]->_sprite);

                                for(auto t : help)
                                    window.draw(t);

                                player.drawTo(window);
                                window.display();
                            }

                            sf::Event event;
                            while(window.pollEvent(event)){
                                switch (event.type) {
                                    case sf::Event::Closed: {
                                        window.close();
                                        tentandofase == false;
                                        fase = -2;
                                        break;
                                    }//QUEBRA TODOS OS LOOPS, FECHANDO O JOGO

                                    case sf::Event::KeyPressed: {
                                        player.processEvents(event.key.code, true);
                                        if(event.key.code == sf::Keyboard::W){
                                            player.update(gameWorld);
                                            playerTexture.loadFromFile("tiles/playerrup.png");
                                            player._sprite.setTexture(playerTexture);
                                        }
                                        if(event.key.code == sf::Keyboard::A){
                                            player.update(gameWorld);
                                            playerTexture.loadFromFile("tiles/playerleft.png");
                                            player._sprite.setTexture(playerTexture);
                                        }
                                        if(event.key.code == sf::Keyboard::S){
                                            player.update(gameWorld);
                                            playerTexture.loadFromFile("tiles/player.png");
                                            player._sprite.setTexture(playerTexture);
                                        }
                                        if(event.key.code == sf::Keyboard::D){
                                            player.update(gameWorld);
                                            playerTexture.loadFromFile("tiles/playerright.png");
                                            player._sprite.setTexture(playerTexture);
                                        }
                                        player.processEvents(event.key.code, false);
                                        break;
                                    }
                                }
                            }

                            window.clear();
                            
                            for(int i = 0; i < gameWorld.get_gridLenght(); i++)
                                for(int j = 0; j < gameWorld.get_gridLenght(); j++)
                                    window.draw(gameWorld.get_tiles()[i][j]->_sprite);

                            for(int i = 0; i < gameWorld.get_objetos().size(); i++)
                                window.draw(gameWorld.get_objetos()[i]->_sprite);

                            help[4].setString(std::to_string(gameWorld._maxMovements - player._movimentos));
                            for(auto t : help)
                                    window.draw(t);

                            player.drawTo(window);
                            window.display();

                            if(gameWorld.ganhou == true)
                                tentandofase = false; //QUEBRA LOOP DE EVENTOS E DA FASE (VOLTA PRO LEVELMENU)

                            if(event.key.code == sf::Keyboard::R)
                                break; //REINICIA FASE

                            if(event.key.code == sf::Keyboard::Escape)
                                tentandofase = false;

                            if(gameWorld._maxMovements <= player._movimentos)
                                break; //QUEBRA LOOP DE EVENTOS SEM QUEBRAR DA FASE (RECOMEÇA FASE)

                        }//RECOMEÇA LOOP DE EVENTOS

                    }//RECOMEÇA LOOP DA FASE
                    
                }
                if (fase == -2) {
                    decision = -1;
                    delete levelMenu;
                    levelMenu = nullptr;
                }//QUEBRA LOOP DO MENU E DO JOGO ABERTO
                if (fase == -1) {
                    break;
                }
            } //RECOMEÇA LOOP DO MENU DE FASES
                                       
        }

    }//RECOMEÇA LOOP DO MENU E DO JOGO ABERTO

    delete menu;
    menu = nullptr;
    return -1;

}     