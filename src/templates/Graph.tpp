#include <iostream>

//**************************************************************************
// Constructor por default
template <typename T>
Graph<T>::Graph()
    : nodesSize(0), edgesSize(0), firstN(nullptr), lastN(nullptr) {}
//**************************************************************************
// Metodo destructor
template <typename T> Graph<T>::~Graph() { clear(); }
//**************************************************************************
// Metodo constructor de copias
template <typename T>
Graph<T>::Graph(const Graph<T> &g)
    : nodesSize(0), edgesSize(0), firstN(nullptr), lastN(nullptr) {
  *this = g;
}
//**************************************************************************
// Metodo operador igual
template <typename T> Graph<T> &Graph<T>::operator=(const Graph<T> &g) {
  if (this == &g)
    return *this;

  // limpiar totalmente la grafica actual
  clear();

  Node *tmpN = g.firstN;

  // Copiando los nodos
  while (tmpN != nullptr) {
    addNode(tmpN->value);
    tmpN = tmpN->next;
  }

  // Copiando los vertices
  tmpN = g.firstN;

  while (tmpN != nullptr) {
    Node *currentNode = getNodeAddress(tmpN->value);
    Edge *tmpE = tmpN->firstE;

    while (tmpE != nullptr) {
      Node *adjacentN = getNodeAddress(tmpE->adjacent->value);
      addEdge(currentNode->value, adjacentN->value);
      tmpE = tmpE->next;
    }

    tmpN = tmpN->next;
  }

  return *this;
}
//**************************************************************************
// Metodo para agregar nodo
template <typename T> void Graph<T>::addNode(T value) {
  if (!searchNode(value)) {
    Node *newN = new Node(value, nullptr, lastN);
    (isEmpty() ? firstN : lastN->next) = newN;
    lastN = newN;
    ++nodesSize;
  }
}
//**************************************************************************
// Metodo para eliminar nodo
template <typename T> void Graph<T>::deleteNode(T value) {
  // Nodo por borrar
  Node *tmp = getNodeAddress(value);
  if (tmp == nullptr)
    return;

  // Borrar nodo de la lista enlazada
  if (tmp == firstN) {
    firstN = tmp->next;
  } else {
    tmp->previous->next = tmp->next;
  }

  if (tmp == lastN) {
    lastN = tmp->previous;
  } else {
    tmp->next->previous = tmp->previous;
  }

  edgesSize -= tmp->isolateNode();

  delete tmp;
  --nodesSize;
}
//**************************************************************************
// Metodo para vaciar el grafo
// :)
template <typename T> void Graph<T>::clear() {
  // Nodo temporal que vaciara todos los nodos del grafo
  Node *tmpN = firstN;
  Node *tmpN2;

  while (tmpN != nullptr) {
    // Aristas temporales que vaciara todas las arista de cada nodo
    Edge *tmpE = tmpN->firstE;
    Edge *tmpE2;

    while (tmpE != nullptr) {
      tmpE2 = tmpE->next;
      delete tmpE;
      tmpE = tmpE2;
    }

    tmpN2 = tmpN->next;
    delete tmpN;
    tmpN = tmpN2;
  }

  firstN = lastN = nullptr;
  nodesSize = edgesSize = 0;
}
//**************************************************************************
// Metodo para vaciar un nodo
// :)
template <typename T> void Graph<T>::clearNode(T value) {
  // Si no existe tal nodo se tira una excepcion
  if (!searchNode(value))
    throw "No existe tal nodo";

  // Nodo a vaciar
  Node *tmpN = getNodeAddress(value);

  // Remover todas las aristas del nodo
  edgesSize -= tmpN->isolateNode();
}
//**************************************************************************
// Metodo para verificar si el grafo esta vacio o no
// :)
template <typename T> bool Graph<T>::isEmpty() const {
  return nodesSize == 0 && edgesSize == 0;
}
//**************************************************************************
// Metodo para agregar una arista al nodo
template <typename T> void Graph<T>::addEdge(T first, T last, int weight) {
  Node *beginningPtr = getNodeAddress(first);
  if (beginningPtr == nullptr)
    return;

  Node *endPtr = getNodeAddress(last);
  if (endPtr == nullptr)
    return;

  if (searchEdge(first, last))
    return;
  beginningPtr->addEdgeInNode(endPtr, weight);
  endPtr->addEdgeInNode(beginningPtr, weight);
  ++edgesSize;
}
//**************************************************************************
// Metodo eliminar aristas de los nodos conectados
// :)
template <typename T> void Graph<T>::deleteEdge(T first, T last) {
  // Nodos correspondientes a su valor
  Node *firstNode = getNodeAddress(first);
  Node *lastNode = getNodeAddress(last);

  if (firstNode == nullptr || lastNode == nullptr || !searchEdge(first, last))
    return;

  // Eliminar aristas de los dos nodos conectados
  firstNode->deleteNodesEdge(lastNode);
  lastNode->deleteNodesEdge(firstNode);
  --edgesSize;
}
//**************************************************************************
// Metodo para verificar si existe el nodo en el grafo
// :)
template <typename T> bool Graph<T>::searchNode(T value) const {
  return getNodeAddress(value) != nullptr;
}
//**************************************************************************
// Metodo para verificar que dos nodos esten correctamente conectados
// :)
template <typename T> bool Graph<T>::searchEdge(T first, T last) const {
  // Nodos a verificar si estan conectados
  Node *firstNode = getNodeAddress(first);
  Node *lastNode = getNodeAddress(last);

  if (firstNode == nullptr || lastNode == nullptr ||
      firstNode->firstE == nullptr || lastNode->firstE == nullptr)
    return false;

  // Puntero a arista a primer nodo que verificara si es adyacente con el otro
  // nodo
  Edge *tmpE = firstNode->firstE;

  while (tmpE != nullptr) {
    // Si es adyacente regresa true
    if (tmpE->adjacent == lastNode)
      return true;

    tmpE = tmpE->next;
  }

  return false;
}
//**************************************************************************
// Metodo que regresa la cantidad de nodos que hay en el grafo
// :)
template <typename T> int Graph<T>::nodeSize() const { return nodesSize; }
//**************************************************************************
// Metodo que regresa la cantidad de aristas que hay en el grafo
// :)
template <typename T> int Graph<T>::edgeSize() const { return edgesSize; }
//**************************************************************************
// Metodo que regresa la potencia de un nodo
// :)
template <typename T> int Graph<T>::getGrade(T value) const {
  // Puntero a nodo para obtener su ubicacion
  Node *tmpN = getNodeAddress(value);

  // Si el nodo no existe se regresa 0
  if (tmpN == nullptr)
    return 0;

  return tmpN->grade;
}
//**************************************************************************
// Metodo para imprimir todo el grafo
// :)
template <typename T> void Graph<T>::print() const {
  Node *tmpN = firstN;

  if (tmpN == nullptr) {
    std::cout << "Graph empty" << std::endl;
    return;
  }
  Edge *tmpE = nullptr;
  while (tmpN != nullptr) {
    std::cout << tmpN->value << ":  ";

    tmpE = tmpN->firstE;
    while (tmpE != nullptr) {
      std::cout << "(" << tmpE->adjacent->value << ", " << tmpE->weight << ")"
                << ", ";
      tmpE = tmpE->next;
    }

    std::cout << "\b\b ";
    std::cout << "\n";
    tmpN = tmpN->next;
  }
}
//**************************************************************************
// Metodo para imprmir valores del nodo
//:)
template <typename T> void Graph<T>::printNode(T value) const {
  // Puntero a nodo temporal
  Node *tmpN = getNodeAddress(value);

  if (tmpN == nullptr)
    throw "El nodo no existe";

  std::cout << "El nodo con el valor " << tmpN->value
            << "tiene una potencia de " << tmpN->grade
            << "y esta conectado con los nodos siguientes: " << std::endl;

  // Puntero a la primera arista del nodo
  Edge *tmpE = tmpN->firstE;

  while (tmpE != nullptr) {
    std::cout << tmpE->adjacent->value << std::endl;
    tmpE = tmpE->next;
  }
}
//**************************************************************************
// Metodo constructor del nodo
template <typename T>
Graph<T>::Node::Node(T name, Graph<T>::Node *next /* nullptr */,
                     Graph<T>::Node *previous /* nullptr */, bool isMarked)
    : value(name), grade(0), firstE(nullptr), lastE(nullptr), next(next),
      previous(previous), isMarked(isMarked) {}

