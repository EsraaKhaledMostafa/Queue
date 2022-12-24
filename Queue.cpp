#include <iostream>
using namespace std;

// Queue using Array

class QueueArr
{
	int* array;
	int front, rear, maxQueue;
public:
	QueueArr(int size)
	{
		maxQueue = size;
		array = new int[size];
		front = rear = -1;
	}

	void EnQueue(int data)
	{
		if (rear != maxQueue - 1)
		{
			if (front == -1 && rear == -1)
			{
				front++;
				array[++rear] = data;
			}
			else
			{
				array[++rear] = data;
			}
		}
		else
		{
			cout << "Queue is Full" << endl;
		}
	}

	void DeQueue()
	{
		if (front != -1 && rear != -1 && front <= rear)
		{
			front++;
		}
		else
		{
			cout << "Queue is Empty" << endl;
		}
	}

	int Peak()
	{
		if (front != -1 && rear != -1 && front <= rear)
		{
			return array[front];
		}
		else
		{
			cout << "Queue is Empty" << endl;
		}
	}

	void Display()
	{
		if (front != -1 && rear != -1 && front <= rear)
		{
			for (int i = front; i <= rear; i++)
			{
				cout << array[i] << endl;
			}
		}
		else
		{
			cout << "Queue is Empty" << endl;
		}
	}
};

// Queue using Linked List
class Node
{
public:
	int data;
	Node* next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

class QueueLL
{
	Node * front, * rear;
public:
	QueueLL()
	{
		front = rear = NULL;
	}

	void EnQueue(int data)
	{
		Node * node = new Node(data);
		if (front == NULL)
		{
			front = rear = node;
		}
		else
		{
			rear->next = node;
			rear = node;
		}
	}

	void DeQueue()
	{
		if (rear == NULL)
		{
			cout << "Queue is Empty" << endl;
		}
		else if(front == rear)
		{
			Node* temp = front;
			front = rear = NULL;
			delete[]temp;
		}
		else
		{
			Node* temp = front;
			front = front->next;
			delete[]temp;
		}
	}

	int Peak()
	{
		if (front == NULL)
		{
			cout << "Queue is Empty" << endl;
		}
		else
		{
			return front->data;
		}
	}

	void Display()
	{
		if (front == NULL)
		{
			cout << "Queue is Empty" << endl;
		}
		else
		{
			Node* CurrentNode = front;
			while (CurrentNode)
			{
				cout << CurrentNode->data << endl;
				CurrentNode = CurrentNode->next;
			}
		}
	}
};




int main()
{
	cout << "Trying Queeu with Array: " << endl;
	QueueArr* myQueue = new QueueArr(5);

	myQueue->EnQueue(1);
	myQueue->EnQueue(2);
	myQueue->EnQueue(3);
	myQueue->EnQueue(4);
	myQueue->EnQueue(5);

	cout << "The Peak value is: " << myQueue->Peak() << endl;
	myQueue->Display();
	cout << endl;

	myQueue->DeQueue();
	myQueue->DeQueue();
	myQueue->DeQueue();

	cout << "The Peak value is: " << myQueue->Peak() << endl;
	myQueue->Display();
	cout << endl;





	cout << "Trying Queeu with Linked List: " << endl;
	QueueLL* Queue = new QueueLL();

	Queue->EnQueue(1);
	Queue->EnQueue(2);
	Queue->EnQueue(3);
	Queue->EnQueue(4);
	Queue->EnQueue(5);

	cout << "The Peak value is: " << Queue->Peak() << endl;
	Queue->Display();
	cout << endl;

	Queue->DeQueue();
	Queue->DeQueue();
	Queue->DeQueue();

	cout << "The Peak value is: " << Queue->Peak() << endl;
	Queue->Display();
	cout << endl;
}
