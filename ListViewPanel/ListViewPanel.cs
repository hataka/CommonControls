using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.Diagnostics;
using System.IO;
using MDIForm.CommonLibrary;

namespace CommonControl
{
  public partial class ListViewPanel : UserControl
  {

    #region Variables
    public String filePath = String.Empty;
    //public XMLTreeMenu.Settings settings;
    public List<string> previousDocuments = new List<string>();
    public List<string> favorateDocuments = new List<string>();
    public ListView.SelectedListViewItemCollection selectedItems;
    // データセット作成
    public DataSet dS;// = new DataSet("dS");
    // データテーブル作成
    public DataTable dT = new DataTable("dT");
    private BindingSource bindingSource1 = new BindingSource();

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

    public List<string> FavorateDocuments
    {
      get
      {
        return this.favorateDocuments;
      }
      set
      {
        this.favorateDocuments = value;
      }
    }
   
        public ListView listView
        {
          get
          {
            //return this.Instance.listView;
        return this.listView1;
      }
      set
          {
          }
        }
    
    #endregion

    #region Constructor
    public ListViewPanel()
    {
      this.InitializeListViewPanel();
    }
    /*
    public ListViewPanel(ParentFormClass maiForm)
    {
      this.MainForm = maiForm;
      this.InitializeListViewPanel();
    }
    */
    public ListViewPanel(ListView listView)
    {
      this.listView1 = listView;
      this.InitializeListViewPanel();
    }

    public ListViewPanel(String filepath)
    {
      this.filePath = filepath;
      this.InitializeListViewPanel();
    }

    public void InitializeListViewPanel()
    {
      this.InitializeComponent();
      this.InitializeInterface();
      this.Text = "ListViewPanel";
      this.menuStrip1.Visible = false;
      this.toolStrip1.Visible = false;
      this.InitializeListView();
      //Bitmap value = ((System.Drawing.Bitmap)(this.toolStripButton1.Image));
      //this.imageList1.Images.AddStrip(value);
      //this.imageList1.TransparentColor = Color.FromArgb(233, 229, 215);
    }

    private void InitializeListView()
    {
      // Set the view to show details.
      //this.listView1.View = View.LargeIcon;
      this.listView1.View = View.Details;

      // Allow the user to edit item text.
      this.listView1.LabelEdit = true;

      // Allow the user to rearrange columns.
      this.listView1.AllowColumnReorder = true;

      // Select the item and subitems when selection is made.
      this.listView1.FullRowSelect = true;

      // Display grid lines.
      this.listView1.GridLines = true;

      // Sort the items in the list in ascending order.
      this.listView1.Sorting = SortOrder.Ascending;

      this.listView1.SmallImageList = this.imageList1;
      this.listView1.LargeImageList = this.imageList1;
      this.listView1.ContextMenuStrip = this.contextMenuStrip1;


      //this.bindingNavigator1.BindingSource = (DataTable)this.listView1;

      // Attach Subitems to the ListView
      //listView1.Columns.Add("Title", 300, HorizontalAlignment.Left);
      ColumnHeader columnHeader1 = new ColumnHeader();
      columnHeader1.Text = "ファイル";
      columnHeader1.TextAlign = HorizontalAlignment.Left;
      columnHeader1.Width = -1;
      this.listView1.Columns.Add(columnHeader1);

      ColumnHeader columnHeader2 = new ColumnHeader();
      columnHeader2.Text = "サイズ";
      columnHeader2.TextAlign = HorizontalAlignment.Left;
      columnHeader2.Width = -1;
      this.listView1.Columns.Add(columnHeader2);

      ColumnHeader columnHeader3 = new ColumnHeader();
      columnHeader3.Text = "種類";
      columnHeader3.TextAlign = HorizontalAlignment.Left;
      columnHeader3.Width = -1;
      this.listView1.Columns.Add(columnHeader3);

      ColumnHeader columnHeader4 = new ColumnHeader();
      columnHeader4.Text = "更新日時";
      columnHeader4.TextAlign = HorizontalAlignment.Left;
      columnHeader4.Width = -1;
      this.listView1.Columns.Add(columnHeader4);

      // The ListViewItemSorter property allows you to specify the
      // object that performs the sorting of items in the ListView.
      // You can use the ListViewItemSorter property in combination
      // with the Sort method to perform custom sorting.
      //_lvwItemComparer = new ListViewItemComparer();
      //this.listView1.ListViewItemSorter = _lvwItemComparer;

      this.dT.Columns.Add("ファイル", typeof(string));
      this.dT.Columns.Add("サイズ", typeof(string));
      this.dT.Columns.Add("種類", typeof(string));
      this.dT.Columns.Add("更新日時", typeof(string));
      //this.bindingSource1.DataSource = this.dT;
      //this.bindingNavigator1.BindingSource = this.bindingSource1;
    }

