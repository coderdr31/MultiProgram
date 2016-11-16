package com.by5.editor;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.Insets;
import java.awt.List;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.InputEvent;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;

import javax.swing.event.TreeSelectionEvent;
import javax.swing.event.TreeSelectionListener;
import javax.swing.text.InternationalFormatter;
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.*;
import javax.swing.tree.TreePath;
import org.omg.CORBA.PUBLIC_MEMBER;
import com.by5.editor.commons.AddInfo;
import com.by5.editor.commons.WorkSpace;
import com.by5.editor.frame.AddFrame;
import com.by5.editor.handler.add.AddFileHandler;
import com.by5.editor.tree.ProjectTreeModel;
import com.by5.editor.tree.ProjectTreeNode;
import com.by5.editor.tree.TreeCreator;
public class EditorFrame extends JFrame {
    private static final long serialVersionUID = 1L;
    private final int WIDTH = 800;
    private final int HEIGHT = 600;
    File file; //打开的文件
    String dir; // 存放路径
    static JTabbedPane tabPane;
    static Box box; // 编辑代码的窗口
    static JDesktopPane desk;
    static JSplitPane editorSplitPane;
    static JScrollPane infoPane; // 右下角的输出信息的窗口
    static JTextArea infoArea;
    static JTextPane pane;
    static String text = null;
    static JScrollPane treePane;
    static JSplitPane mainSplitPane;
    static JTree tree;
    private Action fileNew = new AbstractAction("新建", new ImageIcon("images/newFile.gif")) {
        public void actionPerformed(ActionEvent e) {
            newFile();
        }
    };
    private Action folerNew = new AbstractAction("新建目录", new ImageIcon("images/newFile.gif")) {
        public void actionPerformed(ActionEvent e) {
            // newFolder();
        }
    };
    private Action projectNew = new AbstractAction("新建项目", new ImageIcon("images/newFile.gif")) {
        public void actionPerformed(ActionEvent e) {
            // newProject();
        }
    };
    private Action open = new AbstractAction("打开", new ImageIcon("images/open.gif")) {
        public void actionPerformed(ActionEvent e) {
            // selectFile();
        }
    };
    private Action save = new AbstractAction("保存", new ImageIcon("images/save.gif")) {
        public void actionPerformed(ActionEvent e) {
            try {
                FileOutputStream fos = new FileOutputStream(file);
                BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(fos));
                text = pane.getText();
                bw.write(text);
                bw.close();
                tree.updateUI();
            } catch (Exception e2) {
                e2.printStackTrace();
            }
        }
    };
    private Action build = new AbstractAction("编译", new ImageIcon("images/refresh.gif")) {
        public void actionPerformed(ActionEvent e) {
            try {
                dir = workSpace.getFolder().toString();
                String command = "lexyan" + " " + file.toString();
                Process process = Runtime.getRuntime().exec(command); 
                // 上面的命令要写到系统自带的环境变量中
                
                //将输出的结果在控制台输出
                ArrayList<String> processList = new ArrayList<String>();
                try{
                    BufferedReader input = new BufferedReader(new InputStreamReader(process.getInputStream()));
                    String line = "";
                    while((line = input.readLine()) != null){
                        processList.add(line);
                    }
                    input.close();
                } catch(Exception e1) {
                    e1.printStackTrace();
                }
                for(String line : processList){
                    System.out.println(line);
                }
                
                // 读取生成的文件，并输出到信息栏
                file = new File(workSpace.getFolder().toString() + "/" + "test.asm");
                FileInputStream fis = new FileInputStream(file);
                BufferedReader br = new BufferedReader(new InputStreamReader(fis));
                text = "";
                int ch;
                while ((ch = br.read()) != -1) {
                    text += (char)ch;
                }
                System.out.println(text);   
                JTextPane infoPane = new JTextPane();
                infoPane.setText(text);
                infoPane.setEditable(true);
                infoPane.setVisible(true);
                infoPane.getDocument().addDocumentListener(new Highlighting(infoPane));
                // infoPane并没有什么作用
                infoArea.setBackground(Color.white);
                infoArea.setText(text);
                infoArea.add(infoPane, CENTER_ALIGNMENT);
                infoArea.setVisible(true);

            } catch (IOException e1) {
                e1.printStackTrace();
            }
            
        }
    };
    private Action run = new AbstractAction("运行", new ImageIcon("images/run.gif")) {
        public void actionPerformed(ActionEvent e) {
//        		String command = "gnome-terminal -x bash -c 'lexyanrun; exec bash'";
        		String command = "gnome-terminal";
                try {
					Process process = Runtime.getRuntime().exec(command);
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				} 
             
        }
    };
    private Action drawtree = new AbstractAction("语法树", new ImageIcon("images/file.gif")) {
        public void actionPerformed(ActionEvent e) {
            try {
            	String command = "lexyantree " + file.toString();
                Process process = Runtime.getRuntime().exec(command); 
                // 这里的lexyanrun中要带上 执行可执行文件的命令
//                ArrayList<String> processList = new ArrayList<String>();
//                try{
//                    BufferedReader input = new BufferedReader(new InputStreamReader(process.getInputStream()));
//                    String line = "";
//                    while((line = input.readLine()) != null){
//                        processList.add(line);
//                    }
//                    input.close();
//                } catch(Exception e1) {
//                    e1.printStackTrace();
//                }
//                String text = null;
//                for(String line : processList){
//                    text += line;
//                }
                file = new File("/home/dr/minic1/minic/testfile/treeoutput");
                FileInputStream fis = new FileInputStream(file);
                BufferedReader br = new BufferedReader(new InputStreamReader(fis));
                text = "";
                int ch;
                while ((ch = br.read()) != -1) {
                    text += (char)ch;
                }
                infoArea.setBackground(Color.white);
                infoArea.setText(text);
                System.out.println(text);
            } catch (IOException er) {
                er.printStackTrace();
            }
        }
    };
    private Action exit = new AbstractAction("编辑") {
        public void actionPerformed(ActionEvent e) {
            System.exit(0);
        }
    };
    private Action copy = new AbstractAction("复制", new ImageIcon("images/copy.gif")) {
        public void actionPerformed(ActionEvent e) {
            // if (getCurrentFile() != null)
            // getCurrentFile().getEditPane().copy();
        }
    };
    private Action cut = new AbstractAction("剪切", new ImageIcon("images/cut.gif")) {
        public void actionPerformed(ActionEvent e) {
            // if (getCurrentFile() != null)
            // getCurrentFile().getEditPane().cut();
        }
    };
    private Action paste = new AbstractAction("粘贴", new ImageIcon("images/paste.gif")) {
        public void actionPerformed(ActionEvent e) {
            // if (getCurrentFile() != null)
            // getCurrentFile().getEditPane().paste();
        }
    };
    private JMenuBar menuBar;
    private JMenu editMenu;
    private JMenu fileMenu;
    private JMenu projMenu;
    private JToolBar toolBar;
    private WorkSpace workSpace;
    private TreeCreator treeCreator;
    private AddFrame addFrame;
    public EditorFrame(TreeCreator treeCreator) {
        super();
        this.treeCreator = treeCreator;
        this.setTitle("IDE");
    }
    public void initFrame(WorkSpace space) {
        this.workSpace = space;
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        tabPane = new JTabbedPane(JTabbedPane.TOP, JTabbedPane.SCROLL_TAB_LAYOUT);
        desk = new JDesktopPane();
        desk.setBackground(Color.gray);
        box = new Box(BoxLayout.Y_AXIS);
        pane = new JTextPane();
//        desk.add(pane);
//        pane.setVisible(true);
//        box.add(tabPane);
//        box.add(desk);
        box.add(new JScrollPane(pane)); 
        pane.getDocument().addDocumentListener(new Highlighting(pane));
        pane.setFont(new Font("YaHei Consolas Hybrid", Font.PLAIN, 18));
        pane.setBackground(Color.darkGray);
//        pane.setEditable(false);
//        pane.setVisible(false);
        pane.setBorder(new LineNumberBorder());
        
        
        infoArea = new JTextArea("", 5, 50);
        infoPane = new JScrollPane(infoArea);
        infoArea.setEditable(false);
        infoArea.setBackground(Color.darkGray);
        editorSplitPane = new JSplitPane(JSplitPane.VERTICAL_SPLIT, box, infoPane);
        editorSplitPane.setDividerSize(3);
        editorSplitPane.setDividerLocation(400);
        this.add(editorSplitPane);

        tree = treeCreator.createTree(this);
        treePane = new JScrollPane(tree);
        treePane.setBackground(Color.darkGray);
        mainSplitPane = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT, treePane, editorSplitPane);
        mainSplitPane.setDividerLocation(200);
        mainSplitPane.setDividerSize(3);
        mainSplitPane.setBackground(Color.darkGray);
        this.add(mainSplitPane);

        createMenuBar();
        createToolBar();
        // tree = treeCreator.createTree(this);
        addListeners();
        this.setSize(this.WIDTH, this.HEIGHT);
        this.setLocation(200, 75);
    }
    private void createToolBar() {
        toolBar = new JToolBar();
        toolBar.setFloatable(false);
        toolBar.setMargin(new Insets(0, 10, 5, 5));
        this.add(toolBar, BorderLayout.NORTH);
    }
    public void openFile(Object object){
          try {
              file = new File(workSpace.getFolder().toString() + "/" + object.toString());
              FileInputStream fis = new FileInputStream(file);
              BufferedReader br = new BufferedReader(new InputStreamReader(fis));
              text = "";
              int ch;
              while ((ch = br.read()) != -1) {
                  text += (char)ch;
              }
              System.out.println(text);
              pane.setText(text);
              pane.setEditable(true);
              pane.setCaretColor(Color.white); //设置光标的颜色为白色
              pane.setVisible(true);
//              box.remove(desk);
//              box.add(new JScrollPane(pane));
          } catch (Exception e) {
              e.printStackTrace();
          }
    }
    private void addListeners(){
		fileMenu.add(fileNew).setAccelerator(KeyStroke.getKeyStroke('N', InputEvent.CTRL_MASK));
		fileMenu.add(folerNew).setAccelerator(KeyStroke.getKeyStroke('F', InputEvent.CTRL_MASK));
		fileMenu.add(projectNew).setAccelerator(KeyStroke.getKeyStroke('P', InputEvent.CTRL_MASK));
		fileMenu.add(open).setAccelerator(KeyStroke.getKeyStroke('O', InputEvent.CTRL_MASK));
		fileMenu.add(save).setAccelerator(KeyStroke.getKeyStroke('S', InputEvent.CTRL_MASK));
		fileMenu.add(exit);

		editMenu.add(copy).setAccelerator(KeyStroke.getKeyStroke('C', InputEvent.CTRL_MASK));
		editMenu.add(cut).setAccelerator(KeyStroke.getKeyStroke('X', InputEvent.CTRL_MASK));
		editMenu.add(paste).setAccelerator(KeyStroke.getKeyStroke('V', InputEvent.CTRL_MASK));
		
		projMenu.add(build).setAccelerator(KeyStroke.getKeyStroke("F5"));
		projMenu.add(run).setAccelerator(KeyStroke.getKeyStroke('R', InputEvent.CTRL_MASK));
		projMenu.add(drawtree).setAccelerator(KeyStroke.getKeyStroke('T', InputEvent.CTRL_MASK));
		tree.addTreeSelectionListener(new TreeSelectionListener() {
            @Override
            public void valueChanged(TreeSelectionEvent e) {
                DefaultMutableTreeNode node = (DefaultMutableTreeNode) tree
                        .getLastSelectedPathComponent();
                if (node == null)
                    return;
                Object object = node.getUserObject();
                if (node.isLeaf()) {
                    openFile(object);
                }
 
            }
        });
		toolBar.add(fileNew).setToolTipText("新建");
		toolBar.add(open).setToolTipText("打开");
		toolBar.add(save).setToolTipText("保存");
		toolBar.addSeparator();

		toolBar.add(copy).setToolTipText("复制");
		toolBar.add(cut).setToolTipText("剪切");
		toolBar.add(paste).setToolTipText("粘贴");
		toolBar.addSeparator();
		
		toolBar.add(build).setToolTipText("编译");
		toolBar.add(run).setToolTipText("运行");
		toolBar.add(drawtree).setToolTipText("语法树");
		
	}
    private void createMenuBar() {
        menuBar = new JMenuBar();
        fileMenu = new JMenu("文件");
        editMenu = new JMenu("编辑");
        projMenu = new JMenu("项目");
        menuBar.add(fileMenu);
        menuBar.add(editMenu);
        menuBar.add(projMenu);
        this.setJMenuBar(menuBar);
    }
    public WorkSpace getWorkSpace() {
        return workSpace;
    }
    public ProjectTreeNode getSelectNode() {
        TreePath path = tree.getSelectionPath();
        if (path != null) {
            ProjectTreeNode selectNode = (ProjectTreeNode) path.getLastPathComponent();
            return selectNode;
        }
        return null;
    }

    public void newFile() {
        AddInfo info = new AddInfo("新建项目", this, new AddFileHandler());
        showAddFrame(info);
    }

    private void showAddFrame(AddInfo info) {
        setEnabled(false);
        addFrame = new AddFrame(info);
        addFrame.pack();
        addFrame.setVisible(true);
    }

    // public void reloadNode(ProjectTreeNode selectNode) {
    // if (selectNode == null) return;
    // ProjectTreeModel model = (ProjectTreeModel)getTree().getModel();
    // model.reload(selectNode, treeCreator);
    // }

}
