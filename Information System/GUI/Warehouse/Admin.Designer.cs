﻿namespace Warehouse
{
    partial class Admin
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
            this.库存查询 = new System.Windows.Forms.ToolStripMenuItem();
            this.出入库管理 = new System.Windows.Forms.ToolStripMenuItem();
            this.入库 = new System.Windows.Forms.ToolStripMenuItem();
            this.出库 = new System.Windows.Forms.ToolStripMenuItem();
            this.修改密码 = new System.Windows.Forms.ToolStripMenuItem();
            this.退出系统ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.库存查询,
            this.出入库管理,
            this.修改密码,
            this.退出系统ToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1264, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // 库存查询
            // 
            this.库存查询.Name = "库存查询";
            this.库存查询.Size = new System.Drawing.Size(71, 20);
            this.库存查询.Text = "库存查询";
            this.库存查询.Click += new System.EventHandler(this.库存查询ToolStripMenuItem_Click);
            // 
            // 出入库管理
            // 
            this.出入库管理.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.入库,
            this.出库});
            this.出入库管理.Name = "出入库管理";
            this.出入库管理.Size = new System.Drawing.Size(84, 20);
            this.出入库管理.Text = "出入库管理";
            // 
            // 入库
            // 
            this.入库.Name = "入库";
            this.入库.Size = new System.Drawing.Size(100, 22);
            this.入库.Text = "入库";
            this.入库.Click += new System.EventHandler(this.入库ToolStripMenuItem_Click);
            // 
            // 出库
            // 
            this.出库.Name = "出库";
            this.出库.Size = new System.Drawing.Size(100, 22);
            this.出库.Text = "出库";
            this.出库.Click += new System.EventHandler(this.出库ToolStripMenuItem_Click);
            // 
            // 修改密码
            // 
            this.修改密码.Name = "修改密码";
            this.修改密码.Size = new System.Drawing.Size(71, 20);
            this.修改密码.Text = "修改密码";
            this.修改密码.Click += new System.EventHandler(this.修改密码ToolStripMenuItem_Click);
            // 
            // 退出系统ToolStripMenuItem
            // 
            this.退出系统ToolStripMenuItem.Name = "退出系统ToolStripMenuItem";
            this.退出系统ToolStripMenuItem.Size = new System.Drawing.Size(71, 20);
            this.退出系统ToolStripMenuItem.Text = "退出系统";
            this.退出系统ToolStripMenuItem.Click += new System.EventHandler(this.退出系统ToolStripMenuItem_Click);
            // 
            // Admin
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.ClientSize = new System.Drawing.Size(1264, 729);
            this.ControlBox = false;
            this.Controls.Add(this.menuStrip1);
            this.IsMdiContainer = true;
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Admin";
            this.Text = "仓库管理   当前管理员ID: " + Program.current;
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 库存查询;
        private System.Windows.Forms.ToolStripMenuItem 出入库管理;
        private System.Windows.Forms.ToolStripMenuItem 修改密码;
        private System.Windows.Forms.ToolStripMenuItem 入库;
        private System.Windows.Forms.ToolStripMenuItem 出库;
        private System.Windows.Forms.ToolStripMenuItem 退出系统ToolStripMenuItem;
    }
}