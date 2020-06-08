#include <bits/stdc++.h>
#include<sstream>
using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s)
 {
    bool isPM = false;

    //cout<<s[8]<<s[9]<<endl;
    if(s[8] == 'P')
        isPM = true;

    string resStr = s.substr(0, 8);
    //cout<<resStr<<endl;

    if(isPM)
    {
        stringstream ss;
        int hrs = atoi(resStr.substr(0, 2).c_str());
        if(hrs != 12)
        {
            hrs+=12;
            ss << hrs;
            string sHrs;
            ss >> sHrs;
            resStr[0] = sHrs[0];
            resStr[1] = sHrs[1];
        }
    }
    else
    {
        if(resStr[0]=='1'&&resStr[1]=='2')
            resStr[0]=resStr[1]='0';
    }

    return resStr;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
