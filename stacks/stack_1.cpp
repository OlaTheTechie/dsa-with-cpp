#include <iostream>

using namespace std; 

class Stack {
    private: 
        int capacity; 
        int top; 
        int* arr; 
    
    public: 
        Stack(int size) : capacity(size) {
            arr = new int[capacity]; 
            top = -1;
        }

        ~Stack(){
            cout << "Stack destroyed successfully!" << endl;
            delete[] arr;
        }

        void push(int element) {
            if (top >= capacity - 1){
                cout << "Stack overflow!" << endl;
                return;
            }

            top++; 
            arr[top] = element; 
        }

        void pop(){
            if (top < 0){
                cout << "Stack underflow!" << endl;
                return;
            }

            arr[top] = 0; 
            top--;
        }

        // method to look at an element in a specific location
        int peep(int position){
            if (position > top){
                cout << "Stack underflow!" << endl;
                return -1;
            }

            return arr[position];
        }

        // method to look at the element on top of the stack
        int peek(){
            if (top < 0){
                cout << "Stack is empty" << endl; 
                return -1; 
            }

            return arr[top];
        }

        // method to display the elements of my stack
        void displayElements(){
            if (top < 0){
                cout << "Stackk is empty" << endl; 
                return;
            }

            for (int i = 0; i <= top; i++){
                cout << "Stack element [" << i << "]: " << arr[i] << endl;
            }
            cout << "displayed stack elements successfully" << endl; 
        }

        // function to change an element in the ith position
        void change(int index, int element){
            if (top == -1){
                cout << "stack is empty. No element to change" << endl;
                return;
            }

            if (index > top){
                cout << "stack index out of range" << endl;
            }

            arr[index] = element;
        }

        // method to get the number of elements in the stack
        int count(){
            return top + 1;
        }

        // method to check if the stack is full
        bool isFull(){
            return capacity == top + 1;
        }

        // method to check if the stack is empty
        bool isEmpty(){
            return top == -1;
        }

    

};


int main(){

    // now let me test my stack class 

    Stack stack = Stack(5); 
    // stack.push(77);
    // stack.push(78); 
    stack.change(3, 99);
    stack.displayElements();
    cout << "number of elements on the stack: " << stack.count() << endl;

    cout << boolalpha;
    cout << "is the stack empty?: " << stack.isEmpty() << endl;
    cout << "is the stack full?: " << stack.isFull() << endl;


    return 0;
}