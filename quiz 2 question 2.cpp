#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *detectCycle(ListNode *head) {
    if (!head || !head->next)
        return nullptr;

    ListNode *slow = head;
    ListNode *fast = head;

    // Detect cycle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        // If they meet, there's a cycle
        if (slow == fast)
            break;
    }

    // No cycle found
    if (fast == nullptr || fast->next == nullptr)
        return nullptr;

    // Move slow pointer back to head
    slow = head;

    // Move both pointers at the same pace until they meet
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    // Return the node where the cycle begins
    return slow;
}

int main() {
    // Example usage
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // Cycle

    ListNode *cycleStart = detectCycle(head);
    if (cycleStart)
        cout << "Cycle starts at node with value: " << cycleStart->val << endl;
    else
        cout << "No cycle detected." << endl;

    // Free memory
    while (head) {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
