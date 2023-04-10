namespace Student_Course
{
    partial class Student
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
            this.Add = new System.Windows.Forms.Button();
            this.Delete = new System.Windows.Forms.Button();
            this.Modify = new System.Windows.Forms.Button();
            this.Query = new System.Windows.Forms.Button();
            this.sname = new System.Windows.Forms.TextBox();
            this.sdept = new System.Windows.Forms.TextBox();
            this.ssex = new System.Windows.Forms.TextBox();
            this.sno = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
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
            this.dataGridView1.Location = new System.Drawing.Point(12, 156);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowHeadersWidth = 51;
            this.dataGridView1.RowTemplate.Height = 24;
            this.dataGridView1.Size = new System.Drawing.Size(1109, 494);
            this.dataGridView1.TabIndex = 0;
            // 
            // Add
            // 
            this.Add.Location = new System.Drawing.Point(886, 25);
            this.Add.Name = "Add";
            this.Add.Size = new System.Drawing.Size(86, 43);
            this.Add.TabIndex = 1;
            this.Add.Text = "新增";
            this.Add.UseVisualStyleBackColor = true;
            this.Add.Click += new System.EventHandler(this.Add_Click);
            // 
            // Delete
            // 
            this.Delete.Location = new System.Drawing.Point(886, 89);
            this.Delete.Name = "Delete";
            this.Delete.Size = new System.Drawing.Size(86, 43);
            this.Delete.TabIndex = 2;
            this.Delete.Text = "删除";
            this.Delete.UseVisualStyleBackColor = true;
            this.Delete.Click += new System.EventHandler(this.Delete_Click);
            // 
            // Modify
            // 
            this.Modify.Location = new System.Drawing.Point(1015, 25);
            this.Modify.Name = "Modify";
            this.Modify.Size = new System.Drawing.Size(86, 43);
            this.Modify.TabIndex = 3;
            this.Modify.Text = "修改";
            this.Modify.UseVisualStyleBackColor = true;
            this.Modify.Click += new System.EventHandler(this.Modify_Click);
            // 
            // Query
            // 
            this.Query.Location = new System.Drawing.Point(1015, 89);
            this.Query.Name = "Query";
            this.Query.Size = new System.Drawing.Size(86, 43);
            this.Query.TabIndex = 4;
            this.Query.Text = "查询";
            this.Query.UseVisualStyleBackColor = true;
            this.Query.Click += new System.EventHandler(this.Query_Click_1);
            // 
            // sname
            // 
            this.sname.Location = new System.Drawing.Point(353, 103);
            this.sname.Name = "sname";
            this.sname.Size = new System.Drawing.Size(100, 22);
            this.sname.TabIndex = 5;
            // 
            // sdept
            // 
            this.sdept.Location = new System.Drawing.Point(353, 32);
            this.sdept.Name = "sdept";
            this.sdept.Size = new System.Drawing.Size(100, 22);
            this.sdept.TabIndex = 6;
            // 
            // ssex
            // 
            this.ssex.Location = new System.Drawing.Point(111, 106);
            this.ssex.Name = "ssex";
            this.ssex.Size = new System.Drawing.Size(100, 22);
            this.ssex.TabIndex = 7;
            // 
            // sno
            // 
            this.sno.Location = new System.Drawing.Point(111, 32);
            this.sno.Name = "sno";
            this.sno.Size = new System.Drawing.Size(100, 22);
            this.sno.TabIndex = 8;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(40, 35);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(37, 16);
            this.label1.TabIndex = 9;
            this.label1.Text = "学号";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(291, 35);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(37, 16);
            this.label2.TabIndex = 10;
            this.label2.Text = "系名";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(40, 106);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(37, 16);
            this.label3.TabIndex = 11;
            this.label3.Text = "性别";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(291, 106);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(37, 16);
            this.label4.TabIndex = 12;
            this.label4.Text = "姓名";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(517, 35);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(37, 16);
            this.label5.TabIndex = 14;
            this.label5.Text = "年龄";
            // 
            // sage
            // 
            this.sage.Location = new System.Drawing.Point(579, 32);
            this.sage.Name = "sage";
            this.sage.Size = new System.Drawing.Size(100, 22);
            this.sage.TabIndex = 13;
            // 
            // Student
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1133, 662);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.sage);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.sno);
            this.Controls.Add(this.ssex);
            this.Controls.Add(this.sdept);
            this.Controls.Add(this.sname);
            this.Controls.Add(this.Query);
            this.Controls.Add(this.Modify);
            this.Controls.Add(this.Delete);
            this.Controls.Add(this.Add);
            this.Controls.Add(this.dataGridView1);
            this.Name = "Student";
            this.Text = "Student";
            this.Load += new System.EventHandler(this.Student_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.Button Add;
        private System.Windows.Forms.Button Delete;
        private System.Windows.Forms.Button Modify;
        private System.Windows.Forms.Button Query;
        private System.Windows.Forms.TextBox sname;
        private System.Windows.Forms.TextBox sdept;
        private System.Windows.Forms.TextBox sno;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox sage;
        private System.Windows.Forms.TextBox ssex;
    }
}