#include <iostream>

/***********************************************************************************/
template <typename T>
Graphic<T>::Graphic()
: first(nullptr), last(nullptr), edges_(0), vertex_size(0) {}
/***********************************************************************************/

/***********************************************************************************/
template <typename T> Graphic<T>::~Graphic() { empty(); }
/***********************************************************************************/

/***********************************************************************************/
template <typename T> Graphic<T>::Graphic(const Graphic<T> &g) {}
/***********************************************************************************/

/***********************************************************************************/
template <typename T> Graphic<T> &Graphic<T>::operator=(const Graphic<T> &g) {}
/***********************************************************************************/

/***********************************************************************************/
template <typename T> void Graphic<T>::add(T v) {
    if (find(v))
        return;

    Vertex *aux = new Vertex(v, nullptr, last);
    if (isEmpty())
    {
        first = aux;
        last = aux;
    }
    else
    {
        last->next = aux;
        last = aux;
    }
    ++vertex_size;
}
/***********************************************************************************/

/***********************************************************************************/
template <typename T> void Graphic<T>::add(T v1, T v2) {
    Vertex* vertex1 = vertex_dir(v1);
    Vertex* vertex2 = vertex_dir(v2);

    if (vertex1 == nullptr || vertex2 == nullptr)
        return;

    if(find(v1, v2)) return;

    vertex1->add(vertex2);
    vertex2->add(vertex1);
    
    ++edges_;
}
/***********************************************************************************/

/***********************************************************************************/
template <typename T> void Graphic<T>::deleteVertex(T v) {
    if(!find(v)) return;
    empty(v);
    Vertex* aux = vertex_dir(v);

    //(aux == last ? last : 
    if (aux->id == first->id) {
        first = aux->next;
        if(first == nullptr) last = nullptr;
        else
            first->previous = nullptr;
    }
    else if (aux->id == last->id) {
        aux = last;
        if (vertexSize() == 1) {
            first = last = nullptr;
        } else {
            last = last->previous;
            last->next = nullptr;
        }
    }
    else
    {
        aux->previous->next = aux->next;
        aux->next->previous = aux->previous;
    }
    delete aux;
    --vertex_size;
}
/***********************************************************************************/

/***********************************************************************************/
template <typename T> void Graphic<T>::deleteVertex(T v1, T v2) {
    if(!find(v1, v2)) return;
    vertex_dir(v1)->disconnect(v2);
    vertex_dir(v2)->disconnect(v1);
    --edges_;
}
/***********************************************************************************/

/***********************************************************************************/
template <typename T> bool Graphic<T>::find(T v) const {
    return vertex_dir(v) != nullptr;
}
/***********************************************************************************/

/***********************************************************************************/
template <typename T> bool Graphic<T>::find(T v1, T v2) const {
    return vertex_dir(v1)->edge_dir(v2) != nullptr;
}
/***********************************************************************************/

/***********************************************************************************/
template <typename T> void Graphic<T>::empty() {
    Vertex *aux = first;

    while (!isEmpty()) {
        std::cout << "size: " << vertexSize() << "  id: " << aux->id << std::endl;
        deleteVertex(aux->id);
        aux = aux->next;
        print();
    }
}
/***********************************************************************************/

/***********************************************************************************/
template <typename T> void Graphic<T>::empty(T v) {
    if(!find(v)) return;
    Vertex *aux = vertex_dir(v);
    while (!aux->isEmpty()) {
        deleteVertex(v, aux->last->adjacent->id);
    }
}
/***********************************************************************************/

/***********************************************************************************/
template <typename T> bool Graphic<T>::isEmpty() const {
  return vertex_size == 0;
}
/***********************************************************************************/

/***********************************************************************************/
template <typename T> int Graphic<T>::vertexSize() const { return vertex_size; }
/***********************************************************************************/

/***********************************************************************************/
template <typename T> int Graphic<T>::edgeSize() const { return edges_; }
/***********************************************************************************/

/***********************************************************************************/
template <typename T> int Graphic<T>::vertexGrade(T v) const {
    Vertex* g = vertex_dir(v);
    return (g == nullptr) ? 0 : g->grade; }
/***********************************************************************************/

/***********************************************************************************/
template <typename T> void Graphic<T>::print() const {
    if (isEmpty()) {
        std::cout << "Esta vacio " << std::endl;
        return;
    }
    typename Graphic<T>::Vertex* aux = first;
    typename Graphic<T>::Vertex::Edge* eaux = nullptr;
    for (int i = 0; i < vertex_size; ++i) {
        std::cout << aux->id << ": ";
        eaux = aux->first;
        //std::cout << aux->grade;
        for (int i = 0; i < aux->grade; ++i) {
            std::cout << eaux->adjacent->id << ", ";
            eaux = eaux->next_;
        }
        std::cout << std::endl;
        aux = aux->next;
  }
}
template <typename T> void Graphic<T>::print(T v) const {}
/***********************************************************************************/

/***********************************************************************************/
template <typename T> Graphic<T>::Vertex* Graphic<T>::vertex_dir(T v) const {
    Vertex* aux = first;
    for (int i = 0; i < vertex_size; ++i) {
        if(aux->id == v) return aux;
        aux = aux->next;
    }
    return nullptr;
}
/***********************************************************************************/

/***********************************************************************************/
template <typename T>
Graphic<T>::Vertex::Vertex(T id, Vertex *next_, Vertex *previous) : id(id), grade(0), next(next_), previous(previous) {}
/***********************************************************************************/

/***********************************************************************************/
template <typename T> void Graphic<T>::Vertex::add(Vertex *adj) {
    Edge* aux = new Edge(adj, nullptr, last);
    (isEmpty() ? first : last->next_) = aux;
    last = aux;
    ++grade;
}
/***********************************************************************************/
//desconecta la ultima arista
/***********************************************************************************/
template <typename T> void Graphic<T>::Vertex::disconnect() {
    Edge* aux = last;
    if (grade == 1) {
        first = last = nullptr;
    } else {
        last = last->previous;
        last->next_ = nullptr;
    }
    delete aux;
    --grade;
}
/***********************************************************************************/
//desconecta una arista deseada
/***********************************************************************************/
template <typename T> void Graphic<T>::Vertex::disconnect(T v) {
    Vertex::Edge *aux = first;
    if (v == first->adjacent->id) {
        first = first->next_;
    } else if (v == last->adjacent->id) {
        aux = last;
        if (grade == 1) {
            first = last = nullptr;
        }else{
            last = last->previous;
            last->next_ = nullptr;
        }
    }
    else {
        Vertex::Edge *after = first;
        for (int i = 1; after->next_->adjacent->id != v ; ++i)
            after = after->next_;
        aux = after->next_;
        after->next_ = aux->next_;
    }
    delete aux;
    --grade;
}
/***********************************************************************************/

/***********************************************************************************/
template <typename T> bool Graphic<T>::Vertex::isEmpty() {
    return grade == 0;
}
/***********************************************************************************/

/***********************************************************************************/
template <typename T>
Graphic<T>::Vertex::Edge::Edge(Vertex* adj, Edge* next_, Edge* previous) : adjacent(adj), next_(next_), previous(previous){}
/***********************************************************************************/

/***********************************************************************************/
template <typename T> Graphic<T>::Vertex::Edge* Graphic<T>::Vertex::edge_dir(T v) const {
    Edge* aux = first;
    for (int i = 0; i < grade; ++i) {
        if(aux->adjacent->id == v) return aux;
        aux = aux->next_;
    }
    return nullptr;
}
/***********************************************************************************/
