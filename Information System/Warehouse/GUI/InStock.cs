using MySql.Data.MySqlClient;
using System;
using System.Windows.Forms;
namespace Warehouse
{
    public partial class InStock : Form
    {
        public InStock()
        {
            InitializeComponent();
        }
#pragma warning disable CS0114 // Member hides inherited member; missing override keyword
        private void Stockin_Click(object sender, EventArgs e)
        {
            try
            {
                if (productName.Text == "" || supplierName.Text == "" || warehouseId.Text == "" || quantity.Text == "")
                {
                    MessageBox.Show("请输入完整信息！");
                }
                else
                {
                    string sql = "CALL Add_Inventory(@productName,@supplierName,@warehouseId,@quantity," + employeeId.Text + ")";
                    MySqlConnection conn = new MySqlConnection(Program.str);
                    conn.Open();
                    if (Convert.ToInt32(quantity.Text) <= 0)
                    {
                        MessageBox.Show("入库数量必须大于0！");
                        return;
                    }
                    MySqlCommand cmd = new MySqlCommand(sql, conn);
                    cmd.Parameters.AddWithValue("@productName", productName.Text);
                    cmd.Parameters.AddWithValue("@supplierName", supplierName.Text);
                    cmd.Parameters.AddWithValue("@warehouseId", warehouseId.Text);
                    cmd.Parameters.AddWithValue("@quantity", quantity.Text);
                    cmd.ExecuteNonQuery();
                    conn.Close();
                    MessageBox.Show("入库成功！");
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}
