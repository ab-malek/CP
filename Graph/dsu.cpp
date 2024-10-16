class DisjointSets {
  private:
	vector<int> parents;
	vector<int> sizes;
	int mxsizes = 0;
	int numberOfComponent = 0;

  public:
  	// pass n+1
	DisjointSets(int size){
		parents.resize(size,-1);
		sizes.resize(size,1);
		numberOfComponent = size;
		for (int i = 0; i < size; i++) { parents[i] = i; }
	}

	int find(int x) {
		return parents[x] == x ? x : (parents[x] = find(parents[x]));
	}

	bool unite(int x, int y) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) { return false; }

		if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
		sizes[x_root] += sizes[y_root];
		mxsizes = max(mxsizes, sizes[x_root]);
		parents[y_root] = x_root;
		numberOfComponent--;
		return true;
	}
	bool connected(int x, int y) { return find(x) == find(y); }
	int count(){ return numberOfComponent; };
};
