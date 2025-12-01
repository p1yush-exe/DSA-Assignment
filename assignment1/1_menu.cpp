#include <iostream>

using namespace std;

int main()
{
    int *arr = nullptr;
    int size = 0;
    bool ans = true;

    while (ans)
    {
        int choice;

        cout << "\n----MENU----" << endl;
        cout << "1. CREATE" << endl;
        cout << "2. DISPLAY" << endl;
        cout << "3. INSERT" << endl;
        cout << "4. DELETE" << endl;
        cout << "5. LINEAR SEARCH" << endl;
        cout << "6. EXIT" << endl;
        cout << "Enter an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            if (arr != nullptr)
            {
                delete[] arr;
                arr = nullptr;
            }

            cout << "Enter the size of the new array: ";
            cin >> size;

            arr = new int[size];

            cout << "Please enter " << size << " elements." << endl;
            for (int i = 0; i < size; i++)
            {
                cout << "Enter element number " << i + 1 << ": ";
                cin >> arr[i];
            }
            cout << "Array created." << endl;
            break;
        }

        case 2:
        {
            if (arr == nullptr)
            {
                cout << "Array is not created yet. Please use option 1 first." << endl;
            }
            else
            {
                cout << "Array elements: ";
                for (int i = 0; i < size; i++)
                {
                    cout << arr[i] << ' ';
                }
                cout << endl;
            }
            break;
        }

        case 3:
        {
            if (arr == nullptr)
            {
                cout << "Array is not created yet. Please use option 1 first." << endl;
                break;
            }

            int insel, inspos;
            cout << "Enter the index where you want to insert (0 to " << size << "): ";
            cin >> inspos;

            if (inspos < 0 || inspos > size)
            {
                cout << "Invalid index." << endl;
                break;
            }

            cout << "What element would you like to insert: ";
            cin >> insel;

            int *newArr = new int[size + 1];

            for (int i = 0; i < inspos; i++)
            {
                newArr[i] = arr[i];
            }

            newArr[inspos] = insel;

            for (int i = inspos; i < size; i++)
            {
                newArr[i + 1] = arr[i];
            }

            delete[] arr;
            arr = newArr;
            size++;

            cout << "Inserted." << endl;
            break;
        }

        case 4:
        {
            if (arr == nullptr)
            {
                cout << "Array is not created yet. Please use option 1 first." << endl;
                break;
            }

            cout << "What element do you want to delete?: ";

            int el;
            cin >> el;

            int foundIndex = -1;

            for (int i = 0; i < size; i++)
            {
                if (arr[i] == el)
                {
                    foundIndex = i;
                    break;
                }
            }

            if (foundIndex == -1)
            {
                cout << "Element not found in the array." << endl;
            }
            else
            {
                int *newArr = new int[size - 1];
                for (int i = 0, j = 0; i < size; i++)
                {
                    if (i == foundIndex)
                    {
                        continue;
                    }
                    newArr[j] = arr[i];
                    j++;
                }
                delete[] arr;
                arr = newArr;
                size--;
                cout << "Element deleted." << endl;
            }
            break;
        }

        case 5:
        {
            if (arr == nullptr)
            {
                cout << "Array is not created yet. Please use option 1 first." << endl;
                break;
            }

            cout << "Enter the element to search for: ";
            int el;
            cin >> el;

            int in = -1;
            for (int i = 0; i < size; i++)
            {
                if (arr[i] == el)
                {
                    in = i;
                    break;
                }
            }

            if (in != -1)
            {
                cout << "Element " << el << " found at index " << in << "." << endl;
            }
            else
            {
                cout << "Element " << el << " was not found in the array." << endl;
            }
            break;
        }

        case 6:
        {
            ans = false;
            break;
        }

        default:
        {
            cout << "Invalid option. Please enter a number between 1 and 6." << endl;
            break;
        }
        }
    }

    delete[] arr;
    return 0;
}
