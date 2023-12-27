#include<iostream>
using namespace std;

int main(){
    int i,j,n,space,t;

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

t=i-1;
while(t){
    cout<<t;
    t--;
}
cout<<"\n";
i++;
}


    
    return 0;
}