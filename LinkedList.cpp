#include "LinkedList.hpp"

#include <iostream>
#include <string>

using namespace std; 

LinkedList::LinkedList(){
    head_vertex = 0;
}

LinkedList::~LinkedList(){
    Vertex *current_vertex = head_vertex;

    while (head_vertex != nullptr){
        head_vertex = head_vertex->get_next();
        delete current_vertex;
        current_vertex = nullptr; 
        current_vertex = head_vertex;
    }
}

void LinkedList::addNewEdge(int vertex, double d, double s, int A){
    Vertex *new_vertex = new Vertex(vertex, d, s, A);
    Vertex *current_vertex;

    if (head_vertex == nullptr){
        head_vertex = new_vertex;
    }else{
        current_vertex = head_vertex;

        while (current_vertex->get_next() != nullptr){
            current_vertex = current_vertex->get_next();
        }
        
        current_vertex->set_next(new_vertex);

        //cout << current_vertex->get_next()->get_intersection() << endl;
    }
}

bool LinkedList::checkEdge(int intersection_num, double d, double s){
    Vertex *current_vertex;
    int current_intersection;

    if (head_vertex == nullptr){
        return true;
    }else {
        current_vertex = head_vertex;

        while (current_vertex->get_next() != nullptr){
            current_intersection = current_vertex->get_intersection();
            if (current_intersection == intersection_num){
                current_vertex->set_distance(d);
                current_vertex->set_speed(d);
                return false;
            }
            current_vertex = current_vertex->get_next();
        }
    }

    return true;
}

bool LinkedList::checkEdge(int intersection_num){
    Vertex *current_vertex;
    int current_intersection;

    if (head_vertex == nullptr){
        return true;
    }else {
        current_vertex = head_vertex;

        while (current_vertex->get_next() != nullptr){
            current_intersection = current_vertex->get_intersection();
            if (current_intersection == intersection_num){
                return false;
            }
            current_vertex = current_vertex->get_next();
        }
    }

    return true; 
}

void LinkedList::printVertices(){
    Vertex *current_vertex;

    if (head_vertex == nullptr){
        cout << endl;
    }else{
        current_vertex = head_vertex->get_next();

        while (current_vertex != nullptr){
            cout << current_vertex->get_intersection() << " ";
            current_vertex = current_vertex->get_next();
        }

        cout << endl;
    }
}

VertexDictionary* LinkedList::deleteVertices(){
    Vertex *current_vertex = head_vertex;
    VertexDictionary *vertex_array = new VertexDictionary();
    int current_intersection;

    while (head_vertex != nullptr){
        current_intersection = current_vertex->get_intersection();
        //cout << current_intersection << endl;
        Vertex* new_vertex = new Vertex(current_intersection);;
        vertex_array->addVertex(new_vertex);

        head_vertex = head_vertex->get_next();
        delete current_vertex;
        current_vertex = nullptr;
        current_vertex = head_vertex;
    }

    return vertex_array;
}

void LinkedList::deleteVertex(int intersection){
    //if (head_vertex == nullptr){cout << "nullptr head" <<endl;}
    Vertex *previous_vertex = nullptr;
    Vertex *current_vertex = head_vertex;
    int current_intersection;

    while (current_vertex != nullptr){
        current_intersection = current_vertex->get_intersection();
        //this is the vertex that needs to be deleted
        if (current_intersection == intersection){
            if (previous_vertex == nullptr){
                head_vertex = current_vertex->get_next();
                delete current_vertex;
                //printVertices();
                //cout << "new linked list ^^" << endl;
                return;
            }else{
                previous_vertex->set_next(current_vertex->get_next());
                delete current_vertex;
                //printVertices();
                //cout << "new linked list ^^" << endl;
                return;
            }
        }
        previous_vertex = current_vertex; 
        current_vertex = current_vertex->get_next();
    }
}

bool LinkedList::updateAdjFactor(int intersection, int A){
    Vertex *current_vertex = head_vertex;
    int current_intersection;

    while (current_vertex != nullptr){
        current_intersection = current_vertex->get_intersection();

        if (current_intersection == intersection){
            return current_vertex->updateAdjFactor(A);
        }
    }
    return false;
}   

void LinkedList::addToQueue(PriorityQueue *priority_queue){
    Vertex *current_vertex = head_vertex->get_next();

    while (current_vertex != nullptr){
        priority_queue->insertInPQ(current_vertex);
        current_vertex = current_vertex->get_next();
    }
}

/*
void LinkedList::traverseAdj(PriorityQueue *priority_queue){
    Vertex *current_vertex = head_vertex;

    while (current_vertex != nullptr){

    }
}
*/

int LinkedList::findVertex(int intersection){
    Vertex *current_vertex = head_vertex;
    int current_intersection;

    while (current_vertex != nullptr){
        current_intersection = current_vertex->get_intersection();

        if (current_intersection == intersection){
            return current_vertex->get_traveltime();
        }

        current_vertex = current_vertex->get_next();
    }

    return current_vertex->get_traveltime();
}

Vertex* LinkedList::get_head(){return head_vertex;}