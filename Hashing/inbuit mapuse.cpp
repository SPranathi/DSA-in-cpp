#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string,int> ourmap;
    //insert
    pair<string,int> p("abc",1);
    ourmap.insert(p);
    ourmap["def"]=2;

    //find or access 
    cout<<ourmap["abc"]<<endl;
    cout<<ourmap.at("abc")<<endl;
    cout<<ourmap.size()<<endl;
    cout<<ourmap["ghi"]<<endl;
    cout<<ourmap.size()<<endl;

    //check Presence
    if(ourmap.count("ghi")>0){
        cout<<"ghi is present"<<endl;
    }

    //erase
    ourmap.erase("ghi");
    if(ourmap.count("ghi")>0){
        cout<<"ghi is present"<<endl;
    }
    cout<<ourmap.size()<<endl;
}
