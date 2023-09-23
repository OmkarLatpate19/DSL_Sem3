/*A double-ended queue (deque) is a linear list in which additions and deletions may be made at either end.
Obtain a data representation mapping a deque into a one dimensional array.
Write C++ program to simulate deque with functions to add and #delete elements from either end of the deque.*/

#include <iostream>
using namespace std;
#define size 10

class dequeue
{
public:
    int D[size];
    int front = -1;
    int rear = -1;

    void enqueueF()
    {
        if (front > 0)
        {
            cout << "Enter value to add from front  :";
            front--;
            cin >> D[front];
        }
        else
        {
            cout << "Cannot add at front !!" << endl;
        }
    }

    void enqueueR()
    {
        if (rear == size - 1)
        {
            cout << "Queue is full !!" << endl;
        }
        else
        {
            if (rear == -1)
            {
                front = 0;
            }
            rear += 1;
            cout << "Enter element you want to add from rear :";
            cin >> D[rear];
        }
    }

    void dequeueF()
    {
        int val;
        if (front == -1)
        {
            cout << "Queue is empty !!" << endl;
        }
        else
        {
            val = D[front];
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front += 1;
                cout << "The element " << val << " has been deleted from queue " << endl;
            }
        }
    }

    void dequeueR()
    {
        int val;
        if (rear == -1)
        {
            cout << "Queue is empty !!" << endl;
        }
        else
        {
            val = D[rear];
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                rear -= 1;
                cout << "The element " << val << " has been deleted from queue" << endl;
            }
        }
    }

    void display()
    {
        if (front == -1)
        {
            cout << "Queue is Empty !!" << endl;
        }
        else
        {
            cout << "DEqueue contains :";
            for (int i = front; i <= rear; i++)
            {
                cout << D[i] << " ";
            }
        }
    }
};

int main()
{
    dequeue q;
    int ch;
    bool flag = true;

    while (flag)
    {
        cout << "\n------MENU------\n1.Add from Front\n2.Add from Rear\n3.Delete from Front\n4.Delete from Rear\n5.Exit\n---------------" << endl;
        cout << "Enter your choice :";
        cin >> ch;

        switch (ch)
        {
        case 1:
            q.enqueueF();
            q.display();
            break;

        case 2:
            q.enqueueR();
            q.display();
            break;

        case 3:
            q.dequeueF();
            q.display();
            break;

        case 4:
            q.dequeueR();
            q.display();
            break;

        case 5:
            flag = false;
            cout << "Exitting Program!!" << endl;
            break;

        default:
            cout << "Enter valid choice!!" << endl;
            break;
        }
    }
    return 0;
}