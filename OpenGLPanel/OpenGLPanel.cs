using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
//using System.Linq;
using System.Text;
using System.Windows.Forms;
using OpenGLForm;
using System.Diagnostics;
using System.IO;
using MDIForm.CommonLibrary;

namespace CommonControl
{
  public partial class OpenGLPanel : Form //UserControl
  {
    #region Variables
    //private Panel panel1;
    private Panel panel2;
    public ImageList imageList1;
    public string theme = string.Empty;
    public COpenGL OpenGL; private List<string> previousDocuments = new List<string>();

    private ToolStripSeparator toolStripSeparator9;
    private bool newDocumentFlag = false;
    public string statustext;
    public string filepath = "";
    public string linkFilePath = "";
     private Process currentProcess = null;
    #endregion

    #region Propertirs
    public List<string> PreviousDocuments
    {
      get
      {
        return this.previousDocuments;
      }
      set
      {
        this.previousDocuments = value;
      }
    }
    #endregion

    #region Constructor
    public OpenGLPanel()
    {
      InitializeComponent();
      this.TopLevel = false;
      this.Visible = true;
      this.FormBorderStyle = FormBorderStyle.None;
      this.Dock = DockStyle.Fill;

      this.InitializeInterface();
      IntializeOpenGLPanel();
    }

    public OpenGLPanel(string theme)
    {
      this.theme = theme;
      this.InitializeComponent();
      this.TopLevel = false;
      this.Visible = true;
      this.FormBorderStyle = FormBorderStyle.None;
      this.Dock = DockStyle.Fill;

      this.InitializeInterface();
    }


    public OpenGLPanel(string[] args)
    {
      InitializeComponent();
      this.TopLevel = false;
      this.Visible = true;
      this.FormBorderStyle = FormBorderStyle.None;
      this.Dock = DockStyle.Fill;
      IntializeOpenGLPanel();
      IntializeOpenGLPanel();
    }
    #endregion

    #region Initialization

    public void InitializeInterface()
    {
      CommonInterface.Properties.Settings commonsettings = new CommonInterface.Properties.Settings();
      this.TopLevel = false;
      this.Visible = true;
      this.FormBorderStyle = FormBorderStyle.None;
      this.Dock = DockStyle.Fill;


      //CommonInterface.ParentFormClass;
      //CommonLibrary.Settings commonsettings = new CommonLibrary.Settings();
    }

    public void IntializeOpenGLPanel()
    {
      //String resource = Path.Combine(baseDir, @"CsMacro\CustomDocument\Resources\"); //"
      //String resource = Path.Combine(PathHelper.BaseDir, @"SettingData\\Resources\"); //"
      InitializeImageList();
      //this.新規作成NToolStripButton.Image = new Bitmap(resource + "new_Button.bmp");
      //this.開くOToolStripButton.Image = new Bitmap(resource + "open_Button.bmp");
      //this.上書き保存SToolStripButton.Image = new Bitmap(resource + "save_Button.bmp");
      //this.toolStripButton1.Image = new Bitmap(resource + "saveas_Button.bmp");
      //this.印刷PToolStripButton.Image = new Bitmap(resource + "print_Button.bmp");
      //this.切り取りUToolStripButton.Image = new Bitmap(resource + "cut_Button.bmp");
      //this.コピーCToolStripButton.Image = new Bitmap(resource + "copy_Button.bmp");
      //this.貼り付けPToolStripButton.Image = new Bitmap(resource + "paste_Button.bmp");
      //this.ヘルプLToolStripButton.Image = new Bitmap(resource + "help_Button.bmp");
      //this.新規作成NToolStripMenuItem.Image = new Bitmap(resource + "new_MenuItem.bmp");
      //this.開くOToolStripMenuItem.Image = new Bitmap(resource + "open_MenuItem.bmp");
      //this.印刷PToolStripMenuItem.Image = new Bitmap(resource + "print_MenuItem.bmp");
      //this.印刷プレビューVToolStripMenuItem.Image = new Bitmap(resource + "printpreview_MenuItem.bmp");
      //this.切り取りTToolStripMenuItem.Image = new Bitmap(resource + "cut_MenuItem.bmp");
      //this.コピーCToolStripMenuItem.Image = new Bitmap(resource + "copy_MenuItem.bmp");
      //this.toolStripDropDownButton1.Image = System.Drawing.Image.FromFile(resource + @"famfamicons\asterisk_orange.png");
    }

