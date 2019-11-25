#include<iostream>
#include<string>
#include<math.h>
#include<vector>


typedef unsigned int ui;
typedef long long int ll;
using namespace std;
#define endl "\n"


int main(){

ll T;
cin>>T;
cin.ignore();
while(T--){
    bool flag=1;
    string grid;
    getline(cin,grid);
    ui len=grid.length();
    ui i=0;
    while(i<=len){
	if(grid[i]!='.'){
            ui num=(int)grid[i]-48;
            ui id=i;
            i++;
            while(grid[i]=='.'){
                i++;
            }
            if(i>=len)
                break;
            if((id+num)>=(i-((int)grid[i]-48))){
                flag=0;
                break;
            }
	}
        else
            i++;

    }
    if(flag==1)
        cout<<"safe\n";
    else
        cout<<"unsafe\n";


}

return 0;

}
