#include <iostream>
using namespace std;

int main()
{
    int m, n, temp;
    cout << "Enter the number of rows: ";
    cin >> m;

    cout << "Enter the number of columns: ";
    cin >> n;

    int arr[m][n];

    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout << "Enter element arr[" << i << "]" << "[" << j << "]: ";
            cin >> arr[i][j];
        }
    }

    cout << "Given 2D Array:\n";

    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << "" << endl;
    }

    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (arr[i][j] > arr[i][j+1])
            {
                temp = arr[i][j];
                arr[i][j] = arr[i][j+1];
                arr[i][j+1] = temp;
            }
        }
    }

    cout << "Row-wise Sorted 2D Array" << endl;
    for (int i=0; i<m; i++)
    {
        for (int j = 0; j<n; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << "" << endl;
    }

    return 0;
}