    public void InitializeImageList()
    {
     
      Bitmap bmp3 = (Bitmap)this.toolStripButton1.Image;
      // 
      // imageList1
      // 
      this.imageList1 = new ImageList();
      this.imageList1.Images.AddStrip(bmp3);
      this.imageList1.ColorDepth = System.Windows.Forms.ColorDepth.Depth8Bit;
      this.imageList1.ImageSize = new System.Drawing.Size(16, 16);
      this.imageList1.TransparentColor = System.Drawing.Color.Transparent;
      // 
      // imageList1
      // 
      //Icon型としてアイコンファイルを読み込み、16x16の画像を取得する
      //AddIcon("sakura_16x16.ico"); // 147
      //AddIcon("PSPad00.ico"); //148
      //AddIcon("Scintilla.ico"); //149
      //AddIcon("AnnCompact.ico"); //150
      //System.Drawing.Image img 
      //	= System.Drawing.Image.FromFile(Path.Combine(PathHelper.BaseDir, @"Settings\icons\EmEditor_16x16.png"));
      //System.Drawing.Image img
      //	= System.Drawing.Image.FromFile(Path.Combine(baseDir, @"Settings\icons\EmEditor_16x16.png"));
      //System.Drawing.Image img
      //  = System.Drawing.Image.FromFile(Path.Combine(PathHelper.BaseDir, @"SettingData\icons\EmEditor_16x16.png"));
      //  imageList1.Images.Add(img); //151
      //AddIcon("EmEditor_16x16.png"); //151
      //AddIcon("W95Icon0254_yellow.ico"); //152
      //AddIcon("cmd.ico"); //153
    }
    /**
     * Handles the click event for the menu items.
     */
    public void AddIcon(String name)
    {
		//String baseDir = @"C:\Documents and Settings\kazuhiko\Local Settings\Application Data\FlashDevelop";
		//String baseDir = PathHelper.BaseDir;
		// http://dobon.net/vb/dotnet/graphics/imagefromfile.html
    //String iconPath = Path.Combine(PluginCore.Helpers.PathHelper.BaseDir, @"SettingData\icons\" + name); //"
    //String iconPath = Path.Combine(baseDir, @"Settings\icons\" + name); //"
		//System.Drawing.Icon ico = new System.Drawing.Icon(iconPath, 16, 16);
		//Bitmapに変換する
		//System.Drawing.Bitmap bmp = ico.ToBitmap();
		//変換したBitmapしか使わないならば、元のIconは解放できる
		//ico.Dispose();
		//イメージを表示する
		//this.imageList1.Images.Add(bmp);
    }
    #endregion

    protected override void OnLoad(EventArgs e)
    {
      base.OnLoad(e);
    }

    private void OpenGLPanel_Load(object sender, EventArgs e)
    {
			if (this.theme != string.Empty)
		  {
			  this.panel1.Tag = this.theme;
		  }


      /*
      else if ((string)this.panel1.Tag != string.Empty)
		  {
        if (File.Exists((string)this.panel1.Tag) && Path.GetExtension((string)this.panel1.Tag) == ".exe")
        {
          this.ExecuteInPlace((string)this.panel1.Tag);
        }
        else
        {
          this.theme = (string)this.panel1.Tag;
        }
      }
      */


      else
		  {
			  this.theme = "Lesson05";
		  }
			//this.previousDocuments = this.settings.PreviousOpenGLPanelDocuments;
		  //this.toolStrip1.Visible = this.settings.OpenGLPanelToolBarVisible;
		  //this.statusStrip1.Visible = this.settings.OpenGLPanelStatusBarVisible;
		  //this.executeInPlaceToolStripMenuItem.Checked = this.settings.OpenGLPanelExecuteInPlace;

      this.ツールバーTToolStripMenuItem.Checked = this.toolStrip1.Visible;
      this.ステータスバーSToolStripMenuItem.Checked = this.statusStrip1.Visible;
      this.AddPreviousDocuments(this.theme);
      if (this.Parent is Form) ((Form)this.Parent).FormClosing += new FormClosingEventHandler(this.parentForm_Closing);
      this.InitializeOpenGLPanel("Lesson05");
    }

