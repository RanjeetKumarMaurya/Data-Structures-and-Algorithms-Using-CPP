#include <iostream>

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

//return mid point of linked list
Node* midPoint(Node *head)
{   
    Node* slow = head;
    Node* fast = head->next;
    
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

//merge two sorted linked list
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
    
    while(head1 && head2){
        if(head1->data < head2->data){
            //Node* temp = head1->next;
            currentNode->next = head1;
            currentNode = currentNode->next;
            //currentNode->next = NULL;
            //head1 = temp;
            head1 = head1->next;
        }
        else{
            //Node* temp = head2->next;
            currentNode->next = head2;
            currentNode = currentNode->next;
            //currentNode->next = NULL;
            //head2 = temp;
            head2 = head2->next;
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


Node *mergeSort(Node* head)
{
    //base consition
    if(head == NULL){
        return head;
    }
    
	if(head->next == NULL){
        return head;
    }  
    
    
    //find mid
    Node* mid = midPoint(head);
    Node* temp = mid->next;
    mid->next = NULL;
    
    head = mergeSort(head);
    temp = mergeSort(temp);
    return mergeTwoSortedLinkedLists(head, temp);
}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
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
		Node *head = takeinput();
		head = mergeSort(head);
		print(head);
	}

	return 0;
}