// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<vector<char>> keyboard = {
        {'q','w','e','r','t','y','u','i','o','p'},
        {'a','s','d','f','g','h','j','k','l',';'},
        {'z','x','c','v','b','n','m',',','.','/'}
    };
    
    char shift;
    cin>>shift;
    string moleMsg;
    cin>>moleMsg;
    
    for(int i=0 ; i<moleMsg.size() ; i++){
        char ch = moleMsg[i];
        for(auto v : keyboard){
            for(int j=0 ; j<v.size() ; j++){
                if(v[j] == ch && shift == 'R'){
                    moleMsg[i] = v[j-1];
                }else if(v[j] == ch && shift == 'L'){
                    moleMsg[i] = v[j+1];
                }
            }
        }
    }
    
    cout<<moleMsg;
    

    return 0;
}