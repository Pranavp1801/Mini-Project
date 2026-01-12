#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;

    // constructor
    node(int value) {
        data = value;
        next = NULL;
    }
};

class linkedlist {
public:
    node *head;

    linkedlist() {
        head = NULL;
    }

    void insert_end(int value) {
        node *newnode = new node(value);

        if (head == NULL) {
            head = newnode;
            return;
        }

        node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    void delete_value(int value) {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        if (head->data == value) {
            node *temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted successfully" << endl;
            return;
        }

        node *curr = head;
        while (curr->next != NULL && curr->next->data != value) {
            curr = curr->next;
        }

        if (curr->next == NULL) {
            cout << "Value not found" << endl;
            return;
        }

        node *temp = curr->next;
        curr->next = temp->next;
        delete temp;
        cout << "Deleted successfully" << endl;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        node *temp = head;
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    linkedlist obj;
    int choice, value;

    while (true) {
        cout << "\n1. Insert\n2. Delete\n3. Display\n4. Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            obj.insert_end(value);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            obj.delete_value(value);
            break;
        case 3:
            obj.display();
            break;
        case 4:
            return 0;
        default:
            cout << "Enter valid choice" << endl;
        }
    }
}
