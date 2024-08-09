#include <bits/stdc++.h>
using namespace std;

void markRow(vector<vector<int> > &matrix, int n, int m, int i) {
    // set all non-zero elements as -1 in the row i:
    for (int j = 0; j < m; j++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}


void markCol(vector<vector<int> > &matrix, int n, int m, int j) {
    // set all non-zero elements as -1 in the col j:
    for (int i = 0; i < n; i++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}

vector<vector<int> > approach1(vector<vector<int> > &matrix, int n, int m) {

    // Set -1 for rows and cols
    // that contains 0. Don't mark any 0 as -1:

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                markRow(matrix, n, m, i);
                markCol(matrix, n, m, j);
            }
        }
    }

    // Finally, mark all -1 as 0:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

vector<vector<int> > approach2(vector<vector<int> > &matrix, int n, int m) {

    vector<int> row(n,1), col(m,1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                row[i]=0;
                col[j]=0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] == 0 || col[j]==0) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}
vector<vector<int> > approach3(vector<vector<int> > &matrix, int n, int m) {

    // int row[n] = {0}; --> matrix[..][0]
    // int col[m] = {0}; --> matrix[0][..]

    int col0 = 1;
    // step 1: Traverse the matrix and
    // mark 1st row & col accordingly:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // mark i-th row:
                matrix[i][0] = 0;

                // mark j-th column:
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] != 0) {
                // check for col & row:
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    //step 3: Finally mark the 1st col & then 1st row:
    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

    return matrix;
}

int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int> > matrix(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<"Approach 1\n";
    cout<<"Time Complexity: O((N*M)*(N + M)) + O(N*M), where N = no. of rows in the matrix and M = no. of columns in the matrix.\n";
    cout<<"Reason: Firstly, we are traversing the matrix to find the cells with the value 0. It takes O(N*M). Now, whenever we find any such cell we mark that row and column with -1. This process takes O(N+M). So, combining this the whole process, finding and marking, takes O((N*M)*(N + M)).\n";
    cout<<"Another O(N*M) is taken to mark all the cells with -1 as 0 finally.\n";
    cout<<"Space Complexity: O(1) as we are not using any extra space.";

    vector<vector<int> > ans1 = approach1(matrix, n, m);
    cout << "The Final matrix is: \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans1[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"Approach 2\n";
    cout<<"Time Complexity: O(2*(N*M)), where N = no. of rows in the matrix and M = no. of columns in the matrix.\n";
    cout<<"Reason: We are traversing the entire matrix 2 times and each traversal is taking O(N*M) time complexity.\n";
    cout<<"Space Complexity: O(N) + O(M), where N = no. of rows in the matrix and M = no. of columns in the matrix.\n";
    cout<<"Reason: O(N) is for using the row array and O(M) is for using the col array.\n";
    vector<vector<int> > ans2 = approach2(matrix, n, m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans2[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<"Approach 3\n";
    cout<<"Time Complexity: O(2*(N*M)), where N = no. of rows in the matrix and M = no. of columns in the matrix.\n";
    cout<<"Reason: In this approach, we are also traversing the entire matrix 2 times and each traversal is taking O(N*M) time complexity.\n";
    cout<<"Space Complexity: O(1) as we are not using any extra space.\n";
    vector<vector<int> > ans3 = approach3(matrix, n, m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans3[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

