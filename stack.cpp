#include <iostream>
using namespace std;

class stack
{
private:
    int top;
    int arr[5];

public:
    stack()
    {
        top = -1;
        for (size_t i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == 4;
    }

    void push(int val)
    {
        if (isFull())
        {
            cout << "stack overflow" << endl;
        }
        else
        {
            top++;
            arr[top] = val;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "stack underflow" << endl;
            return 0;
        }
        else
        {
            int popValue = arr[top];
            arr[top] = 0;
            top--;
            return popValue;
        }
    }

    int count()
    {
        return top + 1;
    }

    int peek(int pos)
    {
        if (isEmpty())
        {
            cout << "stack empty" << endl;
            return 0;
        }
        else
        {
            return arr[pos];
        }
    }

    void change(int pos, int val)
    {
        arr[pos] = val;
    }

    void display()
    {
        for (int i = 4; i >= 0; i--)
        {
            cout << arr[i] << '\n';
        }
    }
};

int main()
{
    stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);

    cout << "Stack after pushing 5 elements:" << endl;
    s1.display();

    s1.pop();
    cout << "\nStack after popping 1 element:" << endl;
    s1.display();

    cout << "\nElement at position 2: " << s1.peek(2) << endl;

    s1.change(2, 100);
    cout << "\nStack after changing value at position 2 to 100:" << endl;
    s1.display();

    cout << "\nNumber of elements in the stack: " << s1.count() << endl;

    return 0;
}
