#include<iostream>
using namespace std;

int SumtillN(int n){

    if(n==0){
        return 0;
    }
    int ans=SumtillN(n-1);
    return n+ans;

}

int factorial(int n){
    if(n==0){
        return 1;
    }
    return n*factorial(n-1);
}

int main(){
    int n;
    cin>>n;
    int ans=factorial(n);
    cout<<ans<<endl;

}