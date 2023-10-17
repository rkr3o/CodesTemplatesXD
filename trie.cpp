#include<bits/stdc++.h>
using namespace std ;

#define endl "\n"
#define ll long long int
const int mod = 1e9 + 7;
const int N = 1e5 + 10;

struct Node {

   Node* links[26];
   bool flag = false;


   bool containKey(char ch)
   {
      return (links[ch - 'a'] != NULL);
   }

   void put(char ch , Node* node)
   {
      links[ch - 'a'] = node;
   }

   Node* get(char ch)
   {
      return links[ch - 'a'];
   }
   void setEnd()
   {
      flag = true;
   }
   bool isEnd()
   {
      return flag;
   }
};

class Trie
{
private :
   Node* root ;
public:
   Trie()
   {
      root = new Node();
   }

   void insert(string word)
   {
      Node* node = root;
      for (int i = 0 ; i < word.size() ; i++)
      {
         if (!node->containKey(word[i]))
         {
            node->put(word[i], new Node());
         }

         node = node->get(word[i]);
      }

      node->setEnd();
   }

   bool search(string word)
   {
      Node* node = root;
      for (int i = 0 ; i < word.size() ; i++)
      {
         if (!node->containKey(word[i]))
         {
            return false;
         }

         node = node->get(word[i]);
      }
      return node->isEnd();
   }

   bool startWith(string prefix)
   {
      Node* node = root;
      for (int i = 0 ; i < prefix.size() ; i++)
      {
         if (!node->containKey(prefix[i]))
         {
            return false;
         }

         node = node->get(prefix[i]);
      }
      return true;
   }
};

int main()
{

   int n ;
   cin >> n ;
   vector<int>type(n);
   for (int i = 0; i < n; ++i)
   {
      cin >> type[i];
   }
   vector<string>st(n);
   for (int i = 0; i < n; ++i)
   {
      cin >> st[i];
   }

   Trie trie;

   for (int i = 0; i < n; ++i)
   {
      if (type[i] == 1)
      {
         trie.insert(st[i]);
      }
      else if (type[i] == 2)
      {
         if (trie.search(st[i]))cout << "true" << endl;
         else cout << "false" << endl;
      }
      else {
         if (trie.startWith(st[i])) cout << "true" << endl;
         else cout << "false" << endl;
      }
   }

   return 0 ;
}
