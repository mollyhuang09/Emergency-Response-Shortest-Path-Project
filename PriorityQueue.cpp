#include "PriorityQueue.hpp"

PriorityQueue::PriorityQueue(){
    priority_queue = new VertexDictionary();
    size = 0;
}

PriorityQueue::~PriorityQueue(){
    delete priority_queue;
}

void PriorityQueue::insertInPQ(Vertex *vertex){

    size ++;

    int index = size-1;

    priority_queue->addVertex(vertex);

    int parent_index = (index-1)/2;

    while (index != 0 && priority_queue->get_traveltime(parent_index) > priority_queue->get_traveltime(index)){
        priority_queue->swapVertices(index, parent_index);
        index = parent_index;
    }
}

Vertex* PriorityQueue::extractMin(){
    Vertex *root_vertex;
    
    if (size == 0){
        return nullptr;
    }else if(size == 1){
        size --;
        root_vertex = priority_queue->get_vertex(0);
        return root_vertex;
    }else{
        root_vertex = priority_queue->get_vertex(0);
        priority_queue->set_vertex(0,priority_queue->get_vertex(size-1));
        size --;
        heapify(0);

        return root_vertex;
    }
}

void PriorityQueue::heapify(int i){
    int left = 2*i+1;
    int right = 2*i+2;
    int smallest = i;

    if (left < size && priority_queue->get_traveltime(left) < priority_queue->get_traveltime(i)){
        smallest = left;
    }

    if (right < size && priority_queue->get_traveltime(right) < priority_queue->get_traveltime(smallest)){
        smallest = right;
    }

    if (smallest != i){
        priority_queue->swapVertices(i, smallest);
        heapify(smallest);
    }
}

int PriorityQueue::get_size(){return size;}