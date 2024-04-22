#ifndef GRAPHIC_HPP
#define GRAPHIC_HPP

template<typename T>
class Graphic {
public:
    Graphic();
    ~Graphic();

    Graphic(const Graphic<T> &g);

    Graphic<T> &operator=(const Graphic<T> &g);

    void add(T v); //agrega un vertice
    void add(T v1, T v2); //agrega una arista
    
    void deleteVertex(T v); //elimina vertice
    void deleteVertex(T v1, T v2); //elimina arista

    bool find(T v) const; //busca vertice
    bool find(T v1, T v2) const; //busca arist

    void empty();
    void empty(T v);
    bool isEmpty() const;
    
    int vertexSize() const;
    int edgeSize() const;
    int vertexGrade(T v) const;

    void print() const;
    void print(T v) const;

private:
    
    struct Vertex {
        T id;
        T grade;

        struct Edge {
            Edge(Vertex* adj, Edge* next_ = nullptr, Edge* last = nullptr);
            Vertex *adjacent;
            Edge *next_, *previous;
        } *first, *last;

        Vertex(T id, Vertex* next_ = nullptr, Vertex* previous = nullptr);
        Vertex *next, *previous;
        Edge* edge_dir(T v) const;
        void add(Vertex *ady);
        bool isEmpty();
        void disconnect();
        void disconnect(T v); 
    } *first, *last;
    int edges_;
    int vertex_size;

    Vertex* vertex_dir(T id) const;
};
#include "../templates/Graphic.tpp"

#endif
