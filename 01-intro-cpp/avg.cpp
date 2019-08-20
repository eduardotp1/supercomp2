#include <iostream>
using namespace std;

int main(){

int n;
double b;
double sum=0;
double avg;

cin>>n;

for(int i=0;i<n;i++){
cin>>b;
sum+=b;
}
avg=sum/n;
cout<<avg;
}