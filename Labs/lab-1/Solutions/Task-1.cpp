// Task 1
#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node* next;

		Node(int d) {
			data = d;
			next = NULL;
		}
};

class SLL {
	private:
		Node* head;

	public:
		LinkedList() {
			head = NULL;
		}

		void append(int d) {
			Node* newnode = new Node(d);
			if (head == NULL) {
				head = newnode;
			} else {
				Node* temp = head;
				while (temp->next != NULL) {
					temp = temp->next;
				}
				temp->next = newnode;
			}
		}

		void display() {
			cout << "printing list:" << endl;
			if (!head) {
				cout << "list is empty" << endl;
			} else {
				Node* temp = head;
				while (temp != NULL) {
					cout << temp->data << " ";
					temp = temp->next;
				}
				cout << endl;
			}
			cout << "---" << endl;
		}
};


int main () {
	SLL list;

	list.append(2);
	list.append(4);
	list.append(6);
	list.append(9);

	list.display();

	cin.get();
	return 0;
}
