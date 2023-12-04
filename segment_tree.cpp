void built_seg(int ind,int lo,int hi){

	if(lo == hi){
		seg[ind] = v[lo];
		return;
	}
	int mid = (lo+hi)/2;
	built_seg(ind*2+1,lo,mid);
	built_seg(ind*2+2,mid+1,hi);
	seg[ind] = seg[ind*2+1]+seg[ind*2+2];
}

int query(int ind,int lo,int hi,int l,int r){
	if(lo>=l && hi<=r){
		return seg[ind];
	}
	if(lo>r || hi<l) return 0;
	int mid = (lo+hi)/2;
	int left = query(ind*2+1,lo,mid,l,r);
	int right = query(ind*2+2,mid+1,hi,l,r);
	return left+right;
}

void pointUpdate(int ind,int lo,int hi,int node,int val){
	if(lo == hi){
		seg[ind] += val;
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
		seg[ind] = seg[ind*2+1]+seg[ind*2+2];
	}
}

void rangUpdate(int ind,int lo,int hi,int l,int r,int val){
	if(lazy[ind] != 0){
		seg[ind] += ((hi-lo)+1)*lazy[ind];
		if(hi != lo){
			lazy[ind*2+1] += lazy[ind];
			lazy[ind*2+2] += lazy[ind];
		}
		lazy[ind] = 0;
	}

	if(l>hi || r<lo || lo>hi) return;

	if(l<=lo && r>=hi){
		seg[ind] += (hi-lo+1)*val;
		if(lo != hi){
			lazy[ind*2+1] = val;
			lazy[ind*2+2] = val;
		}
		return;
	}

	int mid = (hi+lo) >> 1;
    rangUpdate(ind*2+1,lo,mid,l,r,val);
    rangUpdate(ind*2+2,mid+1,hi,l,r,val);
    seg[ind] = seg[ind*2+1]+seg[ind*2+2];

}

int lazySum(int ind,int lo,int hi,int l,int r){
	if(lazy[ind] != 0){
		seg[ind] += (hi-lo+1)*lazy[ind];
		if(hi != lo){
			lazy[ind*2+1] = lazy[ind];
			lazy[ind+2+2] = lazy[ind];
		}
	}
	if(l>hi || r< lo) return 0;

	if(l>=lo && r<=hi){
		return seg[ind];
	}
	int mid = (lo+hi)/2;

	return lazySum(ind*2+1,lo,mid,l,r)+lazySum(ind*2+2,mid+1,hi,l,r);
}
