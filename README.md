# Tic Tac Toe / Jogo do Galo em C++

**Tic Tac Toe** (ou **Jogo do Galo**) é um clássico jogo de dois jogadores, implementado em **C++** para rodar no console.  
Este projeto permite que dois jogadores se enfrentem alternando turnos, verificando vitória, empate e jogadas válidas.

---

## 🛠 Funcionalidades

- Menu inicial com opções **Jogar** ou **Sair**.
- Tabuleiro 3x3 exibido com cores no console.
- Alternância automática de jogadores (X e O).
- Verificação de vitória por linhas, colunas ou diagonais.
- Detecção de empate quando todas as posições são preenchidas.
- Pergunta ao jogador se deseja jogar novamente.
- Entrada de nomes dos jogadores.
- Validação completa de entrada para posições inválidas ou ocupadas.

---

## 📂 Estrutura do Código

- **`main()`**: Controla o menu principal e inicia o jogo.
- **`menu()`**: Exibe o menu inicial.
- **`jogo()`**: Função principal do jogo, controla turnos, jogadas e verificações.
- **`desenhoTabuleiro()`**: Exibe o tabuleiro no console com cores.
- **`colocaMarca()`**: Coloca X ou O na posição escolhida.
- **`jogadaValida()`**: Verifica se a posição escolhida está livre.
- **`verificaVitoria()`**: Verifica linhas, colunas e diagonais para determinar vitória.
- **`jogarNovamente()`**: Pergunta se os jogadores querem iniciar outra partida.
- **`limparEcra()`**: Limpa o console (Windows e Linux).
- **`header()`**: Exibe o cabeçalho do jogo.

---

## ⚙️ Tecnologias

- Linguagem: **C++**
- Suporta qualquer compilador C++ moderno (Windows, Linux, Mac).
- Uso de ANSI escape codes para cores no terminal.

---

## 📌 Como executar

1. Compile o código usando um compilador C++:

```bash
g++ -o JogoDoGalo main.cpp
