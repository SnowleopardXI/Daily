namespace Student_Course
{
    partial class FormCourseAdd
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
            this.Add = new System.Windows.Forms.Button();
            this.cno = new System.Windows.Forms.TextBox();
            this.cname = new System.Windows.Forms.TextBox();
            this.ccredit = new System.Windows.Forms.TextBox();
            this.cpno = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // Add
            // 
            this.Add.Location = new System.Drawing.Point(593, 135);
            this.Add.Name = "Add";
            this.Add.Size = new System.Drawing.Size(158, 64);
            this.Add.TabIndex = 2;
            this.Add.Text = "添加";
            this.Add.UseVisualStyleBackColor = true;
            this.Add.Click += new System.EventHandler(this.Add_Click);
            // 
            // cno
            // 
            this.cno.Location = new System.Drawing.Point(117, 48);
            this.cno.Name = "cno";
            this.cno.Size = new System.Drawing.Size(89, 22);
            this.cno.TabIndex = 3;
            this.cno.TextChanged += new System.EventHandler(this.cno_TextChanged);
            // 
            // cname
            // 
            this.cname.Location = new System.Drawing.Point(363, 48);
            this.cname.Name = "cname";
            this.cname.Size = new System.Drawing.Size(139, 22);
            this.cname.TabIndex = 4;
            this.cname.TextChanged += new System.EventHandler(this.cname_TextChanged);
            // 
            // ccredit
            // 
            this.ccredit.Location = new System.Drawing.Point(117, 177);
            this.ccredit.Name = "ccredit";
            this.ccredit.Size = new System.Drawing.Size(89, 22);
            this.ccredit.TabIndex = 5;
            this.ccredit.TextChanged += new System.EventHandler(this.ccredit_TextChanged);
            // 
            // cpno
            // 
            this.cpno.Location = new System.Drawing.Point(363, 177);
            this.cpno.Name = "cpno";
            this.cpno.Size = new System.Drawing.Size(89, 22);
            this.cpno.TabIndex = 6;
            this.cpno.TextChanged += new System.EventHandler(this.cpno_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(59, 51);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(52, 16);
            this.label1.TabIndex = 7;
            this.label1.Text = "课程号";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(290, 51);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(67, 16);
            this.label2.TabIndex = 8;
            this.label2.Text = "课程名称";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(74, 180);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(37, 16);
            this.label3.TabIndex = 9;
            this.label3.Text = "学分";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(305, 180);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(52, 16);
            this.label4.TabIndex = 10;
            this.label4.Text = "先行课";
            // 
            // FormCourseAdd
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(787, 277);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.cpno);
            this.Controls.Add(this.ccredit);
            this.Controls.Add(this.cname);
            this.Controls.Add(this.cno);
            this.Controls.Add(this.Add);
            this.Name = "FormCourseAdd";
            this.Text = "课程添加";
            this.Load += new System.EventHandler(this.FormCourseAdd_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button Add;
        private System.Windows.Forms.TextBox cno;
        private System.Windows.Forms.TextBox cname;
        private System.Windows.Forms.TextBox cpno;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox ccredit;
    }
}