class Solution {
private:
    Node* lca(Node* root, int p, int q) {
        if (!root) {
            return nullptr;
        }
        if (root->data == p || root->data == q) {
            return root;
        }
        Node* left_node = lca(root->left, p, q);
        Node* right_node = lca(root->right, p, q);
        if (left_node && right_node) {
            return root;
        }
        return left_node ? left_node : right_node;
    }
    int dfs(Node* root, int target, char prev) {
        if (!root) {
            return -1;
        }
        if (root->data == target) {
            return 0;
        }
        if (root->left) {
            int turns = dfs(root->left, target, 'L');
            if (turns != -1) {
                if (prev == 'R') {
                    turns++;
                }
                return turns;
            }
        }
        if (root->right) {
            int turns = dfs(root->right, target, 'R');
            if (turns != -1) {
                if (prev == 'L') {
                    turns++;
                }
                return turns;
            }
        }
        return -1;
    }
public:
    int numberOfTurns(Node* root, int p, int q) {
        Node* node = lca(root, p, q);
        if (node->data == p) {
            int ans = dfs(node, q, 'N');
            return ans == 0 ? -1 : ans;
        }
        if (node->data == q) {
            int ans = dfs(node, p, 'N');
            return ans == 0 ? -1 : ans;
        }
        int x = dfs(node, p, 'N');
        int y = dfs(node, q, 'N');
        if (x == -1 || y == -1) {
            return -1;
        }
        return x + y + 1;
    }
};
