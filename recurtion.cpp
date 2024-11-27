#include <iostream>
#include <vector>
#include <queue>
#include <complex>

using namespace std;

// each iteration argument array
vector<int> argument_array;

void display_argument_array() {
    for (int i = 0; i < argument_array.size(); i++) {
        cout << argument_array[i] << ",";
    }
}

//class for binary tree
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Forward declaration for maxLevel and isAllElementsNull functions
static int maxLevel(TreeNode* node);
static bool isAllElementsNull(const std::vector<TreeNode*>& list);
static void printNodeInternal(const std::vector<TreeNode*>& nodes, int level, int maxLevel);

//function that creates binary tree from the argument_array
TreeNode* btd(const std::vector<int>& preorder, int& index) {
    if (index >= preorder.size() || preorder[index] == -1) {
        index += 1;
        return nullptr;
    }

    TreeNode* root = new TreeNode(preorder[index]);
    index++;
    root->left = btd(preorder, index);
    root->right = btd(preorder, index);
    return root;
}

//print level order
void printlevelOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            std::cout << node->val << " ";
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
        std::cout << std::endl; // Print new line after each level
    }
}

//functioon that starts creating tree and returns the root node
TreeNode* buildTree(const std::vector<int>& preorder) {
    int index = 0;
    return btd(preorder, index);
}

static void printWhitespaces(int count) {
    for (int i = 0; i < count; i++)
        std::cout << " ";
}

static int maxLevel(TreeNode* node) {
    if (node == nullptr)
        return 0;

    return std::max(maxLevel(node->left), maxLevel(node->right)) + 1;
}

static bool isAllElementsNull(const std::vector<TreeNode*>& list) {
    for (const auto& object : list) {
        if (object != nullptr)
            return false;
    }
    return true;
}

static void printNodeInternal(const std::vector<TreeNode*>& nodes, int level, int maxLevel) {
    if (nodes.empty() || isAllElementsNull(nodes))
        return;

    int floor = maxLevel - level;
    int edgeLines = std::pow(2, std::max(floor - 1, 0));
    int firstSpaces = std::pow(2, floor) - 1;
    int betweenSpaces = std::pow(2, floor + 1) - 1;

    printWhitespaces(firstSpaces);

    std::vector<TreeNode*> newNodes;
    for (TreeNode* node : nodes) {
        if (node != nullptr) {
            std::cout << node->val;
            newNodes.push_back(node->left);
            newNodes.push_back(node->right);
        } else {
            newNodes.push_back(nullptr);
            newNodes.push_back(nullptr);
            std::cout << " ";
        }
        printWhitespaces(betweenSpaces);
    }
    std::cout << std::endl;

    for (int i = 1; i <= edgeLines; i++) {
        for (size_t j = 0; j < nodes.size(); j++) {
            printWhitespaces(firstSpaces - i);
            if (nodes[j] == nullptr) {
                printWhitespaces(edgeLines + edgeLines + i + 1);
                continue;
            }

            if (nodes[j]->left != nullptr)
                std::cout << "/";
            else
                printWhitespaces(1);

            printWhitespaces(i + i - 1);

            if (nodes[j]->right != nullptr)
                std::cout << "\\";
            else
                printWhitespaces(1);

            printWhitespaces(edgeLines + edgeLines - i);
        }
        std::cout << std::endl;
    }

    printNodeInternal(newNodes, level + 1, maxLevel);
}

static void printNode(TreeNode* root) {
    int maxL = maxLevel(root);
    printNodeInternal(std::vector<TreeNode*> {root}, 1, maxL);
}
