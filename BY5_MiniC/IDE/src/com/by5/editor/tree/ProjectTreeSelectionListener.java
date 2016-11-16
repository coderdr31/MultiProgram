package com.by5.editor.tree;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import com.by5.editor.EditorFrame;

public class ProjectTreeSelectionListener extends MouseAdapter {
	private EditorFrame editorFrame;
	public ProjectTreeSelectionListener(EditorFrame editorFrame) {
		this.editorFrame = editorFrame;
	}
	public void mousePressed(MouseEvent e){
		ProjectTreeNode selectNode =  this.editorFrame.getSelectNode();
		if (selectNode == null) return;
		if (selectNode.getFile().isDirectory()) return;
		//this.editorFrame.openFile(selectNode.getFile());
	}

}
