#include<iostream>
#include "node.h"
using namespace std;

Node* takeinput_better(){
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    while(data!=-1){
        Node *newnode=new Node(data);
        if(head==NULL){
           head=newnode;
           tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
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

void printithnode(Node *head,int i){
    if(i<0){
        return;
    }
    int count=0;
    Node *temp=head;
    while(temp!=NULL){
        if(i==count){
            cout<<temp->data<<endl;
        }
        temp=temp->next;
        count++;
    }

    
}

int main(){
    Node *head=takeinput_better();
    printithnode(head,2);
    print(head);
}