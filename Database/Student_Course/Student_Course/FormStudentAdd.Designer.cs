namespace Student_Course
{
    partial class FormStudentAdd
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
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.ssex = new System.Windows.Forms.TextBox();
            this.sno = new System.Windows.Forms.TextBox();
            this.sname = new System.Windows.Forms.TextBox();
            this.sage = new System.Windows.Forms.TextBox();
            this.sdept = new System.Windows.Forms.TextBox();
            this.Add = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(61, 63);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(37, 16);
            this.label1.TabIndex = 0;
            this.label1.Text = "学号";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(61, 166);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(37, 16);
            this.label2.TabIndex = 1;
            this.label2.Text = "姓名";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(411, 63);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(37, 16);
            this.label3.TabIndex = 2;
            this.label3.Text = "性别";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(411, 166);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(37, 16);
            this.label4.TabIndex = 3;
            this.label4.Text = "年龄";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(61, 270);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(37, 16);
            this.label5.TabIndex = 4;
            this.label5.Text = "系名";
            // 
            // ssex
            // 
            this.ssex.Location = new System.Drawing.Point(454, 60);
            this.ssex.Name = "ssex";
            this.ssex.Size = new System.Drawing.Size(114, 22);
            this.ssex.TabIndex = 5;
            this.ssex.TextChanged += new System.EventHandler(this.ssex_TextChanged);
            // 
            // sno
            // 
            this.sno.Location = new System.Drawing.Point(104, 60);
            this.sno.Name = "sno";
            this.sno.Size = new System.Drawing.Size(114, 22);
            this.sno.TabIndex = 6;
            this.sno.TextChanged += new System.EventHandler(this.sno_TextChanged);
            // 
            // sname
            // 
            this.sname.Location = new System.Drawing.Point(104, 163);
            this.sname.Name = "sname";
            this.sname.Size = new System.Drawing.Size(114, 22);
            this.sname.TabIndex = 7;
            this.sname.TextChanged += new System.EventHandler(this.sname_TextChanged);
            // 
            // sage
            // 
            this.sage.Location = new System.Drawing.Point(454, 160);
            this.sage.Name = "sage";
            this.sage.Size = new System.Drawing.Size(114, 22);
            this.sage.TabIndex = 8;
            this.sage.TextChanged += new System.EventHandler(this.sage_TextChanged);
            // 
            // sdept
            // 
            this.sdept.Location = new System.Drawing.Point(104, 267);
            this.sdept.Name = "sdept";
            this.sdept.Size = new System.Drawing.Size(114, 22);
            this.sdept.TabIndex = 9;
            this.sdept.TextChanged += new System.EventHandler(this.sdept_TextChanged);
            // 
            // Add
            // 
            this.Add.Location = new System.Drawing.Point(591, 287);
            this.Add.Name = "Add";
            this.Add.Size = new System.Drawing.Size(144, 50);
            this.Add.TabIndex = 10;
            this.Add.Text = "添加";
            this.Add.UseVisualStyleBackColor = true;
            this.Add.Click += new System.EventHandler(this.Add_Click);
            // 
            // FormStudentAdd
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(787, 391);
            this.Controls.Add(this.Add);
            this.Controls.Add(this.sdept);
            this.Controls.Add(this.sage);
            this.Controls.Add(this.sname);
            this.Controls.Add(this.sno);
            this.Controls.Add(this.ssex);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "FormStudentAdd";
            this.Text = "学生添加";
            this.Load += new System.EventHandler(this.FormStudentAdd_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox ssex;
        private System.Windows.Forms.TextBox sno;
        private System.Windows.Forms.TextBox sage;
        private System.Windows.Forms.TextBox sdept;
        private System.Windows.Forms.Button Add;
        private System.Windows.Forms.TextBox sname;
    }
}