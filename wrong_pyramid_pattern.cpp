#include<iostream>
using namespace std;

int main(){
    int i,j,n,space,t,p;

    cout<<"enter the row number\n";
    cin>>n;
    i=1;
    while(i<=n){

space=1;
while(space<=n-i){
cout<<" ";
space++;
}
        j=1; 
        while(j<=i){
            cout<<j;
            j++;
        }
t=1;p=i;
while(t<=i){
cout<<p;
p--;
t++;
}



cout<<"\n";
i++;
    }
    return 0;
}