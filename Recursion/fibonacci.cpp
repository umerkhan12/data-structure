#include<iostream>
using namespace std;

int SumtillN(int n){

    if(n==0){
        return 0;
    }
    int ans=SumtillN(n-1);
    return n+ans;

}

int fibonacci(int n){
    if(n==0 || n==1){
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}

int main(){
    int n;
    cin>>n;
    int ans=fibonacci(n);
    cout<<ans<<endl;

}