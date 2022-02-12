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

int arr[1000000],t[1000000];

void build(int arr[],int index, int tl, int tr){
    if(tl>tr){
        return;
    }
    if(tl==tr){
        t[index] = arr[tl]; 
    }   
    else{
        int tmid = (tl + tr)/2;
        build(arr,index*2+1,tmid+1,tr);
        build(arr,index*2,tl,tmid);
        t[index] = min(t[index*2] ,t[index*2+1] );
    }
}

int query(int index, int tl, int tr, int l, int r){
    if(r<tl || l>tr || tl>tr){
        return INT_MAX;
    }
    if(l<=tl && r>=tr){
        return t[index];
    }
    else{
        int tmid = (tl + tr)/2;
        return min(query(index*2,tl,tmid,l,r),query(index*2+1,tmid+1,tr,l,r));
    }
}


int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    build(arr,1,0,n-1);

    int q;
    scanf("%d",&q);
    while(q--){
        int l,r;
        scanf("%d %d",&l,&r);
        cout<<query(1,0,n-1,l,r)<<endl;
    }
}

