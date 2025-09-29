#include <iostream>
#include <algorithm>
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


void binary_insertion_sort(int arr[], int size)
{
    for(int i = 1; i < size; i++)
    {
        int element = arr[i];
        int low = 0, high = i - 1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(arr[mid] <= element)
                low = mid + 1;
            else
                high = mid - 1;
        }

        for(int j = i; j > low; --j)
            arr[j] = arr[j - 1];

        arr[low] = element;
    }
}


void remove_duplicates(int arr[], int& size)
{
    if(size == 0) return;
    int count = 1;
    for(int i = 1; i < size; ++i)
        if(arr[i] != arr[i-1])
            arr[count++] = arr[i];
    size = count;
}

void clean_array(int arr[],int size)
{
    binary_insertion_sort(arr,size);
    remove_duplicates(arr,size);
}

void intersection(int arr1[],int size1,int arr2[],int size2)
{
    clean_array(arr1,size1);
    clean_array(arr2,size2);

    int intsize=max(size1,size2),p=0;
    int intarr[intsize];

    for(int i=0,j=0;i<size1 && j<size2;)
    {   
        if(arr1[i]==arr2[j])
        {
            intarr[p]=arr1[i];
            p++,i++,j++;
        }
        else if(arr1[i]<arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }        
    }

    cout<<"The intersection of both arrays is: ";
    cout<<"[";
    for(int i=0;i<p;i++)
    {
        cout<<" "<<intarr[i];
    }
    cout<<" ]"<<endl;

}

int main()
{
    int arr1[] = {1, 2, 2, 3, 4, 5,69,708,708,708};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {2, 3, 5, 7, 8,60,67,67,67,67,67,67,69};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    intersection(arr1, size1, arr2, size2);

    return 0;
    
}