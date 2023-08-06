using MySql.Data.MySqlClient;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Warehouse
{
    public partial class WarehouseInfo : Form
    {
        public WarehouseInfo()
        {
            InitializeComponent();
        }
        public void Refresh()
        {
            this.id.Text="";
            this.name.Text = "";
            this.addr.Text = "";
            this.contact.Text = "";
            dataGridView1.DataSource = null;
            dataGridView1.Rows.Clear();
            dataGridView1.Columns.Clear();
            string sql = "select * from warehouses";
            MySqlConnection conn = new MySqlConnection(Program.str);
            conn.Open();
            MySqlCommand cmd = new MySqlCommand(sql, conn);
            MySqlDataAdapter ada = new MySqlDataAdapter(cmd);
            DataSet ds = new DataSet();
            ada.Fill(ds);
            dataGridView1.DataSource = ds.Tables[0];
            conn.Close();
        }
        private void add_Click(object sender, EventArgs e)
        {
            try
            {
                string sql = "";
                if (name.Text == "" || addr.Text == "" || contact.Text == "")
                {
                    MessageBox.Show("请填写完整信息");
                    return;
                }
                sql = "CALL Add_Warehouse('" + name.Text + "','" + addr.Text + "','" + contact.Text + "'," + Program.current + ")";
                MySqlConnection conn = new MySqlConnection(Program.str);
                conn.Open();
                MySqlCommand cmd = new MySqlCommand(sql, conn);
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

        private void delete_Click(object sender, EventArgs e)
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

        private void modify_Click(object sender, EventArgs e)
        {
            try
            {
                string sql = "";
                if (id.Text == "" || name.Text == "" || addr.Text == "" || contact.Text == "")
                {
                    MessageBox.Show("请填写完整信息");
                    return;
                }
                sql = "CALL Update_Warehouse(" + id.Text + ",'" + name.Text + "','" + addr.Text + "','" + contact.Text + "'," + Program.current + ")";
                MySqlConnection conn = new MySqlConnection(Program.str);
                conn.Open();
                MySqlCommand cmd = new MySqlCommand(sql, conn);
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

        private void query_Click(object sender, EventArgs e)
        {
            try
            {
                string sql = "";
                if(id.Text == "" && name.Text == "" && addr.Text == "" && contact.Text == "")
                sql= "select * from warehouses";
                else
                {
                    sql = "select * from warehouses where ";
                    if (id.Text != "")
                        sql += "Warehouse_ID = '" + id.Text + "' and ";
                    if (name.Text != "")
                        sql += "Warehouse_Name = '" + name.Text + "' and ";
                    if (addr.Text != "")
                        sql += "Warehouse_Location = '" + addr.Text + "' and ";
                    if (contact.Text != "")
                        sql += "Warehouse_Contact = '" + contact.Text + "' and ";
                    sql = sql.Substring(0, sql.Length - 5);
                }
                MySqlConnection conn = new MySqlConnection(Program.str);
                conn.Open();
                MySqlCommand cmd = new MySqlCommand(sql, conn);
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
