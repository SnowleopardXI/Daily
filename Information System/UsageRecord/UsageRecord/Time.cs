using MySql.Data.MySqlClient;
using System;
using System.Data;
using System.Windows.Forms;

namespace UsageRecord
{
    public partial class Time : Form
    {
        public Time()
        {
            InitializeComponent();
        }

        private void Time_Load(object sender, EventArgs e)
        {
            button1_Click(sender, e);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            using (MySqlConnection conn = new MySqlConnection(Program.str))
            {
                conn.Open(); // 开启连接
                string sql = "SELECT * FROM UserRentalInterval";
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                MySqlDataAdapter ada = new MySqlDataAdapter(cmd);
                DataSet ds = new DataSet();
                ada.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];
            }
        }
    }
}