    public void InitializeInterface()
    {
      /*
      string guid = "0538077E-8C37-4A2B-962B-8FB77DC9F325";
      //Application で例外発生
      try
      {
        this.xmlTreeMenu = (PluginMain)PluginBase.MainForm.FindPlugin(guid);
      }
      catch { }

      this.Instance = new ChildFormControlClass();
      this.Instance.name = "ListViewPanel";
      this.Instance.toolStrip = this.toolStrip1;
      this.Instance.listView = this.listView1;
      this.Instance.bindingNavigator = this.bindingNavigator1;
      this.Instance.MainForm = this;
      this.Instance.menuStrip = this.menuStrip1;
      this.Instance.statusStrip = this.statusStrip1;
      this.Instance.スクリプトToolStripMenuItem = this.スクリプトSToolStripMenuItem;
      this.Instance.PreviousDocuments = this.PreviousDocuments;
     */
    }

    #endregion

    #region Listview Click Handler

    private void ListViewPanel_Load(object sender, EventArgs e)
    {
      try
      {
        //MessageBox.Show("xmlTreeMenu_pluginUI: " + this.MainForm.xmlTreeMenu_pluginUI.GetType().ToString());
        //this.xmlTreeMenuUI = this.MainForm.xmlTreeMenu_pluginUI as XMLTreeMenu.PluginUI; ;
      }
      catch { }
      this.globSearchButton.PerformClick();
    }

    private void listView1_Click(object sender, EventArgs e)
    {
      // 選択項目があるかどうかを確認する
      if (listView1.SelectedItems.Count == 0) return; // 選択項目がないので処理をせず抜ける
      this.selectedItems = listView1.SelectedItems;
      this.filePath = this.selectedItems[0].Tag.ToString();
    }

    private void globFolderButton_Click(object sender, EventArgs e)
    {
      //FolderBrowserDialogクラスのインスタンスを作成
      FolderBrowserDialog fbd = new FolderBrowserDialog();

      //上部に表示する説明テキストを指定する
      fbd.Description = "フォルダを指定してください。";
      //ルートフォルダを指定する
      //デフォルトでDesktop
      fbd.RootFolder = Environment.SpecialFolder.Desktop;
      //最初に選択するフォルダを指定する
      //RootFolder以下にあるフォルダである必要がある
      fbd.SelectedPath = @"C:\Windows";
      //ユーザーが新しいフォルダを作成できるようにする
      //デフォルトでTrue
      fbd.ShowNewFolderButton = true;

      //ダイアログを表示する
      if (fbd.ShowDialog(this) == DialogResult.OK)
      {
        //選択されたフォルダを表示する
        //Console.WriteLine(fbd.SelectedPath);
        this.toolStripComboBox1.Text = fbd.SelectedPath;
      }
    }

