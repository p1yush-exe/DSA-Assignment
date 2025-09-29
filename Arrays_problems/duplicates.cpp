#include <iostream>

using namespace std;

void traverse(int arr[], int size)
{   
    cout<<"[";
    for(int i=0; i<size; ++i)
    {   
        cout<<" "<<arr[i];
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

void remove_duplicates_track(int arr[], int& size)
{
    if(size == 0) return;
    int count = 1;
    for(int i = 1; i < size; ++i)
        if(arr[i] != arr[count-1])
            arr[count++] = arr[i];
    size = count;
}

int main()
{
    int arr[22] = { 209,-15, -15, 0, -2, 8, 42, -3, 19, 209, -21, 5, 17, 0, 17, 0, -2, 11, -8, 27, 0,-99 };
    int size=sizeof(arr)/sizeof(arr[0]);

    cout<<"The array is: ";
    traverse(arr,size);
    cout<<endl;

    bubble_sort(arr,size);

    cout<<"The array after sorting is: ";
    traverse(arr,size);
    cout<<endl;

    remove_duplicates_track(arr,size);

    cout<<"The array after tracking duplicate removal is: ";
    traverse(arr,size);
    cout<<endl;


    return 0;
}