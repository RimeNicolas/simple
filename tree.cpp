
// Binary Indexed Tree (Fenwick tree)
class BIT {
    private:
        std::vector<int> data;
    public:
        BIT(int size) : data(size+1, 0) {}

        void insert(int idx, int val) {
            while (idx < data.size()) {
                data[idx] += val;
                idx += idx & (-idx);
            }
        }

        int rsq(int from, int to) {
            return getSum(to) - getSum(from);
        }

        int getSum(int idx) {
            int val(0);
            while(idx != 0) {
                val += data[idx];
                idx -= idx & (-idx);
            }
            return val;
        }

        std::string repr() const {
            std::string repr;
            std::string sep = " | ";
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


BIT construct_BIT(const std::vector<int>& v) {
    BIT b(v.size()+1);

    for (size_t i(0); i < v.size(); i++) {
        b.insert(i+1, v[i]);
    }
    return b;
}

