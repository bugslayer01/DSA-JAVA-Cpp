#include<bits/stdc++.h>
using namespace std;
bool checkPower2(int);
int main(){
    int n;
    cin>>n;
    // cout<<"hi;";
    cout<< checkPower2(n);
}
bool checkPower2(int x){
    // return(!(x&(~x)));   thsi is wrong 
    return(!(x&(x-1)));
}