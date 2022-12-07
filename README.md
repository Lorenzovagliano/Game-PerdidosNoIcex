## **Perdidos no ICEX**
---
Esse programa é um jogo do gênero "top-down" com a temática de que você é um aluno de PDS II e o professor Douglas te deu a missão de pegar o controle do projetor em uma sala do ICEX. Seu objetivo é chegar até o controle lidando com os obstáculos de maneira inteligente dentro do número limitado de movimentos do seu personagem. 

**Observação:** Apesar do menu possuir 8 opções de níveis no menu, apenas 4 níveis foram implementados.

# Puzzle Game(nome provisório)

## Como Jogar

### Objetivo
O jogador deve conduzir seu herói até o final do campo da fase sem esgotar o número de movimentos máximo que aquela fase permite. Porém, para conseguir isso, ele deverá utilizar estratégias para evitar os obstáculos da forma mais eficiente possível.

### Regras básicas
* O herói não pode atravessar as paredes laterais da fase.
* Pedras e caixas podem ser movidas com a condição de que elas possuam um espaço livre atrás no sentido do movimento
  * Caixas serão destruidas ao serem movidas em direção a um espaço ocupado
* O herói pode passar por cima das armadilhas, porém elas reduzem seu número de movimentos em dobro em relação a um espaço normal, inclusive quando outro objeto é movido enquanto encima delas

### **Ferramentas** 
---
- Linguagem: [C++ 11](https://cplusplus.com/doc/)
- Compilação: [Make](https://www.gnu.org/software/make/)
- Documentação: [Doxygen](https://doxygen.nl/)


### **Compilação**
---
    $ make
**Atenção: Criar antes um diretório ./doc/**

## **Documentação**
---
É necessário ter na raiz do projeto um arquivo Doxyfile. Um arquivo padrão pode ser gerado pelo comando:

    $ doxygen -g
Abaixo a lista de flags que foram modificadas no arquivo original.

    PROJECT_NAME           = "PDS2 - Mini-projeto de exemplo"

    OUTPUT_DIRECTORY       = doc/

    RECURSIVE              = YES

    EXTRACT_ALL            = YES
    EXTRACT_PRIVATE        = YES
    EXTRACT_STATIC         = YES

    HAVE_DOT               = NO
Para gerar a documentação, utilizar:

    $ doxygen Doxyfile

### **Remover arquivos auxiliares**
---
    $ make clean
