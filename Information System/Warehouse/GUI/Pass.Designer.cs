namespace Warehouse
{
    partial class Pass
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
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.verify = new System.Windows.Forms.TextBox();
            this.oldPass = new System.Windows.Forms.TextBox();
            this.userId = new System.Windows.Forms.TextBox();
            this.newPass = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.Modify = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(27, 91);
            this.label4.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(52, 16);
            this.label4.TabIndex = 18;
            this.label4.Text = "原密码";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(27, 193);
            this.label3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(67, 16);
            this.label3.TabIndex = 17;
            this.label3.Text = "再次输入";
            // 
            // verify
            // 
            this.verify.Location = new System.Drawing.Point(156, 190);
            this.verify.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.verify.MaxLength = 32;
            this.verify.Name = "verify";
            this.verify.Size = new System.Drawing.Size(132, 22);
            this.verify.TabIndex = 16;
            // 
            // oldPass
            // 
            this.oldPass.Location = new System.Drawing.Point(156, 87);
            this.oldPass.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.oldPass.MaxLength = 32;
            this.oldPass.Name = "oldPass";
            this.oldPass.Size = new System.Drawing.Size(132, 22);
            this.oldPass.TabIndex = 15;
            // 
            // userId
            // 
            this.userId.Location = new System.Drawing.Point(156, 26);
            this.userId.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.userId.MaxLength = 8;
            this.userId.Name = "userId";
            this.userId.Size = new System.Drawing.Size(132, 22);
            this.userId.TabIndex = 14;
            // 
            // newPass
            // 
            this.newPass.Location = new System.Drawing.Point(156, 142);
            this.newPass.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.newPass.MaxLength = 32;
            this.newPass.Name = "newPass";
            this.newPass.Size = new System.Drawing.Size(132, 22);
            this.newPass.TabIndex = 13;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(27, 145);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(52, 16);
            this.label2.TabIndex = 12;
            this.label2.Text = "新密码";
            // 
            // Modify
            // 
            this.Modify.Location = new System.Drawing.Point(291, 262);
            this.Modify.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Modify.Name = "Modify";
            this.Modify.Size = new System.Drawing.Size(100, 28);
            this.Modify.TabIndex = 11;
            this.Modify.Text = "修改";
            this.Modify.UseVisualStyleBackColor = true;
            this.Modify.Click += new System.EventHandler(this.Modify_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(27, 30);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(48, 16);
            this.label1.TabIndex = 10;
            this.label1.Text = "用户id";
            // 
            // Pass
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(407, 318);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.verify);
            this.Controls.Add(this.oldPass);
            this.Controls.Add(this.userId);
            this.Controls.Add(this.newPass);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.Modify);
            this.Controls.Add(this.label1);
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "Pass";
            this.Text = "修改密码";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox verify;
        private System.Windows.Forms.TextBox oldPass;
        private System.Windows.Forms.TextBox userId;
        private System.Windows.Forms.TextBox newPass;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button Modify;
        private System.Windows.Forms.Label label1;
    }
}