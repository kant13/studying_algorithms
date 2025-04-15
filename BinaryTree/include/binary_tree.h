#include <cstddef>


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class binary_tree {
public:
    binary_tree() : root_{ nullptr }, count_{ 0 } {}

    size_t size() const;
    bool empty() const;
    void add(int val);
    void erase(int val);
    int* find(int val) const;

private:
    TreeNode* root_;
    size_t count_;
};

inline size_t binary_tree::size() const {
    return count_;
}

inline bool binary_tree::empty() const {
    return root_ == nullptr;
}

inline void binary_tree::add(int val) {

}

inline void binary_tree::erase(int val) {

}

inline int* binary_tree::find(int val) const {
    return nullptr;
}
