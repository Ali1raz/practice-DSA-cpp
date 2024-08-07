#include <iostream>
using namespace std;

const int maxVertices = 100;
string vertices[maxVertices];
int graph[maxVertices][maxVertices];
int vCount = 0;

void addVertex(string v) {
	vertices[vCount] = v;
	vCount++;
}

void addEdge(string u, string v, int cost) {
	int idxU, idxV = -1;
	for (int i=0; i<maxVertices; i++) {
		if (vertices[i] == u) {
			idxU = i;
		}
		if (vertices[i] == v) {
			idxV = i;
		}
	}
	if (idxU != -1 && idxV != -1) {
		graph[idxU][idxV] = cost; // if directed graph
	}
}

int getIndex (string v) {
	for (int i=0; i<maxVertices; i++) {
		if (vertices[i] == v) {
			return i;
		}
	}
}

void printGraph() {
	cout << "Printing Graph:" << endl;
	for (int i=0; i<maxVertices; i++) {
		cout << vertices[i] << "	";
	}
	cout << endl;

	cout << "----" << endl;

	cout << "Adjacency matrix:" << endl;
	for (int i=0; i < vCount; i++) {
		for (int j=0; j<vCount; j++) {
			cout << graph[i][j] << "\t";
		}
		cout << endl;
	}


}

int main() {
	addVertex("dallas");
	addVertex("austin");
	addVertex("denver");
	addVertex("chicago");
	addVertex("houston");
	addVertex("washington");
	addVertex("atlanta");

	addEdge("dallas", "austin", 200);
	addEdge("dallas", "denver", 780);
	addEdge("dallas", "chicago", 900);

	addEdge("austin", "dallas", 200);
	addEdge("austin", "houston", 160);

	addEdge("chicago", "denver", 1000);

	addEdge("denver", "chicago", 1000);
	addEdge("denver", "atlanta", 1400);

	addEdge("houston", "atlanta", 800);

	addEdge("atlanta", "washington", 600);
	addEdge("atlanta", "houston", 800);

	addEdge("washington", "atlanta", 600);
	addEdge("washington", "dallas", 1300);

	printGraph();

	system("pause");
	return 0;
}

