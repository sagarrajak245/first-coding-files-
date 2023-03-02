 
#include<iostream>
using namespace std;

void alternate_reverse(int arr[],int size,int k){

for(int i=0;i<size;i+=2){
if(i+1<size){
swap(arr[i],arr[i+k]);
}
}
}



void printarray(int arr[],int size){

 for(int i=0;i<size;i++){

cout<<arr[i]<<" ";
 } 
}

int main(){
int arr[7];
int k;
cout<<"enter the array\n";
for(int i=0;i<7;i++){
cin>>arr[i];
}


cout<<"enter the key\n";
cin>>k;


alternate_reverse(arr,7,k);

cout<<"reverse alternate array is\n";
printarray(arr,7);
cout<<"\n";

return 0;
}