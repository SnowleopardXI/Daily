namespace Warehouse
{
    partial class InStock
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
            this.supplierName = new System.Windows.Forms.TextBox();
            this.stockin = new System.Windows.Forms.Button();
            this.productName = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.employeeId = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.warehouseId = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.quantity = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(29, 100);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(52, 16);
            this.label1.TabIndex = 6;
            this.label1.Text = "供应商";
            // 
            // supplierName
            // 
            this.supplierName.Location = new System.Drawing.Point(111, 96);
            this.supplierName.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.supplierName.MaxLength = 32;
            this.supplierName.Name = "supplierName";
            this.supplierName.Size = new System.Drawing.Size(196, 22);
            this.supplierName.TabIndex = 1;
            // 
            // stockin
            // 
            this.stockin.Location = new System.Drawing.Point(200, 293);
            this.stockin.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.stockin.Name = "stockin";
            this.stockin.Size = new System.Drawing.Size(108, 28);
            this.stockin.TabIndex = 5;
            this.stockin.Text = "入库";
            this.stockin.UseVisualStyleBackColor = true;
            this.stockin.Click += new System.EventHandler(this.stockin_Click);
            // 
            // productName
            // 
            this.productName.Location = new System.Drawing.Point(111, 49);
            this.productName.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.productName.MaxLength = 32;
            this.productName.Name = "productName";
            this.productName.Size = new System.Drawing.Size(196, 22);
            this.productName.TabIndex = 0;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(29, 55);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(67, 16);
            this.label2.TabIndex = 7;
            this.label2.Text = "货物名称";
            // 
            // employeeId
            // 
            this.employeeId.Location = new System.Drawing.Point(111, 246);
            this.employeeId.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.employeeId.MaxLength = 8;
            this.employeeId.Name = "employeeId";
            this.employeeId.Size = new System.Drawing.Size(196, 22);
            this.employeeId.TabIndex = 4;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(29, 255);
            this.label3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(52, 16);
            this.label3.TabIndex = 8;
            this.label3.Text = "员工号";
            // 
            // warehouseId
            // 
            this.warehouseId.Location = new System.Drawing.Point(111, 146);
            this.warehouseId.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.warehouseId.MaxLength = 8;
            this.warehouseId.Name = "warehouseId";
            this.warehouseId.Size = new System.Drawing.Size(196, 22);
            this.warehouseId.TabIndex = 2;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(29, 150);
            this.label4.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(52, 16);
            this.label4.TabIndex = 9;
            this.label4.Text = "仓库号";
            // 
            // quantity
            // 
            this.quantity.Location = new System.Drawing.Point(111, 197);
            this.quantity.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.quantity.MaxLength = 8;
            this.quantity.Name = "quantity";
            this.quantity.Size = new System.Drawing.Size(196, 22);
            this.quantity.TabIndex = 3;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(29, 206);
            this.label5.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(37, 16);
            this.label5.TabIndex = 10;
            this.label5.Text = "数量";
            // 
            // InStock
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(393, 347);
            this.Controls.Add(this.quantity);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.warehouseId);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.employeeId);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.productName);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.stockin);
            this.Controls.Add(this.supplierName);
            this.Controls.Add(this.label1);
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "InStock";
            this.Text = "商品入库";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox supplierName;
        private System.Windows.Forms.Button stockin;
        private System.Windows.Forms.TextBox productName;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox employeeId;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox warehouseId;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox quantity;
        private System.Windows.Forms.Label label5;
    }
}