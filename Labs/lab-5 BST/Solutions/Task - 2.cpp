#include <iostream>
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

class btree {
		Node* root;
	public:
		btree () {
			root= NULL;
		}

		Node* get_root() {
			return root;
		}

		Node* insertRec (Node* curr, int d) {
			if (curr == NULL) {
				return new Node(d);
			}
			if (d < curr->data) {
				curr->left = insertRec(curr->left, d);
			} else {
				curr->right = insertRec(curr->right, d);
			}
			return curr;
		}

		void insert(int d) {
			root = insertRec(root, d);
		}

		void inorder (Node* node) {
			if (node == NULL) {
				return;
			}
			inorder(node->left);
			cout << node->data << "\t";
			inorder(node->right);
		}

		void postorder (Node* node) {
			if (node == NULL) {
				return;
			}
			postorder(node->left);
			postorder(node->right);
			cout << node->data << "\t";
		}

		void preorder (Node* node) {
			if (node == NULL) {
				return;
			}
			cout << node->data << "\t";
			preorder(node->left);
			preorder(node->right);
		}

		Node* minValNode(Node* node) {
			Node* curr = node;
			while (curr && curr->left) {
				curr = curr->left;
			}
			return curr;
		}

		Node* deleteNode(Node* root, int d) {
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
};
int main() {
	btree t;
	t.insert(3);
	t.insert(5);
	t.insert(4);
	t.insert(9);
	t.insert(8);
	t.insert(7);
	t.insert(2);
	t.insert(1);
	t.insert(10);

	cout << "inorderDFS: " << endl;
	t.inorder(t.get_root());
	cout << endl;

	cout << "preorderDFS: " << endl;
	t.preorder(t.get_root());
	cout << endl;

	cout << "postorderDFS: " << endl;
	t.postorder(t.get_root());
	cout << endl;

	cout << "\n----\nCase I::" << endl;
	cout << "Node having no child [ 7 ]:" << endl;
	t.deleteNode(t.get_root(), 7);
	t.inorder(t.get_root());
	cout << endl;

	cout << "\n----\nCase II::" << endl;
	cout << "Node having 1 child { 2 }:" << endl;
	t.deleteNode(t.get_root(), 2);
	t.inorder(t.get_root());
	cout << endl;

	cout << "\n----\nCase III::" << endl;
	cout << "Node having 2 child [ 9 ]:" << endl;
	t.deleteNode(t.get_root(), 9);
	t.inorder(t.get_root());
	cout << endl;

	system("pause");
	return 0;
}
