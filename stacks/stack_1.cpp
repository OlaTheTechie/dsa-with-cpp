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
        int peep(){
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


};


int main(){

    // now let me test my stack class 

    Stack stack = Stack(5); 
    stack.push(77);
    stack.push(78); 
    stack.pop();
    stack.displayElements();

    return 0;
}