#include <iostream>

struct Elem {
    Elem* next, * prev;
    int info;
};

void enqueue(Elem*& first, Elem*& last, int value) {
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->next = NULL;
    if (last != NULL) last->next = tmp;
    tmp->prev = last;
    last = tmp;
    if (first == NULL) first = tmp;
}

void printList(Elem* first) {
    if (first == NULL) {
        std::cout << std::endl;
        return;
    }
    std::cout << first->info << " ";
    printList(first->next);
}


void swapListRecursive(Elem*& first, Elem*& last, Elem* current) {
    if (current == NULL) {
        // Base case: end of the list
        Elem* tmp = first;
        first = last;
        last = tmp;
    }
    else {
        // Recursive case: swap the current node and continue with the next node
        Elem* tmp = current->next;
        current->next = current->prev;
        current->prev = tmp;
        swapListRecursive(first, last, tmp);
    }
}

void swapList(Elem*& first, Elem*& last) {
    swapListRecursive(first, last, first);
}



int main() {
    Elem* first = NULL, * last = NULL;
    enqueue(first, last, 1);
    enqueue(first, last, 2);
    enqueue(first, last, 3);
    enqueue(first, last, 4);
    enqueue(first, last, 5);
    enqueue(first, last, 6);
    std::cout << "Original list: ";
    printList(first);
    swapList(first, last);
    std::cout << "Swapped list: ";
    printList(first);
    return 0;
}

