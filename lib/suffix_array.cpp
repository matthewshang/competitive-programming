struct suffix_array {
public:
    int n;
    vector<int> sa; // sa[i] = starting position of i-th suffix in lexicographical order
    vector<int> rank; // rank[i]: the i-th suffix is in the rev[i]-ith lexicographically smallest suffix

    suffix_array() {}

    template <typename String>
    static suffix_array build(const String& s) {
        int n = s.size();
        suffix_array sa(n);
        sa.build_sa(s);
        return sa;
    }

    template <typename String>
    void build_sa(const String& s) {
        int sigma = *max_element(s.begin(), s.end()) + 1;
        sa.resize(n);
        rank.resize(n);
        vector<int> freq(max(n, sigma * 2));
        vector<int> sa_tmp(n);
        vector<int> rank_tmp(n);

        for (int i = 0; i < n; i++)
            rank[i] = int(s[i]);
        iota(sa.begin(), sa.end(), 0); // initial SA: {0, 1, 2, ..., n-1}
        for (int k = 1; k < n; k <<= 1) { // repeat sorting process log n times
            counting_sort(k, sigma, freq, sa_tmp); // actually radix sort: sort based on the second item
            counting_sort(0, sigma, freq, sa_tmp); // then (stable) sort based on the first item
            rank_tmp[sa[0]] = 0; // re-ranking; start from rank r = 0
            int classes = 0;
            for (int i = 1; i < n; i++) { // compare adjacent suffixes
                // if same pair => same rank r; otherwise, increase classes
                pair<int, int> cur = { rank[sa[i]], rank[(sa[i] + k) % n] };
                pair<int, int> pre = { rank[sa[i - 1]], rank[(sa[i - 1] + k) % n] };
                if (cur != pre)
                    ++classes;
                rank_tmp[sa[i]] = classes;
            }
            swap(rank, rank_tmp); // update the rank array RA
            if (rank[sa[n - 1]] == n - 1) 
                break; // nice optimization trick
        }
    }

private:
    explicit suffix_array(int n_) : n(n_) {}

    void counting_sort(int k, int sigma, vector<int>& freq, vector<int>& sa_tmp) {
        const int maxi = max(sigma, n);
        fill(freq.begin(), freq.begin() + maxi, 0);
        for (int i = 0; i < n; i++) { // count the frequency of each integer rank
            freq[rank[(i + k) % n]]++;
        }
        int sum = 0;
        for (int i = 0; i < maxi; i++) {
            int t = freq[i];
            freq[i] = sum;
            sum += t;
        }
        for (int i = 0; i < n; i++) { // shuffle the suffix array if necessary
            sa_tmp[freq[rank[(sa[i] + k) % n]]++] = sa[i];
        }
        swap(sa, sa_tmp); // update the suffix array SA
    }
};
