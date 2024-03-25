public class Linkedlist {
    private Lnode head;

    private static class Lnode {
        private int data;
        private Lnode next;

        public Lnode(int data) {
            this.data = data;
            this.next = null;
        }
    }

    public boolean cycleDetection() {
        Lnode current = head;

        while (current != null && current.next != null) {
            Lnode Fastptr = head;
            Lnode Slowptr = head;
            while (Fastptr != null && Fastptr.next != null) {
                Fastptr = Fastptr.next.next;
                Slowptr = Slowptr.next;

                if (Fastptr == Slowptr) {
                    return true;
                }
            }
        }
        return false;
    }


    public static void main(String[]args){
        Linkedlist sll = new Linkedlist();

        sll.head = new Lnode (3);
        Lnode scnd = new Lnode( 2);
        Lnode thrd = new Lnode( 0);
        Lnode frth = new Lnode( -4);

        sll.head.next = scnd;
        scnd.next = thrd;
        thrd.next = frth;
        frth.next = scnd;

        System.out.println(sll.cycleDetection());
    }
}
