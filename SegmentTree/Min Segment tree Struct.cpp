struct segmentTreeMin {
	vector<int> seg;
	vector<int> arr;
	segmentTreeMin(int n,int temp[]){
		seg.resize(4*n,0);
		arr.resize(4*n,0);
		for(int i=1;i<=n;i++){
			arr[i] = temp[i];
		}
	}
	void built_seg(int ind,int lo,int hi){
		if(lo == hi){
			seg[ind] = arr[lo];
			return;
		}
		int mid = (lo+hi)/2;
		built_seg(ind*2,lo,mid);
		built_seg(ind*2+1,mid+1,hi);
		seg[ind] = min(seg[ind*2],seg[ind*2+1]);
	}
	 
	int query(int ind,int lo,int hi,int l,int r){
		if(lo>r || hi<l || lo>hi) return INT_MAX;
		if(lo>=l && hi<=r){
			return seg[ind];
		}
		int mid = (lo+hi)/2;
		int left = query(ind*2,lo,mid,l,r);
		int right = query(ind*2+1,mid+1,hi,l,r);
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
				pointUpdate(ind*2,lo,mid,node,val);
			}
			else{
				pointUpdate(ind*2+1,mid+1,hi,node,val);
			}
			seg[ind] = min(seg[ind*2], seg[ind*2+1]);
		}
	}
	int query(int l, int r){
		return query(1,1,n,l,r);
	}
	void pointUpdate(int node, int val){
		pointUpdate(1,1,n,node,val);
	}
};
