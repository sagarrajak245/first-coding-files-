 // code correct hai compiler me problem aa rahi hai online compiler me perfect run kar raha hai..
#include<iostream>
using namespace std;

int binarysearch(int arr[],int size,int key){

int start=0;
int end=size-1;
int mid=start+(end-start)/2;
while(start<end){

if(arr[mid]==key){
    return mid;
}
else if(key>arr[mid]){      
    start=mid+1;
}
else{
    end=mid-1;
}
 mid=start+(end-start)/2;
}
return -1;

}

int main(){
int arr[5];
int key;
cout<<"enter the array\n";
for(int i=0;i<5;i++){
cin>>arr[i];
}

cout<<"enter the key u want \n";
cin>>key;

int search =binarysearch(arr,5,key);
cout<<"the index of key elemnt is\n"<<search;

return 0;
}