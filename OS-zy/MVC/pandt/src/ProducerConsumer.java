public class ProducerConsumer {
    public static void main(String[] args) {
    }
}
class WoTou {
    public int id; 
    WoTou(int id) {
        this.id = id;
    }
    public String toString() {
        return "WoTou : " + id;
    }
}
class SyncStack {
    //int number = 0;
	int p = 0;
    int c = 0;
    int index = 0;
    WoTou[] arrWT = new WoTou[3];
    public synchronized void push(WoTou wt) {
        while(index == arrWT.length) {
            try {
                this.wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        this.notifyAll();       
        arrWT[index] = wt;
        index ++;
    }
    public synchronized WoTou pop() {
        while(index == 0) {
            try {
                this.wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        this.notifyAll();
        index--;
        return arrWT[index];
    }
}
class Producer implements Runnable {
    SyncStack ss = null;
    Producer(SyncStack ss) {
        this.ss = ss;
    }
    public void run() {
        for(int i=0; i<100; i++) {
            WoTou wt = new WoTou(i);
            ss.push(wt);
            ss.p = i ;
//System.out.println("生产了: " + wt);

            try {
                Thread.sleep((int)(Math.random() * 800));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            
        }
    }
}

class Consumer implements Runnable {
    SyncStack ss = null;
    Consumer(SyncStack ss) {
        this.ss = ss;
    }
    public void run() {
        for(int i=0; i<100; i++) {
            WoTou wt = ss.pop();
            ss.c = i ;
//System.out.println("消费了: " + wt);
//System.out.println("消费了: " + ss.number);            
//ss.number ++;
            try {
                Thread.sleep((int)(Math.random() * 800));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }           
        }
    }
}