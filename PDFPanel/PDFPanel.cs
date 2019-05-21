using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace CommonControl
{
  public partial class PDFPanel : UserControl
  {
    public PDFPanel()
    {
      InitializeComponent();
    }

    private void axAcroPDF1_Enter(object sender, EventArgs e)
    {
      String path = String.Empty;
      try
      {
        //path = this.axAcroPDF1.Tag as string;
        path = this.AccessibleName;
        //MessageBox.Show(path);
      }
      catch { }
      if (!String.IsNullOrEmpty(path) && File.Exists(path))
      {
        this.axAcroPDF1.LoadFile(path);
      }
    }
  }
}
