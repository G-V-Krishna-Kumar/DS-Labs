#include <iostream>
using namespace std;

int main()
{
    int m, n;
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

    int row;
    cout << "Enter row to be deleted: ";
    cin >> row;

    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (i == row-1)
            {
                arr[i][j] = 0;
            }
            
        }
        
    }

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