#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream inf;
ofstream outf;

string encrypt(string plain, int n)
{
    // cout<<plain<<" "<<n<<endl;
    string cipher;
    for (int i = 0; i < plain.length(); i++)
    {
        if (plain[i] == ' ')
            cipher.push_back(' ');
        else if (plain[i] >= 'a' && plain[i] <= 'z')
            cipher.push_back((plain[i] - 'a' + n) % 26 + 'a');
        else if (plain[i] >= '0' && plain[i] <= '9')
            cipher.push_back((plain[i] - '0' + n) % 10 + '0');
        else if (plain[i] >= 'A' && plain[i] <= 'Z')
            cipher.push_back((plain[i] - 'A' + n + 26) % 26 + 'A');
        else
        	cipher.push_back(plain[i]);
    }
    cout <<"Cipher text is "<< cipher << endl;
    return cipher;
}

string decrypt(string cipher, int n)
{
    string plain;
    for (int i = 0; i < cipher.length(); i++)
    {
        if (cipher[i] == ' ')
            plain.push_back(' ');
        else if (cipher[i] >= 'a' && cipher[i] <= 'z')
            plain.push_back((cipher[i] - 'a' - n + 26) % 26 + 'a');
        else if (cipher[i] >= 'A' && cipher[i] <= 'Z')
            plain.push_back((cipher[i] - 'A' - n + 26) % 26 + 'A');
        else if (cipher[i] >= '0' && cipher[i] <= '9')
            plain.push_back((cipher[i] - '0' - n + 10) % 10 + '0');
        else
        	plain.push_back(cipher[i]);
    }
    cout <<"Plain text is "<< plain << endl;
    return plain;
}


int find_key_brute(string plain, string cipher)
{
	for(int i=0;i<26;i++)
	{
		string st=decrypt(cipher,i);
		cout<<st<<" "<<i<<endl;
		if(st==plain)
		{
			cout<<"Most appropriate plain text is :- "<<st<<" with key "<<i<<endl;
			return i;	
		}
	}
	return -1;
}

int find_check(string plain,string cipher)
{
    int k;
    if (cipher[0] >= 'a' && cipher[0] <= 'z')
        k = (cipher[0] - plain[0] + 26) % 26;
    if (cipher[0] >= '0' && cipher[0] <= '9')
        k = (cipher[0] - plain[0] + 10) % 10;
    if (cipher[0] >= 'A' && cipher[0] <= 'Z')
        k = (cipher[0] - plain[0] + 26) % 26;
    for (int i = 1; i < plain.length(); i++)
    {
        int ch;
        if (cipher[i] >= 'a' && cipher[i] <= 'z')
            ch = (cipher[0] - plain[0] + 26) % 26;
        else if (cipher[i] >= 'A' && cipher[i] <= 'Z')
            ch = (cipher[0] - plain[0] + 26) % 26;
        else if (cipher[i] >= '0' && cipher[i] <= '9')
            ch = (cipher[0] - plain[0] + 10) % 10;
        if (ch == k || cipher[i] == ' ' || plain[i] == ' ')
            continue;
        else
            return -1;
    }
    return k;
}

