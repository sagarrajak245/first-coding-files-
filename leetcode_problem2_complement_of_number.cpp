#include<iostream>
#include<math.h>
using namespace std;


int main(){

int n,mask,m,ans; 
cout<<"enter the number\n";
cin>>n;
m=n;// ye m variable liya coz right shift ke time n ki value disturb ho jayegi but we have to use n later as its original form 
mask=0;
if(n==0){
    return 1;
}
while(m!=0){
 mask= mask<<1|1;    
m=m>>1;
}
ans=~n&mask;
cout<<ans;

    return 0;
}