package com.by5.editor.frame;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;

import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

import com.by5.editor.EditorFrame;
import com.by5.editor.commons.WorkSpace;

public class WorkspaceFrame extends JFrame {
	
	private JPanel mainPanel;
	private JLabel infoLabel;
	private JPanel chosePanel;
	private JLabel workTextLabel;
	private JTextField pathText;
	private JButton choseButton;
	private JPanel buttonPanel;
	private JButton confirmButton;
	private JButton cancelButton;
	private SpaceChooser chooser;
	private File folder;
	
	public WorkspaceFrame(EditorFrame frame){
		mainPanel = new JPanel();
		infoLabel = new JLabel("请输入工作区间");
		chosePanel = new JPanel();
		workTextLabel = new JLabel("位置: ");
		pathText = new JTextField("", 40);
		choseButton = new JButton("查找");
		buttonPanel = new JPanel();
		confirmButton = new JButton("确定");
		cancelButton = new JButton("取消");
		chooser = new SpaceChooser(this);
		
		mainPanel.setLayout(new BoxLayout(mainPanel, BoxLayout.Y_AXIS));
		mainPanel.add(infoLabel);
		chosePanel.setLayout(new BoxLayout(chosePanel, BoxLayout.X_AXIS));
		choseButton.addActionListener(new ChooseButtonListener(chooser));
		pathText.setEditable(false);
		chosePanel.add(workTextLabel);
		chosePanel.add(pathText);
		chosePanel.add(choseButton);
		mainPanel.add(chosePanel);

		confirmButton.setEnabled(false);
		confirmButton.addActionListener(new ConfirmButtonListener(this, frame));
		buttonPanel.add(confirmButton);
		buttonPanel.add(new JLabel("    "));
		buttonPanel.add(cancelButton);
		cancelButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				System.exit(0);
			}
		});
		mainPanel.add(buttonPanel);
		add(mainPanel);
		pack();
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLocation(300, 200);
		setResizable(false);
	
	}
	
	public File getFolder() {
		return folder;
	}

	public void setFolder(File folder) {
		this.folder = folder;
	}
	
	public JTextField getPathText() {
		return pathText;
	}

	public JButton getConfirmButton() {
		return confirmButton;
	}
}

class ChooseButtonListener implements ActionListener{
	private JFileChooser chooser;
	public ChooseButtonListener(JFileChooser chooser){
		this.chooser = chooser;
	}
	@Override
	public void actionPerformed(ActionEvent e) {
		chooser.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
		chooser.showOpenDialog(null);
	}
} 

class SpaceChooser extends JFileChooser{
	private WorkspaceFrame spaceFrame;
	public SpaceChooser(WorkspaceFrame spaceFrame){
		super("/");
		this.spaceFrame = spaceFrame;
	}
	public void approveSelection(){
		File folder = getSelectedFile();
		spaceFrame.setFolder(folder);
		spaceFrame.getPathText().setText(folder.getAbsolutePath());
		spaceFrame.getConfirmButton().setEnabled(true);
		super.approveSelection();
	}
}

class ConfirmButtonListener implements ActionListener {
	private WorkspaceFrame spaceFrame;
	private EditorFrame editorFrame;
	public ConfirmButtonListener(WorkspaceFrame spaceFrame, EditorFrame editorFrame) {
		this.spaceFrame = spaceFrame;
		this.editorFrame = editorFrame;
	}
	public void actionPerformed(ActionEvent arg0) {
//		System.out.println(spaceFrame.toString());
//		System.out.println(editorFrame.toString());
		editorFrame.initFrame(new WorkSpace(spaceFrame.getFolder(), editorFrame));
		editorFrame.setVisible(true);
		spaceFrame.setVisible(false);
	}
}
