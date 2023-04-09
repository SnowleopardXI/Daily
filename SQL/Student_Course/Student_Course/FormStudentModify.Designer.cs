namespace Student_Course
{
    partial class FormStudentModify
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
            this.sno = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.sdept = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.sname = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.ssex = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.label5 = new System.Windows.Forms.Label();
            this.sage = new System.Windows.Forms.TextBox();
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
            this.label1.Size = new System.Drawing.Size(37, 16);
            this.label1.TabIndex = 6;
            this.label1.Text = "学号";
            // 
            // sno
            // 
            this.sno.Location = new System.Drawing.Point(81, 12);
            this.sno.Name = "sno";
            this.sno.Size = new System.Drawing.Size(100, 22);
            this.sno.TabIndex = 5;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(18, 74);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(37, 16);
            this.label2.TabIndex = 8;
            this.label2.Text = "系名";
            // 
            // sdept
            // 
            this.sdept.Location = new System.Drawing.Point(81, 71);
            this.sdept.Name = "sdept";
            this.sdept.Size = new System.Drawing.Size(100, 22);
            this.sdept.TabIndex = 7;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(209, 71);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(37, 16);
            this.label3.TabIndex = 10;
            this.label3.Text = "姓名";
            // 
            // sname
            // 
            this.sname.Location = new System.Drawing.Point(282, 68);
            this.sname.Name = "sname";
            this.sname.Size = new System.Drawing.Size(95, 22);
            this.sname.TabIndex = 9;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(209, 18);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(37, 16);
            this.label4.TabIndex = 12;
            this.label4.Text = "性别";
            // 
            // ssex
            // 
            this.ssex.Location = new System.Drawing.Point(282, 15);
            this.ssex.Name = "ssex";
            this.ssex.Size = new System.Drawing.Size(95, 22);
            this.ssex.TabIndex = 11;
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
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(431, 18);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(37, 16);
            this.label5.TabIndex = 15;
            this.label5.Text = "年龄";
            // 
            // sage
            // 
            this.sage.Location = new System.Drawing.Point(504, 15);
            this.sage.Name = "sage";
            this.sage.Size = new System.Drawing.Size(95, 22);
            this.sage.TabIndex = 14;
            // 
            // FormStudentModify
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1002, 594);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.sage);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.ssex);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.sname);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.sdept);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.sno);
            this.Controls.Add(this.Modify);
            this.Controls.Add(this.dataGridView1);
            this.Name = "FormStudentModify";
            this.Text = "修改课程信息";
            this.Load += new System.EventHandler(this.FormStudentModify_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.Button Modify;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox sno;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox sdept;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox sname;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox ssex;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox sage;
    }
}