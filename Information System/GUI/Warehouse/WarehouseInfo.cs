using MySql.Data.MySqlClient;
using System;
using System.Data;
using System.Windows.Forms;

namespace Warehouse
{
    public partial class WarehouseInfo : Form
    {
        public WarehouseInfo()
        {
            InitializeComponent();
        }
#pragma warning disable CS0114 // Member hides inherited member; missing override keyword
        public void Refresh()
        {
            this.id.Text = "";
            this.name.Text = "";
            this.addr.Text = "";
            this.contact.Text = "";
            dataGridView1.DataSource = null;
            dataGridView1.Rows.Clear();
            dataGridView1.Columns.Clear();
            string sql = "select Warehouse_ID AS '仓库编号', Warehouse_Location AS '仓库地址', Warehouse_Name AS '仓库名称', Warehouse_Contact AS '仓库联系方式' from warehouses";
            MySqlConnection conn = new MySqlConnection(Program.str);
            conn.Open();
            MySqlCommand cmd = new MySqlCommand(sql, conn);
            MySqlDataAdapter ada = new MySqlDataAdapter(cmd);
            DataSet ds = new DataSet();
            ada.Fill(ds);
            dataGridView1.DataSource = ds.Tables[0];
            conn.Close();
        }
        private void Add_Click(object sender, EventArgs e)
        {
            try
            {
                string sql = "";
                if (name.Text == "" || addr.Text == "" || contact.Text == "")
                {
                    MessageBox.Show("请填写完整信息");
                    return;
                }
                sql = "CALL Add_Warehouse(@name,@addr,@contact," + Program.current + ")";
                MySqlConnection conn = new MySqlConnection(Program.str);
                conn.Open();
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                cmd.Parameters.AddWithValue("name", name.Text);
                cmd.Parameters.AddWithValue("addr", addr.Text);
                cmd.Parameters.AddWithValue("contact", contact.Text);
                cmd.ExecuteNonQuery();
                conn.Close();
                MessageBox.Show("添加成功");
                Refresh();

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void Delete_Click(object sender, EventArgs e)
        {
            try
            {
                string sql = "";
                if (id.Text == "")
                {
                    MessageBox.Show("请填写完整信息");
                    return;
                }
                sql = "CALL Delete_Warehouse(" + id.Text + "," + Program.current + ")";
                MySqlConnection conn = new MySqlConnection(Program.str);
                conn.Open();
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                cmd.ExecuteNonQuery();
                conn.Close();
                MessageBox.Show("删除成功");
                Refresh();

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void Modify_Click(object sender, EventArgs e)
        {
            try
            {
                string sql = "";
                if (id.Text == "" || name.Text == "" || addr.Text == "" || contact.Text == "")
                {
                    MessageBox.Show("请填写完整信息");
                    return;
                }
                sql = "CALL Update_Warehouse(" + id.Text + ",@name,@addr,@contact," + Program.current + ")";
                MySqlConnection conn = new MySqlConnection(Program.str);
                conn.Open();
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                cmd.Parameters.AddWithValue("name", name.Text);
                cmd.Parameters.AddWithValue("addr", addr.Text);
                cmd.Parameters.AddWithValue("contact", contact.Text);
                cmd.ExecuteNonQuery();
                conn.Close();
                MessageBox.Show("修改成功");
                Refresh();

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void Query_Click(object sender, EventArgs e)
        {
            try
            {
                string sql = "select Warehouse_ID AS '仓库编号', Warehouse_Location AS '仓库地址', Warehouse_Name AS '仓库名称', Warehouse_Contact AS '仓库联系方式' from warehouses";
                if (id.Text != "" || name.Text != "" || addr.Text != "" || contact.Text != "")
                    sql += " where Warehouse_ID = @id or Warehouse_Name = @name or Warehouse_Location = @addr or Warehouse_Contact = @contact";
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
