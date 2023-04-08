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
    public partial class FormStudentAdd : Form
    {
        public FormStudentAdd()
        {
            InitializeComponent();
        }

        private void FormStudentAdd_Load(object sender, EventArgs e)
        {

        }

        private void sno_TextChanged(object sender, EventArgs e)
        {

        }

        private void ssex_TextChanged(object sender, EventArgs e)
        {

        }

        private void sname_TextChanged(object sender, EventArgs e)
        {

        }

        private void sage_TextChanged(object sender, EventArgs e)
        {

        }

        private void sdept_TextChanged(object sender, EventArgs e)
        {

        }

        private void Add_Click(object sender, EventArgs e)
        {
            try
            {
                string sno = this.sno.Text.Trim();
                string sname = this.sname.Text.Trim();
                string Ssex = this.ssex.Text.Trim();
                string sage = this.sage.Text.Trim();
                string sdept = this.sdept.Text.Trim();
                string str = "server=" + Program.server + ";User Id=" + Program.username + ";password=" + Program.password + ";Database=" + Program.database;

                MySqlConnection conn = new MySqlConnection(str);//实例化连接
                //判断sno是否存在
                string sql = "select * from student where sno = '" + sno + "'";
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                conn.Open();
                MySqlDataReader reader = cmd.ExecuteReader();
                if (reader.Read())
                {
                    MessageBox.Show("学生号已存在！");
                    return;
                }
                reader.Close();
                //插入数据
                sql = "insert into student values('" + sno + "','" + sname + "','" + Ssex + "','" + sage + "','" + sdept + "')";
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
    }
    
}
