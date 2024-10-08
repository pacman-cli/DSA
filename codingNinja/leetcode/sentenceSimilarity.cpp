#include <iostream>
#include <sstream> // Required for istringstream to split strings
#include <vector>
using namespace std;

// Function to split a sentence into words and return a vector of words
vector<string> split(const string &sentence) {
  vector<string> v; // Vector to store the split words
  string word;      // Temporary variable to hold each word
  istringstream stream(
      sentence);           // String stream to read words from the sentence
  while (stream >> word) { // Extract each word from the stream
    v.push_back(word);     // Add the word to the vector
  }
  return v; // Return the vector containing all words
}

// Function to check if two sentences are similar based on the matching of words
// from the start and end
bool areSentencesSimilar(string sentence1, string sentence2) {
  // Split both sentences into words and store them in two vectors
  vector<string> v1 = split(sentence1);
  vector<string> v2 = split(sentence2);

  int i = 0; // Index to compare from the left (start) side of both sentences
  int j = 0; // Index to compare from the right (end) side of both sentences

  // Compare words from the left side of both sentences while they are equal
  // and as long as there are words in both sentences
  while (i < v1.size() && i < v2.size() && v1[i] == v2[i]) {
    i++; // Move to the next word on the left side
  }

  // Compare words from the right side of both sentences while they are equal
  // `v1.size() - 1 - j` gives the index of the last word moving backward by j
  while (j < v1.size() - i && j < v2.size() - i &&
         v1[v1.size() - 1 - j] == v2[v2.size() - 1 - j]) {
    j++; // Move to the next word on the right side
  }

  // Check if the sum of left-side matches (i) and right-side matches (j)
  // is greater than or equal to the size of the smaller sentence.
  // This means that either the whole sentence matches or one sentence is a
  // subsequence of the other.
  return i + j >= min(v1.size(), v2.size());
}

int main() {
  string s1 = "My name is Haley"; // First sentence to compare
  string s2 = "My Haley";         // Second sentence to compare

  // Output "true" if the sentences are similar, otherwise "false"
  cout << (areSentencesSimilar(s1, s2) ? "true" : "false")
       << endl; // Expected output: "true"

  return 0; // Return 0 to indicate successful execution
}
