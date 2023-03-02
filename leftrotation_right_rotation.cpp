#include<iostream>
#include<vector>
using namespace std;

// code is correct multi threading has to learn

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
int roto;
cout<<"enter the array\n";
for(int i=0;i<7;i++){
cin>>arr[i];
}


cout<<"enter the pivorortoex\n";
cin>>roto;

// right rotation



rev(arr,0,6);
rev(arr,0,roto-1);
rev(arr,roto,6);

cout<<"right rotated array  array is\n";
printarray(arr,7);
cout<<"\n";

//left rotated array is;

rev(arr,0,roto-1);
rev(arr,roto,6);
rev(arr,0,6);


cout<<"left rotated array  array is\n";
printarray(arr,7);
cout<<"\n";


return 0;

}