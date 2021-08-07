#include <iostream>
#include<queue>
#include "TreeNode.h"
using namespace std;

//insert into tree
void insert(TreeNode<int>* root, int node, int value){
	if(root == NULL){
		return;
	}
	if(root->data == node){
		TreeNode<int>* node = new TreeNode<int>(value);
		root->children.push_back(node);
	}
	for(int i = 0; i < root->children.size(); ++i){
		insert(root->children[i], node, value);
	}
}

//take level wise input to the tree
TreeNode<int>* levelWiseInput(){
	queue<TreeNode<int>*> pendingQueue;

	int rootData;
	cout << "Enter root data : " << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	pendingQueue.push(root);

	//traverse through the pending queue
	while (!(pendingQueue.empty()))
	{
		TreeNode<int>* node = pendingQueue.front();
		pendingQueue.pop();

		int numChild;
		cout << "Enter number of child of node -> " << node->data << " : " << endl;
		cin >> numChild;
		for(int i = 0; i < numChild; ++i){
			int childData;
			cout << "Enter " << i + 1 << " th child of " << node->data << " : " << endl;
			cin >> childData;
			TreeNode<int>* node1 = new TreeNode<int>(childData);
			node->children.push_back(node1);
			pendingQueue.push(node1);
		}
	}
	return root;
}

//take input into tree
TreeNode<int>* takeInput(){
	cout << "Enter Root Data : " << endl;
	int rootData;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	cout << "Enter the number of Child of " << rootData << endl;
	int numChild;
	cin >> numChild;
	for(int i = 0; i < numChild; ++i){
		TreeNode<int>* node = takeInput();
		root->children.push_back(node);
	}
	return root;
}

//level wise printing
void levelWisePrint(TreeNode<int>* root){
	if(root == NULL){
		return;
	}
	queue<TreeNode<int>*> pendingQueue;
	pendingQueue.push(root);

	while(!(pendingQueue.empty())){
		TreeNode<int>* node = pendingQueue.front();
		pendingQueue.pop();

		cout << node->data << ":";
		for(int i = 0; i < node->children.size(); ++i){
			cout << node->children[i]->data << ",";
			pendingQueue.push(node->children[i]);
		}
		cout << endl;
	}
}

//print tree
void printTree(TreeNode<int>* root){
	if(root == NULL){
		return;
	}
	cout << root->data << ":";
	for(int i = 0; i < root->children.size(); ++i){
		cout << root->children[i]->data << ",";
	}
	cout << endl;

	for(int i = 0; i < root->children.size(); ++i){
		printTree(root->children[i]);
	}
}

//driver code
int main(){
	TreeNode<int>* root = levelWiseInput();

	//print tree
	cout << "Printing Tree : " << endl;
	levelWisePrint(root);
	//printTree(root);
	

	int ans;
	cout << "Enter 1 to insert any other value to exit : " << endl;
	cin >> ans;
	if(ans == 1){
		cout << "How many node do you want to insert? " << endl;
		int howMany;
		cin >> howMany;
		cout << "Enter " << howMany << " Node and value pair seperated by a space : " << endl;
		while (howMany > 0)
		{
			int a,b;
			cin >> a >> b;
			insert(root, a, b);
			howMany--;
		}
	}

	cout << "Printing Tree after final update: " << endl;
	levelWisePrint(root);
	//printTree(root);
	return 0;
}