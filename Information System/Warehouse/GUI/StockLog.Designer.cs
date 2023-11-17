namespace Warehouse
{
    partial class StockLog
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
            this.operateType = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.query = new System.Windows.Forms.Button();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // operateType
            // 
            this.operateType.FormattingEnabled = true;
            this.operateType.Items.AddRange(new object[] {
            "不限",
            "入库",
            "出库"});
            this.operateType.Location = new System.Drawing.Point(118, 38);
            this.operateType.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.operateType.Name = "operateType";
            this.operateType.Size = new System.Drawing.Size(160, 24);
            this.operateType.TabIndex = 7;
            this.operateType.SelectedIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(37, 42);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(67, 16);
            this.label1.TabIndex = 6;
            this.label1.Text = "操作类型";
            // 
            // query
            // 
            this.query.Location = new System.Drawing.Point(815, 38);
            this.query.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.query.Name = "query";
            this.query.Size = new System.Drawing.Size(100, 28);
            this.query.TabIndex = 5;
            this.query.Text = "查询";
            this.query.UseVisualStyleBackColor = true;
            this.query.Click += new System.EventHandler(this.Query_Click);
            // 
            // dataGridView1
            // 
            this.dataGridView1.AllowUserToAddRows = false;
            this.dataGridView1.AllowUserToOrderColumns = true;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(37, 86);
            this.dataGridView1.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowHeadersWidth = 51;
            this.dataGridView1.Size = new System.Drawing.Size(878, 410);
            this.dataGridView1.TabIndex = 4;
            // 
            // StockLog
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(967, 539);
            this.Controls.Add(this.operateType);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.query);
            this.Controls.Add(this.dataGridView1);
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "StockLog";
            this.Text = "库存日志";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox operateType;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button query;
        private System.Windows.Forms.DataGridView dataGridView1;
    }
}