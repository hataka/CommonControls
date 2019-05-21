using System;
using System.Collections.Generic;
using System.Windows.Forms;
using System.Drawing;
using System.Drawing.Imaging;
using System.Net;
using System.Runtime.InteropServices;
using System.Text;
using System.Drawing.Printing;
namespace CommonLibrary
{
	public class WebHandler
	{
		//////////////////////////////////////////////////////////////////////////
		// Path Url ����֐�
		public static String Path2Url(String path)
		{
			return path.Replace("F:\\", "http://localhost/").Replace("\\", "/");
		}

		public static String Url2Path(String url)
		{
			return url.Replace("http://localhost", "F:").Replace("/", "\\");
		}

		public static Boolean IsWebSite(String path)
		{
			//URL���ۂ������ׂ�
			//http://dobon.net/vb/dotnet/string/regexismatch.html
			if (System.Text.RegularExpressions.Regex.IsMatch(
				path, @"^s?https?://[-_.!~*'()a-zA-Z0-9;/?:@&=+$,%#]+$"))
			{
				return true;
			}
			else return false;
		}

		//////////////////////////////////////////////////////////////////////////
		// Web Document ���� �����֐�
		/// <summary>
		/// id = fileurl �� filePath���擾����
		/// </summary>
		/// <param name="url"></param>
		/// <returns></returns>
		public static String GetPathByID(String url)
		{
			// create a hidden web browser, which will navigate to the page
			System.Windows.Forms.WebBrowser web = new System.Windows.Forms.WebBrowser();
			web.ScrollBarsEnabled = false; // we don't want scrollbars on our image
			web.ScriptErrorsSuppressed = true; // don't let any errors shine through
			web.Navigate(url); // let's load up that page!

			// wait until the page is fully loaded
			while (web.ReadyState != System.Windows.Forms.WebBrowserReadyState.Complete)
				System.Windows.Forms.Application.DoEvents();
			//System.Threading.Thread.Sleep(1500); // allow time for page scripts to update
			// the appearance of the page

			HtmlWindow currentWindow = web.Document.Window;
			String fileurl = "";
			if (web.Document.GetElementById("fileurl") != null)
			{
				fileurl = web.Document.GetElementById("fileurl").InnerText;
				fileurl = Url2Path(fileurl);
			}
			web.Dispose();
			return fileurl;
		}

		/// <summary>
		/// http://msdn.microsoft.com/en-us/library/system.windows.forms.htmlwindow.windowframeelement(VS.80).aspx
		/// The following code example compares the SRC attribute of frames in a FRAMESET 
		/// to the current location. 
		/// If they are different, the frames are reset to their original URLs.
		///
		/// http://social.msdn.microsoft.com/Forums/ja-JP/vsgeneralja/thread/41e23caf-05d6-4dff-b5a1-9b1ecb12b4ed/
		/// WebBrowser�R���g���[������t���[���𗘗p�����̃y�[�W��HTML�\�[�X�擾���@
		/// Frames�iHtmlWindowCollection�j�ɂ� Document �v���p�e�B�Ȃ�đ��݂��Ă��܂��񂪁B
		///			foreach (HtmlWindow window in webBrowser1.Document.Window) {
		///							Debug.WriteLine(window.Document.Title); 
		///			}
		/// �ł͂����ƂƂ�Ă܂��ˁB
		/// �Ƃ���ŁA��������ŏ������邱�Ƃ΂���l���Ă����̂� IPersistStreamInit �������܂������A
		/// �t�@�C���ɕۑ����邾���Ȃ� System.Runtime.InteropServices.ComTypes.IPersistFile ���g����
		/// �ȒP�Ɏ����ł��܂��B
		/// HtmlDocument �� DomDocument �� IPersistFile �ɃL���X�g���� Save ���\�b�h���g������
		/// </summary>
		/// <param name="browser"></param>
		public static void ResetFrames(WebBrowser browser)
		{
			if (!(browser.Document == null))
			{
				HtmlElement frameElement = null;
				HtmlWindow docWindow = browser.Document.Window;

				foreach (HtmlWindow frameWindow in docWindow.Frames)
				{
					frameElement = frameWindow.WindowFrameElement;
					String originalUrl = frameElement.GetAttribute("SRC");

					if (!originalUrl.Equals(frameWindow.Url.ToString()))
					{
						frameWindow.Navigate(new Uri(originalUrl));
					}
				}
			}
		}

