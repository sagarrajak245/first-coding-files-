#include<iostream>
#include<algorithm>
using namespace std;
// it is unstable algorithm
// it is inplace algorithm

void selection_short(int arr[],int size){
for(int i=0;i<size-1;i++){
int minindex=i;

for(int j=i+1;j<size;j++){

if(arr[j]<arr[minindex]){
    minindex=j;
}

}
swap(arr[minindex],arr[i]);

}

}

void printarray(int arr[],int size){

 for(int i=0;i<size;i++){

cout<<arr[i]<<" ";
 } 
}
int main(){

int arr[5];

cout<<"enter the array\n";
for(int i=0;i<5;i++){
cin>>arr[i];
}

selection_short(arr,5);

cout<<"selection short applied array is\n";
printarray(arr,5);

return 0;

}