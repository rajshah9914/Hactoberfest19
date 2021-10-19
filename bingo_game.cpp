#include<bits/stdc++.h>
using namespace std;
int a[5][5],b[5][5],i,j,k,c=0,co[25],m1[25][25]={{0}},m2[25][25]={{0}},f=0,max1,max2;
void find(int k)
{
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(a[i][j]==k)
            m1[i][j]=1;
            if(b[i][j]==k)
            m2[i][j]=1;
        }
    }
}
 
void findmax()
{
    int maxr1=0,maxr2=0;
    for(i=0;i<5;i++)
    {
        int row1=0,row2=0;
        for(j=0;j<5;j++)
        {
            row1+=m1[i][j];
            row2+=m2[i][j];
        }
        maxr1=max(row1,maxr1);
        maxr2=max(row2,maxr2);
    }
    
    int maxc1=0,maxc2=0;
    for(i=0;i<5;i++)
    {
        int col1=0,col2=0;
        for(j=0;j<5;j++)
        {
            col1+=m1[j][i];
            col2+=m2[j][i];
        }
        maxc1=max(col1,maxc1);
        maxc2=max(col2,maxc2);
    }
    
    int maxdl1=0,maxdl2=0;
    int col1=0,col2=0;
    for(i=0;i<5;i++)
    {
        col1+=m1[i][i];
        col2+=m2[i][i];
    }
    maxdl1=max(col1,maxdl1);
    maxdl2=max(col2,maxdl2);
    
    int maxdr1=0,maxdr2=0;
    col1=0;
    col2=0;
    for(i=0;i<5;i++)
    {
        col1+=m1[i][4-i];
        col2+=m2[i][4-i];
    }
    maxdr1=max(col1,maxdr1);
    maxdr2=max(col2,maxdr2);
    
    max1=max(max(max(maxdr1,maxdl1),maxc1),maxr1);
    max2=max(max(max(maxdr2,maxdl2),maxc2),maxr2);
    cout<<max1<<" "<<max2<<endl;
    if(max1==5)
    {
        f=1;
        cout<<"I Won!"<<endl;
    }
    else if(max2==5)
    {
        f=1;
        cout<<"You won -_-"<<endl;
    }
    else if(max1==5 && max2==5)
    {
        f=1;
        cout<<"It's a tie!"<<endl;
    }
}
 
int main()
{
    
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            cin>>a[i][j];
        }
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            cin>>b[i][j];
        }
    }
    for(j=0;j<25;j++)
    {
        cin>>co[j];
        if(f==0)
        {
            find(co[j]);
            findmax();
        }
        else 
        break;
    }
}