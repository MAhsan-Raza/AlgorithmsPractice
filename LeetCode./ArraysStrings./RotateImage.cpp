class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        //transpose
        for(size_t i=0; i<matrix.size(); i++)
        {
            auto v2 = matrix[i];
            for(size_t j=i; j<v2.size(); j++)
            {
                if(i != j)
                    swap(matrix, i, j);
            }
        }
        
        //mirror
        for(size_t i=0; i<matrix.size(); i++)
        {
            auto v2 = matrix[i];
            for(size_t j=0; j<v2.size()/2; j++)
            {
                swap(matrix, i, j, v2.size() -1 - j);
            }
            cout << endl;
        }
    }
    
    void swap(vector<vector<int>>& matrix, int i, int j, int k)
    {
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[i][k];
        matrix[i][k] = tmp;
    }
    
    void swap(vector<vector<int>>& matrix, int i, int j)
    {
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = tmp;
    }
};
