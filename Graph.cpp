#include "Graph.hpp" 

#include <iostream>
#include <string> 

Graph::Graph(){
    adjacency_list = new LinkedList*[500000];

    for (int i = 0; i < 500000; i++){
        adjacency_list[i] = new LinkedList();
    }

    vertex_dictionary = new VertexDictionary();
}

Graph::~Graph(){
    for (int i = 0; i < 500000; i++){
        delete adjacency_list[i];
    }
    delete[] adjacency_list;
    delete vertex_dictionary;
}

void Graph::loadFile(fstream& fin){
    int a;
    int b;
    double d;
    double s;

    while (fin >> a){
        fin >> b;
        fin >> d;
        fin >> s;
        insert(a,b,d,s);
    }
}

void Graph::insert(int a, int b, double d, double s){
    //if the vertex a does not exist, add vertex in dictionary 
    if (!vertex_dictionary->checkVertex(a)){
        Vertex *vertex_a = new Vertex(a);
        vertex_dictionary->addVertex(vertex_a);
        adjacency_list[a-1]->addNewEdge(a,0,0,1);
        //cout << "adding: " << a << endl;
    }

    //if vertex b does not exist, add vertex in dictionary
    if (!vertex_dictionary->checkVertex(b)){
        Vertex *vertex_b = new Vertex(b);
        vertex_dictionary->addVertex(vertex_b);
        adjacency_list[b-1]->addNewEdge(b,0,0,1);
        //cout << "adding: " << b << endl;
    }
    
    //if edge doesn't exist, it will return true and add new edge 
    //if edge does exist, it will update the distance and speed of that edge and return false
    if (adjacency_list[a-1]->checkEdge(b, d, s)){
        adjacency_list[a-1]->addNewEdge(b, d, s, 1);
        adjacency_list[b-1]->addNewEdge(a, d, s, 1);
    }
}

void Graph::printAdjVertices(int a){
    //vertex a does not exist
    if (!vertex_dictionary->checkVertex(a)){
        cout << "failure" << endl;
    }else{
        adjacency_list[a-1]->printVertices();
    }
}

void Graph::deleteVertex(int a){
    if (!vertex_dictionary->checkVertex(a)){
        cout << "failure" << endl;
    }else{
        VertexDictionary *vertex_array = adjacency_list[a-1]->deleteVertices();
        int intersection_num;

        for (int i = 0; i < vertex_array->get_size(); i++){
            intersection_num = vertex_array->getIntersection(i);
            //cout << intersection_num-1 << endl;
            adjacency_list[intersection_num-1]->deleteVertex(a);
        }

        cout << "success" << endl;
        delete vertex_array;
    }
}

void Graph::updateAdjustmentFactor(int a, int b, int A){
    //if a or b vertex doesn't exist
    if (!vertex_dictionary->checkVertex(a) || !vertex_dictionary->checkVertex(b) || adjacency_list[a-1]->checkEdge(b)){
        cout << "failure" << endl;
    }else{
        bool updated = adjacency_list[a-1]->updateAdjFactor(b,A);
        updated = adjacency_list[b-1]->updateAdjFactor(a,A);
        cout << "success" << endl;
    }
}

