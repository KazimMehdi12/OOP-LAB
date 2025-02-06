#include<iostream>
using namespace std;

int main() {
    int a, b, c;
    cout<<"Enter dimensions (a b c): ";
    cin>>a>>b>>c;

    int*** array = new int**[a];
    for(int i=0; i<a; i++) {
        array[i] = new int*[b];
        for(int j=0; j<b; j++) {
            array[i][j] = new int[c];
        }
    }

    cout<<"Enter Elements:"<<endl;
    for(int i=0; i<a; i++) {
        for(int j=0; j<b; j++) {
            for(int k=0; k<c; k++) {
                cout<<"Element ["<<i<<"]["<<j<<"]["<<k<<"]: ";
                cin>>array[i][j][k];
            }
        }
    }

    cout<<"\n3D Array:"<<endl;
    for(int i=0; i<a; i++) {
        for(int j=0; j<b; j++) {
            for(int k=0; k<c; k++) {
                cout<<array[i][j][k] << " ";
            }   cout<<endl;
        }
        cout<<endl;
    }

    for(int i=0; i<a; i++) {
        for(int j=0; j<b; j++) {
            delete[] array[i][j];
        }
        delete[] array[i];
    }
    delete[] array;
}
