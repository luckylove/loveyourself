#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node
{
    ll x;
    ll y;
};
int main()
{
    ll test,i,j,k,n,m,a,b,c,d;
    cin>>test;
    while(test--)
    {
        cin>>n>>m;
        ll arr[n][m];
        vector<struct node> some;
        struct node temp;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>arr[i][j];
                if(arr[i][j]==1)
                {
                    temp.x=i;
                    temp.y=j;
                    some.push_back(temp);
                }
            }
        }
        ll distance[m+n-1]={0};

        int ss=some.size();
        int store;
        for(i=0;i<ss;i++)
        {
            for(j=i+1;j<ss;j++)
            {
                store = abs(some[i].x-some[j].x)+abs(some[i].y-some[j].y);
                if(store<n+m-1)
                {
                    distance[store]++;
                }
            }
        }
        for(i=1;i<n+m-1;i++)
        {
            cout<<distance[i]<<" ";
        }
        cout<<endl;
    }
}
