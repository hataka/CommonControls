//using MDIForm.CommonLibrary;
using MDIForm.CommonLibrary;
using System;
using System.ComponentModel;
using System.Diagnostics;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Net;
using System.Reflection;
using System.Text;
using System.Windows.Forms;

namespace PlayerPanel.Controls
{
	public class Browser : UserControl
	{

    #region Form Variables
    public ToolStrip toolStrip;
		private ToolStripButton goButton;
		private ToolStripButton backButton;
		private ToolStripButton forwardButton;
		private ToolStripButton refreshButton;
		//private ToolStripSpringComboBox addressComboBox;
		private ToolStripDropDownButton toolStripDropDownButton1;
		private ToolStripMenuItem iEで開くToolStripMenuItem;
		private ToolStripMenuItem chromeで開くToolStripMenuItem;
		private ToolStripMenuItem fireFoxで開くToolStripMenuItem;
		private ToolStripSeparator toolStripSeparator2;
		private ToolStripMenuItem linkPathToolStripMenuItem;
		private ToolStripMenuItem サクラエディタSToolStripMenuItem;
		private ToolStripMenuItem pSPadPToolStripMenuItem;
		private ToolStripMenuItem エクスプローラEToolStripMenuItem;
		private ToolStripMenuItem コマンドプロンプトCToolStripMenuItem;
		private ToolStripSeparator toolStripSeparator3;
		private ToolStripMenuItem scintillaCToolStripMenuItem;
		private ToolStripMenuItem richTextBoxToolStripMenuItem;
		private ToolStripMenuItem ソースの表示VToolStripMenuItem;
		private ToolStripMenuItem codeの表示DToolStripMenuItem;
		private ToolStripSeparator toolStripSeparator4;
		private ToolStripMenuItem ファイル名を指定して実行OToolStripMenuItem;
		private ToolStripMenuItem リンクを開くLToolStripMenuItem;
    public  WebBrowser webBrowser;
    private ToolStripMenuItem 保存SToolStripMenuItem;
		private ToolStripSeparator toolStripSeparator1;
		private ToolStripMenuItem mhtで保存ToolStripMenuItem;
		private ToolStripMenuItem htmlで保存ToolStripMenuItem;
		private ToolStripMenuItem textで保存ToolStripMenuItem;
		private ToolStripMenuItem jpegで保存ToolStripMenuItem;
		private ToolStripMenuItem 印刷ToolStripMenuItem;
		private ToolStripSeparator toolStripSeparator5;
		private ToolStripMenuItem 印刷プレビューVToolStripMenuItem;
		private ToolStripSeparator toolStripSeparator6;
		private ToolStripMenuItem ファイルエクスプローラを同期するXToolStripMenuItem;
		private ToolStripSeparator toolStripSeparator7;
		private ToolStripButton searchButton;
		private ToolStripButton GoHomeButton;
		private ToolStripButton printButton;
		private ToolStripButton stopButton;
		private ToolStripMenuItem お気に入りToolStripMenuItem;
		private ToolStripMenuItem 履歴ToolStripMenuItem;
		private ToolStripSeparator toolStripSeparator8;
		private ToolStripMenuItem googleToolStripMenuItem;
		private ToolStripMenuItem デスクトップにショートカットを作成ToolStripMenuItem;
		private ToolStripMenuItem お気に入りに追加ToolStripMenuItem;
		private ToolStripSeparator toolStripSeparator9;
		private ToolStripMenuItem お気に入りのクリアToolStripMenuItem;
		private ToolStripMenuItem 履歴をクリアToolStripMenuItem;
    #endregion

    #region Variables
    //public XMLTreeMenu.PluginMain xmlTreeMenu;
    //private XMLTreeMenu.Settings settings;

    public CommonControl.PlayerPanel playerPanel;
  
    public string linkFilePath = string.Empty;
    private string documentRoot = string.Empty;
		private string serverRoot = string.Empty;

    public const string SETTING_DOCUMENTROOT = "";
    public const string SETTING_SERVERROOT = "";
    public const string SETTING_CHROMEPATH = "";
    public const string SETTING_FIREFOXPATH = "";
    public const string SETTING_SAKURAPATH = "";
    public const string SETTING_PSPADPATH = "";
    #endregion

    #region Properties
    public WebBrowser WebBrowser
		{
			get
			{
				return this.webBrowser;
			}
		}

    //public ToolStripComboBox AddressBox
    /*
    public ToolStripSpringComboBox AdreddressBox
		{
			get
			{
				return this.addressComboBox;
			}
		}
    */
    #endregion

    #region Constructors
    public Browser()
		{
			//this.Font = PluginBase.MainForm.Settings.DefaultFont;
			this.InitializeComponent();
			this.InitializeLocalization();
			this.InitializeInterface();
      this.InitializeBrowser();
    }

    public Browser(CommonControl.PlayerPanel panel)
    {
      this.playerPanel = panel;
      //this.Font = PluginBase.MainForm.Settings.DefaultFont;
      this.InitializeComponent();
      this.InitializeLocalization();
      this.InitializeInterface();
      this.InitializeBrowser();
    }


    #endregion

