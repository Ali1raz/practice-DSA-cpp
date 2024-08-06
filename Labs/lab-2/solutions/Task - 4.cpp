//CREATING TASK MANAGER
#include <iostream>
using namespace std;

class Node {
	public:
		int id;
		string name;
		bool status;
		Node* next;
		Node* prev;
		
		Node(int i, string n, bool c) {
			id = i;
			name = n;
			status = c;
			next = NULL;
			prev = NULL;
		}
		
		string getStatus() {
			return status ? "completed" : "_________";
		}
		
		void display () {
			cout << id << " :: " << name << " >> " << getStatus() << endl;
		}
};

class DLL {
	Node* head;
	Node* tail;
	public:
		DLL() {
			head = NULL;
			tail = NULL;
		}
		
		void add(int i, string n, bool c = false) {
			Node* newnode = new Node(i, n, c);
			newnode->next = NULL;
			newnode->prev = tail;
			
			if (head == NULL) {
				head = newnode;
			} else {
				tail->next = newnode;
			}
			tail = newnode;
		}
		
		void print() {
			cout << "\nPrinting..." << endl;
			if (!head) {
				cout << "List is empty" << endl;
			} else {
				Node* temp = head;
				while (temp != NULL) {
					temp->display();
					temp = temp->next;
				}
			}
			cout << "---" << endl;
		}
		
		void update() {
			int id = -1;
			while (id != 0) {
				cout << "0. to exit or enter id to\nchange status of: ";
				cin >> id;
				Node* temp = head;
				bool found = false;
				while (temp) {
					if (temp->id == id) {
						temp->status = !temp->status;
						found = true;
					}
					temp->display();
					temp = temp->next;
				}
				if (!found) cout << id << " not found..." << endl;
			}
			cout << "---" << endl;
		}
		
		void print_comp() {
			cout << "\nPrinting completed list..." << endl;
			if (head == NULL) {
				cout << "empty list" << endl;
			} else {
				Node* temp = head;
				while (temp != NULL) {
					if (temp->status) {
						temp->display();
					}
					temp = temp->next;
				}
			}
			cout << "---" << endl;
		}
		
		void print_not_completed() {
			cout << "\nPrinting not completed list..." << endl;
			if (head == NULL) {
				cout << "empty list" << endl;
			} else {
				Node* temp = head;
				while (temp != NULL) {
					if (!temp->status) {
						temp->display();
					}
					temp = temp->next;
				}
			}
			cout << "---" << endl;
		}
};
int main() {
	cout << "task management system" << endl;
	
	DLL tasks;
	tasks.add(1, "have breakefast", true);
	tasks.add(2, "SMM", true);
	tasks.add(3, "Go Uni");
	tasks.add(4, "have lunch", false);
	tasks.add(4, "Volleyball", false);
	
	tasks.add(6, "dinner");

	tasks.print();
	tasks.update();
	tasks.print_comp();
	tasks.print_not_completed();
	
	system("pause");
	return 0;
}
