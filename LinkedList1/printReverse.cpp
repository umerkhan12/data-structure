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

void printreverse(Node *head){
    if(head==NULL){
        return;
    }
    printreverse(head->next);
    cout<<head->data<<endl;
}

void removeduplicates(Node *head){
    Node *t1=head;
    Node *t2=head->next;
    while(t2!=NULL){
        if(t1->data!=t2->data){
            t1=t1->next;
            t2=t2->next;
            t1->next=t2;
        }
        else{
            t2=t2->next;
        }
        t1->next=t2;
    }
    //return t1;
}

Node *mergetwoSortedLL(Node *head1,Node *head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    Node *c;
    if(head1->data<head2->data){
        c=head1;
        c->next=mergetwoSortedLL(head1->next,head2);
    }
    else{
        c=head2;
        c->next=mergetwoSortedLL(head1,head2->next);
    }
    return c;
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

int main(){
   /* Node *head=takeinput_better();
    removeduplicates(head);
    print(head);
    cout<<endl;
    Node *ans=midpoint(head);
    cout<<"mid point is:::"<<ans->data<<endl;*/
    Node *head1=takeinput_better();
    Node *head2=takeinput_better();
    Node *head3=mergetwoSortedLL(head1,head2);
    print(head3);
}