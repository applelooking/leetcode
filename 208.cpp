class TrieNode {
public:
    // Initialize your data structure here.
    vector<TrieNode*> children; 
    int val;
    bool end;
    TrieNode() {
        val = 0;
        children = vector<TrieNode*>(26, NULL);
        end = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* ptr = root;
        for (auto ch : word) {
            if (ptr->children[ch - 'a'] == NULL) {
                ptr->children[ch - 'a'] = new TrieNode();
                ++ptr->val;
            }
            ptr = ptr->children[ch - 'a'];
        }
        ptr->end = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* ptr = root;
        for (auto ch : word) {
            if (ptr->children[ch - 'a'] == NULL) {
                return false;
            } else {
                ptr = ptr->children[ch - 'a'];
            }
        }
        return ptr->end == true;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* ptr = root;
        for (auto ch : prefix) {
            if (ptr->children[ch - 'a'] == NULL) return false;
            ptr = ptr->children[ch - 'a'];
        }
        return ptr->val > 0 || ptr->end == true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");