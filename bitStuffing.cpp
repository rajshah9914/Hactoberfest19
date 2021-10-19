#include <bits/stdc++.h>
using namespace std;

bool validate(string s){
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0' || s[i] == '1')
        {
            continue;
        }
        else
        {
            cout << "Please enter a binary data.\n";
            return 1;
        }
    }
    return 0;
}

int main()
{
again:
    cout << "Enter the data to be sent\n";
    string s;
    cin >> s;
    bool flag = validate(s);
    if (flag)
        goto again;

    char code_word[s.length() + 10];
    int i = 0, cnt = 1, j = 0;
    while (i < s.length())
    {
        if (s[i] == '1')
        {
            code_word[j] = s[i];
            for (int k = i + 1; s[k] == '1' && k < s.length() && cnt < 5; k++)
            {
                j++;
                code_word[j] = s[k];
                cnt++;
                if (cnt == 5)
                {
                    j++;
                    code_word[j] = '0';
                }
                i = k;
            }
        }
        else
        {
            code_word[j] = s[i];
            cnt = 1;
        }
        i++;
        j++;
    }
    cout << "The codeword generated is:\n";
    for (int l = 0; l < j; l++)
        cout << code_word[l];
    return 0;
}