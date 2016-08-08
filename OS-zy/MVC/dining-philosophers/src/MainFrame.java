import java.awt.*;
import java.awt.event.*;
public class MainFrame extends Frame{
    public static final int CIRCLE_RAD = 160;
    public static final int WIDTH = 800;
    public static final int HEIGH = 600;

    DiningPhilosophers dp;
    ChopstickArray cArray;
    
    public void paint(Graphics g) {
        Color color = g.getColor();
        g.setColor(Color.red);
        g.drawOval(WIDTH / 2 - CIRCLE_RAD, HEIGH / 2 - CIRCLE_RAD, CIRCLE_RAD * 2, CIRCLE_RAD * 2);
        g.setColor(color);
        dp.draw(g);
        
        for(int i = 0; i < cArray.size ; i++){
            if (2 ==dp.state[i] ) {
                cArray.setchopsticstate((i+4)%5, true);
                cArray.setchopsticstate(i, true);
            }
        }
        cArray.draw(g);
        for(int i = 0; i < cArray.size ; i++){
                cArray.setchopsticstate(i, false);
        }
        
    }
    public void init() {
        
         dp = new DiningPhilosophers(5);
         cArray = new ChopstickArray(5);
        
        int x, y;
        int x1, y1, x2, y2;
        x1 = 400;//从正上方顺时针排序
        y1 = 115;
        x2 = 400;
        y2 = 165;
        x = 400 - 50;
        y = 70 - 50;
        dp.p[3].set(3,this,x1, y1, x2, y2, x, y);
        
        x1 = (int) (400 + 185 * Math.sin(72.0 / 180 * 3.1415926));
        y1 = (int) (300 - 185 * Math.cos(72.0 / 180 * 3.1415926));
        x2 = (int) (400 + 135 * Math.sin(72.0 / 180 * 3.1415926));
        y2 = (int) (300 - 135 * Math.cos(72.0 / 180 * 3.1415926));
        x = (int)(400 + 230 * Math.sin(72.0 / 180 * 3.1415926) - 50);
        y = (int)(300 - 230 * Math.cos(72.0 / 180 * 3.1415926) - 50);
        dp.p[4].set(4,this,x1, y1, x2, y2, x, y);
        
        x1 = (int)(400 + 185 * Math.sin(36.0 / 180 * 3.1415926));
        y1 = (int)(300 + 185 * Math.cos(36.0 / 180 * 3.1415926));
        x2 = (int)(400 + 135 * Math.sin(36.0 / 180 * 3.1415926));
        y2 = (int)(300 + 135 * Math.cos(36.0 / 180 * 3.1415926));
        x = (int)(400 + 230 * Math.sin(36.0 / 180 * 3.1415926) - 50);
        y = (int)(300 + 230 * Math.cos(36.0 / 180 * 3.1415926) - 50);
        dp.p[0].set(0,this,x1, y1, x2, y2, x, y);
        
        x1 = (int)(400 - 185 * Math.sin(36.0 / 180 * 3.1415926));
        y1 = (int)(300 + 185 * Math.cos(36.0 / 180 * 3.1415926));
        x2 = (int)(400 - 135 * Math.sin(36.0 / 180 * 3.1415926));
        y2 = (int)(300 + 135 * Math.cos(36.0 / 180 * 3.1415926));
        x = (int)(400 - 230 * Math.sin(36.0 / 180 * 3.1415926) - 50);
        y = (int)(300 + 230 * Math.cos(36.0 / 180 * 3.1415926) - 50);
        dp.p[1].set(1,this,x1, y1, x2, y2, x, y);     
        
        x1 = (int)(400 - 185 * Math.sin(72.0 / 180 * 3.1415926));
        y1 = (int)(300 - 185 * Math.cos(72.0 / 180 * 3.1415926));
        x2 = (int)(400 - 135 * Math.sin(72.0 / 180 * 3.1415926));
        y2 = (int)(300 - 135 * Math.cos(72.0 / 180 * 3.1415926));
        x = (int)(400 - 230 * Math.sin(72.0 / 180 * 3.1415926) - 50);
        y = (int)(300 - 230 * Math.cos(72.0 / 180 * 3.1415926) - 50);
        dp.p[2].set(2,this,x1, y1, x2, y2, x, y);
        
    }
    public void launchFrame() {
        init();
        setLocation(100, 100);
        setSize(WIDTH, HEIGH);
        setTitle("DiningPhilosophers");
        setResizable(false);
        setBackground(Color.white);
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
        addKeyListener(new KeyMonitor());
        setVisible(true);
    }
    public static void main(String[] args) {
        new MainFrame().launchFrame();
    }
    private class KeyMonitor extends KeyAdapter {
        public void keyPressed(KeyEvent e) {
            int key = e.getKeyCode();
            if(key == KeyEvent.VK_ENTER) {
                run();
            }
        }
    }
    public void run() {
        for (int i = 0; i < dp.size; i++) {
            new Thread(dp.p[i]).start();
        }
    }
    
}
