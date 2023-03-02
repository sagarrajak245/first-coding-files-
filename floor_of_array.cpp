#include<iostream>
using namespace std;

int floor(int arr[],int size,int key){

int start=0;
int end=size-1;
int mid=start+(end-start)/2;
while(start<end){

if(arr[mid]>arr[mid+1]){
    start=mid+1;
}


else{
    end=mid;
}
 mid=start+(end-start)/2;
}
return end;   //when while loop breaks it returns the value less than or equAL to floor that is our index of end 

}

int main(){
int arr[5];
int key;
cout<<"enter the array\n";
for(int i=0;i<5;i++){
cin>>arr[i];
}



int search = floor(arr,5,key);
cout<<"the floor index of array is\n"<<search;

return 0;
}