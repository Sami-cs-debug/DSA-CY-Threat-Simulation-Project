#include <iostream>
#include <string>
using namespace std;

// BST Node
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

// Binary Search Tree
struct BST {
    BSTNode* root;

    // Tree starts empty
    BST() {
        root = nullptr;
    }

    // Insert node in correct position
    BSTNode* insertHelper(BSTNode* node,
                          string name,
                          string type,
                          int severity) {

        if (node == nullptr) {
            return new BSTNode(name, type, severity);
        }

        // Lower severity → left
        if (severity < node->severity) {
            node->left = insertHelper(node->left,
                                      name, type, severity);
        }
        // Higher severity → right
        else if (severity > node->severity) {
            node->right = insertHelper(node->right,
                                       name, type, severity);
        }

        return node;
    }

    // Add new threat
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

    // Display sorted threats
    void inOrderTraversal() {
        cout << "\n===== THREAT PRIORITY REPORT =====" << endl;

        int rank = 1;
        inOrderHelper(root, rank);

        cout << "Total threats ranked: " << rank - 1 << endl;
    }

    // Search threats above threshold
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

    // Show threats above given severity
    void findThreatsAbove(int threshold) {
        cout << "\n===== THREATS AT SEVERITY >= "
             << threshold << " =====" << endl;

        searchHelper(root, threshold);
    }
};
