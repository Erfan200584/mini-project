#include "menuitem.h"
#include "order.h"
#include "orderitem.h"
#include "stdorder.h"
#include "liststdorder.h"


int main() {
    ListStdOrder compstd;
    compstd.loadFromFile();

    int choice;
    do {
        cout << "\n======:: Student Restaurant System ::======\n";
        
        cout << "1) Menu\n";
        cout << "2) New Order\n";
        cout << "3) Deliver Order\n";
        cout << "4) Cancel Order\n";
        cout << "5) Change Order\n";
        cout << "6) Review All Orders\n";
        cout << "0) Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: showMenu();break;
            case 2: compstd.addStudentOrder(); compstd.saveToFile(); break;            
            case 3: compstd.deliverOrder();compstd.saveToFile(); break;
            case 4: compstd.cancelOrder(); compstd.saveToFile(); break;            
            case 5: compstd.changeOrder(); compstd.saveToFile(); break;
            case 6: compstd.reviewAll();break;
            case 0: compstd.saveToFile(); cout << "Saving & exiting...\n"; break;
            default: cout << "Invalid choice!\n"; break;
        }
    } while (choice != 0);

    return 0;
}
