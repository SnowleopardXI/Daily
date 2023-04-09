using MySql.Data.MySqlClient;
using System;
using System.Data;
using System.Windows.Forms;

namespace Student_Course
{
    public partial class FormCourceModify : Form
    {
        public FormCourceModify()
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
        private void FormCourceModify_Load(object sender, EventArgs e)
        {
            
        }

        private void Modify_Click(object sender, EventArgs e)
        {
            string cno = this.cno.Text.Trim();
            string cname = this.cname.Text.Trim();
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
            sql = "update course set cno='" + cno + "',cname='" + cname + "',cpno='" + cpno + "',ccredit='" + ccredit + "' where cno='" + cno + "'";
            cmd = new MySqlCommand(sql, conn);
            cmd.ExecuteNonQuery();
            MessageBox.Show("修改成功！");
            // 刷新
            Refresh();
            conn.Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MySqlConnection conn = new MySqlConnection(Program.str);//实例化连接
            conn.Close();
            conn.Open();//开启连接
            // 读取全部课程信息
            string sql = "select * from course";
            MySqlDataAdapter da = new MySqlDataAdapter(sql, conn);  //数据适配器
            DataTable dt = new DataTable();   //数据表
            da.Fill(dt);   //执行sql，将数据填入数据表
            dataGridView1.DataSource = dt;  //将数据表绑定到dataGridView1上，显示出来
            conn.Close();
        }
    }
}