    private void OpenGLPanel_Leave(object sender, EventArgs e)
    {
    }

    private void OpenGLPanel_Enter(object sender, EventArgs e)
    {
    }

    private void InitializeOpenGLPanel(string theme)
    {
      //if (this.Parent is Form) ((Form)base.Parent).KeyPreview = true;
      this.panel1.BringToFront();
      this.OpenGL = new COpenGL(theme, this.panel1, this.panel1.Width, this.panel1.Height);
      this.timer1.Enabled = true;
      this.timer1.Interval = 10;
      this.timer1.Start();
      this.toolStrip1.Visible = true;
      this.statusStrip1.Visible = false;
    }

    private void parentForm_Closing(object sender, EventArgs e)
    {
      if (this.currentProcess != null)
      {
        if (!this.currentProcess.CloseMainWindow())
        {
          this.currentProcess.Kill();
        }
        this.currentProcess.Close();
        this.currentProcess.Dispose();
      }
      Process process = this.panel2.Tag as Process;
      if (process != null)
      {
        if (!process.CloseMainWindow())
        {
          process.Kill();
        }
        process.Close();
        process.Dispose();
      }
			//this.settings.PreviousOpenGLPanelDocuments = this.previousDocuments;
		  //this.settings.OpenGLPanelMenuBarVisible = this.menuStrip1.Visible;
		  //this.settings.OpenGLPanelToolBarVisible = this.toolStrip1.Visible;
		  //this.settings.OpenGLPanelStatusBarVisible = this.statusStrip1.Visible;
		  //this.settings.OpenGLPanelExecuteInPlace = this.executeInPlaceToolStripMenuItem.Checked;
    }

    public void AddPreviousDocuments(string data)
    {
      try
      {
        ToolStripMenuItem toolStripMenuItem = this.最近開いたファイルRToolStripMenuItem;
        if (this.previousDocuments.Contains(data))
        {
          this.previousDocuments.Remove(data);
        }
        this.previousDocuments.Insert(0, data);
        this.PopulatePreviousDocumentsMenu();
      }
      catch (Exception ex)
      {
        MessageBox.Show(ex.Message.ToString());
      }
    }

    public void PopulatePreviousDocumentsMenu()
    {
      try
      {
        ToolStripMenuItem toolStripMenuItem = this.最近開いたファイルRToolStripMenuItem;
        toolStripMenuItem.DropDownItems.Clear();
        for (int i = 0; i < this.previousDocuments.Count; i++)
        {
          string text = this.previousDocuments[i];
          ToolStripMenuItem toolStripMenuItem2 = new ToolStripMenuItem();
          toolStripMenuItem2.Click += new EventHandler(this.PreviousDocumentsMenuItem_Click);
          toolStripMenuItem2.Tag = text;
          toolStripMenuItem2.Text = text;
          if (i < 15)
          {
            toolStripMenuItem.DropDownItems.Add(toolStripMenuItem2);
          }
          else
          {
            this.previousDocuments.Remove(text);
          }
        }
        if (this.previousDocuments.Count > 0)
        {
          toolStripMenuItem.DropDownItems.Add(new ToolStripSeparator());
          toolStripMenuItem.DropDownItems.Add(this.最近開いたファイルをクリアCToolStripMenuItem);
          toolStripMenuItem.Enabled = true;
        }
        else
        {
          toolStripMenuItem.Enabled = false;
        }
      }
      catch (Exception ex)
      {
        MessageBox.Show(ex.Message.ToString());
      }
    }

