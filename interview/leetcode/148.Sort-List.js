/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var sortList = function(head) {
    var arr = []
    var curr = head
    while(curr){
        arr.push(Number(curr.val))
        curr = curr.next
    }
    
    arr.sort((a,b)=>a-b)
    curr = head
    while(arr.length){
        var val = arr.shift()
        curr.val = val
        curr = curr.next
    }
    
    return head
};