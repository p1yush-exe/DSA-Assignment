#include <iostream>

using namespace std;

void traverse(int arr[], int size)
{   
    cout<<"[";
    for(int i=0; i<size; ++i)
    {   
        cout<<" ("<<i<<":)"<<arr[i];
    }   
    cout<<" ]"<<endl;
}

void bubble_sort(int arr[], int size)
{
    int temp;
    for(int i=0; i<size-1;i++)
    {
        for(int j=0; j<size-i-1;j++)
        {   
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int remove_duplicates_3loop(int arr[], int& size)
{   

    return size;
}

int remove_duplicates_2loop(int arr[], int& size)
{   
    
    return size;
}

int remove_duplicates_(int arr[], int& size)
{   
    
    return size;
}

int remove_duplicates_(int arr[], int& size)
{   
    
    return size;
}

int main()
{
    int arr[20] = { -15, 0, 23, -7, 8, 42, -3, 19, 0, -21, 5, 17, -9, 0, 34, -2, 11, -8, 27, 0 };
    int size=sizeof(arr)/sizeof(arr[0]);

    cout<<"The array is: ";
    traverse(arr,size);
    cout<<endl;

    bubble_sort(arr,size);

    cout<<"The array is: ";
    traverse(arr,size);
    cout<<endl;

    remove_duplicates(arr,size);

    cout<<"The array is: ";
    traverse(arr,size);
    cout<<endl;


    return 0;
}