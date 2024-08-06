#include <iostream>
using namespace std;

class Node {
	public:
		int id;
		string name;
		double price;
		int qnt;
		Node* next;

		Node(int i, string n, double p, int q) {
			id = i;
			name = n;
			price = p;
			qnt = q;
			next = NULL;
		}
};

class SLL {
		Node* head;

	public:
		SLL() {
			head = NULL;
		}

		void addItem(int i, string n, double p, int q) {
			Node* newnode = new Node(i, n, p, q);
			newnode->next = NULL;

			if (!head) {
				head = newnode;
			} else {
				Node* temp = head;
				while (temp->next) {
					temp = temp->next;
				}
				temp->next = newnode;
			}
		}

		void deleteItem(int id) {
			cout << "\nDeleting item {" << id << "}:" << endl;
			if (head == NULL) {
				cout << "Shopping cart is empty." << endl;
			} else {
				bool found = false;
				if (head->id == id) {
					found = true;
					Node* temp = head;
					head = head->next;
					delete temp;
				} else {
					Node* temp = head;
					while (temp->next) {
						if (temp->next->id == id) {
							found = true;
							Node* nodeToDelete = temp->next;
							temp->next = temp->next->next;
							delete nodeToDelete;
							break;
						}
						temp = temp->next;
					}
				}
				
				if (!found) {
					cout << "Item not found in shopping cart." << endl;
				} else {
					cout << "Item with id {" << id << "} deleted" << endl;
				}
				
			}
			cout << "---" << endl;
		}

		void changeQuantity(int id, int quantity) {
			cout << "\nUpdating Qnt" << endl;
			if (!head) {
				cout << "List is empty " << endl;
			} else {
				bool found = false;
				Node* temp = head;
				while (temp) {
					found = true;
					if (temp->id == id) {
						temp->qnt = quantity;
					}
					temp = temp->next;
				}
				if (!found) {
					cout << "Item not found in shopping cart." << endl;
				} else {
					cout << "Item id {"  << id << "} Updated" << endl;
				}
			}
			cout << "---" << endl;
		}

		void calculateBill() {
			cout << "\nCalculating Bill" << endl;
			if (!head) {
				cout << "list is empty" << endl;
			} else {
				double totalBill = 0;
				Node* temp = head;
				while (temp) {
					totalBill += temp->price * temp->qnt;
					temp = temp->next;
				}
				cout << "Total bill: " << totalBill << endl;
			}
		}

		void displayCart() {
			cout << "\nDisplay Cart" << endl;
			if (!head) {
				cout << "list is empty" << endl;
			} else {
				Node* temp = head;
				while (temp) {
					cout << "Item ID: " << temp->id
					     << ", Name: " << temp->name
					     << ", Price: " << temp->price
					     << ", Quantity: " << temp->qnt
					     << endl;
					temp = temp->next;
				}
			}
			cout << "---" << endl;
		}
};

int main() {
	SLL cart;

	cart.addItem(1, "Apple", 1.00, 2);
	cart.addItem(2, "Banana", 0.50, 3);
	cart.addItem(3, "Orange", 1.50, 1);

	cart.displayCart();

	cart.changeQuantity(2, 4);

	cart.displayCart();

	cart.deleteItem(3);
//	cart.deleteItem(99);

	cart.displayCart();

	cart.calculateBill();
	
	system("pause");
	return 0;
}

