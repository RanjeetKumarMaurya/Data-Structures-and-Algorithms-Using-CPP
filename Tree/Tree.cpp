#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//create tree node and intialise it
template <typename T>
class TreeNode{
	public:
		T data;
		vector<TreeNode<T>*> children;
	
	//intialise tree node
	TreeNode(T data){
		this -> data = data;
	}
	
	//deintialise tree node
	~TreeNode(){
		for(int i = 0; i < children.size(); i++){
			delete children[i];
		}
	}
};

//populated tree level wise
TreeNode<int>* takeInputLevelWise(){
	
	int node;
	cin >> node;
	TreeNode<int>* root = new TreeNode<int>(node);
	
	queue<TreeNode<int>*> pendingNodes;
	
	pendingNodes.push(root);
	
	while(pendingNodes.size() != 0){
		TreeNode<int>* temp = pendingNodes.front();
		pendingNodes.pop();
		
		int numOfChild;
		cin >> numOfChild;
		
		while(numOfChild){
			int d;
			cin >> d;
			TreeNode<int>* newNode = new TreeNode<int>(d);
			temp->children.push_back(newNode);
			pendingNodes.push(newNode);
			
			numOfChild--;
		}
		
	}
	return root;
}


//driver code
int main(){
	TreeNode<int>* root = takeInputLevelWise();
	cout << root -> data;
}


