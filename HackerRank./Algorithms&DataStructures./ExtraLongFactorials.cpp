#include <bits/stdc++.h>

using namespace std;

void PrintVector(const vector<int>& vec, const string& lable)
{
    cout << lable << ": ";
    int nv = vec.size();
    while(--nv>=0)  cout << vec[nv];
    cout << endl;
}

void ConvertNToVec(int n, vector<int>& vec)
{
    while(n)
    {
        vec.push_back(n%10);
        n = n / 10;
    }
}

int AddByDigit(int i, int j, int& carry)
{
    //cout<<endl<<"AddByDigit: i="<<i<<", j="<<j<<", carry="<<carry<<", res=";
    int res = 0;
    int tmp = i + j + carry;

    if(tmp == -1) // works only for -1
    {
        carry = tmp;
        res = 9;
    }
    else 
    {
        if(tmp > 9)
        {
            res = tmp % 10;
            carry = tmp / 10;
        }
        else
        {
            res = tmp;
            carry = 0;
        }
    }

    //cout<<res<<", newCarry="<<carry<<endl;
    return res;
}

//return false if result reaches zero
bool ADD(const vector<int>& a, const vector<int>& b, vector<int>& res)
{
    res.clear();

    int i = 0;
    int carry = 0;
    int nRes = 0;

    for(; i<a.size(); i++)
    {
        if(i < b.size())
        {
            nRes = AddByDigit(a[i], b[i], carry);
        }
        else
            nRes = AddByDigit(a[i], 0, carry);
        
        res.push_back(nRes);
    }

    while(i<b.size())
    {
        nRes = AddByDigit(a[i], b[i], carry);
        res.push_back(nRes);
        i++;
    }

    if(carry != 0)
        res.push_back(carry);

    bool bIsEmpty = true;
    i = res.size();
    while(--i>=0)
    {
        //cout<<res[i];
        if(res[i] != 0)
        {//cout<<"Vec not empty, found: "<<res[i]<<endl;
            bIsEmpty = false;
            break;
        }
    }
        //PrintVector(res);

    if(bIsEmpty)
    {//cout<<"Vec is empty "<<endl;
        res.clear();
        return false;
    }
    return true;
}

void MUL(const vector<int>& a, vector<int> b, vector<int>& res)
{
    vector<int> resSUB, resADD;
    res = a;
    
    while(ADD(b, {-1}, resSUB))
    {
        ADD(res, a, resADD);        
        b.swap(resSUB);
        res.swap(resADD);//PrintVector(res, "res");PrintVector(b, "b");cout<<endl;
    }
}

// Complete the extraLongFactorials function below.
void extraLongFactorials(int n) 
{
    vector<int> a, resSUB, resMUL;
    vector<int> res;
    ConvertNToVec(n, a);
    res = a;

    // not correct it is doing: 5*4*5*3*5*2*5*1
    while(ADD(a, {-1}, resSUB))
    {
        //PrintVector(resSUB, "resSUB");
        MUL(res, resSUB, resMUL);
        /*PrintVector(a, "a");
        PrintVector(res, "res");
        PrintVector(resMUL, "resMUL");*/
        res.swap(resMUL);
        a.swap(resSUB);
    }

    for(int i=res.size()-1; i>=0; i--)
        cout<<res[i];
    cout<<endl;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}
