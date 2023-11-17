using MySql.Data.MySqlClient;
using System;
using System.Data;
using System.Windows.Forms;

namespace Users
{
    public partial class Home : Form
    {
        public Home()
        {
            InitializeComponent();
        }
        public void Refresh()
        {
            using (MySqlConnection conn = new MySqlConnection(Program.str))
            {
                conn.Open();
                string sql = "SELECT id, name AS 姓名, gender AS 性别, age AS 年龄, phone AS 手机号 FROM users";
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                MySqlDataAdapter da = new MySqlDataAdapter(cmd);
                DataSet ds = new DataSet();
                da.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];
                conn.Close();
            }
            id.Text = "";
            age.Text = "";
            name.Text = "";
            phone.Text = "";
        }
        private void query_Click_1(object sender, EventArgs e)
        {
            using (MySqlConnection conn = new MySqlConnection(Program.str))
            {
                conn.Open();
                string sql = "SELECT id, name AS 姓名, gender AS 性别, age AS 年龄, phone AS 手机号 FROM users";
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                MySqlDataAdapter da = new MySqlDataAdapter(cmd);
                DataSet ds = new DataSet();
                da.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];
                conn.Close();
            }
        }

        private void add_Click_1(object sender, EventArgs e)
        {
            using (MySqlConnection conn = new MySqlConnection(Program.str))
            {
                conn.Open();
                string count = "SELECT COUNT(*) FROM users WHERE name = @name or id = @id";
                string sql = "Insert INTO users(name,gender,age,phone) VALUES(@name,@gender,@age,@phone)";
                MySqlCommand cmd = new MySqlCommand(count, conn);
                cmd.Parameters.AddWithValue("@name", name.Text);
                cmd.Parameters.AddWithValue("@id", id.Text);
                int result = Convert.ToInt32(cmd.ExecuteScalar());
                if (result == 1)
                {
                    MessageBox.Show("用户已存在");
                    conn.Close();
                    return;
                }
                cmd = new MySqlCommand(sql, conn);
                cmd.Parameters.AddWithValue("@name", name.Text);
                cmd.Parameters.AddWithValue("gender", gender.Text);
                cmd.Parameters.AddWithValue("@age", age.Text);
                cmd.Parameters.AddWithValue("@phone", phone.Text);
                cmd.ExecuteNonQuery();
                conn.Close();
            }
            MessageBox.Show("添加成功");
            Refresh();
        }

        private void modify_Click_1(object sender, EventArgs e)
        {
            using (MySqlConnection conn = new MySqlConnection(Program.str))
            {
                conn.Open();
                string count = "SELECT COUNT(*) FROM users WHERE name = @name or id = @id";
                string sql = "UPDATE users SET name = @name, gender = @gender, age = @age, phone = @phone WHERE id = @id";
                if (id.Text == "" && name.Text == "" && gender.Text == "" && age.Text == "" && phone.Text == "")
                {
                    MessageBox.Show("请输入完整信息");
                    conn.Close();
                    return;
                }
                MySqlCommand cmd = new MySqlCommand(count, conn);
                cmd.Parameters.AddWithValue("@name", name.Text);
                cmd.Parameters.AddWithValue("@id", id.Text);
                int result = Convert.ToInt32(cmd.ExecuteScalar());
                if (result == 0)
                {
                    MessageBox.Show("用户不存在");
                    conn.Close();
                    return;
                }
                cmd = new MySqlCommand(sql, conn);
                cmd.Parameters.AddWithValue("@name", name.Text);
                cmd.Parameters.AddWithValue("@id", id.Text);
                cmd.Parameters.AddWithValue("@gender", gender.Text);
                cmd.Parameters.AddWithValue("@age", age.Text);
                cmd.Parameters.AddWithValue("@phone", phone.Text);
                cmd.ExecuteNonQuery();
                conn.Close();
                MessageBox.Show("修改成功");
                Refresh();
            }
        }

        private void delete_Click_1(object sender, EventArgs e)
        {
            using (MySqlConnection conn = new MySqlConnection(Program.str))
            {
                conn.Open();
                string count = "SELECT COUNT(*) FROM users WHERE id = @id";
                string sql = "DELETE FROM users WHERE id = @id";
                MySqlCommand cmd = new MySqlCommand(count, conn);
                cmd.Parameters.AddWithValue("@id", id.Text);
                int result = Convert.ToInt32(cmd.ExecuteScalar());
                if (result == 0)
                {
                    MessageBox.Show("用户不存在");
                    conn.Close();
                    return;
                }
                cmd = new MySqlCommand(sql, conn);
                cmd.Parameters.AddWithValue("@id", id.Text);
                cmd.ExecuteNonQuery();
                conn.Close();
                MessageBox.Show("删除成功");
                Refresh();
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            using (MySqlConnection conn = new MySqlConnection(Program.str))
            {
                conn.Open();
                string sql = "SELECT * FROM notesview";
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                MySqlDataAdapter da = new MySqlDataAdapter(cmd);
                DataSet ds = new DataSet();
                da.Fill(ds);
                dataGridView2.DataSource = ds.Tables[0];
                conn.Close();
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            using (MySqlConnection conn = new MySqlConnection(Program.str))
            {
                if (id.Text == "")
                {
                    MessageBox.Show("请输入用户id");
                    return;
                }
                conn.Open();
                string countSql = "SELECT COUNT(*) FROM users WHERE id = @id";
                string noteCount = "SELECT COUNT(*) FROM notes WHERE id = @id";
                string InsertSql = "INSERT INTO notes(id,notes) VALUES(@id,@note)";
                string UptateSql = "UPDATE notes SET notes = @note WHERE id = @id";
                string DeleteSql = "DELETE FROM notes WHERE id = @id";
                MySqlCommand cmd = new MySqlCommand(countSql, conn);
                if (note.Text == "")
                {
                    cmd = new MySqlCommand(DeleteSql, conn);
                    cmd.Parameters.AddWithValue("@id", uid.Text);
                    cmd.ExecuteNonQuery();
                    conn.Close();
                    MessageBox.Show("删除成功");
                    button1_Click(sender, e);
                    return;
                }
                cmd.Parameters.AddWithValue("@id", uid.Text);
                int result = Convert.ToInt32(cmd.ExecuteScalar());
                if (result == 0)
                {
                    MessageBox.Show("用户不存在");
                    conn.Close();
                    return;
                }
                cmd = new MySqlCommand(noteCount, conn);
                cmd.Parameters.AddWithValue("@id", uid.Text);
                result = Convert.ToInt32(cmd.ExecuteScalar());
                if (result == 1)
                {
                    MySqlCommand cmd2 = new MySqlCommand(UptateSql, conn);
                    cmd2.Parameters.AddWithValue("@id", uid.Text);
                    cmd2.Parameters.AddWithValue("@note", note.Text);
                    cmd2.ExecuteNonQuery();
                    conn.Close();
                    MessageBox.Show("修改成功");
                    // 模拟查询按钮
                    button1_Click(sender, e);
                    return;
                }
                cmd = new MySqlCommand(InsertSql, conn);
                cmd.Parameters.AddWithValue("@id", uid.Text);
                cmd.Parameters.AddWithValue("@note", note.Text);
                cmd.ExecuteNonQuery();
                conn.Close();
                MessageBox.Show("添加成功");
                button1_Click(sender, e);
                return;
            }
        }

        private void exit_Click(object sender, EventArgs e)
        {
            //询问
            try
            {
                DialogResult result = MessageBox.Show("是否退出系统？", "提示", MessageBoxButtons.OKCancel, MessageBoxIcon.Question);
                if (result == DialogResult.OK)
                    Application.Exit();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}