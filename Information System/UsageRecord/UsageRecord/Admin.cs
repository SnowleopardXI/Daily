using System;
using System.Windows.Forms;

namespace UsageRecord
{
    public partial class Admin : Form
    {
        public Admin()
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
        private void 管理设备ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                DeviceMgr frm = new DeviceMgr
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
        private void 管理用户ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                UserMgr frm = new UserMgr
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
        private void 修改密码ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                Pass frm = new Pass
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
    }
}
