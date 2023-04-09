namespace Student_Course
{
    partial class Course
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
            this.cpno = new System.Windows.Forms.TextBox();
            this.cname = new System.Windows.Forms.TextBox();
            this.ccredit = new System.Windows.Forms.TextBox();
            this.cno = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
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
            this.dataGridView1.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellContentClick);
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
            // cpno
            // 
            this.cpno.Location = new System.Drawing.Point(440, 103);
            this.cpno.Name = "cpno";
            this.cpno.Size = new System.Drawing.Size(100, 22);
            this.cpno.TabIndex = 5;
            // 
            // cname
            // 
            this.cname.Location = new System.Drawing.Point(440, 32);
            this.cname.Name = "cname";
            this.cname.Size = new System.Drawing.Size(100, 22);
            this.cname.TabIndex = 6;
            // 
            // ccredit
            // 
            this.ccredit.Location = new System.Drawing.Point(111, 106);
            this.ccredit.Name = "ccredit";
            this.ccredit.Size = new System.Drawing.Size(100, 22);
            this.ccredit.TabIndex = 7;
            // 
            // cno
            // 
            this.cno.Location = new System.Drawing.Point(111, 32);
            this.cno.Name = "cno";
            this.cno.Size = new System.Drawing.Size(100, 22);
            this.cno.TabIndex = 8;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(40, 35);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(52, 16);
            this.label1.TabIndex = 9;
            this.label1.Text = "课程号";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(378, 35);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(52, 16);
            this.label2.TabIndex = 10;
            this.label2.Text = "课程名";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(40, 106);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(37, 16);
            this.label3.TabIndex = 11;
            this.label3.Text = "学分";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(378, 106);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(52, 16);
            this.label4.TabIndex = 12;
            this.label4.Text = "先行课";
            // 
            // Course
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1133, 662);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.cno);
            this.Controls.Add(this.ccredit);
            this.Controls.Add(this.cname);
            this.Controls.Add(this.cpno);
            this.Controls.Add(this.Query);
            this.Controls.Add(this.Modify);
            this.Controls.Add(this.Delete);
            this.Controls.Add(this.Add);
            this.Controls.Add(this.dataGridView1);
            this.Name = "Course";
            this.Text = "Course";
            this.Load += new System.EventHandler(this.Course_Load);
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
        private System.Windows.Forms.TextBox cpno;
        private System.Windows.Forms.TextBox cname;
        private System.Windows.Forms.TextBox ccredit;
        private System.Windows.Forms.TextBox cno;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
    }
}