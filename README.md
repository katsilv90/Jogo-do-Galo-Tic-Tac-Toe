# Tic Tac Toe / Jogo do Galo em C++

**Tic Tac Toe** (ou **Jogo do Galo**) é um clássico jogo de dois jogadores, implementado em **C++** para ser executado no console.  
Este projeto permite que dois jogadores se enfrentem alternando turnos, verificando vitórias, empates e jogadas válidas.

---

## 🛠 Funcionalidades

- Menu inicial com opções **Jogar** ou **Sair**.
- Tabuleiro 3x3 exibido com cores no terminal.
- Alternância automática de jogadores (X e O).
- Verificação de vitória por linhas, colunas ou diagonais.
- Detecção de empate quando todas as posições estão preenchidas.
- Pergunta ao jogador se deseja jogar novamente.
- Entrada de nomes dos jogadores.
- Validação completa de entrada para posições inválidas ou ocupadas.

---

## 📂 Estrutura do Código

- **`main()`**: Controla o menu principal e inicia o jogo.
- **`menu()`**: Exibe o menu inicial.
- **`jogo()`**: Função principal do jogo, controla turnos, jogadas e verificações.
- **`desenhoTabuleiro()`**: Exibe o tabuleiro no terminal com cores.
- **`colocaMarca()`**: Coloca X ou O na posição escolhida.
- **`jogadaValida()`**: Verifica se a posição escolhida está livre.
- **`verificaVitoria()`**: Verifica linhas, colunas e diagonais para determinar vitória.
- **`jogarNovamente()`**: Pergunta se os jogadores querem iniciar outra partida.
- **`limparEcra()`**: Limpa o terminal (Windows e Linux).
- **`header()`**: Exibe o cabeçalho do jogo.

---

## ⚙️ Tecnologias

- Linguagem: **C++**
- Suporta qualquer compilador C++ moderno (Windows, Linux, Mac).
- Utiliza **códigos de escape ANSI** para cores no terminal.

---

## 📌 Como executar

1. Compile o código usando um compilador C++:

```bash
g++ -o JogoDoGalo main.cpp

