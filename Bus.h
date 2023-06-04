#ifndef BUS_H
#define BUS_H
#include<iostream>
using namespace std;
class a
{
    //decalration of all variables 
    int busn[10] = {};
    int seat[100][100] = {0};
    string driver[10], arrival[10], depart[10], from[10], to[10];
    
    int rear ;
    int front;
    int bil ;



public:
    a();//constrcutor    
    void insert();//insert
    void validation(int ,int);//validation of used seat number in a bus
    void deleted();//deletion function
    void update();//update details function
    void menu(); // menu display
    void selectionSort(); //sorting function
   
    //queue function
    void Enqueue(int value);
    void Dequeue();
    bool Empty();
    int queueFront();
    int queueRear();
    void FirstHistory();
    //end of queue used functions


    void show();//search function
    void seatbook();//seat reservation
    void avail();//available //view 
}; 
#endif


