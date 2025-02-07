#include<iostream>
using namespace std;

int main(){
    int size;

    cout<<"Enter Size Of Array: ";
    cin>>size;

    int* array = new int[size];

    for(int i=0; i<size; ++i) {
    	cout<<"Enter Element "<<i+1<<": ";
        cin>>array[i];
    }
    cout<<"Elements Of Array:" << endl;
    for(int i=0; i<size; ++i) {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    
    delete[] array;
}
