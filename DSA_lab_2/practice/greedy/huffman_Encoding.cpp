/*
 * Huffman Encoding Implementation
 * 
 * This program implements the Huffman coding algorithm for data compression.
 * Huffman coding assigns variable-length codes to characters based on their frequencies.
 * More frequent characters get shorter codes, resulting in overall compression.
 * 
 * Time Complexity: O(n log n) where n is the number of unique characters
 * Space Complexity: O(n) for storing the Huffman tree
 */

#include <iostream>      // For input/output operations (cin, cout)
#include <queue>         // For priority_queue used in building Huffman tree
#include <unordered_map> // For storing character-to-code mappings (hash table)
#include <vector>        // For dynamic arrays to store input data
#include <stdexcept>    // For exception handling (invalid_argument)

using namespace std;

// Node structure for the Huffman Tree
struct Node {
    char data;          // Character stored in the node (valid only for leaf nodes)
    int freq;           // Frequency of the character or subtree
    Node* left;         // Pointer to left child (represents '0' in code)
    Node* right;        // Pointer to right child (represents '1' in code)

    // Constructor: Initialize a new node with given character and frequency
    // All new nodes start as leaf nodes with null children
    Node(char data, int freq)
        : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

// Custom comparator class for the priority queue
// This creates a min-heap based on node frequencies
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;  // Return true if 'a' should have lower priority
    }
};

// Recursive function to deallocate the entire Huffman tree
// Performs a post-order traversal to ensure proper cleanup
void deleteTree(Node* root) {
    if (root == nullptr) return;     // Base case: empty subtree
    deleteTree(root->left);          // First delete left subtree
    deleteTree(root->right);         // Then delete right subtree
    delete root;                     // Finally delete current node
}

// Recursive function to generate Huffman codes for each character
// Traverses the tree, building codes by adding '0' for left moves and '1' for right
void printCodes(Node* root, string code,
                unordered_map<char, string>& huffmanCodes) {
    if (!root) return;               // Base case: empty subtree
    
    // When we reach a leaf node, we've found a complete character code
    if (!root->left && !root->right) {
        huffmanCodes[root->data] = code;  // Store code in hash table
        cout << root->data << ": " << code << endl;  // Print character and its code
    }

    // Recursively build codes for left and right subtrees
    printCodes(root->left, code + "0", huffmanCodes);   // Add '0' for left path
    printCodes(root->right, code + "1", huffmanCodes);  // Add '1' for right path
}

// Function to validate input data before processing
// Throws exceptions if input data is invalid
void validateInput(const vector<char>& characters, const vector<int>& frequencies) {
    // Check for empty input
    if (characters.empty() || frequencies.empty()) {
        throw invalid_argument("Input vectors cannot be empty");
    }
    
    // Verify matching sizes of input vectors
    if (characters.size() != frequencies.size()) {
        throw invalid_argument("Character and frequency vectors must have the same size");
    }
    
    // Verify all frequencies are positive
    for (int freq : frequencies) {
        if (freq <= 0) {
            throw invalid_argument("Frequencies must be positive");
        }
    }
}

// Main function to build the Huffman Tree
// Returns the root node of the constructed tree
Node* huffmanEncoding(const vector<char>& characters, const vector<int>& frequencies) {
    try {
        // Validate input before processing
        validateInput(characters, frequencies);
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return nullptr;
    }

    // Create min-heap priority queue for building tree
    // Queue will automatically keep nodes sorted by frequency
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    // Phase 1: Create initial leaf nodes
    // Create a node for each character and add to priority queue
    for (size_t i = 0; i < characters.size(); ++i) {
        minHeap.push(new Node(characters[i], frequencies[i]));
    }

    // Phase 2: Build the Huffman Tree
    // Continue combining nodes until only one remains (the root)
    while (minHeap.size() > 1) {
        // Get two nodes with lowest frequencies
        Node* x = minHeap.top(); minHeap.pop();
        Node* y = minHeap.top(); minHeap.pop();

        // Create new internal node as their parent
        Node* z = new Node('\0', x->freq + y->freq);  // '\0' indicates internal node
        z->left = x;    // Smaller frequency becomes left child
        z->right = y;   // Larger frequency becomes right child

        // Add new internal node back to queue
        minHeap.push(z);
    }

    // Return root of the completed Huffman tree
    return minHeap.empty() ? nullptr : minHeap.top();
}

int main() {
    try {
        // Example input: characters and their frequencies
        vector<char> characters = {'a', 'b', 'c', 'd', 'e', 'f'};
        vector<int> frequencies = {5, 9, 12, 13, 16, 45};

        // Build the Huffman Tree from input data
        Node* root = huffmanEncoding(characters, frequencies);
        
        if (root) {
            // Generate and display Huffman codes for each character
            cout << "Huffman Codes:\n";
            unordered_map<char, string> huffmanCodes;
            printCodes(root, "", huffmanCodes);

            // Clean up allocated memory
            deleteTree(root);
        }
    } catch (const exception& e) {
        // Handle any unexpected errors
        cout << "Error: " << e.what() << endl;
        return 1;  // Return error status
    }

    return 0;  // Return success status
}
