#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

template <typename T>
class Graph{
public:

    // Constructor por default
    Graph();

    ~Graph();
    Graph(const Graph &g);
    Graph & operator=(const Graph &g);


    void addNode(T value);
    void deleteNode(T value);

    void clear();
    void clearNode(T value);
    bool isEmpty() const;

    void addEdge(T first, T last);
    void deleteEdge(T first, T last);

    bool searchNode(T value) const;
    bool searchEdge(T first, T last) const;

    int nodeSize() const;
    int edgeSize() const;
    int getGrade(T value) const;

    void print() const;
    void printNode(T value) const;

private:
    int nodesSize, edgesSize;
    struct Node;

    struct Edge{
        Edge(Node *adj, Edge *next = nullptr, Edge *previous = nullptr);
        Node *adjacent;
        Edge *next, *previous;
    };

    struct Node {
        Node(T name, Node *next = nullptr, Node *previous = nullptr);
        void addEdgeInNode(Node *adj);
        void deleteNodesEdge(Node *adj);
        bool isNodeConnected() const;
        int isolateNode();
        Edge *searchNodeAddress(Node *adj);
        T value;
        int grade;
        Edge *firstE, *lastE;
        Node *next, *previous;
    } *firstN, *lastN;

    Node *getNodeAddress(T value) const;
};

#include "../templates/Graph.tpp"

#endif //GRAPH_GRAPH_H
