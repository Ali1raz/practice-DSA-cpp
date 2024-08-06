#include <iostream>
using namespace std;

class Node {
	public:
		int id;
		string name;
		int cls;
		double cgpa;
		Node* next;

		Node(int i, string n, int c, double cgpa) {
			id = i;
			name = n;
			cls = c;
			cgpa = cgpa;
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
		
		void addStudent (int i, string n, int c, double cgpa) {
			Node* newnode = new Node(i, n, c, cgpa);
			newnode->next = NULL;
			
			if (head == NULL) {
				head = newnode;
			} else {
				Node* temp = head;
				while (temp->next) {
					temp= temp->next;
				}
				temp->next = newnode;
			}
		}

		void displayList () {
			cout << "\nPrinting List" << endl;
			if (!head) {
				cout <<"List is empty" << endl;
			} else {
				Node* temp = head;
				while (temp != NULL) {
					cout << "Student ID: " << temp->id << ", Name: " << temp->name
					     << ", Class: " << temp->cls << ", CGPA: " << temp->cgpa
					     << endl;
					temp = temp->next;
				}
			}
			cout << "----" << endl;
		}

		void updateMarks(int id, double marks) {
			cout << "\nUpdating marks of " << id << endl;
			if (!head) {
				cout <<"List is empty" << endl;
			} else {
				Node* temp = head;
				bool found = false;
				while (temp != NULL) {
					if (temp->id == id) {
						found = true;
						temp->cgpa = marks;
//						return; // only check first match
					}
					temp = temp->next;
				}
				if (!found) {
					cout << "Student not found with Id:" << id << endl;
				} else {
					cout << "Student marks with Id {" << id << "} updated" << endl;
				}
			}
		}

		void updateGpa(int id, double gpa) {
			cout << "\nUpdating GPA of: " << id << endl;
			if (!head) {
				cout <<"List is empty" << endl;
			} else {
				Node* temp = head;
				bool found = false;
				while (temp != NULL) {
					if (temp->id == id) {
						found = true;
						temp->cgpa = gpa;
						// return;
					}
					temp = temp->next;
				}
				if (!found) {
					cout << "no student found with id: " << id << endl;
				} else {
					cout << "GPA of {" << id << "} updated" << endl;
				}
			}
			cout << "----" << endl;
		}

		void viewGpaGreater3() {
			if (!head) {
				cout <<"List is empty" << endl;
			} else {
				Node* temp = head;
				bool found = false;
				while (temp != NULL) {
					if (temp->cgpa > 3.0) {
						found = true;
						cout << "Student ID: " << temp->id << ", Name: " << temp->name << ", Class: " << temp->cls << ", CGPA: " << temp->cgpa << endl;
					}
					temp = temp->next;
				}
				if (!found) {
					cout << "Student not dound" << endl;
				}
			}
			cout << "----" << endl;
		}

		void viewSem2Or3GpaLess2() {
			if (!head) {
				cout <<"List is empty" << endl;
			} else {
				bool found = false;
				Node* temp = head;
				while (temp != NULL) {
					if ((temp->cls == 2 || temp->cls == 3) && temp->cgpa < 2.0) {
						found = true;
						cout << "Student ID: " << temp->id
						     << ", Name: " << temp->name
						     << ", Class: " << temp->cls
						     << ", CGPA: " << temp->cgpa
						     << endl;
					}
					temp = temp->next;
				}
				if (!found) {
					cout << "Student not found" << endl;
				}
			}
			cout << "----" << endl;
		}
};

int main() {
	SLL list;

	list.addStudent(1, "Abc", 1, 3.5);
	list.addStudent(2, "Defgh", 2, 2.5);
	list.addStudent(3, "Bob", 3, 3.8);
	list.addStudent(4, "Jklmno", 2, 1.9);
	list.addStudent(5, "Mnop Q", 1, 3.2);

	list.displayList();
	
	list.updateMarks(2, 3);
	list.updateMarks(88, 3);
	
	list.updateGpa(3, 3.6);

	cout << "Students with GPA greater than 3.0:" << endl;
	list.viewGpaGreater3();

	cout << "\nStudents from semester 2 or 3 with GPA less than 2.0:" << endl;
	list.viewSem2Or3GpaLess2();

	system("pause");
	return 0;
}
