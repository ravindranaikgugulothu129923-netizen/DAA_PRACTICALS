#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace chrono;

int linearSearch(const vector<int>& a,int key){
    for(int i=0;i<a.size();i++) if(a[i]==key) return i;
    return -1;
}
int binarySearch(const vector<int>& a,int key){
    int low=0,high=a.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(a[mid]==key) return mid;
        if(a[mid]<key) low=mid+1; else high=mid-1;
    }
    return -1;
}
void display(const vector<int>& a){ for(int x:a) cout<<x<<" "; cout<<endl; }

int main(){
    int n; cout<<"Enter number of elements: "; cin>>n;
    vector<int>a(n); cout<<"Enter elements: "; for(int&x:a)cin>>x;
    int key; cout<<"Enter element to search: "; cin>>key;
    cout<<"\nOriginal Array: "; display(a);

    auto st=high_resolution_clock::now(); int p=linearSearch(a,key);
    auto en=high_resolution_clock::now();
    cout<<"\nLinear Search\n";
    if(p!=-1) cout<<"Element found at index "<<p<<endl; else cout<<"Element not found\n";
    cout<<"Time Taken: "<<duration_cast<microseconds>(en-st).count()<<" microseconds\n";

    vector<int>b=a; sort(b.begin(),b.end());
    cout<<"\nSorted Array for Binary Search: "; display(b);
    st=high_resolution_clock::now(); p=binarySearch(b,key); en=high_resolution_clock::now();
    cout<<"\nBinary Search\n";
    if(p!=-1) cout<<"Element found at index "<<p<<endl; else cout<<"Element not found\n";
    cout<<"Time Taken: "<<duration_cast<microseconds>(en-st).count()<<" microseconds\n";

    cout<<"\nGUGULOTHU RAVINDRA NAIK\n92400118332\n5-EN18\n";
    return 0;
}