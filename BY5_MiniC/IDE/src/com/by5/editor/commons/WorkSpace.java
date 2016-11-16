package com.by5.editor.commons;

import java.io.File;

import com.by5.editor.EditorFrame;

public class WorkSpace {
	private File folder;
	private EditorFrame editorFrame;
	public WorkSpace(File folder, EditorFrame editorFrame) {
		this.folder = folder;
		this.editorFrame = editorFrame;
	}
	public EditorFrame getEditorFrame() {
		return editorFrame;
	}
	public void setEditorFrame(EditorFrame editorFrame) {
		this.editorFrame = editorFrame;
	}
	public File getFolder() {
		return folder;
	}
	public void setFolder(File folder) {
		this.folder = folder;
	}
}
