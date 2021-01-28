#include<iostream>
#include "Node.h"
using namespace std;


node *takeinput(){
    int data;
    cin>>data;
    
    node *head=NULL;
    node *tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);

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

void print(node *head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}


node *midpoint(node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node *slow=head;
    node *fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

node *merge(node *head1,node *head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    node *c;
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

node *mergesort(node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node *mid=midpoint(head);
    node *a=head;
    node *b=mid->next;
    mid->next=NULL;
    a=mergesort(a);
    b=mergesort(b);
    node *final=merge(a,b);
    return final;
}

int length(node *head){
    if(head==NULL){
        return 0;
    }
    return 1+length(head->next);
}

node *appendNlasttoFirst(node *head,int n){

    if(head==NULL || head->next==NULL){
        return head;
    }
    int len=length(head);
    int count=len-n;
    int i=0;
    node *prev=NULL;
    node *temp=head;
    while(temp!=NULL && i<count){
        prev=temp;
        temp=temp->next;
        i++;
    }
    node *h1=temp->next;
    while(h1!=NULL && h1->next!=NULL){
        h1=h1->next;
    }
    h1->next=head;
    if(prev!=NULL){
        prev->next=NULL;
    }
    return temp;


}


node *reverse(node *head){
    /*if(head==NULL || head->next){
        return head;
    }*/
    node *nextnode=head;
    node *curr=head;
    node *prev=NULL;
    while(nextnode!=NULL){
        nextnode=nextnode->next;
        curr->next=prev;
        prev=curr;
        curr=nextnode;
    }
    return prev;


}

node *reverserec(node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node *smallans=reverserec(head->next);
    node *tail=head->next;
    tail->next=head;
    head->next=NULL;
    return smallans;
}

node *removeduplicates(node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node *t1=head;
    node *t2=head->next;
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
    return head;
}


int main(){
    node *head=takeinput();
    node *ans=removeduplicates(head);
    print(ans);
}