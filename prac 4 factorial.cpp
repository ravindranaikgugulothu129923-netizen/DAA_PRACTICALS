#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

unsigned long long factorialIterative(int n){
    unsigned long long result=1;
    for(int i=1;i<=n;i++) result*=i;
    return result;
}
unsigned long long factorialRecursive(int n){
    if(n<=1)return 1;
    return n*factorialRecursive(n-1);
}

int main(){
    int n;
    cout<<"Enter a non-negative integer: ";cin>>n;
    if(n<0){cout<<"Invalid input!\n";return 1;}

    auto st=high_resolution_clock::now();
    auto r1=factorialIterative(n);
    auto en=high_resolution_clock::now();
    auto t1=duration<double,nano>(en-st).count();

    st=high_resolution_clock::now();
    auto r2=factorialRecursive(n);
    en=high_resolution_clock::now();
    auto t2=duration<double,nano>(en-st).count();

    cout<<"\n--- Results for "<<n<<"! ---\n";
    cout<<"Iterative Result : "<<r1<<endl;
    cout<<"Iterative Time : "<<t1<<" ns"<<endl;
    cout<<"------------------------------\n";
    cout<<"Recursive Result : "<<r2<<endl;
    cout<<"Recursive Time : "<<t2<<" ns"<<endl;

    cout<<"\nGUGULOTHU RAVINDRA NAIK\n92400118332\n5-EN18\n";
    return 0;
}