#include<iostream>
using namespace std;

int SumtillN(int n){

    if(n==0){
        return 0;
    }
    int ans=SumtillN(n-1);
    return n+ans;

}

int main(){
    int n;
    cin>>n;
    int ans=SumtillN(n);
    cout<<ans<<endl;

}