using MySql.Data.MySqlClient;
using System;
using System.Data;
using System.Windows.Forms;

namespace Student_Course
{
    public partial class Student : Form
    {
        public Student()
        {
            InitializeComponent();

        }
        public void Refresh()
        {
            try
            {
                string sql = "select * from student";
                MySqlConnection conn = new MySqlConnection(Program.str);//实例化连接
                MySqlDataAdapter da = new MySqlDataAdapter(sql, conn);  //数据适配器
                DataTable dt = new DataTable();   //数据表
                da.Fill(dt);   //执行sql，将数据填入数据表
                dataGridView1.DataSource = dt;  //将数据表绑定到dataGridView1上，显示出来
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
        private void Add_Click(object sender, EventArgs e)
        {
            try
            {
                string sno = this.sno.Text.Trim();
                string sname = this.sname.Text.Trim();
                string ssex = this.ssex.Text.Trim();
                string sage = this.sage.Text.Trim();
                string sdept = this.sdept.Text.Trim();
                MySqlConnection conn = new MySqlConnection(Program.str);//实例化连接
                //判断sno是否存在
                string sql = "select * from student where sno = '" + sno + "'";
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                conn.Open();
                MySqlDataReader reader = cmd.ExecuteReader();
                if (reader.Read())
                {
                    MessageBox.Show("学号已存在！");
                    return;
                }
                reader.Close();
                //插入数据
                sql = "insert into student values('" + sno + "','" + sname + "','" + ssex + "'" + sage + "','" + sdept + "')";
                cmd = new MySqlCommand(sql, conn);
                cmd.ExecuteNonQuery();
                MessageBox.Show("添加成功！");
                Refresh();
                conn.Close();
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
                string sno = this.sno.Text.Trim();
                string sname = this.sname.Text.Trim();
                string ssex = this.ssex.Text.Trim();
                string sage = this.sage.Text.Trim();
                string sdept = this.sdept.Text.Trim();
                MySqlConnection conn = new MySqlConnection(Program.str);//实例化连接
                conn.Open();
                // 判断学号
                string sql = "select * from student where sno='" + sno + "'";
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                MySqlDataReader reader = cmd.ExecuteReader();
                if (!reader.Read())
                {
                    MessageBox.Show("学号不存在！");
                    return;
                }
                reader.Close();
                // 修改
                DialogResult result = MessageBox.Show("确实要修改吗？", "询问信息", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
                if (result == DialogResult.No)
                    return;
                sql = "update student set sno='" + sno + "',sname='" + sname + "',ssex='" + ssex + "',sage='" + sage + "',sdept='" + sdept + "' where sno='" + sno + "'";
                cmd = new MySqlCommand(sql, conn);
                cmd.ExecuteNonQuery();
                MessageBox.Show("修改成功！");
                // 刷新
                Refresh();
                conn.Close();
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
                string sno = this.sno.Text.Trim();
                string sname = this.sname.Text.Trim();
                DialogResult result = MessageBox.Show("确实要删除吗？", "询问信息", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
                if (result == DialogResult.No)
                {
                    return;
                }

                MySqlConnection conn = new MySqlConnection(Program.str);//实例化连接y
                conn.Open();
                string sql = "select * from student where sno = '" + sno + "'";
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                MySqlDataReader reader = cmd.ExecuteReader();
                //判断是否存在
                if (!reader.Read())
                {
                    MessageBox.Show("学号不存在！");
                    return;
                }
                reader.Close();
                //删除
                sql = "delete from student where sno = '" + sno + "' or sname='" + sname + "'";
                cmd = new MySqlCommand(sql, conn);
                int count = cmd.ExecuteNonQuery();
                conn.Close();
                MessageBox.Show("影响了" + count.ToString() + "行！");
                // 刷新
                Refresh();
                conn.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
        private void Student_Load(object sender, EventArgs e)
        {

        }

        private void Query_Click_1(object sender, EventArgs e)
        {
            try
            {
                // 判断是否有输入
                string condition = " 'a'='a' "; 
                string sno = this.sno.Text.Trim();
                if (sno != "")
                {
                    condition += " and sno like @sno ";
                }
                string sname = this.sname.Text.Trim();
                if (sname != "")
                {
                    condition += " and sname like @sname ";
                }
                string ssex = this.ssex.Text.Trim();
                if (ssex != "")
                {
                    condition += " and ssex like @ssex ";
                }
                string sage = this.sage.Text.Trim();
                if (sage != "")
                {
                    condition += " and sage like @sage ";
                }
                string sdept = this.sdept.Text.Trim();
                if (sdept != "")
                {
                    condition += " and sdept like @sdept ";
                }
                MySqlConnection conn = new MySqlConnection(Program.str);//实例化连接
                string sql = "select * from student where " + condition;
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                MySqlParameter param = new MySqlParameter();
                param.DbType = DbType.String;
                param.Value = sno;
                cmd.Parameters.Add(param);
                if (conn.State != ConnectionState.Open)
                    conn.Open();
                conn.Close();
                MySqlDataAdapter da = new MySqlDataAdapter(cmd);
                da.SelectCommand.Parameters.Add("@sno", MySqlDbType.String, 20).Value = "%" + sno + "%";
                da.SelectCommand.Parameters.Add("@sname", MySqlDbType.String, 20).Value = "%" + sname + "%";
                da.SelectCommand.Parameters.Add("@ssex", MySqlDbType.String, 20).Value = "%" + ssex + "%";
                da.SelectCommand.Parameters.Add("@sage", MySqlDbType.String, 20).Value = "%" + sage + "%";
                da.SelectCommand.Parameters.Add("@sdept", MySqlDbType.String, 20).Value = "%" + sdept + "%";
                DataSet ds = new DataSet();
                da.Fill(ds);
                this.dataGridView1.DataSource = ds.Tables[0];

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}
