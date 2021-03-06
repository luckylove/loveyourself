// C++ implementation of search and insert
// operations on Trie
#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

// trie node
struct TrieNode
{
	struct TrieNode *children[ALPHABET_SIZE];

	// isEndOfWord is true if the node represents
	// end of a word
	bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
	struct TrieNode *pNode = new TrieNode;

	pNode->isEndOfWord = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;

	return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, string key)
{
	struct TrieNode *pCrawl = root;

	for (int i= 0; i< key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();

		pCrawl = pCrawl->children[index];
	}

	// mark last node as leaf
	pCrawl->isEndOfWord = true;
}

// Returns true if key presents in trie, else
// false
bool search(struct TrieNode *root, string key)
{
	struct TrieNode *pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			return false;

		pCrawl = pCrawl->children[index];
	}

	return (pCrawl != NULL );
}

// Driver
int main()
{
	int n,m;
	cin>>n;
	string keys[n];
	int i,j,k;
	struct TrieNode *root = getNode();
	for(i=0;i<n;i++)
    {
        cin>>keys[i];
        string some="";
        m=keys[i].size();
        some.push_back(keys[i][0]);
       // cout<<"m is "<<m<<endl;
        //cout<<"some is "<<some<<endl;
        struct TrieNode *pCrawl = root;
        for(j=1;j<m;j++)
        {

       // cout<<"some is "<<some<<endl;
           // cout<<"tt"<<endl;

            if(search(root, some)==false)
            {
                cout<<some;
                break;
            }
            else
            {
               // cout<<"calling else"<<endl;
                some.push_back(keys[i][j]);
               	//pCrawl = pCrawl->children[keys[i][j-1]-'a'];
            }



        }
       // cout<<"calling inset"<<endl;
       insert(root, keys[i]);
       //if(search(root, keys[i]))
       // cout<<"so true"<<endl;

    }




}

