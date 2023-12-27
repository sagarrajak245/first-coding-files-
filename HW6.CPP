#include<iostream>
using namespace std;

int main(){
    int i,j,n,t;

    cout<<"enter the row number\n";
    cin>>n;
    i=1;
    while(i<=n){
        j=1;t=n;
        while(j<=n){
            cout<<t;
            t--;
            j++;
        }
cout<<"\n";
i++;
    }
    return 0;
}