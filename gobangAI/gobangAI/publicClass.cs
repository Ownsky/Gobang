using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;
using System.Drawing;

namespace gobangAI
{
    public class publicClass
    {
        public int x = 0, y = 0;
        public bool order = true;
        public int steps
        {
            get;
            set;
        } = 0;
        public void win(bool ord)
        {
            new win(ord).ShowDialog();
            gobangInit(order);
            new confirmOrder().ShowDialog();
            init();
        }
        void init()
        {
            x = 0;
            y = 0;
            steps = 0;
        }
        [DllImport("gobangCore.dll", CallingConvention = CallingConvention.Cdecl)]//, EntryPoint = "gobangInit"
        public static extern int gobangInit(bool order);

        [DllImport("gobangCore.dll", CallingConvention = CallingConvention.Cdecl)]//, EntryPoint = "gobangCore"
        public static extern int gobangCoreG(ref int x, ref int y);

        [DllImport("gobangCore.dll", CallingConvention = CallingConvention.Cdecl)]//, EntryPoint = "gobangCore"
        public static extern int gobangCoreS(ref int x, ref int y);

        [DllImport("gobangCore.dll", CallingConvention = CallingConvention.Cdecl)]//, EntryPoint = "gobangCore"
        public static extern int getChessboard(int x, int y);

        [DllImport("gobangCore.dll", CallingConvention = CallingConvention.Cdecl)]//, EntryPoint = "gobangCore"
        public static extern int  getValueboard(int x, int y);

        [DllImport("gobangCore.dll", CallingConvention = CallingConvention.Cdecl)]//, EntryPoint = "gobangCore"
        public static extern int getOrder();

    }
}
