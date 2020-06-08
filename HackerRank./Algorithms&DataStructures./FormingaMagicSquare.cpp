#include <bits/stdc++.h>

using namespace std;

int getDistance(const vector<vector<int>>& ms, const vector<vector<int>>& s)
{
    int dist = 0;

    for(int row=0; row<3; row++)
    {
        for(int col=0; col<3; col++)
        {
            dist += abs(ms[row][col] - s[row][col]);
        }
    }
    cout<<dist<<" ";
    return dist;
}

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) 
{
    vector<vector<vector<int>>> ams =  {
    {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
    {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
    {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
    {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}}, 
    {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
    {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}}, 
    {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}}, 
    {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}},
    };

    int minDist = 0;

    for(int mat=0; mat<8; mat++)
    {
        int tmpDist = getDistance(ams[mat], s);
        
        if(mat == 0)
        {
            minDist = tmpDist;
        }
        else if(minDist > tmpDist)
            minDist = tmpDist;
    }

    return minDist;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
