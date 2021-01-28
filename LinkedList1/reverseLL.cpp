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

Node *ReverseLLiterative(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *smallerans=ReverseLLiterative(head->next);
    Node *tail=head->next;
    tail->next=head;
    head->next=NULL;
    return smallerans;
}

int main(){
    Node *head=takeinput_better();
    Node *ans=ReverseLLiterative(head);
    print(ans);
}