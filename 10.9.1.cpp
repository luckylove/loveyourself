#include<bits/stdc++.h>
using namespace std;
int digitsum(long long int a)
{
    int sum=0;
    while(a!=0)
    {
        sum+=a%10;
        a=a/10;
    }
    return sum;
}
int main()
{
    long long int test,a,b,c,d,k,n,m;
    cin>>test;
    while(test--)
    {
        cin>>n>>d;
        set<long long int > vt;
        set<long long int > ans;
        vt.insert(n);
        int minn=n;
        int minindex=0;

        int countt=0;
        // now we are doing it again and again accordingly for it
        int index=20;
        int temp;
        // same elementes are repeated again and again accordingly for it
        // can we take the set i think yes
        set<long long int> lookup;
        lookup.insert(n);
        while(index>0)
        {
            countt++;
            for(auto i=vt.begin();i!=vt.end();i++)
            {
                temp=digitsum(*i);
                cout<<"*i "<<*i<<" temp is "<<temp<<endl;

                if(temp<minn)
                {
                    minn=temp;
                    minindex=countt;
                }
                if(ans.find(*i+d)==ans.end()&&lookup.find(*i+d)==lookup.end())
                {
                   ans.insert(*i+d);
                   lookup.insert(*i+d);
                }
                if(ans.find(temp)==ans.end()&&lookup.find(temp)==lookup.end())
                {
                    ans.insert(temp);
                     lookup.insert(temp);
                }
            }
            for(auto j=lookup.begin();j!=lookup.end();j++)
            {
                cout<<*j<<" ";
            }
            cout<<endl;
            cout<<endl;
            vt=ans;
            ans.clear();
            if(minn==1)
            {
                break;
            }
            index--;
            cout<<"min is "<<minn<<" min index is "<<minindex<<endl;
        }
        cout<<minn<<" "<<minindex<<endl;


    }
}



