#include<iostream>
using namespace std;

int main(){

int n,sum;
cout<<"enter ur number\n";
cin>>n;
sum=0;
for(int i=1;i<=n;i++){

    cout<<i<<" "<<"\n";

    //sum=sum+i;
    sum+=i;
}
cout<<"the sum of series is\n"<<sum;



    return 0;
}