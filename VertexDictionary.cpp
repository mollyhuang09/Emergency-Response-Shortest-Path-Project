#include "VertexDictionary.hpp"

#include <iostream>
#include <string>

using namespace std;

VertexDictionary::VertexDictionary(){
    capacity = 10;
    size = 0;
    vertex_array = new Vertex*[capacity];
}

VertexDictionary::~VertexDictionary(){
    for (int i = 0; i < size; i++){
        delete vertex_array[i];
    }
    delete[] vertex_array;
}

bool VertexDictionary::checkVertex(int intersection){
    //cout << "size: " << size << endl;
    for (int i = 0; i < size; i++){
        if (vertex_array[i]->get_intersection() == intersection){
            return true;
        }
    }
    return false;
}

void VertexDictionary::addVertex(Vertex *vertex){
    vertex_array[size] = vertex;

    size ++;

    if (size >= capacity){
        capacity += 10;
        Vertex **temp = new Vertex*[capacity];

        for (int i = 0; i < size; i++){
            temp[i] = vertex_array[i];
        }

        delete [] vertex_array;
        vertex_array = temp;
    }

    /*
    cout << "printing dictionary" << endl;

    for (int i = 0; i < size; i++){
        cout << vertex_array[i]->get_intersection() << " ";
    }
    cout << endl;
    */
}

void VertexDictionary::swapVertices(int index, int parent_index){
    Vertex *temp; 

    temp = vertex_array[index];
    vertex_array[index] = vertex_array[parent_index];
    vertex_array[parent_index] = temp;
}

int VertexDictionary::get_size(){return size;}

int VertexDictionary::getIntersection(int i){return vertex_array[i]->get_intersection();}

double VertexDictionary::get_traveltime(int i){return vertex_array[i]->get_traveltime();}

Vertex* VertexDictionary::get_vertex(int i){return vertex_array[i];}

void VertexDictionary::set_vertex(int i, Vertex *vertex){vertex_array[i] = vertex;}

void VertexDictionary::set_traveltime(int i, double t){vertex_array[i-1]->set_traveltime(t);}

