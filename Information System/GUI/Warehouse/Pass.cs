using MySql.Data.MySqlClient;
using System;
using System.Windows.Forms;

namespace Warehouse
{
    public partial class Pass : Form
    {
        public Pass()
        {
            InitializeComponent();
        }

        private void Modify_Click(object sender, EventArgs e)
        {
            try
            {
                MySqlConnection conn = new MySqlConnection(Program.str);//实例化连接
                conn.Open();//开启连接
                MySqlCommand cmd = null;
                if (newPass.Text != verify.Text)
                {
                    MessageBox.Show("两次输入的密码不一致！");
                    return;
                }
                //Read Admin_ID from Login.cs
                string before = "SELECT Password FROM admins WHERE Admin_ID='" + userId.Text + "'";
                //Execute the query
                cmd = new MySqlCommand(before, conn);
                MySqlDataReader dataReader = cmd.ExecuteReader();
                dataReader.Read();
                string password = dataReader.GetString("Password");
                dataReader.Close();
                string oldstr = "SELECT sha1('" + oldPass.Text + "')";
                MySqlCommand cmd1 = new MySqlCommand(oldstr, conn);
                MySqlDataReader dataReader1 = cmd1.ExecuteReader();
                dataReader1.Read();
                string old = dataReader1.GetString(0);
                dataReader1.Close();
                string user = userId.Text;
                if (this.userId.Text == "" || !System.Text.RegularExpressions.Regex.IsMatch(this.userId.Text, @"^[0-9]*$"))
                {
                    MessageBox.Show("ID格式错误");
                    return;
                }
                if (this.oldPass.Text == "" || System.Text.RegularExpressions.Regex.IsMatch(this.oldPass.Text, @"[']") || System.Text.RegularExpressions.Regex.IsMatch(this.oldPass.Text, @"[-][-]"))
                {
                    MessageBox.Show("原密码格式错误");
                    return;
                }
                if (this.newPass.Text == "" || System.Text.RegularExpressions.Regex.IsMatch(this.newPass.Text, @"[']") || System.Text.RegularExpressions.Regex.IsMatch(this.newPass.Text, @"[-][-]"))
                {
                    MessageBox.Show("新密码格式错误");
                    return;
                }
                if (password != old && userId.Text == Program.current)
                {
                    MessageBox.Show("原密码错误！");
                    string sql = "INSERT INTO admin_actions (Admin_ID, Action_Type, Action_Description, Action_Time) VALUES (" + Program.current + ", '修改密码', + 'ID: " + Program.current + " 的管理员修改" + user + "的密码时输入了错误的原密码', NOW())";
                    MySqlCommand cmd3 = new MySqlCommand(sql, conn);
                    cmd3.ExecuteNonQuery();
                    return;
                }
                else
                {
                    string after = "UPDATE admins SET Password=sha1('" + newPass.Text + "') WHERE Admin_ID='" + userId.Text + "'";
                    MySqlCommand cmd2 = new MySqlCommand(after, conn);
                    cmd2.ExecuteNonQuery();
                    MessageBox.Show("修改成功！");
                    this.Close();
                    string log = "INSERT INTO admin_actions (Admin_ID, Action_Type, Action_Description, Action_Time) VALUES (" + Program.current + ", '修改密码', + 'ID: " + Program.current + " 的管理员修改了" + user + "的密码', NOW())";
                    MySqlCommand cmd3 = new MySqlCommand(log, conn);
                    cmd3.ExecuteNonQuery();
                }
                conn.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}
