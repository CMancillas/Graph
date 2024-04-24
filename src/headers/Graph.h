/**
* \file Graph.hpp
 * \brief Implementacion de la clase Graph.
 * \author Braulio Alessandro Sánchez Bermúdez
 * \author Carlos Enrique Mancillas Duran
 * \date 23/04/2024
 * */



#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

/** \class Graph
*
* Esta clase template ofrece una implementaci&oacute;n de grafo (grafica)
para agregar,
* eliminar elementos, y consultar el valor de cada nodo (vertice), entre otras.
*
* \tparam T Tipo de elementos almacenados en el grafo.
*
*
***/

template <typename T>
class Graph{
public:

    /**
    ** \brief Constructor por defecto que inicializa un grafo
    */
    Graph();

    /**
    * \brief Destructor que libera la memoria deL grafo.
    */
    ~Graph();

    /**
     * \brief Constructor de copia.
     * @param g Otro grafo de la cual se copiar&aacute;n los elementos.
     */
    Graph(const Graph &g);

    /**
     *  \brief Sobrecarga del operador de asignaci&oacute;n.
     * @param g Otro grafo del cual se copiar&aacute;n los elementos.
     * @return Referencia al grafo actual.
     */
    Graph & operator=(const Graph &g);

    /**
     * 
    * \brief Agrega un nuevo nodo al grafo.
     * @param value El valor del nodo a agregar.
     */
    void addNode(T value);

    /**
     * \brief Elimina un nodo del grafo.
     * @param value El nodo a eliminar.
     */
    void deleteNode(T value);

    /**
     * \brief Vacia el grafo.
     */
    void clear();

     /**
     *\brief Vacia el nodo a eligir.
     * @param value El nodo a vaciar.
     */
    void clearNode(T value);

    /**
     * \brief Verifica si el grafo esta vacio.
     * @return true si esta vacio, false en otro caso.
     */
    bool isEmpty() const;

    /**
     *
     * \brief Agrega un nuevo vertice a los nodos seleccionado del grafo.
     * @param first El primer nodo a conectar.
     * @param last El nodo a conectar con el primer nodo.
     */
    void addEdge(T first, T last);

    /**
     *
     * \brief Elimina un vertice existente a los nodos seleccionado del grafo.
     * @param first El primer nodo a desconectar.
     * @param last El nodo a desconectar con el primer nodo.
     */
    void deleteEdge(T first, T last);

    /**
     * \brief Busca un nodo en el grafo.
     * @param value Valor a verificar si esta en el grafo.
     * @return true si el nodo se encuentra en el grafo, false en otro caso.
     */
    bool searchNode(T value) const;

    /**
     * \brief Busca una arista en el grafo.
     * @param first Primer nodo conectado a la arista.
     * @param last Segundo/Ultimo nodo conectado a la arista.
     * @return true si la arista se encuentra en el grafo, false en otro caso.
     */
    bool searchEdge(T first, T last) const;

    /**
     * \brief Cuenta el numero de nodos que se encuentran en el grafo.
     * @return Numero de nodos que se encuentran en el grafo.
     */
    int nodeSize() const;

    /**
     * \brief Cuenta el numero de aristas que se encuentran en el grafo.
     * @return Numero de aristas que se encuentran en el grafo.
     */
    int edgeSize() const;

    /**
     * \brief Calcula la potencia de un nodo especifico.
     * @param value Nodo a calcular su potencia.
     * @return Potencia del nodo.
     */
    int getGrade(T value) const;

    /**
     * \brief Imprime el grafo completo.
     */
    void print() const;

    /**
     * \brief Imprime las aristas del nodo a especificar.
     * @param value Nodo a imprimir.
     */
    void printNode(T value) const;

private:
    int nodesSize, edgesSize;
    struct Node;

    struct Edge{
        Edge(Node *adj, Edge *next = nullptr, Edge *previous = nullptr, int weight = 0);
        Node *adjacent;
        Edge *next, *previous;
        int weight;
    };

    struct Node {
        Node(T name, Node *next = nullptr, Node *previous = nullptr);

        /**
         * \brief Conecta los nodos con una arista.
         * @param adj Nodo adyacente que sera conectado.
         */
        void addEdgeInNode(Node *adj);

        /**
         * \brief Elimina la arista de los nodos conectados.
         * @param adj Nodo adyacente que sera desconectado.
         */
        void deleteNodesEdge(Node *adj);

        /**
         * \brief Verifica si el nodo esta conectado.
         * @return true si esta conectado, false en otro caso.
         */
        bool isNodeConnected() const;

        /**
         * \brief Aisla el nodo.
         * @return tama;o de la potencia del nodo.
         */
        int isolateNode();

        /**
         * \brief Busca la ubicacion en memoria del nodo.
         * @param adj Nodo adyacente que sera buscado.
         * @return Puntero arista al nodo.
         */
        Edge *searchNodeAddress(Node *adj);
        T value;
        int grade;
        Edge *firstE, *lastE;
        Node *next, *previous;
    } *firstN, *lastN;

    /**
     * \brief Obtiene la ubicacion en memoria del nodo.
     * @param value Nodo a buscar.
     * @return Puntero a nodo con la ubicacion de memoria.
     */
    Node *getNodeAddress(T value) const;
};

#include "../templates/Graph.tpp"

#endif //GRAPH_GRAPH_H
