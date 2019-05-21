using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using EPocalipse.Json.Viewer;
using System.IO;

namespace XMLTreeMenu.Controls
{
	public partial class JsonViewerPanel : UserControl
	{
		private string WindowTitle = "JsonViewerPanel";
		public JsonViewerPanel()
		{
			InitializeComponent();
			//this.StartPosition = FormStartPosition.CenterScreen;
			this.Text = WindowTitle;
      //Debug.WriteLine(String.Format("タイトル名 = [{0}]", this.Text));
      this.DragEnter += MainForm_DragEnter;
			this.DragDrop += MainForm_DragDrop;
		}

		public string GetWindowTitle()
		{
			return WindowTitle;
		}

		void MainForm_DragDrop(object sender, DragEventArgs e)
		{
			string[] fileNames =(string[])e.Data.GetData(DataFormats.FileDrop, false);
			if (fileNames.Length != 0)
			{
				this.jsonViewer1.SetFilePath(fileNames[0]);
				LoadFromFile(fileNames[0]);
			}
		}

		void updateTitle()
		{
			string buf = this.Text;
			if (buf.LastIndexOf("-") > 0)
			{
				buf = buf.Substring(buf.LastIndexOf("-") + 2);
			}
			string windowTitle = String.Format("{0} - {1}", this.jsonViewer1.GetFilePath(), buf);
			//this.Text = windowTitle;
			((Form)this.Parent).Text = Path.GetFileName(windowTitle);
			this.jsonViewer1.Tag = this.jsonViewer1.GetFilePath();
		}

		void MainForm_DragEnter(object sender, DragEventArgs e)
		{
			if (e.Data.GetDataPresent(DataFormats.FileDrop))
				e.Effect = DragDropEffects.Copy;
			else
				e.Effect = DragDropEffects.None;
		}

		//this.Shown += new System.EventHandler(this.MainForm_Shown);
		// Shown の定義なし
		private void MainForm_Shown(object sender, EventArgs e)
		{
			string[] args = Environment.GetCommandLineArgs();
			for (int i = 1; i < args.Length; i++)
			{
				string arg = args[i];
				if (arg.Equals("/c", StringComparison.OrdinalIgnoreCase))
				{
					LoadFromClipboard();
				}
				else if (File.Exists(arg))
				{
					this.jsonViewer1.SetFilePath(arg);
					LoadFromFile(arg);
				}
			}
		}

		private void LoadFromFile(string fileName)
		{
			updateTitle();
			string json = File.ReadAllText(fileName);
			//MessageBox.Show(json);
			this.jsonViewer1.ShowTab(Tabs.Text);
			this.jsonViewer1.Json = json;
		}

		private void LoadFromClipboard()
		{
			string json = Clipboard.GetText();
			if (!String.IsNullOrEmpty(json))
			{
				this.jsonViewer1.ShowTab(Tabs.Viewer);
				this.jsonViewer1.Json = json;
			}
		}

		private void MainForm_Load(object sender, EventArgs e)
		{
			this.jsonViewer1.ShowTab(Tabs.Text);
		}

		private void exitToolStripMenuItem_Click(object sender, EventArgs e)
		{
			Application.Exit();
		}

		private void openToolStripMenuItem_Click(object sender, EventArgs e)
		{
			OpenFileDialog dialog = new OpenFileDialog();
			dialog.Filter = "json files (*.json)|*.json|All files (*.*)|*.*";
			dialog.FilterIndex = 1;
			dialog.InitialDirectory = Application.StartupPath;
			dialog.Title = "Open file";
			if (dialog.ShowDialog() == DialogResult.OK)
			{
				this.jsonViewer1.SetFilePath(dialog.FileName);
				this.LoadFromFile(dialog.FileName);
			}
		}

		private void aboutJSONViewerToolStripMenuItem_Click(object sender, EventArgs e)
		{
			new AboutJsonViewer().ShowDialog();
		}

		private void selectAllToolStripMenuItem_Click(object sender, EventArgs e)
		{
			Control c;
			c = this.jsonViewer1.Controls.Find("txtJson", true)[0];
			((RichTextBox)c).SelectAll();
		}

		private void deleteToolStripMenuItem_Click(object sender, EventArgs e)
		{
			Control c;
			c = this.jsonViewer1.Controls.Find("txtJson", true)[0];
			string text;
			if (((RichTextBox)c).SelectionLength > 0)
				text = ((RichTextBox)c).SelectedText;
			else
				text = ((RichTextBox)c).Text;
			((RichTextBox)c).SelectedText = "";
		}

