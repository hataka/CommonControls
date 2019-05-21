using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using CommonLibrary;
using CommonLibrary.FlashPanel;
using System.Configuration;
using MDIForm.CommonLibrary;

namespace CommonControl
{
  public partial class FlashPanel : UserControl
  {
    #region Variables
    global::FlashPanel.Properties.Settings
      settings = new global::FlashPanel.Properties.Settings();
    //CommonLibrary.Settings commonsettings = new CommonLibrary.Settings();
    
    public BrowserEx browser;
    public String filePath = String.Empty;

    public List<string> previousDocuments = new List<string>();
    public List<string> favorateDocuments = new List<string>();

    #endregion

    #region Constructor
    public FlashPanel()
    {
      InitializeComponent();
      InitializeFlashPanel();
    }
    #endregion

    #region Initialization
    private void InitializeFlashPanel()
    {
      //MessageBox.Show(this.settings.Name);
      this.menuStrip1.Visible = this.settings.MenuBarVisible;
      this.toolStrip1.Visible = this.settings.ToolBarVisible;
      this.statusStrip1.Visible = this.settings.StatusBarVisible;


      // https://stackoverflow.com/questions/844412/convert-stringcollection-to-liststring
      //List<string> listOfStrings = new List<string>(new StringCollectionEnumerable(stringCollection));
      for (int i = 0; i < this.settings.PreviousDocuments.Count; i++)
      {
        this.previousDocuments.Add(this.settings.PreviousDocuments[i]);
      }
      this.PopulatePreviousDocumentsMenu();

      for (int i = 0; i < this.settings.BookMarks.Count; i++)
      {
        this.favorateDocuments.Add(this.settings.BookMarks[i]);
      }
      this.PopulateFavorateDocumentsMenu();

      this.browser = new BrowserEx();
      browser.Dock = DockStyle.Fill;
      browser.webBrowser1.Navigate("http://www.google.co.jp");
      this.Controls.Add(browser);
      browser.SendToBack();
      this.propertyGrid1.SelectedObject = this.settings;
    }
    #endregion

    #region Event Handler 
    private void FlashPanel_Load(object sender, EventArgs e)
    {
      //  まだ this.AccessibleDescription はロードされていない
      //  ここにおくとだめ
      //MessageBox.Show(this.AccessibleDescription);
    }

    private void FlashPanel_Enter(object sender, EventArgs e)
    {
      // OK!!!!
      //MessageBox.Show(this.AccessibleName);
      //MessageBox.Show(this.AccessibleDescription);
      // おかしい MenuBarが消える
      //ApplySetting();
    }

    private void axShockwaveFlash1_Enter(object sender, EventArgs e)
    {
      String path = String.Empty;
      try
      {
        path = this.axShockwaveFlash1.Tag as string;
        this.filePath = path;
      }
      catch { }
      //ここでもだめ
      //ApplySetting();

      if (!String.IsNullOrEmpty(path) && File.Exists(path))
      {
        this.axShockwaveFlash1.BringToFront();
        this.axShockwaveFlash1.LoadMovie(0, path);
        this.browser.webBrowser1.Navigate(path);
        this.toolStripStatusLabel1.Text = path;
      }
    }

    public  void ApplySetting()
    {
      /*
      //MessageBox.Show(this.AccessibleDescription);
      Dictionary<String, String> dic = StringHandler.Get_Values(this.AccessibleName, ';','=');
      // ループ変数にKeyValuePairを使う
      foreach (KeyValuePair<string, string> kvp in dic)
      {
        string key = kvp.Key;
        string value = kvp.Value;
        MessageBox.Show(value,key);
      }
     
      if (dic.ContainsKey("MenuBarVisible"))
      {
         //this.menuStrip1.Visible = Convert.ToBoolean(dic["MenuBarVisible"]);
        this.menuStrip1.Visible = dic["MenuBarVisible"].ToLower() == "true" ? true : false;
      }
      if (dic.ContainsKey("ToolBarVisible")) this.toolStrip1.Visible = Convert.ToBoolean(dic["ToolBarVisible"]);
      if (dic.ContainsKey("StatusBarVisible")) this.menuStrip1.Visible = Convert.ToBoolean(dic["StatusBarVisible"]);
      */
    }

    private void SaveSettings()
    {
      this.settings.PreviousDocuments.Clear();
      this.settings.PreviousDocuments.AddRange(this.previousDocuments.ToArray());
      this.settings.MenuBarVisible = this.menuStrip1.Visible;
      this.settings.ToolBarVisible = this.toolStrip1.Visible;
      this.settings.StatusBarVisible = this.statusStrip1.Visible;
      this.settings.BookMarks.Clear();
      this.settings.BookMarks.AddRange(this.favorateDocuments.ToArray());
      this.settings.Save();
    }

    #endregion

