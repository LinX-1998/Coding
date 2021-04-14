/* ------------------------------*/
/* Created by LinX on 2021/04/14.*/
/* ------------------------------*/
/*
 name: 实现Trie（前缀树）
 */
#include<cstring>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

class Trie {
private:
    bool flag;
    Trie* next[26];
public:
    Trie() {
        flag = false;
        memset(next, 0, sizeof(next));
    }

    void insert(string word) {
        Trie* node = this;
        for(int i=0;i<word.size();i++) {
            if(node->next[word[i] - 'a']==0) {
                node -> next[word[i] - 'a'] = new Trie();
            }
            node = node -> next[word[i] - 'a'];
        }
        node -> flag = true;
    }

    bool search(string word) {
        Trie* node = this;
        for(int i=0;i<word.size();i++) {
            if(node->next[word[i] - 'a']==0) {
                return false;
            }
            node = node -> next[word[i] - 'a'];
        }
        return node -> flag;
    }

    bool startsWith(string prefix) {
        Trie* node = this;
        for(int i=0;i<prefix.size();i++) {
            if(node->next[prefix[i] - 'a']==0) {
                return false;
            }
            node = node -> next[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */