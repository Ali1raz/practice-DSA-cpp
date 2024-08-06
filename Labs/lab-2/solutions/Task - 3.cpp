#include <iostream>
using namespace std;

class Node {
	public:
		string name;
		string program;
		int id;
		bool isCompleted;
		Node* next;
		Node* prev;
		Node(int i, string n, string p, bool c) {
			id = i;
			name = n;
			program = p;
			isCompleted = c;
			next = NULL;
			prev = NULL;
		}

		string getCompleted() {
			return isCompleted ? "completed" : "____";
		}

		void display () {
			cout << "id: " << id
			     << "\tName: " << name << "\tProgram: " << program
			     << " status: " << getCompleted()
			     << endl;
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

		void print() {
			cout << "\nPrinting List" << endl;
			if (head == NULL ) {
				cout << "List is empty" << endl;
			} else {
				cout << "printing..." << endl;
				Node* temp = head;
				while (temp) {
					temp->display();
					temp = temp->next;
				}
			}
			cout << "---" << endl;
		}

		void add(int id, string name, string program, bool isCompleted) {
			Node* newnode = new Node(id, name, program, isCompleted);
			newnode->next = NULL;
			newnode->prev = tail;

			if (head == NULL) {
				head = newnode;
			} else {
				tail->next = newnode;
			}
			tail = newnode;
		}

		void update() {
			int id;
			cout << "Request for change status of: ";
			cin >> id;
			Node* temp = head;
			bool found = false;
			while (temp) {
				if (temp->id == id) {
					cout << "previus status of " << id << ": " << temp->getCompleted() << endl;
					// temp->isCompleted = !temp->isCompleted;
					temp->isCompleted = true;
					found = true;
					temp->display();
				}
				temp = temp->next;
			}
			if (!found)	cout << id << " not found..." << endl;
			else cout << id << " Updated" << endl;
			cout << "---" << endl;
		}

		void print_comp() {
			cout << "printing completed list..." << endl;
			if (head == NULL) {
				cout << "empty list" << endl;
			} else {
				Node* temp = head;
				while (temp != NULL) {
					if (temp->isCompleted) {
						temp->display();
					}
					temp = temp->next;
				}
			}
			cout << "---" << endl;
		}

		void print_notCompleted() {
			cout << "printing not completed list..." << endl;
			if (head == NULL) {
				cout << "empty list" << endl;
			} else {
				Node* temp = head;
				while (temp != NULL) {
					if (!temp->isCompleted) {
						temp->display();
					}
					temp = temp->next;
				}
			}
			cout << "---" << endl;
		}
};
int main() {
	DLL list;
	list.add(2, "ali", "bse", true);
	list.add(2, "Abdullah", "bse", true);
	list.add(1, "waseem", "bse", true);
	list.add(3, "ahmar", "bse", false);
	list.add(4, "naveed", "bse", false);
	list.add(5, "hassan", "bse", false);
	list.add(6, "zubair", "bse", true);
	list.add(6, "asif", "bse", true);

	list.print();

	list.update();

	list.print_comp();
	list.print_notCompleted();
	
	system("pause");
	return 0;
}
