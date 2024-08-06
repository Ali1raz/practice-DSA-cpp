// Task 4.
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

		void append() {
			string name;
			int marks;
			char choice;

			do {
				cout << "Enter student name: ";
				cin >> name;
				cout << "Enter student marks: ";
				cin >> marks;

				Node* newnode = new Node(name, marks);
				if (head == NULL) {
					head = newnode;
				} else {
					Node* temp = head;
					while (temp->next != NULL) {
						temp = temp->next;
					}
					temp->next = newnode;
				}

				cout << "Do you want to add another student? (y/n): ";
				cin >> choice;
			} while (choice != 'n');
		}



		void display() {
			cout << "Printing list:" << endl;
			if (!head) {
				cout << "list is empty" << endl;
			} else {
				Node* temp = head;
				while (temp != NULL) {
					cout << "Name: " << temp->name << " Marks: " << temp->marks << endl;
					temp = temp->next;
				}
			}
			cout << "---" << endl;
		}

		void display_pass_students() {
			cout << "\nPrinting pass students:" << endl;
			if (!head) {
				cout << "list is empty" << endl;
			} else {
				Node* temp = head;
				while (temp != NULL) {
					if (temp->marks >= 50) {
						cout << "Name: " << temp->name << "\tMarks: " << temp->marks << endl;
					}
					temp = temp->next;
				}
			}
			cout << "---" << endl;
		}
		
		void display_fail_students() {
			cout << "\nPrinting fail students:" << endl;
			if (!head) {
				cout << "list is empty" << endl;
			} else {
				Node* temp = head;
				while (temp != NULL) {
					if (temp->marks < 50) {
						cout << "Name: " << temp->name << "\tMarks: " << temp->marks << endl;
					}
					temp = temp->next;
				}
			}
			cout << "---" << endl;
		}
};


int main () {
	SLL list;

	list.append();

	list.display();
	list.display_pass_students();
	list.display_fail_students();

	cin.get();
	return 0;
}

