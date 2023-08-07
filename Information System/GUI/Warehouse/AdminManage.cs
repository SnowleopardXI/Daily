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
            this.id.Text="";
            this.name.Text="";
            this.email.Text="";
            this.phone.Text="";
            this.Admintype.Text="";
        }
        private void query_Click(object sender, EventArgs e)
        {
            MySqlConnection conn = new MySqlConnection(Program.str);
            conn.Open();
            string sql = "select * from admins_view";
            if (id.Text == "" && name.Text == "" && email.Text == "" && phone.Text == "" && Admintype.Text == "")
                sql += "";
            else
            {
                sql += " where ";
                if (id.Text != "")
                    sql += "管理员ID = " + id.Text + " and ";
                if (name.Text != "")
                    sql += "管理员姓名 = '" + name.Text + "' and ";
                if (email.Text != "")
                    sql += "Email = '" + email.Text + "' and ";
                if (phone.Text != "")
                    sql += "手机号 = '" + phone.Text + "' and ";
                if (Admintype.Text != "")
                    sql += "类型 = '" + Admintype.Text + "' and ";
                sql = sql.Substring(0, sql.Length - 4);
            }
            MySqlCommand cmd = new MySqlCommand(sql, conn);
            MySqlDataAdapter ada = new MySqlDataAdapter(cmd);
            DataSet ds = new DataSet();
            ada.Fill(ds);
            dataGridView1.DataSource = ds.Tables[0];
            conn.Close();
        }

        private void add_Click(object sender, EventArgs e)
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
                string sql = "CALL Add_Admin(" + Program.current + ",'" + name.Text + "',1,sha1(123456),'" + email.Text + "'," + phone.Text + ",";
                if (Admintype.Text == "管理员")
                    sql += "1)";
                if (Admintype.Text == "超级管理员")
                    sql += "2)";
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                cmd.ExecuteNonQuery();
                MessageBox.Show("添加成功,初始密码为123456");
                Clear();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
        private void delete_Click(object sender, EventArgs e)
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
                string sql = "CALL Delete_Admin(" + Program.current + "," + id.Text + ")";
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                cmd.ExecuteNonQuery();
                MessageBox.Show("删除成功");
                Clear();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void modify_Click(object sender, EventArgs e)
        {
            try
            {
                MySqlConnection conn = new MySqlConnection(Program.str);
                conn.Open();
                if(id.Text == "" || name.Text == "" || email.Text == "" || phone.Text == "" || Admintype.Text == "")
                {
                    MessageBox.Show("请填写完整信息");
                    return;
                }
                string sql = "CALL Update_Admin(" + Program.current + "," + id.Text + ",'" + name.Text + "',1,";
                if (Admintype.Text == "管理员")
                    sql += "1,'" + email.Text + "','" + phone.Text + "')";
                if (Admintype.Text == "超级管理员")
                    sql += "2,'" + email.Text + "','" + phone.Text + "')";
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                cmd.ExecuteNonQuery();
                MessageBox.Show("修改成功");
                Clear();
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void enable_Click(object sender, EventArgs e)
        {
            try
            {
                if(id.Text == "")
                {
                    MessageBox.Show("请填写完整信息");
                    return;
                }
                MySqlConnection conn = new MySqlConnection(Program.str);
                conn.Open();
                string sql = "select count(*) from admins where Admin_ID= " + id.Text;
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                int count = Convert.ToInt32(cmd.ExecuteScalar());
                if (count == 0)
                {
                    MessageBox.Show("该管理员不存在");
                    return;
                }
                sql = "Update admins set Valid= 1 where Admin_ID = " + id.Text;
                cmd = new MySqlCommand(sql, conn);
                cmd.ExecuteNonQuery();
                sql = "Insert into admin_actions(Admin_ID,Action_Type,Action_Time,Action_Description) values(" + Program.current + ",'启用管理员',now(),'管理员ID为" + Program.current + " 启用了管理员ID为" + id.Text + "的管理员')";
                cmd = new MySqlCommand(sql, conn);
                cmd.ExecuteNonQuery();
                MessageBox.Show("启用成功");
                Clear();
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void disable_Click(object sender, EventArgs e)
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
                string sql = "select count(*) from admins where Admin_ID= " + id.Text;
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                int count = Convert.ToInt32(cmd.ExecuteScalar());
                if (count == 0)
                {
                    MessageBox.Show("该管理员不存在");
                    return;
                }
                sql = "Update admins set Valid= 0 where Admin_ID = " + id.Text;
                cmd = new MySqlCommand(sql, conn);
                cmd.ExecuteNonQuery();
                sql = "Insert into admin_actions(Admin_ID,Action_Type,Action_Time,Action_Description) values(" + Program.current + ",'禁用管理员',now(),'管理员ID为" + Program.current + " 禁用了管理员ID为" + id.Text + "的管理员')";
                cmd = new MySqlCommand(sql, conn);
                cmd.ExecuteNonQuery();
                MessageBox.Show("禁用成功");
                Clear();
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}