    private void PreviousDocumentsMenuItem_Click(object sender, EventArgs e)
    {
      ToolStripMenuItem toolStripMenuItem = (ToolStripMenuItem)sender;
      try
      {
        if (this.Parent is Form) ((Form)this.Parent).KeyPreview = true;
        if (File.Exists(toolStripMenuItem.Text) && Path.GetExtension(toolStripMenuItem.Text) == ".exe")
        {
          try
          {
            if (this.executeInPlaceToolStripMenuItem.Checked)
            {
							//PluginBase.MainForm.WorkingDirectory = Path.GetDirectoryName(toolStripMenuItem.Text);
              this.ExecuteInPlace(toolStripMenuItem.Text);
              //((DockContent)this.Parent).TabText = Path.GetFileName(toolStripMenuItem.Text);
              //this.settings.PreviousCustomDocuments.Add("XMLTreeMenu.Controls.OpenGLPanel!" + toolStripMenuItem.Text);	
              //if (this.Parent is Form) ((Form)this.Parent).Text = Path.GetFileName(toolStripMenuItem.Text);
              this.AddPreviousDocuments(toolStripMenuItem.Text);
            }
            else
            {
              new Process
              {
                StartInfo =
                  {
                    FileName = toolStripMenuItem.Text,
                    WorkingDirectory = Path.GetDirectoryName(toolStripMenuItem.Text)
                }
              }.Start();
            }
          }
          catch (Exception ex)
          {
            string message = ex.Message.ToString();
            MessageBox.Show(ex.Message.ToString());
          }
        }
        else
        {
          if (this.OpenGL != null)
          {
            this.OpenGL.Dispose();
          }
          this.OpenGL = new COpenGL(toolStripMenuItem.Text, this.panel1, this.panel1.Width, this.panel1.Height);
          this.panel1.Refresh();
          this.panel1.Tag = toolStripMenuItem.Text;
          if (this.Parent is Form) ((Form)this.Parent).Text = Path.GetFileName(toolStripMenuItem.Text);
          this.newDocumentFlag = false;
          this.AddPreviousDocuments(toolStripMenuItem.Text);
        }
      }
      catch (Exception ex)
      {
        string message = ex.Message.ToString();
        MessageBox.Show(ex.Message.ToString());
      }
    }

    private void timer1_Tick(object sender, EventArgs e)
    {
      if (this.OpenGL != null)
      {
        this.OpenGL.Render();
        this.OpenGL.SwapOpenGLBuffers();
      }
    }

    private void panel1_Paint(object sender, PaintEventArgs e)
    {
      if (this.OpenGL != null)
      {
        this.OpenGL.ReSizeGLScene(this.panel1.Width, this.panel1.Height);
      }
    }

    private void OpenGL_Click(object sender, EventArgs e)
    {
      ToolStripMenuItem toolStripMenuItem = (ToolStripMenuItem)sender;
      //if (base.Parent is Form) ((Form)base.Parent).KeyPreview = true;
      this.panel1.BringToFront();
      if (this.OpenGL != null)
      {
        this.OpenGL.Dispose();
      }
      this.OpenGL = new COpenGL(toolStripMenuItem.Text, this.panel1, this.panel1.Width, this.panel1.Height);
      this.panel1.Refresh();
      this.panel1.Tag = toolStripMenuItem.Text;
      //if (base.Parent is Form) ((Form)base.Parent).Text = Path.GetFileNameWithoutExtension(toolStripMenuItem.Text);
      this.newDocumentFlag = false;
      this.AddPreviousDocuments(toolStripMenuItem.Text);
      //this.settings.PreviousCustomDocuments.Add("XMLTreeMenu.Controls.OpenGLPanel!" + toolStripMenuItem.Text);	
      //XMLTreeMenu.Controls.OpenGLPanel!Lesson05
    }

