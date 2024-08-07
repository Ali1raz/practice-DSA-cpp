#include <iostream>
#include <limits>
#include <queue>
using namespace std;

class Node {
	public:
		int data;
		Node* left;
		Node* right;

		Node(int d) {
			data = d;
			left = NULL;
			right = NULL;
		}
};

class Btree {
		Node* root;

		Node* insertRec (Node* curr, int d) {
			if (!curr) {
				return new Node(d);
			} else if (d < curr->data) {
				curr->left = insertRec(curr->left, d);
			} else {
				curr->right = insertRec(curr->right, d);
			}
			return curr;
		}

		int minValueNode(Node* node) {
			Node* current = node;
			while (current && current->left != NULL) {
				current = current->left;
			}
			return current->data;
		}
		int maxValueNode(Node* node) {
			Node* current = node;
			while (current && current->right != NULL) {
				current = current->right;
			}
			return current->data;
		}
	public:
		Btree () {
			root = NULL;
		}

		Node* getRoot() {
			return root;
		}

		void insert (int d) {
			root = insertRec(root, d);
		}

		void InorderDFS (Node* node) {
			if (getRoot() == NULL) {
				cout << "enter nodes first\n---" << endl;
			} else {
				if (!node) return;
				InorderDFS(node->left);
				cout << node->data << "\t";
				InorderDFS(node->right);
			}
		}

		void PreorderDFS (Node* node) {
			if (getRoot() == NULL) {
				cout << "enter nodes first\n---" << endl;
			} else {
				if (!node) return;
				cout << node->data << "\t";
				PreorderDFS(node->left);
				PreorderDFS(node->right);
			}
		}

		void PostorderDFS (Node* node) {
			if (getRoot() == NULL) {
				cout << "enter nodes first\n---" << endl;
			} else {
				if (!node) return;
				PostorderDFS(node->left);
				PostorderDFS(node->right);
				cout << node->data << "\t";
			}
		}

		void print_min_node() {
			if (getRoot() == NULL) {
				cout << "enter nodes first\n---" << endl;
			} else {
				cout << "Node with min val: " << minValueNode(root) << "\n---" << endl;
			}
		}

		void print_max_node() {
			if (getRoot() == NULL) {
				cout << "enter nodes first\n---" << endl;
			} else
				cout << "Node with max val: " << maxValueNode(root) << "\n---" << endl;
		}

		void BFS (Node* node) {
			if (getRoot() == NULL) {
				cout << "enter nodes first\n---" << endl;
			} else {
				if (getRoot() == NULL) {
					cout << "enter nodes first\n---" << endl;
				} else {
					if (node == NULL) {
						return;
					}
					queue<Node*> q;
					q.push(node);
					while (!q.empty()) {
						Node* curr = q.front();
						cout << curr->data << "\t";
						q.pop();
						if (curr->left != NULL) {
							q.push(curr->left);
						}
						if (curr->right != NULL) {
							q.push(curr->right);
						}
					}
				}
			}
			cout << "\n----" << endl;
		}

		Node* searchNode(Node* node, int val) {
			if (node == NULL || node->data == val) {
				return node;
			}
			Node* leftResult = searchNode(node->left, val);
			if (leftResult) {
				return leftResult;
			}
			return searchNode(node->right, val);
		}

		void print_children() {
			if (getRoot() == NULL) {
				cout << "enter nodes first\n---" << endl;
			} else {

				int tv;
				cout << "Enter target Node<int>: ";
				cin >> tv;
				Node* tn = searchNode(getRoot(), tv);
				if (tn) {
					cout << "Subtree after " << tv << " :" << endl;
					InorderDFS(tn);
					cout << endl;
				}
			}
		}

		Node* minValNode(Node* node) {
			Node* curr = node;
			while (curr && curr->left) curr = curr->left;
			return curr;
		}

		Node* deleteNode(Node* root, int d) {
			if (getRoot() == NULL) {
				cout << "enter nodes first\n---" << endl;
			} else {

				if (root == NULL) {
					return root;
				}
				if (d < root->data) {
					root->left = deleteNode(root->left, d);
				} else if (d > root->data) {
					root->right = deleteNode(root->right, d);
				} else {
					if (root->left == NULL) {
						Node* temp = root->right;
						delete root;
						return temp;
					} else if (root->right == NULL) {
						Node* temp = root->left;
						delete root;
						return temp;
					}
					Node* temp = minValNode(root->right);
					root->data = temp->data;
					root->right = deleteNode(root->right, temp->data);
				}
				return root;
			}
		}
};

void printDFSMenu(Btree t) {
	system("cls"); // clears console in windows
	// system("clear"); //for Linux or macOS
	cout << "DFS traversal:\n[1]: Preorder\n[2]: Inorder\n"
	     "[3]: Postorder\n[0]: back\n----" << endl;
	string dfs;
	cout << "Enter command: ";
	while (dfs[0] != '0') {

		getline(cin, dfs);
		if (dfs.empty()) continue;
		switch(dfs[0]) {
			case '0':
				cout << "exiting..." << endl;
				break;
			case '1':
				cout << "Preorder DFS:" << endl;
				t.PreorderDFS(t.getRoot());
				cout << endl;
				break;
			case '2':
				cout << "Iorder DFS:" << endl;
				t.InorderDFS(t.getRoot());
				cout << endl;
				break;
			case '3':
				cout << "Postrder DFS:" << endl;
				t.PostorderDFS(t.getRoot());
				cout << endl;
				break;
			default:
				cout << "command not found! Try again: ";
//				break;
		}
	}
}

int input_int (int& input) {
	while (!(cin >> input)) {
		cout << "Try again<int>: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
//	int org = input;
//	return org;
	return input;
}

int main() {
	Btree t;

	string ch;
	while (ch[0] != '0') {
		cout << "[1]: Insert Node\n[2]: DFS traversal\n"
		     "[3]: BFS traversal\n"
		     "[4]: search\n[5]: Print Children of current Node\n"
		     "[6]: Max value\n[7]: min vlaue\n"
		     "[8]: to delete a node\n"
		     "[0]: exit\n----" << endl;
		cout << "Enter command: ";
//			cin.ignore();
//		getline(cin, ch);
		cin >> ch;
		cin.ignore();
		switch (ch[0]) {
			case '0':
				cout << "exiting..." << endl;
				break;
			case '1':
				cout << "insert" << endl;
				cout << "Insert" << endl;
				while (true) {
					cout << "[0]: Exit\nEnter data<int>: ";
					int data = input_int(data);
					if (data == 0) break;
					t.insert(data);
				}
				break;
			case '2':
				printDFSMenu(t);
				break;
			case '3':
				system("cls");
				cout << "BFS: " << endl;
				t.BFS(t.getRoot());
				cout << endl;
				break;
			case '4':
				int search;
				cout << "enter data to search<int>: ";
				input_int(search);
				cout << "searching: " << search << endl;
				if (t.searchNode(t.getRoot(), search) != NULL) {
					cout << "value: " << search << " found" << endl;
				} else {
					cout << "value: " << search << " not found" << endl;
				}
				cout << "---" << endl;
				break;
			case '5':
				cout << "printin child:" << endl;
				t.print_children();
				break;
			case '6':
				t.print_max_node();
				break;
			case '7':
				t.print_min_node();
				break;
			case '8':
				int node;
				while (true) {
					cout << "enter node to delete: ";
					cin >> node;
					if (node || node > 0) {
						t.deleteNode(t.getRoot(), node);
						break;
					}
				}
				break;
			default:
				cout << "command [" << ch[0] << "] not found! Try again: ";
				break;
		}
	}

	system("pause");
	return 0;
}

