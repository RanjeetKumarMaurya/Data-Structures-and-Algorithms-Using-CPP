#include<bits/stdc++.h>
using namespace std;

//print graph in the order they inseted
void printDFS(int **edges, int n, int sv, bool *isVisited){
	cout << sv << " ";
	isVisited[sv] = true;

	for(int i = 0; i < n; ++i){
		if(i == sv){
			continue;
		}
		if(edges[sv][i] == 1){
			if(isVisited[i]){
				continue;
			}
			printDFS(edges, n, i, isVisited);
		}
	}
}

//BFS Traversal
void printBFS(int **edges, int n, int sv, bool *isVisited){
	queue<int> pendingQueue;
	pendingQueue.push(sv);

	while(pendingQueue.size() != 0){

		int front = pendingQueue.front();
		if(isVisited[front] == false){
			pendingQueue.pop();

			isVisited[front] = true;
			

			cout << front << " ";

			for(int i = 0; i < n; ++i){
				if((i != front) && (edges[front][i] == 1) && (isVisited[i] == false)){
					pendingQueue.push(i);
				}
			}
		}
		else{
			//make isVisited array false
			for(int i = 0 ; i <n; ++i){
				isVisited[i] = false;
			}
			break;
		}
	}
}

//print connected component 
void printConnectedComponenetInGraph(int **edges, int n){
	bool *isVisited = new bool[n];
	//make isVisited false by default
	for(int  i = 0; i < n; ++i){
		isVisited[i] = false;
	}

	//call for all unvisited nodes
	int comp = 0;
	for(int i = 0; i < n; ++i){
		if(isVisited[i] == false){
			comp++;
			cout << "\n" <<comp << "th component : ";
			printDFS(edges, n, i, isVisited);
		}
	}
	//delete isVisited array
	delete []isVisited;
}

//check if path exits
bool hasPath(int **edges, int n, int a, int b, bool * isVisited){
	if(edges[a][b] == 1){
		return true;
	}

	else{
		isVisited[a] = true;

	for(int i = 0; i < n; ++i){
		if((i != a) && (edges[a][i] == 1) && (isVisited[i] == false)){
			cout << "Checking through " << i << "th children of node " << a << endl;
			hasPath(edges, n, i, b, isVisited);
		}
	}
	//if not a path then return false and make isVisited array false;
	return false;
	}
	
}

//get path between twio node and print them
void getPath(int **edges, int n, int s, int d){
	unordered_map<int, int> map; //map to store the parent child relation between two node
	bool* isVisited = new bool[n]; // to store the visited node
	for(int i = 0; i < n; ++i){
		isVisited[i] = false;
	}


	queue<int> pendingQueue;
	pendingQueue.push(s);

	while(pendingQueue.size() != 0){
		int front = pendingQueue.front();
		pendingQueue.pop();
		isVisited[front] = true;

		for(int i = 0; i < n; ++i){
			if((edges[front][i] == 1) && (i == d)){
				map[i] = front;
				break;
			}
			if((i != front) && (edges[front][i] = 1) && (isVisited[i] == false)){
				map[i] = front;
				pendingQueue.push(i);
			}
		}
	}

	//print nodes using map
	int a = s;
	int b = d;
	cout << b << "->";
	int it = map[b];
	while(it != a){
		cout << it << "->";
		it = map[it];
	}
	cout << it << endl;
	/*
	vector<int> output;
	int it = map[b];
	output.push_back(it);
	while(it != a){
		it = map[it];
		output.push_back(it);
	}
	output.push_back(it);

	for(int i = output.size() - 1; i >= 0; --i){
		cout << output[i] << " " << endl;
	}
	*/

}


//Graph input for testing purpose
// 7 8 0 1 0 2 1 3 1 4 3 5 4 5 5 6 6 2
// 7 7 0 1 0 2 1 3 1 4 3 5 4 5 5 6
// 7 4 0 1 0 3 1 3 6 5


//driver code
int main(){

	int n, e;
	cout << "Enter number of vertex in the graph " << endl;
	cin >> n;
	//create a 2D matrix of size N x N and intialse it with zero
	int **edges = new int*[n];
	for(int i = 0; i < n; ++i){
		int *edges1 = new int[n];
		edges[i] = edges1;
		for(int j = 0; j < n; ++j){
			edges[i][j] = 0;
		}
	}

	//insert edges of the graph (Treat it as an undirected graph)
	cout << "Enter number of edges " << endl;
	cin >> e;

	cout << "Enter " << e << " edges seperate by a space " << endl;
	for(int i = 0; i < e; ++i){
		cout << "Enter " << i << " th edges (Enter starting vertex and end vertex e. g. 3 4) ";
		int f,t;
		cin >> f >> t;
		edges[f][t] = 1;
		edges[t][f] = 1;
	}

	//create a visited matrix of size N and intialise it with zero
	bool *isVisited = new bool[n];
	for(int i = 0; i < n; ++i){
		isVisited[i] = false;
	}

	//print graph
	cout << "\n\nDFS traversal of the graph : " << endl;
	printDFS(edges, n, 0, isVisited);
	//make isVisted array false
	for(int i = 0; i < n; ++i){
	isVisited[i] = false;
	}

	//print bsf traversal of graph
	cout << "\n\nBFS Traversal of the graph is : " << endl;
	printBFS(edges, n, 0, isVisited);

	//print all connected component of a graph
	cout << "\n\nConnected component of graph " << endl;
	printConnectedComponenetInGraph(edges, n);

	//check if there exits a path between two node
	int a, b;
	cout << "\n\nEnter two node to check if there exist a path between them " << endl;
	cin >> a >> b;
	bool path = hasPath(edges, n, a, b, isVisited);
	if(path){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}

	//check if there exits a path between two node if yes then print the nodes in between using BFS
	/*
	int s, d;
	cout << "\n\nEnter two node to check if there exist a path between them " << endl;
	cin >> s >> d; 
	cout << "Printing if path exist between node " << s << " and " << "node " << d << endl;
	getPath(edges, n, s, d);
	*/


	//free all memory
	for(int i = 0; i < n; ++i){
		delete edges[i];
	}
	delete []edges;

	delete []isVisited;

	return 0;

}