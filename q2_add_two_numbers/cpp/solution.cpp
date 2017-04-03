/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode rtn_head(0), *rtn_list = &rtn_head;
      int last_res = 0, tempsum = 0;
      while (l1 || l2 || last_res) {
        tempsum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + last_res;
        last_res = tempsum >= 10 ? tempsum / 10 : 0;
        tempsum -= last_res * 10;
        rtn_list->next = new ListNode(tempsum);
        rtn_list = rtn_list->next;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
      }
      return rtn_head.next;
    }
};
