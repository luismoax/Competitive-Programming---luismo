

// Complete the has_cycle function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
 // Luismo
bool has_cycle(SinglyLinkedListNode* head)
{
    map<SinglyLinkedListNode*, int> hh;
    SinglyLinkedListNode* curr = head;
    while(curr != NULL)
    {
        if(hh.find(curr) != hh.end())
            return true;
        hh[curr] = 1;
        curr = curr->next;
    }
    return false;
}

