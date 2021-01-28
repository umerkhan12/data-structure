#include<iostream>
#include "node.h"
using namespace std;

Node* takeinput(){
    int data;
    cin>>data;
    Node *head=NULL;
    while(data!=-1){
        Node *newnode=new Node(data);
        if(head==NULL){
            newnode->next=head;
            head=newnode;
        }
        else{
            Node *temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
        }
        cin>>data;
    }
    return head;
}

void print(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){
    Node *head=takeinput();
    print(head);
}