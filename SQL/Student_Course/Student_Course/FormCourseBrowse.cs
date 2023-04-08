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
    public partial class FormCourseBrowse : Form
    {
        public FormCourseBrowse()
        {
            InitializeComponent();
        }

        private void buttonQuery_Click(object sender, EventArgs e)
        {
            try
            {
                string tiaojian = " 'a'='a' ";
                string cno = this.textBoxCno.Text.Trim();
                if (cno != "")
                {
                    tiaojian += " and cno like '%" + cno + "%' ";
                }

                string cname = this.textBoxCname.Text.Trim();
                if (cname != "")
                {
                    tiaojian += " and cname like '%" + cname + "%' ";
                }


                string str = "server=" + Program.server + ";User Id=" + Program.username + ";password=" + Program.password + ";Database=" + Program.database;
                MySqlConnection conn = new MySqlConnection(str);//实例化连接
                string sql = "select * from course where " + tiaojian;
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
                string cno = this.textBoxCno.Text.Trim();
                if (cno != "")
                {
                    tiaojian += " and cno like @cno ";
                }

                string cname = this.textBoxCname.Text.Trim();
                if (cname != "")
                {
                    tiaojian += " and cname like @cname ";
                }


                string str = "server=" + Program.server + ";User Id=" + Program.username + ";password=" + Program.password + ";Database=" + Program.database;
                MySqlConnection conn = new MySqlConnection(str);//实例化连接
                string sql = "select * from course where " + tiaojian;
                MySqlDataAdapter da = new MySqlDataAdapter(sql, conn);  //数据适配器
                da.SelectCommand.Parameters.Add("@cno", MySqlDbType.String, 20).Value = "%" + cno + "%";
                da.SelectCommand.Parameters.Add("@cname", MySqlDbType.String, 20).Value = "%" + cname + "%";
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

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void textBoxCno_TextChanged(object sender, EventArgs e)
        {

        }

        private void FormCourseBrowse_Load(object sender, EventArgs e)
        {

        }
    }
}
