#include<iostream>
#include<algorithm>
using namespace std;
// it is unstable algorithm
// it is inplace algorithm

void bubble_short(int arr[],int size){
for(int i=1;i<size;i++){


for(int j=0;j<size-i;j++){

if(arr[j]>arr[j+1]){
    swap(arr[j],arr[j+1]);
}

}
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

bubble_short(arr,5);

cout<<"bubble short applied array is\n";
printarray(arr,5);

return 0;

}