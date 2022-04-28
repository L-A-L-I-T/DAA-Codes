#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int freq;
  char ch;
  Node *left, *right;
  Node(int freq, char ch)
  {
    this->freq = freq;
    this->ch = ch;
    this->left = NULL;
    this->right = NULL;
  }
};

class myComp
{
public:
  bool operator()(Node *a, Node *b)
  {
    return a->freq >= b->freq;
  }
};

Node *huffManAlgo(priority_queue<Node *, vector<Node *>, myComp> &pq)
{
  while (pq.size() > 1)
  {
    Node *left = pq.top();
    pq.pop();
    Node *right = pq.top();
    pq.pop();
    int sum = left->freq + right->freq;
    Node *root = new Node(sum, '$');
    root->left = left;
    root->right = right;
    pq.push(root);
  }
  return pq.top();
}

void printHuffManCodes(Node *root, string s)
{
  if (!root)
    return;
  if (root->ch != '$')
  {
    cout << root->ch << " : " << s << endl;
  }
  printHuffManCodes(root->left, s + "0");
  printHuffManCodes(root->right, s + "1");
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif 
  priority_queue<Node *, vector<Node *>, myComp> pq;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int freq;
    char ch;
    cin >> ch;
    cin >> freq;
    Node *newNode = new Node(freq, ch);
    pq.push(newNode);
  }
  Node *root = huffManAlgo(pq);
  printHuffManCodes(root, "");
  return 0;
}