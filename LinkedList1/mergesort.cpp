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

Node *midpoint(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *slow=head;
    Node *fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;

}

Node *merge(Node *head1,Node *head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    Node *c;
    if(head1->data<head2->data){
        c=head1;
        c->next=merge(head1->next,head2);
    }
    else{
        c=head2;
        c->next=merge(head1,head2->next);
    }
    return c;
}

Node *mergesort(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *mid=midpoint(head);
    Node *a=head;
    Node *b=mid->next;
    mid->next=NULL;
    a=mergesort(a);
    b=mergesort(b);

    //merge
    Node *c=merge(a,b);
    return c;
}

int main(){
    Node *head=takeinput_better();
    Node *ans=mergesort(head);
    print(ans);
}