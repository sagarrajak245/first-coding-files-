 
#include<iostream>
using namespace std;


int main(){
int row,i,j,space;
cout<<"enter the row number\n";
cin>>row;

i=1;
while(i<=row){

space=1;
while(space<i){

cout<<" ";
space++;
}

j=1;
while(j<=row+i-1){

    cout<<j<<" ";
    j++;
}
cout<<"\n";
i++;
}


return 0;
}