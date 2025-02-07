#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter Number of Elements: ";
    cin>>n;

    int* arr = new int[n];
    cout<<"Enter "<<n<<" Elements: \n";
       for(int i=0; i<n; i++) {
       	  cout<<"Enter Element "<<i+1<<" ";
          cin>>*(arr+i);
    }

    cout<<"Elements Of Array: ";
       for(int i=0; i<n; i++) {
          cout<<*(arr+i)<<" ";
    }     cout<<endl;

    int sum = 0;
    int* ptr = arr;
    for(int i=0; i<n; i++) {
         sum += *(ptr + i);
    }

    cout<<"THE SUM IS: "<<sum<<endl;
    delete[] arr;
}