//**************************************************************************
// Metodo para agregar una nueva arista a un nodo
template <typename T>
void Graph<T>::Node::addEdgeInNode(Graph::Node *adj, int weight) {
  Graph<T>::Edge *newE = new Graph<T>::Edge(adj, nullptr, lastE, weight);
  (isNodeConnected() ? firstE : lastE->next) = newE;
  lastE = newE;
  ++grade;
}
//**************************************************************************
// Metodo que aisla a un nodo
template <typename T> int Graph<T>::Node::isolateNode() {
  int edgeNum = grade;
  while (!isNodeConnected()) {
    firstE->adjacent->deleteNodesEdge(this);
    deleteNodesEdge(firstE->adjacent);
  }

  return edgeNum;
}
//**************************************************************************
// Metodo que verifica si un nodoe sta conectado
template <typename T> bool Graph<T>::Node::isNodeConnected() const {
  return grade == 0;
}
//**************************************************************************
// Metodo que elimina las aristas de un nodo
template <typename T> void Graph<T>::Node::deleteNodesEdge(Graph::Node *adj) {
  // Por borrar
  Edge *aux = searchNodeAddress(adj);

  if (aux == nullptr)
    return;

  (aux == firstE ? firstE : aux->previous->next) = aux->next;
  (aux == lastE ? lastE : aux->next->previous) = aux->previous;
  delete aux;
  --grade;
}
//**************************************************************************
// Metodo que devuelve un puntero a la arista del nodo adyacente
// **preguntar maestra por este
template <typename T>
typename Graph<T>::Edge *Graph<T>::Node::searchNodeAddress(Graph::Node *adj) {
  Edge *aux = firstE;
  while (aux != nullptr && aux->adjacent != adj) {
    aux = aux->next;
  }

  return aux;
}

