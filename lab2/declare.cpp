#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cout << "Enter number of rows: ";
    cin >> m;
    cout << "Enter number of columns: ";
    cin >> n;

    //Declaring
    int arr[m][n];

    //Initializing
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout << "Enter element arr[" << i << "][" << j << "]: ";
            cin >> arr[i][j];
            cout << "" << endl;
        }
    }

    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout << "Element arr[" << i << "][" << j << "]: " << arr[i][j] << endl;
        }
    }

    return 0;
}