#include<iostream>
#include<bits/stdc++.h>
using namespace::std;

class SegmentTree{
    vector<int> seg;
    public:
    SegmentTree(int n){
        seg.resize(4*n+1,INT_MAX);
    }
    void build(vector<int> &arr,int ind, int low, int high){
        if(low==high) {
            seg[ind]=arr[low];
            return;
        }
        int mid=low+(high-low)/2;
        build(arr, 2*ind+1, low, mid);
        build(arr, 2*ind+2, mid+1,high);
        seg[ind]=min(seg[2*ind+1], seg[2*ind+2]);
    }
    int queryMin(int ind, int low, int high, int l, int r){
        if(r<low || l>high) return INT_MAX;
        if(l<=low && r>=high) return seg[ind];
        int mid=low+(high-low)/2;
        int left=queryMin(2*ind+1, low, mid, l,r);
        int right=queryMin(2*ind+2, mid+1, high, l,r);
        return min(left, right);
    }

    void update(int ind, int low, int high, int i, int val){
        if(low==high){
            seg[ind]=val;
            return;
        }
        int mid=low+(high-low)/2;
        if(i<=mid) update(2*ind+1, low, mid, i, val);
        else update(2*ind+2,mid+1, high, i, val);
        seg[ind]=min(seg[2*ind+1], seg[2*ind+2]);

    }
    
};

// int main(){
//     vector<int> arr;
//     arr.push_back(6);
//     arr.push_back(2);
//     arr.push_back(5);
//     arr.push_back(1);
//     arr.push_back(2);
//     arr.push_back(2);
//     SegmentTree st(6);
//     st.build(arr,0,0,5);
//     st.update(0,0,5,3,3);
//     cout<<st.queryMin(0,0,5,0,3)<<endl;
//     st.update(0,0,5,3,0);
//     cout<<st.queryMin(0,0,5,0,3);
//     return 0;
// }