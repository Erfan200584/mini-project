#ifndef ORDER_H
#define ORDER_H
#include "menuitem.h"
#include <string>
using namespace std;
class Order {
public:
    string name;
    int price;
    int count;
    Order* next;
    Order(int i, int c);
    Order(const string& n, int c, int p);
};


#endif