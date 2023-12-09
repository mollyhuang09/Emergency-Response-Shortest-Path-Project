#ifndef VERTEXDICTIONARY_HPP
#define VERTEXDICTIONARY_HPP

#include <iostream>
#include <string>

#include "Vertex.hpp"

using namespace std;

class VertexDictionary {
public: 
    VertexDictionary();

    ~VertexDictionary();

    bool checkVertex(int intersection);

    void addVertex(Vertex *vertex);

    void swapVertices (int index, int parent_index);

    int get_size();

    int getIntersection(int i);

    double get_traveltime(int i);

    Vertex* get_vertex(int i);

    void set_vertex(int i, Vertex *vertex);

    void set_traveltime(int i, double t);

private:
    int size;
    int capacity;
    Vertex **vertex_array;
};



#endif