package com.by5.editor.frame;

import javax.swing.*;

import com.by5.editor.commons.AddInfo;

public class AddFrame extends JFrame {
	private JPanel mainPanel;
	private JPanel namePanel;
	private JLabel nameLabel;
	private JTextField nameText;
	private JPanel buttonPanel;
	private JButton confirmButton;
	private JButton cancelButton;
	
	public AddFrame(final AddInfo info) {
		mainPanel = new JPanel();
		namePanel = new JPanel();
		nameLabel = new JLabel(info.getInfo());
		nameText = new JTextField("",20);
		buttonPanel = new JPanel();
		confirmButton = new JButton("ȷ��");
		cancelButton = new JButton("ȡ��");
		
		mainPanel.setLayout(new BoxLayout(mainPanel, BoxLayout.Y_AXIS));
		/*
		addWindowListener(new WindowAdapter() {
			public void windowClosing(java.awt.event.WindowEvent e) {
				cancel(info);
			}
		});
		*/
		this.setLocation(200,200);
		this.setResizable(false);
		
		namePanel.setLayout(new BoxLayout(namePanel, BoxLayout.X_AXIS));
		namePanel.add(nameLabel);
		namePanel.add(nameText);
		/*
		nameText.addKeyListener(new KeyAdapter() {
			public void keyReleased(KeyEvent e) {
				if (nameText.getText().equals("")) {
					confirmButton.setEnabled(false);
				} else {
					confirmButton.setEnabled(true);
				}
			}
		});
		*/
		buttonPanel.setLayout(new BoxLayout(buttonPanel, BoxLayout.X_AXIS));
		confirmButton.setEnabled(false);
		buttonPanel.add(confirmButton);
		buttonPanel.add(new JLabel("     "));
		buttonPanel.add(cancelButton);
		/*
		cancelButton.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e) {
				cancel(info);
			}
		});
		confirmButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (nameText.getText() == "") return;
				handerConfirm(info);
			}
		});
		*/
		mainPanel.add(namePanel);
		mainPanel.add(buttonPanel);
		
		this.add(mainPanel);
		pack();
	} 
	private void handerConfirm(AddInfo info) {
		String data = nameText.getText();
		info.getHandler().afterAdd(info.getEditorFrame(), this, data);
	}
	
	private void cancel(AddInfo info) {
		info.getEditorFrame().setEnabled(true);
		setVisible(false);
	}
}
