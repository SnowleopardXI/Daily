using MySql.Data.MySqlClient;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices.ComTypes;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace UsageRecord
{
    public partial class Booked : Form
    {
        public Booked()
        {
            InitializeComponent();
        }

        private void reload_Click(object sender, EventArgs e)
        {
            using (MySqlConnection conn = new MySqlConnection(Program.str))
            {
                conn.Open();
                string sql = "select RecordID AS 记录ID, DeviceID AS 设备ID, UserID AS 用户ID, StartTime AS 开始时间, EndTime AS 结束时间 from UsageRecords where UserID = " + Program.uid + " and Status = 0";
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                MySqlDataAdapter adapter = new MySqlDataAdapter(cmd);
                DataSet ds = new DataSet();
                adapter.Fill(ds);
                // Clear datagridview
                dataGridView1.DataSource = null;
                dataGridView1.Rows.Clear();
                dataGridView1.Refresh();
                // Add data to datagridview
                dataGridView1.DataSource = ds.Tables[0];
                conn.Close();
            }
        }

        private void Booked_Load(object sender, EventArgs e)
        {
            reload_Click(sender, e);
        }
    }
}
