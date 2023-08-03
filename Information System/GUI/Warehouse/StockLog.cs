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
    public partial class StockLog : Form
    {
        public StockLog()
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
                sql = "select * from stock_records";
            }
            else if (operateType.Text == "入库")
            {
                sql = "select * from stock_records where Quantity_Change <0";
            }
            else if (operateType.Text == "出库")
            {
                sql = "select * from stock_records where Quantity_Change >0";
            }
            MySqlDataAdapter sda = new MySqlDataAdapter(sql, conn);//使用适配器对象来填充数据集
            DataSet ds = new DataSet();//实例化数据集
            sda.Fill(ds);//填充数据集
            dataGridView1.DataSource = ds.Tables[0];//将数据集绑定到datagridview上显示出来
            conn.Close();//关闭连接
        }
    }
}
