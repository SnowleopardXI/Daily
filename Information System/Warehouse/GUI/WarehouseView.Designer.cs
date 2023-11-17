using System.Windows.Forms;

namespace Warehouse
{
    partial class WarehouseView
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
            this.query = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.id = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.addr = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.name = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.contact = new System.Windows.Forms.TextBox();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // query
            // 
            this.query.Location = new System.Drawing.Point(1019, 33);
            this.query.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.query.Name = "query";
            this.query.Size = new System.Drawing.Size(112, 35);
            this.query.TabIndex = 3;
            this.query.Text = "查询";
            this.query.UseVisualStyleBackColor = true;
            this.query.Click += new System.EventHandler(this.Query_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(39, 40);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(53, 20);
            this.label1.TabIndex = 4;
            this.label1.Text = "仓库id";
            // 
            // id
            // 
            this.id.Location = new System.Drawing.Point(112, 35);
            this.id.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.id.MaxLength = 8;
            this.id.Name = "id";
            this.id.Size = new System.Drawing.Size(148, 26);
            this.id.TabIndex = 5;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(296, 40);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(73, 20);
            this.label2.TabIndex = 6;
            this.label2.Text = "仓库位置";
            // 
            // addr
            // 
            this.addr.Location = new System.Drawing.Point(400, 35);
            this.addr.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.addr.MaxLength = 64;
            this.addr.Name = "addr";
            this.addr.Size = new System.Drawing.Size(306, 26);
            this.addr.TabIndex = 7;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(39, 114);
            this.label3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(57, 20);
            this.label3.TabIndex = 8;
            this.label3.Text = "仓库名";
            // 
            // name
            // 
            this.name.Location = new System.Drawing.Point(112, 109);
            this.name.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.name.MaxLength = 32;
            this.name.Name = "name";
            this.name.Size = new System.Drawing.Size(148, 26);
            this.name.TabIndex = 9;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(296, 114);
            this.label4.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(73, 20);
            this.label4.TabIndex = 10;
            this.label4.Text = "联系方式";
            // 
            // contact
            // 
            this.contact.Location = new System.Drawing.Point(400, 109);
            this.contact.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.contact.MaxLength = 64;
            this.contact.Name = "contact";
            this.contact.Size = new System.Drawing.Size(306, 26);
            this.contact.TabIndex = 11;
            // 
            // dataGridView1
            // 
            this.dataGridView1.AllowUserToAddRows = false;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(27, 159);
            this.dataGridView1.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowHeadersWidth = 51;
            this.dataGridView1.Size = new System.Drawing.Size(1135, 499);
            this.dataGridView1.TabIndex = 12;
            // 
            // WarehouseView
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1200, 692);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.contact);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.name);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.addr);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.id);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.query);
            this.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.Name = "WarehouseView";
            this.Text = "仓库信息查询";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Button query;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox id;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox addr;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox name;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox contact;
        private System.Windows.Forms.DataGridView dataGridView1;
        private void id_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsDigit(e.KeyChar) && !char.IsControl(e.KeyChar))
            {
                e.Handled = true;
            }
        }
    }
}