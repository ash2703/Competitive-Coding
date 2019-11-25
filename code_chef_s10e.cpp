#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

void showdq(deque <int> g,int *arr,int Size,auto& Min)
{
    deque <int> :: iterator it;
    cout << "queue \n";
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << "\narray; \n";
    for(int i=0;i<Size;i++)
        cout<<arr[i]<<"\t";
    cout << "\nminimum  :"<<Min<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned int t;
    cin>>t;
    while(t){
    int Size,val,good=0;
    int Min;
    cin>>Size;
    deque<int> dq;
    dq.push_back(INT_MAX);
    int *arr=new int[Size];
    for(int i =0;i<Size;i++){
        cin>>arr[i];
        }
    unsigned int i=0;
    while(i<Size){
        Min=*min_element(dq.begin(),dq.end());
        if (arr[i] < Min){
            cout<<"incrementing for "<<arr[i]<<" when min is "<<Min<<"\n";
            good++;}
        showdq(dq,arr,Size,Min);
        dq.push_back(arr[i]);
        if (dq.size()>5)
            dq.pop_front();
        i++;
    }
    showdq(dq,arr,Size,Min);
    delete []arr;
    dq.clear();
    cout<<"answer  :"<<good<<"\n";
    t--;

    }
    return 0;
}
