public class LinkedList{
    public static class ListNode{
        int data;
        ListNode next;

        public ListNode (int data){
            this.data = data;
            this.next = null;
        }
    }

    public static ListNode head;
    public static ListNode tail;
    int size = 0;

    //Add First
    public void addFirst(int data){
        ListNode newNode = new ListNode(data);
        newNode.next = head; //link
        head = newNode;
        size++;
    }

    //Add Last
    public void addLast(int data){
        ListNode newNode = new ListNode(data);
        if(head == null){
            head = tail = newNode;
            return;
        }
        tail.next = newNode;
        tail = newNode;
        size++;
    }

    //Add Between
    public void add(int idx, int data){
        if(idx == 0){
            addFirst(data);
            return;
        }
        ListNode newNode = new ListNode(data);
        ListNode temp = head;
        int i = 0;
        while(i < idx-1){
            temp = temp.next;
            i++;
        }
        newNode.next = temp.next;
        temp.next = newNode;
        size++;
    }

    //Remove First
    public int removeFirst(){
        if(size == 0){
            System.out.println("LL is empty");
            return Integer.MIN_VALUE;
        } else if(size == 1){
            int val = head.data;
            head = tail = null;
            size = 0;
            return val;
        }
        int val = head.data;
        head = head.next;
        size--;
        return val;
    }

    //Remove Last
    public int removeLast(){
        if(size == 0){
            System.out.println("LL is empty");
            return Integer.MIN_VALUE;
        }else if(size == 1){
            int val = head.data;
            head = tail = null;
            size = 0;
            return val;
        }
        ListNode prev = head;
        for(int i=0; i<size-1; i++){
            prev = prev.next;
        }
        int val = prev.next.data;
        prev.next = null;
        tail = prev;
        size--;
        return val;
    }

    //Travarse a Linked List
    public void print(){
        if(head == null){
            System.out.println("LL is empty");
            return;
        }
        ListNode temp = head;
        while(temp != null){
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    public static ListNode mid(ListNode head){
        ListNode slow = head;
        ListNode fast = head.next;

        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }

    public static ListNode marge(ListNode head, ListNode head2){
        ListNode margeLL = new ListNode(-1);
        ListNode temp = margeLL;
        while(head != null && head2 != null){
            if(head.data <= head2.data){
                temp.next = head;
                head = head.next;
                temp = temp.next;
            }
            else{
                temp.next = head2;
                head2 = head2.next;
                temp = temp.next;
            }
        }

        while(head != null){
            temp.next = head;
            head = head.next;
            temp = temp.next;
        }

        while(head2 != null){
            temp.next = head2;
            head2 = head2.next;
            temp = temp.next;
        }

        return margeLL.next;
    }

    public static ListNode margeSort(ListNode head){
        if(head == null || head.next == null){
            return head;
        }
        ListNode mid1 = mid(head);
        ListNode head2 = mid1.next;
        mid1.next = null;

        ListNode newleft = margeSort(head);
        ListNode newright = margeSort(head2);

        return marge(newleft, newright);
    }
    
    public static ListNode getMid(ListNode head){
        ListNode slow = head;
        ListNode fast = head.next;

        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }

    public static ListNode reverse(ListNode head){
        ListNode prev = head;
        ListNode current = head.next;
        ListNode nextNode = current.next;
        prev.next = null;
        while(nextNode != null){
            current.next = prev;
            prev = current;
            current = nextNode;
            nextNode = current.next;
        }
        current.next = prev;
        head = current;
        return head;
    }

    public static void reorderList(ListNode head) {
        ListNode ptr = head;
        ListNode mid = getMid(ptr);
        ListNode head2 = mid.next;
        mid.next = null;
        
        ListNode ptr1 = head;
        ListNode ptr2 = head2;
        ListNode reLL = new ListNode(ptr1.data);
        ListNode ptr3 = reLL.next;
        while(ptr1 != null && ptr2 != null){
            ptr3 = ptr2;
            ptr2 = ptr2.next;
            ptr3 = ptr3.next;
            ptr3 = ptr1;
            ptr1 = ptr1.next;
            ptr3 = ptr3.next;
        }

        while(ptr1 != null){
            ptr3 = ptr1;
            ptr1 = ptr1.next;
            ptr3 = ptr3.next;
        }

        while(ptr2 != null){
            ptr3 = ptr2;
            ptr2 = ptr2.next;
            ptr3 = ptr3.next;
        }

        head = reLL;
    }
    public static void main(String args[]){
        LinkedList ll = new LinkedList();
        ll.addFirst(1);
        ll.addFirst(2);
        ll.addFirst(3);
        ll.addFirst(4);
        ll.addFirst(5);

        ll.print();
        reorderList(ll.head);
        ll.print();
    }
}