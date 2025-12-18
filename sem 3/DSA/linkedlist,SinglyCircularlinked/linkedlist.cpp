#include <iostream>
using namespace std;

#include <memory>

struct Node {
    int data;
    unique_ptr<Node> next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    unique_ptr<Node> head;

public:
    LinkedList() : head(nullptr) {}

    void insertAtBeginning(int value) {
        auto newNode = std::make_unique<Node>(value);
        newNode->next = std::move(head);
        head = std::move(newNode);
    }

    void insertAtEnd(int value) {
        auto newNode = std::make_unique<Node>(value);
        Node* current = head.get();
        if (!current) {
            head = std::move(newNode);
            return;
        }
        while (current->next) {
            current = current->next.get();
        }
        current->next = std::move(newNode);
    }

    void insertAtMiddle(int value, int position) {
        if (position <= 1) {
            insertAtBeginning(value);
            return;
        }

        auto newNode = std::make_unique<Node>(value);
        Node* current = head.get();
        for (int i = 1; i < position - 1 && current; i++) {
            current = current->next.get();
        }
        if (!current) {
            std::cout << "Position out of range" << std::endl;
            return;
        }
        newNode->next = std::move(current->next);
        current->next = std::move(newNode);
    }

    void deleteFromBeginning() {
        if (!head) {
            return;
        }
        head = std::move(head->next);
    }

    void deleteFromEnd() {
        if (!head) {
            return;
        }
        if (!head->next) {
            head.reset();
            return;
        }
        Node* current = head.get();
        while (current->next->next) {
            current = current->next.get();
        }
        current->next.reset();
    }

    void deleteFromMiddle(int position) {
        if (position <= 1) {
            deleteFromBeginning();
            return;
        }

        Node* current = head.get();
        Node* previous = nullptr;
        for (int i = 1; i < position && current; i++) {
            previous = current;
            current = current->next.get();
        }
        if (!current) {
            std::cout << "Position out of range" << std::endl;
            return;
        }
        previous->next = std::move(current->next);
    }

    void display() {
        Node* current = head.get();
        while (current) {
            cout << current->data << " ";
            current = current->next.get();
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList list;

    int choice, value, position;

    do {
        std::cout << "1. Insert at beginning\n"
                     "2. Insert at end\n"
                     "3. Insert at middle\n"
                     "4. Delete from beginning\n"
                     "5. Delete from end\n"
                     "6. Delete from middle\n"
                     "7. Display elements\n"
                     "8. Exit\n"
                     "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
               cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position to insert: ";
                cin >> position;
                list.insertAtMiddle(value, position);
                break;
            case 4:
                list.deleteFromBeginning();
                break;
            case 5:
                list.deleteFromEnd();
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> position;
                list.deleteFromMiddle(position);
                break;
            case 7:
                cout << "Linked list elements: ";
                list.display();
                break;
            case 8:
                cout << "Exiting program...";
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 8);

    return 0;
}
