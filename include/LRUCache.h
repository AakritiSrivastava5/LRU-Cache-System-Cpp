#ifndef LRUCACHE_H
#define LRUCACHE_H

#include <unordered_map>
using namespace std;

class LRUCache{
    public:
    class node{
        public:
        int key,value;
        node* prev;
        node*next;
        node(int k,int v)
        {
            this->key=k;
            this->value=v;
            prev=next=nullptr;
        }
    };
    int capacity;
    unordered_map<int,node*>mpp;
    node*head;
    node*tail;

    int hits,misses,totalOps;
    LRUCache(int capacity);

    void addnode(node*newnode);
    void deletenode(node*delnode);

    int get(int key);
    void put(int key,int value);

    void showStats();
};
#endif