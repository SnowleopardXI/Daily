using MySql.Data.MySqlClient;
using System;
using System.Data;
using System.Windows.Forms;

namespace Warehouse
{
    public partial class SupplierView : Form
    {
#pragma warning disable CS0114 // Member hides inherited member; missing override keyword
        public SupplierView()
        {
            InitializeComponent();
        }
        private void Query_Click(object sender, EventArgs e)
        {
            MySqlConnection conn = new MySqlConnection(Program.str);
            conn.Open();
            if (SupplierID.Text == "" && supplierName.Text == "" && contact.Text == "" && address.Text == "")
            {
                string sql = "select Supplier_ID AS '供应商ID', Supplier_Name AS '供应商名称', Contact_Info AS '联系方式', Address AS '地址' from suppliers";
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                MySqlDataAdapter da = new MySqlDataAdapter(cmd);
                DataSet ds = new DataSet();
                da.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];
            }
            else
            {
                string sql = "select Supplier_ID AS '供应商ID', Supplier_Name AS '供应商名称', Contact_Info AS '联系方式', Address AS '地址' from suppliers ";
                if (SupplierID.Text != "" || supplierName.Text != "" || contact.Text != "" || address.Text != "")
                {
                    sql += "where Supplier_ID = " + SupplierID.Text + " or Supplier_Name = @Supplier_Name or Contact_Info = @Contact_Info or Address = @Address";
                }
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                cmd.Parameters.AddWithValue("@Supplier_Name", supplierName.Text);
                cmd.Parameters.AddWithValue("@Contact_Info", contact.Text);
                cmd.Parameters.AddWithValue("@Address", address.Text);
                MySqlDataAdapter da = new MySqlDataAdapter(cmd);
                DataSet ds = new DataSet();
                da.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];
            }
        }
    }
}
