using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using MySql.Data.MySqlClient;
using MySql.Data.Types;

namespace Student_Course
{
	public partial class FormStudentBrowse : Form
	{
        public FormStudentBrowse()
		{
			InitializeComponent();
		}

		private void buttonQuery_Click(object sender, EventArgs e)
		{
			try
			{
				string tiaojian = " 'a'='a' ";
				string sno = this.textBoxSno.Text.Trim();
				if (sno != "")
				{
					tiaojian += " and sno like '%" + sno + "%' "; 
				}
				
				string sname = this.textBoxSname.Text.Trim();
				if (sname != "")
				{
					tiaojian += " and sname like '%"+ sname +"%' ";
				}

                string str = "server=" + Program.server + ";User Id=" + Program.username + ";password=" + Program.password + ";Database=" + Program.database;
                MySqlConnection conn = new MySqlConnection(str);//实例化连接
				string sql = "select * from student where " + tiaojian ;
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

		private void buttonQuery2_Click(object sender, EventArgs e)
		{
			try
			{
				string tiaojian = " 'a'='a' ";
				string sno = this.textBoxSno.Text.Trim();
				if (sno != "")
				{
					tiaojian += " and sno like @sno ";
				}

				string sname = this.textBoxSname.Text.Trim();
				if (sname != "")
				{
					tiaojian += " and sname like @sname ";
				}

                string str = "server=" + Program.server + ";User Id=" + Program.username + ";password=" + Program.password + ";Database=" + Program.database;
                MySqlConnection conn = new MySqlConnection(str);//实例化连接
				string sql = "select * from student where " + tiaojian;
				MySqlDataAdapter da = new MySqlDataAdapter(sql, conn);  //数据适配器
				da.SelectCommand.Parameters.Add("@sno", MySqlDbType.String, 20).Value = "%" + sno + "%";
				da.SelectCommand.Parameters.Add("@sname", MySqlDbType.String, 20).Value = "%" + sname + "%";
				DataTable dt = new DataTable();   //数据表
				da.Fill(dt);   //执行sql，将数据填入数据表
				dataGridView1.DataSource = dt;  //将数据表绑定到dataGridView1上，显示出来
				
			}
			catch (Exception ex)
			{
					MessageBox.Show(ex.Message);
			}
		}

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void splitContainer1_Panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void textBoxSno_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBoxSname_TextChanged(object sender, EventArgs e)
        {

        }

        private void FormStudentBrowse_Load(object sender, EventArgs e)
        {

        }
    }
}
