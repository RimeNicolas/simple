

//Abstract
class Tree {
    protected:
        size_t v_size;
        std::vector<int> data;
    public:
        Tree(size_t size, size_t data_size) {
            v_size = size;
            data.resize(data_size);
        };
        virtual ~Tree() = default;

        virtual void insert(int idx, const int val) = 0;

        virtual int rq(const int l, const int r) const = 0;
};

//Abstract
class BinaryTree: public Tree {
    public:
        BinaryTree(size_t size, size_t data_size) : Tree(size, data_size) {
            v_size = size;
            data.resize(data_size);
        };
        virtual ~BinaryTree() = default;

        enum TypeTraversal { preorder, inorder, postorder, level };

        std::vector<int> traversal(TypeTraversal typ) const {
            std::vector<int> trav;
            switch(typ){
                case TypeTraversal::preorder:
                    intl_traversal(trav, 1, typ);
                    break;
                case TypeTraversal::inorder:
                    intl_traversal(trav, 1, typ);
                    break;
                case TypeTraversal::postorder:
                    intl_traversal(trav, 1, typ);
                case TypeTraversal::level:
                    intl_level_traversal(trav, 1);
            }
            return trav;
        }
    protected:
        void intl_traversal(std::vector<int>& t, const size_t i, TypeTraversal typ) const {
            if (i >= data.size()) return;
            if (typ == TypeTraversal::preorder) t.push_back(data[i]);
            intl_traversal(t, i << 1, typ);
            if (typ == TypeTraversal::inorder) t.push_back(data[i]);
            intl_traversal(t, i << 1 | 1, typ);
            if (typ == TypeTraversal::postorder) t.push_back(data[i]);
        }
        void intl_level_traversal(std::vector<int>& t, size_t i) const {
            std::queue<int> q;
            q.push(i);

            while(!q.empty()) {
                i = q.front();
                if (i >= data.size()) break;
                q.pop();
                t.push_back(data[i]);
                q.push(i << 1);
                q.push(i << 1 | 1);
            }
                
        }
};

// Binary Indexed Tree (Fenwick tree)
class BITree: public Tree {
    public:
        BITree(const std::vector<int>& v) : Tree(v.size(), v.size()+1) {
            for (size_t i(0); i < v_size; i++) {
                insert(i+1, v[i]);
            }
        }

        void insert(int idx, const int val) {
            while (idx < data.size()) {
                data[idx] += val;
                idx += idx & (-idx);
            }
        }

        int rq(const int l, const int r) const {
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
class SegmentTree : public BinaryTree {
    public:
        SegmentTree(const std::vector<int>& v) : BinaryTree(v.size(), 2 * v.size()) {
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

        int rq(int l, int r) const {
            int res(0);

            for (l += v_size, r += v_size; l < r; l >>= 1, r >>= 1) {
                if (l&1) res += data[l++];
                if (r&1) res += data[--r];
            }
            return res;
        }
};
