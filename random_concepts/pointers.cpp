#include<iostream>
using namespace std;

// function prototype for pointer function, need to declare variables
int func(int *x, int*y);

// structure with pointers

struct X {
    int x;
    int y;
};

int main(int argc, char *argv[])
{
    X *ptr = new X;
    ptr->x = 10;
    ptr->y = 5;
    cout<<ptr->x<<" "<<ptr->y<<endl;

    delete ptr;

    // 1D Dynamic array
    int *arr1 = new int [5];

    for(int i = 0; i<5; i++)
    {
        arr1[i] = i+1;
        *(arr1+i) = i+1;
    }

    for (int i = 0; i < 5; ++i) {
        cout<<arr1[i]<<" ";
    }
    cout<<endl;


    delete[] arr1;



    // 2D dynamic array
    int ** arr2 = new int * [3]; // pointer to the array of pointers
    for(int i = 0; i<3; i++)
    {
        int *a = new int [3];
        arr2[i] = a;
    }

    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin>>arr2[i][j];
        }
    }

    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout<<arr2[i][j]<<" ";
        }
        cout<<endl;
    }

    delete [] arr2;

}