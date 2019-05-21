using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Reflection;

namespace CommonControl
{
  public partial class ReoGridPanel : UserControl
  {    
 
    #region Variables
    global::ReoGridPanel.Properties.Settings
        settings = new global::ReoGridPanel.Properties.Settings();
    //CommonLibrary.Settings commonsettings = new CommonLibrary.Settings();

    public List<string> previousDocuments = new List<string>();
    public List<string> favorateDocuments = new List<string>();
    public string filePath = String.Empty;
    #endregion

    #region Properties
    //public ParentFormClass MainForm { get; set; }
    //public ChildFormControlClass Instance { get; set; }
    public List<string> PreviousDocuments
    {
      get { return this.previousDocuments; }
      set { this.previousDocuments = value; }
    }
    public List<string> FavorateDocuments
    {
      get { return this.favorateDocuments; }
      set { this.favorateDocuments = value; }
    }
    #endregion

    public ReoGridPanel()
    {
      InitializeComponent();
    }

    public void InitializeInterface()
    {
      throw new NotImplementedException();
    }

    #region Event Handler
    private void reoGridControl1_Enter(object sender, EventArgs e)
    {

    }

    private void ReoGridPanel_Load(object sender, EventArgs e)
    {

    }

    private void ReoGridPanel_Enter(object sender, EventArgs e)
    {
      String path = String.Empty;
      try
      {
        this.filePath = this.AccessibleName;
        path = this.AccessibleName;
        this.reoGridControl1.Tag = path;
      }
      catch { }
      //ここでもだめ
      //ApplySetting();

      if (!String.IsNullOrEmpty(path) && File.Exists(path))
      {
        this.reoGridControl1.Load(path);
        this.toolStripStatusLabel1.Text = path;
      }
    }

    #endregion

    #region General Method

    public  void CallMainCommand(String name, String argStr)
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
