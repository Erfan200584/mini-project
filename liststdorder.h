#ifndef LISTSTDORDER_H
#define LISTSTDORDER_H

#include "stdorder.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


class ListStdOrder {
private:
    StdOrder* head;
    int orderCounter;

public:
    ListStdOrder();
    void addStudentOrder();
    void reviewAll();
    void changeOrder();
    void deliverOrder();
    void cancelOrder();
    void saveToFile(const string& filename = "orders.txt");
    void loadFromFile(const string& filename = "orders.txt");
};



#endif