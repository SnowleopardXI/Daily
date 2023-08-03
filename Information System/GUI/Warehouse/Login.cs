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
                Program.current=this.id.Text;
                password=this.pass.Text;
                MySqlConnection conn = new MySqlConnection(Program.str);//实例化连接
                conn.Open();//开启连接
                string sql = "SELECT Admin_Type FROM admins WHERE Admin_ID = '" + this.id.Text + "' AND Password = sha1('" + this.pass.Text + "')";//查询语句
                MySqlCommand cmd = new MySqlCommand(sql, conn);//执行查询
                MySqlDataReader reader = cmd.ExecuteReader();//读取查询结果
                if (reader.Read())//如果读取到结果
                {
                    if (reader[0].ToString() == "1")//如果是普通管理员
                    {
                        Admin admin = new Admin();//实例化管理员窗体
                        admin.Show();//显示管理员窗体
                        this.Hide();//隐藏登录窗体
                    }
                    else//如果是超级管理员
                    {
                        SuperAdmin superadmin = new SuperAdmin();//实例化超级管理员窗体
                        superadmin.Show();//显示超级管理员窗体
                        this.Hide();//隐藏登录窗体
                    }
                }
                else//如果没有读取到结果
                {
                    MessageBox.Show("用户名或密码错误！");//弹出提示
                    this.id.Text = "";//清空用户名输入框
                    this.pass.Text = "";//清空密码输入框
                }
                reader.Close();//关闭读取
                conn.Close();//关闭连接
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}