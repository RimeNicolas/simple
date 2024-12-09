// Binary Indexed Tree (Fenwick tree)
class BIT {
    private:
        std::vector<int> data;
    public:
        BIT(const std::vector<int>& v) : data(v.size()+1) {
            for (size_t i(0); i < v.size(); i++) {
                insert(i+1, v[i]);
            }
        }

        void insert(int idx, const int val) {
            while (idx < data.size()) {
                data[idx] += val;
                idx += idx & (-idx);
            }
        }

        int rsq(const int l, const int r) const {
            return getSum(r) - getSum(l);
        }

        int getSum(const int i) const {
            int val(0);
            int idx(i);
            while(idx != 0) {
                val += data[idx];
                idx -= idx & (-idx);
            }
            return val;
        }

        std::string repr() const {
            const std::string sep = " | ";
            std::string repr;
            std::string el;
            std::unordered_map<int,std::string> idx_list;
            int idx(0);

            for (int i(1); i < data.size(); i++) {
                idx = i;
                while (idx < data.size()) {
                    idx_list[idx] += std::to_string(i-1) + ",";
                    idx += idx & (-idx);
                }
            }

            // idx 0 is dummy node
            for (int i(1); i < data.size(); i++) {
                el = std::to_string(data[i]);
                el.insert(0, 10 - el.size(), ' ');
                repr += bin_repr(i) + sep + el + sep + "f(" + idx_list[i];
                repr.replace(repr.size()-1, 1, ")\n");
            }
            return repr;
        }
};


// Segment tree
class SegmentTree {
    private:
        size_t v_size;
        std::vector<int> data;
    public:
        SegmentTree(const std::vector<int>& v) : v_size(v.size()), data(2*v_size) {
            for (size_t i(0); i < v_size; i++) {
                data[v_size+i] = v[i];
            }
            for (size_t i(v_size-1); i > 0; i--) {
                data[i] = data[i<<1] + data[i<<1 | 1];
            }
        }

        void insert(int idx, const int val) {
            data[idx + v_size] = val;
            for (size_t i(idx + v_size); i > 1; i >>= 1) {
                data[i>>1] = data[i] + data[i^1];
            }
        }

        int rsq(int l, int r) const {
            int res(0);

            for (l += v_size, r += v_size; l < r; l >>= 1, r >>= 1) {
                if (l&1) res += data[l++];
                if (r&1) res += data[--r];
            }
            return res;
        }
};
