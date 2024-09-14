#include<iostream>
#include<bits/stdc++.h>
using namespace::std;

class DisjointSet{
    vector<int> rank, parent, size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    int findPar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findPar(parent[node]);
    }
    void unionRank(int x, int y){
        int px=findPar(x);
        int py=findPar(y);
        if(px==py) return;
        else if(rank[px]<rank[py]){
            parent[px]=py;
        }
        else if(rank[px]>rank[py]){
            parent[py]=px;
        }
        else{
            parent[py]=px;
            rank[px]++;
        }
        
    }
    void unionSize(int x, int y){
        int px=findPar(x);
        int py=findPar(y);
        if(px==py) return;
        else if(size[px]<size[py]){
            parent[px]=py;
            size[py]=size[px]+size[py];
        }
        else{
            parent[py]=px;
            size[px]=size[px]+size[py];
        }
    }
};

int main(){
    DisjointSet ds(7);
    cout<<ds.findPar(3)<<endl;
    ds.unionSize(1,7);
    ds.unionSize(2,7);
    ds.unionSize(6,4);
    ds.unionSize(3,1);
    ds.unionSize(1,4);
    cout<<ds.findPar(5)<<" "<<ds.findPar(6);
    return 0;
}