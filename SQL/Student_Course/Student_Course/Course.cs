﻿using MySql.Data.MySqlClient;
using System;
using System.Data;
using System.Windows.Forms;

namespace Student_Course
{
    public partial class Course : Form
    {
        public Course()
        {
            InitializeComponent();

        }
        public void Refresh()
        {
            try
            {
                string sql = "select * from course";
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
                string cno = this.cno.Text.Trim();
                string cname = this.cname.Text.Trim();
                string cpno = this.cpno.Text.Trim();
                string ccredit = this.ccredit.Text.Trim();
                MySqlConnection conn = new MySqlConnection(Program.str);//实例化连接
                //判断cno,cname是否存在
                string sql = "select * from course where cno = '" + cno + "' or cname = '" + cname + "'";
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                conn.Open();
                MySqlDataReader reader = cmd.ExecuteReader();
                if (reader.Read())
                {
                    MessageBox.Show("课程号或课程名已存在！");
                    return;
                }
                reader.Close();
                //插入数据
                sql = "insert into course values('" + cno + "','" + cname + "','" + cpno + "','" + ccredit + "')";
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
                string condition = " 'a'='a' "; string cno = this.cno.Text.Trim();
                if (cno != "")
                {
                    condition += " and cno like @cno ";
                }
                string cname = this.cname.Text.Trim();
                if (cname != "")
                {
                    condition += " and cname like @cname ";
                }
                string cpno = this.cpno.Text.Trim();
                string ccredit = this.ccredit.Text.Trim();
                MySqlConnection conn = new MySqlConnection(Program.str);//实例化连接
                conn.Open();
                // 判断课程号或课程名是否存在
                string sql = "select * from course where cno='" + cno + "' or cname='" + cname + "'";
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                MySqlDataReader reader = cmd.ExecuteReader();
                if (!reader.Read())
                {
                    MessageBox.Show("课程号或课程名不存在！");
                    return;
                }
                reader.Close();
                // 修改
                DialogResult result = MessageBox.Show("确实要修改吗？", "询问信息", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
                if (result == DialogResult.No)
                    return;
                sql = "update course set cno='" + cno + "',cname='" + cname + "',cpno='" + cpno + "',ccredit='" + ccredit + "' where cno='" + cno + "' or" + " cname='" + cname + "'";
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
                string cno = this.cno.Text.Trim();
                string cname = this.cname.Text.Trim();
                DialogResult result = MessageBox.Show("确实要删除吗？", "询问信息", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
                if (result == DialogResult.No)
                {
                    return;
                }

                MySqlConnection conn = new MySqlConnection(Program.str);//实例化连接y
                conn.Open();
                string sql = "select * from course where cno = '" + cno + "' or cname='" + cname + "'";
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                MySqlDataReader reader = cmd.ExecuteReader();
                //判断是否存在
                if (!reader.Read())
                {
                    MessageBox.Show("课程号或课程名不存在！");
                    return;
                }
                reader.Close();
                //删除
                sql = "delete from course where cno = '" + cno + "' or cname='" + cname + "'";
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
        private void Course_Load(object sender, EventArgs e)
        {

        }

        private void Query_Click_1(object sender, EventArgs e)
        {
            try
            {
                // 判断是否有输入
                string condition = " 'a'='a' "; string cno = this.cno.Text.Trim();
                if (cno != "")
                {
                    condition += " and cno like @cno ";
                }
                string cname = this.cname.Text.Trim();
                if (cname != "")
                {
                    condition += " and cname like @cname ";
                }
                string cpno = this.cpno.Text.Trim();
                if (cpno != "")
                {
                    condition += " and cpno like @cpno ";
                }
                string ccredit = this.ccredit.Text.Trim();
                if (ccredit != "")
                {
                    condition += " and ccredit like @ccredit ";
                }
                MySqlConnection conn = new MySqlConnection(Program.str);//实例化连接
                string sql = "select * from course where " + condition;
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                MySqlParameter param = new MySqlParameter();
                param.DbType = DbType.String;
                param.Value = cno;
                cmd.Parameters.Add(param);
                if (conn.State != ConnectionState.Open)
                    conn.Open();
                conn.Close();
                MySqlDataAdapter da = new MySqlDataAdapter(cmd);
                da.SelectCommand.Parameters.Add("@cno", MySqlDbType.String, 20).Value = "%" + cno + "%";
                da.SelectCommand.Parameters.Add("@cname", MySqlDbType.String, 20).Value = "%" + cname + "%";
                da.SelectCommand.Parameters.Add("@cpno", MySqlDbType.String, 20).Value = "%" + cpno + "%";
                da.SelectCommand.Parameters.Add("@ccredit", MySqlDbType.String, 20).Value = "%" + ccredit + "%";
                DataSet ds = new DataSet();
                da.Fill(ds);
                this.dataGridView1.DataSource = ds.Tables[0];

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
    }
}
