using MySql.Data.MySqlClient;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
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
                string str = "server=" + Program.server + ";User Id=" + Program.username + ";password=" + Program.password + ";Database=" + Program.database;
                MySqlConnection conn = new MySqlConnection(str);//实例化连接
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
                string str = "server=" + Program.server + ";User Id=" + Program.username + ";password=" + Program.password + ";Database=" + Program.database;
                MySqlConnection conn = new MySqlConnection(str);//实例化连接
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

    }
}
