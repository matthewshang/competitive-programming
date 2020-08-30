struct dsu {
    vi par, szs;
    dsu(int n) : par(n), szs(n, 1) { iota(all(par), 0); }
    int size(int x) { return szs[find(x)]; }
    int find(int x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }
    bool join(int u, int v) {
        int a = find(u), b = find(v);
        if (a == b) return false;
        if (szs[a] < szs[b]) swap(a, b);
        par[b] = a;
        szs[a] += szs[b];
        return true;
    }
};
