#include <iostream>
using namespace std;
int main (){
int a;
cout<<"enter the number\n";
cin>>a;

if(a%2 !=0 && a%a==0)
{
 cout<<"number is prime";
}
else{
    cout<<"number is not prime";
}
    return 0; 
}