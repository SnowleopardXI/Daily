using MySql.Data.MySqlClient;
using System;
using System.Linq;
using System.Windows.Forms;
namespace Warehouse
{
    public partial class Login : Form
    {
        public string password = "";
        public Login()
        {
            InitializeComponent();
        }
        bool IsContinuousZeros(string password)
        {
            return password.All(c => c == '0');
        }
        private void Login_Button_Click(object sender, EventArgs e)
        {
            try
            {
                Program.current = this.id.Text;
                password = this.pass.Text;
                string connectionString = Program.str; // 数据库连接字符串
                using (MySqlConnection conn = new MySqlConnection(connectionString))
                {
                    conn.Open(); // 开启连接
                    string sql = "SELECT count(*) FROM admins WHERE Admin_ID = @id";
                    MySqlCommand cmd = new MySqlCommand(sql, conn);
                    cmd.Parameters.AddWithValue("@id", int.Parse(Program.current));

                    // 判断用户是否存在
                    if (Convert.ToInt32(cmd.ExecuteScalar()) == 0)
                    {
                        MessageBox.Show("用户不存在");
                        return;
                    }
                    cmd.Dispose();
                    // 判断用户是否被禁用
                    sql = "SELECT Valid FROM admins WHERE Admin_ID = @id";
                    cmd = new MySqlCommand(sql, conn);
                    cmd.Parameters.AddWithValue("@id", int.Parse(Program.current));
                    cmd.Dispose();
                    if (Convert.ToInt32(cmd.ExecuteScalar()) == 0)
                    {
                        MessageBox.Show("用户已被禁用");
                        sql = "INSERT into admin_actions(Admin_ID, Action_Type, Action_Description, Action_Time) VALUES(@id, '登录', 'ID : " + Program.current + " 用户已被禁用，无法登录系统', @actionTime)";
                        cmd = new MySqlCommand(sql, conn);
                        cmd.Parameters.AddWithValue("@id", int.Parse(Program.current));
                        cmd.Parameters.AddWithValue("@actionTime", DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss"));
                        cmd.ExecuteNonQuery();
                        cmd.Dispose();
                        return;
                    }
                    sql = "SELECT COUNT(*) FROM admins WHERE Admin_ID = @id AND Password = sha1(@password)";
                    cmd = new MySqlCommand(sql, conn);
                    cmd.Parameters.AddWithValue("@id", int.Parse(Program.current));
                    cmd.Parameters.AddWithValue("@password", password);
                    if (IsContinuousZeros(password))
                    {
                        MessageBox.Show("密码不能为连续的0");
                        return;
                    }
                    // 判断密码是否正确
                    if (Convert.ToInt32(cmd.ExecuteScalar()) == 0)
                    {
                        MessageBox.Show("密码错误");
                        cmd.Dispose();
                        sql = "INSERT into admin_actions(Admin_ID, Action_Type, Action_Description, Action_Time) VALUES(@id, '登录', 'ID : " + Program.current + " 密码错误，无法登录系统', @actionTime)";
                        cmd = new MySqlCommand(sql, conn);
                        cmd.Parameters.AddWithValue("@id", int.Parse(Program.current));
                        cmd.Parameters.AddWithValue("@actionTime", DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss"));
                        cmd.ExecuteNonQuery();
                        cmd.Dispose();
                        return;
                    }
                    // 判断是否为管理员
                    sql = "SELECT Admin_Type FROM admins WHERE Admin_ID = @id";
                    cmd = new MySqlCommand(sql, conn);
                    cmd.Parameters.AddWithValue("@id", int.Parse(Program.current));
                    cmd.Dispose();
                    if (Convert.ToInt32(cmd.ExecuteScalar()) == 2)
                    {
                        SuperAdmin superadmin = new SuperAdmin(); // 实例化超级管理员窗体
                        superadmin.Show(); // 显示超级管理员窗体
                    }
                    else if (Convert.ToInt32(cmd.ExecuteScalar()) == 1)
                    {
                        Admin admin = new Admin(); // 实例化管理员窗体
                        admin.Show(); // 显示管理员窗体
                    }
                    this.Hide(); // 隐藏登录窗体
                    // 记录登录动作
                    sql = "INSERT into admin_actions(Admin_ID, Action_Type, Action_Description, Action_Time) VALUES(@id, '登录', 'ID : " + Program.current + " 登录系统', @actionTime)";
                    cmd = new MySqlCommand(sql, conn);
                    cmd.Parameters.AddWithValue("@id", int.Parse(Program.current));
                    cmd.Parameters.AddWithValue("@actionTime", DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss"));
                    cmd.ExecuteNonQuery();
                    cmd.Dispose();
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}