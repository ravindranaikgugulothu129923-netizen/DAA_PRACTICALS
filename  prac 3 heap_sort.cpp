#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace chrono;

void maxHeapify(vector<int>&a,int n,int i){
    int largest=i,l=2*i+1,r=2*i+2;
    if(l<n&&a[l]>a[largest])largest=l;
    if(r<n&&a[r]>a[largest])largest=r;
    if(largest!=i){swap(a[i],a[largest]);maxHeapify(a,n,largest);}
}
void maxHeapSort(vector<int>&a){
    for(int i=a.size()/2-1;i>=0;i--)maxHeapify(a,a.size(),i);
    for(int i=a.size()-1;i>0;i--){swap(a[0],a[i]);maxHeapify(a,i,0);}
}
void minHeapify(vector<int>&a,int n,int i){
    int small=i,l=2*i+1,r=2*i+2;
    if(l<n&&a[l]<a[small])small=l;
    if(r<n&&a[r]<a[small])small=r;
    if(small!=i){swap(a[i],a[small]);minHeapify(a,n,small);}
}
void minHeapSort(vector<int>&a){
    for(int i=a.size()/2-1;i>=0;i--)minHeapify(a,a.size(),i);
    for(int i=a.size()-1;i>0;i--){swap(a[0],a[i]);minHeapify(a,i,0);}
    reverse(a.begin(),a.end());
}
void display(const vector<int>&a){for(int x:a)cout<<x<<" ";cout<<endl;}

int main(){
    int n;cout<<"Enter number of elements: ";cin>>n;
    vector<int>a(n);cout<<"Enter elements: ";for(int&x:a)cin>>x;
    vector<int>mx=a,mn=a;
    auto st=high_resolution_clock::now();maxHeapSort(mx);auto en=high_resolution_clock::now();
    auto tmax=duration_cast<nanoseconds>(en-st).count();
    st=high_resolution_clock::now();minHeapSort(mn);en=high_resolution_clock::now();
    auto tmin=duration_cast<nanoseconds>(en-st).count();

    cout<<"\nOriginal Array: ";display(a);
    cout<<"\n========== MAX HEAP SORT ==========\n";
    cout<<"Sorted Array: ";display(mx);cout<<"Time: "<<tmax<<" ns\n";
    cout<<"\n========== MIN HEAP SORT ==========\n";
    cout<<"Sorted Array: ";display(mn);cout<<"Time: "<<tmin<<" ns\n";
    cout<<"\nGUGULOTHU RAVINDRA NAIK\n92400118332\n5-EN18\n";
    return 0;
}