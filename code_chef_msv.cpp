#include<iostream>
#include<set>
#include<vector>
using namespace std;
typedef unsigned int ui;

template<class InputIterator, class T>
InputIterator Find (InputIterator first, InputIterator last, const T& val)
{
  while (last!=first) {
    if (*last==val) return last;
    --last;
  }
  return first;
}

template<typename Container>
void show(const Container& data){
    typename Container::iterator beg = data.begin();
    for(beg;beg!=data.end();beg++)
        cout<<*beg<<"\t";
    cout<<"\n";
    }



int main(){
    int t;
    cin>>t;
    while(t--){
        ui Size,Count=0,Max_Count=0;
        int val;
        cin>>Size;
        vector<int> arr;
        for(ui i=0;i<Size;i++){
            cin>>val;
            arr.push_back(val);}
        if(Size<=7){
            for(ui i=1;i<Size;i++){
                for(ui j=0;j<i;j++){
                    if(arr[j]%arr[i]==0)
                        Count++;
                }
                if(Count>Max_Count)
                    Max_Count=Count;
                Count=0;
            }

            cout<<"\nanswer  "<<Max_Count<<"\n";

        }
        else{
            set<int> s(arr.begin(),arr.end());
            ui Set_Size=s.size();
            ui looped=0;
            ui brk= Set_Size>100?100:Set_Size;

            cout<<"vector  ";
            for(auto i:arr)
                cout<<i<<" ";
            cout<<"\nset  ";
            show(s);
            for(auto i:s){
                auto it=Find(arr.begin(),arr.end(),i);
                cout<<i<<" found in array \n";
                for(auto it1=arr.begin();it1!=it;it1++){
                    if (((*it1)%(*it))==0){
                        Count++;
                        }
                }
                cout<<"count is : "<<Count<<"\n";
                if(Count>Max_Count)
                    Max_Count=Count;
                Count=0;
                looped++;

                if(looped>brk){
                    cout<<"breaking\n";
                    break;}

            }
            cout<<"\nanswer  "<<Max_Count<<"\n";
        }

    }

    return 0;
}
