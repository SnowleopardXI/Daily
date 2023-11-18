using MySql.Data.MySqlClient;
using System;
using System.Data;
using System.Windows.Forms;

namespace Warehouse
{
    public partial class Supplier : Form
    {
#pragma warning disable CS0114 // Member hides inherited member; missing override keyword
        public void Refresh()
        {
            dataGridView1.DataSource = null;
            dataGridView1.Rows.Clear();
            dataGridView1.Columns.Clear();
            MySqlConnection conn = new MySqlConnection(Program.str);
            conn.Open();
            string sql = "select Supplier_ID AS '供应商ID', Supplier_Name AS '供应商名称', Contact_Info AS '联系方式', Address AS '地址' from suppliers";
            MySqlCommand cmd = new MySqlCommand(sql, conn);
            MySqlDataAdapter da = new MySqlDataAdapter(cmd);
            DataSet ds = new DataSet();
            da.Fill(ds);
            dataGridView1.DataSource = ds.Tables[0];
            conn.Close();
        }
        public Supplier()
        {
            InitializeComponent();
        }

        private void Add_Click(object sender, EventArgs e)
        {
            MySqlConnection conn = new MySqlConnection(Program.str);
            conn.Open();
            if (supplierName.Text == "" || contact.Text == "" || address.Text == "")
            {
                MessageBox.Show("请填写完整信息");
                return;
            }
            string sql = "CALL Add_Suppliers('" + supplierName.Text + "','" + contact.Text + "','" + address.Text + "'," + Program.current + ")";
            MySqlCommand cmd = new MySqlCommand(sql, conn);
            try
            {
                cmd.ExecuteNonQuery();
                MessageBox.Show("添加成功");
                Refresh();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            conn.Close();
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
                    sql += "where Supplier_ID = @Supplier_ID or Supplier_Name = @Supplier_Name or Contact_Info = @Contact_Info or Address = @Address";
                }
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                cmd.Parameters.AddWithValue("@Supplier_ID", SupplierID.Text);
                cmd.Parameters.AddWithValue("@Supplier_Name", supplierName.Text);
                cmd.Parameters.AddWithValue("@Contact_Info", contact.Text);
                cmd.Parameters.AddWithValue("@Address", address.Text);
                MySqlDataAdapter da = new MySqlDataAdapter(cmd);
                DataSet ds = new DataSet();
                da.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];
            }
        }

        private void Modify_Click(object sender, EventArgs e)
        {
            if (SupplierID.Text == "" || supplierName.Text == "" || contact.Text == "" || address.Text == "")
            {
                MessageBox.Show("请填写完整信息");
                return;
            }
            MySqlConnection conn = new MySqlConnection(Program.str);
            conn.Open();
            string sql = "CALL Update_Supplier(@Supplier_ID,@Supplier_Name,@Contact_Info,@Address," + Program.current + ")";
            MySqlCommand cmd = new MySqlCommand(sql, conn);
            cmd.Parameters.AddWithValue("@Supplier_ID", SupplierID.Text);
            cmd.Parameters.AddWithValue("@Supplier_Name", supplierName.Text);
            cmd.Parameters.AddWithValue("@Contact_Info", contact.Text);
            cmd.Parameters.AddWithValue("@Address", address.Text);
            try
            {
                cmd.ExecuteNonQuery();
                MessageBox.Show("修改成功");
                Refresh();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            conn.Close();
        }
        private void Delete_Click(object sender, EventArgs e)
        {
            MySqlConnection conn = new MySqlConnection(Program.str);
            conn.Open();
            string sql = "CALL Delete_Supplier(@Supplier_ID," + Program.current + ")";
            MySqlCommand cmd = new MySqlCommand(sql, conn);
            cmd.Parameters.AddWithValue("@Supplier_ID", SupplierID.Text);
            try
            {
                cmd.ExecuteNonQuery();
                MessageBox.Show("删除成功");
                Refresh();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            conn.Close();
        }
    }
}
