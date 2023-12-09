//Intersections in a City

#include "Vertex.hpp" 

#include <iostream>
#include <string>

using namespace std;

Vertex::Vertex(){
    intersection_num = 0;
    source_num = 0;
    distance = 0; 
    speed_limit = 0;
    adjustment_factor = 0;
    travel_time = 0;
    min_distance = 0;
    next_intersection = nullptr;
}

Vertex::Vertex(int intersection){
    intersection_num = intersection;
    source_num = 0;
    distance = 0; 
    speed_limit = 0;
    adjustment_factor = 0;
    travel_time = 0;
    min_distance = 0;
    next_intersection = nullptr;
}

Vertex::Vertex(int a, double d, double s, int A){
    intersection_num = a;
    distance = d;
    speed_limit = s;
    adjustment_factor = A;
    travel_time = d/(s*A);
    next_intersection = nullptr;
}

Vertex::Vertex(int src, int dest, double t){
    source_num = src;
    intersection_num = dest;
    travel_time = t;
}

Vertex::~Vertex(){
    next_intersection = nullptr;
}

bool Vertex::updateAdjFactor(int A){
    if (adjustment_factor == A){
        return false;
    }else{
        adjustment_factor = A;

        if (adjustment_factor == 0){
            travel_time = __DBL_MAX__;
        }else{
            travel_time = distance/(speed_limit*adjustment_factor);
        }
        return true;
    }
}

int Vertex::get_intersection(){return intersection_num;}

Vertex* Vertex::get_next(){return next_intersection;}

double Vertex::get_traveltime(){return travel_time;}

void Vertex::set_next(Vertex *new_next_vertex){next_intersection = new_next_vertex;}

void Vertex::set_distance(double d){distance = d;}

void Vertex::set_speed(double s){speed_limit = s;}

void Vertex::set_intersection(int intersection){intersection_num = intersection;}

void Vertex::set_traveltime(int t){travel_time = t;}