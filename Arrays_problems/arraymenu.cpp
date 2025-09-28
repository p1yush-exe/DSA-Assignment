#include <iostream>
using namespace std;

namespace array{
    void traverse(int arr[], int size)
    {   
        cout<<"[";
        for(int i=0; i<size; ++i)
        {
            cout<<' '<<arr[i];
        }   
        cout<<" ]";
    }

    int min(int arr[], int size)
    {
        int min=arr[0];

        for(int i=1; i<size; ++i)
        {
            if(arr[i]<min)
            {   
                min=arr[i];
            }
        }

        return min;
    }

    int* insert(int* arr, int size, int insertion, int position)
    {
        for(int i=0, i<size; i++)
        {
            int position 
        }
    }  

    int* erase(int* arr, int size)
    {

    }
}


int main()
{
    int arr[7]= {54,0,-8,2,5,-32,99};
    int size= sizeof(arr)/sizeof(arr[0]);
    
    traverse(arr, size);
    cout << endl;

    min(arr, size);
    
    return 0;
}