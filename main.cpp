#include <iostream>
#include <chrono>
#include "tree.h"
#include "sort.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
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
        
        // Variável auxiliar para leitura de dados
        int iData;

        // Registra tempo de execução
        auto timeStart = Clock::now();

        cout << "============================================" << endl << endl;

        // Executa a opção escolhida
        switch (iOption) {
            case 1: {
                // Deletar árvore atual
                deleteTree(ptrRoot);

                // Ler nome do arquivo
                string sFilename;
                cout << "Digite o caminho absoluto do arquivo: ";
                cin >> sFilename;

                // Ler árvore de um arquivo
                ptrRoot = buildTreeFromFile(sFilename);
                break;
            }
            case 2:
                // Deletar árvore atual
                deleteTree(ptrRoot);

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
                cout << "Digite o número a ser inserido: ";
                cin >> iData;
                insertElement(ptrRoot, iData);
                break;
            case 6:
                // Ler elemento
                cout << "Digite o número a ser removido: ";
                cin >> iData;

                // Remover elemento
                ptrRoot = removeNode(ptrRoot, iData);
                break;
            case 7: {
                // Ler elemento
                cout << "Digite o número a ser buscado: ";
                cin >> iData;

                // Buscar elemento
                struct TreeNode* ptrNode = findAddress(ptrRoot, iData);
                if (ptrNode != nullptr)
                    cout << "Elemento encontrado! " << ptrNode << endl;
                else
                    cout << "Elemento não encontrado!" << endl;
                break;
            }
            case 8:
                // Verificar se é completa
                if (completeTree(ptrRoot, 0, getSize(ptrRoot)))
                    cout << "A árvore é completa!" << endl;
                else
                    cout << "A árvore não é completa!" << endl;
                break;
            case 9:
                // Verificar se é perfeita
                if (perfectTree(ptrRoot, getHeight(ptrRoot), 0))
                    cout << "A árvore é perfeita!" << endl;
                else
                    cout << "A árvore não é perfeita!" << endl;
                break;
            case 10:
                // Exibir árvore
                printTree(ptrRoot);
                break;
            case 11:
                // Bubble Sort
                bubbleSort(ptrRoot);
                cout << "Árvore ordenada usando Bubble Sort." << endl;
                break;
            case 12:
                // Selection Sort
                selectionSort(ptrRoot);
                cout << "Árvore ordenada usando Selection Sort." << endl;
                break;
            case 13: {
                // Insertion Sort
                TreeNode* ptrList = nullptr;
                treeToList(ptrRoot, ptrList);
                insertionSort(ptrList);
                ptrRoot = ptrList;
                cout << "Árvore ordenada usando Insertion Sort." << endl;
                break;
            }
            case 14:
                // Shell Sort
                shellSort(ptrRoot);
                cout << "Árvore ordenada usando Shell Sort." << endl;
                break;
            case 15:
                // Sair
                return 0;
            default:
                cout << "Opção inválida!" << endl << endl;
                // Pula para o início do loop
                continue;
        }
        cout << endl << "============================================" << endl;

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
