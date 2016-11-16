package com.by5.editor;

import java.io.File;

import com.by5.editor.commons.WorkSpace;
import com.by5.editor.frame.AddFrame;
import com.by5.editor.frame.WorkspaceFrame;
import com.by5.editor.tree.TreeCreator;
import com.by5.editor.tree.TreeCreatorImpl;

public class EditorMain {

	public static void main(String[] args) {
		TreeCreator treeCreator = new TreeCreatorImpl();
		EditorFrame frame = new EditorFrame(treeCreator);
		WorkspaceFrame space = new WorkspaceFrame(frame);
		//AddFrame frame = new AddFrame();
//		space.setVisible(true);
		
		
	    frame.initFrame(new WorkSpace(new File("/home/dr/minic1/minic/testfile"), frame));
	    frame.setVisible(true);
	}

}