    #region Click Handler
    private void 開くOToolStripMenuItem_Click(object sender, EventArgs e)
    {
      string initialDirectory = Path.GetDirectoryName(this.filePath);
      string filter = "swfファイル(*.swf)|*.swf|すべてのファイル(*.*)|*.*";
      string fileName = Path.GetFileName(this.filePath);
      string file = Lib.File_OpenDialog(fileName, initialDirectory, filter);
      try
      {
        this.filePath = file;
        this.axShockwaveFlash1.BringToFront();
        this.axShockwaveFlash1.LoadMovie(0, file);
        this.browser.webBrowser1.Navigate(file);
        this.AddPreviousDocuments(file);
        this.toolStripStatusLabel1.Text = file;
      }
      catch(Exception exc)
      {
        MessageBox.Show(exc.Message, ToString());
      }
    }

    private void 最近開いたファイルをクリアCToolStripMenuItem_Click(object sender, EventArgs e)
    {
      this.previousDocuments.Clear();
      this.PopulatePreviousDocumentsMenu();
    }


    private void 名前を付けて保存AToolStripMenuItem_Click(object sender, EventArgs e)
    {

    }

    private void 終了XToolStripMenuItem_Click(object sender, EventArgs e)
    {

    }

    private void ツールバーTToolStripMenuItem_Click(object sender, EventArgs e)
    {
      this.toolStrip1.Visible = this.ツールバーTToolStripMenuItem.Checked;
    }

    private void ステータスバーSToolStripMenuItem_Click(object sender, EventArgs e)
    {
      this.statusStrip1.Visible = this.ステータスバーSToolStripMenuItem.Checked;
    }

    private void カスタマイズCToolStripMenuItem_Click(object sender, EventArgs e)
    {
      //this.propertyGrid1.BringToFront();
    }

    private void browserで表示ToolStripMenuItem_Click(object sender, EventArgs e)
    {
      this.browser.BringToFront();
    }

    private void systemで開くPToolStripMenuItem_Click(object sender, EventArgs e)
    {
      System.Diagnostics.Process.Start(this.filePath);
    }

    private void ActivateControl(object sender, EventArgs e)
    {
      ToolStripMenuItem item = sender as ToolStripMenuItem;
      this.flashFToolStripMenuItem.Checked = false;
      this.browserBToolStripMenuItem.Checked = false;
      this.propertyGridPToolStripMenuItem.Checked = false;
      item.Checked = true;
      switch(item.Name)
      {
        case "flashFToolStripMenuItem":
          this.axShockwaveFlash1.BringToFront();
          this.axShockwaveFlash1.Refresh();
          break;
        case "browserBToolStripMenuItem":
          this.browser.BringToFront();
          this.browser.Refresh();
          break;
        case "propertyGridPToolStripMenuItem":
          this.propertyGrid1.BringToFront();
          this.propertyGrid1.Refresh();
          break;
      }
    }

    private void 共通設定ToolStripMenuItem_Click(object sender, EventArgs e)
    {
      //this.propertyGrid1.SelectedObject = this.commonsettings;
      this.propertyGrid1.BringToFront();
    }

    private void 設定ToolStripMenuItem_Click(object sender, EventArgs e)
    {
      this.propertyGrid1.SelectedObject = this.settings;
      this.propertyGrid1.BringToFront();
    }
    #endregion

    #region FavorateDocument Management

    private void AddFavorateDocuments(String data)
    {
      try
      {
        ToolStripMenuItem toolStripMenuItem = this.お気に入りFToolStripMenuItem;
        if (this.favorateDocuments.Contains(data))
        {
          this.favorateDocuments.Remove(data);
        }
        this.favorateDocuments.Insert(0, data);
        this.PopulateFavorateDocumentsMenu();
      }
      catch (Exception ex)
      {
        MessageBox.Show(ex.Message.ToString());
      }
    }

