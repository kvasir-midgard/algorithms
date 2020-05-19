/*
greedy3.c
--------------------------------------------------------------------------------
Huffman Lossless Encoding

- Get frequency for all letters in uncoded message
- Create an ordered forest of vertex containing letter and frequency
- Build tree starting with two smallest smallest vertex by merging them and
  adding new parent with the sum of their frequencies
- Continue last step until only one tree exist in the forest
*/
#include <bits/stdc++.h>
using namespace std;

// Structure for Huf. tree node containing letter, frequency, and child pointers
struct huffNode {
  char data;               // holds the relevent character
  unsigned freq;           // frequency of the character
  huffNode *left, *right;  // child pointers for a given node

  // initalize pointers and node information
  huffNode(char data, unsigned freq) {
    left = right = NULL;
    this->data = data;
    this->freq = freq;
  }
};

// Structure for dividing two nodes into greater and lesser frequency
struct nodeCompare {
  bool operator()(huffNode* l, huffNode* r) { return (l->freq > r->freq); }
};

// Traverses from root to leaves printing huffman encoding for each character
void codePrinter(struct huffNode* root, string str) {
  // check if root exists
  if (!root) {
    return;
  }

  // root is character so print root
  if (root->data != '#') {
    printf("%d: %s \n", root->data, str.c_str());
  }

  // print 0 for each left child edge and 1 for each right child edge
  codePrinter(root->left, str + "0");
  codePrinter(root->right, str + "1");
}

// Uses Huffman alg to build Huffman tree then traverse tree to print codes
void huffEncoder(int size, int freq[], char data[]) {
  struct huffNode *top, *left, *right;

  // creates min-ordered forest based on frequency of the character
  priority_queue<huffNode*, vector<huffNode*>, nodeCompare> minPQ;
  for (int i = 0; i < size; ++i) minPQ.push(new huffNode(data[i], freq[i]));

  // while there are more than one tree in the forest continue building
  while (minPQ.size() != 1) {
    // get the next two min frequency nodes from the forest
    left = minPQ.top();
    minPQ.pop();
    right = minPQ.top();
    minPQ.pop();

    // create parent node with sum of the frequencies and internal node data
    top = new huffNode('#', left->freq + right->freq);

    // connect min node as left child and 2nd min node as right child
    top->left = left;
    top->right = right;

    // add new parent node back into min PQ.
    minPQ.push(top);
  }
  // output huffman encoding to terminal
  codePrinter(minPQ.top(), "");
}

// tester
int main() {
  char ray[] = {'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  int freq[] = {2, 5, 13, 19, 29, 31, 41, 47, 59, 67, 73};
  int size = sizeof(ray) / sizeof(ray[0]);
  huffEncoder(size, freq, ray);
  return 0;
}
