 
#include<iostream>
using namespace std;


int main(){
int row,i,j,space;
cout<<"enter the row number\n";
cin>>row;
for(i=1;i<=row;i++){
for(j=1;j<i;j++){
    cout<<" ";
}
for(j=1;j<row-i+1;j++){
    cout<<j+i-1;

}
cout<<"\n";
}


}