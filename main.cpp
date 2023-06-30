#include <iostream>
#include <chrono>
#include "tree.h"
#include "sort.h"

using std::cout;
using std::cin;
using std::endl;
using Clock = std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;

// Protótipos de funções
void printMenu();

int main()
{
    // Cria ponteiro para a raiz da árvore
    struct TreeNode* ptrRoot = nullptr;

    // Loop principal
    while (true) {
        printMenu();

        // Ler opção
        int iOption;
        cout << "Escolha uma opção: ";
        cin >> iOption;

        // Registra tempo de execução
        auto timeStart = Clock::now();

        // Executa a opção escolhida
        switch (iOption) {
            case 1:
                // Ler árvore de um arquivo
                break;
            case 2:
                // Ler árvore de dados digitados
                ptrRoot = buildTreeFromUserInput();
                break;
            case 3:
                // Altura da árvore
                cout << "Altura da árvore: " << getHeight(ptrRoot) << endl;
                break;
            case 4:
                // Tamanho da árvore
                cout << "Tamanho da árvore: " << getSize(ptrRoot) << endl;
                break;
            case 5:
                // Inserir elemento
                int iData;
                cout << "Digite o número a ser inserido: ";
                cin >> iData;
                insertElement(ptrRoot, iData);
                break;
            case 6:
                // Remover elemento
                break;
            case 7:
                // Buscar elemento
                break;
            case 8:
                // Verificar se é completa
                break;
            case 9:
                // Verificar se é perfeita
                break;
            case 10:
                // Exibir árvore
                break;
            case 11:
                // Bubble Sort
                break;
            case 12:
                // Selection Sort
                break;
            case 13:
                // Insertion Sort
                break;
            case 14:
                // Shell Sort
                break;
            case 15:
                // Sair
                return 0;
            default:
                cout << "Opção inválida!" << endl << endl;
                // Pula para o início do loop
                continue;
        }
        // Calcula tempo de execução
        auto timeEnd = Clock::now();
        auto timeDiff = duration_cast<milliseconds>(timeEnd - timeStart);

        // Exibe tempo de execução
        cout << "Tempo de execução: " << timeDiff.count() << " ms" << endl << endl;
    }
    return 0;
}

void printMenu()
{
    // ASCII art obtido de https://www.asciiart.eu/plants/bonsai-trees
    // por Corwyn Yasuo Miyagishima
    cout << "Manipulação de árvore:" << endl;
    cout <<
        " 1 - Ler árvore de um arquivo        ,.,\n"
        " 2 - Ler árvore de dados digitados  MMMM_    ,..,\n"
        " 3 - Altura da árvore                 \"_ \"__\"MMMMM          ,...,,\n"
        " 4 - Tamanho da árvore         ,..., __.\" --\"    ,.,     _-\"MMMMMMM\n"
        " 5 - Inserir elemento         MMMMMM\"___ \"_._   MMM\"_.\"\" _ \"\"\"\"\"\"\n"
        " 6 - Remover elemento          \"\"\"\"\"    \"\" , \\_.   \"_. .\"\n"
        " 7 - Buscar elemento                  ,., _\"__ \\__./ .\"\n"
        " 8 - Verificar se é completa         MMMMM_\"  \"_    ./\n"
        " 9 - Verificar se é perfeita          ''''      (    )\n"
        "10 - Exibir árvore             ._______________.-'____\"---._."
        << endl;

    cout << endl << "Ordenação de árvore:" << endl;
    cout << "11 - Bubble Sort" << endl;
    cout << "12 - Selection Sort" << endl;
    cout << "13 - Insertion Sort" << endl;
    cout << "14 - Shell Sort" << endl;

    cout << endl << "15 - Sair" << endl;
}