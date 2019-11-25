#include<iostream>

using namespace std;
typedef unsigned int ui;
typedef long long int ll;

int main(){
    ui t;
    cin>>t;
    while(t--){
        ll n,k,a,b,Val;

        cin>>n>>k;

        ll *arr=new ll[n];

        ll Mul,C;
        bool flag=0;
        if((n%2!=0) && k>n){
            arr[n/2]=0;
            flag=1;}
        Mul=(k/n)%3;

        C=k%n;

        k= C>0 ? C:0;


        for(ll i=0;i<n;i++){
            cin>>Val;
            if(i<(n/2))
                arr[i]=Val;
            else{
                if(Mul==2){
                    arr[n-i-1]=arr[n-i-1]^Val;
                    arr[i]=arr[n-i-1]^Val;
                    arr[n-i-1]^=arr[i];
                    arr[i]^=arr[n-i-1];

                }
                else if(Mul==1){
                    arr[n-i-1]=arr[n-i-1]^Val;
                    arr[i]=arr[n-i-1]^Val;
                }
                else{
                    arr[i]=Val;
                }
            }
        }


        if(k>0){
        for(ll i=0;i<k;i++){
            Val=arr[i];


            arr[i]=arr[n-i-1]^Val;


                }
            }


        if(flag==1){
            arr[n/2]=0;
        }

        //cout<<"array after constant  of "<<k<<"\n";
        for(ll i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<"\n";

    }
    return 0;
}
