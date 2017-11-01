using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace gobangAI
{
    public partial class confirmOrder : Form
    {
        public confirmOrder()
        {
            InitializeComponent();
        }

        private void OKButton_Click(object sender, EventArgs e)
        {
            if (computerFirst.Checked) Form1.chessbd.order = true;
            if (youFirst.Checked) Form1.chessbd.order = false;
            this.Close();
        }
    }
}
