using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace UsageRecord
{
    public partial class User : Form
    {
        public User()
        {
            InitializeComponent();
        }
        private void 查询设备ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                Status frm = new Status
                {
                    MdiParent = this
                };
                frm.Show();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
        private void 租借归还设备ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                Operate frm = new Operate
                {
                    MdiParent = this
                };
                frm.Show();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
        private void 退出系统ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                //询问是否退出
                DialogResult result = MessageBox.Show("是否退出系统？", "提示", MessageBoxButtons.OKCancel, MessageBoxIcon.Question);
                if (result == DialogResult.OK)//如果选择确定
                    Application.Exit();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void 查询当前ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                Booked frm = new Booked
                {
                    MdiParent = this
                };
                frm.Show();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}
