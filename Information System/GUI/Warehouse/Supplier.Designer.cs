namespace Warehouse
{
    partial class Supplier
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
            this.id = new System.Windows.Forms.Label();
            this.SupplierID = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.supplierName = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.contact = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.address = new System.Windows.Forms.TextBox();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.add = new System.Windows.Forms.Button();
            this.modify = new System.Windows.Forms.Button();
            this.delete = new System.Windows.Forms.Button();
            this.query = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // id
            // 
            this.id.AutoSize = true;
            this.id.Location = new System.Drawing.Point(43, 36);
            this.id.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.id.Name = "id";
            this.id.Size = new System.Drawing.Size(65, 16);
            this.id.TabIndex = 0;
            this.id.Text = "供应商ID";
            // 
            // SupplierID
            // 
            this.SupplierID.Location = new System.Drawing.Point(135, 32);
            this.SupplierID.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.SupplierID.MaxLength = 8;
            this.SupplierID.Name = "SupplierID";
            this.SupplierID.Size = new System.Drawing.Size(132, 22);
            this.SupplierID.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(368, 36);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(67, 16);
            this.label1.TabIndex = 2;
            this.label1.Text = "供应商名";
            // 
            // supplierName
            // 
            this.supplierName.Location = new System.Drawing.Point(452, 32);
            this.supplierName.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.supplierName.MaxLength = 32;
            this.supplierName.Name = "supplierName";
            this.supplierName.Size = new System.Drawing.Size(132, 22);
            this.supplierName.TabIndex = 3;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(43, 96);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(67, 16);
            this.label2.TabIndex = 4;
            this.label2.Text = "联系信息";
            // 
            // contact
            // 
            this.contact.Location = new System.Drawing.Point(135, 96);
            this.contact.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.contact.MaxLength = 64;
            this.contact.Name = "contact";
            this.contact.Size = new System.Drawing.Size(132, 22);
            this.contact.TabIndex = 5;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(368, 100);
            this.label3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(37, 16);
            this.label3.TabIndex = 6;
            this.label3.Text = "地址";
            // 
            // address
            // 
            this.address.Location = new System.Drawing.Point(452, 96);
            this.address.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.address.MaxLength = 64;
            this.address.Name = "address";
            this.address.Size = new System.Drawing.Size(132, 22);
            this.address.TabIndex = 7;
            // 
            // dataGridView1
            // 
            this.dataGridView1.AllowUserToAddRows = false;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(28, 140);
            this.dataGridView1.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowHeadersWidth = 51;
            this.dataGridView1.Size = new System.Drawing.Size(1340, 571);
            this.dataGridView1.TabIndex = 8;
            // 
            // add
            // 
            this.add.Location = new System.Drawing.Point(1131, 30);
            this.add.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.add.Name = "add";
            this.add.Size = new System.Drawing.Size(100, 28);
            this.add.TabIndex = 9;
            this.add.Text = "添加";
            this.add.UseVisualStyleBackColor = true;
            this.add.Click += new System.EventHandler(this.add_Click);
            // 
            // modify
            // 
            this.modify.Location = new System.Drawing.Point(1131, 92);
            this.modify.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.modify.Name = "modify";
            this.modify.Size = new System.Drawing.Size(100, 28);
            this.modify.TabIndex = 10;
            this.modify.Text = "修改";
            this.modify.UseVisualStyleBackColor = true;
            this.modify.Click += new System.EventHandler(this.modify_Click);
            // 
            // delete
            // 
            this.delete.Location = new System.Drawing.Point(1268, 30);
            this.delete.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.delete.Name = "delete";
            this.delete.Size = new System.Drawing.Size(100, 28);
            this.delete.TabIndex = 11;
            this.delete.Text = "删除";
            this.delete.UseVisualStyleBackColor = true;
            this.delete.Click += new System.EventHandler(this.delete_Click);
            // 
            // query
            // 
            this.query.Location = new System.Drawing.Point(1268, 90);
            this.query.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.query.Name = "query";
            this.query.Size = new System.Drawing.Size(100, 28);
            this.query.TabIndex = 12;
            this.query.Text = "查询";
            this.query.UseVisualStyleBackColor = true;
            this.query.Click += new System.EventHandler(this.query_Click);
            // 
            // Supplier
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1401, 742);
            this.Controls.Add(this.query);
            this.Controls.Add(this.delete);
            this.Controls.Add(this.modify);
            this.Controls.Add(this.add);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.address);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.contact);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.supplierName);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.SupplierID);
            this.Controls.Add(this.id);
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "Supplier";
            this.Text = "供应商管理";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label id;
        private System.Windows.Forms.TextBox SupplierID;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox supplierName;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox contact;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox address;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.Button add;
        private System.Windows.Forms.Button modify;
        private System.Windows.Forms.Button delete;
        private System.Windows.Forms.Button query;
    }
}