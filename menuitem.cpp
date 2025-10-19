#include "menuitem.h"
#include <iostream>

const int MENU_SIZE = 9;
MenuItem menu[MENU_SIZE] = {
    {1, "Kabab Kobideh", 22000},
    {2, "Pizza", 22000},
    {3, "Pasta", 17000},
    {4, "Coca-Cola", 20000},
    {5, "Dough", 17000},
    {6, "Delster", 30000},
    {7, "Salad", 10000},
    {8, "Yogurt", 12000},
    {9, "Soup", 15000}
};


void showMenu() {
    cout << "\n====== MENU ======\n";
    for (int i = 0; i < MENU_SIZE; i++) {
        cout << menu[i].id << ") " << menu[i].name << " - " << menu[i].price << endl;
    }
    cout << "===================\n";
}