		/// <summary>
		/// http://www.slotware.net/blog/2009/03/cwebbrowser.html
		/// WebBrowser�R���g���[����̃e�L�X�g���I������Ă��邩���Ȃ����𔻕ʂ���̂́A
		/// ������Ƃ�������ŁA�W����Document�v���p�e�B�����ł͂ł��܂���B
		/// �����mshtml.IHTMLDocument2�Ȃ���̂��g���K�v������܂��B
		/// ���̎��uMicrosoft.mshtml�v���Q�Ƃɒǉ�����̂�Y��Ȃ��ł��������B
		/// ���Ď��ۂɁA�I��͈͂̃e�L�X�g���擾����ɂ�
		/// mshtml.IHTMLDocument2 doc = (mshtml.IHTMLDocument2)this.webBrowser1.Document.DomDocument;
		/// �ŁADomDocument�I�u�W�F�N�g���擾���Ă���A
		/// mshtml.IHTMLTxtRange range = (mshtml.IHTMLTxtRange)doc.selection.createRange();
		/// string selection = range.text;
		/// </summary>
		/// <param name="browser"></param>
		/// <returns>�I��͈͂̕�����</returns>
		/*
    public static String GetSelection(WebBrowser browser)
		{
			mshtml.IHTMLDocument2 doc = (mshtml.IHTMLDocument2)browser.Document.DomDocument;
			mshtml.IHTMLTxtRange range = (mshtml.IHTMLTxtRange)doc.selection.createRange();
			string selection = range.text;
			return selection;
		}
     */ 
		
		/// <summary>
		/// Web�y�[�W��MHT�`���i.mht�t�@�C���j�ŕۑ�����
		/// http://www.atmarkit.co.jp/fdotnet/dotnettips/690createmht/createmht.html
		/// </summary>
		/// <param name="url">�ۑ�����y�[�W��URL</param>
		/// <param name="filepath">�ۑ���̃t�@�C���̃p�X��</param>
		/// <returns>true:���� false:���s</returns>
		/*
    public static bool CreateMHT(string url, string filepath)
		{
			CDO.MessageClass msg = new CDO.MessageClass();
			try
			{
				// CDO.CdoMHTMLFlags.cdoSuppressNone��
				// �y�[�W���ŎQ�Ƃ��Ă��邷�ׂẴ��\�[�X���_�E�����[�h
				msg.CreateMHTMLBody(
					url, // �ۑ�����y�[�W��URL
					CDO.CdoMHTMLFlags.cdoSuppressNone,
					"",  // �F�؂��K�v�ȏꍇ�̃��[�U�[��
					""); // ����уp�X���[�h
			}
			catch (Exception exc)
			{
				String s = exc.Message.ToString();
				//System.Console.WriteLine("�y�[�W�擾���s");
				MessageBox.Show(Lib.OutputError(s), "�y�[�W�擾���s");
				return false;
			}
			ADODB.Stream st = msg.GetStream();
			st.SaveToFile(
				filepath, // �ۑ���̃t�@�C���̃p�X��
				ADODB.SaveOptionsEnum.adSaveCreateOverWrite);
			st.Close();
			return true;
		}
    */
		/// <summary>
		/// http://social.msdn.microsoft.com/Forums/en-US/csharpgeneral/thread/ed830c39-563f-4c79-a023-28104179695e/
		/// 
		///		you can try this to save web pages:
		///		1. Add COM in Reference
		///				this is the Microsoft CDO for Windows Library (C:\WINDOWS\System32\cdosys.dll)
		///		2. code�F
		///			CDO.Message msg = new CDO.MessageClass();
		///			CDO.Configuration cfg = new CDO.ConfigurationClass();		
		///			msg.Configuration = cfg;
		///			msg.CreateMHTMLBody("http://www.google.com", CDO.CdoMHTMLFlags.cdoSuppressAll, "", "");
		///			msg.GetStream().SaveToFile("c:\\text.mht", ADODB.SaveOptionsEnum.adSaveCreateOverWrite);
		/// </summary>
		public static void SaveWebPageAsMHT()
		{
			//CDO.Message msg = new CDO.MessageClass();
			//CDO.Configuration cfg = new CDO.ConfigurationClass();
			//msg.Configuration = cfg;
			//msg.CreateMHTMLBody("http://www.google.com", CDO.CdoMHTMLFlags.cdoSuppressAll, "", "");
			//msg.GetStream().SaveToFile(@"F:\textgoogle.mht", ADODB.SaveOptionsEnum.adSaveCreateOverWrite);
		}		
		
