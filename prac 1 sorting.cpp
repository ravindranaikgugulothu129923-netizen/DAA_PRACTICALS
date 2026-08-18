#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace chrono;

void display(const vector<int>& a) {
    for (int x : a) cout << x << " ";
    cout << endl;
}

void bubbleSort(vector<int>& a) {
    int n = a.size();
    for (int i=0;i<n-1;i++)
        for (int j=0;j<n-i-1;j++)
            if (a[j] > a[j+1]) swap(a[j],a[j+1]);
}

void selectionSort(vector<int>& a) {
    int n=a.size();
    for(int i=0;i<n-1;i++){
        int m=i;
        for(int j=i+1;j<n;j++)
            if(a[j]<a[m]) m=j;
        swap(a[i],a[m]);
    }
}

void insertionSort(vector<int>& a) {
    for(int i=1;i<a.size();i++){
        int key=a[i], j=i-1;
        while(j>=0 && a[j]>key){ a[j+1]=a[j]; j--; }
        a[j+1]=key;
    }
}

void mergeArray(vector<int>& a,int l,int m,int r){
    vector<int>L(a.begin()+l,a.begin()+m+1), R(a.begin()+m+1,a.begin()+r+1);
    int i=0,j=0,k=l;
    while(i<L.size() && j<R.size()) a[k++]=(L[i]<=R[j]?L[i++]:R[j++]);
    while(i<L.size()) a[k++]=L[i++];
    while(j<R.size()) a[k++]=R[j++];
}
void mergeSort(vector<int>& a,int l,int r){
    if(l<r){ int m=l+(r-l)/2; mergeSort(a,l,m); mergeSort(a,m+1,r); mergeArray(a,l,m,r); }
}
int partitionArray(vector<int>& a,int l,int h){
    int p=a[h],i=l-1;
    for(int j=l;j<h;j++) if(a[j]<p) swap(a[++i],a[j]);
    swap(a[i+1],a[h]); return i+1;
}
void quickSort(vector<int>& a,int l,int h){
    if(l<h){ int p=partitionArray(a,l,h); quickSort(a,l,p-1); quickSort(a,p+1,h); }
}

int main(){
    int n; cout<<"Enter number of elements: "; cin>>n;
    vector<int> original(n);
    cout<<"Enter elements: "; for(int& x:original) cin>>x;
    cout<<"\nOriginal Array: "; display(original);

    vector<pair<string, void(*)(vector<int>&)>> sorts = {
        {"Bubble Sort", bubbleSort}, {"Selection Sort", selectionSort},
        {"Insertion Sort", insertionSort}
    };
    for(auto &s:sorts){
        auto a=original; auto st=high_resolution_clock::now(); s.second(a);
        auto en=high_resolution_clock::now();
        cout<<"\n"<<s.first<<": "; display(a);
        cout<<"Time: "<<duration_cast<microseconds>(en-st).count()<<" microseconds\n";
    }
    auto a=original; auto st=high_resolution_clock::now(); mergeSort(a,0,n-1); auto en=high_resolution_clock::now();
    cout<<"\nMerge Sort: "; display(a);
    cout<<"Time: "<<duration_cast<microseconds>(en-st).count()<<" microseconds\n";
    a=original; st=high_resolution_clock::now(); quickSort(a,0,n-1); en=high_resolution_clock::now();
    cout<<"\nQuick Sort: "; display(a);
    cout<<"Time: "<<duration_cast<microseconds>(en-st).count()<<" microseconds\n";

    cout<<"\nGUGULOTHU RAVINDRA NAIK\n92400118332\n5-EN18\n";
    return 0;
}