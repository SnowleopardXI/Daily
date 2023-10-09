namespace Warehouse
{
    partial class OutStock
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
            this.employeeId = new System.Windows.Forms.TextBox();
            this.出库 = new System.Windows.Forms.Button();
            this.productName = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.warehouseId = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.quantity = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(33, 34);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(63, 16);
            this.label1.TabIndex = 0;
            this.label1.Text = "销售员id";
            // 
            // employeeId
            // 
            this.employeeId.Location = new System.Drawing.Point(152, 30);
            this.employeeId.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.employeeId.MaxLength = 8;
            this.employeeId.Name = "employeeId";
            this.employeeId.Size = new System.Drawing.Size(132, 22);
            this.employeeId.TabIndex = 1;
            // 
            // 出库
            // 
            this.出库.Location = new System.Drawing.Point(256, 247);
            this.出库.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.出库.Name = "出库";
            this.出库.Size = new System.Drawing.Size(100, 28);
            this.出库.TabIndex = 9;
            this.出库.Text = "出库";
            this.出库.UseVisualStyleBackColor = true;
            this.出库.Click += new System.EventHandler(this.出库_Click);
            // 
            // productName
            // 
            this.productName.Location = new System.Drawing.Point(152, 83);
            this.productName.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.productName.MaxLength = 32;
            this.productName.Name = "productName";
            this.productName.Size = new System.Drawing.Size(132, 22);
            this.productName.TabIndex = 4;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(33, 87);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(52, 16);
            this.label2.TabIndex = 3;
            this.label2.Text = "货物名";
            // 
            // warehouseId
            // 
            this.warehouseId.Location = new System.Drawing.Point(152, 140);
            this.warehouseId.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.warehouseId.MaxLength = 8;
            this.warehouseId.Name = "warehouseId";
            this.warehouseId.Size = new System.Drawing.Size(132, 22);
            this.warehouseId.TabIndex = 6;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(33, 143);
            this.label3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(52, 16);
            this.label3.TabIndex = 5;
            this.label3.Text = "仓库号";
            // 
            // quantity
            // 
            this.quantity.Location = new System.Drawing.Point(152, 192);
            this.quantity.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.quantity.MaxLength = 8;
            this.quantity.Name = "quantity";
            this.quantity.Size = new System.Drawing.Size(132, 22);
            this.quantity.TabIndex = 8;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(33, 196);
            this.label4.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(37, 16);
            this.label4.TabIndex = 7;
            this.label4.Text = "数量";
            // 
            // OutStock
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(388, 305);
            this.Controls.Add(this.quantity);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.warehouseId);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.productName);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.出库);
            this.Controls.Add(this.employeeId);
            this.Controls.Add(this.label1);
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "OutStock";
            this.Text = "商品出库";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox employeeId;
        private System.Windows.Forms.Button 出库;
        private System.Windows.Forms.TextBox productName;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox warehouseId;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox quantity;
        private System.Windows.Forms.Label label4;
    }
}