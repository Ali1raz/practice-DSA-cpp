#include <iostream>
using namespace std;

class Node {
	public:
		int id;
		int numItems;
		Node* next;

		Node(int i, int n) {
			id = i;
			numItems = n;
			next = NULL;
		}
};

class Queue {
		Node* front;
		Node* rear;

	public:
		Queue () {
			front = NULL;
			rear = NULL;
		}

		void addCustomer(int id, int numItems) {
			Node* newNode = new Node(id, numItems);
			if (rear == NULL) {
				front = newNode;
				rear = newNode;
			} else {
				rear->next = newNode;
				rear = newNode;
			}
			cout << "Customer " << id << " added to queue with " << numItems << " items." <<  endl;
		}

		void serveCustomer() {
			if (front == NULL) {
				cout << "No customers in queue." <<  endl;
			} else {
				int currentId = front->id;
				int currentNumItems = front->numItems;
				Node* temp = front;
				front = front->next;
				if (front == NULL) {
					rear = NULL;
				}
				delete temp;
				cout << "Serving customer " << currentId << " with " << currentNumItems << " items." <<  endl;
			}
			cout << "---" << endl;
		}

		void displayCurrentCustomer() {
			cout << "\nDisplaying customers queue: " << endl;
			if (front == NULL) {
				cout << "No customers in queue." <<  endl;
			} else {
				cout << "Current customer: " << front->id << " with " << front->numItems << " items." <<  endl;
			}
			cout << "---" << endl;
		}
};

int main() {
	Queue s;
	s.addCustomer(1, 5);
	s.addCustomer(2, 3);
	s.addCustomer(3, 2);
	
	s.displayCurrentCustomer();
	s.serveCustomer();
	s.serveCustomer();
	s.displayCurrentCustomer();
	
	system("pause");
	return 0;
}

