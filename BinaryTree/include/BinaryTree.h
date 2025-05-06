#include <algorithm>
#include <cstddef>
#include <vector>
#include <queue>
#include <iostream>


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class BinaryTree {
public:
    BinaryTree() : root_{ nullptr }, count_{ 0 } {}

    ~BinaryTree();

    size_t size() const;
    bool empty() const;
    void add(int val);
    void add(const std::vector<int>& vals);
    void erase(int val);
    bool find(int val) const;
    void clear();

    // Корінь-Ліво-Право
    void printPreOrder() const;

    // Ліво-Право-Корінь
    void printPostOrder() const;
    
    // Ліво-Корінь-Право
    void printInOrder() const;

    // level-order рівень за рівнем
    void printBFS() const;

    void printDFS() const;

    std::vector<int> preOrder() const;

    bool isBalanced() const;

private:
    TreeNode* root_;
    size_t count_;

private:
    void printPreOrder(TreeNode* node) const;
    void printPostOrder(TreeNode* node) const;
    void printInOrder(TreeNode* node) const;
    void printBFS(TreeNode* node) const;

    void printDFS(TreeNode* node, std::string path, std::vector<std::string>& paths) const;

    void preOrder(TreeNode* node, std::vector<int>& preOrderList) const;
    bool find(TreeNode* node, int val) const;
    void add(TreeNode*& node, int val);
    void erase(TreeNode*& node, int val);
    void clear(TreeNode* node);
    int isBalanced(TreeNode* node) const;
};

inline BinaryTree::~BinaryTree() {
    clear(root_);
}

inline bool BinaryTree::isBalanced() const {
    bool ret = isBalanced(root_) != -1;
    return ret;
}

/*
* Pre-order 15, 9, 3, 1, 8, 4, 12, 23, 17
        15
       /  \
      9    23
     / \    /
    3  12  17
    / \
    1  8
     /
    4
*/
inline int BinaryTree::isBalanced(TreeNode* node) const {
    if (!node) {
        std::cout << std::endl;
        return 0;
    }

    int leftHeight = isBalanced(node->left);
    if (leftHeight == -1) return -1;

    int rightHeight = isBalanced(node->right);
    if (rightHeight == -1) return -1;

    if (std::abs(leftHeight - rightHeight) > 1) {
        return -1;
    }

    return std::max(leftHeight, rightHeight) + 1;
}

inline void BinaryTree::clear() {
    clear(root_);
    root_ = nullptr;
    count_ = 0;
}

inline void BinaryTree::clear(TreeNode* node) {
    if (!node) {
        return;
    }
    clear(node->left);
    clear(node->right);
    delete node;
}

inline size_t BinaryTree::size() const {
    return count_;
}

inline bool BinaryTree::empty() const {
    return (root_ == nullptr);
}

void BinaryTree::add(TreeNode*& node, int val) {
    if (!node) {
        node = new TreeNode(val);
        ++count_;
        return;
    }

    if (val < node->val) {
        add(node->left, val);
    }
    else if (val > node->val) {
        add(node->right, val);
    }
    else {
        // do nothing, value already exists
        return;
    }
}

inline void BinaryTree::add(int val) {
    add(root_, val);
}

inline void BinaryTree::add(const std::vector<int>& vals) {
    for (const auto& val : vals) {
        add(val);
    }
}

inline void BinaryTree::erase(TreeNode*& node, int val) {
    if (!node) {
        return;
    }

    if (val < node->val) {
        erase(node->left, val);
    }
    else if (val > node->val) {
        erase(node->right, val);
    }
    else {
        if (node->left && node->right) {
            // Find the in-order successor (smallest in the right subtree)
            TreeNode* successor = node->right;
            while (successor->left) {
                successor = successor->left;
            }
            node->val = successor->val; // Replace value
            erase(node->right, successor->val); // Remove successor
        }
        else if (!node->left && node->right) {
            TreeNode* tmp = node->right;
            delete node;
            node = tmp;
            --count_;
        }
        else if (node->left && !node->right) {
            TreeNode* tmp = node->left;
            delete node;
            node = tmp;
            --count_;
        }
        else { // !node->left && !node->right
            delete node;
            node = nullptr;
            --count_;
        }
    }
}

inline void BinaryTree::erase(int val) {
    erase(root_, val);
}

inline bool BinaryTree::find(TreeNode* node, int val) const {
    if (!node) {
        return false;
    }

    if (val < node->val) {
        find(node->left, val);
    }
    else if (val > node->val) {
        find(node->right, val);
    }
    else {
        return true;
    }
}

inline bool BinaryTree::find(int val) const {
    return find(root_, val);
}

inline void BinaryTree::printPreOrder(TreeNode* node) const {
    if (!node) {
        return;
    }
    std::cout << node->val << " ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}

inline void BinaryTree::printPreOrder() const {
    printPreOrder(root_);
    if (!this->empty()) {
        std::cout << std::endl;
    }
}

inline void BinaryTree::printPostOrder() const {
    printPostOrder(root_);
    if (!this->empty()) {
        std::cout << std::endl;
    }
}

inline void BinaryTree::printPostOrder(TreeNode* node) const {
    if (!node) {
        return;
    }
    printPostOrder(node->left);
    printPostOrder(node->right);
    std::cout << node->val << " ";
}

inline void BinaryTree::preOrder(TreeNode* node, std::vector<int>& preOrderList) const {
    if (!node) {
        return;
    }
    preOrderList.push_back(node->val);
    preOrder(node->left, preOrderList);
    preOrder(node->right, preOrderList);
}

inline std::vector<int> BinaryTree::preOrder() const {
    std::vector<int> ret;
    ret.reserve(this->size());
    preOrder(root_, ret);
    return ret;
}

inline void BinaryTree::printInOrder() const {
    printInOrder(root_);
    if (!this->empty()) {
        std::cout << std::endl;
    }
}

inline void BinaryTree::printInOrder(TreeNode* node) const {
    if (!node) {
        return;
    }
    printInOrder(node->left);
    std::cout << node->val << " ";
    printInOrder(node->right);
}

inline void BinaryTree::printBFS() const {
    printBFS(root_);
}

/*
* Pre-order 15, 9, 3, 1, 8, 4, 12, 23, 17
        15
       /  \
      9    23
     / \    /
     3 12  17
    / \
    1 8
     /
    4
*/
inline void BinaryTree::printBFS(TreeNode* node) const {
    if (!node) {
        return;
    }
    std::queue<TreeNode*> q;
    q.push(root_);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        std::cout << current->val << " ";

        if (current->left) {
            q.push(current->left);
        }
        if (current->right) {
            q.push(current->right);
        }
    }
}

inline void BinaryTree::printDFS() const {
    std::vector<std::string> paths;
    if (root_) {
        printDFS(root_, "", paths);
    }

    for (const auto& path : paths) {
        std::cout << path << std::endl;
    }
}

inline void BinaryTree::printDFS(TreeNode* node, std::string path, std::vector<std::string>& paths) const {
    // Append the current node's value to the path
    path += std::to_string(node->val);

    // If it's a leaf node, add the path to the result
    if (!node->left && !node->right) {
        paths.push_back(path);
    }
    else {
        // Otherwise, continue the path with "->" and recurse
        path += "->";
        if (node->left) printDFS(node->left, path, paths);
        if (node->right) printDFS(node->right, path, paths);
    }
}
