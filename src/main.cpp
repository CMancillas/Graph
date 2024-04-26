#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "headers/Graph.hpp"

using namespace std;
int main() {


    srand(time(NULL));

    Graph<int> g1;
    Graph<char> g2;

    // Agregando nodos
    for (int i = 97; i <= 105; ++i)
    {
        g2.addNode(i);
    }

    g2.addEdge('a', 'b',3); 
    g2.addEdge('a', 'c',1);
    g2.addEdge('a', 'd',6);
    g2.addEdge('b', 'c',1); 
    g2.addEdge('b', 'e',2);
    g2.addEdge('b', 'g',7);
    g2.addEdge('c', 'e',6);
    g2.addEdge('d', 'f',4);
    g2.addEdge('d', 'i',5);
    g2.addEdge('e', 'f',3);
    g2.addEdge('e', 'h',2); 
    g2.addEdge('f', 'i',2);
    g2.addEdge('g', 'h',1);
    g2.addEdge('g', 'i',2);
    g2.addEdge('h', 'i',3);

    g2.print(); 
    std::cout << g2.Prim('a') << "\n\n\n\n";
   
    // Agregando nodos
    for (int i = 0; i < 9; ++i)
    {
        g1.addNode(i);
    }

    g1.addEdge(0, 1,4);
    g1.addEdge(0, 7,8);
    g1.addEdge(1, 2,8);
    g1.addEdge(1, 7,11); 
    g1.addEdge(2, 3,7);
    g1.addEdge(2, 8,2);
    g1.addEdge(2, 5,4);
    g1.addEdge(3, 4,9);
    g1.addEdge(3, 5,14);
    g1.addEdge(4, 5,10);
    g1.addEdge(5, 6,2);
    g1.addEdge(6, 7,1);
    g1.addEdge(6, 8,6);
    g1.addEdge(7, 8,7);
    //g1.addEdge('h', 'i',3);
      g1.print(); 
    std::cout << g1.Prim(0) << '\n';

    // cout << "Conectaremos los nodos: " << endl;
    // for (int i = 1; i <= 5; ++i)
    // {

    //     for (int j = 0; j < 4; ++j)
    //     {
    //         int randNode;
    //         do
    //         {
    //             randNode = rand() % 5 + 1;
    //         } while (randNode == i);

    //         g1.addEdge(i, randNode);
    //     }

    // }

    // g1.print();
    // g2 = g1;
    // cout << "El grafo no esta vacio, tiene  " << g1.nodeSize() << " nodos, con " <<
    //       g1.edgeSize() << " aristas." << endl;
    // cout << "Quitaremos el nodo 2 del grafo: " << endl;
    // g1.deleteNode(2);
    // g1.print();

    // if (g1.isEmpty())
    // {
    //     cout << "El grafo esta vacio. " << endl;
    // }
    // else
    // {
    //     cout << "El grafo no esta vacio, tiene  " << g1.nodeSize() << " nodos, con " <<
    //        g1.edgeSize() << " aristas." << endl;
    // }

    // cout << "Grado del nodo 1: " << g1.getGrade(1) << endl;

    // cout << "Limpiaremos el nodo 1: " << endl;
    // g1.clearNode(1);
    // g1.print();


    // // CHECAR
    // cout << "El grafo no esta vacio, tiene  " << g1.nodeSize() << " nodos, con " <<
    //        g1.edgeSize() << " aristas." << endl;

    // // OPERADOR IGUAL

    // cout << "Copiando grafo:" << endl;
    // g2.print(); 
    // //BUSQUEDAS

    // cout << "conexion entre el nodo 1 y el 2" << endl;
    // if(g2.searchEdge(1, 2)) cout << "Si hay conexion\n";
    // else cout << "No hay conexion\n";

    // //LIMPIAR
    // cout << "Vaciando grafo:" << endl;
    // g1.clear();
    // g1.print(); 


    return 0;
}