int find_key_freq(string plain, string cipher)
{
	
	vector<pair<double,char> >original_freq;
	original_freq.push_back(make_pair(0.08,  'a'));
	original_freq.push_back(make_pair(0.015,  'b'));
	original_freq.push_back(make_pair(0.028,  'c'));
	original_freq.push_back(make_pair(0.043,  'd'));
	original_freq.push_back(make_pair(0.126,  'e'));
	original_freq.push_back(make_pair(0.021,  'f'));
	original_freq.push_back(make_pair(0.02,  'g'));
	original_freq.push_back(make_pair(0.06,  'h'));
	original_freq.push_back(make_pair(0.07,  'i'));
	original_freq.push_back(make_pair(0.005,  'j'));
	original_freq.push_back(make_pair(0.009,  'k'));
	original_freq.push_back(make_pair(0.04,  'l'));
	original_freq.push_back(make_pair(0.22,  'm'));
	original_freq.push_back(make_pair(0.065,  'n'));
	original_freq.push_back(make_pair(0.075,  'o'));
	original_freq.push_back(make_pair(0.02,  'p'));
	original_freq.push_back(make_pair(0.002,  'q'));
	original_freq.push_back(make_pair(0.06,  'r'));
	original_freq.push_back(make_pair(0.065,  's'));
	original_freq.push_back(make_pair(0.09,  't'));
	original_freq.push_back(make_pair(0.025,  'u'));
	original_freq.push_back(make_pair(0.01,  'v'));
	original_freq.push_back(make_pair(0.021,  'w'));
	original_freq.push_back(make_pair(0.002,  'x'));
	original_freq.push_back(make_pair(0.02,  'y'));
	original_freq.push_back(make_pair(0.001,  'z'));
	
//    {0.015, 'b'},
//    {0.028, 'c'},
//    {0.043, 'd'},
//    {0.126, 'e'},
//    {0.021, 'f'},
//    {0.02,  'g'},
//    {0.06,  'h'},
//    {0.07,  'i'},
//    {0.005, 'j'},
//    {0.009, 'k'},
//    {0.04,  'l'},
//    {0.022, 'm'},
//    {0.065, 'n'},
//    {0.075, 'o'},
//    {0.02,  'p'},
//    {0.002, 'q'},
//    {0.06,  'r'},
//    {0.065, 's'},
//    {0.09,  't'},
//    {0.025, 'u'},
//    {0.01,  'v'},
//    {0.021, 'w'},
//    {0.002, 'x'},
//    {0.02,  'y'},
//    {0.001, 'z'}};
    vector<pair<double,char> >cipher_freq(26);
    map<char,int>mp1;
    for(int i=0;i<cipher.length();i++)
    {
        mp1[cipher[i]]++;
    }
    int len=cipher.length();
    for(int i=0;i<26;i++)
    {
        double k = (double)mp1[i+'a']/len;
        cipher_freq[i] = {k,i+'a'};
    }
    sort(cipher_freq.begin(),cipher_freq.end());
    sort(original_freq.begin(),original_freq.end());
    for(int i=0;i<26;i++)
    {
        int kk = abs(original_freq[i].second - cipher_freq[i].second);
//        cout << decrypt(cipher,kk) << "\n\n";
		string st=decrypt(cipher,i);
		cout<<st<<" "<<i<<endl;
		if(st==plain)
		{
			cout<<"Most appropriate plain text is :- "<<st<<" with key "<<i<<endl;
			return i;	
		}
    }
    return -1;
//    int k;
//    map<char, int> mp1, mp2;
//    for (int i = 0; i < plain.length(); i++)
//        mp1[plain[i]]++;
//    for (int i = 0; i < cipher.length(); i++)
//        mp2[cipher[i]]++;
//    char ch;
//    vector<pair<int, char> > v1, v2;
//    map<char,int>::iterator itt,it;
//    for (itt = mp1.begin(); itt != mp1.end(); itt++)
//    {
//        v1.push_back({itt->second, itt->first});
//    }
//    for (it = mp2.begin(); it != mp2.end(); it++)
//    {
//        v2.push_back({it->second, it->first});
//    }
//    sort(v1.begin(), v1.end());
//    sort(v2.begin(), v2.end());
//    string pl, ci;
//    for (int i = 0; i < v2.size(); i++)
//    {
//        pl.push_back(v1[i].second);
//        ci.push_back(v2[i].second);
//    }
//    return find_check(pl, ci);
}


//string decrypt(string cipher, int n)
//{
//    string plain;
//    for (int i = 0; i < cipher.length(); i++)
//    {
//        if (cipher[i] == ' ')
//            plain.push_back(' ');
//        else if (cipher[i] >= 'a' && cipher[i] <= 'z')
//            plain.push_back((cipher[i] - 'a' - n + 26) % 26 + 'a');
//        else if (cipher[i] >= 'A' && cipher[i] <= 'Z')
//            plain.push_back((cipher[i] - 'A' - n + 26) % 26 + 'A');
//        else if (cipher[i] >= '0' && cipher[i] <= '9')
//            plain.push_back((cipher[i] - '0' - n + 10) % 10 + '0');
//        else
//        	plain.push_back(cipher[i]);
//    }
//    cout << plain << endl;
//    return plain;
//}

int main()
{
     ifstream inf1("plain.txt");
     ifstream inf2("cipher.txt");
     ifstream inf3("key.txt");
    int n;
    string plain, cipher;
    getline(inf1,plain);
//    inf1 >> plain;
    inf3 >> n;
    string ee=encrypt(plain, n);
    getline(inf2,cipher);
//    inf2 >> cipher;
    string dd=decrypt(cipher, n);
    int z = find_key_brute(plain, cipher);
    if (z == -1)
        cout << "Not a Caesar Cipher" << endl;
    else
        cout << "Key using Brute Force Attack is :- " << z << endl;
    z = find_key_freq(plain, cipher);
    if (z == -1)
        cout << "Not a Caesar Cipher" << endl;
    else
        cout << "Key using freq. analysis attack is :- " << z << endl;
    //    myfile.close();
}


