package com.by5.editor.tree;

import java.io.File;
import java.util.ArrayList;
import java.util.List;

import javax.swing.JTree;
import javax.swing.tree.DefaultTreeCellRenderer;
import javax.swing.tree.TreePath;

import com.by5.editor.EditorFrame;
import com.by5.editor.commons.WorkSpace;
import com.by5.editor.util.ImageUtil;

public class TreeCreatorImpl implements TreeCreator {
	@Override
	public JTree createTree(EditorFrame editorFrame) {
		File spaceFolder = editorFrame.getWorkSpace().getFolder();
		ProjectTreeNode root = new ProjectTreeNode(spaceFolder, true);
		ProjectTreeModel treeModel = new ProjectTreeModel(root);
		JTree tree = new JTree(treeModel);
		

		List<File> projectFolders = getProjectFolders(spaceFolder);
		System.out.println(projectFolders.size());
		
		for (int i = 0; i < projectFolders.size(); i++) {
			File projectFolder = projectFolders.get(i);
			ProjectTreeNode node = createNode(projectFolder);
			root.add(node);
			System.out.println("hello");
		}

		DefaultTreeCellRenderer renderer = new DefaultTreeCellRenderer();
		renderer.setOpenIcon(ImageUtil.getImageIcon(ImageUtil.FOLDER_OPEN));
		renderer.setLeafIcon(ImageUtil.getImageIcon(ImageUtil.FILE));
		renderer.setClosedIcon(ImageUtil.getImageIcon(ImageUtil.FOLDER_CLOSE));
		tree.setCellRenderer(renderer);
		
		tree.addMouseListener(new ProjectTreeSelectionListener(editorFrame));
		
		TreePath path = new TreePath(root);
		tree.expandPath(path);
		tree.setRootVisible(true);
		
		return tree;
	}

	@Override
	public ProjectTreeNode createNode(File folder) {
		ProjectTreeNode parent = null;
		
		if (!folder.isDirectory()) return new ProjectTreeNode(folder, false);
		else parent = new ProjectTreeNode(folder, true);
			
		List<ProjectTreeNode> nodes = createNodes(parent.getFile());
		
		for (ProjectTreeNode node : nodes) {
			parent.add(createNode(node.getFile()));
		}
		return parent;
	}

	private List<ProjectTreeNode> createNodes(File folder) {
		File[] files = folder.listFiles();
		List<ProjectTreeNode> result = new ArrayList<ProjectTreeNode>();
		for (File file : files) {	
			if (file.isDirectory()) result.add(new ProjectTreeNode(file, true));
			if (!file.isDirectory()) result.add(new ProjectTreeNode(file, false));
		}
		return result;
	}
	

	private List<String> getProjectNames(File spaceFolder) {
		List<String> result = new ArrayList<String>();
		for (File file : spaceFolder.listFiles()) {
			if (file.isDirectory()){
				for (File proj : file.listFiles()){
					if (proj.getName().endsWith(".project")) {
						System.out.println(proj.getName());
						result.add(proj.getName().substring(0, proj.getName().indexOf(".project")));
						break;
					}
				}
			}

		}
		return result;
	}
	

	private List<File> getProjectFolders(File spaceFolder) {
//		List<String> projectNames = getProjectNames(spaceFolder);
		List<File> result = new ArrayList<File>();
		File[] files = spaceFolder.listFiles();
		for (File file : files) {
			if (file.isFile()) {
//				for (String projectName : projectNames) {
//					if (projectName.equals(file.getName())) {
						result.add(file);
//						break;
//					}
//				}
			}
		}
		
		return result;
	}
}
