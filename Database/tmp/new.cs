using MySql.Data.MySqlClient;
using System;
using System.Data;
using System.Windows.Forms;
#pragma warning disable CS0114 // Member hides inherited member; missing override keyword
#pragma warning disable IDE0017 // Simplify object initialization
namespace Course
{
    public partial class Course : Form
    {
        // 关闭外键检查
        readonly string FKey_off = "SET FOREIGN_KEY_CHECKS=0";
        readonly string FKey_on = "SET FOREIGN_KEY_CHECKS=1";
        public Course()
        {
            InitializeComponent();

        }
        public void Clear()
        {
            this.cno.Text = "";
            this.cname.Text = "";
            this.cpno.Text = "";
            this.ccredit.Text = "";
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
        private void Add_Click(object sender, EventArgs e)
        {
            try
            {
                // 连接数据库，假设使用名为 "connectionString" 的连接字符串
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    connection.Open();

                    // 检查课程号或课程名是否已存在
                    string checkQuery = "SELECT COUNT(*) FROM course WHERE cno = @cno OR cname = @cname";
                    using (SqlCommand checkCommand = new SqlCommand(checkQuery, connection))
                    {
                        checkCommand.Parameters.AddWithValue("@cno", cno);
                        checkCommand.Parameters.AddWithValue("@cname", cname);
                        int existingCount = (int)checkCommand.ExecuteScalar();

                        if (existingCount > 0)
                        {
                            // 课程号或课程名已存在，提示用户
                            MessageBox.Show("课程号或课程名已存在，请重新输入。");
                            return;
                        }
                    }

                    // 插入新课程
                    string insertQuery = "INSERT INTO course (cno, cname, ccredit, cpno) VALUES (@cno, @cname, @ccredit, @cpno)";
                    using (SqlCommand insertCommand = new SqlCommand(insertQuery, connection))
                    {
                        insertCommand.Parameters.AddWithValue("@cno", cno);
                        insertCommand.Parameters.AddWithValue("@cname", cname);
                        insertCommand.Parameters.AddWithValue("@ccredit", ccredit);
                        insertCommand.Parameters.AddWithValue("@cpno", cpno);
                        insertCommand.ExecuteNonQuery();
                    }

                    // 关闭连接
                    connection.Close();
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void Modify_Click(object sender, EventArgs e)
        {
            try
            {
                // 连接数据库，假设使用名为 "connectionString" 的连接字符串
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    connection.Open();

                    // 检查课程号是否存在
                    string checkQuery = "SELECT COUNT(*) FROM course WHERE cno = @cno";
                    using (SqlCommand checkCommand = new SqlCommand(checkQuery, connection))
                    {
                        checkCommand.Parameters.AddWithValue("@cno", cno);
                        int existingCount = (int)checkCommand.ExecuteScalar();

                        if (existingCount == 0)
                        {
                            // 课程号不存在，提示用户
                            MessageBox.Show("课程号不存在，请重新输入。");
                            return;
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void Delete_Click(object sender, EventArgs e)
        {
            try
            {
                // 连接数据库，假设使用名为 "connectionString" 的连接字符串
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    connection.Open();

                    // 检查课程号是否存在
                    string checkQuery = "SELECT COUNT(*) FROM course WHERE cno = @cno";
                    using (SqlCommand checkCommand = new SqlCommand(checkQuery, connection))
                    {
                        checkCommand.Parameters.AddWithValue("@cno", cno);
                        int existingCount = (int)checkCommand.ExecuteScalar();

                        if (existingCount == 0)
                        {
                            // 课程号不存在，提示用户
                            MessageBox.Show("课程号不存在，请重新输入。");
                            return;
                        }
                    }

                    // 删除课程
                    string deleteQuery = "DELETE FROM course WHERE cno = @cno";
                    using (SqlCommand deleteCommand = new SqlCommand(deleteQuery, connection))
                    {
                        deleteCommand.Parameters.AddWithValue("@cno", cno);
                        deleteCommand.ExecuteNonQuery();
                    }

                    // 关闭连接
                    connection.Close();
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
        private void Course_Load(object sender, EventArgs e)
        {

        }

        private void Query_Click_1(object sender, EventArgs e)
        {
            try
            {
                // 连接数据库，假设使用名为 "connectionString" 的连接字符串
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    connection.Open();

                    // 根据课程号或课程名进行模糊查询
                    string searchQuery = "SELECT * FROM course WHERE cno LIKE '%' + @searchKeyword + '%' OR cname LIKE '%' + @searchKeyword + '%'";
                    using (SqlCommand searchCommand = new SqlCommand(searchQuery, connection))
                    {
                        searchCommand.Parameters.AddWithValue("@searchKeyword", searchKeyword);

                        // 执行查询
                        SqlDataReader reader = searchCommand.ExecuteReader();

                        // 遍历结果集并输出课程信息
                        while (reader.Read())
                        {
                            string cno = reader.GetString(reader.GetOrdinal("cno"));
                            string cname = reader.GetString(reader.GetOrdinal("cname"));
                            int ccredit = reader.GetInt32(reader.GetOrdinal("ccredit"));
                            string cpno = reader.GetString(reader.GetOrdinal("cpno"));

                            // 在此处处理查询结果，可以将课程信息显示在界面上或进行其他操作
                            Console.WriteLine($"课程号: {cno}, 课程名: {cname}, 学分: {ccredit}, 先修课程号: {cpno}");
                        }

                        reader.Close();
                    }

                    // 关闭连接
                    connection.Close();
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

    }
}
