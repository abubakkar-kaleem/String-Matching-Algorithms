#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

// Rabin-Karp String Matching Algorithm
class Rabin_Karp {
public:
    // Search for the word in the given data using Rabin-Karp algorithm
    int SearchWord(string data, string word) {
        int n = data.length();
        int m = word.length();

        long dataHash = CalculateHash(data, m - 1);
        long wordHash = CalculateHash(word, m - 1);

        // Iterate through the data to search for the word
        for (int i = 1; i <= n - m + 1; i++) {
            if (wordHash == dataHash && checkEqual(data, i - 1, i + m - 2, word, 0, m - 1)) {
                cout << "Found Word First Character at Index:";
                return i - 1;
            }

            if (i < n - m + 1) {
                dataHash = ReCalculateHash(data, i - 1, i + m - 1, dataHash, m);
            }
        }
        return -1; // Word not found
    }

private:
    // Recalculate hash value for the next substring
    long ReCalculateHash(string data, int previousIndex, int newIndex, long previousHash, int patternLength) {
        long newHash = previousHash - data[previousIndex];
        newHash = newHash / 26; // Efficient modulus operation
        newHash += data[newIndex] * pow(26, patternLength - 1);
        return newHash;
    }

    // Calculate the initial hash value for a substring
    long CalculateHash(string data, int end) {
        long hash = 0;
        for (int i = 0; i <= end; i++) {
            hash += data[i] * pow(26, i);
        }
        return hash;
    }

    // Compare two substrings to check if they are equal
    bool checkEqual(string str1, int start1, int end1, string str2, int start2, int end2) {
        if (end1 - start1 != end2 - start2) {
            return false;
        }
        while (start1 <= end1 && start2 <= end2) {
            if (str1[start1] != str2[start2]) {
                return false;
            }
            start1++;
            start2++;
        }
        return true;
    }
};

// KMP String Matching Algorithm
class KMP {
private:
    string data;

public:
    KMP(const string& d) {
        data = d;
    }

    // Perform the KMP search for the given word
    void KMPSearch(string word) {
        int M = word.length();
        int N = data.length();

        int* arr = new int[M]; // Array to store longest prefix-suffix lengths
        CompareWord(word, M, arr); // Prepare the array

        int i = 0, j = 0;
        while (i < N) {
            if (word[j] == data[i]) {
                j++;
                i++;
            }

            if (j == M) {
                cout << "Found Word First Character at Index: " << i - j << endl;
                j = arr[j - 1]; // Backtrack to continue searching
            } else if (i < N && word[j] != data[i]) {
                if (j != 0)
                    j = arr[j - 1]; // Use the precomputed array to skip unnecessary comparisons
                else
                    i = i + 1; // Move to the next character
            }
        }
        delete[] arr; // Clean up the allocated memory
    }

private:
    // Precompute the longest prefix-suffix array
    void CompareWord(string word, int M, int* arr) {
        int length = 0;
        arr[0] = 0;

        int i = 1;
        while (i < M) {
            if (word[i] == word[length]) {
                length++;
                arr[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = arr[length - 1];
                } else {
                    arr[i] = 0;
                    i++;
                }
            }
        }
    }
};

// Trie Tree for Word Insertion and Search
struct Node {
    Node *child[26];
    bool EndOfWord;
};

class TrieTree {
public:
    // Create a new trie node
    Node* GetNode() {
        Node* temp = new Node;
        temp->EndOfWord = false;

        for (int i = 0; i < 26; i++) {
            temp->child[i] = NULL;
        }
        return temp;
    }

    // Insert a word into the trie
    void Insert(Node* root, string data) {
        Node* NewNode = root;

        for (int i = 0; i < data.length(); i++) {
            int index = data[i] - 'a';
            if (!NewNode->child[index]) {
                NewNode->child[index] = GetNode();
            }
            NewNode = NewNode->child[index];
        }

        NewNode->EndOfWord = true; // Mark the end of the word
    }

    // Search for a word in the trie
    bool search(Node* root, string data) {
        Node* temp = root;

        for (int i = 0; i < data.length(); i++) {
            int index = data[i] - 'a';
            if (!temp->child[index]) {
                return false; // Word not found
            }
            temp = temp->child[index];
        }

        return (temp != NULL && temp->EndOfWord); // Check if it's the end of the word
    }
};

// Main function to demonstrate all algorithms
int main() {
    // Rabin-Karp Algorithm
    cout << "Rabin Karp Data Structure:\n";
    Rabin_Karp obj1;
    string text = "abcxabcaby";
    string pattern = "abcaby";

    int index = obj1.SearchWord(text, pattern);
    if (index == -1) {
        cout << "Word Not Match\n";
    } else {
        cout << index << "\n";
    }

    cout << "---------------------------------------\n\n";

    // Trie Tree Algorithm
    cout << "Trie Tree Data Structure:\n";
    TrieTree obj;
    string arr[] = {"zbc", "abgl", "cdf", "abcd", "lmn"};
    int size = sizeof(arr) / sizeof(*arr);
    Node* root = obj.GetNode();

    for (int i = 0; i < size; i++) {
        obj.Insert(root, arr[i]);
    }

    cout << "Search Word abg: ";
    int r = obj.search(root, "abg");
    if (r == 1) {
        cout << "Found\n";
    } else {
        cout << "Not Found\n";
    }

    cout << "Search Word cdf: ";
    r = obj.search(root, "cdf");
    if (r == 1) {
        cout << "Found\n";
    } else {
        cout << "Not Found\n";
    }

    cout << "---------------------------------------\n\n";

    // KMP Algorithm
    cout << "KMP Data Structure:\n";
    string txt = "abcxabcabcaby";
    string patt = "abcaby";
    KMP kmp(txt);
    kmp.KMPSearch(patt);
}
