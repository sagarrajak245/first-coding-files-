#include<iostream>
#include<math.h>
using namespace std;
// use of combination and factorial with function
int fact(int a){

int fact=1;
for(int i=1;i<=a;i++){
fact=fact*i;
}
return fact;
}


int combination(int a,int b){

int ans;

ans= fact(a)/(fact(b)*fact(a-b));

return ans;

}



int main(){

int c,d;
cout<<"enter the parameters\n";
cin>>c>>d;

//int b=fact(c);
//cout<<"the value of\n"<<b;

int s=combination(c,d);
cout<<"the value of combination is\n"<<s;
    return 0;
}