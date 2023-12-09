#include "Graph.hpp"

#include <iostream>
#include <string> 
#include <fstream>
#include <exception>

using namespace std; 

class IllegalException : public exception{
    virtual const char* what() const throw(){
        return "illegal argument";
    }
}illegal_exception;

int main(){
    Graph *new_Graph;
    string command; 

    new_Graph = new Graph();

    while (cin >> command){
        if (command == "LOAD"){
            string filename;
            cin >> filename; 
            fstream fin(filename.c_str());
            new_Graph->loadFile(fin);
            cout << "success" << endl;
        }

        else if (command == "INSERT"){
            
            int a; 
            int b; 
            double d;
            double s;

            cin >> a; 
            cin >> b;
            cin >> d;
            cin >> s;
            
            try{
                if (a <= 500000 && a > 0 && b <= 500000 && b > 0 && s > 0 && d > 0){
                    new_Graph->insert(a,b,d,s);
                    cout << "success" << endl;
                }else{
                    throw illegal_exception;
                }
            }

            catch(exception& ex){
                cout << ex.what() << endl;
            }
        }

        else if (command == "PRINT"){
            int a; 
            cin >> a;

            try{
                if (a <= 500000 && a > 0){
                    new_Graph->printAdjVertices(a);
                }else{
                    throw illegal_exception;
                }
            }

            catch(exception& ex){
                cout << ex.what() << endl;
            }
        }

        else if (command == "DELETE"){
            int a; 
            cin >> a;

            try{
                if (a <= 500000 && a > 0){
                    new_Graph->deleteVertex(a);
                }else{
                    throw illegal_exception;
                }
            }

            catch(exception& ex){
                cout << ex.what() << endl;
            }
        }

        else if (command == "PATH"){
            int a; 
            int b;
            cin >> a;
            cin >> b;

            try{
                if (a <= 500000 && a > 0 && b <= 500000 && b > 0){
                    new_Graph->findPath(a,b);
                }else{
                    throw illegal_exception;
                }
            }

            catch(exception& ex){
                cout << ex.what() << endl;
            }
        }

        else if (command == "TRAFFIC"){
            int a; 
            int b;
            int A;
            cin >> a;
            cin >> b;
            cin >> A;

            try{
                if (a <= 500000 && a > 0 && b <= 500000 && b > 0){
                    new_Graph->updateAdjustmentFactor(a, b, A);
                }else{
                    throw illegal_exception;
                }
            }

            catch(exception& ex){
                cout << ex.what() << endl;
            }
        }

        else if (command == "UPDATE"){
            string filename;
            cin >> filename; 
            fstream fin(filename.c_str());
            new_Graph->updateFile(fin);
        }

        else if (command == "LOWEST"){
            int a;
            int b;
            cin >> a;
            cin >> b;

            try{
                if (a <= 500000 && a > 0 && b <= 500000 && b > 0){
                    new_Graph->findLowest(a,b);
                }else{
                    throw illegal_exception;
                }
            }

            catch(exception& ex){
                cout << ex.what() << endl;
            }
        }

        else if (command == "END"){
            delete new_Graph;
        }
    }
    return 0;
}