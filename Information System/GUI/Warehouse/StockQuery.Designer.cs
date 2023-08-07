namespace Warehouse
{
    partial class StockQuery
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
            this.Query = new System.Windows.Forms.Button();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.Product_ID = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.Warehouse_ID = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.Product_Name = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // Query
            // 
            this.Query.Location = new System.Drawing.Point(920, 31);
            this.Query.Margin = new System.Windows.Forms.Padding(4);
            this.Query.Name = "Query";
            this.Query.Size = new System.Drawing.Size(100, 28);
            this.Query.TabIndex = 0;
            this.Query.Text = "查询";
            this.Query.UseVisualStyleBackColor = true;
            this.Query.Click += new System.EventHandler(this.Query_Click);
            // 
            // dataGridView1
            // 
            this.dataGridView1.AllowUserToAddRows = false;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(40, 123);
            this.dataGridView1.Margin = new System.Windows.Forms.Padding(4);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowHeadersWidth = 51;
            this.dataGridView1.Size = new System.Drawing.Size(980, 402);
            this.dataGridView1.TabIndex = 1;
            // 
            // Product_ID
            // 
            this.Product_ID.Location = new System.Drawing.Point(115, 27);
            this.Product_ID.Margin = new System.Windows.Forms.Padding(4);
            this.Product_ID.MaxLength = 8;
            this.Product_ID.Name = "Product_ID";
            this.Product_ID.Size = new System.Drawing.Size(132, 22);
            this.Product_ID.TabIndex = 2;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(37, 31);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(52, 16);
            this.label1.TabIndex = 3;
            this.label1.Text = "产品号";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(37, 78);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(52, 16);
            this.label2.TabIndex = 4;
            this.label2.Text = "仓库号";
            // 
            // Warehouse_ID
            // 
            this.Warehouse_ID.Location = new System.Drawing.Point(115, 78);
            this.Warehouse_ID.Margin = new System.Windows.Forms.Padding(4);
            this.Warehouse_ID.MaxLength = 8;
            this.Warehouse_ID.Name = "Warehouse_ID";
            this.Warehouse_ID.Size = new System.Drawing.Size(132, 22);
            this.Warehouse_ID.TabIndex = 5;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(335, 31);
            this.label3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(52, 16);
            this.label3.TabIndex = 7;
            this.label3.Text = "产品名";
            // 
            // Product_Name
            // 
            this.Product_Name.Location = new System.Drawing.Point(412, 27);
            this.Product_Name.Margin = new System.Windows.Forms.Padding(4);
            this.Product_Name.MaxLength = 32;
            this.Product_Name.Name = "Product_Name";
            this.Product_Name.Size = new System.Drawing.Size(132, 22);
            this.Product_Name.TabIndex = 6;
            // 
            // StockQuery
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1067, 554);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.Product_Name);
            this.Controls.Add(this.Warehouse_ID);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.Product_ID);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.Query);
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "StockQuery";
            this.Text = "库存查询";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button Query;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.TextBox Product_ID;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox Warehouse_ID;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox Product_Name;
    }
}