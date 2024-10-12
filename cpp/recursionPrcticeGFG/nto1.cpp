#include<iostream>
using namespace std;
void to(int n ){
    if (n==0)
    {
        return;
    }
    cout<<n<<endl;
    to(n-1);
    
}
int main(){
    int n;
    cout<<"enter value of n"<<endl;
    cin>>n;
    to(n);
}