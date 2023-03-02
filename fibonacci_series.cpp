#include<iostream>
using namespace std;
// fibonacci series using for loop;
int main(){

int n,b,a,sum,i;
cout<<"enter the number\n";
cin>>n;
a=0,b=1;
cout<<a+b<<" ";
for(i=1;i<=n;i++){
sum=a+b;
a=b;
b=sum;
cout<<a+b<<" ";
}

    return 0; 
}