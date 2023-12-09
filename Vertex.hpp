//Intersections in a City

#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <iostream>
#include <string>

using namespace std;

class Vertex {
public: 
    //contructor
    Vertex();

    Vertex(int intersection);

    Vertex(int a, double d, double s, int A);

    Vertex(int src, int dest, double t);

    //destructor
    ~Vertex();

    int get_intersection();

    Vertex* get_next();

    double get_traveltime();

    void set_next(Vertex *new_next_vertex);

    void set_distance(double d);

    void set_speed(double s);

    bool updateAdjFactor (int A);

    void set_intersection(int intersection);

    void set_traveltime(int t);

private:
    int intersection_num;
    int source_num;
    double distance; 
    double speed_limit;
    int adjustment_factor;
    double travel_time;
    double min_distance;
    Vertex *next_intersection;
};

#endif 