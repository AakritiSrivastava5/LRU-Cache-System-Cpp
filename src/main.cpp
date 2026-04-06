#include <iostream>
#include "LRUCache.h"
#include <sstream>

using namespace std;
int main()
{
    int capacity;
    cout<<" Enter capacity:"<<endl;
    cin>>capacity;
    cin.ignore();

    LRUCache cache(capacity);

    cout<<"Enter commands (put key value/ get key/display/stats/exit):"<<endl;
    string line;
    while(true)
    {
        cout<<" > "<<endl;
        getline(cin,line);
        if(line=="exit")
        {
            break;
        }
        stringstream ss(line);
        string command;
        ss>>command;
        
        if(command=="put")
        {
            int k,v;
            ss>>k>>v;
            cache.put(k,v);
            cout<<"Inserted\n";
        }
        else if(command=="get")
        {
            int k;
            ss>>k;
            int value=cache.get(k);
            if(value==-1)
            {
                cout<<"NOT FOUND\n";
            }
            else{
                cout<<"Value:"<<value<<endl;
            }
        }
        else if(command=="stats")
        {
            cache.showStats();
        }
    }
    return 0;
}