		/// <summary>
		/// http://www.atmarkit.co.jp/bbs/phpBB/viewtopic.php?topic=43520&forum=7
		/// </summary>
		private static Bitmap bmp;  // ����C�x���g�ɓn���u���E�U�C���[�W
		public static  void PreviewPrintPage(WebBrowser browser)
		{
			System.Drawing.Printing.PrintDocument pd = new System.Drawing.Printing.PrintDocument();
			pd.PrintPage += new System.Drawing.Printing.PrintPageEventHandler(pd_PrintPage);
			pd.DefaultPageSettings.Landscape = true; // ������ 
			pd.DefaultPageSettings.PaperSize = new PaperSize("A4", 827, 1169);// �p���T�C�Y
			PrintPreviewDialog ppd = new PrintPreviewDialog();
			ppd.Document = pd;
			ppd.SetBounds(0, 0, 1024, 768); // �v���r���[��ʃT�C�Y 
			ppd.Document.DocumentName = "�T���v��";

			// �ǉ��J�n
			//Rectangle rect = this.RectangleToScreen(browser.Bounds);
			Rectangle rect = browser.RectangleToScreen(browser.Bounds);
			bmp = new Bitmap(rect.Width, rect.Height, PixelFormat.Format32bppArgb);
			Graphics g = Graphics.FromImage(bmp);
			g.CopyFromScreen(rect.X, rect.Y, 0, 0, rect.Size, CopyPixelOperation.SourceCopy);
			// �ǉ��I��

			//����v���r���[�_�C�A���O��\������ 
			ppd.ShowDialog();

		}
		private static void pd_PrintPage(object sender, System.Drawing.Printing.PrintPageEventArgs e)
		{
			e.Graphics.DrawImage(bmp, new Point(0, 0));
		}
	
		
		/// <summary>
		/// http://jeanne.wankuma.com/tips/csharp/dialog/print.html
		/// </summary>
		public static void PrintPage()
		{
			// PrintDialog �̐V�����C���X�^���X�𐶐����� (�f�U�C�i����ǉ����Ă���ꍇ�͕K�v�Ȃ�)
			PrintDialog printDialog1 = new PrintDialog();
			// PrinterSettings �̐V�����C���X�^���X�𐶐����� (�K�{)
			printDialog1.PrinterSettings = new System.Drawing.Printing.PrinterSettings();
			// �v�����^�����w�肷��
			//printDialog1.PrinterSettings.PrinterName = "PrinterName";
			// ����͈͂��u�y�[�W�w��v�ɂ���
			printDialog1.PrinterSettings.PrintRange = System.Drawing.Printing.PrintRange.SomePages;
			// ����͈͂Ŏw��\�ȍő�y�[�W����ݒ肷��
			printDialog1.PrinterSettings.MaximumPage = short.MaxValue;
			// ����͈͂Ŏw��\�ȍŏ��y�[�W����ݒ肷��
			printDialog1.PrinterSettings.MinimumPage = 1;
			// ����J�n�y�[�W��ݒ肷��
			printDialog1.PrinterSettings.FromPage = 1;
			// ����I���y�[�W��ݒ肷��
			printDialog1.PrinterSettings.ToPage = short.MaxValue;
			// [�t�@�C���֏o��] �`�F�b�N�{�b�N�X��L���ɂ��� (�����l true)
			//printDialog1.AllowPrintToFile = true;
			// [�t�@�C���֏o��] �`�F�b�N�{�b�N�X���I���ɂ��� (�����l false)
			printDialog1.PrintToFile = true;
			// ����͈͂̃y�[�W�w���L���ɂ��� (�����l false)
			printDialog1.AllowSelection = true;
			// ����͈͂̃y�[�W�w���L���ɂ��� (�����l false)
			printDialog1.AllowSomePages = true;
			// [���P�ʂň��] �`�F�b�N�{�b�N�X���I���ɂ��� (�����l true)
			//printDialog1.PrinterSettings.Collate = true;
			// ������ݒ肷��
			printDialog1.PrinterSettings.Copies = 8;
			// [�w���v] �{�^����\������ (�����l false)
			printDialog1.ShowHelp = true;
			// [�l�b�g���[�N] �{�^����\������ (�����l true)
			//printDialog1.ShowNetwork = true;
			// �_�C�A���O��\�����A�߂�l�� [OK] �̏ꍇ�͈���̏��������s����
			if (printDialog1.ShowDialog() == DialogResult.OK)
			{
				MessageBox.Show("�����ɁA����̏������������Ă�������");
				//this.currentWebBrowser().Print();
			}
			// �s�v�ɂȂ������_�Ŕj������ (�������� �I�u�W�F�N�g�̔j����ۏ؂��� ���Q��)
			printDialog1.Dispose();
		}
		
