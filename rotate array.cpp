#include<iostream>
#include<vector>
using namespace std;

void rev(int arr[],int start,int end){
while(start<end){
swap(arr[start],arr[end]);
start++;
end--;
}
}


void printarray(int arr[],int size){

 for(int i=0;i<size;i++){

cout <<arr[i]<<" ";
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


rev(arr,7,k);

cout<<"reverse  array is\n";
printarray(arr,7);
cout<<"\n";





return 0;

}










