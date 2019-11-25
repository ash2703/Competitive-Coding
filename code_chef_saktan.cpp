#include<iostream>
#include<unordered_map>
#include<numeric>
using namespace std;
typedef unsigned int ui;
typedef long long int ll;
#define endl "\n"
int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    ll T;
    cin>>T;
    while(T--){
        unordered_map<ll,ll> row,col;
        ll Q,N,M;
        ll x,y,odd_Count;
        cin>>N>>M>>Q;
        for(ll i=0;i<Q;i++){
            cin>>x>>y;
            col[y]++;
            row[x]++;
            col[y]%=2;
            row[x]%=2;


        }

        

        ll or_count=0,oc_count=0;
        or_count=accumulate(row.begin(),row.end(),or_count,[](size_t prev,const pair<int,int>& a){
                            return prev+a.second;
            });
        oc_count=accumulate(col.begin(),col.end(),oc_count,[](size_t prev,const pair<int,int>& a){
                            return prev+a.second;
            });
        odd_Count=((N-or_count)*oc_count)+(or_count*(M-oc_count));
        cout<<odd_Count<<endl;
    }
    return 0;
}