class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        for(size_t i=0; i<9; i++)
        {
            unordered_set<char> colSet;
            unordered_set<char> rowSet;
            for(size_t j=0; j<9; j++)
            {
                char nColCell = board[i][j];
                char nRowCell = board[j][i];
                
                if(nColCell != '.')
                {
                    if(nColCell < '1' || nColCell > '9')
                        return false;
                    
                    if(colSet.find(nColCell) != colSet.end())
                        return false;
                    colSet.insert(nColCell);
                }
                
                if(nRowCell != '.')
                {                    
                    if(nRowCell < '1' || nRowCell > '9')
                        return false;
                    
                    if(rowSet.find(nRowCell) != rowSet.end())
                        return false;
                    rowSet.insert(nRowCell);
                }
            }
        }
        
        
        for(size_t i=0; i<9; i+=3)
        {
            for(size_t j=0; j<9; j+=3)
            {
                unordered_set<char> celSet;
                for(size_t x=i; x<i+3; x++)
                {
                    for(size_t y=j; y<j+3; y++)
                    {
                        char celVal = board[x][y];
                        
                        if(celVal == '.')   continue;
                        
                        if(celSet.find(celVal) != celSet.end())
                        {
                            cout << x << ", " << y;
                            return false;
                        }
                        celSet.insert(celVal);
                    }
                }
            }
        }
        return true;
    }
};