		/// <summary>
		/// A method to capture a webpage as a System.Drawing.Bitmap
		/// </summary>
		/// <param name="URL">The URL of the webpage to capture</param>
		/// <returns>A System.Drawing.Bitmap of the entire page</returns>
		public static System.Drawing.Bitmap CaptureWebPage(string URL)
		{
			// create a hidden web browser, which will navigate to the page
			System.Windows.Forms.WebBrowser web = new System.Windows.Forms.WebBrowser();
			web.ScrollBarsEnabled = false; // we don't want scrollbars on our image
			web.ScriptErrorsSuppressed = true; // don't let any errors shine through
			web.Navigate(URL); // let's load up that page!

			// wait until the page is fully loaded
			while (web.ReadyState != System.Windows.Forms.WebBrowserReadyState.Complete)
				System.Windows.Forms.Application.DoEvents();
			System.Threading.Thread.Sleep(1500); // allow time for page scripts to update
			// the appearance of the page

			// set the size of our web browser to be the same size as the page
			int width = web.Document.Body.ScrollRectangle.Width;
			int height = web.Document.Body.ScrollRectangle.Height;
			web.Width = width;
			web.Height = height;
			// a bitmap that we will draw to
			System.Drawing.Bitmap bmp = new System.Drawing.Bitmap(width, height);
			// draw the web browser to the bitmap
			web.DrawToBitmap(bmp, new System.Drawing.Rectangle(0, 0, width, height));
			return bmp; // return the bitmap for processing
		}


		////////////////////////////////////////////////////////////////////////////////////////////////
		// TODO: �R�[�h���� 
		//[C#]
		System.Net.WebClient downloadClient = null;
		//Button1��Click�C�x���g�n���h��
		private void Button1_Click(object sender, EventArgs e)
		{
			//Button1.Enabled = false;
			//Button2.Enabled = true;

			//�_�E�����[�h�����t�@�C���̕ۑ���
			string fileName = "C:\\test.gif";
			//�_�E�����[�h���URL
			Uri u = new Uri("http://localhost/image.gif");

			//WebClient�̍쐬
			if (downloadClient == null)
			{
				downloadClient = new System.Net.WebClient();
				//�C�x���g�n���h���̍쐬
				downloadClient.DownloadProgressChanged +=
						new System.Net.DownloadProgressChangedEventHandler(
								downloadClient_DownloadProgressChanged);
				downloadClient.DownloadFileCompleted +=
						new System.ComponentModel.AsyncCompletedEventHandler(
								downloadClient_DownloadFileCompleted);
			}
			//�񓯊��_�E�����[�h���J�n����
			downloadClient.DownloadFileAsync(u, fileName);
		}

		//Button2��Click�C�x���g�n���h��
		private void Button2_Click(object sender, EventArgs e)
		{
			//�񓯊��_�E�����[�h���L�����Z������
			if (downloadClient != null)
				downloadClient.CancelAsync();
		}

