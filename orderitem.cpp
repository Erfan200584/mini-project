#include "orderitem.h"
#include <iostream>
using namespace std;

OrderItem::OrderItem() { head = nullptr; }

void OrderItem::addOrderItem(int id, int count) {
    Order* newOrder = new Order(id, count);
    if (head == nullptr) head = newOrder;
    else {
        Order* cur = head;
        while (cur->next != nullptr) cur = cur->next;
        cur->next = newOrder;
    }
}

void OrderItem::addFromFile(const string& name, int count, int price) {
    Order* newOrder = new Order(name, count, price);
    if (head == nullptr) head = newOrder;
    else {
        Order* cur = head;
        while (cur->next != nullptr) cur = cur->next;
        cur->next = newOrder;
    }
}

void OrderItem::printOrders() {
    Order* cur = head;
    while (cur != nullptr) {
        cout << "   " << cur->name << " x" << cur->count << " (" << cur->price << ")\n";
        cur = cur->next;
    }
}

string OrderItem::serialize() const {
    
    string data;
    Order* cur = head;
    while (cur) {
        data += cur->name + "," + to_string(cur->count) + "," + to_string(cur->price) + ";";
        cur = cur->next;
    }
    return data;
}


int OrderItem::itemCount() const {
     int cnt = 0;
     Order* cur = head;
     while (cur) { ++cnt; cur = cur->next; }
     return cnt;
}