    private void globSearchButton_Click(object sender, EventArgs e)
    {
      //http://dobon.net/vb/dotnet/file/getfiles.html
      this.dT.Rows.Clear();
      this.listView1.Items.Clear();

      String globDir = this.toolStripComboBox1.Text;
      String pattern = this.toolStripComboBox2.Text;
      string[] files = System.IO.Directory.GetFiles(globDir, pattern, System.IO.SearchOption.AllDirectories);
      String columntext = "Glob " + "Folder: " + globDir + " Pattern; " + pattern + " 全" + files.Length.ToString() + "件";

      for (int i = 0; i < files.Length; i++)
      {
        //FileInfoオブジェクトを作成
        System.IO.FileInfo fi = new System.IO.FileInfo(files[i]);
        //隠し属性があるか調べる
        if ((fi.Attributes & System.IO.FileAttributes.Hidden) == System.IO.FileAttributes.Hidden)
        {
          //Console.WriteLine("隠し属性があります。");
        }
        //隠し属性を追加する
        //fi.Attributes |= System.IO.FileAttributes.Hidden;
        //隠し属性を削除する
        //fi.Attributes &= ~System.IO.FileAttributes.Hidden;
        //読み取り専用属性を付ける
        //fi.IsReadOnly = true;
        //作成日時の取得
        //Console.WriteLine(fi.CreationTime);
        //更新日時の取得
        //Console.WriteLine(fi.LastWriteTime);
        //アクセス日時の取得
        //Console.WriteLine(fi.LastAccessTime);
        //作成日時の設定
        //fi.CreationTime = DateTime.Now;
        //更新日時の設定
        //fi.LastWriteTime = DateTime.Now;
        //アクセス日時の設定
        //fi.LastAccessTime = DateTime.Now;
        //ファイルのサイズを取得
        //long filesize = fi.Length;

        ListViewItem listItem = new ListViewItem(files[i]);
        //ListViewItem listItem = new ListViewItem(Path.GetFileName(files[i]), this.GetIconImageIndex(files[i]));

        
        //TODO
        //ListViewItem listItem = new ListViewItem(Path.GetFileName(files[i]), ExtractIconIfNecessary(files[i], true));

        listItem.Tag = files[i];
        listItem.ToolTipText = files[i];
        listItem.SubItems.Add(fi.Length.ToString());
        listItem.SubItems.Add(Path.GetExtension(fi.Name).Replace(".", ""));
        listItem.SubItems.Add(fi.LastWriteTime.ToString());
        this.listView1.Items.Add(listItem);

        /*
        //データロウ作成
        DataRow dR = dT.NewRow();
        dR = this.dT.NewRow();
        // データロウ レコード作成
        dR["ファイル"] = files[i];
        dR["サイズ"] = fi.Length.ToString();
        dR["種類"] = Path.GetExtension(fi.Name).Replace(".", "");
        dR["更新日時"] = fi.LastWriteTime.ToString();
        // データテーブル レコード追加
        this.dT.Rows.Add(dR);
       */
      }

      //this.LoadList();


      foreach (ColumnHeader ch in this.listView1.Columns)
      {
        ch.Width = -1;
      }

      this.listView1.Refresh();
      //FIXME
      //if (!this.toolStripComboBox1_ItemExists(globDir)) this.toolStripComboBox1.Items.Insert(0, globDir);
      // リストビュー データソース選択
      //this.listView1.DataSource = dS;
      // リストビュー データバインド
      //this.listView1.DataBindings();
    }


    // Load Data from the DataSet into the ListView
    private void LoadList()
    {
      // Get the table from the data set
      //DataTable dtable = _DataSet.Tables["Titles"];

      // Clear the ListView control
      this.listView1.Items.Clear();

      // Display items in the ListView control
      for (int i = 0; i < this.dT.Rows.Count; i++)
      {
        DataRow drow = this.dT.Rows[i];
        // Only row that have not been deleted
        if (drow.RowState != DataRowState.Deleted)
        {
          // Define the list items

          ListViewItem listItem = new ListViewItem(Path.GetFileName(drow["ファイル"].ToString()));
          //TODO
          //ListViewItem listItem = new ListViewItem(Path.GetFileName(drow["ファイル"].ToString()),
          //  ExtractIconIfNecessary(drow["ファイル"].ToString(), true));


          listItem.Tag = drow["ファイル"].ToString();
          listItem.ToolTipText = drow["ファイル"].ToString();
          listItem.SubItems.Add(drow["サイズ"].ToString());
          listItem.SubItems.Add(drow["種類"].ToString());
          listItem.SubItems.Add(drow["更新日時"].ToString());
          // Add the list items to the ListView
          this.listView1.Items.Add(listItem);
        }
      }
    }

    private void listView1_DoubleClick(object sender, EventArgs e)
    {
      // 選択項目があるかどうかを確認する
      if (listView1.SelectedItems.Count == 0) return; // 選択項目がないので処理をせず抜ける
      ListViewItem itemx = listView1.SelectedItems[0];
      String path = itemx.Tag.ToString();
      if (System.IO.Directory.Exists(path))
      {
        DirectoryInfo dir = new DirectoryInfo(path);
        FileSystemInfo[] infos = dir.GetFileSystemInfos();
        this.UpdateUI(this.filePath, dir, infos);
      }
      else if (System.IO.File.Exists(path))
      {
        try
        {
          switch (this.toolStripComboBox3.Text.ToLower())
          {
            case "opendocument":
              //PluginBase.MainForm.CallCommand("PluginCommand", @"XMLTreeMenu.OpenDocument;" + path);
              break;
            case "inplace":
              //PluginBase.MainForm.CallCommand("PluginCommand", @"XMLTreeMenu.ExecuteInPlace;" + path);
              break;
            case "conexe":
              Process.Start("cmd.exe", "/k " + path);
              break;
            case "runprocess":
            default:
              Process.Start(path);
              break;
          }
        }
        catch (Exception ex)
        {
          MessageBox.Show(ex.Message.ToString());
        }
      }
    }

