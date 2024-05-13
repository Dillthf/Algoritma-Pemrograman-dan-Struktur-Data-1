#include <iostream>

using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
};

struct Node {
    Mahasiswa data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
    int size;
public:
    Queue() {
        front = NULL;
        rear = NULL;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(string nama, string nim) {
        Node* newNode = new Node;
        newNode->data.nama = nama;
        newNode->data.nim = nim;
        newNode->next = NULL;
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    void dequeue() {
        if (!isEmpty()) {
            Node* temp = front;
            front = front->next;
            delete temp;
            size--;
        }
    }

    int countQueue() {
        return size;
    }

    void clearQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void viewQueue() {
        Node* current = front;
        cout << "Data antrian mahasiswa:" << endl;
        int count = 1;
        while (current != NULL) {
            cout << count << ". Nama: " << current->data.nama << ", NIM: " << current->data.nim << endl;
            current = current->next;
            count++;
        }
        for (int i = count; i <= 5; i++) {
            cout << i << ". (kosong)" << endl;
        }
    }
};

int main() {
    Queue queue;
    queue.enqueue("Dill", "2311110048");
    queue.enqueue("Joonie", "9419120912");
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;
    queue.dequeue();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;
    queue.clearQueue();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;
    return 0;
}
