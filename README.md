## **Perdidos no ICEX**
---
Esse programa é um jogo top-down de puzzles com a temática de que você é um aluno de PDS II e o professor Douglas te deu a missão de pegar o controle do projetor em uma sala do ICEX. Seu objetivo é chegar até o controle lidando com os obstáculos de maneira inteligente dentro do número limitado de movimentos do seu personagem.
---
![Captura de tela 2023-02-08 192303](https://user-images.githubusercontent.com/111889654/217664809-b94a208c-9110-4ceb-8ed7-b64c6cd16129.png)
![Captura de tela 2023-02-08 192309](https://user-images.githubusercontent.com/111889654/217664930-d5c2602e-0eed-4c5b-b527-e09430a26569.png)
![Captura de tela 2023-02-08 192314](https://user-images.githubusercontent.com/111889654/217664964-ee4e9898-aa08-45d1-91e5-a30f82d58dbc.png)
![Captura de tela 2023-02-08 194453](https://user-images.githubusercontent.com/111889654/217668309-ee541c01-1ac8-4f07-aa62-02c36ee55475.png)
---
### Regras básicas
* O herói não pode atravessar as paredes laterais e as estantes da fase.
* Mesas e caixas podem ser empurradas com a condição de que elas possuam um espaço livre atrás no sentido do movimento.
  * Caixas serão destruidas ao serem movidas em direção a um espaço ocupado, incluindo fantasmas. Porém, mesas podem ocupar o mesmo espaço de um fantasma.
* O herói pode passar por cima dos fantasmas, porém eles reduzem seu número de movimentos em dobro em relação a um espaço normal, inclusive quando outro objeto é movido enquanto encima deles.
* Para passar pelas teias, o herói deve pegar a tesoura, podendo assim, cortá-las
---
**Observação:** 
Apesar do menu possuir 8 opções de níveis no menu, apenas 4 níveis foram implementados.
---
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
**Atenção: É necessário ter Doxygen instalado para utilizar este comando e criar antes um diretório ./doc/**. O comando pode depender da sua distro. No Ubuntu, utilizar: sudo apt-get install doxygen

### **Remover arquivos auxiliares**
---
    $ make clean
