namespace Users
{
    partial class Home
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
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.label1 = new System.Windows.Forms.Label();
            this.id = new System.Windows.Forms.TextBox();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.phone = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.gender = new System.Windows.Forms.ComboBox();
            this.delete = new System.Windows.Forms.Button();
            this.add = new System.Windows.Forms.Button();
            this.modify = new System.Windows.Forms.Button();
            this.query = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.姓名 = new System.Windows.Forms.Label();
            this.name = new System.Windows.Forms.TextBox();
            this.age = new System.Windows.Forms.TextBox();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.button1 = new System.Windows.Forms.Button();
            this.dataGridView2 = new System.Windows.Forms.DataGridView();
            this.button2 = new System.Windows.Forms.Button();
            this.label5 = new System.Windows.Forms.Label();
            this.uid = new System.Windows.Forms.TextBox();
            this.note = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.exit = new System.Windows.Forms.Button();
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.tabPage2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).BeginInit();
            this.SuspendLayout();
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Location = new System.Drawing.Point(0, 0);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(1463, 760);
            this.tabControl1.TabIndex = 0;
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.label1);
            this.tabPage1.Controls.Add(this.id);
            this.tabPage1.Controls.Add(this.dataGridView1);
            this.tabPage1.Controls.Add(this.phone);
            this.tabPage1.Controls.Add(this.label2);
            this.tabPage1.Controls.Add(this.gender);
            this.tabPage1.Controls.Add(this.delete);
            this.tabPage1.Controls.Add(this.add);
            this.tabPage1.Controls.Add(this.modify);
            this.tabPage1.Controls.Add(this.query);
            this.tabPage1.Controls.Add(this.label4);
            this.tabPage1.Controls.Add(this.label3);
            this.tabPage1.Controls.Add(this.姓名);
            this.tabPage1.Controls.Add(this.name);
            this.tabPage1.Controls.Add(this.age);
            this.tabPage1.Location = new System.Drawing.Point(4, 29);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(1455, 727);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "客户信息管理";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(456, 29);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(26, 20);
            this.label1.TabIndex = 32;
            this.label1.Text = "ID";
            // 
            // id
            // 
            this.id.Location = new System.Drawing.Point(524, 29);
            this.id.Name = "id";
            this.id.Size = new System.Drawing.Size(100, 26);
            this.id.TabIndex = 31;
            // 
            // dataGridView1
            // 
            this.dataGridView1.AllowUserToAddRows = false;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(29, 150);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowHeadersWidth = 62;
            this.dataGridView1.RowTemplate.Height = 28;
            this.dataGridView1.Size = new System.Drawing.Size(1393, 559);
            this.dataGridView1.TabIndex = 30;
            // 
            // phone
            // 
            this.phone.Location = new System.Drawing.Point(307, 26);
            this.phone.Name = "phone";
            this.phone.Size = new System.Drawing.Size(100, 26);
            this.phone.TabIndex = 29;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(237, 32);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(41, 20);
            this.label2.TabIndex = 28;
            this.label2.Text = "电话";
            // 
            // gender
            // 
            this.gender.FormattingEnabled = true;
            this.gender.Items.AddRange(new object[] {
            "不限",
            "男",
            "女"});
            this.gender.Location = new System.Drawing.Point(107, 89);
            this.gender.Name = "gender";
            this.gender.Size = new System.Drawing.Size(100, 28);
            this.gender.TabIndex = 27;
            // 
            // delete
            // 
            this.delete.Location = new System.Drawing.Point(1318, 89);
            this.delete.Name = "delete";
            this.delete.Size = new System.Drawing.Size(104, 41);
            this.delete.TabIndex = 26;
            this.delete.Text = "删除";
            this.delete.UseVisualStyleBackColor = true;
            this.delete.Click += new System.EventHandler(this.delete_Click_1);
            // 
            // add
            // 
            this.add.Location = new System.Drawing.Point(1318, 28);
            this.add.Name = "add";
            this.add.Size = new System.Drawing.Size(104, 41);
            this.add.TabIndex = 25;
            this.add.Text = "添加";
            this.add.UseVisualStyleBackColor = true;
            this.add.Click += new System.EventHandler(this.add_Click_1);
            // 
            // modify
            // 
            this.modify.Location = new System.Drawing.Point(1187, 89);
            this.modify.Name = "modify";
            this.modify.Size = new System.Drawing.Size(104, 41);
            this.modify.TabIndex = 24;
            this.modify.Text = "修改";
            this.modify.UseVisualStyleBackColor = true;
            this.modify.Click += new System.EventHandler(this.modify_Click_1);
            // 
            // query
            // 
            this.query.Location = new System.Drawing.Point(1187, 28);
            this.query.Name = "query";
            this.query.Size = new System.Drawing.Size(104, 41);
            this.query.TabIndex = 23;
            this.query.Text = "查询";
            this.query.UseVisualStyleBackColor = true;
            this.query.Click += new System.EventHandler(this.query_Click_1);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(237, 89);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(41, 20);
            this.label4.TabIndex = 22;
            this.label4.Text = "年龄";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(37, 94);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(41, 20);
            this.label3.TabIndex = 21;
            this.label3.Text = "性别";
            // 
            // 姓名
            // 
            this.姓名.AutoSize = true;
            this.姓名.Location = new System.Drawing.Point(39, 32);
            this.姓名.Name = "姓名";
            this.姓名.Size = new System.Drawing.Size(41, 20);
            this.姓名.TabIndex = 20;
            this.姓名.Text = "姓名";
            // 
            // name
            // 
            this.name.Location = new System.Drawing.Point(107, 26);
            this.name.Name = "name";
            this.name.Size = new System.Drawing.Size(100, 26);
            this.name.TabIndex = 19;
            // 
            // age
            // 
            this.age.Location = new System.Drawing.Point(307, 89);
            this.age.Name = "age";
            this.age.Size = new System.Drawing.Size(100, 26);
            this.age.TabIndex = 18;
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.note);
            this.tabPage2.Controls.Add(this.label6);
            this.tabPage2.Controls.Add(this.uid);
            this.tabPage2.Controls.Add(this.label5);
            this.tabPage2.Controls.Add(this.button2);
            this.tabPage2.Controls.Add(this.dataGridView2);
            this.tabPage2.Controls.Add(this.button1);
            this.tabPage2.Location = new System.Drawing.Point(4, 29);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(1455, 727);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "客户备注管理";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(1315, 27);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(104, 41);
            this.button1.TabIndex = 24;
            this.button1.Text = "查询";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // dataGridView2
            // 
            this.dataGridView2.AllowUserToAddRows = false;
            this.dataGridView2.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView2.Location = new System.Drawing.Point(26, 102);
            this.dataGridView2.Name = "dataGridView2";
            this.dataGridView2.RowHeadersWidth = 62;
            this.dataGridView2.RowTemplate.Height = 28;
            this.dataGridView2.Size = new System.Drawing.Size(1393, 601);
            this.dataGridView2.TabIndex = 25;
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(1142, 27);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(104, 41);
            this.button2.TabIndex = 26;
            this.button2.Text = "修改";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(31, 42);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(26, 20);
            this.label5.TabIndex = 27;
            this.label5.Text = "ID";
            // 
            // uid
            // 
            this.uid.Location = new System.Drawing.Point(79, 42);
            this.uid.Name = "uid";
            this.uid.Size = new System.Drawing.Size(100, 26);
            this.uid.TabIndex = 28;
            // 
            // note
            // 
            this.note.Location = new System.Drawing.Point(294, 42);
            this.note.Name = "note";
            this.note.Size = new System.Drawing.Size(273, 26);
            this.note.TabIndex = 30;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(246, 42);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(41, 20);
            this.label6.TabIndex = 29;
            this.label6.Text = "备注";
            // 
            // exit
            // 
            this.exit.Location = new System.Drawing.Point(1319, 766);
            this.exit.Name = "exit";
            this.exit.Size = new System.Drawing.Size(104, 41);
            this.exit.TabIndex = 25;
            this.exit.Text = "退出";
            this.exit.UseVisualStyleBackColor = true;
            this.exit.Click += new System.EventHandler(this.exit_Click);
            // 
            // Home
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1474, 817);
            this.ControlBox = false;
            this.Controls.Add(this.exit);
            this.Controls.Add(this.tabControl1);
            this.Name = "Home";
            this.Text = "客户管理系统";
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabPage1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox id;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.TextBox phone;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ComboBox gender;
        private System.Windows.Forms.Button delete;
        private System.Windows.Forms.Button add;
        private System.Windows.Forms.Button modify;
        private System.Windows.Forms.Button query;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label 姓名;
        private System.Windows.Forms.TextBox name;
        private System.Windows.Forms.TextBox age;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.DataGridView dataGridView2;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.TextBox uid;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox note;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Button exit;
    }
}