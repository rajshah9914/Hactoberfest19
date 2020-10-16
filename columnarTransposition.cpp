#include<bits/stdc++.h>
using namespace std;

void encrypt()
{
    string plain,key;
    getline(cin,plain);
    cin>>key;
    // cout<<plain<<endl;
    int n=key.length();
    map<char,int>mp;
    for(int i=0;i<key.size();i++)
        mp[key[i]]=i+1;
    // cout<<mp['h']<<endl;
    char mat[100][100];
    int i=0;
    // cout<<plain.length()<<endl;
    while(i*n<plain.length()) {
        for (int j = 0; j < n; j++) {
            if(plain.length()<j){
            cout<<plain.length()<<endl;
            mat[i][j]=' ';
        }
            else
            mat[i][j]=plain[i*n+j];
        }
        i+=1;
    }
    // for(int j=0;j<i;j++)
    // {
    //     for(int k=0;k<n;k++)
    //     cout<<mat[j][k]<<" ";
    //     cout<<endl;
    // }
    // cout<<i<<endl;
    int rows=i;
    string ans;
    for(char ch='a';ch<='z';ch++)
    {
        if(mp[ch]!=0){
            int position=mp[ch]-1;
            for(int i=0;i<=rows;i++)
            {
                ans.push_back(mat[i][position]);
            }
        }
    }
    cout<<ans<<endl;
}

void decrypt()
{
    // cout<<"hi"<<endl;
    cout<<endl;
    string cipher,key;
    getline(cin,cipher);
    // cout<<cipher<<endl;
    cin>>key;
    // cout<<key<<endl;
    int n=key.length();
    map<char,int>mp;
    for(int i=0;i<key.size();i++)
        mp[key[i]]=i+1;
    // cout<<mp['h']<<endl;
    char mat[100][100];
    int i=0;
    int c=0;
    int rows=cipher.size()/n;
    for(char ch='a';ch<='z';ch++)
    {
        if(mp[ch]!=0){
            c+=1;
            int position=mp[ch]-1;
            int st=(c-1)*rows;
            for(int i=st;i<st+rows;i++)
            {
                mat[i-st][position]=cipher[i];
            }
        }
    }

    string ans;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<n;j++)
        {
            // cout<<mat[i][j]<<" ";
            ans.push_back(mat[i][j]);
        }
        // cout<<endl;
    }
    cout<<ans<<endl;
    
}

int main()
{
    // encrypt();
    decrypt();
}

//geeks for geeks
// hack

//e  kefgsgsrekoe 
// hack