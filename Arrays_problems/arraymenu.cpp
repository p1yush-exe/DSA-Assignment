// Developa Menu driven program to demonstrate the following operations of Arrays
// ——MENU——-
// 1.CREATE
// 2.DISPLAY
// 3.INSERT
// 4.DELETE
// 5.LINEAR SEARCH
// 6.EXIT

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

int max(int arr[], int size)
{
    int max=arr[0];
    for(int i=1; i<size; ++i)
    {
        if(arr[i]>max)
        {   
            max=arr[i];
        }
    }
    return max;
}

// int* insert(int* arr, int size, int insertion, int position)
// {   
//     int newarr[size+1];
//     for(int i=size; i>position; --i)
//     {
//         newarr[i]=arr[i-1];
//     }
//     newarr[position]=insertion;
//     for(int i=position-1; i>0; ++i)
//     {
//         newarr[i]=newarr[i-1];
//     }
//     return newarr;
// }  

// int* erase(int* arr, int size, int position)
// {
//     int newarr[size];
//     for(int i=position; i>position; --i)
//     {
//         newarr[i-1]=newarr[i];
//     }
//     return newarr;
// }



int main()
{
    char answer = 'y';
    int arr[100];
    int size = 0;
    bool arrayExists = false;

    while (answer == 'y')
    {
        cout << "——MENU——-" << endl;
        cout << "1.CREATE" << endl;
        cout << "2.DISPLAY" << endl;
        cout << "3.INSERT" << endl;
        cout << "4.DELETE" << endl;
        cout << "5.LINEAR SEARCH" << endl;
        cout << "6.EXIT" << endl;

        int option;
        cin >> option;

        switch (option)
        {
        case 1:
            // if (arrayExists)
            // {
            //     char confirm;
            //     cout << "Array already exists. Do you want to overwrite and delete previous array? (y/n): ";
            //     cin >> confirm;
            //     if (confirm != 'y')
            //     {
            //         cout << "Array creation cancelled." << endl;
            //         break;
            //     }
            // }
            // cout << "Enter number of elements: ";
            // cin >> size;
            // cout << "Enter " << size << " elements: ";
            // for (int i = 0; i < size; ++i)
            // {
            //     cin >> arr[i];
            // }
            // arrayExists = true;
            // cout << "Array created successfully." << endl;
            break;

        case 2:
            /* code */
            break;

        case 3:
            /* code */
            break;

        case 4:
            /* code */
            break;

        case 5:
            /* code */
            break;

        case 6:
            cout << "Enter n to exit: ";
            cin >> answer;
            break;

        default:
            cout << "Enter a valid option";
            break;
        }
    }

    cout << "The array looks like: ";
    traverse(arr, size);
    cout << endl;

    cout << "The smallest element in the array is: " << min(arr, size) << endl;
    cout << "The largest element in the array is: " << max(arr, size) << endl;

    return 0;
}