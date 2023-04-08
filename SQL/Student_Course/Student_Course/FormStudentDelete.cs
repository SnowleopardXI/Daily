﻿﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using MySql.Data.MySqlClient;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.StartPanel;

namespace Student_Course
{
    public partial class FormStudentDelete : Form
    {
        public FormStudentDelete()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                string str = "server=" + Program.server + ";User Id=" + Program.username + ";password=" + Program.password + ";Database=" + Program.database;
                MySqlConnection conn = new MySqlConnection(str);//实例化连接
                string sql = "select * from student";
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

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                int row = dataGridView1.CurrentRow.Index;
                if (row < 0)
                    return;

                DialogResult result = MessageBox.Show("确实要删除吗？", "询问信息", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
                if (result == DialogResult.No)
                    return;
                string sno = dataGridView1["sno", row].Value.ToString();
                string str = "server=" + Program.server + ";User Id=" + Program.username + ";password=" + Program.password + ";Database=" + Program.database;
                MySqlConnection conn = new MySqlConnection(str);//实例化连接
                string sql = "delete from student where sno=?";
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                MySqlParameter param = new MySqlParameter();
                param.DbType = DbType.String;
                param.Value = sno;
                cmd.Parameters.Add(param);
                if (conn.State != ConnectionState.Open)
                    conn.Open();
                int count = cmd.ExecuteNonQuery();
                conn.Close();
                MessageBox.Show("影响了" + count.ToString() + "行！");
                // 刷新
                sql = "select * from student";
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

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
    }
}
