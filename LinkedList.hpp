#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "Vertex.hpp"
#include "VertexDictionary.hpp"
#include "PriorityQueue.hpp"

#include <iostream>
#include <string>

using namespace std; 

class LinkedList {
public: 
    //constructor
    LinkedList(); 

    //destructor
    ~LinkedList();

    void addNewEdge(int vertex, double d, double s, int A);

    bool checkEdge(int intersection_num, double d, double s);

    bool checkEdge(int intersection_num);

    void printVertices();

    VertexDictionary* deleteVertices();

    void deleteVertex(int intersection);

    bool updateAdjFactor(int intersection, int A);

    void addToQueue(PriorityQueue *priority_queue);

    //void traverseAdj(PriorityQueue *priority_queue);

    int findVertex(int intersection);

    Vertex* get_head();

private: 
    Vertex *head_vertex;
};

#endif