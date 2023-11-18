using MySql.Data.MySqlClient;
using System;
using System.Data;
using System.Windows.Forms;

namespace UsageRecord
{
    public partial class Status : Form
    {
        public Status()
        {
            InitializeComponent();
        }

        private void query_Click(object sender, EventArgs e)
        {
            using (MySqlConnection conn = new MySqlConnection(Program.str))
            {
                conn.Open();
                string sql = "select * from DeviceStatus ";
                dataGridView1.DataSource = null;
                if (type.Text == "" && name.Text == "" && deviceStat.Text == "")
                {
                    MySqlCommand cmd = new MySqlCommand(sql, conn);
                    MySqlDataAdapter ada = new MySqlDataAdapter(cmd);
                    DataSet ds = new DataSet();
                    ada.Fill(ds);
                    dataGridView1.DataSource = ds.Tables[0];
                }
                else if (deviceStat.Text != "")
                {
                    if (type.Text != "")
                    {
                        sql += "where 设备类型 = @type and 设备状态 = @deviceStat ";
                    }
                    else
                    {
                        sql += "where 设备状态 = @deviceStat ";
                    }
                    MySqlCommand cmd = new MySqlCommand(sql, conn);
                    cmd.Parameters.AddWithValue("@type", type.Text);
                    cmd.Parameters.AddWithValue("@deviceStat", deviceStat.Text);
                    MySqlDataAdapter ada = new MySqlDataAdapter(cmd);
                    DataSet ds = new DataSet();
                    dataGridView1.Rows.Clear();
                    dataGridView1.Columns.Clear();
                    ada.Fill(ds);
                    dataGridView1.DataSource = ds.Tables[0];
                }
                else if (type.Text != "")
                {
                    sql += "where 设备类型 = @type ";
                    if (name.Text != "")
                    {
                        sql += "and 设备名称 = @name ";
                    }
                    MySqlCommand cmd = new MySqlCommand(sql, conn);
                    cmd.Parameters.AddWithValue("@type", type.Text);
                    cmd.Parameters.AddWithValue("@name", name.Text);
                    MySqlDataAdapter ada = new MySqlDataAdapter(cmd);
                    DataSet ds = new DataSet();
                    dataGridView1.Rows.Clear();
                    dataGridView1.Columns.Clear();
                    ada.Fill(ds);
                    dataGridView1.DataSource = ds.Tables[0];
                }
                else
                {
                    sql += "where 设备类型 = @type or 设备名称 = @name ";
                    MySqlCommand cmd = new MySqlCommand(sql, conn);
                    cmd.Parameters.AddWithValue("@name", name.Text);
                    cmd.Parameters.AddWithValue("@type", type.Text);
                    MySqlDataAdapter ada = new MySqlDataAdapter(cmd);
                    DataSet ds = new DataSet();
                    dataGridView1.Rows.Clear();
                    dataGridView1.Columns.Clear();
                    ada.Fill(ds);
                    dataGridView1.DataSource = ds.Tables[0];
                }   
            }
        }
    }
}
