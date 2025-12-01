#include <iostream>

void selection_sort(int* arr, int n)
{      
    int min_in=0,temp=0;
    for(int i=0;i<n;++i)
    {   
        min_in=i;
        for(int j=i;j<n;++j)
        {
            if(arr[j]<arr[min_in])
            {
                min_in=j;
            }
        }
        temp=arr[min_in];
        arr[min_in]=arr[i];
        arr[i]=temp;
    }
}

void swap(int* arr, int i, int j)
{   
    if (i==j) return;
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void better_selection_sort(int* arr, int n)
{      
    int min_in=0,max_in,temp=0;
    for(int i=0;i<n/2;++i)
    {   
        min_in=i,max_in=n-1-i;
        if (arr[min_in] > arr[max_in])
        {
            swap(arr, min_in, max_in);
        }
    
        for(int j=i;j<n-1-i;++j)
        {
            if(arr[j]<arr[min_in])
            {
                min_in=j;
            }
            else if(arr[j]>arr[max_in])
            {
                max_in=j;
            }
        }

        swap(arr,min_in,i);

        if (max_in == i)
        {
            max_in = min_in;
        }
            
        swap(arr,max_in,n-1-i);
    }
}

void insertion_sort(int* arr, int n)
{
  for(int i=1;i<n-1;++i)
  { 
    int temp=arr[i];
    int j=i; 

    while(j > 0 && arr[j-1] > temp)
    {
        arr[j]=arr[j-1];
        --j;
    }

    arr[j]=temp;
  }  
}

void bubble_sort(int* arr, int n)
{   
    int temp=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n-i-1;++j)
        {
            if(arr[j+1]<arr[j])
            {
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

void merge(int* arr, int l, int m, int r);

void merge_sort(int* arr, int l, int r)
{   
    if(l>=r) return;

    int m= l + (r - l) / 2;

    merge_sort(arr,l,m);   
    merge_sort(arr,m+1,r); 

    merge(arr, l, m, r);  
}

void merge_sort(int* arr, int n)
{   
    if (n<=1)
        return;
    merge_sort(arr,0,n-1);
}

void merge(int* arr, int l, int m, int r)
{
    int n1= m - l + 1;
    int n2= r - m;

    int* L= new int[n1]; int* R= new int[n2];

    for(int i=0;i<n1;++i) L[i]=arr[l+i];
    for(int i=0;i<n2;++i) R[i]=arr[m+1+i];

    int i=0, j=0, k=l;

    while(i < n1  && j < n2)
    {
        if(L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];

    delete[] L; delete[] R;
}

void quick_sort(int* arr, int l, int r)
{   
    if(l>=r) return;

    int pivot=arr[r];
    int i=l-1;

    for(int j=l;j<r;++j)
        if(arr[j]<=pivot) swap(arr,++i,j);

    swap(arr,++i,r);

    int p=i;

    quick_sort(arr,l,p-1);
    quick_sort(arr,p+1,r);
}

void quick_sort(int* arr, int n)
{   
    if(n<=1) return; 
    quick_sort(arr, 0, n-1);
}

int main() {
    int choice = 0;
    int size = 30;

    while (true) {
        int test[size]={19, 17, 1,4,-5,0,0,3,0,67,2,-99, 77, -2, -69,1,4,-5,0,0,3,0,67,2,-99,67,88, 0, 2, 56};
        
        std::cout << "Before sorting: [ ";
        for (int i = 0; i < size; ++i)
        {
            std::cout << test[i];
            std::cout << " ";
        }        
        std::cout << "]\n\n";

        std::cout << "---- SORT MENU ----\n";
        std::cout << "1. Selection Sort\n";
        std::cout << "2. Better Selection Sort\n";
        std::cout << "3. Insertion Sort\n";
        std::cout << "4. Bubble Sort\n";
        std::cout << "5. Merge Sort\n";
        std::cout << "6. Quick Sort\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "SELECTION SORT\n";
                selection_sort(test, size);
                break;
            case 2:
                std::cout << "BETTER SELECTION SORT\n";
                selection_sort(test, size);
                break;
            case 3:
                std::cout << "INSERTION SORT\n";
                insertion_sort(test, size);
                break;
            case 4:
                std::cout << "BUBBLE SORT\n";
                bubble_sort(test, size);
                break;
            case 5:
                std::cout << "MERGE SORT\n";
                merge_sort(test, size);
                break;
            case 6:
                std::cout << "QUICK SORT\n";
                quick_sort(test, size);
                break;
            case 7:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }

        std::cout << "\n";

        std::cout << "After sorting: [ ";
        for (int i = 0; i < size; ++i)
        {
            std::cout << test[i];
            std::cout << " ";
        }        
        std::cout << "]\n\n";

    }
}
