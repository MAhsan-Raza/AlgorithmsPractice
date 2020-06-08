#include <iostream>
#include <vector>
#include<unordered_map>
#include<sstream>

using namespace std;

typedef enum
{
    ROOT = 0,
    PREFIX,
    WORD
    
} EnTrieNodeType;

class _TrieNode;
typedef unordered_map<char, _TrieNode*> TrieMap;

typedef struct _TrieNode
{
    EnTrieNodeType nodeType;
    char data;
    int count;
    
    TrieMap childern;
    
    _TrieNode(EnTrieNodeType nt, char d, int n) 
        : nodeType(nt), data(d), count(n) {}
        
    string toString()
    {
        if(nodeType == ROOT)
            return "ROOT";
            
        stringstream ss;
        ss << data << ", " << 
            ((nodeType == PREFIX) ? "PREFIX" : "WORD") 
            << ", " << count;
        return ss.str();
    }
    
} TrieNode;

TrieNode* g_root = nullptr;

TrieNode* traverse(const string& str, 
    int& index, TrieNode* crnt, bool& matched)
{
    if(index >= str.size())
    {
        //cout << "\nIndex up returning current[" << crnt->toString() << "]";
        return crnt;
    }
    
    //cout << "\nTraversing for [" << str[index] << "] current[" << crnt->toString() << "]";
    
    TrieMap::const_iterator cItr = crnt->childern.find(str[index]);
    
    if(cItr == crnt->childern.end())
    {
        //cout << "\nnot matched[" << str[index] << "] returning current[" << crnt->toString() << "]";
        return crnt;
    }
    
    if(index == str.size() - 1)
    {
        //cout << "\nExact match [" << str[index] << "] returning current[" << cItr->second->toString() << "]";
        matched = true;
        return cItr->second;
    }
    else return traverse(str, ++index, cItr->second, matched);
}

TrieNode* traverseEx(const string& str, 
    int& index, TrieNode* crnt, bool& matched, string& prefix)
{
    if(index >= str.size())
    {
        //cout << "\nIndex up returning current[" << crnt->toString() << "]";
        return crnt;
    }
    
    //cout << "\nTraversing for [" << str[index] << "] current[" << crnt->toString() << "]";
    
    TrieMap::const_iterator cItr = crnt->childern.find(str[index]);
    
    if(cItr == crnt->childern.end())
    {
        //cout << "\nnot matched[" << str[index] << "] returning current[" << crnt->toString() << "]";
        return crnt;
    }
    
    if(index == str.size() - 1)
    {
        //cout << "\nExact match [" << str[index] << "] returning current[" << cItr->second->toString() << "]";
        matched = true;
        return cItr->second;
    }
    else 
    {
        prefix += str[index];
        return traverse(str, ++index, cItr->second, matched);
    }
}

void traverseAll(TrieNode* crnt, 
    string& prefix, vector<string>& words)
{
    prefix += crnt->data;
    
    if(crnt->nodeType == WORD)
    {
        words.push_back(prefix);
    }
    
    TrieMap::const_iterator cItr = crnt->childern.begin();
    
    while(cItr != crnt->childern.end())
    {
        traverseAll(cItr->second, prefix, words);
        ++cItr;
    }
}

int search(const string& str)
{
    int index = 0;
    bool matched = false;
    TrieNode* tmp = traverse(str, index, g_root, matched);
    
    if(matched)
    {
        //cout << "\nSearch successfull, count[" << tmp->count << "]";
        return tmp->count;
    }
        
    //cout << "\nSearch failed";
    return 0;
}

void createNewBranch(const string& str, int index, TrieNode* current)
{
    /*cout <<"\nCreating new branch from [" 
        << current->toString() << "] with [" << str[index] << "]";*/
        
    if(index == str.size() - 1)
    {
        //cout << "\nBranch completed creating leaf";
        TrieNode* tmp = new TrieNode(WORD, str[index], 1);
        current->childern[str[index]] = tmp;
    }
    else
    {
        //cout << "\nExtending branch";
        TrieNode* tmp = new TrieNode(PREFIX, str[index], 0);
        current->childern[str[index]] = tmp;
        createNewBranch(str, ++index, tmp);
    }
}

int insertTrie(const string& str)
{
    int index = 0;
    bool matched = false;
    //cout << "\nAt insert finding the prefix for [" << str << "]";
    TrieNode* prefix = traverse(str, index, g_root, matched);
    if(matched)
    {
        /*cout << "\nAlready present [" << str 
            << "], count [" << prefix->count <<  "]";*/
        return ++prefix->count;
    }
    else
    {
        createNewBranch(str, index, prefix);
        //cout << "\nInserted [" << str << "]";
        return 1;
    }
}

bool getWordsFromPrefix(
    const string& prefix, vector<string> words)
{
    int index = 0;
    bool matched = false;
    string triesPrefix;
    TrieNode* tnPrefix = traverseEx(str, index, g_root, matched, triesPrefix);
    
    if(tnPrefix != nullptr && tnPrefix != g_root)
    {
       if(tnPrefix->nodeType == WORD)
            words.pus_back(triesPrefix)
    }
    
    return false;
}

int main() 
{
	int nTestCases = 0;
	cin >> nTestCases;
	while(nTestCases--)
	{
	    g_root = new TrieNode(ROOT, 0, 0); //memory leak
	    
        int nWords = 0;
        cin >> nWords;
        for(int i=0; i<nWords; i++)
        {
            string str;
            cin >> str;
            insertTrie(str);
        }
        
        string tosearch;
        cin >> tosearch;
        
        int count = search(tosearch);
        cout << ((count == 0) ? 0 : 1) << endl;
	}
	
	return 0;
}
