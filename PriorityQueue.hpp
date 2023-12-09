#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include <iostream>
#include <string>

#include "Vertex.hpp"
#include "VertexDictionary.hpp"

using namespace std;

class PriorityQueue{
public:
    PriorityQueue();

    ~PriorityQueue();

    void insertInPQ(Vertex *vertex);

    void heapify(int i);

    Vertex* extractMin();

    int get_size();

private: 
    VertexDictionary *priority_queue;
    int size;
};
#endif