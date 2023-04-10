namespace Student_Course
{
    partial class FormCourceModify
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
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.Modify = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.cno = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.cpno = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.cname = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.ccredit = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridView1
            // 
            this.dataGridView1.AllowUserToAddRows = false;
            this.dataGridView1.AllowUserToOrderColumns = true;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(12, 113);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowHeadersWidth = 51;
            this.dataGridView1.RowTemplate.Height = 24;
            this.dataGridView1.Size = new System.Drawing.Size(978, 469);
            this.dataGridView1.TabIndex = 0;
            // 
            // Modify
            // 
            this.Modify.Location = new System.Drawing.Point(849, 18);
            this.Modify.Name = "Modify";
            this.Modify.Size = new System.Drawing.Size(128, 58);
            this.Modify.TabIndex = 1;
            this.Modify.Text = "修改";
            this.Modify.UseVisualStyleBackColor = true;
            this.Modify.Click += new System.EventHandler(this.Modify_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(18, 15);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(52, 16);
            this.label1.TabIndex = 6;
            this.label1.Text = "课程号";
            // 
            // cno
            // 
            this.cno.Location = new System.Drawing.Point(81, 12);
            this.cno.Name = "cno";
            this.cno.Size = new System.Drawing.Size(100, 22);
            this.cno.TabIndex = 5;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(18, 74);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(52, 16);
            this.label2.TabIndex = 8;
            this.label2.Text = "先行课";
            // 
            // cpno
            // 
            this.cpno.Location = new System.Drawing.Point(81, 71);
            this.cpno.Name = "cpno";
            this.cpno.Size = new System.Drawing.Size(100, 22);
            this.cpno.TabIndex = 7;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(209, 71);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(52, 16);
            this.label3.TabIndex = 10;
            this.label3.Text = "课程名";
            // 
            // cname
            // 
            this.cname.Location = new System.Drawing.Point(282, 68);
            this.cname.Name = "cname";
            this.cname.Size = new System.Drawing.Size(240, 22);
            this.cname.TabIndex = 9;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(209, 18);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(67, 16);
            this.label4.TabIndex = 12;
            this.label4.Text = "课程学分";
            // 
            // ccredit
            // 
            this.ccredit.Location = new System.Drawing.Point(282, 15);
            this.ccredit.Name = "ccredit";
            this.ccredit.Size = new System.Drawing.Size(95, 22);
            this.ccredit.TabIndex = 11;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(684, 18);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(128, 58);
            this.button1.TabIndex = 13;
            this.button1.Text = "读取";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // FormCourceModify
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1002, 594);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.ccredit);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.cname);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.cpno);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.cno);
            this.Controls.Add(this.Modify);
            this.Controls.Add(this.dataGridView1);
            this.Name = "FormCourceModify";
            this.Text = "修改课程信息";
            this.Load += new System.EventHandler(this.FormCourceModify_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.Button Modify;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox cno;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox cpno;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox cname;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox ccredit;
        private System.Windows.Forms.Button button1;
    }
}