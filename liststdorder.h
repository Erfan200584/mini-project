#ifndef LISTSTDORDER_H
#define LISTSTDORDER_H

#include "stdorder.h"


class listStdOrder {
private:
    StdOrder* head;
    int orderCounter;

public:
    listStdOrder();
    void addStudentOrder();
    void reviewAll();
    void changeOrder();
    void deliverOrder();
    void cancelOrder();
    void saveToFile(const string& filename = "orders.txt");
    void loadFromFile(const string& filename = "orders.txt");
};



#endif