using MySql.Data.MySqlClient;
using System;
using System.Windows.Forms;

namespace UsageRecord
{
    public partial class Pass : Form
    {
        public Pass()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            using (MySqlConnection conn = new MySqlConnection(Program.str))
            {
                if (newPass.Text != ver.Text)
                {
                    MessageBox.Show("两次输入的密码不一致");
                    return;
                }
                conn.Open();
                string sql = "select count(*) from Users where UserID = @id ";
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                cmd.Parameters.AddWithValue("@id", id.Text);
                int count = Convert.ToInt32(cmd.ExecuteScalar());
                if (count == 0)
                {
                    MessageBox.Show("用户不存在");
                    return;
                }
                sql = "update Users set Password = @pass where UserID = @id ";
                cmd = new MySqlCommand(sql, conn);
                cmd.Parameters.AddWithValue("@pass", newPass.Text);
                cmd.Parameters.AddWithValue("@id", id.Text);
                cmd.ExecuteNonQuery();
                MessageBox.Show("修改成功");
            }
        }
    }
}
