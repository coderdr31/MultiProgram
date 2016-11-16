package com.by5.editor;
import javax.swing.*;
import javax.swing.border.AbstractBorder;
import javax.swing.event.*;
import javax.swing.text.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.HashSet;
import java.util.Set;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class LineNumberBorder extends AbstractBorder { 
    public LineNumberBorder() {
    }

    public Insets getBorderInsets(Component c) {
        return getBorderInsets(c, new Insets(0, 0, 0, 0));
    }

    public Insets getBorderInsets(Component c, Insets insets) {
        if (c instanceof JTextPane) {
            insets.left = 20;
        }
        return insets;
    }

    public boolean isBorderOpaque() {
        return false;
    }

    public void paintBorder(Component c, Graphics g, int x, int y, int width, int height) {
        java.awt.Rectangle clip = g.getClipBounds();
        FontMetrics fm = g.getFontMetrics();
        int fontHeight = fm.getHeight();
        int ybaseline = y + fm.getAscent();
        int startingLineNumber = (clip.y / fontHeight) + 1;
        if (startingLineNumber != 1) {
            ybaseline = y + startingLineNumber * fontHeight - (fontHeight - fm.getAscent());
        }
        int yend = ybaseline + height;
        if (yend > (y + height)) {
            yend = y + height;
        }
        g.setColor(Color.pink);
        while (ybaseline < yend) {
            String label = padLabel(startingLineNumber, 0, true);
            g.drawString(label, 0, ybaseline);
            ybaseline += fontHeight;
            startingLineNumber++;
        }
    }

    private String padLabel(int lineNumber, int length, boolean addSpace) {
        StringBuffer buffer = new StringBuffer();
        buffer.append(lineNumber);
        for (int count = (length - buffer.length()); count > 0; count--) {
            buffer.insert(0, ' ');
        }
        if (addSpace) {
            buffer.append(' ');
        }
        return buffer.toString();
    }
}