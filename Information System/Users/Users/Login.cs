using System;
using System.Windows.Forms;
using MySql.Data.MySqlClient;

namespace Users
{
    public partial class Login : Form
    {
        public Login()
        {
            InitializeComponent();
        }

        private void loginbtn_Click(object sender, EventArgs e)
        {
            using (MySqlConnection conn = new MySqlConnection(Program.str))
            {
                conn.Open(); // 开启连接

                string sql = "SELECT COUNT(*) FROM admin_login_k WHERE admin_name = @name AND admin_pass = @pass";
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                cmd.Parameters.AddWithValue("@name", username.Text);
                cmd.Parameters.AddWithValue("@pass", pass.Text);
                int count = Convert.ToInt32(cmd.ExecuteScalar());
                if (count == 1)
                {
                    MessageBox.Show("登录成功");
                    Home home = new Home();
                    home.Show();
                    this.Hide();
                }
                else
                {
                    MessageBox.Show("登录失败");
                }

            }
        }
    }
}
