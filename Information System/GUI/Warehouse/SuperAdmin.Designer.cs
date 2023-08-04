namespace Warehouse
{
    partial class SuperAdmin
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.人员管理 = new System.Windows.Forms.ToolStripMenuItem();
            this.基础信息管理ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.供应商 = new System.Windows.Forms.ToolStripMenuItem();
            this.货物信息管理 = new System.Windows.Forms.ToolStripMenuItem();
            this.查询库存ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.查询流水ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.入库ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.出库ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.仓库信息管理 = new System.Windows.Forms.ToolStripMenuItem();
            this.系统维护 = new System.Windows.Forms.ToolStripMenuItem();
            this.管理员日志 = new System.Windows.Forms.ToolStripMenuItem();
            this.退出系统ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.人员管理,
            this.基础信息管理ToolStripMenuItem,
            this.系统维护,
            this.退出系统ToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1264, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // 人员管理
            // 
            this.人员管理.Name = "人员管理";
            this.人员管理.Size = new System.Drawing.Size(71, 20);
            this.人员管理.Text = "人员管理";
            this.人员管理.Click += new System.EventHandler(this.人员管理_Click);
            // 
            // 基础信息管理ToolStripMenuItem
            // 
            this.基础信息管理ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.供应商,
            this.货物信息管理,
            this.仓库信息管理});
            this.基础信息管理ToolStripMenuItem.Name = "基础信息管理ToolStripMenuItem";
            this.基础信息管理ToolStripMenuItem.Size = new System.Drawing.Size(97, 20);
            this.基础信息管理ToolStripMenuItem.Text = "基础信息管理";
            // 
            // 供应商
            // 
            this.供应商.Name = "供应商";
            this.供应商.Size = new System.Drawing.Size(165, 22);
            this.供应商.Text = "供应商信息管理";
            this.供应商.Click += new System.EventHandler(this.供应商_Click);
            // 
            // 货物信息管理
            // 
            this.货物信息管理.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.查询库存ToolStripMenuItem,
            this.查询流水ToolStripMenuItem,
            this.入库ToolStripMenuItem,
            this.出库ToolStripMenuItem});
            this.货物信息管理.Name = "货物信息管理";
            this.货物信息管理.Size = new System.Drawing.Size(165, 22);
            this.货物信息管理.Text = "货物信息管理";
            // 
            // 查询库存ToolStripMenuItem
            // 
            this.查询库存ToolStripMenuItem.Name = "查询库存ToolStripMenuItem";
            this.查询库存ToolStripMenuItem.Size = new System.Drawing.Size(126, 22);
            this.查询库存ToolStripMenuItem.Text = "查询库存";
            this.查询库存ToolStripMenuItem.Click += new System.EventHandler(this.查询库存ToolStripMenuItem_Click);
            // 
            // 查询流水ToolStripMenuItem
            // 
            this.查询流水ToolStripMenuItem.Name = "查询流水ToolStripMenuItem";
            this.查询流水ToolStripMenuItem.Size = new System.Drawing.Size(126, 22);
            this.查询流水ToolStripMenuItem.Text = "查询流水";
            this.查询流水ToolStripMenuItem.Click += new System.EventHandler(this.查询流水ToolStripMenuItem_Click);
            // 
            // 入库ToolStripMenuItem
            // 
            this.入库ToolStripMenuItem.Name = "入库ToolStripMenuItem";
            this.入库ToolStripMenuItem.Size = new System.Drawing.Size(126, 22);
            this.入库ToolStripMenuItem.Text = "入库";
            this.入库ToolStripMenuItem.Click += new System.EventHandler(this.入库ToolStripMenuItem_Click);
            // 
            // 出库ToolStripMenuItem
            // 
            this.出库ToolStripMenuItem.Name = "出库ToolStripMenuItem";
            this.出库ToolStripMenuItem.Size = new System.Drawing.Size(126, 22);
            this.出库ToolStripMenuItem.Text = "出库";
            this.出库ToolStripMenuItem.Click += new System.EventHandler(this.出库ToolStripMenuItem_Click);
            // 
            // 仓库信息管理
            // 
            this.仓库信息管理.Name = "仓库信息管理";
            this.仓库信息管理.Size = new System.Drawing.Size(165, 22);
            this.仓库信息管理.Text = "仓库信息管理";
            this.仓库信息管理.Click += new System.EventHandler(this.仓库信息管理_Click);
            // 
            // 系统维护
            // 
            this.系统维护.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.管理员日志});
            this.系统维护.Name = "系统维护";
            this.系统维护.Size = new System.Drawing.Size(71, 20);
            this.系统维护.Text = "系统维护";
            // 
            // 管理员日志
            // 
            this.管理员日志.Name = "管理员日志";
            this.管理员日志.Size = new System.Drawing.Size(126, 22);
            this.管理员日志.Text = "系统日志";
            this.管理员日志.Click += new System.EventHandler(this.管理员日志_Click);
            // 
            // 退出系统ToolStripMenuItem
            // 
            this.退出系统ToolStripMenuItem.Name = "退出系统ToolStripMenuItem";
            this.退出系统ToolStripMenuItem.Size = new System.Drawing.Size(71, 20);
            this.退出系统ToolStripMenuItem.Text = "退出系统";
            this.退出系统ToolStripMenuItem.Click += new System.EventHandler(this.退出系统ToolStripMenuItem_Click);
            // 
            // SuperAdmin
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.ClientSize = new System.Drawing.Size(1264, 729);
            this.ControlBox = false;
            this.Controls.Add(this.menuStrip1);
            this.IsMdiContainer = true;
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "SuperAdmin";
            this.Text = "超级管理   当前管理员ID: ";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 人员管理;
        private System.Windows.Forms.ToolStripMenuItem 基础信息管理ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 供应商;
        private System.Windows.Forms.ToolStripMenuItem 货物信息管理;
        private System.Windows.Forms.ToolStripMenuItem 仓库信息管理;
        private System.Windows.Forms.ToolStripMenuItem 系统维护;
        private System.Windows.Forms.ToolStripMenuItem 管理员日志;
        private System.Windows.Forms.ToolStripMenuItem 退出系统ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 查询库存ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 查询流水ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 入库ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 出库ToolStripMenuItem;
    }
}