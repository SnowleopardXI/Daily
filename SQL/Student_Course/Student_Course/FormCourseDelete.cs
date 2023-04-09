using System;
using System.Data;
using System.Windows.Forms;

using MySql.Data.MySqlClient;

namespace Student_Course
{
    public partial class FormCourseDelete : Form
    {
        public FormCourseDelete()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                MySqlConnection conn = new MySqlConnection(Program.str);//实例化连接
                string sql = "select * from course";
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
                string cno = dataGridView1["cno", row].Value.ToString();
                MySqlConnection conn = new MySqlConnection(Program.str);//实例化连接
                string sql = "delete from course where cno=?";
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                MySqlParameter param = new MySqlParameter();
                param.DbType = DbType.String;
                param.Value = cno;
                cmd.Parameters.Add(param);
                if (conn.State != ConnectionState.Open)
                    conn.Open();
                int count = cmd.ExecuteNonQuery();
                conn.Close();
                MessageBox.Show("影响了" + count.ToString() + "行！");
                // 刷新
                sql = "select * from course";
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