		private void downloadClient_DownloadProgressChanged(object sender,
			System.Net.DownloadProgressChangedEventArgs e)
		{
			Console.WriteLine("{0}% ({1}byte �� {2}byte) �_�E�����[�h���I�����܂����B",
					e.ProgressPercentage, e.TotalBytesToReceive, e.BytesReceived);
		}

		private void downloadClient_DownloadFileCompleted(object sender,
			System.ComponentModel.AsyncCompletedEventArgs e)
		{
			if (e.Error != null)
				Console.WriteLine("�G���[:{0}", e.Error.Message);
			else if (e.Cancelled)
				Console.WriteLine("�L�����Z������܂����B");
			else
				Console.WriteLine("�_�E�����[�h���������܂����B");

			//Button1.Enabled = true;
			//Button2.Enabled = false;
		}
		////////////////////////////////////////////////////////////////////////////////////////////////

		
		public static List<String> ExtractUrlFromText(String text)
		{
			List<String> url = new List<string>();
			//Regex�I�u�W�F�N�g���쐬
			System.Text.RegularExpressions.Regex r =
				new System.Text.RegularExpressions.Regex(
					@"https?://[-_.!~*'()a-zA-Z0-9;/?:@&=+$,%#]+$",
					System.Text.RegularExpressions.RegexOptions.IgnoreCase
					| System.Text.RegularExpressions.RegexOptions.Multiline
					);
			//TextBox1.Text���Ő��K�\���ƈ�v����Ώۂ�1����
			System.Text.RegularExpressions.Match m = r.Match(text);
			//���̂悤�Ɉ�v����Ώۂ����ׂČ������邱�Ƃ��ł���
			//System.Text.RegularExpressions.MatchCollection mc = r.Matches(TextBox1.Text);
			while (m.Success)
			{
				//��v�����Ώۂ����������Ƃ��L���v�`�����������������\��
				//Console.WriteLine(m.Value);
				url.Add(m.Value);
				//���Ɉ�v����Ώۂ�����
				m = m.NextMatch();
			}
			return url;
		}

		// http://www.atmarkit.co.jp/fdotnet/dotnettips/039inifile/inifile.html
		[DllImport("KERNEL32.DLL")]
		public static extern uint
			GetPrivateProfileString(string lpAppName,
			string lpKeyName, string lpDefault,
			StringBuilder lpReturnedString, uint nSize,
			string lpFileName);
		/*
		[DllImport("KERNEL32.DLL",EntryPoint="GetPrivateProfileStringA")]
		public static extern uint 
			GetPrivateProfileStringByByteArray(string lpAppName, 
			string lpKeyName, string lpDefault, 
			byte [] lpReturnedString, uint nSize, 
			string lpFileName);

		[DllImport("KERNEL32.DLL")]
		public static extern uint 
			GetPrivateProfileInt( string lpAppName, 
			string lpKeyName, int nDefault, string lpFileName );

		[DllImport("KERNEL32.DLL")]
			public static extern uint WritePrivateProfileString(
			string lpAppName,
			string lpKeyName,
			string lpString,
			string lpFileName);
		*/
		// http://uchukamen.com/Programming/iniFile/#SEC5
		//uint entryLength;
		//string strEntryStringValue;
		//System.Text.StringBuilder strEntryString = new System.Text.StringBuilder( 256 );
		//entryLength = GetPrivateProfileString( "SECTION", "ENTRY", "Nothing", strEntryString, (uint)(strEntryString.Capacity), "C:\\TEMP\\TEST.ini" );
		//strEntryStringValue = strEntryString.ToString();
		// ���̗�ł́AC:\TEMP\Test.ini 
		// �t�@�C���̃Z�N�V������ "SECTION" �ɁA�L�[�l�[��"ENTRY" �ɒl "Hello" ���ݒ肳��܂��B
		//[DEFAULT]
		//BASEURL=http://msdn.microsoft.com/en-us/library/ms533049.aspx
		//[InternetShortcut]
		//URL=http://msdn.microsoft.com/en-us/library/ms533049.aspx
		/// <summary>
		/// 
		/// </summary>
		/// <param name="path"></param>
		/// <returns></returns>
		public static String GetUrlFromInternetShortcut(String path)
		{
			uint entryLength;
			string strEntryStringValue;

			System.Text.StringBuilder strEntryString = new System.Text.StringBuilder(256);
			entryLength = GetPrivateProfileString(
				"InternetShortcut", "URL", "Nothing", strEntryString,
				(uint)(strEntryString.Capacity), path);
			strEntryStringValue = strEntryString.ToString();
			return strEntryStringValue;
		}

