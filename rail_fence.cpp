#include<bits/stdc++.h>
using namespace std;

void encrypt()
{
    string plain;
    int key;
    getline(cin,plain);
    cin>>key;
    string ans;
    int d=(key-1)*2;
    for(int i=0;i<key;i++){
        if(i!=0)
        d-=2;
        if(d==0){
            d=(key-1)*2;
        }
        for(int j=i;j<plain.length();j+=d){
            ans.push_back(plain[j]);
        }
    }
    cout<<ans<<endl;
}

void decrypt()
{
    string cipher;
    int key;
    getline(cin,cipher);
    cin>>key;
    string ans;
    if (key == 1) cout<<cipher<<endl;
    map<int,vector<int>> mp;
    int edge=0,j=0;
    for(int i=0;i<cipher.length();i++) 
    {
        mp[j].push_back(i);
        if (i%(key-1)==0)
        edge^=1;
        if(edge)
        j+=1;
        else
        j-=1;
    }
    ans.resize(cipher.length());
    int k=0;
    for(int i=0;k<cipher.length() && i<key;i++) 
    {
        for(int j: mp[i]) 
        ans[j] = cipher[k++];
        // k+=1;
    }
    cout<<ans<<endl;
}

int main()
{
    // encrypt();
    decrypt();
}

//geeksforgeeks
// 3

//gsgsekfrekeoe 
// 3