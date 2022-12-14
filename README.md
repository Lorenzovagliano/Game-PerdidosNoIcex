## **Perdidos no ICEX**
---
Esse programa é um jogo top-down de puzzles com a temática de que você é um aluno de PDS II e o professor Douglas te deu a missão de pegar o controle do projetor em uma sala do ICEX. Seu objetivo é chegar até o controle lidando com os obstáculos de maneira inteligente dentro do número limitado de movimentos do seu personagem. 

**Observação:** Apesar do menu possuir 8 opções de níveis no menu, apenas 4 níveis foram implementados.

### Regras básicas
* O herói não pode atravessar as paredes laterais da fase.
* Mesas e caixas podem ser movidas com a condição de que elas possuam um espaço livre atrás no sentido do movimento
  * Caixas serão destruidas ao serem movidas em direção a um espaço ocupado
* O herói pode passar por cima dos fantasmas, porém eles reduzem seu número de movimentos em dobro em relação a um espaço normal, inclusive quando outro objeto é movido enquanto encima deles

### **Ferramentas** 
---
- Linguagem: [C++ 11](https://cplusplus.com/doc/)
- Biblioteca: [SFML](https://www.sfml-dev.org/)
- Compilação: [Make](https://www.gnu.org/software/make/)
- Documentação: [Doxygen](https://doxygen.nl/)


### **Compilação**
---
    $ make
**Atenção: Para compilar, é necessário ter a biblioteca SFML instalada no linux e criar um diretório ./build/**. O comando pode depender da sua distro. No Ubuntu, utilizar: sudo apt-get install libsfml-dev.

## **Documentação**
---
Para gerar a documentação, utilizar:

    $ doxygen Doxyfile
**Atenção: Criar antes um diretório ./doc/**

### **Remover arquivos auxiliares**
---
    $ make clean