    /// <summary>
    /// Updates the UI in the GUI thread
    /// </summary>
    private void UpdateUI(string path, DirectoryInfo directory, FileSystemInfo[] infos)
    {
      this.listView1.Columns[0].Text = path;
      //this.ClearImageList();
      //this.pluginMain.Settings.FilePath = path;
      //this.selectedPath.Text = path;
      this.filePath = path;
      this.listView1.BeginUpdate();
      this.listView.ListViewItemSorter = null;
      this.listView.Items.Clear();
      try
      {
        ListViewItem item;
        if (directory.Parent != null)
        {
          item = new ListViewItem("[..]", 2);
          //TODO
          //item = new ListViewItem("[..]", ExtractIconIfNecessary("/Folder/", false));
          item.Tag = directory.Parent.FullName;
          item.SubItems.Add("-");
          item.SubItems.Add("-");
          item.SubItems.Add("-");
          this.listView1.Items.Add(item);
        }
        foreach (FileSystemInfo info in infos)
        {
          DirectoryInfo subDir = info as DirectoryInfo;
          if (subDir != null && (subDir.Attributes & FileAttributes.Hidden) == 0)
          {
            item = new ListViewItem(subDir.Name, 2);
            //TODO
            //item = new ListViewItem(subDir.Name, ExtractIconIfNecessary(subDir.FullName, false));
            item.Tag = subDir.FullName;
            item.SubItems.Add("-");
            item.SubItems.Add("-");
            item.SubItems.Add(subDir.LastWriteTime.ToString());
            this.listView1.Items.Add(item);
          }
        }
        foreach (FileSystemInfo info in infos)
        {
          FileInfo file = info as FileInfo;
          if (file != null && (file.Attributes & FileAttributes.Hidden) == 0)
          {
            //String kbs = TextHelper.GetString("Info.Kilobytes");
            String kbs = "KB";

            //TODO
            item = new ListViewItem(file.Name, 2);
            //item = new ListViewItem(file.Name, this.GetIconImageIndex(file.FullName));
            item.Tag = file.FullName;
            item.ToolTipText = file.FullName;
            if (file.Length / 1024 < 1) item.SubItems.Add("1 " + kbs);
            else item.SubItems.Add((file.Length / 1024) + " " + kbs);
            item.SubItems.Add(file.Extension.ToUpper().Replace(".", ""));
            item.SubItems.Add(file.LastWriteTime.ToString());
            this.listView1.Items.Add(item);
          }
        }
        //this.watcher.Path = path;
        //this.listView.ListViewItemSorter = this.listViewSorter;
      }
      finally
      {
        // Select the possible created item
        /*
        if (this.autoSelectItem != null)
        {
          foreach (ListViewItem item in this.listView.Items)
          {
            if (item.Text == this.autoSelectItem)
            {
              this.fileView.Focus();
              item.BeginEdit();
              break;
            }
          }
          this.autoSelectItem = null;
        }
        */
        this.Cursor = Cursors.Default;
        this.listView.ContextMenuStrip = this.contextMenuStrip1;
        //this.syncronizeButton.Enabled = true;
        //this.selectedPath.Enabled = true;
        //this.browseButton.Enabled = true;
        //this.updateInProgress = false;
        this.listView.EndUpdate();
      }
    }



    /*
    private void ヘルプLToolStripButton_Click(object sender, EventArgs e)
    {
      //String path = @"F:\VCSharp\FlashDevelop4.3.0x\External\Plugins\DirTreePanel\doxygen\html\index.html";
      String path = "http://hata2/VCSharp/FlashDevelop4.3.0x/External/Plugins/DirTreePanel/doxygen/html/index.html";
      PluginBase.MainForm.CallCommand("PluginCommand", "XMLTreeMenu.BrowseEx;" + path);
    }
    //////////////////////////////////////////////////	
    */



    #endregion


    #region ContextMenu Click Handler

    private void 開くtoolStripMenuItem1_Click(object sender, EventArgs e)
    {
      // 選択項目があるかどうかを確認する
      //if (listView1.SelectedItems.Count == 0) return; // 選択項目がないので処理をせず抜ける
      //ListViewItem itemx = listView1.SelectedItems[0];
      //itemx.SubItems.
      //MessageBox.Show(this.filePath);
    }

