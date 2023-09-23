/*Queues are frequently used in computer programming, and a typical example is the creation of a job queue by an operating system.
If the operating system does not use priorities, then the jobs are processed in the order they enter the system.
Write C++ program for simulating job queue. Write functions to add job and delete job from queue.*/

#include <iostream>
#define size 10
using namespace std;

class Queue
{
public:
    //const static int size = 10;
    int start = -1;
    int end = -1;
    int array[size];

    void push(int x)
    {
        if (end == size - 1)
        {
            cout << "Queue overflow !!!" << endl;
        }
        array[++end] = x;
    }

    int pop()
    {
        if (start == end)
        {
            cout << "Queue Underflow !!!" << endl;
            return -1;
        }
        return array[++start];
    }

    void display()
    {
        if (start == end)
        {
            cout << "Queue is empty !!!" << endl;
        }
        else
        {
            cout << "Queue contains :" << endl;
            for (int i = start + 1; i <= end; i++)
            {
                cout << array[i] << " " << endl;
            }
        }
    }

    void Enqueue(Queue &q, int job)
    {
        q.push(job);
    }

    void Dequeue(Queue &q)
    {
        q.pop();
        cout << array[start] << " has been deleted." << endl;
    }
};

int main()
{
    Queue job_line;
    bool flag = true;
    while (flag)
    {
        int ch;
        cout << "------MENU------\n1.Add Element\n2.Delete Element\n3.Display Queue\n4.Exit\n---------------" << endl;
        cout << "Enter your choice :";
        cin >> ch;

        switch (ch)
        {

        case 1:
            int n;
            cout << "Enter element you want to add :";
            cin >> n;
            job_line.Enqueue(job_line, n);
            break;

        case 2:
            job_line.Dequeue(job_line);
            break;

        case 3:
            job_line.display();
            break;

        case 4:
            flag = false;
            cout << "Exitting Program !!!" << endl;
            break;

        default:
            cout << "Enter valid choice !!" << endl;
            break;
        }
    }
    return 0;
}