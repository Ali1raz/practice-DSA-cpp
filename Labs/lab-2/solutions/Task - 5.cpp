//INVENTORY MANAGEMENT SYSTEM
#include <iostream>
using namespace std;

class Node {
	public:
		string name;
		int id;
		int qnt;
		int price;
		Node* next;
		Node* prev;

		Node(int i, string n, int p, int q) {
			id =i;
			name = n;
			price = p;
			qnt = q;
			next = NULL;
			prev = NULL;
		}

		void print() {
			cout << id << " >> "
			     << name << "\t>> "
			     << price << "\t"
			     << qnt << "\t"
			     << endl;
		};
};

class DLL {
		Node* head;
		Node* tail;
	public:
		DLL() {
			head = NULL;
			tail = head;
		}

		void add(int id, string name, int price, int qnt) {
			Node* newnode = new Node(id, name, price, qnt);
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
			cout << "printing " << endl;
			if (head == NULL) {
				cout << "emty DLL" << endl;
			} else {
				Node* temp = head;
				while (temp != NULL) {
					temp->print();
					temp = temp->next;
				}
			}
			cout << "---" << endl;
		}

		void update(int id) {
			bool found = false;
			cout << "Updating " << id << endl;
			Node* temp = head;
			while (temp) {
				if (temp->id == id) {
					cout << "Enter qnt: ";
					cin >>temp->qnt;
					found = true;
					cout << "updated " << temp->name;
					temp->print();
				}
				temp = temp->next;
			}
			if (!found) {
				cout << id << " not found..." << endl;
			}

			cout << "---" << endl;
		}

		void remove(int id) {
			Node* temp = head;
			while (temp && temp->id != id) {
				temp= temp->next;
			}
			if (!temp) {
				cout << id << " not found" << endl;
			} else {
				if (temp == head) {
					head = head->next;
					cout<<"head";
				} else if (temp == tail) {
					tail = tail->prev;
				} else {
					temp->next->prev = temp->prev;
					temp->prev->next = temp->next;
				}
				cout << "deleted " << temp->name << endl;
				delete temp;
			}
			cout << "---" << endl;
		}

		void with_low_stock() {
			cout << "printing products with low stock" << endl;
			Node* temp = head;
			int count = 0;
			while (temp != NULL) {
				if (temp->qnt < 30) {
					++count;
					temp->print();
				}
				temp = temp->next;
			}
			cout << "total count " << count << endl;
			if (!count) {
				cout << "no product is in low stock" << endl;
			}

			cout << "---" << endl;
		}
};

int main() {
	DLL is;
	is.add(1, "shirts", 700, 43);
	is.add(2, "jeans", 900, 28);
	is.add(3, "jogers", 2200, 49);
	is.add(4, "snacker", 2350, 56);
	is.add(5, "loafers", 2350, 34);
	is.add(6, "shiners", 150, 72);
	is.add(7, "sandles", 1600, 45);
	is.add(8, "boots", 2350, 25);
	is.add(9, "slpers", 400, 29);
	is.add(10, "trainee", 1150, 29);

	is.print();
	
	is.remove(4);
	is.print();
	
	is.update(2);
	is.print();
	
	is.with_low_stock();
	
	system("pause");
	return 0;
}
