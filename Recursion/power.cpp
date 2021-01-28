#include<iostream>
using namespace std;

int powerusingrecursion(int base,int power){

    if(power==0){
        return 1;
    }
    int ans=powerusingrecursion(base,power-1);
    return base*ans;

}

int main(){
    int base;
    int power;
    cin>>base>>power;
    int ans=powerusingrecursion(base,power);
    cout<<ans<<endl;

}