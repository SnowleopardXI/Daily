﻿using System;
using System.Windows.Forms;

namespace Warehouse
{
    public partial class SuperAdmin : Form
    {
        public SuperAdmin()
        {
            InitializeComponent();
        }

        private void 修改密码ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                Pass frm = new Pass();
                frm.MdiParent = this;
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

        private void 管理员日志_Click(object sender, EventArgs e)
        {
            try
            {
                AdminLog frm = new AdminLog();
                frm.MdiParent = this;
                frm.Show();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }


        private void 仓库信息管理_Click(object sender, EventArgs e)
        {
            try
            {
                StockInfo frm = new StockInfo();
                frm.MdiParent = this;
                frm.Show();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void 查询流水ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                StockLog frm = new StockLog();
                frm.MdiParent = this;
                frm.Show();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void 查询库存ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                StockQuery frm = new StockQuery();
                frm.MdiParent = this;
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
                InStock frm = new InStock();
                frm.MdiParent = this;
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
                OutStock frm = new OutStock();
                frm.MdiParent = this;
                frm.Show();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void 供应商_Click(object sender, EventArgs e)
        {
            try
            {
                Supplier frm = new Supplier();
                frm.MdiParent = this;
                frm.Show();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}
