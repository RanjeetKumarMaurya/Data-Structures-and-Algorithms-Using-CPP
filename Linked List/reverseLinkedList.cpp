#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }

        ~Node(){
            delete next;
        }
};


Node* getInput(){
    int x;
    cin >> x;
    Node* head = new Node(x);
    Node* temp = head;

    int val;
    cin >> val;
    while (val != -1)
    {
        Node* newNode = new Node(val);
        head -> next = newNode;
        head = head->next;
        cin >> val;
    }
    return temp; 
}

void printLinkedList(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* reverseLinkedList(Node* head){
    if(head == NULL){
        return head;
    }

    Node* pre = NULL;
    while(head->next != NULL){
        Node* temp = head->next;
        head->next = pre;
        pre = head;
        head = temp;
    }
    head->next = pre;
    return head;
}

int main(){
    Node* head = getInput();
    printLinkedList(head);
    head = reverseLinkedList(head);
    printLinkedList(head);
    return 0;
}