    private void フォルダを表示ToolStripMenuItem_Click(object sender, EventArgs e)
    {
      DirectoryInfo dir = new DirectoryInfo(Path.GetDirectoryName(this.filePath));
      FileSystemInfo[] infos = dir.GetFileSystemInfos();
      this.UpdateUI(Path.GetDirectoryName(this.filePath), dir, infos);
    }

    private void ブラウザで開くtoolStripMenuItem1_Click(object sender, EventArgs e)
    {
      String path = this.filePath;
      // TODO
      //this.BrowseEx(this.dirTreeView1.filepath);
      //PluginBase.MainForm.CallCommand("PluginCommand", "XMLTreeMenu.BrowseEx;" + path);
    }

    private void サクラエディタToolStripMenuItem1_Click(object sender, EventArgs e)
    {
      if (File.Exists(this.filePath) && Lib.textfile.Contains(Path.GetExtension(this.filePath.ToLower())))
      {
        if (File.Exists("C:\\Program Files (x86)\\sakura\\sakura.exe"))
        {
          Process.Start("C:\\Program Files (x86)\\sakura\\sakura.exe", this.filePath);
        }
        else if (File.Exists("C:\\TiuDevTools\\sakura\\sakura.exe"))
        {
          Process.Start("C:\\TiuDevTools\\sakura\\sakura.exe", this.filePath);
          return;
        }
      }
    }

    private void pSPadToolStripMenuItem1_Click(object sender, EventArgs e)
    {
      if (File.Exists(this.filePath) && Lib.textfile.Contains(Path.GetExtension(this.filePath.ToLower())))
      {
        if (File.Exists("C:\\Program Files (x86)\\PSPad editor\\PSPad.exe"))
        {
          Process.Start("C:\\Program Files (x86)\\PSPad editor\\PSPad.exe", filePath);
        }
        else if (File.Exists("F:\\Programs\\PSPad editor\\PSPad.exe"))
        {
          Process.Start("F:\\Programs\\PSPad editor\\PSPad.exe", this.filePath);
          return;
        }
      }
    }

    private void fDDocumentToolStripMenuItem_Click(object sender, EventArgs e)
    {
      String path = this.filePath;
      if (System.IO.Directory.Exists(path)) return;
      try
      {
        // TODO
        //this.OpenDocument(path);
        //PluginBase.MainForm.CallCommand("PluginCommand", "XMLTreeMenu.OpenDocument;" + path);
      }
      catch (Exception exc)
      {
        MessageBox.Show(exc.Message.ToString());
      }
    }

    private void azukiControlToolStripMenuItem3_Click(object sender, EventArgs e)
    {
      //MainForm.Run_AzukiControl(DirTreeBox.dirTreeView1.filepath);
      String path = this.filePath;
      if (System.IO.Directory.Exists(path)) return;
      try
      {
        // HACK - dirTreeView1_azukiControlToolStripMenuItem3_Click
        //this.OpenDocument(path);
        //PluginBase.MainForm.CallCommand("PluginCommand",
        //  "XMLTreeMenu.CreateCustomDocument;AzukiEditor|" + path);
      }
      catch (Exception exc)
      {
        MessageBox.Show(exc.Message.ToString());
      }
    }

    private void richTextEditorToolStripMenuItem1_Click(object sender, EventArgs e)
    {
      //XMLTreeMenu.CreateCustomDocumentMainForm.Run_RichTextEditor(DirTreeBox.dirTreeView1.filepath);
      String path = this.filePath;
      if (System.IO.Directory.Exists(path)) return;
      try
      {
        // HACK - dirTreeView1_richTextEditorToolStripMenuItem1_Click
        //this.OpenDocument(path);
        //PluginBase.MainForm.CallCommand("PluginCommand",
        //  "XMLTreeMenu.CreateCustomDocument;RichTextEditor|" + path);
      }
      catch (Exception exc)
      {
        MessageBox.Show(exc.Message.ToString());
      }
    }

    private void エクスプローラToolStripMenuItem1_Click(object sender, EventArgs e)
    {
      if (Directory.Exists(this.filePath))
      {
        Process.Start(this.filePath);
        return;
      }
      if (Directory.Exists(Path.GetDirectoryName(this.filePath)))
      {
        Process.Start(Path.GetDirectoryName(this.filePath));
      }
    }

