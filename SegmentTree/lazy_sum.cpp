int ar[N];
int seg[4*N];
int lazy[4*N];
// 0 based index
void built_seg(int ind,int lo,int hi){
    if(lo == hi){
        seg[ind] = ar[lo];
        return;
    }
    int mid = (lo+hi)/2;
    built_seg(ind*2+1,lo,mid);
    built_seg(ind*2+2,mid+1,hi);
    seg[ind] = (seg[ind*2+1] + seg[ind*2+2]);
}

void rangeUpdate(int ind,int lo,int hi,int l,int r,int val){
    if(lazy[ind] != 0){
        seg[ind] += ((hi-lo)+1)*lazy[ind];
        if(hi != lo){
            lazy[ind*2+1] += lazy[ind];
            lazy[ind*2+2] += lazy[ind];
        }
        lazy[ind] = 0ll;
    }

    if(l>hi || r<lo || lo>hi) return;

    if(l<=lo && r>=hi){
        seg[ind] += (hi-lo+1)*val;
        if(lo != hi){
            lazy[ind*2+1] += val;
            lazy[ind*2+2] += val;
        }
        return;
    }

    int mid = (hi+lo) >> 1;
    rangeUpdate(ind*2+1,lo,mid,l,r,val);
    rangeUpdate(ind*2+2,mid+1,hi,l,r,val);
    seg[ind] = seg[ind*2+1]+seg[ind*2+2];
}

int lazyquery(int ind,int lo,int hi,int l,int r){
    if(lazy[ind] != 0){
        seg[ind] += (hi-lo+1)*lazy[ind];
        if(hi != lo){
            lazy[ind*2+1] += lazy[ind];
            lazy[ind*2+2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if(l>hi || r< lo) return 0;

    if(l<=lo && r>=hi){
        return seg[ind];
    }
    int mid = (lo+hi)/2;

    return lazyquery(ind*2+1,lo,mid,l,r)+lazyquery(ind*2+2,mid+1,hi,l,r);
}



int lazyquery(int l, int r){
    return lazyquery(0,0,n-1,l,r);
}
void rangeUpdate(int l,int r,int val){
    rangeUpdate(0,0,n-1,l,r,val);
}
