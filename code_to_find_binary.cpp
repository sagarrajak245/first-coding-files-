#include<iostream>
#include<math.h>
using namespace std;
//code is right but tecnhnical error in compiler code  runs perfectly everywhere else
int main(){


int i,n,ans;

cout<<"enter the number\n";
cin>>n;
i=0;
ans=0;
while(n!=0){
    long long int bit= n & 1;
    ans=(bit*pow(10,i))+ans;
    n=n>>1;
    i++;

}

cout<<"the binary number of entered number is\n"<<ans;

    return 0;
}