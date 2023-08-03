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

        private void stockin_Click(object sender, EventArgs e)
        {
            if(productName.Text==""||supplierName.Text==""||warehouseId.Text==""||quantity.Text=="")
            {
                MessageBox.Show("请输入完整信息！");
            }
            else
            {
                string sql = "CALL Add_Inventory('" + productName.Text + "','" + supplierName.Text + "','" + warehouseId.Text + "'," + quantity.Text + ","+Program.current+")";
                MySqlConnection conn = new MySqlConnection(Program.str);
                conn.Open();
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                cmd.ExecuteNonQuery();
                conn.Close();
                MessageBox.Show("入库成功！");
            }
        }
    }
}
