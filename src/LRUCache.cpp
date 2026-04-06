
#include <iostream>
#include "LRUCache.h"

using namespace std;
LRUCache::LRUCache(int capacity)
{
    this->capacity=capacity;
    head=new node(-1,-1);
    tail=new node(-1,-1);
    head->next=tail;
    tail->prev=head;
    hits=0,misses=0,totalOps=0;
}
void LRUCache::addnode(node*newnode)
{
    node*temp=head->next;
    newnode->next=temp;
    temp->prev=newnode;
    head->next=newnode;
    newnode->prev=head;
}
void LRUCache::deletenode(node*delnode)
{
    node*delprev=delnode->prev;
    node*delnext=delnode->next;
    delprev->next=delnext;
    delnext->prev=delprev;
}
int LRUCache::get(int key)
{
    totalOps++;
    if(mpp.find(key)!=mpp.end())
    {
        node*resnode=mpp[key];
        int res=resnode->value;
        deletenode(resnode);
        addnode(resnode);
        hits++;
        return res;
    }
    misses++;
    return -1;
}
void LRUCache::put(int key,int value)
{
    totalOps++;

    // Remove if key already exists
    if(mpp.find(key) != mpp.end())
    {
        node* existingnode = mpp[key];
        deletenode(existingnode);
        delete existingnode;
        mpp.erase(key);
    }

    // Evict LRU if cache is full
    if(mpp.size() == capacity)
    {
        node* lru = tail->prev;   // store LRU
        deletenode(lru);          // unlink from list
        mpp.erase(lru->key);      // remove from map
        delete lru;               // free memory
    }

    // Add new node at front
    node* newnode = new node(key,value);
    addnode(newnode);
    mpp[key] = newnode;
}

void LRUCache::showStats()
{
    cout<<"Total Operations:"<<totalOps<<endl;
    cout<<"Hits:"<<hits<<endl;
    cout<<"Misses:"<<misses<<endl;
    if(totalOps>0)
    {
       double hitrate=(double)hits/totalOps*100;
       cout<<"Hit Rate: "<<hitrate<<"%\n";
    }
}