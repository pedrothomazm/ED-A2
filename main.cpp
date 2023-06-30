#include <iostream>
#include "tree.h"
#include "sort.h"

using std::cout;
using std::endl;

// Protótipos de funções
void printMenu();

int main()
{
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