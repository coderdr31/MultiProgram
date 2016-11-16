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


class Fonts implements ActionListener { 
    final JDialog fontDialog;
    final JTextField tfFont, tfSize, tfStyle;
    final int fontStyleConst[] = { Font.PLAIN, Font.ITALIC, Font.BOLD, Font.BOLD + Font.ITALIC };
    final JList listStyle, listFont, listSize;
    JLabel sample;

    public Fonts() {
//        fontDialog = new JDialog(EditorFrame.getFrames(), "Font", true);
        fontDialog = new JDialog();
        Container con = fontDialog.getContentPane();
        con.setLayout(new FlowLayout(FlowLayout.LEFT));

        Font currentFont = EditorFrame.pane.getFont();

        JLabel lblFont = new JLabel("Font:");
        lblFont.setPreferredSize(new Dimension(140, 20));
        JLabel lblStyle = new JLabel("Font Style:");
        lblStyle.setPreferredSize(new Dimension(80, 20));
        JLabel lblSize = new JLabel("Size:");
        lblSize.setPreferredSize(new Dimension(40, 20));
        tfFont = new JTextField(22);
        tfFont.setText(currentFont.getFontName());
        tfFont.selectAll();
        tfFont.setPreferredSize(new Dimension(200, 20));
        tfStyle = new JTextField(12);
        if (currentFont.getStyle() == Font.PLAIN)
            tfStyle.setText("Regular");
        else if (currentFont.getStyle() == Font.ITALIC)
            tfStyle.setText("Italic");
        else if (currentFont.getStyle() == Font.BOLD)
            tfStyle.setText("Bold");
        else if (currentFont.getStyle() == (Font.BOLD + Font.ITALIC))
            tfStyle.setText("Bold Italic");

        tfFont.selectAll();
        tfStyle.setPreferredSize(new Dimension(200, 20));
        tfSize = new JTextField(9);
        tfSize.setText(currentFont.getSize() + "");
        tfSize.selectAll();
        tfSize.setPreferredSize(new Dimension(200, 20));

        final String fontStyle[] = { "Regular", "Italic", "Bold", "Bold Italic" };
        listStyle = new JList(fontStyle);

        GraphicsEnvironment ge = GraphicsEnvironment.getLocalGraphicsEnvironment();
        final String fontName[] = ge.getAvailableFontFamilyNames();
        int defaultFontIndex = 0;
        for (int i = 0; i < fontName.length; i++) {
            if (fontName[i].equals(currentFont.getFontName())) {
                defaultFontIndex = i;
                break;
            }
        }
        listFont = new JList(fontName);
        listFont.setSelectedIndex(defaultFontIndex);
        listFont.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        listFont.setVisibleRowCount(7);
        listFont.setFixedCellWidth(119);
        listFont.setFixedCellHeight(20);
        listFont.addListSelectionListener(new ListSelectionListener() {
            public void valueChanged(ListSelectionEvent event) {
                tfFont.setText(fontName[listFont.getSelectedIndex()]);
                tfFont.requestFocus();
                tfFont.selectAll();
                updateSample();
            }
        });
        listStyle.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        if (currentFont.getStyle() == Font.PLAIN)
            listStyle.setSelectedIndex(0);
        else if (currentFont.getStyle() == Font.ITALIC)
            listStyle.setSelectedIndex(2);
        else if (currentFont.getStyle() == Font.BOLD)
            listStyle.setSelectedIndex(1);
        else if (currentFont.getStyle() == (Font.BOLD + Font.ITALIC))
            listStyle.setSelectedIndex(3);

        listStyle.setVisibleRowCount(7);
        listStyle.setFixedCellWidth(77);
        listStyle.setFixedCellHeight(20);
        listStyle.addListSelectionListener(new ListSelectionListener() {
            public void valueChanged(ListSelectionEvent event) {
                tfStyle.setText(fontStyle[listStyle.getSelectedIndex()]);
                tfStyle.requestFocus();
                tfStyle.selectAll();
                updateSample();
            }
        });

        final String fontSize[] = { "8", "9", "10", "11", "12", "14", "16", "18", "20", "22", "24", "26", "28", "36",
                "48", "72" };
        listSize = new JList(fontSize);
        int defaultFontSizeIndex = 0;
        for (int i = 0; i < fontSize.length; i++) {
            if (fontSize[i].equals(currentFont.getSize() + "")) {
                defaultFontSizeIndex = i;
                break;
            }
        }
        listSize.setSelectedIndex(defaultFontSizeIndex);

        listSize.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        listSize.setVisibleRowCount(7);
        listSize.setFixedCellWidth(40);
        listSize.setFixedCellHeight(20);
        listSize.addListSelectionListener(new ListSelectionListener() {
            public void valueChanged(ListSelectionEvent event) {
                tfSize.setText(fontSize[listSize.getSelectedIndex()]);
                tfSize.requestFocus();
                tfSize.selectAll();
                updateSample();
            }
        });
//        Editor.fok_btn = new JButton("OK");
//        Editor.fok_btn.addActionListener(this);
//        Editor.fcc_btn = new JButton("Cancel");
//        Editor.fcc_btn.addActionListener(new ActionListener() {
//            public void actionPerformed(ActionEvent e) {
//                fontDialog.dispose();
//            }
//        });

        sample = new JLabel("AaBbYyZz");
        sample.setHorizontalAlignment(SwingConstants.CENTER);
        sample.setPreferredSize(new Dimension(120, 36));

        JPanel samplePanel = new JPanel();
        samplePanel.setBorder(BorderFactory.createTitledBorder("Sample"));
        samplePanel.add(sample);

        con.add(lblFont);
        con.add(lblStyle);
        con.add(lblSize);
        con.add(tfFont);
        con.add(tfStyle);
        con.add(tfSize);

        con.add(new JScrollPane(listFont));
        con.add(new JScrollPane(listStyle));
        con.add(new JScrollPane(listSize));
        con.add(samplePanel);
        updateSample();

//        con.add(Editor.fok_btn);
//        con.add(Editor.fcc_btn);

        fontDialog.setSize(310, 360);
        fontDialog.setLocation(200, 200);
        fontDialog.setResizable(false);
        fontDialog.setVisible(true);
    }

    public void updateSample() {
        Font sampleFont = new Font(tfFont.getText(), fontStyleConst[listStyle.getSelectedIndex()],
                Integer.parseInt(tfSize.getText()));
        sample.setFont(sampleFont);
    }

    public void actionPerformed(ActionEvent e) {
//        if (e.getSource() == Editor.fok_btn) {
//            Font tempFont = new Font(tfFont.getText(), fontStyleConst[listStyle.getSelectedIndex()],
//                    Integer.parseInt(tfSize.getText()));
//            Editor.pane.setFont(tempFont);
//            fontDialog.dispose();
//        }
    }
}