    private void 開くOToolStripMenuItem_Click(object sender, EventArgs e)
    {
      string initialDirectory = "F:\\c_program\\OpenGL\\NeHe\\";
      string filter = "exeファイル(*.exe)|*.exe|すべてのファイル(*.*)|*.*";
      string fileName = "Lesson05.exe";
      string text = Lib.File_OpenDialog(fileName, initialDirectory, filter);
      try
      {
        if (File.Exists(text))
        {
          if (this.executeInPlaceToolStripMenuItem.Checked)
          {

						//PluginBase.MainForm.WorkingDirectory = Path.GetDirectoryName(text);
						this.ExecuteInPlace(text);
            //this.settings.PreviousCustomDocuments.Add("XMLTreeMenu.Controls.OpenGLPanel!" + text);	
            if (this.Parent is Form) ((Form)this.Parent).Text = Path.GetFileName(text);
            this.AddPreviousDocuments(text);
          }
          else
          {
            new Process
            {
              StartInfo =
              {
                FileName = text,
                WorkingDirectory = Path.GetDirectoryName(text)
              }
            }.Start();
          }
        }
      }
      catch (Exception ex)
      {
        string message = ex.Message.ToString();
        MessageBox.Show(Lib.OutputError(message));
      }
    }

    private void 最近開いたファイルをクリアCToolStripMenuItem_Click(object sender, EventArgs e)
    {
      this.previousDocuments.Clear();
      this.PopulatePreviousDocumentsMenu();
    }

    private void 終了XToolStripMenuItem_Click(object sender, EventArgs e)
    {

    }

    private void ツールバーTToolStripMenuItem_Click(object sender, EventArgs e)
    {
      this.toolStrip1.Visible = this.ツールバーTToolStripMenuItem.Checked;
      if (this.toolStrip1.Visible)
      {
        this.toolStrip1.Visible = true;
      }
      else
      {
        this.toolStrip1.Visible = false;
      }
    }

    private void ステータスバーSToolStripMenuItem_Click(object sender, EventArgs e)
    {
      this.statusStrip1.Visible = this.ステータスバーSToolStripMenuItem.Checked;
      this.ステータスバーSToolStripMenuItem1.Checked = this.statusStrip1.Visible;
    }

    private void executeInPlaceToolStripMenuItem_Click(object sender, EventArgs e)
    {

    }

    private void ExecuteInPlace(string path)
    {
      /*
      Process process = this.panel2.Tag as Process;
      if (this.currentProcess != null)
      {
        if (!this.currentProcess.CloseMainWindow())
        {
          this.currentProcess.Kill();
        }
        this.currentProcess.Close();
        this.currentProcess.Dispose();
      }
      this.currentProcess = new Process();
      this.currentProcess.StartInfo.FileName = path;
      this.currentProcess.StartInfo.WorkingDirectory = Path.GetDirectoryName(path);
      this.currentProcess.Start();
      Process tag = Win32.MdiUtil.LoadProcessInControl(this.currentProcess, this.panel2);
      this.panel2.Tag = tag;
      Win32.ShowMaximized(this.currentProcess.MainWindowHandle);
      this.panel2.BringToFront();
      */
    }

    private void テストToolStripMenuItem_Click(object sender, EventArgs e)
    {
      /*
      StringBuilder stringBuilder = new StringBuilder(100);
      List<IntPtr> childWindows = CommonLibrary.Win32.GetChildWindows(this.panel2.Handle);
      foreach (IntPtr current in childWindows)
      {
        CommonLibrary.Win32.GetWindowText(current, stringBuilder, stringBuilder.Capacity);
        MessageBox.Show(stringBuilder.ToString());
      }
      */
    }


    private void 開くOToolStripButton_Click(object sender, EventArgs e)
    {
      this.開くOToolStripMenuItem.PerformClick();
    }

    private void 上書き保存SToolStripMenuItem_Click(object sender, EventArgs e)
    {

    }

    private void 上書き保存SToolStripButton_Click(object sender, EventArgs e)
    {
      this.上書き保存SToolStripMenuItem.PerformClick();
    }

    private void メニューバーMToolStripMenuItem_Click(object sender, EventArgs e)
    {
      this.menuStrip1.Visible = !this.menuStrip1.Visible;
    }

    private void ステータスバーSToolStripMenuItem1_Click(object sender, EventArgs e)
    {
      this.statusStrip1.Visible = !this.statusStrip1.Visible;
      this.ステータスバーSToolStripMenuItem.Checked = this.statusStrip1.Visible;
    }




















  }
}
