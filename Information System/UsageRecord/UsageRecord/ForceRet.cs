using MySql.Data.MySqlClient;
using System;
using System.Windows.Forms;

namespace UsageRecord
{
    public partial class ForceRet : Form
    {
        public ForceRet()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            using (MySqlConnection conn = new MySqlConnection(Program.str))
            {
                conn.Open();
                string checkSql = "select count(*) from UsageRecords where DeviceID = @id and Status = 0 and UserID = @uid";
                string updateSql = "update UsageRecords set Status = 1 , EndTime = @et where DeviceID = @id and Status = 0";
                MySqlCommand cmd = new MySqlCommand(checkSql, conn);
                cmd.Parameters.AddWithValue("@id", id.Text);
                cmd.Parameters.AddWithValue("@uid", user.Text);
                int count = Convert.ToInt32(cmd.ExecuteScalar());
                if (count == 0)
                {
                    MessageBox.Show("设备不存在或未被租借");
                    return;
                }
                cmd = new MySqlCommand(updateSql, conn);
                cmd.Parameters.AddWithValue("@id", id.Text);
                cmd.Parameters.AddWithValue("@et", endDate.Value);
                int affectedRows = cmd.ExecuteNonQuery();
                if (affectedRows == 0)
                {
                    MessageBox.Show("归还失败");
                    return;
                }
                MessageBox.Show("归还成功\n设备编号：" + id.Text + "\n租借人：" + Program.uid + "\n结束时间：" + endDate.Value);
            }
        }
    }
}
