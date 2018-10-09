
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

/// leetcode defined data types ///
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

ListNode* make_listnode(const vector<int> &v) {
  ListNode head(0), *p = &head, *cur;
  for (auto x: v) { cur = new ListNode(x); p->next = cur; p = cur; }
  return head.next;
}

constexpr long long null = numeric_limits<long long>::min();

TreeNode* make_treenode(const vector<long long> &v) {
  vector<TreeNode*> cur, next;
  TreeNode root(0); cur.push_back(&root);
  long long i = 0, n = v.size(), x;
  while (i < n) {
    for (auto p: cur) {
      if ((x = v[i++]) != null) { p->left = new TreeNode(x); next.push_back(p->left); }
      if (i == n || p == &root) continue;
      if ((x = v[i++]) != null) { p->right = new TreeNode(x); next.push_back(p->right); }
    }
    cur.swap(next); next.clear();
  }
  return root.left;
}

template<class T>
ostream& operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  for (int i = 0; i < v.size(); ++i) os << (i > 0 ? "," : "") << v[i];
  os << "]";
  return os;
}

ostream& operator<<(ostream &os, const ListNode *p) {
  vector<int> v;
  while (p) { v.push_back(p->val); p = p->next; }
  return os << v;
}

ostream& operator<<(ostream &os, const TreeNode *t) {
  vector<string> v;
  queue<const TreeNode*> cur, next;
  if (t) cur.push(t);

  while (!cur.empty()) {
    t = cur.front(); cur.pop();
    v.push_back(t ? to_string(t->val) : "null");
    if (t && (t->left || t->right)) {
      next.push(t->left);
      if (t->right || !cur.empty()) next.push(t->right);
    }
    if (cur.empty()) cur.swap(next);
  }
  return os << v;
}

/*
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (27.17%)
 * Total Accepted:    182.7K
 * Total Submissions: 672.4K
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Example:
 * 
 * 
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * 
 * 
 */
	unsigned int test[] = {2,3,5,7,11};
unsigned int FastPowerMod(unsigned long mod, unsigned long base,unsigned long power){
	//printf("base = %lu,power = %lu,mod = %lu\n",base,power,mod);
	long res = 1;
	base %= mod;
	while(power > 0){
		if(power & 1)
			res = (res * base) % mod;
		power >>= 1;
		base = (base*base) % mod;
		//printf("base = %lu,power = %lu,res = %lu\n",base,power,res);
	}
	//printf("res = %lu\n",res%mod);
	return res;
}
bool passMullerRabin(unsigned long num,unsigned int testNum){
	unsigned long d = (num-1)>>1;
	while(!(d & 1))
		d >>=1;
	unsigned int x = FastPowerMod(num,testNum,num-1);
	if(x != 1)
		return 0;
	while(d != num-1){
		x = (x * x) % num;
		if(!(x == 1 || x == num-1))
			return 0;
		d <<=1;
	}
	return 1;
}
bool isPrime(unsigned long num,int times){
	if(num == 2)
		return 1;
	if(num == 1 ||!(num % 2))
		return 0;
	for(int i = 0; i < times && num > test[i];i++)
		if(!passMullerRabin(num,test[i]))
			return 0;
	return 1;
}
class Solution {
public:
    int countPrimes(int n) {
		int count = 1;
        for(int i = 3;i < n;i += 2)
			if(isPrime(i,5))
				count++;
		return count;
    }
};

int main() {
  Solution s;
  decay<int>::type p0 = 10;
  auto res = s.countPrimes(p0);
  cout << res << endl;
  return 0;
}
