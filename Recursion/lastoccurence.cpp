#include<iostream>
using namespace std;

int firstoccurence(int arr[],int n,int x,int i){
    if(i==n){
        return -1;
    }
    if(arr[i]==x){
        return i;
    }
    return firstoccurence(arr,n,x,i+1);

}

int lastoccurence(int arr[],int n,int x,int i){
    if(i==n){
        return -1;
    }
    int restarray=lastoccurence(arr,n,x,i+1);
    if(restarray!=-1){
        return restarray;
    }
    else{
        if(arr[i]==x){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=lastoccurence(arr,n,2,0);
    cout<<ans<<endl;
}