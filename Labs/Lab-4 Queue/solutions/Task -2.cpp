
#include <iostream>
using namespace std;

class Node {
	public:
		string taskName;
		Node* next;
		Node(string taskName) {
			this->taskName = taskName;
			next = NULL;
		}
};

class Printer {
	public:
		Node* front;
		Node* rear;
		Printer() {
			front = NULL;
			rear = NULL;
		}
		void addPrintJob(string taskName) {
			Node* newNode = new Node(taskName);
			if (rear == NULL) {
				front = newNode;
				rear = newNode;
			} else {
				rear->next = newNode;
				rear = newNode;
			}
			cout << "Print job '" << taskName << "' added to printer" << endl;
		}
		void printCurrentJob() {
			if (front == NULL) {
				cout << "No print jobs in printer" << endl;
			} else {
				cout << "Currently printing: " << front->taskName << endl;
			}
		}
		void printNextJob() {
			if (front == NULL) {
				cout << "No print jobs in printer" << endl;
			} else {
				Node* temp = front;
				front = front->next;
				if (front == NULL) {
					rear = NULL;
				}
				delete temp;
				cout << "Printed job" << endl;
			}
		}
};

int main() {
	Printer P1;
	Printer P2;
	Printer P3;
	while (true) {
		cout << "Choose a printer (1/2/3): ";
		int choice;
		cin >> choice;
		cout << "Enter print job name: ";
		string taskName;
		cin >> taskName;
		switch (choice) {
			case 1:
				P1.addPrintJob(taskName);
				break;
			case 2:
				P2.addPrintJob(taskName);
				break;
			case 3:
				P3.addPrintJob(taskName);
				break;
			default:
				cout << "Invalid choice" << endl;
		}
		cout << "Print current job? (y/n): ";
		char printCurrent;
		cin >> printCurrent;
		if (printCurrent == 'y') {
			switch (choice) {
				case 1:
					P1.printCurrentJob();
					break;
				case 2:
					P2.printCurrentJob();
					break;
				case 3:
					P3.printCurrentJob();
					break;
			}
		}
		cout << "Print next job? (y/n): ";
		char printNext;
		cin >> printNext;
		if (printNext == 'y') {
			switch (choice) {
				case 1:
					P1.printNextJob();
					break;
				case 2:
					P2.printNextJob();
					break;
				case 3:
					P3.printNextJob();
					break;
			}
		}
	}
}

