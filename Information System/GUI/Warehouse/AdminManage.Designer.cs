namespace Warehouse
{
    partial class AdminManage
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
            this.id = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.name = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.email = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.phone = new System.Windows.Forms.TextBox();
            this.Admintype = new System.Windows.Forms.ComboBox();
            this.label7 = new System.Windows.Forms.Label();
            this.query = new System.Windows.Forms.Button();
            this.add = new System.Windows.Forms.Button();
            this.delete = new System.Windows.Forms.Button();
            this.disable = new System.Windows.Forms.Button();
            this.modify = new System.Windows.Forms.Button();
            this.enable = new System.Windows.Forms.Button();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(19, 38);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(50, 16);
            this.label1.TabIndex = 3;
            this.label1.Text = "用户ID";
            // 
            // id
            // 
            this.id.Location = new System.Drawing.Point(84, 35);
            this.id.MaxLength = 8;
            this.id.Name = "id";
            this.id.Size = new System.Drawing.Size(100, 22);
            this.id.TabIndex = 4;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(19, 92);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(52, 16);
            this.label2.TabIndex = 5;
            this.label2.Text = "用户名";
            // 
            // name
            // 
            this.name.Location = new System.Drawing.Point(84, 89);
            this.name.MaxLength = 32;
            this.name.Name = "name";
            this.name.Size = new System.Drawing.Size(100, 22);
            this.name.TabIndex = 6;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(221, 38);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(67, 16);
            this.label5.TabIndex = 11;
            this.label5.Text = "电子邮件";
            // 
            // email
            // 
            this.email.Location = new System.Drawing.Point(294, 35);
            this.email.MaxLength = 32;
            this.email.Name = "email";
            this.email.Size = new System.Drawing.Size(100, 22);
            this.email.TabIndex = 12;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(221, 92);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(52, 16);
            this.label6.TabIndex = 13;
            this.label6.Text = "手机号";
            // 
            // phone
            // 
            this.phone.Location = new System.Drawing.Point(294, 89);
            this.phone.MaxLength = 16;
            this.phone.Name = "phone";
            this.phone.Size = new System.Drawing.Size(100, 22);
            this.phone.TabIndex = 14;
            // 
            // Admintype
            // 
            this.Admintype.FormattingEnabled = true;
            this.Admintype.Items.AddRange(new object[] {
            "超级管理员",
            "管理员"});
            this.Admintype.Location = new System.Drawing.Point(524, 35);
            this.Admintype.Name = "Admintype";
            this.Admintype.Size = new System.Drawing.Size(121, 24);
            this.Admintype.TabIndex = 15;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(436, 38);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(82, 16);
            this.label7.TabIndex = 16;
            this.label7.Text = "管理员类型";
            // 
            // query
            // 
            this.query.AutoSize = true;
            this.query.Location = new System.Drawing.Point(738, 34);
            this.query.Name = "query";
            this.query.Size = new System.Drawing.Size(75, 26);
            this.query.TabIndex = 17;
            this.query.Text = "查询";
            this.query.UseVisualStyleBackColor = true;
            this.query.Click += new System.EventHandler(this.Query_Click);
            // 
            // add
            // 
            this.add.AutoSize = true;
            this.add.Location = new System.Drawing.Point(738, 88);
            this.add.Name = "add";
            this.add.Size = new System.Drawing.Size(75, 26);
            this.add.TabIndex = 18;
            this.add.Text = "添加";
            this.add.UseVisualStyleBackColor = true;
            this.add.Click += new System.EventHandler(this.Add_Click);
            // 
            // delete
            // 
            this.delete.AutoSize = true;
            this.delete.Location = new System.Drawing.Point(534, 88);
            this.delete.Name = "delete";
            this.delete.Size = new System.Drawing.Size(171, 26);
            this.delete.TabIndex = 19;
            this.delete.Text = "删除(仅当不存在记录）";
            this.delete.UseVisualStyleBackColor = true;
            this.delete.Click += new System.EventHandler(this.Delete_Click);
            // 
            // disable
            // 
            this.disable.AutoSize = true;
            this.disable.Location = new System.Drawing.Point(833, 88);
            this.disable.Name = "disable";
            this.disable.Size = new System.Drawing.Size(75, 26);
            this.disable.TabIndex = 20;
            this.disable.Text = "禁用";
            this.disable.UseVisualStyleBackColor = true;
            this.disable.Click += new System.EventHandler(this.Disable_Click);
            // 
            // modify
            // 
            this.modify.AutoSize = true;
            this.modify.Location = new System.Drawing.Point(833, 35);
            this.modify.Name = "modify";
            this.modify.Size = new System.Drawing.Size(75, 26);
            this.modify.TabIndex = 21;
            this.modify.Text = "修改";
            this.modify.UseVisualStyleBackColor = true;
            this.modify.Click += new System.EventHandler(this.Modify_Click);
            // 
            // enable
            // 
            this.enable.AutoSize = true;
            this.enable.Location = new System.Drawing.Point(932, 35);
            this.enable.Name = "enable";
            this.enable.Size = new System.Drawing.Size(75, 26);
            this.enable.TabIndex = 22;
            this.enable.Text = "启用";
            this.enable.UseVisualStyleBackColor = true;
            this.enable.Click += new System.EventHandler(this.Enable_Click);
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(22, 127);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowHeadersWidth = 51;
            this.dataGridView1.RowTemplate.Height = 24;
            this.dataGridView1.Size = new System.Drawing.Size(1000, 406);
            this.dataGridView1.TabIndex = 23;
            // 
            // AdminManage
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1067, 554);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.enable);
            this.Controls.Add(this.modify);
            this.Controls.Add(this.disable);
            this.Controls.Add(this.delete);
            this.Controls.Add(this.add);
            this.Controls.Add(this.query);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.Admintype);
            this.Controls.Add(this.phone);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.email);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.name);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.id);
            this.Controls.Add(this.label1);
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "AdminManage";
            this.Text = "人员管理";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox id;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox name;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox email;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox phone;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Button query;
        private System.Windows.Forms.Button add;
        private System.Windows.Forms.Button delete;
        private System.Windows.Forms.Button disable;
        private System.Windows.Forms.Button modify;
        private System.Windows.Forms.Button enable;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.ComboBox Admintype;
    }
}