		public static String WebClientGet3(String url)
		{
			WebClient wc = new WebClient();
			//byte[] data = wc.DownloadData("http://www.google.co.jp/");
			byte[] data = wc.DownloadData(url);
			Encoding enc = Encoding.GetEncoding("Shift_JIS");
			string html = enc.GetString(data);
			//Console.WriteLine(html);
			return html;
		}

		public static String WebClientGet3(String url, String encoding)
		{
			WebClient wc = new WebClient();
			//byte[] data = wc.DownloadData("http://www.google.co.jp/");
			byte[] data = wc.DownloadData(url);
			Encoding enc = Encoding.GetEncoding(encoding);
			string html = enc.GetString(data);
			//Console.WriteLine(html);
			return html;
		}


	
		
		public static String StripTags(String html)
		{
			//[C#]
			// commentsAndPhpTags = /<!--[\s\S]*?-->|<\?(?:php)?[\s\S]*?\?>/gi;
			//URL�Ƀ����N��t����
			html = System.Text.RegularExpressions.Regex.Replace(
					html, @"<!--[\s\S]*?-->", "");
			return System.Text.RegularExpressions.Regex.Replace(
					html, @"<\/?([a-z][a-z0-9]*)\b[^>]*>", "");
		}
		
		/// <summary>
		/// http://dobon.net/vb/dotnet/internet/analyzeurl.html
		/// 
		/// </summary>
		/// <param name="link"></param>
		/// <param name="url"></param>
		/// <returns></returns>
		public static String AbsoluteURLFromLink(String url, String link)
		{
			Uri uri = new Uri(new Uri(url), link);
			if (link == String.Empty || url == String.Empty) return "";
			//���URI��\������
			return uri.AbsoluteUri; //public string AbsoluteUri
		}

		/// <summary>
		/// ��΃p�X 
		/// string url = "http://user:pass@www.dobon.net:80/vb/bbs.cgi?id=a%20b&n=1#top";
		/// ����: /vb/bbs.cgi
		/// </summary>
		/// <param name="url"></param>
		/// <returns></returns>
		public static String AbsolutePath(String fullurl)
		{
			Uri uri = new Uri(fullurl);
			return uri.AbsolutePath; 
		}
		/// <summary>
		/// ���[�J���z�X�g���Q�Ƃ��邩�ǂ���
		/// </summary>
		/// <param name="url"></param>
		/// <returns></returns>
		public static Boolean IsLocalhost(String url)
		{
			Uri uri = new Uri(url);
			return uri.IsLoopback; 
		}

