using MySql.Data.MySqlClient;
using System;
using System.Data;
using System.Windows.Forms;

namespace UsageRecord
{
    public partial class UserMgr : Form
    {
        public UserMgr()
        {
            InitializeComponent();
        }

        private void UserMgr_Load(object sender, EventArgs e)
        {

        }
        public void Refresh()
        {
            using (MySqlConnection conn = new MySqlConnection(Program.str))
            {
                name.Text = "";
                id.Text = "";
                contact.Text = "";
                type.Text = "";
                conn.Open();
                string sql = "select * from user";
                MySqlDataAdapter adapter = new MySqlDataAdapter(sql, conn);
                DataSet ds = new DataSet();
                adapter.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];
            }
        }
        private void add_Click(object sender, EventArgs e)
        {
            using (MySqlConnection conn = new MySqlConnection(Program.str))
            {
                conn.Open();
                string countSql = "select count(*) from Users where Name = @name";
                MySqlCommand cmd = new MySqlCommand(countSql, conn);
                cmd.Parameters.AddWithValue("@name", name.Text);
                int count = Convert.ToInt32(cmd.ExecuteScalar());
                if (count > 0)
                {
                    MessageBox.Show("用户名已存在");
                    return;
                }
                if (type.Text == "不限")
                {
                    MessageBox.Show("类型错误");
                    return;
                }
                string sql = "insert into Users(Type, Name, ContactInfo, Valid, Password) values(@type, @name, @contact, 1, 123456)";
                cmd = new MySqlCommand(sql, conn);
                cmd.Parameters.AddWithValue("@id", id.Text);
                int flag = 0;
                if (type.Text == "管理员")
                    flag = 1;
                else flag = 0;
                cmd.Parameters.AddWithValue("@type", flag);
                cmd.Parameters.AddWithValue("@name", name.Text);
                cmd.Parameters.AddWithValue("@contact", contact.Text);
                cmd.ExecuteNonQuery();
                MessageBox.Show("添加成功");
            }
        }

        private void delete_Click(object sender, EventArgs e)
        {
            using (MySqlConnection conn = new MySqlConnection(Program.str))
            {
                conn.Open();
                if (id.Text == "")
                {
                    MessageBox.Show("请输入ID");
                    return;
                }
                string countSql = "select count(*) from Users where UserID = @id";
                MySqlCommand cmd = new MySqlCommand(countSql, conn);
                cmd.Parameters.AddWithValue("@id", id.Text);
                int count = Convert.ToInt32(cmd.ExecuteScalar());
                if (count == 0)
                {
                    MessageBox.Show("用户不存在");
                    return;
                }
                string sql = "delete from Users where UserID = @id";
                cmd = new MySqlCommand(sql, conn);
                cmd.Parameters.AddWithValue("@id", uid.Text);
                cmd.ExecuteNonQuery();
                MessageBox.Show("删除成功");
            }
        }

        private void modify_Click(object sender, EventArgs e)
        {
            using (MySqlConnection conn = new MySqlConnection(Program.str))
            {
                conn.Open();
                if (id.Text == "" && name.Text == "" && contact.Text == "")
                {
                    MessageBox.Show("请输入修改信息");
                    return;
                }
                string countSql = "select count(*) from Users where UserID = @id";
                MySqlCommand cmd = new MySqlCommand(countSql, conn);
                cmd.Parameters.AddWithValue("@id", id.Text);
                int count = Convert.ToInt32(cmd.ExecuteScalar());
                if (count == 0)
                {
                    MessageBox.Show("用户不存在");
                    return;
                }
                int flag = 0;
                if (type.Text == "管理员")
                    flag = 1;
                else if (type.Text == "普通用户")
                    flag = 0;
                else if (type.Text == "不限")
                    flag = -1;
                if (flag != -1)
                {
                    string sql = "update Users set Type = @type, Name = @name, ContactInfo = @contact where UserID = @id";
                    cmd = new MySqlCommand(sql, conn);
                    cmd.Parameters.AddWithValue("@id", uid.Text);
                    cmd.Parameters.AddWithValue("@type", flag);
                    cmd.Parameters.AddWithValue("@name", name.Text);
                    cmd.Parameters.AddWithValue("@contact", contact.Text);
                    cmd.ExecuteNonQuery();
                }
            }
        }

        private void query_Click(object sender, EventArgs e)
        {
            using (MySqlConnection conn = new MySqlConnection(Program.str))
            {
                conn.Open();
                if (id.Text == "" && name.Text == "" && contact.Text == "")
                {
                    string sql = "select * from Users";
                    MySqlDataAdapter adapter = new MySqlDataAdapter(sql, conn);
                    DataSet ds = new DataSet();
                    adapter.Fill(ds);
                    dataGridView1.DataSource = ds.Tables[0];
                }
                else
                {
                    string sql = "select * from Users ";
                    if (type.Text != "")
                    {
                        int flag = 0;
                        if (type.Text == "管理员")
                            flag = 1;
                        else if (type.Text == "普通用户")
                            flag = 0;
                        else if (type.Text == "不限")
                            flag = -1;
                        if (flag != -1)
                            sql += "where Type = " + flag;
                    }
                    MySqlDataAdapter adapter = new MySqlDataAdapter(sql, conn);
                    adapter.SelectCommand.Parameters.AddWithValue("@id", uid.Text);
                    adapter.SelectCommand.Parameters.AddWithValue("@name", name.Text);
                    adapter.SelectCommand.Parameters.AddWithValue("@contact", contact.Text);
                    DataSet ds = new DataSet();
                    adapter.Fill(ds);
                    dataGridView1.DataSource = ds.Tables[0];
                }
            }
        }
    }
}
