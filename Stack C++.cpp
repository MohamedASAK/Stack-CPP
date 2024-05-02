#include <iostream>
using namespace std;
struct node
{
	int Data;
	node* next;
};

// global pointer
node* TOP = NULL;
node* current = NULL;

bool isEmpty()
{
	if (TOP == NULL)
		return true;
	else
		return false;
}
void push(int newdata)
{
	node* current = new node();
	current->Data = newdata;
	if (!isEmpty())
	{
		current->next = TOP;
		TOP = current;
	}
	else
	{
		TOP = current;
		TOP->next = NULL;
	}
}
void pop()
{
	if (!isEmpty())
	{
		current = TOP;
		TOP = TOP->next;
		delete current;
	}
	else
		cout << "No stack found" << endl;
}
void popAll()
{
	while (!isEmpty())
	{
		current = TOP;
		TOP = TOP->next;
		delete current;
	}
}
void display()
{
	if (!isEmpty())
	{
		current = TOP;
		while (current != NULL)
		{
			cout << current->Data << endl;
			current = current->next;
		}
	}
	else cout << "There is no data in the Stack\n";
}
void app()
{
	/*
		op -> operation
		c -> confirm
		p -> push node
		ao -> another operation
		s -> starter app
	*/
		int op, c, p, ao, s;
	cout << "--- Welcome to stack implementation---\n";
	do
	{
		cout << "Choise what do you want\n";
		cout << "Push -> (1)\n";
		cout << "Pop an Elements -> (2) \n";
		cout << "POP All Elements -> (3)\n";
		cout << "Display -> (4)\n";
		cout << "Exit -> (5)\n";
		cin >> op;
		switch (op)
		{
		case 1:
			cout << "Enter value do you want to push \n";
			cin >> p;
			push(p);
			break;
		case 2:
			cout << "Are you sure to pop one node\n";
			cout << "To Confirm Enter -> (1)\n";
			cout << "To Cancel Enter -> any key\n";
			cin >> c;
			if (c == 1)
			{
				pop();
				cout << "\nCheck data of stack after poping first node : \n ";
				display();
			}
			else {
				cout << "Pop is canceled\n";
			}
			break;
		case 3:
			cout << "Are you sure to pop all nodes\n";
			cout << "To Confirm Enter -> (1)\n";
			cout << "To Cancel Enter -> any key\n";
			cin >> c;
			if (c == 1)
			{
				popAll ();
				cout << "\nCheck data of stack after poping all nodes : \n ";
				display();
			}
			else {
				cout << "Pop all is canceled\n";
			}
			break;
		case 4:
			cout << "Pushed Elements are:\n";
			display();
			break;
		case 5:
			return;
			break;
		default:
			cout << "Wrong Input Try Again\n";
		}
		cout << "Do you want another opration\n";
		cout << "Yes -> 1 \n";
		cout << "NO -> any key \n";
		cin >> ao;
	} while (ao == 1);
}
int main()
{
	app();
	return 0;
}