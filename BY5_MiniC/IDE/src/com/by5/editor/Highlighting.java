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

class Highlighting implements DocumentListener {
    private Set<String> keywords;
    private Style keywordStyle;
    private Style normalStyle;

    public Highlighting(JTextPane pane) {

        keywordStyle = ((StyledDocument) pane.getDocument()).addStyle("Keyword_Style", null);
        normalStyle = ((StyledDocument) pane.getDocument()).addStyle("Keyword_Style", null);
        StyleConstants.setForeground(keywordStyle, Color.RED);
        StyleConstants.setForeground(normalStyle, Color.white);

        keywords = new HashSet<String>() {
            {
                add("private");
                add("protected");
                add("public");
                add("abstract");
                add("class");
                add("extends");
                add("final");
                add("implements");
                add("interface");
                add("native");
                add("new");
                add("static");
                add("strictfp");
                add("synchronized");
                add("transient");
                add("volatile");
                add("break");
                add("continue");
                add("return");
                add("do");
                add("while");
                add("if");
                add("else");
                add("for");
                add("instanceof");
                add("switch");
                add("case");
                add("default");
                add("assert");
                add("catch");
                add("finally");
                add("throw");
                add("throws");
                add("try");
                add("import");
                add("package");
                add("boolean");
                add("byte");
                add("char");
                add("double");
                add("float");
                add("int");
                add("long");
                add("short");
                add("null");
                add("super");
                add("this");
                add("void");
                add("goto");
            }
        };
    }

    public void colouring(StyledDocument doc, int pos, int len) throws BadLocationException {
        int start = indexOfWordStart(doc, pos);
        int end = indexOfWordEnd(doc, pos + len);
        char ch;
        while (start < end) {
            ch = getCharAt(doc, start);
            if (Character.isLetter(ch) || ch == '_') {
                start = colouringWord(doc, start);
            } else {
                SwingUtilities.invokeLater(new ColouringTask(doc, start, 1, normalStyle));
                ++start;
            }
        }
    }

    public int colouringWord(StyledDocument doc, int pos) throws BadLocationException {
        int wordEnd = indexOfWordEnd(doc, pos);
        String word = doc.getText(pos, wordEnd - pos);

        if (keywords.contains(word)) {
            SwingUtilities.invokeLater(new ColouringTask(doc, pos, wordEnd - pos, keywordStyle));
        } else {
            SwingUtilities.invokeLater(new ColouringTask(doc, pos, wordEnd - pos, normalStyle));
        }

        return wordEnd;
    }

    public char getCharAt(Document doc, int pos) throws BadLocationException {
        return doc.getText(pos, 1).charAt(0);
    }

    public int indexOfWordStart(Document doc, int pos) throws BadLocationException {
        while (pos > 0 && isWordCharacter(doc, pos - 1))
            pos--;
        return pos;
    }

    public int indexOfWordEnd(Document doc, int pos) throws BadLocationException {
        while (isWordCharacter(doc, pos))
            pos++;
        return pos;
    }

    public boolean isWordCharacter(Document doc, int pos) throws BadLocationException {
        char ch = getCharAt(doc, pos);
        return (Character.isLetter(ch) || Character.isDigit(ch) || ch == '_');
    }

    @Override
    public void changedUpdate(DocumentEvent e) {
    }

    @Override
    public void insertUpdate(DocumentEvent e) {
        try {
            colouring((StyledDocument) e.getDocument(), e.getOffset(), e.getLength());
        } catch (BadLocationException e1) {
            e1.printStackTrace();
        }
    }

    @Override
    public void removeUpdate(DocumentEvent e) {
        try {
            colouring((StyledDocument) e.getDocument(), e.getOffset(), 0);
        } catch (BadLocationException e1) {
            e1.printStackTrace();
        }
    }

    private class ColouringTask implements Runnable {
        private StyledDocument doc;
        private Style style;
        private int pos;
        private int len;

        public ColouringTask(StyledDocument doc, int pos, int len, Style style) {
            this.doc = doc;
            this.pos = pos;
            this.len = len;
            this.style = style;
        }

        public void run() {
            try {
                doc.setCharacterAttributes(pos, len, style, true);
            } catch (Exception e) {
                //
            }
        }
    }
}