//**************************************************************************
// Metodo constructor de la arista
template <typename T>
Graph<T>::Edge::Edge(Graph<T>::Node *adj, Graph<T>::Edge *next /* nullptr */,
                     Graph<T>::Edge *previous /* nullptr */, int weight,
                     bool isMarked)
    : adjacent(adj), next(next), previous(previous), weight(weight),
      isMarked(isMarked) {}
//**************************************************************************
// Metodo que devuelve un puntero a direccion en memoria de un nodo
template <typename T>
typename Graph<T>::Node *Graph<T>::getNodeAddress(T value) const {
  Node *aux = firstN;
  while (aux != nullptr && aux->value != value) {
    aux = aux->next;
  }

  return aux;
}
//************************************************************************************

template <typename T> int Graph<T>::Prim(T vertex) const {
    
    Node *v = getNodeAddress(vertex);
    if (v == nullptr)
        return 0;
    
    int total_weight = 0;
    int visit_node = 1;
    int less_weight = v->firstE->weight;
    
    DoublyLinkedList<Graph<T>::Node *> nodes_marked;
    
    nodes_marked.insertLast(v);

    Edge *e = v->firstE;
    Edge *aux = e;

    while (visit_node < nodesSize) {
        for (int i = 0; i < nodes_marked.size(); ++i) {
            aux = nodes_marked[i]->firstE;
            for (int j = 0; j < nodes_marked[i]->grade; ++j) {
                if(nodes_marked.searchValue(aux->adjacent)) {
                    aux = aux->next;
                    continue;
                }
                if (aux->weight <= less_weight || less_weight == -1) {
                    less_weight = aux->weight;
                    e = aux;
                }
                aux = aux->next;
            }
        }

        v = e->adjacent;
        ++visit_node; 
        total_weight += e->weight;
        if(!nodes_marked.searchValue(v))
            nodes_marked.insertLast(v);

        less_weight = -1;
    }
    print(nodes_marked, total_weight);
    if(nodes_marked.size() < nodesSize) throw "No es conexa";
    return total_weight;
}
//************************************************************************************
template <typename T>
void Graph<T>::print(const DoublyLinkedList<Node *>& l, int weight) const{
    std::cout << "[g = (";
    for(int i = 0; i < l.size(); ++i){
        std::cout << l[i]->value << ", ";
    }
    std::cout << "\b\b), w = " << weight << "]\n";
}
//************************************************************************************
