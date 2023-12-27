#include <iostream>
using namespace std;
int main (){

int i,j,n,number;
cout<<"enter the number\n";
cin>>n;

i=1;
while(i<=n){

    j=1; number=i;
    while(j<=i){
        cout<<number<<" ";
        number++;
j=j+1;
    }
   
cout<<"\n";

i=i+1;

}

    

    return 0; 
}