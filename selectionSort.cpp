#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){

    int n;
    cin>>n;


    int arr[n];

    for(int i=0;i<n;i++) cin>>arr[i];

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                swap(arr[i],arr[j]);
            }
        }
    }

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";



    return 0;
}