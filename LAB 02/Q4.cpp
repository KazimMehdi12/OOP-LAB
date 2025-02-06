#include<iostream>
#include<string>
using namespace std;

void Sorting(string* arr, int n) {
    for(int i=0 ; i<(n-1) ; i++) {
        for (int j=i+1 ; j<n ; j++) {
            if(arr[i] > arr[j]) {
               string temp = arr[i];
               arr[i] = arr[j];
               arr[j] = temp;
            }
       }
   }
}

int main() {
    int n;
    cout<<"Enter the number of strings: ";
    cin>>n;

    string* words = new string[n];
    for(int i=0; i<n; i++){
        cout<<"Enter string: "<<i+1<<": ";
        cin>>words[i];
    }
    
    Sorting(words, n);
    
    cout<<"\nSorted Strings: "<<endl;
    for(int i=0; i<n; i++){
        cout<<words[i]<<endl;
    }

    delete[] words;
}
