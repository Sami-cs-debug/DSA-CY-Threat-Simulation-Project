#include <iostream>
#include <string>
using namespace std;

// ── BST NODE ──────────────────────────────────────────────────
// Each node stores one threat with its severity
// Left child always has lower severity
// Right child always has higher severity
struct BSTNode {
    string threatName;  // name of threat e.g. Trojan
    string type;        // type e.g. Malware
    int severity;       // danger level used for sorting
    BSTNode* left;      // pointer to left child
    BSTNode* right;     // pointer to right child

    // Set values when node is created
    BSTNode(string n, string t, int s) {
        threatName = n;
        type       = t;
        severity   = s;
        left       = nullptr;
        right      = nullptr;
    }
};

// ── BINARY SEARCH TREE ────────────────────────────────────────
// Stores threats sorted by severity automatically
// Lower severity goes LEFT
// Higher severity goes RIGHT
// In-order traversal gives threats sorted low to high
// Teacher question: why BST?
// Answer: BST keeps threats sorted as we insert them
// No need to sort manually after adding

struct BST {
    BSTNode* root;  // top of the tree

    // Tree starts empty
    BST() {
        root = nullptr;
    }

    // ── insertHelper ──────────────────────────────────────────
    // Recursive function that finds correct position
    // Compares severity to decide left or right
    BSTNode* insertHelper(BSTNode* node,
                          string name,
                          string type,
                          int severity) {

        // If spot is empty place node here
        if (node == nullptr) {
            return new BSTNode(name, type, severity);
        }

        // If severity is less go to left subtree
        if (severity < node->severity) {
            node->left = insertHelper(node->left,
                                      name, type, severity);
        }
        // If severity is more go to right subtree
        else if (severity > node->severity) {
            node->right = insertHelper(node->right,
                                       name, type, severity);
        }

        return node;
    }

    // ── insert ────────────────────────────────────────────────
    // Adds a new threat into the BST by severity
    void insert(string name, string type, int severity) {
        root = insertHelper(root, name, type, severity);
    }

    // ── inOrderHelper ─────────────────────────────────────────
    // Visits LEFT then ROOT then RIGHT
    // This gives threats in sorted order low to high
    void inOrderHelper(BSTNode* node, int& rank) {
        if (node == nullptr) return;

        // Go left first (lower severity)
        inOrderHelper(node->left, rank);

        // Print this node
        cout << "RANK " << rank
             << " | Severity: " << node->severity
             << " | " << node->threatName
             << " | Type: " << node->type
             << endl;
        rank++;

        // Go right last (higher severity)
        inOrderHelper(node->right, rank);
    }

    // ── inOrderTraversal ──────────────────────────────────────
    // Prints all threats sorted from lowest to highest severity
    // Proves BST inorder traversal to teacher
    void inOrderTraversal() {
        cout << "\n===== THREAT PRIORITY REPORT =====" << endl;
        cout << "Sorted lowest to highest severity"    << endl;
        cout << "----------------------------------"    << endl;
        int rank = 1;
        inOrderHelper(root, rank);
        cout << "----------------------------------"    << endl;
        cout << "Total threats ranked: " << rank - 1  << endl;
    }

    // ── searchHelper ──────────────────────────────────────────
    // Searches BST for threats at or above a severity threshold
    void searchHelper(BSTNode* node, int threshold) {
        if (node == nullptr) return;

        searchHelper(node->left, threshold);

        // Print if severity meets threshold
        if (node->severity >= threshold) {
            cout << "  -> " << node->threatName
                 << " | Severity: " << node->severity
                 << " | Type: " << node->type
                 << endl;
        }

        searchHelper(node->right, threshold);
    }

    // ── findThreatsAbove ──────────────────────────────────────
    // Shows all threats at or above given severity level
    void findThreatsAbove(int threshold) {
        cout << "\n===== THREATS AT SEVERITY >= "
             << threshold << " =====" << endl;
        searchHelper(root, threshold);
    }
};
