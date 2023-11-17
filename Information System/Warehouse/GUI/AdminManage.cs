using MySql.Data.MySqlClient;
using System;
using System.Data;
using System.Windows.Forms;

namespace Warehouse
{
    public partial class AdminManage : Form
    {
        public AdminManage()
        {
            InitializeComponent();
        }
        public void Clear()
        {
            this.id.Text = "";
            this.name.Text = "";
            this.email.Text = "";
            this.phone.Text = "";
            this.Admintype.Text = "";
        }
        public void Refresh()
        {
            MySqlConnection conn = new MySqlConnection(Program.str);
            conn.Open();
            string sql = "select * from admins_view";
            MySqlCommand cmd = new MySqlCommand(sql, conn);
            cmd.ExecuteNonQuery();
            MySqlDataAdapter da = new MySqlDataAdapter(cmd);
            DataSet ds = new DataSet();
            da.Fill(ds);
            dataGridView1.DataSource = ds.Tables[0];
            conn.Close();
        }
        private void Query_Click(object sender, EventArgs e)
        {
            MySqlConnection conn = new MySqlConnection(Program.str);
            conn.Open();
            string sql = "";
            MySqlCommand cmd = new MySqlCommand(sql, conn);
            MySqlDataAdapter da = new MySqlDataAdapter(cmd);
            DataSet ds = new DataSet();
            if (id.Text == "" && name.Text == "" && email.Text == "" && phone.Text == "" && Admintype.Text == "")
            {
                sql = "select * from admins_view";
                cmd = new MySqlCommand(sql, conn);
                cmd.ExecuteNonQuery();
                da = new MySqlDataAdapter(cmd);
                ds = new DataSet();
                da.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];
                conn.Close();
                return;
            }
            sql = "select * from admins_view where 管理员ID = @id or 管理员姓名 = @name or Email = @email or 类型 = @type or 手机号 = @phone";
            cmd = new MySqlCommand(sql, conn);
            cmd.Parameters.AddWithValue("@id", id.Text);
            cmd.Parameters.AddWithValue("@name", name.Text);
            cmd.Parameters.AddWithValue("@phone", phone.Text);
            cmd.Parameters.AddWithValue("@type", Admintype.Text);
            cmd.Parameters.AddWithValue("@email", email.Text);
            cmd.ExecuteNonQuery();
            da = new MySqlDataAdapter(cmd);
            ds = new DataSet();
            da.Fill(ds);
            dataGridView1.DataSource = ds.Tables[0];
            conn.Close();
        }
        private void Add_Click(object sender, EventArgs e)
        {
            try
            {
                MySqlConnection conn = new MySqlConnection(Program.str);
                conn.Open();
                if (name.Text == "" || email.Text == "" || phone.Text == "" || Admintype.Text == "")
                {
                    MessageBox.Show("请填写完整信息");
                    return;
                }
                string sql = "CALL Add_Admin(" + Program.current + ",";
                string condition = "@name,1,sha1(123456),@email,@phone,";
                if (Admintype.Text == "管理员")
                    condition += "1)";
                if (Admintype.Text == "超级管理员")
                    condition += "2)";
                sql += condition;
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                cmd.Parameters.AddWithValue("@name", name.Text);
                cmd.Parameters.AddWithValue("@phone", phone.Text);
                cmd.Parameters.AddWithValue("@email", email.Text);
                cmd.ExecuteNonQuery();
                MessageBox.Show("添加成功,初始密码为123456");
                Clear();
                Refresh();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
        private void Delete_Click(object sender, EventArgs e)
        {
            try
            {
                MySqlConnection conn = new MySqlConnection(Program.str);
                conn.Open();
                if (id.Text == "")
                {
                    MessageBox.Show("请填写完整信息");
                    return;
                }
                string sql = "CALL Delete_Admin(" + Program.current + ",";
                string condition = "@id)";
                sql += condition;
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                cmd.Parameters.AddWithValue("@id", id.Text);
                cmd.ExecuteNonQuery();
                MessageBox.Show("删除成功");
                Clear();
                Refresh();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void Modify_Click(object sender, EventArgs e)
        {
            try
            {
                MySqlConnection conn = new MySqlConnection(Program.str);
                conn.Open();
                if (id.Text == "" || name.Text == "" || email.Text == "" || phone.Text == "" || Admintype.Text == "")
                {
                    MessageBox.Show("请填写完整信息");
                    return;
                }
                string sql = "select Valid from admins where Admin_ID = @id";
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                cmd.Parameters.AddWithValue("@id", id.Text);
                int valid = Convert.ToInt32(cmd.ExecuteScalar());
                sql = "CALL Update_Admin(" + Program.current + ",";
                string condition = "@id,@name,@valid,";
                if (Admintype.Text == "管理员")
                    condition += "1,";
                if (Admintype.Text == "超级管理员")
                    condition += "2,";
                condition += "@email,@phone)";
                sql += condition;
                cmd = new MySqlCommand(sql, conn);
                cmd.Parameters.AddWithValue("@id", id.Text);
                cmd.Parameters.AddWithValue("@name", name.Text);
                cmd.Parameters.AddWithValue("@phone", phone.Text);
                cmd.Parameters.AddWithValue("@valid", valid);
                cmd.Parameters.AddWithValue("@type", Admintype.Text);
                cmd.Parameters.AddWithValue("@email", email.Text);
                cmd.ExecuteNonQuery();
                MessageBox.Show("修改成功");
                Clear();
                Refresh();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void Enable_Click(object sender, EventArgs e)
        {
            try
            {
                if (id.Text == "")
                {
                    MessageBox.Show("请填写完整信息");
                    return;
                }
                MySqlConnection conn = new MySqlConnection(Program.str);
                conn.Open();
                string sql = "select count(*) from admins where Admin_ID= @id";
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                cmd.Parameters.AddWithValue("@id", id.Text);
                int count = Convert.ToInt32(cmd.ExecuteScalar());
                if (count == 0)
                {
                    MessageBox.Show("该管理员不存在");
                    return;
                }
                sql = "Update admins set Valid= 1 where Admin_ID = @id";
                cmd = new MySqlCommand(sql, conn);
                cmd.Parameters.AddWithValue("@id", id.Text);
                cmd.ExecuteNonQuery();
                sql = "Insert into admin_actions(Admin_ID,Action_Type,Action_Time,Action_Description) values(" + Program.current + ",'启用管理员',now(),'管理员：" + Program.current + " 启用了管理员ID：" + id.Text + "')";
                cmd = new MySqlCommand(sql, conn);
                cmd.Parameters.AddWithValue("@id", id.Text);
                cmd.ExecuteNonQuery();
                MessageBox.Show("启用成功");
                Clear();
                Refresh();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void Disable_Click(object sender, EventArgs e)
        {
            try
            {
                if (id.Text == "")
                {
                    MessageBox.Show("请填写完整信息");
                    return;
                }
                MySqlConnection conn = new MySqlConnection(Program.str);
                conn.Open();
                string sql = "select count(*) from admins where Admin_ID= @id";
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                cmd.Parameters.AddWithValue("@id", id.Text);
                int count = Convert.ToInt32(cmd.ExecuteScalar());
                if (count == 0)
                {
                    MessageBox.Show("该管理员不存在");
                    return;
                }
                sql = "Update admins set Valid= 0 where Admin_ID = @id";
                cmd = new MySqlCommand(sql, conn);
                cmd.Parameters.AddWithValue("@id", id.Text);
                cmd.ExecuteNonQuery();
                sql = "Insert into admin_actions(Admin_ID,Action_Type,Action_Time,Action_Description) values(" + Program.current + ",'禁用管理员',now(),'管理员ID：" + Program.current + " 禁用了管理员ID：" + id.Text + "')";
                cmd = new MySqlCommand(sql, conn);
                cmd.ExecuteNonQuery();
                MessageBox.Show("禁用成功");
                Clear();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}