    public void PopulateFavorateDocumentsMenu()
    {
      try
      {
        ToolStripMenuItem toolStripMenuItem = this.お気に入りFToolStripMenuItem;
        toolStripMenuItem.DropDownItems.Clear();
        for (int i = 0; i < this.favorateDocuments.Count; i++)
        {
          string text = this.favorateDocuments[i];
          ToolStripMenuItem toolStripMenuItem2 = new ToolStripMenuItem();
          toolStripMenuItem2.Click += new EventHandler(this.FavorateDocumentsMenuItem_Click);
          toolStripMenuItem2.Tag = text;
          toolStripMenuItem2.Text = text;
          if (i < 15)
          {
            toolStripMenuItem.DropDownItems.Add(toolStripMenuItem2);
          }
          else
          {
            this.favorateDocuments.Remove(text);
          }
        }
        if (this.favorateDocuments.Count > 0)
        {
          toolStripMenuItem.DropDownItems.Add(new ToolStripSeparator());
          toolStripMenuItem.DropDownItems.Add(this.お気に入りに追加AToolStripMenuItem);
          toolStripMenuItem.DropDownItems.Add(this.お気に入りをクリアCToolStripMenuItem);
          toolStripMenuItem.DropDownItems.Add(new ToolStripSeparator());
          toolStripMenuItem.DropDownItems.Add(this.kingFMKToolStripMenuItem);
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

    private void FavorateDocumentsMenuItem_Click(object sender, EventArgs e)
    {

      ToolStripMenuItem toolStripMenuItem = (ToolStripMenuItem)sender;
      string file = toolStripMenuItem.Tag as string;
      try
      {
        this.filePath = file;
        this.axShockwaveFlash1.BringToFront();
        this.axShockwaveFlash1.LoadMovie(0, file);
        this.browser.webBrowser1.Navigate(file);
        this.AddPreviousDocuments(file);
        this.toolStripStatusLabel1.Text = file;
      }
      catch (Exception exc)
      {
        MessageBox.Show(exc.Message.ToString());
      }
    }

    private void お気に入りに追加AToolStripMenuItem_Click(object sender, EventArgs e)
    {
      this.AddFavorateDocuments(this.filePath);
      this.PopulateFavorateDocumentsMenu();
      this.SaveSettings();
    }

    private void お気に入りをクリアCToolStripMenuItem_Click(object sender, EventArgs e)
    {
      this.favorateDocuments.Clear();
      this.PopulateFavorateDocumentsMenu();
    }

    #endregion

    #region PreviousDocumentt Management
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
          //((Control)toolStripMenuItem2).ContextMenuStrip = this.contextMenuStrip1;
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
      string file = toolStripMenuItem.Tag as string;
      try
      {
        this.filePath = file;
        this.axShockwaveFlash1.BringToFront();
        this.axShockwaveFlash1.LoadMovie(0, file);
        this.browser.webBrowser1.Navigate(file);
        this.AddPreviousDocuments(file);
        this.toolStripStatusLabel1.Text = file;
      }
      catch (Exception exc)
      {
        MessageBox.Show(exc.Message.ToString());
      }
    }

    /*
    public void AddPreviousDocuments(string data)
    {
      try
      {
        ToolStripMenuItem toolStripMenuItem = this.最近開いたファイルToolStripMenuItem;
        if (this.previousDocuments.Contains(data))
        {
          this.previousDocuments.Remove(data);
        }
        this.previousDocuments.Insert(0, data);
        this.UpdateAccessibleDescription();
        this.PopulatePreviousDocumentsMenu();
      }
      catch (Exception ex)
      {
        MessageBox.Show(ex.Message.ToString());
      }
    }
    */

    /*
    public void PopulatePreviousDocumentsMenu()
    {
      try
      {
        ToolStripMenuItem toolStripMenuItem = this.最近開いたファイルToolStripMenuItem;
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
          toolStripMenuItem.DropDownItems.Add(this.最近開いたファイルをクリアToolStripMenuItem);
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
    */
    /*
    private void PreviousDocumentsMenuItem_Click(object sender, EventArgs e)
    {
      ToolStripMenuItem toolStripMenuItem = (ToolStripMenuItem)sender;
      string text = toolStripMenuItem.Tag as string;
      if (File.Exists(text) && Lib.IsImageFile(text))
      {
        try
        {
          if (!this.ScribbleMode && !this.RubberBandMode)
          {
            this.pictureBox1.Image = new Bitmap(text);
            this.pictureBox1.SizeMode = PictureBoxSizeMode.Zoom;
            ((Form)base.Parent).Text = Path.GetFileName(text);
            this.pictureBox1.Tag = text;
            this.AddPreviousDocuments(text);
            this.pictureBox1.Refresh();
          }
        }
        catch (Exception ex)
        {
          string text2 = ex.Message.ToString();
          MessageBox.Show(Lib.OutputError(text2));
        }
      }
      else if (text.StartsWith("qcgraph!"))
      {
        this.AddPreviousDocuments(text);
        this.DrawQcGraphItem(text.Replace("qcgraph!", ""));
      }
    }
    */
    private void 最近開いたファイルをクリアToolStripMenuItem_Click(object sender, EventArgs e)
    {
      this.previousDocuments.Clear();
      this.PopulatePreviousDocumentsMenu();
      //this.UpdateAccessibleDescription();
    }








    #endregion

   
    private void test()
    {
      ExeConfigurationFileMap efm = new ExeConfigurationFileMap { ExeConfigFilename = "AppConfig/app.config" };
      Configuration configuration = ConfigurationManager.OpenMappedExeConfiguration(efm, ConfigurationUserLevel.None);
      if (configuration.HasFile)
      {
        AppSettingsSection appSettings = configuration.AppSettings;
        KeyValueConfigurationElement element = appSettings.Settings["myconfig"];
        Console.WriteLine(element.Value);
        Console.ReadKey(true);
      }
    }
   


  }
}
