using MySql.Data.MySqlClient;
using System;
using System.Windows.Forms;
namespace Warehouse
{
    public partial class Login : Form
    {
        public string password ="";
        public Login()
        {
            InitializeComponent();
        }

        private void button_login_Click(object sender, EventArgs e)
        {
            try 
            {
                //this.id.Text只能为纯数字
                if (this.id.Text == "" || !System.Text.RegularExpressions.Regex.IsMatch(this.id.Text, @"^[0-9]*$"))
                {
                    MessageBox.Show("ID格式错误");
                    return;
                }
                Program.current=this.id.Text;
                password=this.pass.Text;
                //this.password.Text不能包含空格或 --)
                if (this.pass.Text.Contains(" ") || System.Text.RegularExpressions.Regex.IsMatch(this.pass.Text, @"[']") || System.Text.RegularExpressions.Regex.IsMatch(this.pass.Text, @"[-][-]"))
                {
                    MessageBox.Show("密码格式错误");
                    return;
                }
                MySqlConnection conn = new MySqlConnection(Program.str);//实例化连接
                conn.Open();//开启连接
                string sql="SELECT count(*) FROM admins WHERE Admin_ID = " + this.id.Text;
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                //判断用户是否存在
                if (Convert.ToInt32(cmd.ExecuteScalar()) == 0)
                {
                    MessageBox.Show("用户不存在");
                    return;
                }
                //判断是否被禁用
                sql="SELECT Valid FROM admins WHERE Admin_ID = " + this.id.Text;
                cmd = new MySqlCommand(sql, conn);
                if (Convert.ToInt32(cmd.ExecuteScalar()) == 0)
                {
                    MessageBox.Show("用户已被禁用");
                    sql="INSERT into admin_actions(Admin_ID,Action_Type,Action_Description,Action_Time) VALUES('" + Program.current + "','登录','ID: " + Program.current + " 已禁用，无法登录系统','" + DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss") + "')";
                    cmd = new MySqlCommand(sql, conn);
                    cmd.ExecuteNonQuery();
                    return;
                }
                sql="SELECT COUNT(*) FROM admins WHERE Admin_ID = " + this.id.Text + " AND Password = sha1('" + password + "')";
                cmd=new MySqlCommand(sql, conn);
                //判断密码是否正确
                if (Convert.ToInt32(cmd.ExecuteScalar()) == 0)
                {
                    MessageBox.Show("密码错误");
                    sql="INSERT into admin_actions(Admin_ID,Action_Type,Action_Description,Action_Time) VALUES('" + Program.current + "','登录','ID: " + Program.current + " 密码错误','" + DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss") + "')";
                    cmd = new MySqlCommand(sql, conn);
                    cmd.ExecuteNonQuery();
                    return;
                }
                //判断是否为管理员
                sql="SELECT Admin_Type FROM admins WHERE Admin_ID = " + this.id.Text;
                cmd = new MySqlCommand(sql, conn);
                if (Convert.ToInt32(cmd.ExecuteScalar()) == 2)
                {
                    SuperAdmin superadmin = new SuperAdmin();//实例化超级管理员窗体
                    superadmin.Show();//显示超级管理员窗体
                    this.Hide();//隐藏登录窗体
                }
                if(Convert.ToInt32(cmd.ExecuteScalar()) == 1)
                {
                    Admin admin = new Admin();//实例化管理员窗体
                    admin.Show();//显示管理员窗体
                    this.Hide();//隐藏登录窗体
                }
                sql = "INSERT into admin_actions(Admin_ID,Action_Type,Action_Description,Action_Time) VALUES('" + Program.current + "','登录','ID: " + Program.current + " 登录系统','" + DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss") + "')";
                cmd = new MySqlCommand(sql, conn);
                cmd.ExecuteNonQuery();
                conn.Close();//关闭连接
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}