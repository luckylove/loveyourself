// you can do it now shubham
#include<bits/stdc++.h>
# define ll long long
using namespace std;
struct node
{
    ll pro;
    ll b;
};
bool compare(node n,node m)
{
    if(n.pro==m.pro)
    {
        return n.b<m.b;
    }
    return n.pro<m.pro;
}
ll findsome(node* product ,ll n, ll mid)
{
    int i,j;
    ll some=0;
    for(i=mid+1;i<n;i++)
    {
        some+=ceil((long double)(product[i].pro-product[mid].pro)/product[i].b);
    }
    return some;
}
void dofinalthings(node* product,ll n,ll mid,ll m)
{
    // dofinal things
   // cout<<"now we are in dofinalthings"<<endl;
   // cout<<"mid is "<<mid<<endl;
    ll countt=0;
    ll i,j;
    for(i=mid+1;i<n;i++)
    {
        countt=ceil((long double)(product[i].pro-product[mid].pro)/product[i].b);
                if(countt>=m)
                 {
                     product[i].pro=product[i].pro-(product[i].b)*m;
                     m=0;
                    // cout<<"m is converted to zero"<<m<<endl;
                     break;
                 }
                 else
                 {
                     product[i].pro=product[i].pro-(product[i].b)*countt;
                     m=m-countt;
                 }
    }
    // if still m is greater then m>0
    if(m>0)
    {
        //cout<<"m is "<<m<<endl;
        product[mid].pro=product[mid].pro-product[mid].b;
        m--;
        if(m>0)
        dofinalthings(product,n,mid,m);
    }
    return ;
}
void dosearch(node* product,ll n,ll start,ll endd,ll m)
{
    ll mid;
   while(start<=endd)
   {
        mid=start +(endd-start)/2;
       //cout<<"mid is "<<mid<<endl;
       ll some=findsome(product,n,mid);
      // cout<<"some that we get is "<<some<<endl;
       if(some>m)
       {
           // we need to just shipt right side
          // cout<<"shifting right side"<<endl;
           //dosearch(product,n,mid+1,endd,m);
           start=mid+1;
       }
       else if(some==m||mid==start)
       {
           // means we are getting the things
           dofinalthings(product,n,mid,m);
           return ;
       }
       else
       {
          // cout<<"shifging left side"<<endl;
           //dosearch(product,n,start,mid-1,m);
           endd=mid-1;
       }
   }

}
void dosomething(node* product ,ll start,ll endd)
{
    sort(product+start,product+endd+1,compare);
     dosearch(product,n,0,n-1,m);
}
int main()
{
    ll test,a,b,c,d,i,j,k,l,n,m;
    cin>>n>>m;
    ll arr[n];
    ll brr[n];
    node product[n];
    ll total=0;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        total+=arr[i];
    }
    for(i=0;i<n;i++)
    {
        cin>>brr[i];
        product[i].pro=arr[i]*brr[i];
        product[i].b=brr[i];
    }

   // cout<<"initially we get is "<<endl;
        for(i=0;i<n;i++)
        {
            //cout<<product[i].pro<<"    "<<product[i].b<<endl;
        }
    if(total<=m)
    {
        cout<<0<<endl;
    }
    else
    {
        dosomething(product,0,n-1);

        //cout<<"now we are again inthe main funciton"<<endl;
        ll maxx=0;
        for(i=0;i<n;i++)
        {
           // cout<<product[i].pro<<"    "<<product[i].b<<endl;
            maxx=max(maxx,product[i].pro);
        }
        cout<<maxx<<endl;

    }


}



