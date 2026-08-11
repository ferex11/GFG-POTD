class Solution {
private:
    void dfs(Node* root, int depth, vector<int>& ans) {
        if (!root) {
            return;
        }
        if (depth == ans.size()) {
            ans.push_back(root->data);
        }
        dfs(root->left, depth + 1, ans);
        dfs(root->right, depth + 1, ans);
    }
public:
    vector<int> leftView(Node *root) {
        vector<int> ans;
        dfs(root, 0, ans);
        return ans;
    }
};
