package com.by5.editor.handler.add;

import java.io.File;

import javax.swing.JOptionPane;

import com.by5.editor.EditorFrame;
import com.by5.editor.exception.FileException;
import com.by5.editor.frame.AddFrame;
import com.by5.editor.tree.ProjectTreeNode;

public class AddFileHandler implements AddHandler {
    public void afterAdd(EditorFrame editorFrame, AddFrame addFrame, Object data) {
        try {
            ProjectTreeNode selectNode = editorFrame.getSelectNode();
            File folder = selectNode.getFile();
            if (!folder.isDirectory()) {
                ProjectTreeNode parent = (ProjectTreeNode)selectNode.getParent();
                selectNode = parent;
                folder = parent.getFile();
            }
            File newFile = new File(folder.getAbsoluteFile() + File.separator + data);
            if (newFile.exists()) {
                JOptionPane.showMessageDialog(addFrame, "�ļ��Ѿ�����");
                return;
            }
            newFile.createNewFile();
//            editorFrame.reloadNode(selectNode);
            editorFrame.setEnabled(true);
            addFrame.setVisible(false);
        } catch (Exception e) {
            throw new FileException("create file error: " + e.getMessage());
        }
    }
}