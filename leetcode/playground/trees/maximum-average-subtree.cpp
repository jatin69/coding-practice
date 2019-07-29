/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
          output += "null, ";
          continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

void prettyPrintTree(TreeNode* node, string prefix = "", bool isLeft = true) {
    if (node == nullptr) {
        cout << "Empty tree";
        return;
    }

    if(node->right) {
        prettyPrintTree(node->right, prefix + (isLeft ? "¦   " : "    "), false);
    }

    cout << prefix + (isLeft ? "+-- " : "+-- ") + to_string(node->val) + "\n";

    if (node->left) {
        prettyPrintTree(node->left, prefix + (isLeft ? "    " : "¦   "), true);
    }
}


struct augNode{
    int sum;
    int size;
    double maxAvg;
    TreeNode* maxAvgNode;
};


augNode dfs(TreeNode* root){

    if(root == 0){
        return {0, 0, 0.0, nullptr};
    }

    augNode l = dfs(root->left);
    augNode r = dfs(root->right);

    int currSum = l.sum + r.sum + root->val;
    int currSize = l.size + r.size + 1;
    double currAvg = currSum / currSize;
    double currMaxAvg = 0;
    TreeNode* currMaxAvgNode = nullptr;

    if(currAvg > l.maxAvg){
        if(currAvg > r.maxAvg){
            currMaxAvg = currAvg;
            currMaxAvgNode = root;
        }
        else{
            currMaxAvg = r.maxAvg;
            currMaxAvgNode = r.maxAvgNode;
        }
    }
    else{
        if(l.maxAvg > r.maxAvg){
            currMaxAvg = l.maxAvg;
             currMaxAvgNode = l.maxAvgNode;
        }
        else{
            currMaxAvg = r.maxAvg;
             currMaxAvgNode = r.maxAvgNode;
        }
    }

    return {
        currSum, currSize, currMaxAvg, currMaxAvgNode
    };
}

TreeNode* findMaxAvg(TreeNode* root){
    if(root==nullptr) return root;
    augNode res = dfs(root);
    return res.maxAvgNode;
}

int main() {
    string line;
    // line = "[2, -2, 14, -1, 1, 5, -1]";
    line = "[7, 8, -1]";
    TreeNode* root = stringToTreeNode(line);
    prettyPrintTree(root);
    cout << "\nMax Average subtree : \n";
    TreeNode* res = findMaxAvg(root);
    prettyPrintTree(res);
    return 0;
}

