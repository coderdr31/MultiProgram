package com.by5.editor.util;
import java.awt.Image;
import java.io.File;
import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
public class ImageUtil {
	public static String FOLDER_CLOSE = "images/folder-close.gif";
	public static String FOLDER_OPEN = "images/folder-open.gif";
	public static String FILE = "images/file.gif";
	public static Image getImage(String path) {
		try {
			return ImageIO.read(new File(path));
		} catch (Exception e) {
			e.printStackTrace();
			return null;
		}
	}
	public static ImageIcon getImageIcon(String path) {
		return new ImageIcon(getImage(path));
	}
}
