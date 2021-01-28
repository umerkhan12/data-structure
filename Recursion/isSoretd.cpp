#include<iostream>
using namespace std;

bool issorted(int arr[],int n){
    if(n==1){
        return true;
    }
    bool ans = issorted(arr+1,n-1);
    return (arr[0]<arr[1] && ans);
}

int main(){
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bool ans=issorted(arr,n);
    cout<<ans<<endl;
}