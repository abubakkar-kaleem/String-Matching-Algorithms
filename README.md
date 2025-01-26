### Project Title: String Matching Algorithms: Comparing Rabin-Karp, KMP, and Trie Data Structures

### Project Overview:
This project implements and compares three well-known string-matching algorithms: **Rabin-Karp**, **Knuth-Morris-Pratt (KMP)**, and **Trie Trees**. String matching plays an essential role in a variety of applications, such as searching for specific patterns in large datasets, DNA sequence analysis, text-editing programs, and plagiarism detection. The goal of this project is to implement each of these algorithms and compare their performance in terms of efficiency and time complexity.

### Algorithms Implemented:

1. **Rabin-Karp Algorithm**:
   - The Rabin-Karp algorithm uses a hash function to efficiently search for a pattern in a larger string. It calculates a hash value for both the pattern and the substrings in the given text and compares these hash values to identify matching subsequences. The main advantage of Rabin-Karp is its ability to handle multiple pattern matching efficiently.
   - **Time Complexity**: O(n*m), where n is the length of the text and m is the length of the pattern.
   - **Space Complexity**: O(n), additional space for hash values.
   - **Pros**: Effective for detecting plagiarism, capable of matching multiple patterns.
   - **Cons**: Can be slower than other algorithms in practice and requires extra space.

2. **Knuth-Morris-Pratt (KMP) Algorithm**:
   - KMP improves upon the brute-force approach by preprocessing the pattern to build a longest prefix-suffix array. This allows the algorithm to skip unnecessary comparisons and find matches in linear time. KMP is a fast and efficient method for string matching.
   - **Time Complexity**: O(n + m), where n is the length of the text and m is the length of the pattern.
   - **Space Complexity**: O(m) for the preprocessed array.
   - **Pros**: Faster than brute-force and Rabin-Karp, especially for smaller alphabets, and has an optimal time complexity.
   - **Cons**: Requires extra space for preprocessing.

3. **Trie Tree Data Structure**:
   - A Trie tree is a type of prefix tree used to store strings in an efficient manner. The structure allows for fast lookup times and is especially useful for applications like auto-completion and prefix matching. Each node in the trie represents a character in the string, and edges represent the relationship between characters.
   - **Time Complexity**: O(m), where m is the length of the word being searched or inserted.
   - **Space Complexity**: O(n), where n is the total number of characters in the tree.
   - **Pros**: Fast lookup, no collisions, provides an alphabetical ordering of strings.
   - **Cons**: High memory usage due to multiple node pointers and can be slower than hash table lookups in some cases.

### Features:
- **Rabin-Karp Algorithm** for efficient pattern matching using hash functions.
- **Knuth-Morris-Pratt (KMP)** for fast pattern matching with linear time complexity.
- **Trie Tree** for storing and searching a collection of strings with efficient prefix-based matching.
- Comparison of the time complexities and efficiency of these algorithms.
- Demonstration of each algorithm's functionality and its applications.

### Methodology:
The project demonstrates the use of the three algorithms to match patterns within a given string. Each algorithm was implemented as a class with specific functions:
- **Rabin-Karp** uses a hash-based approach to compare patterns.
- **KMP** builds a preprocessing array to optimize the search.
- **Trie Tree** stores words in a tree structure, enabling efficient prefix search.

### Findings and Results:
- **Rabin-Karp**: The algorithm performs well when searching for multiple pattern matches but can be slower in practice due to the hash function's overhead.
- **Knuth-Morris-Pratt (KMP)**: This algorithm offers the fastest matching time and is efficient for searching with smaller alphabets. Its preprocessing phase increases its memory usage.
- **Trie Tree**: A very efficient structure for prefix-based search, but it consumes a large amount of memory due to its hierarchical nature. Ideal for use cases like autocomplete.

### Conclusion:
- **KMP** is optimal for pattern searching when dealing with smaller alphabets, and it operates in O(n + m) time, making it the fastest among the three.
- **Rabin-Karp** is useful in scenarios involving multiple patterns but is limited by its O(n * m) time complexity.
- **Trie Tree** excels in prefix matching, though it can be memory-intensive, making it suitable for dictionary-based applications like autocomplete.

### How to Use:
1. Clone this repository.
2. Compile and run the program with a C++ compiler (e.g., `g++`).
3. Modify the input data or search patterns in the `main` function to test the algorithms with different strings and patterns.

---

This project provides a comprehensive comparison of fundamental string-matching algorithms and helps evaluate their efficiency based on time complexity and practical use cases.