		private void pasteToolStripMenuItem_Click(object sender, EventArgs e)
		{
			Control c;
			c = this.jsonViewer1.Controls.Find("txtJson", true)[0];
			((RichTextBox)c).Paste();
		}

		private void copyToolStripMenuItem_Click(object sender, EventArgs e)
		{
			Control c;
			c = this.jsonViewer1.Controls.Find("txtJson", true)[0];
			((RichTextBox)c).Copy();
		}

		private void cutToolStripMenuItem_Click(object sender, EventArgs e)
		{
			Control c;
			c = this.jsonViewer1.Controls.Find("txtJson", true)[0];
			((RichTextBox)c).Cut();
		}

		private void undoToolStripMenuItem_Click(object sender, EventArgs e)
		{
			Control c;
			c = this.jsonViewer1.Controls.Find("txtJson", true)[0];
			((RichTextBox)c).Undo();
		}

		private void findToolStripMenuItem_Click(object sender, EventArgs e)
		{
			Control c;
			c = this.jsonViewer1.Controls.Find("pnlFind", true)[0];
			((Panel)c).Visible = true;
			Control t;
			t = this.jsonViewer1.Controls.Find("txtFind", true)[0];
			((TextBox)t).Focus();
		}

		private void expandAllToolStripMenuItem_Click(object sender, EventArgs e)
		{
			Control c;
			c = this.jsonViewer1.Controls.Find("tvJson", true)[0];
			((TreeView)c).BeginUpdate();
			try
			{
				if (((TreeView)c).SelectedNode != null)
				{
					TreeNode topNode = ((TreeView)c).TopNode;
					((TreeView)c).SelectedNode.ExpandAll();
					((TreeView)c).TopNode = topNode;
				}
			}
			finally
			{
				((TreeView)c).EndUpdate();
			}
		}

		private void copyToolStripMenuItem1_Click(object sender, EventArgs e)
		{
			Control c;
			c = this.jsonViewer1.Controls.Find("tvJson", true)[0];
			TreeNode node = ((TreeView)c).SelectedNode;
			if (node != null)
			{
				Clipboard.SetText(node.Text);
			}
		}

		private void copyValueToolStripMenuItem_Click(object sender, EventArgs e)
		{
			Control c;
			c = this.jsonViewer1.Controls.Find("tvJson", true)[0];
			JsonViewerTreeNode node = (JsonViewerTreeNode)((TreeView)c).SelectedNode;
			if (node != null && node.JsonObject.Value != null)
			{
				Clipboard.SetText(node.JsonObject.Value.ToString());
			}
		}

		private void saveToolStripMenuItem_Click(object sender, EventArgs e)
		{
			SaveFileDialog sfd = new SaveFileDialog();
			string filePath = this.jsonViewer1.GetFilePath();

			if (filePath.Length == 0)
			{
				sfd.FileName = "file.json";
				sfd.InitialDirectory = @"C:\";
				sfd.Filter =
					//   "Json(*.json)|*.json|All(*.*)|*.*";
						"All(*.*)|*.*";
				sfd.FilterIndex = 1;
				sfd.Title = "Save as";
				sfd.RestoreDirectory = true;
				sfd.OverwritePrompt = true;
				sfd.CheckPathExists = true;

				if (sfd.ShowDialog() == DialogResult.OK)
				{
					System.IO.StreamWriter sw = new System.IO.StreamWriter(sfd.FileName);
					sw.Write(this.jsonViewer1.txtJson.Text);
					this.jsonViewer1.Json = this.jsonViewer1.txtJson.Text;
					sw.Close();
				}
			}
			else
			{
				System.IO.StreamWriter sw = new System.IO.StreamWriter(filePath);
				sw.Write(this.jsonViewer1.txtJson.Text);
				this.jsonViewer1.Json = this.jsonViewer1.txtJson.Text;
				sw.Close();
			}
		}

		private void formatToolStripMenuItem_Click(object sender, EventArgs e)
		{
			this.jsonViewer1.FormatJsonExternal();
		}

		//this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.MainForm_Closing);
		// UserControl に FormClosing 定義なし　
		private void MainForm_Closing(object sender, FormClosingEventArgs e)
		{
			//Properties.Settings.Default.Save();
		}

		private void JsonViewer_Load(object sender, EventArgs e)
		{

		}
	
	}
}
