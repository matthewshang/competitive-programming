template <typename F>
int first_true(int low, int high, F pred) {
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (pred(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

template <typename F>
int last_true(int low, int high, F pred) {
    while (low < high) {
        int mid = low + (high - low + 1) / 2;
        if (pred(mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    return low;
}
