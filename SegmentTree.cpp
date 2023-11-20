#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    using ll = long long int;
    const int MAXN = 3e6 + 10;
    vector<ll> arr;
    vector<ll> seg;
    vector<ll> lazy;

public:
    SegmentTree(ll n, const vector<ll>& input) : arr(input), seg(4 * n), lazy(4 * n) {
        build(0, 0, n - 1);
    }

    void update(ll ind, ll low, ll high, ll node, ll val) {
        if (low == high) {
            seg[ind] = val;
            return;
        } else {
            ll mid = (low + high) / 2;
            if (node >= low && node <= mid) {
                update(2 * ind + 1, low, mid, node, val);
            } else {
                update(2 * ind + 2, mid + 1, high, node, val);
            }
            seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
        }
    }

    void rangeUpdate(int ind, int low, int high, int l, int r, int val) {
        if (lazy[ind] != 0) {
            seg[ind] += (high - low + 1) * lazy[ind];
            if (low != high) {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        if (high < l || low > r) return;
        if (low >= l && high <= r) {
            seg[ind] += (high - low + 1) * val;
            if (low != high) {
                lazy[2 * ind + 1] += val;
                lazy[2 * ind + 2] += val;
            }
            return;
        }
        int mid = (low + high) / 2;
        rangeUpdate(2 * ind + 1, low, mid, l, r, val);
        rangeUpdate(2 * ind + 2, mid + 1, high, l, r, val);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    ll lazyQuerySum(int ind, int low, int high, int l, int r) {
        if (lazy[ind] != 0) {
            seg[ind] += (high - low + 1) * lazy[ind];
            if (low != high) {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        if (high < l || low > r) return 0;
        if (low >= l && high <= r) return seg[ind];
        int mid = (low + high) / 2;
        ll left = lazyQuerySum(2 * ind + 1, low, mid, l, r);
        ll right = lazyQuerySum(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }

    ll query(ll ind, ll low, ll high, ll l, ll r) {
        if (low >= l && high <= r) return seg[ind];
        if (high < l || low > r) return 0;
        ll mid = (low + high) / 2;
        ll left = query(2 * ind + 1, low, mid, l, r);
        ll right = query(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }

    void build(ll ind, ll low, ll high) {
        if (low == high) {
            seg[ind] = arr[low];
            return;
        }
        ll mid = (low + high) / 2;
        build(2 * ind + 1, low, mid);
        build(2 * ind + 2, mid + 1, high);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
};

int main() {
    ll n, q;
    cin >> n >> q;
    vector<ll> input(n);
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }

    SegmentTree segmentTree(n, input);

    while (q--) {
        ll a;
        cin >> a;
        if (a == 1) {
            int l, r, val;
            cin >> l >> r >> val;
            segmentTree.rangeUpdate(0, 0, n - 1, l - 1, r - 1, val);
        } else {
            ll b, c;
            cin >> b >> c;
            cout << segmentTree.query(0, 0, n - 1, b - 1, c - 1) << endl;
        }
    }

    return 0;
}
