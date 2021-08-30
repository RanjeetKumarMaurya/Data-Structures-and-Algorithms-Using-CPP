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

int length(Node* head){
    if(head == NULL){
        return 0;
    }
    return 1 + length(head->next);
}

Node* appendLastNToFirst(Node* head,int n)
{
    if(head == NULL){
        return head;
    }
    
	int size = length(head);
    
    Node* temp = head;
    Node* temp1 = head;

    int i = 0;
    while(head->next != NULL && i < size){
        if(i = size - n - 1){
            temp1 = head->next;
            head->next = NULL;
            head = temp1;
            i++;
        }
        else{
            head = head->next;
            i++;
        }
    }
    
    head->next = temp;
    return temp1;
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
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}