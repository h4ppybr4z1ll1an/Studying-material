//My solution to the problem found at https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle/


bool has_cycle(SinglyLinkedListNode* head) {
    if(!head)
        return false;

    else {
        std::map<SinglyLinkedListNode*, int> node_map;
        node_map.insert(std::pair<SinglyLinkedListNode*, int>(head, 1));
        auto z = head;

        while(z) {
            z = z->next;
            if(node_map.count(z))
                return true;
            else 
                node_map.insert(std::pair<SinglyLinkedListNode*, int>(z, 1));
        }
    }
    return false;
}
