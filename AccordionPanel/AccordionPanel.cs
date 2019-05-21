using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CommonControl
{
  public partial class AccordionPanel : UserControl
  {
    public example.MainPanel accordion = new example.MainPanel();
    public AccordionPanel()
    {
      InitializeComponent();
      // できない
      //this.Controls.Add((Control)accordion);

    }
  }
}
