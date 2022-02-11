#include<bits/stdc++.h>
#define debug(x) printf("-----------------%d\n",x);
#define LEN sizeof(a)/sizeof(a[0])
#define MEM(arr,k) memset(arr,k,sizeof arr)
#define input freopen("01input.txt","r",stdin)
#define output freopen("01output.txt","w",stdout)
#define go ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
using namespace std;
 
int X8[] = {0, 1, 0, -1, 1, -1, 1, -1};
int Y8[] = {1, 0, -1, 0, 1, -1, -1, 1};
int X4[] = {1, -1, 0, 0};
int Y4[] = {0, 0 , 1, -1};

int arr[100000],t[100000];

void build(int arr[],int index, int tl, int tr){
    if(tl==tr){
        t[index] = arr[tl];
    }   
    else{
        int tmid = (tl + tr)/2;
        build(arr,index*2,tl,tmid);
        build(arr,index*2+1,tmid+1,tr);
        t[index] = t[index*2] + t[index*2+1];
    }
}

int sum(int index, int tl, int tr, int l, int r){
    if(l>r)
        return 0;
    if(l == tl && r==tr){
        return t[index]; 
    }
    int tmid = (tl + tr)/2;
    return sum(index*2, tl, tmid,l,min(r,tmid)) + 
        sum(index*2+1,tmid+1,tr,max(l,tmid+1),r);
}

void update(int index, int tl, int tr, int pos, int new_val){
    if(tl == tr){
        t[index] = new_val;
    }
    else{
        int tmid = (tl + tr)/2;
        if(pos <= tmid){
            update(index*2,tl,tmid,pos,new_val);
        }
        else{ 
            update(index*2+1,tmid+1,tr,pos,new_val);
        }
        t[index] = t[index*2] + t[index*2+1];
    }
}

int main(){
    build(arr,1,0,3);
    cout<<sum(1,0,3,1,3);
    update(1,0,3,1,4);
    cout<<sum(1,0,3,1,3);
}

