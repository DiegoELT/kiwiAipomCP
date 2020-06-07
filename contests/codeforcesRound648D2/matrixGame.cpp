#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int cleanRows = 0, cleanColumns = 0;
int rows, columns;

string getWinner(vector< vector<int> > matrixToDetermine)  // Possible optimization, get both in just one check of the matrix.
{
    cleanRows = rows = matrixToDetermine.size();
    cleanColumns = columns = matrixToDetermine[0].size();

    for(int i = 0; i < rows; i++)  // First lets get clean Rows
    {
        for(int j = 0; j < columns; j++)
        {
            if(matrixToDetermine[i][j])
            {
                cleanRows--;
                break;
            }
        }
    }

    for(int i = 0; i < columns; i++)  // Then we get the clean columns 
    {
        for(int j = 0; j < rows; j++)
        {
            if(matrixToDetermine[j][i])
            {
                cleanColumns--;
                break;
            }
        }
    }

    if(min(cleanRows, cleanColumns) % 2)
        return "Ashish\n";
    else
        return "Vivek\n";
}

int main()
{
    int testCases, rows, columns, takenOrNot;
    vector< vector<int> > matrix;
    vector<int> row; 

    cin >> testCases; 

    for(int i = 0; i < testCases; i++)
    {
        cin >> rows >> columns;
        for(int j = 0; j < rows; j++)
        {
            for(int k = 0; k < columns; k++)
            {
                cin >> takenOrNot;
                row.push_back(takenOrNot);
            }
            matrix.push_back(row);
            row.clear();
        }
        cout << getWinner(matrix);
        matrix.clear();
    }

    return 0;
}

// Note from the author: Even though in the contest the code didn't manage to pass pre-test 1, this was due to me not writing one of the returning strings right. So I am still considering it under "contest".