//Dijkstra's Algorithm
void Graph::findPath(int a, int b){
    PriorityQueue *priority_queue = new PriorityQueue();
    int size = vertex_dictionary->get_size();
    int intersection;
    int src_vertex = a;
    int dest_vertex = b;
    double distance[500000];
    bool visited[500000];

    if (adjacency_list[a-1]->get_head() == nullptr || adjacency_list[b-1]->get_head() == nullptr){
        cout << "failure" << endl;
        return;
    }

    //initalizing all the vertices to INFINITY
    for (int i = 0; i < size; i++){
        intersection = vertex_dictionary->getIntersection(i);
        distance[intersection-1] = __DBL_MAX__;
    }

    distance[src_vertex-1] = 0;

    adjacency_list[src_vertex-1]->addToQueue(priority_queue);
    visited[src_vertex-1] = true;

    //while PQ is not empty 
    while (priority_queue->get_size() != 0){
        Vertex *min_vertex = priority_queue->extractMin();
        int min_intersection = min_vertex->get_intersection();
        int min_traveltime = min_vertex->get_traveltime();
        
        Vertex *current_vertex = (adjacency_list[min_intersection-1]->get_head())->get_next();

        while (current_vertex != nullptr){
            int current_intersection = current_vertex->get_intersection();
            /*
            if (visited[dest_vertex-1] == true){
                cout << endl;
                return;
            }
            */
            if (visited[current_intersection-1] == false){
                int current_traveltime = current_vertex->get_traveltime();
                if (distance[current_intersection-1] > min_traveltime + current_traveltime){
                    distance[current_intersection-1] = min_traveltime + current_traveltime;
                    Vertex *new_vertex = new Vertex(src_vertex, current_intersection, min_traveltime+current_traveltime);
                    priority_queue->insertInPQ(new_vertex);
                    if (current_intersection == dest_vertex){
                        cout << min_intersection << " ";
                    }
                }
            }

            current_vertex = current_vertex->get_next();
        }
        visited[min_intersection-1] = true;
    }
    cout << endl;

    //delete priority_queue;
    for (int i = 0; i < size; i++){
        intersection = vertex_dictionary->getIntersection(i);
        distance[intersection-1] = __DBL_MAX__;
        visited[intersection-1] = false;
    }
    //cout << distance[b-1] << endl;
}

void Graph::updateFile(fstream& fin){
    int a;
    int b;
    int A;
    bool updated = true;

    while (fin >> a){
        fin >> b;
        fin >> A;
        if (!adjacency_list[a-1]->updateAdjFactor(b,A) && !adjacency_list[b-1]->updateAdjFactor(a,A)){
            updated = false;
        }
    }

    if (updated == true){
        cout << "success" << endl;
    }else{
        cout << "failure" << endl;
    }
}

void Graph::findLowest(int a, int b){
    PriorityQueue *lowest_priority_queue = new PriorityQueue();
    int size = vertex_dictionary->get_size();
    int intersection;
    double lowest_distance[500000];
    bool lowest_visited[500000];

    if (adjacency_list[a-1]->get_head() == nullptr || adjacency_list[b-1]->get_head() == nullptr){
        cout << "failure" << endl;
        return;
    }

    //initalizing all the vertices to INFINITY
    for (int i = 0; i < size; i++){
        intersection = vertex_dictionary->getIntersection(i);
        lowest_distance[intersection-1] = __DBL_MAX__;
    }

    lowest_distance[a-1] = 0;

    adjacency_list[a-1]->addToQueue(lowest_priority_queue);
    lowest_visited[a-1] = true;

    //while PQ is not empty 
    while (lowest_priority_queue->get_size() != 0){
        Vertex *min_vertex = lowest_priority_queue->extractMin();
        int min_intersection = min_vertex->get_intersection();
        int min_traveltime = min_vertex->get_traveltime();
        
        Vertex *current_vertex = (adjacency_list[min_intersection-1]->get_head())->get_next();

        while (current_vertex != nullptr){
            int current_intersection = current_vertex->get_intersection();
            if (lowest_visited[current_intersection-1] == false){
                int current_traveltime = current_vertex->get_traveltime();
                if (lowest_distance[current_intersection-1] > min_traveltime + current_traveltime){
                    lowest_distance[current_intersection-1] = min_traveltime + current_traveltime;
                    Vertex *new_vertex = new Vertex(a, current_intersection, min_traveltime+current_traveltime);
                    lowest_priority_queue->insertInPQ(new_vertex);
                }
            }

            current_vertex = current_vertex->get_next();
        }
        lowest_visited[min_intersection-1] = true;
    }

    if (lowest_distance[b-1] < __DBL_MAX__){
        cout << "lowest is " << lowest_distance[b-1] << endl;
    }else{
        cout << "failure" << endl;
    }

    //delete lowest_priority_queue;
    for (int i = 0; i < size; i++){
        intersection = vertex_dictionary->getIntersection(i);
        lowest_distance[intersection-1] = __DBL_MAX__;
        lowest_visited[intersection-1] = false;
    }
}