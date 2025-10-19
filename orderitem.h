#ifndef ORDERITEM_H
#define ORDERITEM_H

#include "order.h"
#include <string>


class OrderItem {
public:
    Order* head;

    OrderItem();
    void addOrderItem(int id, int count);
    void addFromFile(const string& name, int count, int price);
    void printOrders();
    string serialize() const;
    int itemCount() const;
};


#endif