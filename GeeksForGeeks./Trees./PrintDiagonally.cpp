#include <iostream>
#include<vector>
using namespace std;

typedef vector<vector<int>> Matrix;

int main() 
{
	int nTestCases = 0;
	cin >> nTestCases;
	while(nTestCases--)
	{
        Matrix mat;
        int nDims = 0;
        cin >> nDims;
        for(int i=0; i<nDims; i++)
        {
            mat.push_back(std::vector<int>());
            for(int j=0; j<nDims; j++)
            {
                int num = 0;
                cin >> num;
                mat[i].push_back(num);
            }
        }
        
    	int nDigs = (mat.size()*2) - 1;
    	int nItr = 0;
    	int end = 0;
    	
    	for(int i=0; i<nDigs; i++)
    	{
    	    int start = 0;
    	    if(i < mat.size())
    	    {
    	        end = i;
    	        nItr = i+1;
    	    }
    	    else if(i == mat.size())
    	    {
    	        end = i - 1;
    	        --nItr;
    	        start = (i + 1) - mat.size();
    	    }
    	    else
    	    {
    	        --nItr;
    	        start = (i + 1) - mat.size();
    	    }
    	    
    	    int col = end;
    	    
    	    for(int j=0; j<nItr; j++)
    	    {
    	        cout << mat[start++][col--] << " ";
    	    }
    	}
    	cout << endl;
	}
	
	return 0;
}
