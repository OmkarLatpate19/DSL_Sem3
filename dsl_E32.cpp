/*  Pizza parlor accepting maximum M orders. Orders are served in first come first served basis.
Order once placed cannot be cancelled. Write C++ program to simulate the system using circular queue using array.*/

#include <iostream>
using namespace std;
#define size 10

class Cafe
{
public:
	int order[size];
	int f = -1, r = -1;

	bool isempty()
	{
		return (f == -1) ? true : false;
	}

	bool isfull()
	{
		return ((r + 1) % size == f) ? true : false;
	}

	void takeOrder()
	{
		if (isfull())
		{
			cout << "Cafe is full. Please wait !!" << endl;
		}
		else
		{
			int val;
			cout << "Enter ID for order :";
			cin >> val;
			if (f == -1)
			{
				f++;
				r++;
				order[r] = val;
			}
			else
			{
				r = (r + 1) % size;
				order[r] = val;
			}
		}
	}

	void serveOrder()
	{
		if (isempty())
		{
			cout << "All orders have been served !!" << endl;
		}
		else
		{
			cout << "Order ID " << order[f] << " has been served." << endl;
			if (f == r)
			{
				f = r = -1;
			}
			else
			{
				f = (f + 1) % size;
			}
		}
	}

	void display()
	{
		if (isempty())
		{
			cout << "Order list is empty !!" << endl;
		}
		else
		{
			cout << "Order ID list is : ";
			for ( int i = f; i != r; i=((i + 1) % size))
			{
				cout << order[i] << " ";
			}
			cout << order[r] << " ";
		}
	}
};

int main()
{
	Cafe c;
	int ch;
	bool flag = true;

	while (flag)
	{
		cout << "\n~~~~~Cafe OMKAR~~~~~\n"<< endl;
		cout << "------MENU------\n1.Take Order\n2.Serve Order\n3.Display Order List\n4.Exit\n----------------" << endl;
		cout << "Enter choice :";
		cin >> ch;

		switch (ch)
		{
		case 1:
			c.takeOrder();
			break;

		case 2:
			c.serveOrder();
			break;

		case 3:
			c.display();
			break;

		case 4:
			flag = false;
			cout << "Thanks for visiting !! Come again !!	" << endl;
			break;

		default:
			cout << "Enter valid choice !!" << endl;
			break;
		}
	}
}