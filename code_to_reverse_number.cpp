#include<iostream>
#include<math.h>
using namespace std;

int main(){

int i,n,ans;

cout<<"enter the number\n";
cin>>n;
ans=0;
while(n!=0){
    int digit=n%10;
    
    ans=ans*10+digit;
    n=n/10;
    
}
cout<<"the reverse of entered number is\n"<<ans;

    return 0;
}