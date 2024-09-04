int seg[4*N];
// 0 based index
void built_seg(int ind,int lo,int hi){
    if(lo == hi){
        seg[ind] = ar[lo];
        return;
    }
    int mid = (lo+hi)/2;
    built_seg(ind*2+1,lo,mid);
    built_seg(ind*2+2,mid+1,hi);
    seg[ind] = min(seg[ind*2+1],seg[ind*2+2]);
}
     
int query(int ind,int lo,int hi,int l,int r){
    if(lo>r || hi<l || lo>hi) return INT_MAX;
    if(lo>=l && hi<=r){
         return seg[ind];
    }
    int mid = (lo+hi)/2;
    int left = query(ind*2+1,lo,mid,l,r);
    int right = query(ind*2+2,mid+1,hi,l,r);
    return min(left, right);
}
     
void pointUpdate(int ind,int lo,int hi,int node,int val){
    if(lo == hi){
        seg[ind] = val;
        return ;
    }
    else{
        int mid = (lo+hi) >> 1;
        if(node<=mid && node>=lo){
            pointUpdate(ind*2+1,lo,mid,node,val);
        }
        else{
            pointUpdate(ind*2+2,mid+1,hi,node,val);
        }
        seg[ind] = min(seg[ind*2+1], seg[ind*2+2]);
    }
}

int query(int l, int r){
    return query(0,0,n-1,l,r);
}
void pointUpdate(int node, int val){
    pointUpdate(0,0,n-1,node,val);
}
