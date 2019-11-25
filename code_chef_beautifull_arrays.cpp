#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef unsigned int ui;
typedef long long int ll;

int main()
{
    int t;
    cin>>t;
    while(t--){
        ui n,ones=0,zeros=0,flag=1;
        cin>>n;
        vector<int> v;
        for(ui i=0;i<n;i++)
            {
                ll val;
                cin>>val;
                if(val!=0 and val !=1)
                    v.push_back(val);
                else{
                    if(val==0)
                        ones=1;
                    if(val==1)
                        zeros=1;

                }

            }
        sort(v.begin(),v.end());
        for(auto i=v.rbegin();i!=v.rend();i++){
            for(auto j=i+1;j!=v.rend();j++){
                cout<<" i "<<*i<<" j "<<*j;
                if((((*i)*(*j))>(*(v.end()-1))) || (((*i)*(*j))<(*(v.begin())))){cout<<"breaking out of bounds\n";
                        flag=0;
                        break;
                }

                if(((*i)==(*j)) and !(zeros || ones)){cout<<"breaking equal\n";
                        flag=0;
                        break;}

            }
            if(!flag)
                break;
        }
        if(flag)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}
