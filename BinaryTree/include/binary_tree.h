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
    bool find(int val) const;

private:
    TreeNode* root_;
    size_t count_;

private:
    bool find(TreeNode* node, int val) const;
    void add(TreeNode*& node, int val);
    void erase(TreeNode*& node, int val);
};

inline size_t binary_tree::size() const {
    return count_;
}

inline bool binary_tree::empty() const {
    return (root_ == nullptr);
}

void binary_tree::add(TreeNode*& node, int val) {
    if (!node) {
        node = new TreeNode(val);
        ++count_;
        return;
    }

    if (node->val < val) {
        add(node->left, val);
    }
    else if (node->val > val) {
        add(node->right, val);
    }
}

inline void binary_tree::add(int val) {
    add(root_, val);
}

// FIXME
inline void binary_tree::erase(TreeNode*& node, int val) {
    if (!node) {
        return;
    }

    if (node->val < val) {
        erase(node->left, val);
    }
    else if (node->val > val) {
        erase(node->right, val);
    }
    else {
        if (node->left && node->right) {

        }
        else if (!node->left && node->right) {

        }
        else if (node->left && !node->right) {

        }
        else { // !node->left && !node->right
            delete node;
            node = nullptr;
            --count_;
        }
    }
}

inline void binary_tree::erase(int val) {
    erase(root_, val);
}

inline bool binary_tree::find(TreeNode* node, int val) const {
    if (!node) {
        return false;
    }

    if (node->val < val) {
        find(node->left, val);
    }
    else if (node->val > val) {
        find(node->right, val);
    }
    else {
        return true;
    }
}

inline bool binary_tree::find(int val) const {
    return find(root_, val);
}
