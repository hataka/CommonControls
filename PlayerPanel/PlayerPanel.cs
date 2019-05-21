using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using MDIForm.CommonLibrary;
using System.IO;
using System.Reflection;
using PlayerPanel.Controls;

namespace CommonControl
{
  public partial class PlayerPanel : UserControl
  {
    #region Variables
    public String filePath;
    public Browser browser;
    //自分自身の実行ファイルのパスを取得する
    // https://dobon.net/vb/dotnet/vb6/apppath.html
    public String appPath = System.Reflection.Assembly.GetExecutingAssembly().Location;

    // 名前空間まで含めてクラス名を取得
    public String appFullClassName; //= this.PlayerPanel.GetType().FullName;
    // クラス名のみ取得
    public String appClassName;// = this.GetType().Name;
    #endregion

    #region Constructor
    public PlayerPanel()
    {
      this.InitializeComponent();
      this.InitializeInterface();
      this.LoadControls();
    }
    #endregion

    #region Initialization
    public void InitializeInterface()
    {
      this.appFullClassName = this.GetType().FullName;
      this.appClassName = this.GetType().Name;
      this.AccessibleDescription = this.appFullClassName + "@" + this.appPath;
      /*
      string guid = "92d9a647-6cd3-4347-9db6-95f324292399";
      this.antPlugin = (PluginMain)PluginBase.MainForm.FindPlugin(guid);
      this.Instance = new ChildFormControlClass();
      this.Instance.name = "PlayerPanel";
      this.Instance.toolStrip = this.toolStrip1;
      this.Instance.menuStrip = this.menuStrip1;
      this.Instance.statusStrip = this.statusStrip1;
      this.Instance.スクリプトToolStripMenuItem = this.スクリプトSToolStripMenuItem;
      this.Instance.PreviousDocuments = this.PreviousDocuments;
      this.Instance.callPluginCommand = this.CallPluginCommand;
      */
    }

  public void LoadControls()
    {
      this.browser = new Browser(this);
      this.browser.Dock = DockStyle.Fill;
      this.Controls.Add(this.browser);
      
      //this.Controls.Remove(this.pictureBox1);
      //this.picturePanel = new PicturePanel(this);
      //this.picturePanel.Dock = DockStyle.Fill;
      //this.Controls.Add(this.picturePanel);
      //MessageBox.Show(this.Controls.Count.ToString());

      //this.Controls.Remove(this.richTextBox1);
      //this.editor = new RichTextEditor(this);
      //this.editor.menuStrip1.Visible = false;
      //this.editor.Dock = DockStyle.Fill;
      //this.Controls.Add(this.editor);
    }

    private void InitializePlayerPanel()
    {
      /*
      this.menuStrip1.Visible = true;
      this.statusStrip1.Visible = false;
      this.toolStrip1.Visible = false;
      this.playerPToolStripMenuItem.Tag = this.axWindowsMediaPlayer1;
      this.propertyGridGToolStripMenuItem.Tag = this.propertyGrid1;
      this.pictureIToolStripMenuItem.Tag = this.picturePanel;// this.pictureBox1;
      this.richTextRToolStripMenuItem.Tag = this.editor;
      this.browserbToolStripMenuItem.Tag = this.browser;// this.webBrowser1;
      */                                                  //this.InitializeBrowser();
    }
    #endregion

    #region Event Handler
    private void PlayerPanel_Load(object sender, EventArgs e){ }

    private void PlayerPanel_Enter(object sender, EventArgs e)
    {
      this.filePath = this.AccessibleName;
      if (File.Exists(this.filePath))
      {
        if (Lib.IsSoundFile(this.filePath) || Lib.IsVideoFile(this.filePath))
        {
          this.axWindowsMediaPlayer1.URL = this.filePath;
          this.axWindowsMediaPlayer1.BringToFront();
        }
        else if (Lib.IsImageFile(this.filePath))
        {
          this.pictureBox1.Image = Image.FromFile(this.filePath);
          this.pictureBox1.BringToFront();
        }
        else
        {
          try
          {
            if (Path.GetExtension(this.filePath) == ".rtf")
            {
              this.richTextBox1.LoadFile(this.filePath);
              //this.editor.richTextBox1.LoadFile(path);
            }
            else
            {
              this.richTextBox1.Text = Lib.File_ReadToEndDecode(this.filePath);
              //this.editor.richTextBox1.Text = Lib.File_ReadToEndDecode(path);
            }
            this.richTextBox1.BringToFront();
          }
          catch (Exception ex)
          {
            string message = ex.Message.ToString();
            MessageBox.Show(Lib.OutputError(message), MethodBase.GetCurrentMethod().Name);
          }
        }
      }
      else if (Lib.IsWebSite(this.filePath))
      {
        this.browser.WebBrowser.Navigate(this.filePath);
        this.browser.BringToFront();
      }
      else this.axWindowsMediaPlayer1.URL = @"F:\My Music\２つのミサ曲\２つのミサ曲.asx";
    }
    #endregion

    #region General Method
    public void CallMainCommand(String name, String argStr)
    {
      string AccessibleDefaultActionDescription = this.AccessibleDefaultActionDescription;
      String classname = AccessibleDefaultActionDescription.Split('@')[0];
      String path = AccessibleDefaultActionDescription.Split('@')[1];
      Object[] parameters = new Object[2];
      parameters[0] = name; parameters[1] = argStr;
      try
      {
        Assembly assembly = Assembly.LoadFrom(path);
        Type type = assembly.GetType(classname);
        Object instance = (Object)Activator.CreateInstance(type);
        MethodInfo method3 = type.GetMethod("CallCommandFromDll");
        method3.Invoke(instance, parameters);
        /*
          switch (accessor.ToLower())
          {
            case "private":
              MethodInfo method = type.GetMethod(methodname, BindingFlags.InvokeMethod | BindingFlags.NonPublic | BindingFlags.Instance);
              method.Invoke(instance, parameters);
              return true;
            case "static":
              MethodInfo method2
                   = type.GetMethod(methodname, BindingFlags.Static | BindingFlags.Public);
              method2.Invoke(null, parameters);
              return true;
            default:
              MethodInfo method3 = type.GetMethod(methodname);
              method3.Invoke(instance, parameters);
              return true;
          }
          */
      }
      catch (Exception exc)
      {
        MessageBox.Show(exc.Message.ToString());
        //  , "CallCommand(String name, String tag)");
      }
    }
    #endregion

    #region Click Handler
    private void バージョン情報AToolStripMenuItem_Click(object sender, EventArgs e)
    {
      this.CallMainCommand("About", "");
    }

    public void Test1(object sender, EventArgs e)
    {
      if (sender != null)
      {
        ToolStripItem button = (ToolStripItem)sender;
        //String msg = button.Tag as String;
        String msg = button.AccessibleName;
        MessageBox.Show(msg, MethodBase.GetCurrentMethod().Name);
      }
    }


    #endregion

  }
}
