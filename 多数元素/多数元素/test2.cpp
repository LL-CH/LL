#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int main(){
    string str;
    while(getline(cin,str)){
        vector<int> v;
        for(size_t i=0;i<str.size();i++){
            if(str[i]!=' ')
             v.push_back(str[i]-'0');
        }
        map<int,int> mi;
        for(auto e:v){
            mi[e]++;
        }
        int ret=v[0];
        for(size_t i=0;i<v.size();i++){
            if(mi[v[i]]>mi[ret])
                ret=v[i];
        }
        cout<<ret<<endl;
    }
    
    return 0;
}