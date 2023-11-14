using MySql.Data.MySqlClient;
using System;
using System.Data;
using System.Windows.Forms;

namespace Warehouse
{
    public partial class StockQuery : Form
    {
        public StockQuery()
        {
            InitializeComponent();
        }
#pragma warning disable CS0114 // Member hides inherited member; missing override keyword
        public void Refresh()
        {
            this.Product_ID.Text = "";
            this.Product_Name.Text = "";
            this.Warehouse_ID.Text = "";
            dataGridView1.DataSource = null;
            dataGridView1.Rows.Clear();
            dataGridView1.Columns.Clear();
            string sql = "SELECT * FROM inv_view";
            MySqlConnection conn = new MySqlConnection(Program.str);
            conn.Open();
            MySqlDataAdapter adapter = new MySqlDataAdapter(sql, conn);
            DataSet ds = new DataSet();
            adapter.Fill(ds);
            dataGridView1.DataSource = ds.Tables[0];
            conn.Close();
        }
        private void Query_Click(object sender, EventArgs e)
        {
            MySqlConnection conn = new MySqlConnection(Program.str);
            conn.Open();
            string sql = "SELECT * FROM inv_view";
            //判断产品号、产品名称、仓库号是否为空
            if (Product_ID.Text != "" || Product_Name.Text != "" || Warehouse_ID.Text != "")
            { 
                sql += " WHERE 产品ID = @Product_ID or 仓库ID = @Warehouse_ID or 产品名 = @Product_Name";
            }
            MySqlCommand cmd = new MySqlCommand(sql, conn);
            cmd.Parameters.AddWithValue("Product_ID", Product_ID.Text);
            cmd.Parameters.AddWithValue("Warehouse_ID", Warehouse_ID.Text);
            cmd.Parameters.AddWithValue("Product_Name", Product_Name.Text);
            MySqlDataAdapter da = new MySqlDataAdapter(cmd);
            DataSet ds = new DataSet();
            da.Fill(ds);
            dataGridView1.DataSource = ds.Tables[0].DefaultView;
            conn.Close();
        }
    }
}