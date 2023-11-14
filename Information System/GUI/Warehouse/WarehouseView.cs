using MySql.Data.MySqlClient;
using System;
using System.Data;
using System.Windows.Forms;
#pragma warning disable CS0114 // Member hides inherited member; missing override keyword
namespace Warehouse
{
    public partial class WarehouseView : Form
    {
        public WarehouseView()
        {
            InitializeComponent();
        }

        private void Query_Click(object sender, EventArgs e)
        {
            try
            {
                string sql = "select * from warehouse_view";
                if (id.Text != "" || name.Text != "" || addr.Text != "" || contact.Text != "")
                    sql += " where 仓库编号 = @id or 仓库名称 = @name or 仓库地址 = @addr or 仓库联系方式 = @contact";
                MySqlConnection conn = new MySqlConnection(Program.str);
                conn.Open();
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                cmd.Parameters.AddWithValue("id", id.Text);
                cmd.Parameters.AddWithValue("name", name.Text);
                cmd.Parameters.AddWithValue("addr", addr.Text);
                cmd.Parameters.AddWithValue("contact", contact.Text);
                MySqlDataAdapter ada = new MySqlDataAdapter(cmd);
                DataSet ds = new DataSet();
                ada.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];
                conn.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}
