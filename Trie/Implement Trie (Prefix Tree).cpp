class TrieNode {
public:
    bool is_word;
    TrieNode *children[26];
    
    TrieNode() {
        is_word = false;
        
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};
class Trie {
public:
    Trie() {
         root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *cur = root;
        for(int i=0;i<word.size();i++)
        {
            int k=word[i]-'a';
            if(cur->children[k]==NULL)
                cur->children[k]=new TrieNode();
            cur=cur->children[k];
        }
        cur->is_word=true;
    }
    
    bool search(string word) {
        TrieNode *cur = root;
        for(int i=0;i<word.size();i++)
        {
            int k=word[i]-'a';
            if(cur->children[k]==NULL)
                return false;
            cur=cur->children[k];
        }
        return cur->is_word;
    }
    
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for(int i=0;i<prefix.size();i++)
        {
            int k=prefix[i]-'a';
            if(cur->children[k]==NULL)
                return false;
            cur=cur->children[k];
        }
        return true;
    }
    private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
