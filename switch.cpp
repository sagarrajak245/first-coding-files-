#include<iostream>
#include<math.h>
using namespace std;
int main(){

int amount, rupee_notes;
cout<<"enter the amount\n";
cin>>amount;
cout<<"enter the notes\n";
cin>>rupee_notes;
switch(rupee_notes){

    case 100:{ cout<<"100 rupees notes will be\n"<<amount/100; }
    cout<<"\n";

    case 50:{ cout<<"50 rupees notes will be\n"<<amount/50; }
     cout<<"\n";

    case 20:{ cout<<"20 rupees notes will be\n"<<amount/20; }
     cout<<"\n";

    case 10:{ cout<<"10 rupees notes will be\n"<<amount/10; }
    
default:{cout<<"enter the valid notes";}
     
}

    return 0;
}