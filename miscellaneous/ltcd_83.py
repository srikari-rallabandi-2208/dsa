'''
LeetCode - problem 83
'''

    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        curr = head 
        while curr :
            while curr.next and curr.next.val == curr.val:
                curr.next = curr.next.next
            curr = curr.next
        return head
