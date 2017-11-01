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
    public partial class Form1 : Form
    {
        public static publicClass chessbd;
        Pen p;
        Graphics board;
        Font f;
        SolidBrush b, w;
        //bool firstPaint = true;
        void paintBoard()
        {
            board.Clear(Color.Gray);
            for (int i = 30; i <= 590; i += 40)
            {
                board.DrawLine(p, i, 30, i, 590);
                board.DrawLine(p, 30, i, 590, i);
                board.DrawString(Convert.ToString((i - 15) / 40), f, b, i - 10, 2);
                board.DrawString(Convert.ToString((i - 15) / 40), f, b, 2, i - 10);
            }
            if (chessbd.order && (chessbd.steps == 0))
            {
                publicClass.gobangCoreG(ref chessbd.x, ref chessbd.y);
                //paintBoard();
                chessbd.steps++;
            }
            //textBox1.Text = Convert.ToString(chessbd.steps);
            for (int i = 0; i < 15; i++)
            {
                for (int j = 0; j < 15; j++) {
                    int k = publicClass.getChessboard(i, j);
                    if (k != 0)
                    {
                        Rectangle rect = new Rectangle(i * 40 + 20, j * 40 + 20, 20, 20);
                        board.FillEllipse(Convert.ToBoolean(k - 1) ? b : w, rect);
                        board.DrawEllipse(p, i * 40 + 20, j * 40 + 20, 20, 20);
                    }
                    else board.DrawString(Convert.ToString(publicClass.getValueboard(i, j)), f, b, i * 40 + 20, j * 40 + 20);
                }
            }
            Rectangle r = new Rectangle(chessbd.x * 40 + 25, chessbd.y * 40 + 25, 10, 10);
            board.FillRectangle((chessbd.steps%2 == 0) ? b : w, r);
        }
        public Form1()
        {
            InitializeComponent();
            chessbd = new publicClass();
            new confirmOrder().ShowDialog();
            publicClass.gobangInit(chessbd.order);
            p = new Pen(Color.Black, 2);
            board = CreateGraphics();
            f = new Font("宋体", 8);
            b = new SolidBrush(Color.Black);
            w = new SolidBrush(Color.White);
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            /*e.Graphics*/
            //board = e.Graphics;
            paintBoard();
            //if (firstPaint)
            //{
            //    firstPaint = false;
            //}
            //for (int i = 30; i <= 590; i += 40)
            //{
            //    board.DrawLine(p, i, 30, i, 590);
            //    board.DrawLine(p, 30, i, 590, i);
            //    board.DrawString(Convert.ToString((i - 15) / 40), f, b, i - 10, 2);
            //    board.DrawString(Convert.ToString((i - 15) / 40), f, b, 2, i - 10);
            //}
            //if (chessbd.order && (chessbd.steps == 0))
            //{
            //    publicClass.gobangCore(ref chessbd.x, ref chessbd.y);
            //    chessbd.oneStep(ref board);
            //}


        }

        private void backgroundWorker1_DoWork(object sender, DoWorkEventArgs e)
        {
            backgroundWorker1.RunWorkerAsync();
        }

        private void Form1_MouseClick(object sender, MouseEventArgs e)
        {
            Point formPoint = this.PointToClient(Control.MousePosition);
            if (formPoint.X >= 10 && formPoint.X <= 600 && formPoint.Y >= 10 && formPoint.Y <= 600)
            {
                chessbd.x = (formPoint.X - 10) / 40;
                chessbd.y = (formPoint.Y - 10) / 40;
                int tmp = publicClass.gobangCoreS(ref chessbd.x, ref chessbd.y);
                switch (tmp)
                {
                    case -1:
                        break;
                    case 0:
                        paintBoard();
                        chessbd.steps++;
                        break;
                    default:
                        paintBoard();
                        chessbd.steps++;
                        chessbd.win(!Convert.ToBoolean(tmp - 1));
                        InitializeComponent();
                        break;
                }
                if (tmp == 0)
                {
                    tmp = publicClass.gobangCoreG(ref chessbd.x, ref chessbd.y);
                    if (tmp != 0)
                    {
                        paintBoard();
                        chessbd.steps++;
                        chessbd.win(!Convert.ToBoolean(tmp - 1));
                        InitializeComponent();
                    }
                    else
                    {
                        paintBoard();
                        chessbd.steps++;
                    }
                }
                //Refresh();
            }
        }

        /*private void button1_Click(object sender, EventArgs e)
        {
            int x = 0, y = 0;
            x = Convert.ToInt32(textBox1.Text);
            y = Convert.ToInt32(textBox2.Text);
            if (x > 0 && x < 15 && y > 0 && y < 15)
            {
                chessbd.x = x; chessbd.y = y;
                int t = publicClass.gobangCore(ref chessbd.x, ref chessbd.y);
                label1.Text = Convert.ToString(t);
                board.DrawEllipse(p, chessbd.x*40+20, chessbd.y*40+20, 20, 20);
                t = publicClass.gobangCore(ref chessbd.x, ref chessbd.y);
                label1.Text = Convert.ToString(t);
                board.DrawEllipse(p, chessbd.x * 40 + 20, chessbd.y * 40 + 20, 20, 20);
                
            }
        }*/
    }
}
