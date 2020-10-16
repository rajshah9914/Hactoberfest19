#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mxN=1e5+1;

void encrypt(){
    int v[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)
            v[i][j]=-1;
    }
    map<char,int>mp;
    mp['j'-'a']=1;
    string plain,key;
    cin>>plain>>key;
    int k=0,f=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            v[i][j]=key[k]-'a';
            mp[key[k]-'a']=1;
            k+=1;
            if(k==key.size()){
                f=1;
                break;
            }
        }
        if(f)
            break;
    }
    k=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(v[i][j]==-1) {
                if (!mp[k]) {
                    v[i][j] = k;
                    mp[k] = 1;
                    k += 1;
                } else {
                    while (mp[k])
                        k += 1;
                    v[i][j] = k;
                    mp[k] = 1;
                    k += 1;
                }
            }
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<(char)(v[i][j]+'a')<<" ";
        }
        cout<<endl;
    }
    vector<string>vv;
    if((plain.length()%2) !=0){
        plain.push_back('z');
    }
    for(int i=0;i<plain.length();i+=2){
        string s;
        s.push_back(plain[i]);
        s.push_back(plain[i+1]);
        vv.push_back(s);
    }
    string ans;
    for(int i=0;i<vv.size();i++){
        string st=vv[i];
        char a=st[0];
        char b=st[1];
        if(a=='j')
            a='i';
        if(b=='j')
            b='i';
        int ai,aj,bi,bj;
        f=0;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(v[i][j]==(a-'a')){
                    f=1;
                    ai=i;
                    aj=j;
                    break;
                }
            }
            if(f)
                break;
        }
        f=0;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(v[i][j]==(b-'a')){
                    f=1;
                    bi=i;
                    bj=j;
                    break;
                }
            }
            if(f)
                break;
        }

        if(ai==bi){
            char aa=(char)(v[ai][(aj+1)%5]+'a');
            char bb=(char)(v[ai][(bj+1)%5]+'a');
            ans.push_back(aa);
            ans.push_back(bb);
        }
        else if(aj==bj){
            char aa=(char)(v[(ai+1)%5][aj]+'a');
            char bb=(char)(v[(bi+1)%5][aj]+'a');
            ans.push_back(aa);
            ans.push_back(bb);
        }
        else{
//            cout<<ai<<" "<<aj<<" "<<bi<<" "<<bj<<endl;
            char aa=(char)(v[ai][bj]+'a');
            char bb=(char)(v[bi][aj]+'a');
            ans.push_back(aa);
            ans.push_back(bb);
        }
    }
    cout<<"Cipher Text is:-"<<endl;
    cout<<ans<<endl;
}

void decrypt(){
    int v[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)
            v[i][j]=-1;
    }
    map<char,int>mp;
    mp['j'-'a']=1;
    string cipher,key;
    cin>>cipher>>key;
    int k=0,f=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            v[i][j]=key[k]-'a';
            mp[key[k]-'a']=1;
            k+=1;
            if(k==key.size()){
                f=1;
                break;
            }
        }
        if(f)
            break;
    }
    k=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(v[i][j]==-1) {
                if (!mp[k]) {
                    v[i][j] = k;
                    mp[k] = 1;
                    k += 1;
                } else {
                    while (mp[k])
                        k += 1;
                    v[i][j] = k;
                    mp[k] = 1;
                    k += 1;
                }
            }
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<(char)(v[i][j]+'a')<<" ";
        }
        cout<<endl;
    }
    vector<string>vv;
    if((cipher.length()%2) !=0){
        cipher.push_back('z');
    }
    for(int i=0;i<cipher.length();i+=2){
        string s;
        s.push_back(cipher[i]);
        s.push_back(cipher[i+1]);
        vv.push_back(s);
    }
    string ans;
    for(int i=0;i<vv.size();i++){
        string st=vv[i];
        char a=st[0];
        char b=st[1];
        if(a=='j')
            a='i';
        if(b=='j')
            b='i';
        int ai,aj,bi,bj;
        f=0;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(v[i][j]==(a-'a')){
                    f=1;
                    ai=i;
                    aj=j;
                    break;
                }
            }
            if(f)
                break;
        }
        f=0;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(v[i][j]==(b-'a')){
                    f=1;
                    bi=i;
                    bj=j;
                    break;
                }
            }
            if(f)
                break;
        }

        if(ai==bi){
            char aa=(char)(v[ai][(aj-1+5)%5]+'a');
            char bb=(char)(v[ai][(bj-1+5)%5]+'a');
            ans.push_back(aa);
            ans.push_back(bb);
        }
        else if(aj==bj){
            char aa=(char)(v[(ai-1+5)%5][aj]+'a');
            char bb=(char)(v[(bi-1+5)%5][aj]+'a');
            ans.push_back(aa);
            ans.push_back(bb);
        }
        else{
//            cout<<ai<<" "<<aj<<" "<<bi<<" "<<bj<<endl;
            char aa=(char)(v[ai][bj]+'a');
            char bb=(char)(v[bi][aj]+'a');
            ans.push_back(aa);
            ans.push_back(bb);
        }
    }
    cout<<"Plain Text is:-"<<endl;
    cout<<ans<<endl;
}

signed main(){
    int t;
    int ch;
    cout<<"1. Encryption    2. Decryption.."<<endl;
    cin>>ch;
    switch(ch){
        case 1: encrypt();
        break;
        case 2: decrypt();
        break;
    }

}


//1
//instruments
//monarchy

//2
//gatlmzclrqtx
//monarchy