    private void コマンドプロンプトToolStripMenuItem1_Click(object sender, EventArgs e)
    {
      if (Directory.Exists(this.filePath))
      {
        Directory.SetCurrentDirectory(this.filePath);
        Process.Start("C:\\windows\\system32\\cmd.exe");
        return;
      }
      if (Directory.Exists(Path.GetDirectoryName(this.filePath)))
      {
        Directory.SetCurrentDirectory(Path.GetDirectoryName(this.filePath));
        Process.Start("C:\\windows\\system32\\cmd.exe");
      }
    }

    private void viewerToolStripMenuItem_Click(object sender, EventArgs e)
    {
      //MainForm.Run_PHPViewer(DirTreeBox.dirTreeView1.filepath);
    }

    private void システムプログラムToolStripMenuItem_Click(object sender, EventArgs e)
    {
      if (File.Exists(this.filePath))
      {
        Process.Start(this.filePath);
      }
    }

    private void コンテキストメニューtoolStripMenuItem1_Click(object sender, EventArgs e)
    {
      /*
      // TODO
      //if (treeView1.SelectedNode != null)
      try
      {
        FileInfo[] selectedPathsAndFiles = new FileInfo[1];
        // 選択ノードのPathを取得
        String path = this.filePath;
        if (!File.Exists(path)) return;
        ShellContextMenu scm = new ShellContextMenu();
        Point location = new Point(this.contextMenuStrip1.Bounds.Left,
                                    this.contextMenuStrip1.Bounds.Top);
        selectedPathsAndFiles[0] = new FileInfo(path);
        this.contextMenuStrip1.Hide(); // Hide default menu
        scm.ShowContextMenu(selectedPathsAndFiles, location);
      }
      catch //else
      {
        MessageBox.Show("ノードを選択してください");
      }
      */
    }

    private void 再読込みRToolStripMenuItem_Click(object sender, EventArgs e)
    {
      //String path = this.selectedPath.Text;
      //if (!String.IsNullOrEmpty(path)) this.PopulateFileView(path);
      //String path = this.selectedPath.Text;
      //if (!String.IsNullOrEmpty(path)) this.PopulateFileView(path);
    }

    private void プロジェクトにシンクロSToolStripMenuItem_Click(object sender, EventArgs e)
    {
      //String path = this.selectedPath.Text;
      //if (!String.IsNullOrEmpty(path)) this.PopulateFileView(path);

    }

    private void 新規ファイルNToolStripMenuItem_Click(object sender, EventArgs e)
    {
      try
      {
        //String filename = TextHelper.GetString("Info.NewFileName");
        //Int32 codepage = (Int32)PluginBase.MainForm.Settings.DefaultCodePage;
        //String extension = PluginBase.MainForm.Settings.DefaultFileExtension;
        //String file = Path.Combine(this.selectedPath.Text, filename) + "." + extension;
        //String unique = FileHelper.EnsureUniquePath(file);
        //FileHelper.WriteFile(unique, "", Encoding.GetEncoding(codepage), PluginBase.Settings.SaveUnicodeWithBOM);
        //this.autoSelectItem = Path.GetFileName(unique);
      }
      catch (Exception ex)
      {
        String exMsg = ex.Message.ToString();
        //ErrorManager.ShowError(ex);
      }
    }

    private void 新規フォルダーFToolStripMenuItem_Click(object sender, EventArgs e)
    {
      /*
      try
      {

        String folderName = TextHelper.GetString("Info.NewFolderName");
        String target = Path.Combine(this.selectedPath.Text, folderName);
        String unique = FolderHelper.EnsureUniquePath(target);
        Directory.CreateDirectory(unique);
        this.autoSelectItem = folderName;
      }
      catch (Exception ex)
      {
        ErrorManager.ShowError(ex);
      }
      */
    }

    private void 検索と置換FToolStripMenuItem_Click(object sender, EventArgs e)
    {
      //DataEvent de = new DataEvent(EventType.Command, "FileExplorer.FindHere", this.GetSelectedFiles());
      //EventManager.DispatchEvent(this, de);
    }

