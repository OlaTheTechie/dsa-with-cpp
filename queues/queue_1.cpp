#include <iostream> 

using namespace std; 

// a class to implement a simple linear queue
class Queue {
    // private memeber variables 
    private: 
        int front;
        int rear; 
        int* arr;
        int capacity;
        int item_count;

    public: 
        // the constructor 
        Queue (int capacity) : capacity(capacity), item_count(0){
            arr = new int[capacity];
            cout << "successfully constructed the queue object" << endl; 
        }

        ~Queue(){
            cout << "successfullly destroyed the queue object" << endl;
        }

        // method to check if queue is empty 
        bool isEmpty(){
            return item_count == 0; 
        }

        // method to check if the queue is full 
        bool isFull(){
            return item_count == capacity;
        }

        void enque(int element){

            if (isFull()){
                cout << "queue is already full, cannot perform and enque" << endl;
                return;
            }
            if (isEmpty()){
                front++;
                rear++; 
                arr[rear] = element;
                item_count++;
                return;
            }

            rear++; 
            arr[rear] = element;
            item_count++;
        }

        // method to perform a dequeue
        void dequeue(){
            if (isEmpty()){
                cout << "qeueue is empty, cannot perform a deque" << endl;
                return;
            }

            arr[front] = 0;
            front++;
            item_count--;
        }

        // method to display all the elements of the queue
        void displayElements(){
            if(isEmpty()){
                cout << "queue is empty, no element to display" << endl;
                return;
            }

            for (int i = front; i < rear + 1; i++){
                cout << arr[i] << "  "; 
            }

            cout << endl;
        }

};

int main(){
    Queue queueu = Queue(5);
    queueu.enque(66);
    queueu.enque(78);
    queueu.dequeue();
    queueu.displayElements();
}