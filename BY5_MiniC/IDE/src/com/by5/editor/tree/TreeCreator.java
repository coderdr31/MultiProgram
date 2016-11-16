package com.by5.editor.tree;

import java.io.File;

import javax.swing.JTree;

import com.by5.editor.EditorFrame;

public interface TreeCreator {
	JTree createTree(EditorFrame editorFrame);
	ProjectTreeNode createNode(File folder);
}
