using MySql.Data.MySqlClient;
using System;
using System.Data;
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
            string sql = "SELECT Record_ID AS '记录编号', Inventory_ID AS '产品编号', Quantity_Change AS '数量变化', Record_Time AS '记录时间', Admin_ID AS '管理员编号' FROM stock_records";
            if (operateType.Text == "不限")
            {
                sql += "";
            }
            else if (operateType.Text == "入库")
            {
                sql += " where Quantity_Change >0";
            }
            else if (operateType.Text == "出库")
            {
                sql += " where Quantity_Change <0";
            }
            MySqlDataAdapter sda = new MySqlDataAdapter(sql, conn);//使用适配器对象来填充数据集
            DataSet ds = new DataSet();//实例化数据集
            sda.Fill(ds);//填充数据集
            dataGridView1.DataSource = ds.Tables[0];//将数据集绑定到datagridview上显示出来
            conn.Close();//关闭连接
        }
    }
}
