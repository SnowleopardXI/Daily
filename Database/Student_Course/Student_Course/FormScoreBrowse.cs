using MySql.Data.MySqlClient;
using System;
using System.Data;
using System.Windows.Forms;

namespace Student_Course
{
    public partial class FormScoreBrowse : Form
    {
        public FormScoreBrowse()
        {
            InitializeComponent();
        }

        private void FormScoreBrowse_Load(object sender, EventArgs e)
        {

        }

        private void 查询_Click(object sender, EventArgs e)
        {
            MySqlConnection conn = new MySqlConnection(Program.str);//实例化连接
            string sql = "SELECT student.sno AS '学号',student.sname AS '姓名',student.sdept AS '系名',course.cname AS '课程名',sc.grade AS '成绩' FROM student,sc,course WHERE student.sno=sc.sno AND course.cno=sc.cno";
            MySqlDataAdapter da = new MySqlDataAdapter(sql, conn);  //数据适配器
            DataTable dt = new DataTable();   //数据表
            da.Fill(dt);   //执行sql，将数据填入数据表
            dataGridView1.DataSource = dt;  //将数据表绑定到dataGridView1上，显示出来
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
    }
}
