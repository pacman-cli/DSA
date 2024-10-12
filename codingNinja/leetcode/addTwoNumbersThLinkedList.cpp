#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    // Dummy node to form the new list
    ListNode *dummy = new ListNode(0);
    ListNode *current = dummy;
    int carry = 0;

    // Loop while either list still has nodes or there is a carry to process
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
      // Get values of the current nodes of l1 and l2, or 0 if null
      // int val1 = (l1 != nullptr) ? l1->val : 0;
      // int val2 = (l2 != nullptr) ? l2->val : 0;

      int val1 = 0; // Initialize val1
      if (l1 != nullptr) {
        val1 = l1->val; // Assign the value from l1 if it exists
      }

      int val2 = 0; // Initialize val2
      if (l2 != nullptr) {
        val2 = l2->val; // Assign the value from l2 if it exists
      }
      // Sum of current digits and carry
      int sum = val1 + val2 + carry;
      carry = sum / 10;

      // Create a new node for the current digit (sum % 10)
      current->next = new ListNode(sum % 10);
      current = current->next;

      // Move to the next nodes in l1 and l2 if they exist
      if (l1 != nullptr)
        l1 = l1->next;
      if (l2 != nullptr)
        l2 = l2->next;
    }

    // Return the next node of dummy as it points to the result list's head
    return dummy->next;
  }
};

// Helper function to print the linked list
void printList(ListNode *node) {
  while (node != nullptr) {
    cout << node->val;
    if (node->next != nullptr) {
      cout << " -> ";
    }
    node = node->next;
  }
  cout << endl;
}

int main() {
  // Example 1: l1 = [2, 4, 3], l2 = [5, 6, 4]
  ListNode *l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(3);

  ListNode *l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(4);

  Solution sol;
  ListNode *result = sol.addTwoNumbers(l1, l2);

  // Print the result
  cout << "Sum: ";
  printList(result);

  return 0;
}
