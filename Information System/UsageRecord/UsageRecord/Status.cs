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
                    
                    if (deviceStat.Text == "占用")
                    {
                        sql += "where 设备状态 = '占用'";
                    }
                    else if (deviceStat.Text == "可用")
                    {
                        sql += "where 设备状态 = '可用'";
                    }
                    else sql += "";
                    MySqlCommand cmd = new MySqlCommand(sql, conn);
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
