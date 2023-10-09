using System;
using System.Windows.Forms;

namespace Warehouse
{
    public partial class Admin : Form
    {
        public Admin()
        {
            InitializeComponent();
        }

        private void 库存查询ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                StockQuery frm = new StockQuery
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
                AdminPass frm = new AdminPass
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

        private void 入库ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                InStock frm = new InStock
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

        private void 出库ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                OutStock frm = new OutStock
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
