using System.Windows.Forms;

namespace Warehouse
{
    partial class SupplierView
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
            this.query = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // id
            // 
            this.id.AutoSize = true;
            this.id.Location = new System.Drawing.Point(48, 45);
            this.id.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.id.Name = "id";
            this.id.Size = new System.Drawing.Size(74, 20);
            this.id.TabIndex = 0;
            this.id.Text = "供应商ID";
            // 
            // SupplierID
            // 
            this.SupplierID.Location = new System.Drawing.Point(152, 40);
            this.SupplierID.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.SupplierID.MaxLength = 8;
            this.SupplierID.Name = "SupplierID";
            this.SupplierID.Size = new System.Drawing.Size(148, 26);
            this.SupplierID.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(414, 45);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(73, 20);
            this.label1.TabIndex = 2;
            this.label1.Text = "供应商名";
            // 
            // supplierName
            // 
            this.supplierName.Location = new System.Drawing.Point(508, 40);
            this.supplierName.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.supplierName.MaxLength = 32;
            this.supplierName.Name = "supplierName";
            this.supplierName.Size = new System.Drawing.Size(148, 26);
            this.supplierName.TabIndex = 3;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(48, 120);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(73, 20);
            this.label2.TabIndex = 4;
            this.label2.Text = "联系信息";
            // 
            // contact
            // 
            this.contact.Location = new System.Drawing.Point(152, 120);
            this.contact.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.contact.MaxLength = 64;
            this.contact.Name = "contact";
            this.contact.Size = new System.Drawing.Size(148, 26);
            this.contact.TabIndex = 5;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(414, 125);
            this.label3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(41, 20);
            this.label3.TabIndex = 6;
            this.label3.Text = "地址";
            // 
            // address
            // 
            this.address.Location = new System.Drawing.Point(508, 120);
            this.address.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.address.MaxLength = 64;
            this.address.Name = "address";
            this.address.Size = new System.Drawing.Size(148, 26);
            this.address.TabIndex = 7;
            // 
            // dataGridView1
            // 
            this.dataGridView1.AllowUserToAddRows = false;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(32, 175);
            this.dataGridView1.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowHeadersWidth = 51;
            this.dataGridView1.Size = new System.Drawing.Size(1508, 714);
            this.dataGridView1.TabIndex = 8;
            // 
            // query
            // 
            this.query.Location = new System.Drawing.Point(1404, 38);
            this.query.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.query.Name = "query";
            this.query.Size = new System.Drawing.Size(112, 35);
            this.query.TabIndex = 12;
            this.query.Text = "查询";
            this.query.UseVisualStyleBackColor = true;
            this.query.Click += new System.EventHandler(this.Query_Click);
            // 
            // SupplierView
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1576, 928);
            this.Controls.Add(this.query);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.address);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.contact);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.supplierName);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.SupplierID);
            this.Controls.Add(this.id);
            this.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.Name = "SupplierView";
            this.Text = "供应商信息查询";
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
        private System.Windows.Forms.Button query;
        private void SupplierID_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsDigit(e.KeyChar) && !char.IsControl(e.KeyChar))
            {
                e.Handled = true;
            }
        }
    }
}