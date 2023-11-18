namespace UsageRecord
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
            this.components = new System.ComponentModel.Container();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.查询设备ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.管理设备ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.管理用户ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.修改密码ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.退出系统ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.GripMargin = new System.Windows.Forms.Padding(2, 2, 0, 2);
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(24, 24);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.查询设备ToolStripMenuItem,
            this.管理设备ToolStripMenuItem,
            this.管理用户ToolStripMenuItem,
            this.修改密码ToolStripMenuItem,
            this.退出系统ToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1577, 33);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // 查询设备ToolStripMenuItem
            // 
            this.查询设备ToolStripMenuItem.Name = "查询设备ToolStripMenuItem";
            this.查询设备ToolStripMenuItem.Size = new System.Drawing.Size(104, 29);
            this.查询设备ToolStripMenuItem.Text = "查询设备";
            this.查询设备ToolStripMenuItem.Click += new System.EventHandler(this.查询设备ToolStripMenuItem_Click);
            // 
            // 管理设备ToolStripMenuItem
            // 
            this.管理设备ToolStripMenuItem.Name = "管理设备ToolStripMenuItem";
            this.管理设备ToolStripMenuItem.Size = new System.Drawing.Size(104, 29);
            this.管理设备ToolStripMenuItem.Text = "管理设备";
            this.管理设备ToolStripMenuItem.Click += new System.EventHandler(this.管理设备ToolStripMenuItem_Click);
            // 
            // 管理用户ToolStripMenuItem
            // 
            this.管理用户ToolStripMenuItem.Name = "管理用户ToolStripMenuItem";
            this.管理用户ToolStripMenuItem.Size = new System.Drawing.Size(104, 29);
            this.管理用户ToolStripMenuItem.Text = "管理用户";
            this.管理用户ToolStripMenuItem.Click += new System.EventHandler(this.管理用户ToolStripMenuItem_Click);
            // 
            // 修改密码ToolStripMenuItem
            // 
            this.修改密码ToolStripMenuItem.Name = "修改密码ToolStripMenuItem";
            this.修改密码ToolStripMenuItem.Size = new System.Drawing.Size(104, 29);
            this.修改密码ToolStripMenuItem.Text = "修改密码";
            this.修改密码ToolStripMenuItem.Click += new System.EventHandler(this.修改密码ToolStripMenuItem_Click);
            // 
            // 退出系统ToolStripMenuItem
            // 
            this.退出系统ToolStripMenuItem.Name = "退出系统ToolStripMenuItem";
            this.退出系统ToolStripMenuItem.Size = new System.Drawing.Size(104, 29);
            this.退出系统ToolStripMenuItem.Text = "退出系统";
            this.退出系统ToolStripMenuItem.Click += new System.EventHandler(this.退出系统ToolStripMenuItem_Click);
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.ImageScalingSize = new System.Drawing.Size(24, 24);
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(61, 4);
            // 
            // Admin
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1577, 813);
            this.Controls.Add(this.menuStrip1);
            this.IsMdiContainer = true;
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Admin";
            this.Text = "系统管理";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 查询设备ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 管理设备ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 管理用户ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 修改密码ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 退出系统ToolStripMenuItem;
    }
}