		/// <summary>
		/// ��΃C���X�^���X�ł��邩�ǂ���
		/// </summary>
		/// <param name="url"></param>
		/// <returns></returns>
		public static Boolean IsAbsoluteUri(String url)
		{
			Uri uri = new Uri(url);
			return uri.IsAbsoluteUri;
		}


	}
}
//http://rucio.cloudapp.net/ThreadDetail.aspx?ThreadId=10188
/*
[C#]
//��͂���URL�i����URL�͎��݂��܂���j
string url = "http://user:pass@www.dobon.net:80/vb/bbs.cgi?id=a%20b&n=1#top";

//���URI
Console.WriteLine(u.AbsoluteUri);
//����: http://user:pass@www.dobon.net/vb/bbs.cgi?id=a%20b&n=1#top

//�T�[�o�[��DNS(Domain Name System)�z�X�g���܂���IP�A�h���X�ƁA�|�[�g�ԍ�
Console.WriteLine(u.Authority);
//����: www.dobon.net

//DNS�̉����Ɉ��S�Ɏg�p�ł���G�X�P�[�v�������ꂽ�z�X�g��
Console.WriteLine(u.DnsSafeHost);
//����: www.dobon.net

//�G�X�P�[�v�t���O�����g
Console.WriteLine(u.Fragment);
//����: #top

//�T�[�o�[��DNS�z�X�g���܂���IP�A�h���X
Console.WriteLine(u.Host);
//����: www.dobon.net

//�z�X�g���̌^
switch (u.HostNameType)
{
    case UriHostNameType.Basic:
        Console.WriteLine(
            "�z�X�g�͐ݒ肳��܂������A�^������ł��܂���B");
        break;
    case UriHostNameType.Dns:
        Console.WriteLine(
            "�z�X�g���́A�h���C�����V�X�e���`���̃z�X�g���ł��B");
        break;
    case UriHostNameType.IPv4:
        Console.WriteLine(
            "�z�X�g���́AIP Version 4 �`���̃z�X�g�A�h���X�ł��B");
        break;
    case UriHostNameType.IPv6:
        Console.WriteLine(
            "�z�X�g���́AIP Version 6 �`���̃z�X�g �A�h���X�ł��B");
        break;
    case UriHostNameType.Unknown:
        Console.WriteLine("�z�X�g���̌^���w�肳��Ă��܂���B");
        break;
}
//����: �z�X�g���́A�h���C�����V�X�e���`���̃z�X�g���ł��B

//��΃C���X�^���X�ł��邩�ǂ���
Console.WriteLine(u.IsAbsoluteUri);
//����: True

//�|�[�g�l�����̃X�L�[���̊���̃|�[�g�l���ǂ���
Console.WriteLine(u.IsDefaultPort);
//����: True

//�t�@�C��URI���ǂ���
Console.WriteLine(u.IsFile);
//����: False

//���[�J���z�X�g���Q�Ƃ��邩�ǂ���
Console.WriteLine(u.IsLoopback);
//����: False

//UNC�p�X���ǂ���
Console.WriteLine(u.IsUnc);
//����: False

//Uri�R���X�g���N�^�ɓn���ꂽ����URI������
Console.WriteLine(u.OriginalString);
//����: http://user:pass@www.dobon.net:80/vb/bbs.cgi?id=a%20b&n=1#top

//���[�J���I�y���[�e�B���O�V�X�e���ł̃t�@�C�����\��
Console.WriteLine(u.LocalPath);
//����: /vb/bbs.cgi

//AbsolutePath�v���p�e�B��Query�v���p�e�B���^�╄(?)�ŋ�؂����`��
Console.WriteLine(u.PathAndQuery);
//����: /vb/bbs.cgi?id=a%20b&n=1

//�|�[�g�ԍ�
Console.WriteLine(u.Port);
//����: 80

//�N�G�����
Console.WriteLine(u.Query);
//����: ?id=a%20b&n=1

//�X�L�[����
Console.WriteLine(u.Scheme);
//����: http

//�Z�O�����g
foreach (string s in u.Segments)
    Console.WriteLine("\t" + s);
//����: 
//    /
//    vb/
//    bbs.cgi

//Uri�C���X�^���X�̍쐬�O�ɁAURI�����񂪃G�X�P�[�v����Ă��邩
Console.WriteLine(u.UserEscaped);
//����: False

//���[�U�[���A�p�X���[�h�Ȃǂ̃��[�U�[�ŗL�̏��
Console.WriteLine(u.UserInfo);
//����: user:pass

//���[����X�L�[���܂�
Console.WriteLine(u.GetLeftPart(UriPartial.Scheme));
//����: http://

//���[���猠���܂�
Console.WriteLine(u.GetLeftPart(UriPartial.Authority));
//����: http://user:pass@www.dobon.net

//���[����p�X�܂�
Console.WriteLine(u.GetLeftPart(UriPartial.Path));
//����: http://user:pass@www.dobon.net/vb/bbs.cgi

//���[����N�G���܂�
Console.WriteLine(u.GetLeftPart(UriPartial.Query));
//����: http://user:pass@www.dobon.net/vb/bbs.cgi?id=a%20b&n=1

//�G�X�P�[�v�������ꂽ���K�`����URI 
Console.WriteLine(u.ToString());
//����: http://user:pass@www.dobon.net/vb/bbs.cgi?id=a b&n=1#top
*/