#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

/*
class Node{
public:
    Node(int k, int v):key(k),value(v) {}
    int key;
    int value;
};

class LRUCache {
public:
    LRUCache(int capacity):cpcty(capacity) {}

    int get(int key) {
        if(l.empty())return -1;
        for(auto it = l.begin(); it != l.end(); ++it){
            if((*it).key == key){
                Node tmp((*it).key, (*it).value);
                l.erase(it);
                l.push_back(tmp);
                return tmp.value;
            }
        }
        return -1;
    }

    void put(int key, int value) {
        Node tmp(key, value);
        if(get(key) != -1){
            for(auto it = l.begin(); it != l.end(); ++it){
                if((*it).key == key){
                    l.erase(it);
                    break;
                }
            }
        }
        else{
            if(!l.empty()&&(int)l.size() == cpcty){
                //cout << value << ' ' << l.front().value <<endl;
                l.pop_front();
            }
        }
        l.push_back(tmp);
    }

    void out_put()
    {
        for(auto e:l)
        {
            cout << e.key << ' ' << e.value << '|';
        }
        cout << endl;
    }
    list<Node> l;
private:
    int cpcty;
};
*/

class LRUCache {
public:
    LRUCache(int capacity):cpcty(capacity) {}

    int get(int key) {
        auto it = umap.find(key);
        if(it == umap.end()){
            return -1;
        }
        else{
            pair<int,int> tmp = make_pair(key, it->second->second);
            l.erase(it->second);
            l.push_back(tmp);
            return tmp.second;
        }
    }

    void put(int key, int value) {
        if(get(key) != -1){
            int del = l.back().first;
            umap.erase(del);
            l.pop_back();
        }
        if((int)l.size() == cpcty){
            int del = l.front().first;
            umap.erase(del);

            l.pop_front();
        }

        l.push_back(make_pair(key, value));
        for(auto it = l.begin(); it != l.end(); ++it){
            if(it->first == key){
                umap.insert(make_pair(key, it));
                break;
            }
        }
    }

    void out_put()
    {
        for(auto e:l){
            cout << e.first << ' ' << e.second << '|';
        }
        cout << endl;
    }

private:
    int cpcty;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> umap;    
};


int main()
{
    LRUCache cache(2);
    cache.put(2,1);
    cache.out_put();
    cache.put(2,2);
    cache.out_put();
    cout << cache.get(2) << endl;
    cache.put(1,1);
    cache.out_put();
    cache.put(4,1);
    cache.out_put();
    cout << cache.get(2) << endl;
    return 0;
}

