using MySql.Data.MySqlClient;
using System;
using System.Windows.Forms;

namespace Warehouse
{
    public partial class AdminPass : Form
    {
        public AdminPass()
        {
            InitializeComponent();
        }

        private void Modify_Click(object sender, EventArgs e)
        {
            try
            {
                if (newPass.Text != verify.Text)
                {
                    MessageBox.Show("两次输入的密码不一致！");
                    return;
                }
                //Read Admin_ID from Login.cs
                string before = "SELECT Password FROM admins WHERE Admin_ID='" + Program.current + "'";
                //Execute the query
                MySqlConnection conn = new MySqlConnection(Program.str);
                conn.Open();
                MySqlCommand cmd = new MySqlCommand(before, conn);
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
                if (password != old)
                {
                    MessageBox.Show("原密码错误！");
                    return;
                }
                else
                {
                    string after = "UPDATE admins SET Password=sha1('" + newPass.Text + "') WHERE Admin_ID='" + Program.current + "'";
                    MySqlCommand cmd2 = new MySqlCommand(after, conn);
                    cmd2.ExecuteNonQuery();
                    MessageBox.Show("修改成功！");
                    this.Close();
                    string log = "INSERT INTO admin_actions (Admin_ID, Action_Type, Action_Description, Action_Time) VALUES (" + Program.current + ", '修改密码', + 'ID: " + Program.current + " 的管理员修改了密码', NOW())";
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
