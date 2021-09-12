/*
*    author:  shinter_pres
*    created: 16.07.2021 01:22:52
*/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  int getSize(ListNode *l) {
    int cnt = 0;
    while (l != NULL) {
      cnt++;
      l = l->next;
    }
    return cnt;
  }
  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      int sizeFirst = getSize(l1);
      int sizeSecond = getSize(l2);

      if (sizeSecond > sizeFirst) {
        ListNode *tmp;
        tmp = l2;
        l2 = l1;
        l1 = tmp;
      }
      int carry = 0; // 繰り上がり
      int sum = 0;

      ListNode *head = l1;
      ListNode *prev = NULL;
      while (l2 != NULL) {
        prev = l1;
        sum = carry + l1->val + l2->val;
        int quo = sum % 10;
        carry = sum / 10;
        l1->val = quo;
        l1 = l1->next;
        l2 = l2->next;
      }

      while (carry and l1 != NULL) {
        prev = l1;
        sum = carry + l1->val;
        int quo = sum % 10;
        carry = sum / 10;
        l1->val = quo;
        l1 = l1->next;
      }

      if (carry) {
        ListNode *extra = new ListNode();
        extra->val = carry;
        extra->next = NULL;
        prev->next = extra;
      }
      return head;
    }
};

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  return 0;
}
