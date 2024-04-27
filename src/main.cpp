#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "headers/Graph.hpp"

using namespace std;
int main() {


    try{
    srand(time(NULL));

    Graph<int> g1, g2;

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

            g1.addEdge(i, randNode, rand()%9);
        }

    }

    g1.print();
    g2 = g1;
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

    cout << "Grado del nodo 1: " << g1.getGrade(1) << endl;

    cout << "Limpiaremos el nodo 1: " << endl;
    //g1.clearNode(1);
    g1.print();


    // CHECAR
    cout << "El grafo no esta vacio, tiene  " << g1.nodeSize() << " nodos, con " <<
           g1.edgeSize() << " aristas." << endl;

    // OPERADOR IGUAL

    cout << "Copiando grafo:" << endl;
    g2.print(); 
    //BUSQUEDAS

    cout << "conexion entre el nodo 1 y el 2" << endl;
    if(g2.searchEdge(1, 2)) cout << "Si hay conexion\n";
    else cout << "No hay conexion\n";

    cout<< "G1 Prim: " << g1.Prim(3) << std::endl;
    cout<< "G2 Prim: " << g2.Prim(4) << std::endl;
    
    //LIMPIAR
    cout << "Vaciando grafo:" << endl;
    g1.clear();
    g1.print(); 

    }catch(const char* msg){
        std::cout << msg << std::endl;
    }
    return 0;
}
