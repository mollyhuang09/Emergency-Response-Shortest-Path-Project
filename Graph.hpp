#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <string> 
#include <fstream>

#include "Vertex.hpp"
#include "LinkedList.hpp"
#include "VertexDictionary.hpp"
#include "PriorityQueue.hpp"

using namespace std;

class Graph {
public: 
    //constructor
    Graph();

    //destructor
    ~Graph();

    void loadFile(fstream& fin);

    void insert(int a, int b, double d, double s);

    void printAdjVertices(int a);
    
    void deleteVertex(int a);

    void updateAdjustmentFactor(int a, int b, int A);

    void findPath(int a, int b);

    void updateFile(fstream& fin);

    void findLowest(int a, int b);

private:
    //a pointer variable pointing to pointers of instances of Vertex objects
    LinkedList **adjacency_list;
    VertexDictionary *vertex_dictionary;
};

#endif
