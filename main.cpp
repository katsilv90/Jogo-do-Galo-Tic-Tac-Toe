#include <iostream>
#include <locale.h>
#include <string>

using namespace std;

// Limpa o ecrã para Windows e Linux
void limparEcra() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

//Cabeçalho do jogo
void header() {
    cout << "  ****************" << endl;
    cout << "    Jogo do Galo" << endl;
    cout << "  ****************" << endl;
}

// Desenha o tabuleiro
void desenhoTabuleiro(char tabuleiro[3][3]) {
    // Código ANSI para cores
    string azul = "\033[1;36m";
    string branco = "\033[37m";
    string reset = "\033[0m";
    //Grelha/Linhas do jogo
    cout << endl;
    cout << "    " <<branco<< tabuleiro[0][0] << azul<<" | " <<branco<< tabuleiro[0][1] <<azul<< " | " <<branco<< tabuleiro[0][2] <<azul<< endl;
    cout << "  -------------" << endl;
    cout << "    " << branco<<tabuleiro[1][0] << azul<<" | " <<branco<< tabuleiro[1][1] <<azul<< " | " << branco<<tabuleiro[1][2]<<azul << endl;
    cout << "  -------------" << endl;
    cout << "    " << branco<<tabuleiro[2][0] <<azul<< " | " <<branco<< tabuleiro[2][1] <<azul<< " | " <<branco<< tabuleiro[2][2] <<azul<< endl;
    cout<<reset;
}

// Coloca a marca (X ou O) no tabuleiro
void colocaMarca(char tabuleiro[3][3], int posicao, char marca) {
    int linha = (posicao - 1) / 3;           // Calcula a linha do tabuleiro
    int coluna = (posicao - 1) % 3;      // Calcula a coluna do tabuleiro
    tabuleiro[linha][coluna] = marca;  // Coloca a marca ('X' ou 'O') na posição calculada.
}

// Verifica se posição é válida
bool jogadaValida(char tabuleiro[3][3], int posicao) {
    if (posicao < 1 || posicao > 9)
        return false;

        //Converte a posição (1 a 9) para índice de matriz (0,0);(0,1) etc
    int linha = (posicao - 1) / 3;
    int coluna = (posicao - 1) % 3;

    return tabuleiro[linha][coluna] != 'X' && tabuleiro[linha][coluna] != 'O';  //Verificar se a posição está livre
}

// Verifica vitória
bool verificaVitoria(char tabuleiro[3][3], char marca) {
    for (int i = 0; i < 3; i++) {
            //Verifica linhas horizontais e colunas verticais
        if ((tabuleiro[i][0] == marca && tabuleiro[i][1] == marca && tabuleiro[i][2] == marca) ||
            (tabuleiro[0][i] == marca && tabuleiro[1][i] == marca && tabuleiro[2][i] == marca))
            return true;
    }

        //Verifica as diagonais
    if ((tabuleiro[0][0] == marca && tabuleiro[1][1] == marca && tabuleiro[2][2] == marca) ||
        (tabuleiro[0][2] == marca && tabuleiro[1][1] == marca && tabuleiro[2][0] == marca))
        return true;

    return false;
}

//Pergunta se querem jogar novamente
bool jogarNovamente() {
    int escolha;

    while (true) {
        cout << "\nQuer jogar novamente?\n";
        cout << "1 - Sim\n";
        cout << "2 - Não\n";
        cout << "Escolha uma opção: ";
        cin >> escolha;

        // Se o utilizador digitou letras ou símbolos
        if (cin.fail()) {                     //Detecta que houve erro
            cin.clear();                    //Limpa o erro
            cin.ignore(1000, '\n');  //Descarta até 1000 caracteres OU até encontrar Enter.
            cout << "Entrada inválida! Digite apenas 1 ou 2.\n";
            continue;
        }

        if (escolha == 1) {
            return true;   // Jogar novamente
        }

        if (escolha == 2) {
            cout << "Obrigado por jogar!\n";
            return false;  // Encerrar jogo
        }
        cout << "Opção inválida! Escolha 1 ou 2.\n";
    }
}


// Menu Inicial
int menu() {
    int escolha;

    do {
        limparEcra();
        cout << "*******************************\n";
        cout << "      Menu Jogo do Galo          \n";
        cout << "*******************************\n";
        cout << " 1 - Jogar\n";
        cout << " 2 - Sair\n";
        cout << " Escolha uma opção: ";
        cin >>escolha;

        if (cin.fail()) {                     //Detecta que houve erro
            cin.clear();                     //Limpa o erro
            cin.ignore(1000, '\n');    //Descarta até 1000 caracteres OU até encontrar Enter.
            escolha = 0;                  // Marca escolha como inválida para repetir o loop
        }

    } while (escolha < 1 || escolha > 2);

    return escolha;
}

// Jogo do galo
void jogo() {
    // Código ANSI para cores
    string azul = "\033[1;36m";
    string reset = "\033[0m";

    string jogador1, jogador2;

    limparEcra();
    cout << " Insira o nome do jogador 1 (X): ";
    cin >> jogador1;
    cout << " Insira o nome do jogador 2 (O): ";
    cin >> jogador2;

    while (true) { // Jogar várias vezes

        char tabuleiro[3][3] = {
            {'1', '2', '3'},
            {'4', '5', '6'},
            {'7', '8', '9'}
        };

        int jogada = 0;                     // Contador de jogadas, usado para alternar jogadores e marcas
        bool partidaAtiva = true;    // Indica se a partida atual continua ativa

        limparEcra();
        header();
        desenhoTabuleiro(tabuleiro);

        while (partidaAtiva) {
            string jogadorAtual = (jogada % 2 == 0) ? jogador1 : jogador2;    // Determina o jogador da vez
            char marcaAtual = (jogada % 2 == 0) ? 'X' : 'O';                              // Determina a marca da vez
            int posicao;                                                                                      // Armazena a posição escolhida

            cout << "\n " <<azul<< jogadorAtual << reset<<" (" << marcaAtual << "), escolha uma posição (1-9): ";

            while (true) {
                cin >> posicao;

                if (cin.fail()) {                       //Detecta que houve erro
                    cin.clear();                       //Limpa o erro
                    cin.ignore(1000, '\n');      //Descarta até 1000 caracteres OU até encontrar Enter.
                    cout << " Entrada inválida! Digite um número entre 1 e 9: ";
                    continue;
                }

                if (!jogadaValida(tabuleiro, posicao)) {
                    cout << " Posição inválida ou ocupada! Escolha outra: ";
                    continue;
                }

                break;
            }

            colocaMarca(tabuleiro, posicao, marcaAtual);

            limparEcra();
            header();
            desenhoTabuleiro(tabuleiro);

            jogada++;

            if (verificaVitoria(tabuleiro, marcaAtual)) {
                cout << "\n " << jogadorAtual << " venceu!" << endl;
                partidaAtiva = false;
                break;
            }

            if (jogada == 9) {
                cout << "\n Empate!" << endl;
                partidaAtiva = false;
                break;
            }
        }

        if(!jogarNovamente()){
            break;
        }
        swap(jogador1, jogador2); // alterna quem começa
    }
}

//Início do programa
int main() {
    setlocale(LC_ALL, "");

    while (true) {
        int escolha = menu();

        if (escolha == 2) {
            cout << " A encerrar o jogo..." << endl;
            break;
        }

        jogo();
    }

    return 0;
}
