#include <iostream>

using namespace std;

struct List {
    int data;
    List* next;
};

void insert_front(List** l, int data) {
    List* list = new List();
    list->data = data;
    list->next = *l;
    *l = list;
}

void insert_back(List* l, int data) {
    if (l->next == nullptr) {
        List* list = new List();
        list->data = data;
        list->next = nullptr;
        l->next = list;
    } else {
        insert_back(l->next, data);
    }
}

void insert(List** head, int data, int k) {
    if (k == 0) {
        insert_front(head, data);
        return;
    }
    
    List* l = *head;
    for (int i = 1; i < k; i++) {
        if (l->next == nullptr) {
            break;
        } else {
            l = l->next;
        }
    }
    
    List* list = new List();
    list->data = data;
    list->next = l->next;
    l->next = list;
}

List* search(List* list, int data) {
    if (list == nullptr) {
        return nullptr;
    }
    if (list->data == data) {
        return list;
    }
    else {
        return search(list->next, data);
    }
}

List* predecessor(List* list, int data) {
    if (list == nullptr || list->next == nullptr) {
        return nullptr;
    } else {
        if (list->next->data == data) {
            return list;
        } else {
            return predecessor(list->next, data);
        }
    }
}

void delete_list(List** head, int data) {
    List* list = search(*head, data);
    if (list != nullptr) {
        List* predec = predecessor(*head, data);
        if (predec == nullptr) {
            *head = list->next;
        } else {
            predec->next = list->next;
        }
        delete list;
    }
}

void reverse(List** head) {
    List* first = *head;
    if (first == nullptr) {
        return;
    }
    
    List* rest = first->next;
    if (rest == nullptr) {
        return;
    }
    
    reverse(&rest);
    first->next->next = first;
    first->next = nullptr;
    *head = rest;
}

void print(List* l) {
    while (l != nullptr) {
        cout << l->data << " ";
        l = l->next;
    }
    cout << endl;
}

List* initialize() {
    return nullptr;
}

int main() {
    List* head = initialize();
    insert_front(&head, 1);
    insert_front(&head, 2);
    insert_back(head, 3);
    insert(&head, 4, 0);
    print(head);
    print(search(head, 2));
    delete_list(&head, 2);
    print(head);
    reverse(&head);
    print(head);
    return 0;
}