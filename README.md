## **Perdidos no ICEX**
---
This program is a top-down puzzle game where you play as a UFMG CS student, and Professor Douglas has given you the mission to retrieve the projector remote control in a room at the ICEX building. Your objective is to reach the control by cleverly dealing with obstacles within the limited number of moves available.
---
![Captura de tela 2023-02-08 192303](https://user-images.githubusercontent.com/111889654/217664809-b94a208c-9110-4ceb-8ed7-b64c6cd16129.png)
![Captura de tela 2023-02-08 192309](https://user-images.githubusercontent.com/111889654/217664930-d5c2602e-0eed-4c5b-b527-e09430a26569.png)
![Captura de tela 2023-02-08 192314](https://user-images.githubusercontent.com/111889654/217664964-ee4e9898-aa08-45d1-91e5-a30f82d58dbc.png)
![Captura de tela 2023-02-08 194453](https://user-images.githubusercontent.com/111889654/217668309-ee541c01-1ac8-4f07-aa62-02c36ee55475.png)
---
### Basic Rules
* The player cannot pass through the side walls and bookshelves in the level.
* Tables and boxes can be pushed as long as there is an empty space behind them in the direction of movement.
  * Boxes will be destroyed if moved towards an occupied space, including ghosts. However, tables can occupy the same space as a ghost.
* The player can move over ghosts, but they consume twice as many movement points as a normal space, even when another object is moved while on top of them.
* To pass through spider webs, the hero needs to obtain the scissors, which allows them to cut through them.
---
**Warning:** 
Although the menu has 8 level options, only 4 levels have been implemented so far.
---
### **Tools** 
---
- Language: [C++ 11](https://cplusplus.com/doc/)
- Library: [SFML](https://www.sfml-dev.org/)
- Compiler: [GCC](https://gcc.gnu.org/)
- Build: [Make](https://www.gnu.org/software/make/)
- Documentation: [Doxygen](https://doxygen.nl/)


### **Build Process**
---
To build program, use:

    $ make
**Attention: In order to compile, it is necessary to have the SFML library installed on Linux and to create a "./build/" directory.** The command may vary depending on your Linux distribution. On Ubuntu, you can use the following command to install SFML: sudo apt-get install libsfml-dev.

## **Documentation**
---
To generate Documentation, use:

    $ doxygen Doxyfile
**Attention: It is necessary to have Doxygen installed to use this command, and please create a "./doc/" directory beforehand.** The command may vary depending on your Linux distribution. On Ubuntu, you can use the following command to install Doxygen: sudo apt-get install doxygen

### **Removing object files and executable**
---
    $ make clean
