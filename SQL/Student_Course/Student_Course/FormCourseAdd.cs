using System;
using System.Windows.Forms;

using MySql.Data.MySqlClient;


namespace Student_Course
{
    public partial class FormCourseAdd : Form
    {
        
        public FormCourseAdd()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void Add_Click(object sender, EventArgs e)
        {
            try
            {
                string cno = this.cno.Text.Trim();
                string cname = this.cname.Text.Trim();
                string ccredit = this.ccredit.Text.Trim();
                string cpno = this.cpno.Text.Trim();

                
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
                sql = "insert into course values('" + cno + "','" + cname + "','" + ccredit + "','" + cpno + "')";
                cmd = new MySqlCommand(sql, conn);
                cmd.ExecuteNonQuery();
                MessageBox.Show("添加成功！");
                conn.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void cno_TextChanged(object sender, EventArgs e)
        {

        }

        private void cname_TextChanged(object sender, EventArgs e)
        {

        }

        private void ccredit_TextChanged(object sender, EventArgs e)
        {

        }

        private void cpno_TextChanged(object sender, EventArgs e)
        {

        }

        private void FormCourseAdd_Load(object sender, EventArgs e)
        {

        }
    }
}
