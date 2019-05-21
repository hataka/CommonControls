using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using XMLTreeMenu.Controls;

namespace PlayerPanel.Controls
{
  public class Player
  {

    public static XMLTreeMenu.Controls.PlayerPanel MaiPanel
    {
      get; set;
    }

    public Player()
    {
      InitializeComponent();
    }

    static void InitializeComponent()
    {
      MaiPanel.axWindowsMediaPlayer1.URL = @"C:\home\KingFM.asx";
    }

    public static void mediaPlayerToolStripMenuItem_Click(object sender, EventArgs e)
    {
      MaiPanel.axWindowsMediaPlayer1.Ctlcontrols.stop();
      Process.Start(MaiPanel.axWindowsMediaPlayer1.URL);
    }



  }
}
