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
    public partial class win : Form
    {
        bool order;
        public win(bool ord)
        {
            InitializeComponent();
            order = ord;
        }

        private void win_Load(object sender, EventArgs e)
        {
            if (order) label1.Text = "Computer win!";
            else label1.Text = "You win!";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Application.Exit();//////////
            this.Close();
        }
    }
}
