namespace Warehouse
{
    partial class AdminPass
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
            this.label1 = new System.Windows.Forms.Label();
            this.Modify = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.newPass = new System.Windows.Forms.TextBox();
            this.oldPass = new System.Windows.Forms.TextBox();
            this.verify = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(16, 27);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(48, 16);
            this.label1.TabIndex = 0;
            this.label1.Text = "用户id";
            // 
            // Modify
            // 
            this.Modify.Location = new System.Drawing.Point(280, 260);
            this.Modify.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Modify.Name = "Modify";
            this.Modify.Size = new System.Drawing.Size(100, 28);
            this.Modify.TabIndex = 1;
            this.Modify.Text = "修改";
            this.Modify.UseVisualStyleBackColor = true;
            this.Modify.Click += new System.EventHandler(this.Modify_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(16, 143);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(52, 16);
            this.label2.TabIndex = 3;
            this.label2.Text = "新密码";
            // 
            // newPass
            // 
            this.newPass.Location = new System.Drawing.Point(145, 139);
            this.newPass.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.newPass.MaxLength = 32;
            this.newPass.Name = "newPass";
            this.newPass.Size = new System.Drawing.Size(132, 22);
            this.newPass.TabIndex = 4;
            // 
            // oldPass
            // 
            this.oldPass.Location = new System.Drawing.Point(145, 80);
            this.oldPass.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.oldPass.MaxLength = 32;
            this.oldPass.Name = "oldPass";
            this.oldPass.Size = new System.Drawing.Size(132, 22);
            this.oldPass.TabIndex = 6;
            // 
            // verify
            // 
            this.verify.Location = new System.Drawing.Point(145, 187);
            this.verify.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.verify.MaxLength = 32;
            this.verify.Name = "verify";
            this.verify.Size = new System.Drawing.Size(132, 22);
            this.verify.TabIndex = 7;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(16, 191);
            this.label3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(67, 16);
            this.label3.TabIndex = 8;
            this.label3.Text = "再次输入";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(16, 89);
            this.label4.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(52, 16);
            this.label4.TabIndex = 9;
            this.label4.Text = "原密码";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(141, 27);
            this.label5.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(0, 16);
            this.label5.TabIndex = 10;
            // 
            // AdminPass
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(404, 332);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.verify);
            this.Controls.Add(this.oldPass);
            this.Controls.Add(this.newPass);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.Modify);
            this.Controls.Add(this.label1);
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "AdminPass";
            this.Text = "修改密码";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button Modify;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox newPass;
        private System.Windows.Forms.TextBox oldPass;
        private System.Windows.Forms.TextBox verify;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
    }
}