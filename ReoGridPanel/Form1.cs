using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
//using unvell.ReoGrid.Editor;

namespace ReoGridApplication
{
  public partial class Form1 : Form
  {
    CommonControl.ReoGridPanel reoGridEditor1;

    public Form1()
    {
      InitializeComponent();
      this.reoGridEditor1 = new CommonControl.ReoGridPanel();
      reoGridEditor1.Dock = DockStyle.Fill;
      this.Controls.Add(this.reoGridEditor1);
      this.ClientSize = new Size(1200, 800);
      this.StartPosition = FormStartPosition.CenterScreen;

    }
  }
}
