// Task 2
#include <iostream>
using namespace std;

class Node {
	public:
		string name;
		int marks;
		Node* next;

		Node(string n, int m) {
			name = n;
			marks = m;
			next = NULL;
		}
};

class SLL {
	private:
		Node* head;

	public:
		SLL() {
			head = NULL;
		}

		void append(string n, int m) {
			Node* newnode = new Node(n, m);
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
					cout << "Name: " << temp->name << "\tmarks: " << temp->marks << endl;
					temp = temp->next;
				}
			}
			cout << "---" << endl;
		}
};


int main () {
	SLL list;

	list.append("Ali", 92);
	list.append("Raza", 88);
	list.append("Abdullah", 98);
	list.append("Naveed", 9);
	list.append("Ahmar", 90);
	list.append("Hassan", 90);
	list.append("Waseem", 94);
	list.append("Asif", 94);

	list.display();

	cin.get();
	return 0;
}
