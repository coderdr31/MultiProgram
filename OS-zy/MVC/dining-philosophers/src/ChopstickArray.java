import java.awt.Color;
import java.awt.Graphics;

public class ChopstickArray {
    Chopstick[] chopsticks;
    int size;
    public ChopstickArray(int s) {
        size = s;
        int x1, y1, x2, y2;
        chopsticks = new Chopstick[size];// 从正下方顺时针排序
        x1 = 400;
        y1 = 485;
        x2 = 400;
        y2 = 435;
        chopsticks[0] = new Chopstick(0, x1, y1, x2, y2);
        x1 = (int) (400 - 185 * Math.sin(72.0 / 180 * 3.1415926));
        y1 = (int) (300 + 185 * Math.cos(72.0 / 180 * 3.1415926));
        x2 = (int) (400 - 135 * Math.sin(72.0 / 180 * 3.1415926));
        y2 = (int) (300 + 135 * Math.cos(72.0 / 180 * 3.1415926));
        chopsticks[1] = new Chopstick(1, x1, y1, x2, y2);
        x1 = (int) (400 - 185 * Math.sin(36.0 / 180 * 3.1415926));
        y1 = (int) (300 - 185 * Math.cos(36.0 / 180 * 3.1415926));
        x2 = (int) (400 - 135 * Math.sin(36.0 / 180 * 3.1415926));
        y2 = (int) (300 - 135 * Math.cos(36.0 / 180 * 3.1415926));
        chopsticks[2] = new Chopstick(2, x1, y1, x2, y2);
        x1 = (int) (400 + 185 * Math.sin(36.0 / 180 * 3.1415926));
        y1 = (int) (300 - 185 * Math.cos(36.0 / 180 * 3.1415926));
        x2 = (int) (400 + 135 * Math.sin(36.0 / 180 * 3.1415926));
        y2 = (int) (300 - 135 * Math.cos(36.0 / 180 * 3.1415926));
        chopsticks[3] = new Chopstick(3, x1, y1, x2, y2);
        x1 = (int) (400 + 185 * Math.sin(72.0 / 180 * 3.1415926));
        y1 = (int) (300 + 185 * Math.cos(72.0 / 180 * 3.1415926));
        x2 = (int) (400 + 135 * Math.sin(72.0 / 180 * 3.1415926));
        y2 = (int) (300 + 135 * Math.cos(72.0 / 180 * 3.1415926));
        chopsticks[4] = new Chopstick(4, x1, y1, x2, y2);
    }

    public void setchopsticstate(int id, boolean bool) {
        chopsticks[id].used = bool;
    }
    public void draw(Graphics g) {
        for (int i = 0; i < chopsticks.length; i++) {
            chopsticks[i].draw(g);
        }
    }
    class Chopstick {
        int x1, y1, x2, y2;
        private int id;

        boolean used = false;

        public void draw(Graphics g) {
            if (!used) {
                Color color = g.getColor();
                g.setColor(Color.black);
                g.drawLine(x1, y1, x2, y2);
                g.setColor(color);
            }
        }

        public Chopstick(int id, int x1, int y1, int x2, int y2) {
            this.id = id;
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
        }

    }
}
