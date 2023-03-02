#include <iostream>
using namespace std;
int main (){

int n;
cout<<"enter the number\n";
cin>>n;

if(n&(n-1)!=0){
    cout<<"entered number is not of power of 2";
}
   else {cout<<"it is power of 2";}

    return 0; 
}