    private void 信頼するパスに追加ToolStripMenuItem_Click(object sender, EventArgs e)
    {
      /*
      String path;
      String trustFile;
      String trustParams;
      // add selected file
      if ((this.fileView.SelectedItems.Count != 0) && (this.fileView.SelectedIndices[0] > 0))
      {
        String file = this.fileView.SelectedItems[0].Tag.ToString();
        if (File.Exists(file)) file = Path.GetDirectoryName(file);
        if (!Directory.Exists(file)) return;
        DirectoryInfo info = new DirectoryInfo(file);
        path = info.FullName;
        trustFile = path.Replace('\\', '_').Remove(1, 1);
        while ((trustFile.Length > 100) && (trustFile.IndexOf('_') > 0)) trustFile = trustFile.Substring(trustFile.IndexOf('_'));
        trustParams = "FlashDevelop_" + trustFile + ".cfg;" + path;
      }
      // add current folder
      else
      {
        FileInfo info = new FileInfo(this.selectedPath.Text);
        path = info.FullName;
        trustFile = path.Replace('\\', '_').Remove(1, 1);
        while ((trustFile.Length > 100) && (trustFile.IndexOf('_') > 0)) trustFile = trustFile.Substring(trustFile.IndexOf('_'));
        trustParams = "FlashDevelop_" + trustFile + ".cfg;" + path;
      }
      // add to trusted files
      DataEvent deTrust = new DataEvent(EventType.Command, "ASCompletion.CreateTrustFile", trustParams);
      EventManager.DispatchEvent(this, deTrust);
      if (deTrust.Handled)
      {
        String message = TextHelper.GetString("Info.PathTrusted");
        ErrorManager.ShowInfo("\"" + path + "\"\n" + message);
      }
*/
    }

    private void コピーCToolStripMenuItem1_Click(object sender, EventArgs e)
    {
      /*
      StringCollection items = new StringCollection();
      for (Int32 i = 0; i < this.fileView.SelectedItems.Count; i++)
      {
        items.Add(fileView.SelectedItems[i].Tag.ToString());
      }
      Clipboard.SetFileDropList(items);
      */
    }

    private void 削除DToolStripMenuItem_Click(object sender, EventArgs e)
    {
      /*
      try
      {
        String message = TextHelper.GetString("Info.ConfirmDelete");
        String confirm = TextHelper.GetString("FlashDevelop.Title.ConfirmDialog");
        DialogResult result = MessageBox.Show(message, " " + confirm, MessageBoxButtons.YesNo, MessageBoxIcon.Question);
        if (result == DialogResult.Yes)
        {
          for (Int32 i = 0; i < this.fileView.SelectedItems.Count; i++)
          {
            String path = this.fileView.SelectedItems[i].Tag.ToString();
            if (!FileHelper.Recycle(path))
            {
              String error = TextHelper.GetString("FlashDevelop.Info.CouldNotBeRecycled");
              throw new Exception(error + " " + path);
            }
            DocumentManager.CloseDocuments(path);
          }
        }
      }
      catch (Exception ex)
      {
        ErrorManager.ShowError(ex);
      }
      */
    }

    private void 名前の変更MToolStripMenuItem_Click(object sender, EventArgs e)
    {
      this.selectedItems[0].BeginEdit();
    }

    private void 貼り付けPToolStripMenuItem1_Click(object sender, EventArgs e)
    {
      /*
      String target = String.Empty;
      if (this.fileView.SelectedItems.Count == 0) target = this.selectedPath.Text;
      else target = this.fileView.SelectedItems[0].Tag.ToString();
      StringCollection items = Clipboard.GetFileDropList();
      for (Int32 i = 0; i < items.Count; i++)
      {
        if (File.Exists(items[i]))
        {
          String copy = Path.Combine(target, Path.GetFileName(items[i]));
          String file = FileHelper.EnsureUniquePath(copy);
          File.Copy(items[i], file, false);
        }
        else
        {
          String folder = FolderHelper.EnsureUniquePath(target);
          FolderHelper.CopyFolder(items[i], folder);
        }
      }
      */
    }

    #endregion

    #region Icon Management

