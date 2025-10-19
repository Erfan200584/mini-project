#ifndef STDORDER_H
#define STDORDER_H
#include "orderitem.h"

class StdOrder {
public:
    string firstName;
    string lastName;
    string stdId;
    int status; 
    int numOrder;
    OrderItem items;
    StdOrder* next;

    StdOrder(const string& f, const string& l, const string& id, int n);
};






#endif