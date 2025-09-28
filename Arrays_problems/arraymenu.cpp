// Develop a Menu driven program to demonstrate the following operations of Arrays
// ——MENU——-
// 1.CREATE
// 2.DISPLAY
// 3.INSERT
// 4.DELETE
// 5.LINEAR SEARCH
// 6.EXIT

#include <iostream>
#include <cstring>
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

int linear_search(int arr[], int size, int element)
{   
    for(int i=0; i<size; ++i)
    {
        if(arr[i]==element)
        {   
            return i;        
        }
    }

    return -1;
}

void insert(int arr[], int &size, int insertion, int position)
{   
    if (position < 0 || position >= size) {
        cout << "Invalid position. Position should be between 0 and " << (size-1) << endl;
        return;
    }

    size++;

    for(int i=size; i>position; --i)
    {
        arr[i]=arr[i-1];
    }

    arr[position]=insertion;
    cout<<"Insertion successful"<<endl;  
}  

void erase(int arr[], int &size, int position)
{   
    if (position < 0 || position >= size) {
        cout << "Invalid position. Position should be between 0 and " << (size-1) << endl;
        return;
    }
    
    size--;

    for(int i=position; i<size; ++i)
    {
        arr[i]=arr[i+1];
    }
    cout<<"Deletion successful"<<endl;  
}  

int main()
{
    char answer = 'y';
    int arr[100];
    int size = 10,el=0,pos=0;
    bool arrayExists = true;

    for(int i=0; i<size; ++i)
    {
        arr[i]= 5*(i*i*i) - 12*(i*i) + 4*i + 9;
    }

    while (answer == 'y')
    {
        cout << "---MENU---" << endl;
        cout << "1.CREATE" << endl;
        cout << "2.DISPLAY" << endl;
        cout << "3.INSERT" << endl;
        cout << "4.DELETE" << endl;
        cout << "5.LINEAR SEARCH" << endl;
        cout << "6.MAXIMUM ELEMENT" << endl;
        cout << "7.MINIMUM ELEMENT" << endl;
        cout << "8.EXIT" << endl;

        int option;
        cin >> option;

        switch (option)
        {
        case 1:
            cout<<endl;
            if (arrayExists)
            {
            char confirm;
            cout << "Array already exists. Do you want to overwrite and delete previous array? (y/n): ";
            cin >> confirm;
            if (confirm == 'n')
            {
                cout << "Array creation cancelled." << endl;
                break;
            }
            cout << "Overwriting previous array..." << endl;
            }

            cout << "Enter number of elements: ";
            cin >> size;
            cout << "Enter " << size << " elements: ";

            for (int i = 0; i < size; ++i)
            {
                cin >> arr[i];
            }

            arrayExists = true;
            cout << "Array created successfully." << endl;

            cout<<endl;

            break;

        case 2:
            cout<<endl;
            if (!arrayExists) 
            {
                cout << "No array exists. Please create an array first." << endl;
                break;
            }

            cout<<"The current array is: ";
            traverse(arr,size);

            cout<<endl;

            break;

        case 3:
            cout<<endl;
            if (!arrayExists) 
            {
                cout << "No array exists. Please create an array first." << endl;
                break;
            }

            cout<<"Enter the element that you want to insert: ";
            cin>>el;

            cout<<"Enter the position where you want to insert it: ";
            cin>>pos;

            insert(arr,size,el,pos);

            el=0,pos=0;

            cout<<endl;

            break;

        case 4:
            cout<<endl;
            if (!arrayExists) 
            {
                cout << "No array exists. Please create an array first." << endl;
                break;
            }

            cout<<"Enter the position where you want to delete an element from: ";
            cin>>pos;

            erase(arr,size,pos);

            pos=0;

            cout<<"Deletion successful"<<endl;
            cout<<endl;

            break;

        case 5:
            cout<<endl;
            if (!arrayExists) 
            {
                cout << "No array exists. Please create an array first." << endl;

                break;
            }

            cout<<"Enter which element you want to find: ";
            cin>>el;

            pos=linear_search(arr,size,el);

            if(pos!=-1)
            {
                cout<<"element found at index "<<pos<<endl;
            }
            else
            {
                cout<<"element not found"<<endl;
            }

            pos=0,el=0;
            cout<<endl;

            break;

        case 6:
            cout<<endl;
            if (!arrayExists) 
            {
                cout << "No array exists. Please create an array first." << endl;
                break;
            }

            cout << "The largest element in the array is: " << max(arr, size) << endl;
            cout<<endl;

            break;

        case 7:
            cout<<endl;
            if (!arrayExists) 
            {
                cout << "No array exists. Please create an array first." << endl;
                break;
            }

            cout << "The smallest element in the array is: " << min(arr, size) << endl;
            cout<<endl;

            break;

        case 8:
            cout<<endl;
            cout << "Enter n to exit: ";
            cin >> answer;

            cout<<endl;

            break;

        default:
            cout<<endl;
            cout << "Enter a valid option";
            cout<<endl;
            break;
        }

        cout<<string(50,'-');
        cin.ignore();
        cout<<endl;
    }

    return 0;
}