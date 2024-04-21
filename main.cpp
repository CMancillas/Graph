#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Graph.h"

using namespace std;
int main() {


    srand(time(NULL));

    Graph<int> g1;

    // Agregando nodos
    for (int i = 1; i <= 5; ++i)
    {
        g1.addNode(i);
    }


    cout << "Conectaremos los nodos: " << endl;
    for (int i = 1; i <= 5; ++i)
    {

        for (int j = 0; j < 4; ++j)
        {
            int randNode;
            do
            {
                randNode = rand() % 5 + 1;
            } while (randNode == i);

            g1.addEdge(i, randNode);
        }

    }

    g1.print();
    cout << "El grafo no esta vacio, tiene  " << g1.nodeSize() << " nodos, con " <<
          g1.edgeSize() << " aristas." << endl;
    cout << "Quitaremos el nodo 2 del grafo: " << endl;
    g1.deleteNode(2);
    g1.print();

    if (g1.isEmpty())
    {
        cout << "El grafo esta vacio. " << endl;
    }
    else
    {
        cout << "El grafo no esta vacio, tiene  " << g1.nodeSize() << " nodos, con " <<
           g1.edgeSize() << " aristas." << endl;
    }

    cout << "Potencia del nodo 1: " << g1.getPow(1) << endl;

    cout << "Limpiaremos el nodo 1: " << endl;
    g1.clearNode(1);
    g1.print();


    // CHECAR
    cout << "El grafo no esta vacio, tiene  " << g1.nodeSize() << " nodos, con " <<
           g1.edgeSize() << " aristas." << endl;

    // OPERADOR IGUAL

    //BUSQUEDAS



    return 0;
}
