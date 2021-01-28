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

Node* deletenode(Node *head,int i){
    if(i==0){
        return head->next;
    }
    Node *temp=head;
    int count=0;
    while(temp!=NULL && count<i-1){
        temp=temp->next;
        count++;
    }
    if(temp==NULL || temp->next==NULL){
        return head;
    }
    temp->next=temp->next->next;
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
    print(head);
}