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

namespace Warehouse
{
    public partial class AdminLog : Form
    {
        public AdminLog()
        {
            InitializeComponent();
        }
        private void query_Click(object sender, EventArgs e)
        {
            // Clear the data in the table
            dataGridView1.DataSource = null;
            dataGridView1.Rows.Clear();
            dataGridView1.Columns.Clear();
            MySqlConnection conn = new MySqlConnection(Program.str);//实例化连接
            conn.Open();//开启连接
            string sql = "";
            if (operateType.Text == "不限")
            {
                sql = "select * from admin_actions";
                MySqlDataAdapter da = new MySqlDataAdapter(sql, conn);
                DataSet ds = new DataSet();
                da.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];
            }
            else if(operateType.Text == "货物管理")
            {
                sql = "select * from admin_actions where Action_Type='入库' or Action_Type='出库'";
                MySqlDataAdapter da = new MySqlDataAdapter(sql, conn);
                DataSet ds = new DataSet();
                da.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];
            }
            else if(operateType.Text == "用户管理")
            {
                sql= "select * from admin_actions where Action_Type='添加用户' or Action_Type='删除用户' or Action_Type='修改用户'";
                MySqlDataAdapter da = new MySqlDataAdapter(sql, conn);
                DataSet ds = new DataSet();
                da.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];
            }
            else if(operateType.Text == "用户验证")
            {
                sql = "select * from admin_actions where Action_Type like '%密码%' or Action_Type like '%登录%'";
                MySqlDataAdapter da = new MySqlDataAdapter(sql, conn);
                DataSet ds = new DataSet();
                da.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];
            }
            else if(operateType.Text == "仓库管理")
            {
                sql = "select * from admin_actions where Action_Type like '%仓库%'";
                MySqlDataAdapter da = new MySqlDataAdapter(sql, conn);
                DataSet ds = new DataSet();
                da.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];
            }
            else if(operateType.Text == "供应商管理")
            {
                sql = "select * from admin_actions where Action_Type like '%供应商%'";
                MySqlDataAdapter da = new MySqlDataAdapter(sql, conn);
                DataSet ds = new DataSet();
                da.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];
            }
            conn.Close();
        }
    }
}
