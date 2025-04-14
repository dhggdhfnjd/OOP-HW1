#include<iostream>
using namespace std;
int main(){
int* p1,p2;
int a=0,b=0;
p1=&a;
p2=&b;
p1=p1+p2;
cout<<a<<endl;
}