#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the climbingLeaderboard function below.
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) 
{
    vector<int> vRes;

    int scr = 1;
    map<int, int> umLB;

    int prev=-1;

    cout << endl << "Other's scores" << endl;
    for(auto x : scores)
    {
        if(x != prev)
        {
            umLB[x] = scr;
            cout << x << ": " << scr << ", ";
            prev = x;
            ++scr;
        }
    }
    cout<<endl;
    cout<<endl;

    cout << endl << "Alice's scores" << endl;
    for(auto a : alice)
    {
        map<int, int>::const_iterator ci = umLB.find(a);

        if(ci != umLB.end())
        {
            cout << a << " already present with score: " << ci->second << endl;
            vRes.push_back(ci->second);
        }
        else 
        {
            cout << a << " not present inserting" << endl;
            auto at = umLB.insert(make_pair(a, 0));
            if(a == umLB.rbegin()->first)
            {
                cout<<"Largest points, score = 1" << endl;
                vRes.push_back(1);
            }
            else if(a == umLB.begin()->first)
            {
                auto grtr = (++(at.first));
                cout<<"Greator item: " << grtr->first << ": " << grtr->second << endl;
                int nsc = grtr->second + 1;
                vRes.push_back(nsc);
            }
            else
            {
                auto smaller = (--(at.first));
                cout<<"Smaller item: " << smaller->first << ": " << smaller->second << endl;
                vRes.push_back(smaller->second);
            }
            umLB.erase(a);
        }
        cout<<endl;
        cout<<endl;
    }

    /*for(auto a:alice)
    {
        int scr = 1;
        for(int i=0; i<scores.size(); i++)
        {
            int x=scores[i];

            if(i!=0 && x==scores[i-1])
                continue;
            
            if(x == a)
            {
                vRes.push_back(scr);
                break;
            }
            else if(x < a)
            {
                vRes.push_back(scr);
                break;
            }

            ++scr;
        }

        if(*scores.rbegin()>a)
            vRes.push_back(scr);
    }*/

    return vRes;
    /*map<int, bool> mpLB;

    cout << endl << "Other's scores" << endl;
    for(auto x:scores)
    {
        mpLB[x] = false;
        cout << x << " ";
    }

    cout << endl << "Alice's scores" << endl;
    for(auto a : alice)
    {
        mpLB[a] = true; //insert or update prev
        cout << a << " ";
    }

    int i=1;
    vector<int> vRes;
    for(auto z : mpLB)
    {
        if(z.second == true)
            vRes.push_back(i);
        ++i;
    }

    reverse(vRes.begin(), vRes.end());
    return vRes;*/
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int scores_count;
    cin >> scores_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(scores_count);

    for (int i = 0; i < scores_count; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    int alice_count;
    cin >> alice_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string alice_temp_temp;
    getline(cin, alice_temp_temp);

    vector<string> alice_temp = split_string(alice_temp_temp);

    vector<int> alice(alice_count);

    for (int i = 0; i < alice_count; i++) {
        int alice_item = stoi(alice_temp[i]);

        alice[i] = alice_item;
    }

    vector<int> result = climbingLeaderboard(scores, alice);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
