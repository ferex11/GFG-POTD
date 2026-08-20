class Solution {
private:
    int ans = INT_MIN;;
    void dfs(Node* root, int max_ancestor) {
        if (!root) {
            return;
        }
        ans = max(ans, max_ancestor - root->data);
        max_ancestor = max(max_ancestor, root->data);
        dfs(root->left, max_ancestor);
        dfs(root->right, max_ancestor);
    }
public:
    int maxDiff(Node* root) {
        dfs(root->left, root->data);
        dfs(root->right, root->data);
        return ans;
    }
};
