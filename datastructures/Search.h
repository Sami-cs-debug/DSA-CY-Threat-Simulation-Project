#include <iostream>
#include <string>
using namespace std;

struct BSTNode {
    string threatName;
    string type;
    int severity;
    BSTNode* left;
    BSTNode* right;

    BSTNode(string n, string t, int s) {
        threatName = n;
        type = t;
        severity = s;
        left = nullptr;
        right = nullptr;
    }
};

struct BST {
    BSTNode* root;

    // Tree starts empty
    BST() {
        root = nullptr;
    }

    // Insert node
    BSTNode* insertHelper(BSTNode* node,
                          string name,
                          string type,
                          int severity) {

        if (node == nullptr) {
            return new BSTNode(name, type, severity);
        }

        // Smaller severity → left
        if (severity < node->severity) {
            node->left = insertHelper(node->left,
                                      name, type, severity);
        }

        // Greater severity → right
        else if (severity > node->severity) {
            node->right = insertHelper(node->right,
                                       name, type, severity);
        }

        return node;
    }

    // Add threat
    void insert(string name, string type, int severity) {
        root = insertHelper(root, name, type, severity);
    }

    // In-order traversal
    void inOrderHelper(BSTNode* node, int& rank) {
        if (node == nullptr) return;

        inOrderHelper(node->left, rank);

        cout << "RANK " << rank
             << " | Severity: " << node->severity
             << " | " << node->threatName
             << " | Type: " << node->type
             << endl;

        rank++;

        inOrderHelper(node->right, rank);
    }

    // Display threats
    void inOrderTraversal() {
        cout << "\n===== THREAT PRIORITY REPORT =====" << endl;

        int rank = 1;
        inOrderHelper(root, rank);

        cout << "Total threats ranked: " << rank - 1 << endl;
    }

    // Search threats
    void searchHelper(BSTNode* node, int threshold) {
        if (node == nullptr) return;

        searchHelper(node->left, threshold);

        if (node->severity >= threshold) {
            cout << "  -> " << node->threatName
                 << " | Severity: " << node->severity
                 << " | Type: " << node->type
                 << endl;
        }

        searchHelper(node->right, threshold);
    }

    // Show threats above severity
    void findThreatsAbove(int threshold) {
        cout << "\n===== THREATS AT SEVERITY >= "
             << threshold << " =====" << endl;

        searchHelper(root, threshold);
    }
};
