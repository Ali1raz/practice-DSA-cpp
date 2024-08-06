// Task 3
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
			cout << "Printing list:" << endl;
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
	
	list.append("abc", 46);
	list.append("xyz", 36);
	list.append("uio", 20);

	list.display();
	list.display_pass_students();

	cin.get();
	return 0;
}
