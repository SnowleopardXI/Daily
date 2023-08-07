using System;
using System.Windows.Forms;
using MySql.Data.MySqlClient;
namespace Warehouse
{
    public partial class InStock : Form
    {
        public InStock()
        {
            InitializeComponent();
        }
        public void Refresh()
        {
            this.productName.Text = "";
            this.supplierName.Text = "";
            this.warehouseId.Text = "";
            this.quantity.Text = "";
            this.employeeId.Text = "";
        }
        private void stockin_Click(object sender, EventArgs e)
        {
            try
            {
                if (productName.Text == "" || supplierName.Text == "" || warehouseId.Text == "" || quantity.Text == "")
                {
                    MessageBox.Show("请输入完整信息！");
                }
                else
                {
                    string sql = "CALL Add_Inventory('" + productName.Text + "','" + supplierName.Text + "','" + warehouseId.Text + "'," + quantity.Text + "," + Program.current + ")";
                    MySqlConnection conn = new MySqlConnection(Program.str);
                    conn.Open();
                    MySqlCommand cmd = new MySqlCommand(sql, conn);
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
