#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

Node* mergeTwoSortedLinkedLists(Node *head1, Node *head2) {
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    Node* head = NULL;
    Node* currentNode = NULL;
    
    if(head1->data < head2->data){
        head = head1;
        currentNode = head1;
        head1 = head1->next;
        currentNode->next = NULL;
    }
    else{
        head = head2;
        currentNode = head2;
        head2 = head2->next;
        currentNode->next = NULL;
    }
    
    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            Node* temp = head1->next;
            currentNode->next = head1;
            currentNode = currentNode->next;
            currentNode->next = NULL;
            head1 = temp;
        }
        else{
            Node* temp = head2->next;
            currentNode->next = head2;
            currentNode = currentNode->next;
            currentNode->next = NULL;
            head2 = temp;
        }
    }
    
    if(head1 == NULL){
        currentNode->next = head2;
    }
    else{
        currentNode->next = head1;
    }
    
    return head;
}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head1 = takeinput();
		Node *head2 = takeinput();
		Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
		print(head3);
	}
	return 0;
}