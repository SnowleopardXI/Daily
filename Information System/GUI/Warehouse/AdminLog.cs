using MySql.Data.MySqlClient;
using System;
using System.Data;
using System.Windows.Forms;

namespace Warehouse
{
    public partial class AdminLog : Form
    {
        public AdminLog()
        {
            InitializeComponent();
        }
        private void Query_Click(object sender, EventArgs e)
        {
            // Clear the data in the table
            dataGridView1.DataSource = null;
            dataGridView1.Rows.Clear();
            dataGridView1.Columns.Clear();
            MySqlConnection conn = new MySqlConnection(Program.str);//实例化连接
            conn.Open();//开启连接
            string sql = "SELECT * FROM admin_actview ";
            if (operateType.Text == "不限")
            {
                MySqlDataAdapter da = new MySqlDataAdapter(sql, conn);
                DataSet ds = new DataSet();
                da.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];
            }
            else if (operateType.Text == "货物管理")
            {
                sql += "where 操作类型='入库' or 操作类型='出库'";
                MySqlDataAdapter da = new MySqlDataAdapter(sql, conn);
                DataSet ds = new DataSet();
                da.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];
            }
            else if (operateType.Text == "用户管理")
            {
                sql += "where 操作类型 like '%用户%'";
                MySqlDataAdapter da = new MySqlDataAdapter(sql, conn);
                DataSet ds = new DataSet();
                da.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];
            }
            else if (operateType.Text == "用户验证")
            {
                sql += "where 操作类型 like '%密码%' or 操作类型 like '%登录%'";
                MySqlDataAdapter da = new MySqlDataAdapter(sql, conn);
                DataSet ds = new DataSet();
                da.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];
            }
            else if (operateType.Text == "仓库管理")
            {
                sql += "where 操作类型 like '%仓库%'";
                MySqlDataAdapter da = new MySqlDataAdapter(sql, conn);
                DataSet ds = new DataSet();
                da.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];
            }
            else if (operateType.Text == "供应商管理")
            {
                sql += "where 操作类型 like '%供应商%'";
                MySqlDataAdapter da = new MySqlDataAdapter(sql, conn);
                DataSet ds = new DataSet();
                da.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];
            }
            conn.Close();
        }
    }
}
