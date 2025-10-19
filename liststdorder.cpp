#include "liststdorder.h"
#include "menuitem.h"

ListStdOrder::ListStdOrder() : head(nullptr), orderCounter(0) {}

void ListStdOrder::addStudentOrder(){
    string f, l, id;
    showMenu();
    cout << "Enter first name: "; cin >> f;
    cout << "Enter last name: ";  cin >> l;
    cout << "Enter student ID: "; cin >> id;
    orderCounter++;
    StdOrder* newStd = new StdOrder(f, l, id, orderCounter);
    char cont = 'y';
    while (cont == 'y' || cont == 'Y') {
        int itemId, count;
        cout << "Enter menu item id: "; cin >> itemId;
        cout << "Enter quantity: ";     cin >> count;
        if (itemId >= 1 && itemId <= MENU_SIZE && count > 0)
            newStd->items.addOrderItem(itemId, count);
        else
            cout << "Invalid input. Try again.\n";
        cout << "Add another item? (y/n): ";
        cin >> cont;
    }
    if (!head) head = newStd;
    else {
        StdOrder* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = newStd;
    }
    cout << "Order #" << newStd->numOrder << " created successfully!\n";
}

void ListStdOrder::reviewAll() {
    if (!head) { cout << "No orders found.\n"; return; }
    StdOrder* cur = head;
    cout << "\n===== All Orders =====\n";
    while (cur) {
        cout << "Order #" << cur->numOrder << " | "
             << cur->firstName << " " << cur->lastName
             << " (" << cur->stdId << ")\n";
        cout << "Status: " << (cur->status==0? "In Progress" : (cur->status==1? "Delivered":"Canceled")) << "\n";
        cur->items.printOrders();
        cout << "----------------------\n";
        cur = cur->next;
    }
}

void ListStdOrder::changeOrder() {
    int num;
    cout << "Enter order number to change: ";
    cin >> num;

    StdOrder* cur = head;
    while (cur && cur->numOrder != num)
        cur = cur->next;

    if (!cur) {
        cout << "Order not found.\n";
        return;
    }
    if (cur->status != 0) {
        cout << "Only active orders can be changed.\n";
        return;
    }

    cout << "\nChanging order #" << num << "\n";
    cout << "1) Add item\n2) Remove specific item\nChoice: ";
    int ch;
    cin >> ch;

    if (ch == 1) {
        int itemId, count;
        cout << "Enter menu item id: ";
        cin >> itemId;
        cout << "Enter quantity: ";
        cin >> count;

        if (itemId >= 1 && itemId <= MENU_SIZE && count > 0) {
            cur->items.addOrderItem(itemId, count);
            cout << " Item added.\n";
        } else {
            cout << " Invalid input.\n";
        }
    }

    else if (ch == 2) {
        
        cout << "\nCurrent items in order #" << num << ":\n";
        Order* o = cur->items.head;
        int index = 1;
        while (o) {
            cout << index << ") " << o->name << " x" << o->count
                 << " (" << o->price << ")\n";
            o = o->next;
            index++;
        }

        cout << "Enter item number to delete: ";
        int delIndex;
        cin >> delIndex;

        if (delIndex < 1 || delIndex >= index) {
            cout << " Invalid item number.\n";
            return;
        }

        Order* prev = nullptr;
        Order* curItem = cur->items.head;
        int pos = 1;

        while (curItem && pos < delIndex) {
            prev = curItem;
            curItem = curItem->next;
            pos++;
        }

        if (!curItem) {
            cout << " Item not found.\n";
            return;
        }

        if (!prev) {
            cur->items.head = curItem->next;
        } else {
            prev->next = curItem->next;
        }

        delete curItem;
        cout << " Item deleted successfully.\n";
    }

    else {
        cout << "No changes made.\n";
    }
}

void ListStdOrder::deliverOrder() {
    int num; cout << "Enter order number to mark as delivered: "; cin >> num;
    StdOrder* cur = head;
    while (cur && cur->numOrder != num) cur = cur->next;
    if (!cur) { cout << "Order not found.\n"; return; }
    if (cur->status != 0) { cout << "Order already closed.\n"; return; }
    cur->status = 1;
    cout << "Order #" << num << " marked as delivered.\n";
}

void ListStdOrder::cancelOrder() {
    int num; cout << "Enter order number to cancel: "; cin >> num;
    StdOrder* cur = head;
    while (cur && cur->numOrder != num) cur = cur->next;
    if (!cur) { cout << "Order not found.\n"; return; }
    if (cur->status == 1) { cout << "Already delivered. Can't cancel.\n"; return; }
    cur->status = 2;
    cout << "Order #" << num << " canceled.\n";
}

void ListStdOrder::saveToFile(const string& filename = "orders.txt") {
    ofstream file(filename);
    if (!file) { cerr << "Cannot open file for writing.\n"; return; }
    StdOrder* cur = head;
    while (cur) {
        
        file << cur->numOrder << "|" << cur->firstName << "|" << cur->lastName
             << "|" << cur->stdId << "|" << cur->status << "|"
             << cur->items.serialize() << "\n";
        cur = cur->next;
    }
    file.close();
}

void ListStdOrder::loadFromFile(const string& filename = "orders.txt") {
    ifstream file(filename);
    if (!file) { return; }
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string token;
        if (!getline(ss, token, '|')) continue;
        int num = stoi(token);
        string f, l, id;
        if (!getline(ss, f, '|')) continue;
        if (!getline(ss, l, '|')) continue;
        if (!getline(ss, id, '|')) continue;
        if (!getline(ss, token, '|')) continue; 
        int status = stoi(token);
        string itemsData;
        if (!getline(ss, itemsData)) itemsData = ""; 
        
        StdOrder* newStd = new StdOrder(f, l, id, num);
        newStd->status = status;
        
        stringstream itss(itemsData);
        string part;
        while (getline(itss, part, ';')) {
            if (part.empty()) continue;

            stringstream pss(part);
            string namePart, countPart, pricePart;
            if (!getline(pss, namePart, ',')) continue;
            if (!getline(pss, countPart, ',')) continue;
            if (!getline(pss, pricePart, ',')) continue;
            int cnt = stoi(countPart);
            int prc = stoi(pricePart);
            
            bool added = false;
            for (int i = 0; i < MENU_SIZE; ++i) {
                if (menu[i].name == namePart) {
                    newStd->items.addOrderItem(menu[i].id, cnt);
                    added = true;
                    break;
                }
            }
            if (!added) {
                
                newStd->items.addFromFile(namePart, cnt, prc);
            }
        }
        
        if (!head) head = newStd;
        else {
            StdOrder* cur2 = head;
            while (cur2->next) cur2 = cur2->next;
            cur2->next = newStd;
        }
        
        if (num > orderCounter) orderCounter = num;
    }
    file.close();
}