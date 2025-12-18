#include <iostream>
using namespace std;

class queue {
    int arr[3];
    int front;
    int rear;

public:
    queue() {
        front = -1;
        rear = -1;
        for (int i = 0; i < 3; i++) {
            arr[i] = 0;
        }
    }

    bool isfull() {
        return rear == 2;
    }

    bool isempty() {
        return (front == -1 && rear == -1);
    }

    void enqueue(int val) {
        if (isfull()) {
            cout << "Queue is full\n";
            return;
        }
        else if (isempty()) {
            rear = 0;
            front = 0;
            arr[rear] = val;
        }
        else {
            rear++;
            arr[rear] = val;
        }
    }

    int dequeue() {
        if (isempty()) {
            cout << "Queue is empty\n";
            return 0;
        }
        int x = arr[front];
        arr[front] = 0;
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front++;
        }
        return x;
    }

    int count() {
        if (isempty())
            return 0;
        else
            return (rear - front + 1);
    }

    void display() {
        if (isempty()) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    queue q1;
    int option, val;
    do {
        cout << "What operation do you want to perform? Select option number. Enter 0 to exit\n";
        cout << "1. Enqueue()\n";
        cout << "2. Dequeue()\n";
        cout << "3. IsEmpty()\n";
        cout << "4. IsFull()\n";
        cout << "5. Count()\n";
        cout << "6. Display()\n";
        cout << "7. Clear screen\n";
        cin >> option;
        switch (option) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> val;
            q1.enqueue(val);
            break;
        case 2:
            cout << "Dequeued value: " << q1.dequeue() << endl;
            break;
        case 3:
            if (q1.isempty())
                cout << "Queue is empty\n";
            else
                cout << "Queue is not empty\n";
            break;
        case 4:
            if (q1.isfull())
                cout << "Queue is full\n";
            else
                cout << "Queue is not full\n";
            break;
        case 5:
            cout << "Count of items in queue: " << q1.count() << endl;
            break;
        case 6:
            cout << "Queue elements: ";
            q1.display();
            break;
        case 7:
            system("cls");
            break;
        }
    } while (option != 0);
    return 0;
}
