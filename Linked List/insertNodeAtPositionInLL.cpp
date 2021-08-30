#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node* insertNodeReHelper(Node *head, int i, int data, Node* pre, Node* temp){
    
    if(head == NULL){
        temp = head;
        return temp;
    }
    
    if(i == 0){
        Node* newNode = new Node(data);
        pre->next = newNode;
        newNode->next = head;
        return temp;
    }
    
    insertNodeReHelper(head->next, i - 1, data, head, temp);
}


Node* insertNode(Node *head, int i, int data) {
    Node* temp = head;
    Node* pre = NULL;
    insertNodeReHelper(head, i, data, pre, temp);
    return temp;
}

Node *takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1) {
        Node *newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        Node *head = takeinput();
        int pos, data;
        cin >> pos >> data;
        head = insertNode(head, pos, data);
        print(head);
    }
}