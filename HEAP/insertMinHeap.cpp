#include<iostream>
#include<vector>
using namespace std;

class Heap{

    vector<int> v;
    public:
    Heap(int size=10){
        v.reserve(size);
        v.push_back(-1);

    }

    void push(int d){
        v.push_back(d);
        int idx=v.size()-1;
        int parent=idx/2;
        while(idx>1 and v[idx]>v[parent]){
            swap(v[idx],v[parent]);
            idx=parent;
            parent=parent/2;
        }

    }

};

int main(){
    Heap h;
    h.push(10);
    
}
