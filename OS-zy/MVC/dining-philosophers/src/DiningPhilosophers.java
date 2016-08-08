import java.awt.Color;
import java.awt.Graphics;

public class DiningPhilosophers {
    public DiningPhilosophers(int x) {
        size = x;
        state = new int[size]; // 0-thinking,1-hungry,2-eating
        p = new Philosopher[size];
        for (int i = 0; i < size; i++) {
            p[i] = new Philosopher();
        }
    }
    int size;
    public int[] state;
    Philosopher[] p;

    public void draw(Graphics g) {
        for (int i = 0; i < size; i++) {
            p[i].draw(g);
        }

    }

    synchronized void test(int x) {
        int k = x;
        if (2 != state[(k + 4) % size] && 1 == state[k] && 2 != state[(k + 1) % size]) {
            state[k] = 2;
        }
    }

    class Philosopher implements Runnable {

        int i; // 第几位
        int x1, y1, x2, y2; // 筷子的位置
        int x, y; // 哲学家的位置
        MainFrame mf; // 图形化界面
        int sleepTime = 3000;

        public void draw(Graphics g) {

            Color color = g.getColor();
            switch (state[i]) {
                case 0 :
                    g.setColor(Color.gray);
                    g.fillOval(x, y, 100, 100);
                    g.setColor(Color.black);
                    g.drawString("thinking", x + 40, y + 40);
                    break;
                case 1 :
                    g.setColor(Color.red);
                    g.fillOval(x, y, 100, 100);
                    g.setColor(Color.black);
                    g.drawString("hungry", x + 40, y + 40);
                    break;
                case 2 :
                    g.setColor(Color.green);
                    g.fillOval(x, y, 100, 100);
                    g.setColor(Color.black);
                    g.drawString("eating", x + 40, y + 40);

                    g.setColor(Color.yellow);
                    g.drawLine(x1, y1, x2, y2);
                    break;

                default :
                    break;
            }
            g.setColor(color);

        }
        public void set(int i, MainFrame mf, int x1, int y1, int x2, int y2, int x, int y) {

            state[i] = 0;

            this.mf = mf;
            this.i = i;
            this.x1 = x1;
            this.x2 = x2;
            this.y1 = y1;
            this.y2 = y2;
            this.x = x;
            this.y = y;

        }

        synchronized void pickup() {
            // System.out.println("up" +i );
            state[i] = 1;
            mf.repaint();
            try {
                Thread.sleep(sleepTime/4);
            } catch (Exception e) {
                e.printStackTrace();
            }
            test(i);
            while (state[i] != 2) {
                new Thread().yield();
            }

            state[i] = 2;
            // System.out.println("eat" +i );
            mf.repaint();
            try {
                Thread.sleep(sleepTime);
            } catch (Exception e) {
                e.printStackTrace();
            }
            try {
                Thread.sleep((int) (Math.random() * 7000));
            } catch (InterruptedException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }

        }

        synchronized void putdown() {
            // System.out.println("down" +i );
            state[i] = 0;
            test((i + 4) % 5);
            test((i + 1) % 5);
            mf.repaint();
            try {
                Thread.sleep(sleepTime);
            } catch (Exception e) {
                e.printStackTrace();
            }

        }

        void think() {
            state[i] = 0;
            // System.out.println("think" +i );
            try {
                Thread.sleep((int) (Math.random() * 8000));
            } catch (InterruptedException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }

        public void run() {
            while (true) {
                think();
                pickup();
                putdown();
            }
        }

    }

}
