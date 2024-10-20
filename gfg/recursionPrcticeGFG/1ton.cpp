#include<iostream>
using namespace std;
void to(int n,int i ){
    cout<<i<<endl;
    if (i==n)
    {
        return;
    }
    to(n,++i);
    
}
int main(){
    int n;
    cout<<"enter value of n"<<endl;
    cin>>n;
    to(n,1);
}