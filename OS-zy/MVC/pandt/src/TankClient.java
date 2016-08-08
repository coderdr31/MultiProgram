import java.awt.*;
import java.awt.event.*;

public class TankClient extends Frame {
    public static final int GAME_WIDTH = 800;
    public static final int GAME_HEIGHT = 600;
    boolean init1 = false;
    boolean init2 = false;

    
    SyncStack ss;
    Producer p;
    Consumer c;
    Police police;
    Theif theif;

    
    
    private static Toolkit tk = Toolkit.getDefaultToolkit(); // 获取默认工具
    private static Image[] images = { // 静态
            tk.getImage(TankClient.class.getClassLoader().getResource("picture/0.jpg")), // 反射机制，装载到内存
            tk.getImage(TankClient.class.getClassLoader().getResource("picture/1.jpg"))

    };
    private class Theif {
        int x_p = 10, y_p = GAME_HEIGHT / 2;
        void draw(Graphics g) {
           
            Color c = g.getColor();
            g.setColor(Color.RED);
            g.fillOval(x_p + 7 * ss.c, y_p, 5, 5);
            
            g.setColor(c);
            g.drawImage(images[0], x_p + 7 * ss.c, y_p - 40, null);
            g.drawString("跑了" + ss.c + "步", x_p + 7 * ss.c, y_p - 40);
        }
    }
    private class Police {
        int x_p = 10, y_p = GAME_HEIGHT / 2;
        void draw(Graphics g) {
            
            Color c = g.getColor();
            g.setColor(Color.black);
            g.fillOval(x_p + 7 * ss.p, y_p, 5, 5);
            g.setColor(c);
            g.drawImage(images[1], x_p + 7 * ss.p, y_p, null);
            g.drawString("跑了" + ss.p + "步", x_p + 7 * ss.p, y_p + 40);
        }
    }

    public void paint(Graphics g) {
        
        Color c = g.getColor();
        g.setColor(Color.GREEN);
        g.drawLine(10, GAME_HEIGHT / 2, 710, GAME_HEIGHT / 2); // 画跑道
        g.setColor(c);
        police.draw(g);
        theif.draw(g);
        
    }

    public void lauchFrame() {
        this.setLocation(400, 300);
        this.setSize(GAME_WIDTH, GAME_HEIGHT);
        this.setTitle("produce and consume");
        this.setBackground(Color.blue);
        this.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
        this.addKeyListener(new KeyMonitor());
        this.setResizable(false);
        setVisible(true);
        ss = new SyncStack();
        p = new Producer(ss);
        c = new Consumer(ss);
        police = new Police();
        theif = new Theif();
    }
    private class KeyMonitor extends KeyAdapter {

        @Override
        public void keyPressed(KeyEvent e) {
            if (KeyEvent.VK_ENTER == e.getKeyCode()) {

                new Thread(p).start();
                new Thread(c).start();
                new Thread(new PaintThread()).start();
            }
        }

    }

    public static void main(String[] args) {
        new TankClient().lauchFrame();

    }

    private class PaintThread implements Runnable {

        public void run() {
            while (true) {
                repaint();
                try {
                    Thread.sleep(50);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

}