    #region Initializations
    private void InitializeComponent()
		{
      System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Browser));
      this.toolStrip = new System.Windows.Forms.ToolStrip();
      this.backButton = new System.Windows.Forms.ToolStripButton();
      this.forwardButton = new System.Windows.Forms.ToolStripButton();
      this.stopButton = new System.Windows.Forms.ToolStripButton();
      this.refreshButton = new System.Windows.Forms.ToolStripButton();
      this.toolStripSeparator7 = new System.Windows.Forms.ToolStripSeparator();
      this.toolStripDropDownButton1 = new System.Windows.Forms.ToolStripDropDownButton();
      this.iEで開くToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.chromeで開くToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.fireFoxで開くToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
      this.お気に入りToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.googleToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.toolStripSeparator9 = new System.Windows.Forms.ToolStripSeparator();
      this.お気に入りに追加ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.お気に入りのクリアToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.履歴ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.履歴をクリアToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.toolStripSeparator8 = new System.Windows.Forms.ToolStripSeparator();
      this.保存SToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.デスクトップにショートカットを作成ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.mhtで保存ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.htmlで保存ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.textで保存ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.jpegで保存ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.toolStripSeparator5 = new System.Windows.Forms.ToolStripSeparator();
      this.印刷ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.印刷プレビューVToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
      this.linkPathToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.サクラエディタSToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.pSPadPToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.エクスプローラEToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.コマンドプロンプトCToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
      this.scintillaCToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.richTextBoxToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.toolStripSeparator6 = new System.Windows.Forms.ToolStripSeparator();
      this.ファイルエクスプローラを同期するXToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.ソースの表示VToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.codeの表示DToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.toolStripSeparator4 = new System.Windows.Forms.ToolStripSeparator();
      this.ファイル名を指定して実行OToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.リンクを開くLToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.searchButton = new System.Windows.Forms.ToolStripButton();
      this.GoHomeButton = new System.Windows.Forms.ToolStripButton();
      this.printButton = new System.Windows.Forms.ToolStripButton();
      this.goButton = new System.Windows.Forms.ToolStripButton();
      this.webBrowser = new System.Windows.Forms.WebBrowser();
      this.toolStrip.SuspendLayout();
      this.SuspendLayout();
      // 
      // toolStrip
      // 
      this.toolStrip.CanOverflow = false;
      this.toolStrip.GripStyle = System.Windows.Forms.ToolStripGripStyle.Hidden;
      this.toolStrip.ImageScalingSize = new System.Drawing.Size(20, 20);
      this.toolStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.backButton,
            this.forwardButton,
            this.stopButton,
            this.refreshButton,
            this.toolStripSeparator7,
            this.toolStripDropDownButton1,
            this.searchButton,
            this.GoHomeButton,
            this.printButton,
            this.goButton});
      this.toolStrip.Location = new System.Drawing.Point(0, 0);
      this.toolStrip.Name = "toolStrip";
      this.toolStrip.Padding = new System.Windows.Forms.Padding(2, 1, 2, 2);
      this.toolStrip.Size = new System.Drawing.Size(972, 30);
      this.toolStrip.TabIndex = 3;
      // 
      // backButton
      // 
      this.backButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
      this.backButton.Enabled = false;
      this.backButton.Image = ((System.Drawing.Image)(resources.GetObject("backButton.Image")));
      this.backButton.ImageTransparentColor = System.Drawing.Color.Magenta;
      this.backButton.Margin = new System.Windows.Forms.Padding(0, 1, 0, 1);
      this.backButton.Name = "backButton";
      this.backButton.Size = new System.Drawing.Size(24, 25);
      this.backButton.Text = "Back";
      this.backButton.Click += new System.EventHandler(this.BackButtonClick);
      // 
      // forwardButton
      // 
      this.forwardButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
      this.forwardButton.Enabled = false;
      this.forwardButton.Image = ((System.Drawing.Image)(resources.GetObject("forwardButton.Image")));
      this.forwardButton.ImageTransparentColor = System.Drawing.Color.Magenta;
      this.forwardButton.Margin = new System.Windows.Forms.Padding(0, 1, 0, 1);
      this.forwardButton.Name = "forwardButton";
      this.forwardButton.Size = new System.Drawing.Size(24, 25);
      this.forwardButton.Text = "Forward";
      this.forwardButton.Click += new System.EventHandler(this.ForwardButtonClick);
      // 
      // stopButton
      // 
      this.stopButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
      this.stopButton.Image = ((System.Drawing.Image)(resources.GetObject("stopButton.Image")));
      this.stopButton.ImageTransparentColor = System.Drawing.Color.Magenta;
      this.stopButton.Name = "stopButton";
      this.stopButton.Size = new System.Drawing.Size(24, 24);
      this.stopButton.Text = "StopButton";
      this.stopButton.Click += new System.EventHandler(this.stopButton_Click);
      // 
      // refreshButton
      // 
      this.refreshButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
      this.refreshButton.Image = ((System.Drawing.Image)(resources.GetObject("refreshButton.Image")));
      this.refreshButton.ImageTransparentColor = System.Drawing.Color.Magenta;
      this.refreshButton.Margin = new System.Windows.Forms.Padding(0, 1, 1, 1);
      this.refreshButton.Name = "refreshButton";
      this.refreshButton.Size = new System.Drawing.Size(24, 25);
      this.refreshButton.Text = "Refresh";
      this.refreshButton.Click += new System.EventHandler(this.RefreshButtonClick);
      // 
      // toolStripSeparator7
      // 
      this.toolStripSeparator7.Name = "toolStripSeparator7";
      this.toolStripSeparator7.Size = new System.Drawing.Size(6, 27);
      // 
      // toolStripDropDownButton1
      // 
      this.toolStripDropDownButton1.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
      this.toolStripDropDownButton1.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.iEで開くToolStripMenuItem,
            this.chromeで開くToolStripMenuItem,
            this.fireFoxで開くToolStripMenuItem,
            this.toolStripSeparator2,
            this.お気に入りToolStripMenuItem,
            this.履歴ToolStripMenuItem,
            this.toolStripSeparator8,
            this.保存SToolStripMenuItem,
            this.toolStripSeparator5,
            this.印刷ToolStripMenuItem,
            this.印刷プレビューVToolStripMenuItem,
            this.toolStripSeparator1,
            this.linkPathToolStripMenuItem,
            this.ソースの表示VToolStripMenuItem,
            this.codeの表示DToolStripMenuItem,
            this.toolStripSeparator4,
            this.ファイル名を指定して実行OToolStripMenuItem,
            this.リンクを開くLToolStripMenuItem});
      this.toolStripDropDownButton1.Image = ((System.Drawing.Image)(resources.GetObject("toolStripDropDownButton1.Image")));
      this.toolStripDropDownButton1.ImageTransparentColor = System.Drawing.Color.Magenta;
      this.toolStripDropDownButton1.Name = "toolStripDropDownButton1";
      this.toolStripDropDownButton1.Size = new System.Drawing.Size(34, 24);
      this.toolStripDropDownButton1.Text = "toolStripDropDownButton1";
      // 
      // iEで開くToolStripMenuItem
      // 
      this.iEで開くToolStripMenuItem.Name = "iEで開くToolStripMenuItem";
      this.iEで開くToolStripMenuItem.Size = new System.Drawing.Size(260, 26);
      this.iEで開くToolStripMenuItem.Text = "IEで開く";
      this.iEで開くToolStripMenuItem.Click += new System.EventHandler(this.iEで開くToolStripMenuItem_Click);
      // 
      // chromeで開くToolStripMenuItem
      // 
      this.chromeで開くToolStripMenuItem.Name = "chromeで開くToolStripMenuItem";
      this.chromeで開くToolStripMenuItem.Size = new System.Drawing.Size(260, 26);
      this.chromeで開くToolStripMenuItem.Text = "Chromeで開く";
      this.chromeで開くToolStripMenuItem.Click += new System.EventHandler(this.chromeで開くToolStripMenuItem_Click);
      // 
      // fireFoxで開くToolStripMenuItem
      // 
      this.fireFoxで開くToolStripMenuItem.Name = "fireFoxで開くToolStripMenuItem";
      this.fireFoxで開くToolStripMenuItem.Size = new System.Drawing.Size(260, 26);
      this.fireFoxで開くToolStripMenuItem.Text = "FireFoxで開く";
      this.fireFoxで開くToolStripMenuItem.Click += new System.EventHandler(this.fireFoxで開くToolStripMenuItem_Click);
      // 
      // toolStripSeparator2
      // 
      this.toolStripSeparator2.Name = "toolStripSeparator2";
      this.toolStripSeparator2.Size = new System.Drawing.Size(257, 6);
      // 
      // お気に入りToolStripMenuItem
      // 
      this.お気に入りToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.googleToolStripMenuItem,
            this.toolStripSeparator9,
            this.お気に入りに追加ToolStripMenuItem,
            this.お気に入りのクリアToolStripMenuItem});
      this.お気に入りToolStripMenuItem.Name = "お気に入りToolStripMenuItem";
      this.お気に入りToolStripMenuItem.Size = new System.Drawing.Size(260, 26);
      this.お気に入りToolStripMenuItem.Text = "お気に入り";
      // 
      // googleToolStripMenuItem
      // 
      this.googleToolStripMenuItem.Name = "googleToolStripMenuItem";
      this.googleToolStripMenuItem.Size = new System.Drawing.Size(189, 26);
      this.googleToolStripMenuItem.Tag = "http://www.google.co.jp";
      this.googleToolStripMenuItem.Text = "Google";
      this.googleToolStripMenuItem.Click += new System.EventHandler(this.favoriteMenuItem_Click);
      // 
      // toolStripSeparator9
      // 
      this.toolStripSeparator9.Name = "toolStripSeparator9";
      this.toolStripSeparator9.Size = new System.Drawing.Size(186, 6);
      // 
      // お気に入りに追加ToolStripMenuItem
      // 
      this.お気に入りに追加ToolStripMenuItem.Name = "お気に入りに追加ToolStripMenuItem";
      this.お気に入りに追加ToolStripMenuItem.Size = new System.Drawing.Size(189, 26);
      this.お気に入りに追加ToolStripMenuItem.Text = "お気に入りに追加";
      this.お気に入りに追加ToolStripMenuItem.Click += new System.EventHandler(this.お気に入りに追加ToolStripMenuItem_Click);
      // 
      // お気に入りのクリアToolStripMenuItem
      // 
      this.お気に入りのクリアToolStripMenuItem.Name = "お気に入りのクリアToolStripMenuItem";
      this.お気に入りのクリアToolStripMenuItem.Size = new System.Drawing.Size(189, 26);
      this.お気に入りのクリアToolStripMenuItem.Text = "お気に入りのクリア";
      this.お気に入りのクリアToolStripMenuItem.Click += new System.EventHandler(this.お気に入りのクリアToolStripMenuItem_Click);
      // 
      // 履歴ToolStripMenuItem
      // 
      this.履歴ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.履歴をクリアToolStripMenuItem});
      this.履歴ToolStripMenuItem.Name = "履歴ToolStripMenuItem";
      this.履歴ToolStripMenuItem.Size = new System.Drawing.Size(260, 26);
      this.履歴ToolStripMenuItem.Text = "履歴";
      // 
      // 履歴をクリアToolStripMenuItem
      // 
      this.履歴をクリアToolStripMenuItem.Name = "履歴をクリアToolStripMenuItem";
      this.履歴をクリアToolStripMenuItem.Size = new System.Drawing.Size(155, 26);
      this.履歴をクリアToolStripMenuItem.Text = "履歴をクリア";
      this.履歴をクリアToolStripMenuItem.Click += new System.EventHandler(this.履歴をクリアToolStripMenuItem_Click);
      // 
      // toolStripSeparator8
      // 
      this.toolStripSeparator8.Name = "toolStripSeparator8";
      this.toolStripSeparator8.Size = new System.Drawing.Size(257, 6);
      // 
      // 保存SToolStripMenuItem
      // 
      this.保存SToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.デスクトップにショートカットを作成ToolStripMenuItem,
            this.mhtで保存ToolStripMenuItem,
            this.htmlで保存ToolStripMenuItem,
            this.textで保存ToolStripMenuItem,
            this.jpegで保存ToolStripMenuItem});
      this.保存SToolStripMenuItem.Name = "保存SToolStripMenuItem";
      this.保存SToolStripMenuItem.Size = new System.Drawing.Size(260, 26);
      this.保存SToolStripMenuItem.Text = "保存(&S)";
      // 
      // デスクトップにショートカットを作成ToolStripMenuItem
      // 
      this.デスクトップにショートカットを作成ToolStripMenuItem.Name = "デスクトップにショートカットを作成ToolStripMenuItem";
      this.デスクトップにショートカットを作成ToolStripMenuItem.Size = new System.Drawing.Size(275, 26);
      this.デスクトップにショートカットを作成ToolStripMenuItem.Text = "デスクトップにショートカットを作成";
      this.デスクトップにショートカットを作成ToolStripMenuItem.Click += new System.EventHandler(this.デスクトップにショートカットを作成ToolStripMenuItem_Click);
      // 
      // mhtで保存ToolStripMenuItem
      // 
      this.mhtで保存ToolStripMenuItem.Enabled = false;
      this.mhtで保存ToolStripMenuItem.Name = "mhtで保存ToolStripMenuItem";
      this.mhtで保存ToolStripMenuItem.Size = new System.Drawing.Size(275, 26);
      this.mhtで保存ToolStripMenuItem.Text = "mhtで保存";
      // 
      // htmlで保存ToolStripMenuItem
      // 
      this.htmlで保存ToolStripMenuItem.Name = "htmlで保存ToolStripMenuItem";
      this.htmlで保存ToolStripMenuItem.Size = new System.Drawing.Size(275, 26);
      this.htmlで保存ToolStripMenuItem.Text = "htmlで保存";
      this.htmlで保存ToolStripMenuItem.Click += new System.EventHandler(this.htmlで保存ToolStripMenuItem_Click);
      // 
      // textで保存ToolStripMenuItem
      // 
      this.textで保存ToolStripMenuItem.Name = "textで保存ToolStripMenuItem";
      this.textで保存ToolStripMenuItem.Size = new System.Drawing.Size(275, 26);
      this.textで保存ToolStripMenuItem.Text = "textで保存";
      this.textで保存ToolStripMenuItem.Click += new System.EventHandler(this.textで保存ToolStripMenuItem_Click);
      // 
      // jpegで保存ToolStripMenuItem
      // 
      this.jpegで保存ToolStripMenuItem.Name = "jpegで保存ToolStripMenuItem";
      this.jpegで保存ToolStripMenuItem.Size = new System.Drawing.Size(275, 26);
      this.jpegで保存ToolStripMenuItem.Text = "jpegで保存";
      this.jpegで保存ToolStripMenuItem.Click += new System.EventHandler(this.jpegで保存ToolStripMenuItem_Click);
      // 
      // toolStripSeparator5
      // 
      this.toolStripSeparator5.Name = "toolStripSeparator5";
      this.toolStripSeparator5.Size = new System.Drawing.Size(257, 6);
      // 
      // 印刷ToolStripMenuItem
      // 
      this.印刷ToolStripMenuItem.Name = "印刷ToolStripMenuItem";
      this.印刷ToolStripMenuItem.Size = new System.Drawing.Size(260, 26);
      this.印刷ToolStripMenuItem.Text = "印刷(&P)";
      this.印刷ToolStripMenuItem.Click += new System.EventHandler(this.印刷ToolStripMenuItem_Click);
      // 
      // 印刷プレビューVToolStripMenuItem
      // 
      this.印刷プレビューVToolStripMenuItem.Name = "印刷プレビューVToolStripMenuItem";
      this.印刷プレビューVToolStripMenuItem.Size = new System.Drawing.Size(260, 26);
      this.印刷プレビューVToolStripMenuItem.Text = "印刷プレビュー(&V)";
      this.印刷プレビューVToolStripMenuItem.Click += new System.EventHandler(this.印刷プレビューVToolStripMenuItem_Click);
      // 
      // toolStripSeparator1
      // 
      this.toolStripSeparator1.Name = "toolStripSeparator1";
      this.toolStripSeparator1.Size = new System.Drawing.Size(257, 6);
      // 
      // linkPathToolStripMenuItem
      // 
      this.linkPathToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.サクラエディタSToolStripMenuItem,
            this.pSPadPToolStripMenuItem,
            this.エクスプローラEToolStripMenuItem,
            this.コマンドプロンプトCToolStripMenuItem,
            this.toolStripSeparator3,
            this.scintillaCToolStripMenuItem,
            this.richTextBoxToolStripMenuItem,
            this.toolStripSeparator6,
            this.ファイルエクスプローラを同期するXToolStripMenuItem});
      this.linkPathToolStripMenuItem.Name = "linkPathToolStripMenuItem";
      this.linkPathToolStripMenuItem.Size = new System.Drawing.Size(260, 26);
      this.linkPathToolStripMenuItem.Text = "LinkPath";
      // 
      // サクラエディタSToolStripMenuItem
      // 
      this.サクラエディタSToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("サクラエディタSToolStripMenuItem.Image")));
      this.サクラエディタSToolStripMenuItem.Name = "サクラエディタSToolStripMenuItem";
      this.サクラエディタSToolStripMenuItem.Size = new System.Drawing.Size(291, 26);
      this.サクラエディタSToolStripMenuItem.Text = "サクラエディタ(&S)";
      this.サクラエディタSToolStripMenuItem.Click += new System.EventHandler(this.サクラエディタSToolStripMenuItem_Click);
      // 
      // pSPadPToolStripMenuItem
      // 
      this.pSPadPToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("pSPadPToolStripMenuItem.Image")));
      this.pSPadPToolStripMenuItem.Name = "pSPadPToolStripMenuItem";
      this.pSPadPToolStripMenuItem.Size = new System.Drawing.Size(291, 26);
      this.pSPadPToolStripMenuItem.Text = "PSPad(&P)";
      this.pSPadPToolStripMenuItem.Click += new System.EventHandler(this.pSPadPToolStripMenuItem_Click);
      // 
      // エクスプローラEToolStripMenuItem
      // 
      this.エクスプローラEToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("エクスプローラEToolStripMenuItem.Image")));
      this.エクスプローラEToolStripMenuItem.Name = "エクスプローラEToolStripMenuItem";
      this.エクスプローラEToolStripMenuItem.Size = new System.Drawing.Size(291, 26);
      this.エクスプローラEToolStripMenuItem.Text = "エクスプローラ(&E)";
      this.エクスプローラEToolStripMenuItem.Click += new System.EventHandler(this.エクスプローラEToolStripMenuItem_Click);
      // 
      // コマンドプロンプトCToolStripMenuItem
      // 
      this.コマンドプロンプトCToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("コマンドプロンプトCToolStripMenuItem.Image")));
      this.コマンドプロンプトCToolStripMenuItem.Name = "コマンドプロンプトCToolStripMenuItem";
      this.コマンドプロンプトCToolStripMenuItem.Size = new System.Drawing.Size(291, 26);
      this.コマンドプロンプトCToolStripMenuItem.Text = "コマンド・プロンプト(&C)";
      this.コマンドプロンプトCToolStripMenuItem.Click += new System.EventHandler(this.コマンドプロンプトCToolStripMenuItem_Click);
      // 
      // toolStripSeparator3
      // 
      this.toolStripSeparator3.Name = "toolStripSeparator3";
      this.toolStripSeparator3.Size = new System.Drawing.Size(288, 6);
      // 
      // scintillaCToolStripMenuItem
      // 
      this.scintillaCToolStripMenuItem.Name = "scintillaCToolStripMenuItem";
      this.scintillaCToolStripMenuItem.Size = new System.Drawing.Size(291, 26);
      this.scintillaCToolStripMenuItem.Text = "Scintilla(&A)";
      this.scintillaCToolStripMenuItem.Click += new System.EventHandler(this.scintillaCToolStripMenuItem_Click);
      // 
      // richTextBoxToolStripMenuItem
      // 
      this.richTextBoxToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("richTextBoxToolStripMenuItem.Image")));
      this.richTextBoxToolStripMenuItem.Name = "richTextBoxToolStripMenuItem";
      this.richTextBoxToolStripMenuItem.Size = new System.Drawing.Size(291, 26);
      this.richTextBoxToolStripMenuItem.Text = "RichTextEditor(&R)";
      // 
      // toolStripSeparator6
      // 
      this.toolStripSeparator6.Name = "toolStripSeparator6";
      this.toolStripSeparator6.Size = new System.Drawing.Size(288, 6);
      // 
      // ファイルエクスプローラを同期するXToolStripMenuItem
      // 
      this.ファイルエクスプローラを同期するXToolStripMenuItem.Name = "ファイルエクスプローラを同期するXToolStripMenuItem";
      this.ファイルエクスプローラを同期するXToolStripMenuItem.Size = new System.Drawing.Size(291, 26);
      this.ファイルエクスプローラを同期するXToolStripMenuItem.Text = "ファイルエクスプローラを同期する(&X)";
      this.ファイルエクスプローラを同期するXToolStripMenuItem.Click += new System.EventHandler(this.ファイルエクスプローラを同期するXToolStripMenuItem_Click);
      // 
      // ソースの表示VToolStripMenuItem
      // 
      this.ソースの表示VToolStripMenuItem.Name = "ソースの表示VToolStripMenuItem";
      this.ソースの表示VToolStripMenuItem.Size = new System.Drawing.Size(260, 26);
      this.ソースの表示VToolStripMenuItem.Text = "ソースの表示(&V)";
      this.ソースの表示VToolStripMenuItem.Click += new System.EventHandler(this.ソースの表示VToolStripMenuItem_Click);
      // 
      // codeの表示DToolStripMenuItem
      // 
      this.codeの表示DToolStripMenuItem.Name = "codeの表示DToolStripMenuItem";
      this.codeの表示DToolStripMenuItem.Size = new System.Drawing.Size(260, 26);
      this.codeの表示DToolStripMenuItem.Text = "Codeの表示(&D)";
      this.codeの表示DToolStripMenuItem.Click += new System.EventHandler(this.codeの表示DToolStripMenuItem_Click);
      // 
      // toolStripSeparator4
      // 
      this.toolStripSeparator4.Name = "toolStripSeparator4";
      this.toolStripSeparator4.Size = new System.Drawing.Size(257, 6);
      // 
      // ファイル名を指定して実行OToolStripMenuItem
      // 
      this.ファイル名を指定して実行OToolStripMenuItem.Name = "ファイル名を指定して実行OToolStripMenuItem";
      this.ファイル名を指定して実行OToolStripMenuItem.Size = new System.Drawing.Size(260, 26);
      this.ファイル名を指定して実行OToolStripMenuItem.Text = "ファイル名を指定して実行(&O)";
      this.ファイル名を指定して実行OToolStripMenuItem.Click += new System.EventHandler(this.ファイル名を指定して実行OToolStripMenuItem_Click);
      // 
      // リンクを開くLToolStripMenuItem
      // 
      this.リンクを開くLToolStripMenuItem.Name = "リンクを開くLToolStripMenuItem";
      this.リンクを開くLToolStripMenuItem.Size = new System.Drawing.Size(260, 26);
      this.リンクを開くLToolStripMenuItem.Text = "リンクを開く(&L)";
      this.リンクを開くLToolStripMenuItem.Click += new System.EventHandler(this.リンクを開くLToolStripMenuItem_Click);
      // 
      // searchButton
      // 
      this.searchButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
      this.searchButton.Image = ((System.Drawing.Image)(resources.GetObject("searchButton.Image")));
      this.searchButton.ImageTransparentColor = System.Drawing.Color.Magenta;
      this.searchButton.Name = "searchButton";
      this.searchButton.Size = new System.Drawing.Size(24, 24);
      this.searchButton.Text = "GoogleSearch";
      this.searchButton.Click += new System.EventHandler(this.searchButton_Click);
      // 
      // GoHomeButton
      // 
      this.GoHomeButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
      this.GoHomeButton.Image = ((System.Drawing.Image)(resources.GetObject("GoHomeButton.Image")));
      this.GoHomeButton.ImageTransparentColor = System.Drawing.Color.Magenta;
      this.GoHomeButton.Name = "GoHomeButton";
      this.GoHomeButton.Size = new System.Drawing.Size(24, 24);
      this.GoHomeButton.Text = "GoHome";
      this.GoHomeButton.Click += new System.EventHandler(this.GoHomeButton_Click);
      // 
      // printButton
      // 
      this.printButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
      this.printButton.Image = ((System.Drawing.Image)(resources.GetObject("printButton.Image")));
      this.printButton.ImageTransparentColor = System.Drawing.Color.Magenta;
      this.printButton.Name = "printButton";
      this.printButton.Size = new System.Drawing.Size(24, 24);
      this.printButton.Text = "print";
      this.printButton.Click += new System.EventHandler(this.printButton_Click);
      // 
      // goButton
      // 
      this.goButton.Alignment = System.Windows.Forms.ToolStripItemAlignment.Right;
      this.goButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
      this.goButton.Image = ((System.Drawing.Image)(resources.GetObject("goButton.Image")));
      this.goButton.ImageTransparentColor = System.Drawing.Color.Magenta;
      this.goButton.Margin = new System.Windows.Forms.Padding(0, 1, 0, 1);
      this.goButton.Name = "goButton";
      this.goButton.Size = new System.Drawing.Size(24, 25);
      this.goButton.Text = "Go";
      this.goButton.Click += new System.EventHandler(this.BrowseButtonClick);
      // 
      // webBrowser
      // 
      this.webBrowser.Dock = System.Windows.Forms.DockStyle.Fill;
      this.webBrowser.Location = new System.Drawing.Point(0, 30);
      this.webBrowser.Name = "webBrowser";
      this.webBrowser.ScriptErrorsSuppressed = true;
      this.webBrowser.Size = new System.Drawing.Size(972, 467);
      this.webBrowser.TabIndex = 2;
      this.webBrowser.Tag = "http://www.google.co.jp";
      this.webBrowser.WebBrowserShortcutsEnabled = false;
      this.webBrowser.CanGoBackChanged += new System.EventHandler(this.WebBrowserPropertyUpdated);
      this.webBrowser.CanGoForwardChanged += new System.EventHandler(this.WebBrowserPropertyUpdated);
      this.webBrowser.DocumentCompleted += new System.Windows.Forms.WebBrowserDocumentCompletedEventHandler(this.webBrowser_DocumentCompleted);
      this.webBrowser.DocumentTitleChanged += new System.EventHandler(this.WebBrowserDocumentTitleChanged);
      this.webBrowser.Navigated += new System.Windows.Forms.WebBrowserNavigatedEventHandler(this.WebBrowserNavigated);
      this.webBrowser.NewWindow += new System.ComponentModel.CancelEventHandler(this.WebBrowserNewWindow);
      // 
      // Browser
      // 
      this.Controls.Add(this.webBrowser);
      this.Controls.Add(this.toolStrip);
      this.Name = "Browser";
      this.Size = new System.Drawing.Size(972, 497);
      this.Tag = this.webBrowser;
      this.Load += new System.EventHandler(this.Browser_Load);
      this.toolStrip.ResumeLayout(false);
      this.toolStrip.PerformLayout();
      this.ResumeLayout(false);
      this.PerformLayout();

		}

		private void InitializeLocalization()
		{
      /*
      this.goButton.Text = TextHelper.GetString("Label.Go");
			this.backButton.Text = TextHelper.GetString("Label.Back");
			this.forwardButton.Text = TextHelper.GetString("Label.Forward");
			this.refreshButton.Text = TextHelper.GetString("Label.Refresh");
      */
    }

		private void InitializeInterface()
		{
			// 例外発生
      //this.toolStrip.Renderer = new DockPanelStripRenderer(true);
			//this.addressComboBox.FlatStyle = PluginBase.Settings.ComboBoxFlatStyle;
		}

    private void InitializeBrowser()
    {
      /*
      //this.GoHomeButton.Image = PluginBase.MainForm.FindImage("224");
      //this.printButton.Image = PluginBase.MainForm.FindImage("113");
      //this.stopButton.Image = PluginBase.MainForm.FindImage("153");
      string text = "0538077E-8C37-4A2B-962B-8FB77DC9F325";
      //this.xmlTreeMenu = (PluginMain)PluginBase.MainForm.FindPlugin(text);
      //this.settings = (XMLTreeMenu.Settings)this.xmlTreeMenu.Settings;
      this.documentRoot = "http://localhost";// this.settings.DocumentRoot;
      this.serverRoot = @"C:\Apache2.2\htdocs";// this.settings.ServerRoot;

      this.addressComboBox = new ToolStripSpringComboBox();
      this.addressComboBox.Name = "addressComboBox";
      this.addressComboBox.Padding = new Padding(0, 0, 1, 0);
      this.addressComboBox.Size = new Size(363, 23);
      //this.addressComboBox.SelectedIndexChanged += new EventHandler(this.AddressComboBoxSelectedIndexChanged);
      this.addressComboBox.KeyPress += new KeyPressEventHandler(this.AddressComboBoxKeyPress);
      this.toolStrip.Items.Add(this.addressComboBox);
      */
    }
    #endregion

    private void WebBrowserNewWindow(object sender, CancelEventArgs e)
		{
      //this.playerPanel.CallMainCommand("Browse", this.webBrowser.StatusText);

      /*
      if (PluginBase.MainForm.FindPlugin("0538077E-8C37-4A2B-962B-8FB77DC9F325") != null)
      {
        PluginBase.MainForm.CallCommand("PluginCommand", "XMLTreeMenu.BrowseEx;" + this.webBrowser.StatusText);
      }
      else
      {
        PluginBase.MainForm.CallCommand("Browse", "this.webBrowser.StatusText");
      }
      */
      //e.Cancel = true;
    }

		private void WebBrowserPropertyUpdated(object sender, EventArgs e)
		{
			this.backButton.Enabled = this.webBrowser.CanGoBack;
			this.forwardButton.Enabled = this.webBrowser.CanGoForward;
		}

		private void WebBrowserNavigated(object sender, WebBrowserNavigatedEventArgs e)
		{
			//this.addressComboBox.Text = this.webBrowser.Url.ToString();
			this.webBrowser.Tag = this.webBrowser.Url.ToString();
			//PluginBase.MainForm.StatusLabel.Text = this.webBrowser.Url.ToString();
			this.AddHistoryMenuItem(this.webBrowser.Url.ToString());
			//this.xmlTreeMenu.pluginUI.AddPreviousCustomDocuments(this.webBrowser.Url.ToString());
		}

		private void WebBrowserDocumentTitleChanged(object sender, EventArgs e)
		{
			if (this.webBrowser.DocumentTitle.Trim() == "")
			{
				string text = this.webBrowser.Document.Domain.Trim();
				if (!string.IsNullOrEmpty(text))
				{
					base.Parent.Text = text;
				}
				else
				{
					//base.Parent.Text = TextHelper.GetString("Info.UntitledFileStart");
				}
			}
			else
			{
				base.Parent.Text = this.webBrowser.DocumentTitle;
			}
			this.webBrowser.Tag = this.webBrowser.Url.ToString();
			//PluginBase.MainForm.StatusLabel.Text = this.webBrowser.Url.ToString();
		}

		private void AddressComboBoxSelectedIndexChanged(object sender, EventArgs e)
		{
      /*
      if (this.addressComboBox.SelectedItem != null)
			{
				string urlString = this.addressComboBox.SelectedItem.ToString();
				this.webBrowser.Navigate(urlString);
			}
		*/
    }

		private void BackButtonClick(object sender, EventArgs e)
		{
			this.webBrowser.GoBack();
		}

		private void ForwardButtonClick(object sender, EventArgs e)
		{
			this.webBrowser.GoForward();
		}

		private void RefreshButtonClick(object sender, EventArgs e)
		{
			this.webBrowser.Refresh();
		}

		private void BrowseButtonClick(object sender, EventArgs e)
		{
      /*
      string text = this.addressComboBox.Text;
			if (!this.addressComboBox.Items.Contains(text))
			{
				this.addressComboBox.Items.Insert(0, text);
			}
			this.webBrowser.Navigate(text);
		*/
    }

		private void AddressComboBoxKeyPress(object sender, KeyPressEventArgs e)
		{
      /*
      if (e.KeyChar == '\r')
			{
				string text = this.addressComboBox.Text;
				if (!this.addressComboBox.Items.Contains(text))
				{
					this.addressComboBox.Items.Insert(0, text);
				}
				this.webBrowser.Navigate(text);
			}
      */
    }

		public void AddHistoryMenuItem(string file)
		{
      /*
      try
			{
				if (((XMLTreeMenu.Settings)this.xmlTreeMenu.Settings).BrowserHistory.Contains(file))
				{
					((XMLTreeMenu.Settings)this.xmlTreeMenu.Settings).BrowserHistory.Remove(file);
				}
				((XMLTreeMenu.Settings)this.xmlTreeMenu.Settings).BrowserHistory.Insert(0, file);
				this.PopulateHistoryMenu();
			}
			catch (Exception ex)
			{
				MessageBox.Show(ex.Message.ToString());
			}
      */
    }

		public void PopulateHistoryMenu()
		{
      /*
      try
			{
				ToolStripMenuItem toolStripMenuItem = this.履歴ToolStripMenuItem;
				toolStripMenuItem.DropDownItems.Clear();
				for (int i = 0; i < ((XMLTreeMenu.Settings)this.xmlTreeMenu.Settings).BrowserHistory.Count; i++)
				{
					string text = ((XMLTreeMenu.Settings)this.xmlTreeMenu.Settings).BrowserHistory[i];
					ToolStripMenuItem toolStripMenuItem2 = new ToolStripMenuItem();
					toolStripMenuItem2.Click += new EventHandler(this.favoriteMenuItem_Click);
					toolStripMenuItem2.Tag = text;
					toolStripMenuItem2.Text = PathHelper.GetCompactPath(text);
					if (i < 15)
					{
						toolStripMenuItem.DropDownItems.Add(toolStripMenuItem2);
					}
					else
					{
						((XMLTreeMenu.Settings)this.xmlTreeMenu.Settings).BrowserHistory.Remove(text);
					}
				}
				if (((XMLTreeMenu.Settings)this.xmlTreeMenu.Settings).BrowserHistory.Count > 0)
				{
					TextHelper.GetString("Label.ClearReopenList");
					toolStripMenuItem.DropDownItems.Add(new ToolStripSeparator());
					toolStripMenuItem.DropDownItems.Add(this.履歴をクリアToolStripMenuItem);
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
      */
    }

		public void AddBookMarksMenuItem(string label, string url)
		{
      /*
      string item = label + "|" + url;
			try
			{
				if (((XMLTreeMenu.Settings)this.xmlTreeMenu.Settings).BrowserBookMarks.Contains(item))
				{
					((XMLTreeMenu.Settings)this.xmlTreeMenu.Settings).BrowserBookMarks.Remove(item);
				}
				((XMLTreeMenu.Settings)this.xmlTreeMenu.Settings).BrowserBookMarks.Insert(0, item);
				this.PopulateBookMarksMenu();
			}
			catch (Exception ex)
			{
				MessageBox.Show(ex.Message.ToString());
			}
      */
    }

		public void PopulateBookMarksMenu()
		{
      /*
      try
			{
				ToolStripMenuItem toolStripMenuItem = this.お気に入りToolStripMenuItem;
				toolStripMenuItem.DropDownItems.Clear();
				for (int i = 0; i < ((XMLTreeMenu.Settings)this.xmlTreeMenu.Settings).BrowserBookMarks.Count; i++)
				{
          string text = ((XMLTreeMenu.Settings)this.xmlTreeMenu.Settings).BrowserBookMarks[i];
					string[] array = text.Split(new char[]
					{
						'|'
					});
					string text2 = array[0];
					string tag = array[1];
					ToolStripMenuItem toolStripMenuItem2 = new ToolStripMenuItem();
					toolStripMenuItem2.Click += new EventHandler(this.favoriteMenuItem_Click);
					toolStripMenuItem2.Tag = tag;
					toolStripMenuItem2.Text = PathHelper.GetCompactPath(text2);
					if (i < 15)
					{
						toolStripMenuItem.DropDownItems.Add(toolStripMenuItem2);
					}
					else
					{
						((XMLTreeMenu.Settings)this.xmlTreeMenu.Settings).BrowserBookMarks.Remove(text);
					}
				}
				if (((XMLTreeMenu.Settings)this.xmlTreeMenu.Settings).BrowserBookMarks.Count > 0)
				{
					toolStripMenuItem.DropDownItems.Add(this.googleToolStripMenuItem);
					toolStripMenuItem.DropDownItems.Add(new ToolStripSeparator());
					toolStripMenuItem.DropDownItems.Add(this.お気に入りに追加ToolStripMenuItem);
					toolStripMenuItem.DropDownItems.Add(this.お気に入りのクリアToolStripMenuItem);
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
      */
    }

		private void Print()
		{
			this.WebBrowser.ShowPrintDialog();
		}

		private void PrintPreview()
		{
			this.webBrowser.ShowPrintPreviewDialog();
		}

		public bool SaveWebPage(string format)
		{
			string str = string.Empty;
			if (format != null)
			{
				if (format == ".mht")
				{
					str = "mhtファイル(*.mht)|*.mht";
					goto IL_6C;
				}
				if (format == ".html")
				{
					str = "htmlファイル(*.html)|*.html";
					goto IL_6C;
				}
				if (format == ".txt")
				{
					str = "textファイル(*.txt)|*.txt";
					goto IL_6C;
				}
				if (format == ".jpeg")
				{
					str = "jpegファイル(*.jpeg)|*.jpeg";
					goto IL_6C;
				}
			}
			str = "mhtファイル(*.mht)|*.mht";
      IL_6C:
      string filter = str + "|すべてのファイル(*.*)|*.*";
      string initialDirectory = @"F:\";// Path.Combine(PathHelper.BaseDir, "download");
			string fileName = "新しいファイル" + format;
			try
			{
				string text = Lib.File_SaveDialog(fileName, initialDirectory, filter);
				if (File.Exists(text))
				{
					DateTime now = DateTime.Now;
					string text2 = string.Format("_{0:00}{1:00}{2:00}{3:00}{4:00}{5:00}", new object[]
					{
						now.Year,
						now.Month,
						now.Day,
						now.Hour,
						now.Minute,
						now.Second
					});
					string.Concat(new string[]
					{
						Path.GetDirectoryName(text),
						"\\",
						Path.GetFileNameWithoutExtension(text),
						text2,
						Path.GetExtension(text)
					});
				}
				if (text != null)
				{
					if (format != null && !(format == ".mht"))
					{
						if (!(format == ".html"))
						{
							if (!(format == ".txt"))
							{
								if (format == ".jpeg")
								{
									Bitmap bitmap = WebHandler.CaptureWebPage(this.webBrowser.Url.ToString());
									bitmap.Save(text, ImageFormat.Jpeg);
									bitmap.Dispose();
								}
							}
							else
							{
								string encoding = this.webBrowser.Document.Encoding;
								string innerText = this.webBrowser.Document.Body.InnerText;
								StreamWriter streamWriter = new StreamWriter(text, false, Encoding.GetEncoding(encoding));
								streamWriter.Write(innerText);
								streamWriter.Close();
							}
						}
						else
						{
							string encoding2 = this.webBrowser.Document.Encoding;
							string value = WebHandler.WebClientGet3(this.webBrowser.Url.ToString(), encoding2);
							StreamWriter streamWriter2 = new StreamWriter(text, false, Encoding.GetEncoding(encoding2));
							streamWriter2.Write(value);
							streamWriter2.Close();
						}
					}
					MessageBox.Show(text + "\r\nに保存しました", "保存完了");
				}
			}
			catch (Exception ex)
			{
				string message = ex.Message.ToString();
				MessageBox.Show(Lib.OutputError(message), "保存失敗");
				return false;
			}
			return true;


		}

		private void iEで開くToolStripMenuItem_Click(object sender, EventArgs e)
		{
			Process.Start("C:\\Program Files\\Internet Explorer\\iexplore.exe", this.webBrowser.Url.ToString());
		}

		private void chromeで開くToolStripMenuItem_Click(object sender, EventArgs e)
		{
      //MessageBox.Show(this.settings.ChromePath);
      //Process.Start(@"C:\Program Files (x86)\Google\Chrome\Application\chrome.exe", this.webBrowser.Url.ToString());
      //Process.Start("C:\\Documents and Settings\\kazuhiko\\Local Settings\\Application Data\\Google\\Chrome\\Application\\chrome.exe", this.webBrowser.Url.ToString());
      Process.Start(@"C:\Program Files(x86)\Google\Chrome\Application\chrome.exe", this.webBrowser.Url.ToString());
    }

		private void fireFoxで開くToolStripMenuItem_Click(object sender, EventArgs e)
		{
      //Process.Start("C:\\Program Files\\Mozilla Firefox\\firefox.exe", this.webBrowser.Url.ToString());
      Process.Start(@"C:\Program Files\Mozilla Firefox\firefox.exe", this.webBrowser.Url.ToString());
    }

		private void サクラエディタSToolStripMenuItem_Click(object sender, EventArgs e)
		{
			if (File.Exists(this.linkFilePath))
			{
				//ProcessHandler.Run_Sakura(this.linkFilePath);
        Process.Start(@"C:\TiuDevTools\sakura\sakura.exe", this.linkFilePath);
      }
		}

		private void pSPadPToolStripMenuItem_Click(object sender, EventArgs e)
		{
			if (File.Exists(this.linkFilePath))
			{
				//ProcessHandler.Run_PSPad(this.linkFilePath);
        Process.Start(@"F:\Programs\PSPad editor\PSPad.exe", this.linkFilePath);
      }
		}

		private void エクスプローラEToolStripMenuItem_Click(object sender, EventArgs e)
		{
			if (File.Exists(this.linkFilePath))
			{
				ProcessHandler.Run_Explorer(this.linkFilePath);
			}
		}

		private void コマンドプロンプトCToolStripMenuItem_Click(object sender, EventArgs e)
		{
			if (File.Exists(this.linkFilePath))
			{
				ProcessHandler.Run_Cmd(this.linkFilePath);
			}
		}

		private void scintillaCToolStripMenuItem_Click(object sender, EventArgs e)
		{
			//PluginBase.MainForm.OpenEditableDocument(this.linkFilePath);
		}

		private void richTextBoxToolStripMenuItem_Click(object sender, EventArgs e)
		{
		}

		private void ファイルエクスプローラを同期するXToolStripMenuItem_Click(object sender, EventArgs e)
		{
			if (File.Exists(this.linkFilePath))
			{
				//PluginBase.MainForm.CallCommand("PluginCommand", "FileExplorer.BrowseTo;" + Path.GetDirectoryName(this.linkFilePath));
			}
		}

		private void ファイル名を指定して実行OToolStripMenuItem_Click(object sender, EventArgs e)
		{
		}

		private void リンクを開くLToolStripMenuItem_Click(object sender, EventArgs e)
		{
		}

		private void ソースの表示VToolStripMenuItem_Click(object sender, EventArgs e)
		{
			HtmlDocument document = this.webBrowser.Document;
			string encoding = document.Encoding;
			WebHandler.WebClientGet3(this.webBrowser.Url.ToString(), encoding);
		}

		private void codeの表示DToolStripMenuItem_Click(object sender, EventArgs e)
		{
			String url = this.webBrowser.Url.ToString();
    /*  
      if (File.Exists(Lib.Url2Path(this.webBrowser.Url.ToString())))
			{
				PluginBase.MainForm.OpenEditableDocument(Lib.Url2Path(this.webBrowser.Url.ToString()));
			}
		*/
      if (File.Exists(url.Replace(@"http://localhost", @"C:\Apache2.2\htdocs")))
			{
				//PluginBase.MainForm.OpenEditableDocument(url.Replace("http://localhost", @"C:\Apache2.2\htdocs"));
			}
    }

		private void webBrowser_DocumentCompleted(object sender, WebBrowserDocumentCompletedEventArgs e)
		{
			HtmlDocument document = this.webBrowser.Document;
			HtmlWindow window = document.Window;
			if (window.Frames.Count > 0)
			{
				if (window.Frames["MainPanel"].Document.GetElementById("fileurl").InnerText != string.Empty)
				{
          String fileurl = window.Frames["MainPanel"].Document.GetElementById("fileurl").InnerText;
          //this.linkFilePath = Lib.Url2Path(window.Frames["MainPanel"].Document.GetElementById("fileurl").InnerText);
          this.linkFilePath = fileurl.Replace("http://localhost", @"C:\Apache2.2\htdocs").Replace("/", "\\");
          return;
				}
			}
			else if (document.GetElementById("fileurl").InnerText != "")
			{
        string url = document.GetElementById("fileurl").InnerText;
        //this.linkFilePath = Lib.Url2Path(document.GetElementById("fileurl").InnerText);
        //this.linkFilePath = url.Replace("http://localhost", @"C:\Apache2.2\htdocs".Replace("/", "\\"));
      }
		}

		private void Browser_Load(object sender, EventArgs e)
		{
      string path = (string)this.webBrowser.Tag;
      //MessageBox.Show(path);
     //path = "http://www.google.co.jp";
      try
      {
        if (!string.IsNullOrEmpty(path) && File.Exists(path))
        {
          this.webBrowser.Navigate((string)this.webBrowser.Tag);
          ((Form)this.Parent).Text = Path.GetFileNameWithoutExtension(path);
        }
      }
      catch(Exception exc)
      {
        MessageBox.Show(Lib.OutputError(exc.Message.ToString()), MethodBase.GetCurrentMethod().Name);
      }
    }

    private void mhtで保存ToolStripMenuItem_Click(object sender, EventArgs e)
		{
		}

		private void htmlで保存ToolStripMenuItem_Click(object sender, EventArgs e)
		{
			this.SaveWebPage(".html");
		}

		private void textで保存ToolStripMenuItem_Click(object sender, EventArgs e)
		{
			this.SaveWebPage(".txt");
		}

		private void jpegで保存ToolStripMenuItem_Click(object sender, EventArgs e)
		{
			this.SaveWebPage(".jpeg");
		}

		private void 印刷ToolStripMenuItem_Click(object sender, EventArgs e)
		{
			this.Print();
		}

		private void 印刷プレビューVToolStripMenuItem_Click(object sender, EventArgs e)
		{
			this.PrintPreview();
		}

		private void searchButton_Click(object sender, EventArgs e)
		{
			this.webBrowser.Navigate("http://www.google.co.jp/");
		}

		private void GoHomeButton_Click(object sender, EventArgs e)
		{
			this.webBrowser.Navigate("http://localhost/pukiwiki2012/index.php");
		}

		private void printButton_Click(object sender, EventArgs e)
		{
			this.webBrowser.Print();
		}

		private void stopButton_Click(object sender, EventArgs e)
		{
			this.webBrowser.Stop();
		}

		private void favoriteMenuItem_Click(object sender, EventArgs e)
		{
			ToolStripMenuItem toolStripMenuItem = (ToolStripMenuItem)sender;
			string text = toolStripMenuItem.Tag as string;
			if (text != string.Empty)
			{
				//PluginBase.MainForm.CallCommand("PluginCommand", "XMLTreeMenu.BrowseEx;" + text);
			}
		}

		private void デスクトップにショートカットを作成ToolStripMenuItem_Click(object sender, EventArgs e)
		{
      /*
      string path = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.DesktopDirectory), PluginBase.MainForm.CurrentDocument.Text + ".url");
			string str = ((Control)PluginBase.MainForm.CurrentDocument.Controls[0].Tag).Tag.ToString();
			Encoding encoding = Encoding.GetEncoding("shift_jis");
			StreamWriter streamWriter = new StreamWriter(path, false, encoding);
			streamWriter.WriteLine("[InternetShortcut]");
			streamWriter.WriteLine("URL=" + str);
			streamWriter.Close();
		*/
      }

		private void お気に入りに追加ToolStripMenuItem_Click(object sender, EventArgs e)
		{
			//string url = ((Control)PluginBase.MainForm.CurrentDocument.Controls[0].Tag).Tag.ToString();
			//this.AddBookMarksMenuItem(PluginBase.MainForm.CurrentDocument.Text, url);
		}

		private void お気に入りのクリアToolStripMenuItem_Click(object sender, EventArgs e)
		{
      /*
      ((XMLTreeMenu.Settings)this.xmlTreeMenu.Settings).BrowserBookMarks.Clear();
			this.PopulateBookMarksMenu();
      */
    }

		private void 履歴をクリアToolStripMenuItem_Click(object sender, EventArgs e)
		{
      /*
      ((XMLTreeMenu.Settings)this.xmlTreeMenu.Settings).BrowserHistory.Clear();
			this.PopulateHistoryMenu();
      */
    }
   
    /*
		private Icon GetIconFromUrl(string url)
		{
			WebBrowser webBrowser = new WebBrowser();
			webBrowser.ScrollBarsEnabled = false;
			webBrowser.ScriptErrorsSuppressed = true;
			webBrowser.Navigate(url);
			while (webBrowser.ReadyState != WebBrowserReadyState.Complete)
			{
				Application.DoEvents();
			}
			Icon result = null;
			foreach (HtmlElement htmlElement in webBrowser.Document.GetElementsByTagName("link"))
			{
				string attribute = htmlElement.GetAttribute("rel");
				if (attribute == "shortcut icon" || attribute == "icon")
				{
					string attribute2 = htmlElement.GetAttribute("href");
					if (attribute2.StartsWith("http"))
					{
						result = this.getIconFromUrl(attribute2);
						break;
					}
					if (attribute2.StartsWith("/"))
					{
						result = this.getIconFromUrl("http://" + webBrowser.Url.Host + attribute2);
						break;
					}
					result = this.getIconFromUrl(webBrowser.Url.ToString() + attribute2);
					break;
				}
			}
			return result;
		}
    */

    private Icon getIconFromUrl(string url)
		{
			Icon result;
			using (WebClient webClient = new WebClient())
			{
				using (MemoryStream memoryStream = new MemoryStream(webClient.DownloadData(url)))
				{
					result = new Icon(memoryStream);
				}
			}
			return result;
		}
	}

  internal class WebBrowserEx : WebBrowser
  {
    /*
    public override bool PreProcessMessage(ref Message msg)
    {
      //return ((Form)PluginBase.MainForm).PreProcessMessage(ref msg);
    }
    */
  }




}
