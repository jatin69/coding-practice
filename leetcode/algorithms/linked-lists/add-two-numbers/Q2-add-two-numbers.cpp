/*
 * Author : Jatin Rohilla
 * Date   : 21-06-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 */


#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	// base cases
	if (l1->val == 0 && l1->next == NULL) {
		return l2;
	} else if (l2->val == 0 && l2->next == NULL) {
		return l1;
	}


	ListNode* resHead = NULL;
	ListNode* resTail = NULL;

	int sum = 0;
	int carry = 0;

	while (l1 && l2) {
		sum = l1->val + l2->val + carry;
		if (sum > 9) {
			sum -= 10;
			carry = 1;
		} else {
			carry = 0;
		}

		if (resHead == NULL) {
			resHead = resTail = new ListNode(sum);
		} else {
			resTail->next = new ListNode(sum);
			resTail = resTail->next;
		}

		l1 = l1->next;
		l2 = l2->next;
	}

	while (l1) {
		sum = l1->val + carry;
		if (sum > 9) {
			sum -= 10;
			carry = 1;
		} else {
			carry = 0;
		}

		resTail->next = new ListNode(sum);
		resTail = resTail->next;

		l1 = l1->next;
	}

	while (l2) {
		sum = l2->val + carry;
		if (sum > 9) {
			sum -= 10;
			carry = 1;
		} else {
			carry = 0;
		}

		resTail->next = new ListNode(sum);
		resTail = resTail->next;

		l2 = l2->next;
	}

	if (carry) {
		resTail->next = new ListNode(carry);
		resTail = resTail->next;
	}

	return resHead;
}


// JUNE 2019 solution

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
        ListNode* dummy = new ListNode(-1);
        ListNode* l3 = dummy;

        int d1, d2, val, carry = 0;
        while(l1!=nullptr || l2!=nullptr || carry!=0){
            d1 = (l1 ? l1->val : 0);
            d2 = (l2 ? l2->val : 0);
            val = (d1 + d2 + carry);
            carry = val/10;
            val = val%10;
            l3->next = new ListNode(val);
            l3 = l3->next;
            l1 = (l1 ? l1->next : nullptr);
            l2 = (l2 ? l2->next : nullptr);
        }

        return dummy->next;
    }
};


int main() {
	/*
	Example :

	Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
	Output: 7 -> 0 -> 8
	Explanation: 342 + 465 = 807

	test cases :
	2->3 		+ 	0->2 	=	 2->5
	9->9->9 	+	 1 		= 	0->0->0->1

	*/

	return 0;
}



