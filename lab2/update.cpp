#include <iostream>
using namespace std;

int main()
{
    int m, n, element, row, column;
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

    cout << "Enter the element to be updated: ";
    cin >> element;

    cout << "Enter the row at which the element needs to be updated: ";
    cin >> row;

    cout << "Enter the column at which the element needs to be updated: ";
    cin >> column;


    arr[row-1][column-1] = element;

    
    cout << "The 2D Array after Updation:\n";

    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << "" << endl;
    }

    return 0;
}