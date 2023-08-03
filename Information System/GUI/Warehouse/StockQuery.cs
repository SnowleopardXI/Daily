using MySql.Data.MySqlClient;
using System;
using System.Data;
using System.Windows.Forms;

namespace Warehouse
{
    public partial class StockQuery : Form
    {
        public StockQuery()
        {
            InitializeComponent();
        }

        private void Query_Click(object sender, EventArgs e)
        {
            MySqlConnection conn = new MySqlConnection(Program.str);//实例化连接
            conn.Open();//开启连接
            string sql = "";
            //判断产品号、产品名称、产品价格、仓库号是否为空
            if(Product_ID.Text==""&&Product_Name.Text==""&&Product_Price.Text==""&&Warehouse_ID.Text=="")
            {
                sql= "SELECT I.Product_Name AS '商品名', W.Warehouse_Location AS '仓库名', W.Warehouse_Contact AS '仓库联系人', I.Quantity AS '库存数量' FROM Inventory I INNER JOIN Warehouses W ON I.Warehouse_ID = W.Warehouse_ID";
            }
            else
            {
                //判断产品号是否为空
                if(Product_ID.Text!=""&&Product_Name.Text == "")
                {
                    //提示用户输入
                    MessageBox.Show("请输入产品号或产品名称！");
                }
                if (Product_ID.Text != "" && Product_Name.Text != "")
                {
                    //查询产品号和产品名称
                    sql = "SELECT I.Product_Name AS '商品名', W.Warehouse_Location AS '仓库名', W.Warehouse_Contact AS '仓库联系人', I.Quantity AS '库存数量' FROM Inventory I INNER JOIN Warehouses W ON I.Warehouse_ID = W.Warehouse_ID WHERE I.Product_ID = '" + Product_ID.Text + "' AND I.Product_Name = '" + Product_Name.Text + "'";
                }
                else
                {
                    if (Product_ID.Text != "" && Product_Name.Text == "")
                    {
                        //查询产品号
                        sql = "SELECT I.Product_Name AS '商品名', W.Warehouse_Location AS '仓库名', W.Warehouse_Contact AS '仓库联系人', I.Quantity AS '库存数量' FROM Inventory I INNER JOIN Warehouses W ON I.Warehouse_ID = W.Warehouse_ID WHERE I.Product_ID = '" + Product_ID.Text + "'";
                    }
                    else if (Product_ID.Text == "" && Product_Name.Text != "")
                    {
                        //查询产品名称
                        sql = "SELECT I.Product_Name AS '商品名', W.Warehouse_Location AS '仓库名', W.Warehouse_Contact AS '仓库联系人', I.Quantity AS '库存数量' FROM Inventory I INNER JOIN Warehouses W ON I.Warehouse_ID = W.Warehouse_ID WHERE I.Product_Name = '" + Product_Name.Text + "'";
                    }
                }
            }
            MySqlCommand cmd = new MySqlCommand(sql, conn);
            MySqlDataAdapter da = new MySqlDataAdapter(cmd);
            DataSet ds = new DataSet();
            da.Fill(ds);
            dataGridView1.DataSource = ds.Tables[0].DefaultView;
            conn.Close();
        }
    }
}
