#ifndef MENUITEM_H
#define MENUITEM_H
#include <string>
using namespace std;


class MenuItem {
public:
    int id;
    string name;
    int price;
};

const int MENU_SIZE;
MenuItem menu[];

#endif