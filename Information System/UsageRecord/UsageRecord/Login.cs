using System;
using System.Windows.Forms;
using MySql.Data.MySqlClient;

namespace UsageRecord
{
    public partial class Login : Form
    {
        public Login()
        {
            InitializeComponent();
        }

        private void loginbtn_Click(object sender, EventArgs e)
        {
            if(id.Text == "" || pass.Text == "")
            {
                MessageBox.Show("请输入用户名和密码");
                return;
            }
            using (MySqlConnection conn = new MySqlConnection(Program.str))
            {
                conn.Open(); // 开启连接
                string sql = "SELECT COUNT(*) FROM Users WHERE UserID = @id AND Password = @pass AND Valid=1";
                string sql2 = "SELECT Type FROM Users WHERE UserID = @id AND Password = @pass AND Valid=1";
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                cmd.Parameters.AddWithValue("@id", id.Text);
                cmd.Parameters.AddWithValue("@pass", pass.Text);
                int count = Convert.ToInt32(cmd.ExecuteScalar());
                if (count == 1)
                {
                    Program.uid = id.Text;
                    MySqlCommand cmd2 = new MySqlCommand(sql2, conn);
                    cmd2.Parameters.AddWithValue("@id", id.Text);
                    cmd2.Parameters.AddWithValue("@pass", pass.Text);
                    string type = cmd2.ExecuteScalar().ToString();
                    if (type == "1")
                    {
                        this.Hide();
                        new Admin().Show();
                    }
                    else
                    {
                        this.Hide();
                        new User().Show();
                    }
                }
                else
                {
                    MessageBox.Show("登录失败，请检查用户名和密码或联系管理员");
                }

            }
        }
    }
}
