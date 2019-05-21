using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Xml;
using AdvancedDataGridView;
using System.IO;

namespace CommonControl
{
  public partial class TreeGridViewPanel : UserControl
  {
    //private string samplePath = Application.StartupPath + @"\\sample.xml";
    private static string settingDataDir = Path.Combine(Path.GetDirectoryName(Application.ExecutablePath), "SettingData");
    private string samplePath = Path.Combine(settingDataDir, "sample.xml");

    public TreeGridViewPanel()
    {
      InitializeComponent();
      // 編集可能な場合
      this.treeGridView1.EditMode = DataGridViewEditMode.EditOnEnter;
      //this.imageList1.TransparentColor = System.Drawing.Color.Black;//.Transparent;
      //this.treeGridView1.ImageList = this.imageList1;
      //this.treeGridView1.ImageList = this.imageList2;
      DisplayTreeGridView(samplePath);
    }

    private void DisplayTreeGridView(string pathname)
    {
      try
      {
        // SECTION 1. Create a DOM Document and load the XML data into it.
        XmlDocument dom = new XmlDocument();
        dom.Load(pathname);

        // SECTION 2. Initialize the TreeView control.
        this.treeGridView1.Nodes.Clear();
        this.treeGridView1.Nodes.Add(new TreeNode(dom.DocumentElement.Name));
        TreeGridNode tNode = new TreeGridNode();

        // SECTION 3. Populate the TreeView with the DOM nodes.
        AddNode(dom.DocumentElement, null);

      }
      catch (XmlException xmlEx)
      {
        MessageBox.Show(xmlEx.Message);
      }
      catch (Exception ex)
      {
        MessageBox.Show(ex.Message);
      }
    }

    private TreeGridNode AddNode(XmlNode inXmlNode, TreeGridNode inTreeNode)
    {

      TreeGridNode node = new TreeGridNode();
      node.CreateCells(this.treeGridView1);
      node.ImageIndex = 3;
      if (inTreeNode == null)
      {
        this.treeGridView1.Nodes.Add(node);
      }
      else inTreeNode.Nodes.Add(node);
      node.Cells[0].Value = inXmlNode.Name;
      node.Cells[1].Value = inXmlNode.Value;
      //node.Cells[2].Value = sel;

      if (inXmlNode is XmlElement)
      {
        foreach (var att in inXmlNode.Attributes.Cast<XmlAttribute>().Where(a => !a.IsNamespaceDeclaration()))
        //foreach (var att in inXmlNode.Attributes)
        {
          TreeGridNode attnd = new TreeGridNode();
          attnd.CreateCells(this.treeGridView1);
          attnd.ImageIndex = 4;
          //if (inTreeNode != null) inTreeNode.Nodes.Add(attnd);
          if (node != null) node.Nodes.Add(attnd);
          else this.treeGridView1.Nodes.Add(attnd);
          attnd.Cells[0].Value = att.Name;
          attnd.Cells[1].Value = att.Value;
        }
        // Add children
        foreach (XmlNode xNode in inXmlNode.ChildNodes)
        {
          //var tNode = inTreeNode.Nodes[inTreeNode.Nodes.Add(new TreeNode(xNode.Name))];
          AddNode(xNode, node);
        }

      }
      else
      {
        // Not an element.  Character data, comment, etc.  Display all text.
        node.Cells[0].Value = inXmlNode.Name;
        node.Cells[1].Value = inXmlNode.Value;

      }
      //treeGridView1.NodeExpanded = true;
      return node;
    }


  }

  public static class XmlNodeExtensions
  {
    public static bool IsDefaultNamespaceDeclaration(this XmlAttribute attr)
    {
      if (attr == null)
        return false;
      if (attr.NamespaceURI != "http://www.w3.org/2000/xmlns/")
        return false;
      return attr.Name == "xmlns";
    }

    public static bool IsNamespaceDeclaration(this XmlAttribute attr)
    {
      if (attr == null)
        return false;
      if (attr.NamespaceURI != "http://www.w3.org/2000/xmlns/")
        return false;
      return attr.Name == "xmlns" || attr.Name.StartsWith("xmlns:");
    }
  }
}