    /*
    
    
    /// <summary>
    /// Ask the shell to feed us the appropriate icon for the given file, but
    /// first try looking in our cache to see if we've already loaded it.
    /// </summary>
    private int ExtractIconIfNecessary(String path, bool isFile)
    {
      Icon icon; Image image; Size size;
      try
      {
        //size = ScaleHelper.Scale(new Size(16, 16));
        size = new Size(16, 16);
      }
      catch
      {
        size = new Size(16, 16);
      }
      if (PluginCore.Win32.ShouldUseWin32())
      {
        if (isFile) icon = IconExtractor.GetFileIcon(path, false, true);
        else icon = IconExtractor.GetFolderIcon(path, false, true);
        image = ImageKonverter.ImageResize(icon.ToBitmap(), size.Width, size.Height);
        try
        {
          image = PluginBase.MainForm.ImageSetAdjust(image);
        }
        catch { }
        icon.Dispose();
        this.imageList1.Images.Add(image);
        return this.imageList1.Images.Count - 1;
      }

      return isFile ? 0 : 1;
    }

    public Hashtable _systemIcons = new Hashtable();

    public int GetIconImageIndex(string path)
    {
      string extension = Path.GetExtension(path);

      if (_systemIcons.ContainsKey(extension) == false)
      {
        Icon icon = ShellIcon.GetSmallIcon(path);
        this.imageList1.Images.Add(icon);
        _systemIcons.Add(extension, this.imageList1.Images.Count - 1);
      }
      return (int)_systemIcons[Path.GetExtension(path)];
    }
    */
    
    
    
    #endregion







  }

  /// <summary>
  /// Summary description for ShellIcon.
  /// </summary>
  /// <summary>
  /// Summary description for ShellIcon.  Get a small or large Icon with an easy C# function call
  /// that returns a 32x32 or 16x16 System.Drawing.Icon depending on which function you call
  /// either GetSmallIcon(string fileName) or GetLargeIcon(string fileName)
  /// </summary>
  public class ShellIcon
  {
    [StructLayout(LayoutKind.Sequential)]
    public struct SHFILEINFO
    {
      public IntPtr hIcon;
      public IntPtr iIcon;
      public uint dwAttributes;
      [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 260)]
      public string szDisplayName;
      [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 80)]
      public string szTypeName;
    };

    class Win32
    {
      public const uint SHGFI_ICON = 0x100;
      public const uint SHGFI_LARGEICON = 0x0; // 'Large icon
      public const uint SHGFI_SMALLICON = 0x1; // 'Small icon
      [DllImport("shell32.dll")]
      public static extern IntPtr SHGetFileInfo(string pszPath, uint dwFileAttributes, ref SHFILEINFO psfi, uint cbSizeFileInfo, uint uFlags);
    }

    public ShellIcon()
    {
      //
      // Add constructor logic here
      //
    }

    public static Icon GetSmallIcon(string fileName)
    {
      IntPtr hImgSmall; //the handle to the system image list
      SHFILEINFO shinfo = new SHFILEINFO();
      //Use this to get the small Icon
      hImgSmall = Win32.SHGetFileInfo(fileName, 0, ref shinfo, (uint)Marshal.SizeOf(shinfo), Win32.SHGFI_ICON | Win32.SHGFI_SMALLICON);
      //The icon is returned in the hIcon member of the shinfo struct
      return System.Drawing.Icon.FromHandle(shinfo.hIcon);
    }

    public static Icon GetLargeIcon(string fileName)
    {
      IntPtr hImgLarge; //the handle to the system image list
      SHFILEINFO shinfo = new SHFILEINFO();
      //Use this to get the large Icon
      hImgLarge = Win32.SHGetFileInfo(fileName, 0, ref shinfo, (uint)Marshal.SizeOf(shinfo), Win32.SHGFI_ICON | Win32.SHGFI_LARGEICON);
      //The icon is returned in the hIcon member of the shinfo struct
      return System.Drawing.Icon.FromHandle(shinfo.hIcon);
    }
  }

  //http://stackoverflow.com/questions/11159767/how-to-convert-listview-to-datatable
  /*
    * http://chocoload.blog46.fc2.com/blog-entry-3.html
   // データセット作成
 DataSet dS = new DataSet("dS");

 // データテーブル作成
 DataTable dT = new DataTable("dT");
 // データテーブル カラム作成
 dT.Columns.Add("columns1", typeof(string));
 dT.Columns.Add("columns2", typeof(string));
 dT.Columns.Add("columns3", typeof(string));
 // データセット テーブル追加
 dS.Tables.Add(dT);

 // データロウ作成
 DataRow dR = dT.NewRow();
 // データロウ レコード作成
 dR["columns1"] = "row1";
 dR["columns2"] = "row2";
 dR["columns3"] = "row3";
 // データテーブル レコード追加
 dT.Rows.Add(dR);

 // データロウ作成 一行追加
 dR = dT.NewRow();
 dR["columns1"] = "row4";
 dR["columns2"] = "row5";
 dR["columns3"] = "row6";
 dT.Rows.Add(dR);

 // リストビュー データソース選択
 ListView1.DataSource = dS;
 // リストビュー データバインド
 ListView1.DataBind();

 起動画面。*/

}
