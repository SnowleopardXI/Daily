using MySql.Data.MySqlClient;
using System;
using System.Windows.Forms;

namespace Warehouse
{
    public partial class OutStock : Form
    {
        public OutStock()
        {
            InitializeComponent();
        }
#pragma warning disable CS0114 // Member hides inherited member; missing override keyword
        public void Refresh()
        {
            this.productName.Text = "";
            this.quantity.Text = "";
            this.warehouseId.Text = "";
            this.employeeId.Text = "";
        }

        private void 出库_Click(object sender, EventArgs e)
        {
            try
            {
                if (Convert.ToInt32(quantity.Text) <= 0)
                {
                    MessageBox.Show("出库数量必须大于0！");
                    return;
                }
                string sql = "CALL Remove_Inventory(" + Program.current + ",";
                string condition = "@productName" + "," + quantity.Text + "," + warehouseId.Text + ")";
                sql += condition;
                MySqlConnection conn = new MySqlConnection(Program.str);
                conn.Open();
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                cmd.Parameters.AddWithValue("@productName", productName.Text);
                cmd.ExecuteNonQuery();
                conn.Close();
                MessageBox.Show("出库成功");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}
