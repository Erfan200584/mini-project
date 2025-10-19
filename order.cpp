#include "order.h"

Order::Order(int i, int c){
    if (i >= 1 && i <= MENU_SIZE) {
    name = menu[i - 1].name;
    price = menu[i - 1].price;
    } else {
        name = "UNKNOWN";
        price = 0;
    }
    count = c;
    next = nullptr;
}

Order::Order(const string& n, int c, int p) : name(n), price(p), count(c), next(nullptr) {}