#include<iostream>
#include<math.h>
using namespace std;
//codition given is that if int exceeds max value 2^31-1 or min value -2^31  then return 0

int main(){

int i,ans;
int n; 
cout<<"enter the number\n";
cin>>n;
ans=0;
while(n!=0){
    int digit=n%10;
    
    ans=ans*10+digit;
    n=n/10;
    

if(ans>INT32_MAX/10 || ans<INT32_MIN /10){
  return 0;} 

}
cout<<"the reverse of entered number is\n"<<ans;

    return 0;
}