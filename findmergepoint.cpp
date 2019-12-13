//My solution to the problem found at https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists/


int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    
    std::map<SinglyLinkedListNode*, bool> node_map;
    
    while(head1 || head2) {
        
        if(node_map.count(head1) || node_map.count(head2))
            return node_map.count(head1) ? head1->data : head2->data;

        if(head1 == head2)
            return head1->data;

        if(head1) {
            node_map.insert(std::pair<SinglyLinkedListNode*, bool>(head1, 0));
            head1 = head1->next;
        }

        if(head2) {
            node_map.insert(std::pair<SinglyLinkedListNode*, bool>(head2, 0));
            head2 = head2->next;
        }
        

    }

    return 0;

}
