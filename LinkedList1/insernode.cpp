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

Node *insertnode(Node *head,int i,int data){
    Node *newnode=new Node(data);
    if(i==0){
        newnode->next=head;
        head=newnode;
        return head;

    }
    Node *temp=head;
    int count=0;
    while(temp!=NULL && count<i-1){
        temp=temp->next;
        count++;

    }
    if(temp!=NULL){
        Node *a=temp->next;
        temp->next=newnode;
        newnode->next=a;
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
    Node *head=takeinput_better();
    Node *head1=insertnode(head,2,99);
    print(head1);
}