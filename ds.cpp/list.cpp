#include <iostream>
using namespace std;

typedef int list_entry;
#define MAX_LIST 100

class List {
private:
    int count;
    list_entry entry[MAX_LIST];

public:
    List() {
        count = 0;
    }

    bool full() {
        return (count == MAX_LIST);
    }

    bool empty() {
        return (count == 0);
    }

    int size() {
        return count;
    }

    void clear() {
        count = 0;
    }

    void insert(int pos, list_entry item) {
        if (full() || pos < 0 || pos > count) {
            return;
        }
        for (int i = count - 1; i >= pos; i--) {
            entry[i + 1] = entry[i];
        }
        entry[pos] = item;
        count++;
    }

    void remove(int pos, list_entry *pitem) {
        if (empty() || pos < 0 || pos >= count) {
            return;
        }
        *pitem = entry[pos];
        for (int i = pos; i < count - 1; i++) {
            entry[i] = entry[i + 1];
        }
        count--;
    }

    void retrieve(int pos, list_entry *pitem) {
        if (empty() || pos < 0 || pos >= count) {
            return;
        }
        *pitem = entry[pos];
    }

    void replace(int pos, list_entry item) {
        if (empty() || pos < 0 || pos >= count) {
            return;
        }
        entry[pos] = item;
    }

    void traverse(void (*visit)(list_entry)) {
        for (int i = 0; i < count; i++) {
            (*visit)(entry[i]);
        }
    }
};

int main() {
    List myList;
    
    myList.insert(0, 10);
    myList.insert(1, 20);
    myList.insert(1, 15);

    list_entry val;
    myList.retrieve(1, &val);
    cout << "Element at pos 1: " << val << "\n";

    myList.remove(1, &val);
    cout << "Removed: " << val << "\n";

    cout << "List size: " << myList.size() << "\n";

    return 0;
}
