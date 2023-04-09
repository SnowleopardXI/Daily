using MySql.Data.MySqlClient;
using Student_Course;
using System;
using System.Data;
using System.Windows.Forms;

namespace Student_Course
{
    public partial class Main : Form
	{

		public Main()
		{
			InitializeComponent();
		}

        private void 启用_Click(object sender, EventArgs e)
        {
            try
            {
                MySqlConnection conn = new MySqlConnection(Program.str);//实例化连接
                string sql = "set foreign_key_checks=1";
                //执行并返回是否成功
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                if (conn.State != ConnectionState.Open)
                    conn.Open();
                int count = cmd.ExecuteNonQuery();
                conn.Close();
                MessageBox.Show(count.ToString());
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void 禁用_Click(object sender, EventArgs e)
        {
            try
            {
                MySqlConnection conn = new MySqlConnection(Program.str);//实例化连接
                string sql = "set foreign_key_checks=0";
                //执行并返回是否成功
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                if (conn.State != ConnectionState.Open)
                    conn.Open();
                int count = cmd.ExecuteNonQuery();
                conn.Close();
                MessageBox.Show(count.ToString());
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void 课程浏览ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                FormCourseBrowse frm = new FormCourseBrowse();
                frm.MdiParent = this;
                frm.Show();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
        private void 课程添加ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                FormCourseAdd frm = new FormCourseAdd();
                frm.MdiParent = this;
                frm.Show();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void 课程删除ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                FormCourseDelete frm = new FormCourseDelete();
                frm.MdiParent = this;
                frm.Show();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
        private void 学生浏览ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                FormStudentBrowse frm = new FormStudentBrowse();
                frm.MdiParent = this;
                frm.Show();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void 学生添加ToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            try
            {
                FormStudentAdd frm = new FormStudentAdd();
                frm.MdiParent = this;
                frm.Show();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void 学生删除ToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            try
            {
                FormStudentDelete frm = new FormStudentDelete();
                frm.MdiParent = this;
                frm.Show();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
        private void Main_Load(object sender, EventArgs e)
        {

        }

        private void 查看成绩ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                FormScoreBrowse frm = new FormScoreBrowse();
                frm.MdiParent = this;
                frm.Show();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void 课程修改ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                FormCourceModify frm = new FormCourceModify();
                frm.MdiParent = this;
                frm.Show();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void superCourseToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                Course frm = new Course();
                frm.MdiParent = this;
                frm.Show();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void superStudentToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                Student frm = new Student();
                frm.MdiParent = this;
                frm.Show();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void 关于ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                AboutBox frm = new AboutBox();
                frm.MdiParent = this;
                frm.Show();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void 学生修改ToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            try
            {
                FormStudentModify frm = new FormStudentModify();
                frm.MdiParent = this;
                frm.Show();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}
