#include<iostream>
#include<climits>
using namespace std;


class StackusingArray{
    int *data;
    int nextindex;
    int capacity;

    public:

    StackusingArray(int totalsize){
        data=new int[totalsize];
        capacity=totalsize;
        nextindex=0;
    }

    int size(){
        return nextindex;
    }

    bool isempty(){
        return nextindex==0;
    }

    void push(int element){
        if(nextindex==capacity){
            cout<<"Stack is FULL "<<endl;
            return;
        }
        data[nextindex]=element;
        nextindex++;
    }

    int pop(){
        if(nextindex==0){
            cout<<"stack is empty"<<endl;
            return INT_MIN;
        }
        nextindex--;
        int del=data[nextindex];
        return del;
    }

    int top(){
        if(nextindex==0){
            cout<<"stack is empty"<<endl;
            return INT_MIN;
        }
        return data[nextindex-1];
    }

};

int main(){
    StackusingArray s(5);
    s.push(89);
    s.push(12);
    s.push(1);
    s.push(7);
    s.push(70);
    s.push(77);
    //s.pop();
    //s.pop();
    //s.pop();
    //s.pop();

    cout<<s.top()<<endl;
    cout<<s.top()<<endl;

    cout<<s.size()<<endl;

}