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

void selection_sort(int arr[], int size)
{
    int temp, min;
    for(int i=0; i<size-1;i++)
    {   
        min=i;

        for(int j=i+1; j<size;j++)
        {   
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }

        if(min!=i)
        {
            temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }

    }
}

void improved_selection_sort(int arr[], int size)
{   
    int temp, min = 0, max = 0;
    for (int i = 0, k = size - 1; i < size / 2; i++, k--)
    {   
        min = i;
        max = i;

        for (int j = i; j <= k; j++)
        {       
            if (arr[j] < arr[min])
            {   
                min = j;
            }
            
            if (arr[j] > arr[max])
            {       
                max = j;
            }
        }

        if (min != i)
        {   
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
            if (max == i) max = min;
        }

        if (max != k)
        {   
            temp = arr[k];
            arr[k] = arr[max];
            arr[max] = temp;
        }
    }
}

void insertion_sort(int arr[], int size)
{   
    int temp=0,j=0;
    for(int i=1; i<size;i++)
    {
        temp=arr[i];
        j=i;
        for(; j>0 && arr[j-1]>temp;j--)
        {   
            arr[j]=arr[j-1];
        }
        arr[j]=temp;
    }
}

void binary_insertion_sort(int arr[], int size);

void remove_duplicates(int arr[], int size)
{
    
}

void clean_array(int arr[],int size)
{
    bubble_sort(arr,size);
    remove_duplicates(arr,size);
}

int binary_search_iter(int arr[],int size, int element)
{   
    int high=size-1,low=0;
    while(low<=high)
    {
        int middle= low+(high-low)/2;
        if(arr[middle]==element)
        {   
            return middle;
        }
        else if (element > arr[middle])
        {
            low=middle+1;
        }
        else
        {
            high=middle-1;
        }
    }
    return -1;
}

int binary_search_recur(int arr[],int size, int low, int high, int element)
{   
    if(low>high)
    {   
        return -1;
    }

    int middle= low+(high-low)/2;
    
    if(arr[middle]==element)
    {   
        return middle;
    }
    else if (element > arr[middle])
    {
        return binary_search_recur(arr, size, middle+1, high, element);
    }
    else
    {
        return binary_search_recur(arr, size, low, middle-1, element);
    }
    
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

int main()
{
    int arr[22] = { 209, -15, 0, 23, -7, 8, 42, -3, 19, 0, -21, 5, 17, -9, 0, 34, -2, 11, -8, 27, 0,-99 };
    int size=sizeof(arr)/sizeof(arr[0]);

    cout<<"The array is: ";
    traverse(arr,size);
    cout<<endl;

    bubble_sort(arr,size);

    cout<<"The array sorted with bubble sort: ";
    traverse(arr,size);
    cout<<endl;

    int arr1[22] = { 209, -15, 0, 23, -7, 8, 42, -3, 19, 0, -21, 5, 17, -9, 0, 34, -2, 11, -8, 27, 0,-99 };

    selection_sort(arr1,size);

    cout<<"The array sorted with selection sort: ";
    traverse(arr1,size);
    cout<<endl;

    int arr2[22] = { 209, -15, 0, 23, -7, 8, 42, -3, 19, 0, -21, 5, 17, -9, 0, 34, -2, 11, -8, 27, 0,-99 };

    improved_selection_sort(arr2,size);

    cout<<"The array sorted with improved selection sort: ";
    traverse(arr2,size);
    cout<<endl;

    int arr3[22] = { 209, -15, 0, 23, -7, 8, 42, -3, 19, 0, -21, 5, 17, -9, 0, 34, -2, 11, -8, 27, 0,-99 };

    insertion_sort(arr3,size);

    cout<<"The array sorted with insertion sort: ";
    traverse(arr3,size);
    cout<<endl;

    int arr4[22] = { 209, -15, 0, 23, -7, 8, 42, -3, 19, 0, -21, 5, 17, -9, 0, 34, -2, 11, -8, 27, 0,-99 };

    binary_insertion_sort(arr4,size);

    cout<<"The array sorted with binary insertion sort: ";
    traverse(arr4,size);
    cout<<endl;


    int el=0;
    cout<<"Enter the element you want to search: ";
    cin>>el;

    int result1 = binary_search_iter(arr, size, el);
    int result2 = binary_search_recur(arr, size, 0, size-1, el);

    if(result1 != -1)
        cout << "Element found at index " << result1 << " (iterative)" << endl;
    else
        cout << "Element not found (iterative)" << endl;
        
    if(result2 != -1)
        cout << "Element found at index " << result2 << " (recursive)" << endl;
    else
        cout << "Element not found (recursive)" << endl;

    return 0;
}