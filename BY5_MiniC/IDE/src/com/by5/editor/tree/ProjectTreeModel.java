package com.by5.editor.tree;

import javax.swing.tree.DefaultTreeModel;
import javax.swing.tree.TreeNode;

public class ProjectTreeModel extends DefaultTreeModel {
	public ProjectTreeModel(TreeNode arg0) {
		super(arg0);
	}
	

	public void reload(ProjectTreeNode node, TreeCreator creator) {
		ProjectTreeNode parent = (ProjectTreeNode)node.getParent();
		if (parent == null) return;
		int index = parent.getIndex(node);
		parent.remove(index);
		node = creator.createNode(node.getFile());
		parent.insert(node, index);
		super.reload(node);
	}
	
}
