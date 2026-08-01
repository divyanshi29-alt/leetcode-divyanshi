/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    int len = 1;
    struct ListNode *tail = head;

    while (tail->next) {
        tail = tail->next;
        len++;
    }

    k %= len;
    if (k == 0)
        return head;

    tail->next = head;

    int steps = len - k;
    struct ListNode *newTail = head;

    while (--steps)
        newTail = newTail->next;

    struct ListNode *newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}