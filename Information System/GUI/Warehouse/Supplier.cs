using MySql.Data.MySqlClient;
using System;
using System.Data;
using System.Windows.Forms;

namespace Warehouse
{
    public partial class Supplier : Form
    {
        public void Refresh()
        {
            dataGridView1.DataSource = null;
            dataGridView1.Rows.Clear();
            dataGridView1.Columns.Clear();
            MySqlConnection conn = new MySqlConnection(Program.str);
            conn.Open();
            string sql = "select Supplier_ID AS '供应商ID', Supplier_Name AS '供应商名称', Contact_Info AS '联系方式', Address AS '地址' from Suppliers";
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

        private void add_Click(object sender, EventArgs e)
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

        private void query_Click(object sender, EventArgs e)
        {
            MySqlConnection conn = new MySqlConnection(Program.str);
            conn.Open();
            if (SupplierID.Text == "" && supplierName.Text == "" && contact.Text == "" && address.Text == "")
            {
                string sql = "select Supplier_ID AS '供应商ID', Supplier_Name AS '供应商名称', Contact_Info AS '联系方式', Address AS '地址' from Suppliers";
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                MySqlDataAdapter da = new MySqlDataAdapter(cmd);
                DataSet ds = new DataSet();
                da.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];
            }
            else
            {
                string sql = "select Supplier_ID AS '供应商ID', Supplier_Name AS '供应商名称', Contact_Info AS '联系方式', Address AS '地址' from Suppliers where ";
                if (SupplierID.Text != "")
                {
                    sql += "Supplier_ID = " + SupplierID.Text + " and ";
                }
                if (supplierName.Text != "")
                {
                    sql += "Supplier_Name = '" + supplierName.Text + "' and ";
                }
                if (contact.Text != "")
                {
                    sql += "Contact_Info = '" + contact.Text + "' and ";
                }
                if (address.Text != "")
                {
                    sql += "Address = '" + address.Text + "' and ";
                }
                sql = sql.Substring(0, sql.Length - 4);
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                MySqlDataAdapter da = new MySqlDataAdapter(cmd);
                DataSet ds = new DataSet();
                da.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];
            }
        }

        private void modify_Click(object sender, EventArgs e)
        {
            if (SupplierID.Text == "" || (supplierName.Text == "" && contact.Text == "" && address.Text == ""))
            {
                MessageBox.Show("请填写完整信息");
                return;
            }
            MySqlConnection conn = new MySqlConnection(Program.str);
            conn.Open();
            string sql = "";
            if(supplierName.Text != "" && contact.Text == "" && address.Text == "")
            sql="CALL Update_Supplier_Name(" + SupplierID.Text + ",'" + supplierName.Text + "'," + Program.current + ")";
            if(supplierName.Text == "" && contact.Text != "" && address.Text == "")
                sql="CALL Update_Supplier_Contact(" + SupplierID.Text + ",'" + contact.Text + "'," + Program.current + ")";
            else if(supplierName.Text == "" && contact.Text == "" && address.Text != "")
                sql="CALL Update_Supplier_Address(" + SupplierID.Text + ",'" + address.Text + "'," + Program.current + ")";
            else if(supplierName.Text != "" && contact.Text != "" && address.Text == "")
                sql="CALL Update_Supplier_Name_Contact(" + SupplierID.Text + ",'" + supplierName.Text + "','" + contact.Text + "'," + Program.current + ")";
            else if(supplierName.Text != "" && contact.Text == "" && address.Text != "")
                sql="CALL Update_Supplier_Name_Address(" + SupplierID.Text + ",'" + supplierName.Text + "','" + address.Text + "'," + Program.current + ")";
            else if(supplierName.Text == "" && contact.Text != "" && address.Text != "")
                sql="CALL Update_Supplier_Contact_Address(" + SupplierID.Text + ",'" + contact.Text + "','" + address.Text + "'," + Program.current + ")";
            else if(supplierName.Text != "" && contact.Text != "" && address.Text != "")
             sql = "CALL Update_Supplier(" + SupplierID.Text + ",'" + supplierName.Text + "','" + contact.Text + "','" + address.Text + "'," + Program.current + ")";
            MySqlCommand cmd = new MySqlCommand(sql, conn);
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
        private void delete_Click(object sender, EventArgs e)
        {
            MySqlConnection conn = new MySqlConnection(Program.str);
            conn.Open();
            string sql = "CALL Delete_Supplier(" + SupplierID.Text + "," + Program.current + ")";
            MySqlCommand cmd = new MySqlCommand(sql, conn);
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
