#include<iostream>
#include<math.h>
using namespace std;
int main(){

int n;

cout<<"enter number\n";
cin>>n;

cout<<"your power representation of number is\n";
for(int i=1; i<=n; i++){

int ans = pow(n,i);
cout<<ans<<" ";

}
    return 0;
}