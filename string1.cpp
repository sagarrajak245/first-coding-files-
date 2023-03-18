#include<iostream>
#include<algorithm>
#include<string.h>
 #include<bits/stdc++.h>
using namespace std;



char uppercase(char ch){
    char temp;
if(ch>='A'&& ch<='Z'){return ch;}
else{
     temp=ch-'a'+'A';
}

return temp;
}

char lowercase(char ch){
    char temp;
if(ch>='a'&& ch<='z'){return ch;}
else{
     temp=ch-'A'+'a';
}

return temp;
}




int getlength(char arr[],int size){
int i;
int count=0;
for(i=0; i<size;i++){

    if(arr[i]!=0){
        count++;
    }

}

return count;
}


void printarray(char arr[],int size){

 for(int i=0;i<size;i++){

cout <<arr[i]<<" ";
 }

}

bool check_pallindrome(char arr[],int size){
    //to terminate the case sensitivity convert them into completly in upper case or lower case
//hence we used lower case function
    int start=0;
    int end=size-1;
    while(start<=end){

if(lowercase(arr[start])!=lowercase(arr[end])){return 0;}
else{start++;
end--;}
}
return 1;}
 
    

 
int main(){


    // string variable declaration
    string str; 
    
    cout << "Enter the string as an input:";

    getline(cin, str); // implementing a getline() function 
    // The user input will be stored in the str variable 

    cout << "The entered string was:" << endl;
     
    cout << str << endl; 
 
cout << "length of string is" <<endl<<str.length()<<endl;

char arr[5];
char ch;
char mh;
cout<<"enter the element in array\n";
for(int i=0;i<5;i++){
cin>>arr[i];
}
cout<<"enter the character for lower case\n";
cin >>ch;
cout<<"\n";
cout<<"enter the character for upper case\n";
cin >>mh;

printarray(arr,5);
cout<<"\n";
cout<<"the length of string is\n"<<getlength(arr,5);
cout<<"\n";
cout<<"It is pallindrome or not\n"<<check_pallindrome(arr,5);
cout<<"\n";
cout<<"the lower case is\n"<<lowercase(ch);
cout<<"\n";
cout<<"the upper case is\n"<<uppercase(mh);



return 0;
}