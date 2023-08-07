﻿using MySql.Data.MySqlClient;
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
        public void Refresh()
        {
            this.Product_ID.Text = "";
            this.Product_Name.Text = "";
            this.Warehouse_ID.Text = "";
            dataGridView1.DataSource = null;
            dataGridView1.Rows.Clear();
            dataGridView1.Columns.Clear();
            string sql = "SELECT i.Inventory_ID AS 产品号,i.Product_Name AS 商品名 ,w.Warehouse_Name AS 仓库名,w.Warehouse_Contact AS 仓库联系人,i.Quantity AS 库存数量 FROM Inventory AS i JOIN Warehouses AS w ON i.Warehouse_ID = w.Warehouse_ID";
            MySqlConnection conn = new MySqlConnection(Program.str);//实例化连接
            conn.Open();//开启连接
            MySqlDataAdapter adapter = new MySqlDataAdapter(sql, conn);
            DataSet ds = new DataSet();
            adapter.Fill(ds);
            dataGridView1.DataSource = ds.Tables[0];
            conn.Close();
        }
        private void Query_Click(object sender, EventArgs e)
        {
            MySqlConnection conn = new MySqlConnection(Program.str);//实例化连接
            conn.Open();//开启连接
            string sql = "";
            //判断产品号、产品名称、仓库号是否为空
            if (Product_ID.Text == "" && Product_Name.Text == "" && Warehouse_ID.Text == "")
            {
                sql = "SELECT i.Inventory_ID AS 产品号,i.Product_Name AS 商品名 ,w.Warehouse_Name AS 仓库名,w.Warehouse_Contact AS 仓库联系人,i.Quantity AS 库存数量 FROM Inventory AS i JOIN Warehouses AS w ON i.Warehouse_ID = w.Warehouse_ID";
            }
            else
            {
                if(Product_ID.Text != "" && Product_Name.Text != "" && Warehouse_ID.Text != "")
                {
                    sql = "SELECT i.Inventory_ID AS 产品号,i.Product_Name AS 商品名 ,w.Warehouse_Name AS 仓库名,w.Warehouse_Contact AS 仓库联系人,i.Quantity AS 库存数量 FROM Inventory AS i JOIN Warehouses AS w ON i.Warehouse_ID = w.Warehouse_ID WHERE i.Inventory_ID = '" + Product_ID.Text + "' AND i.Product_Name = '" + Product_Name.Text + "' AND i.Warehouse_ID = '" + Warehouse_ID.Text + "'";
                }
                if(Product_ID.Text != "" && Product_Name.Text != "" && Warehouse_ID.Text == "")
                {
                    sql = "SELECT i.Inventory_ID AS 产品号,i.Product_Name AS 商品名 ,w.Warehouse_Name AS 仓库名,w.Warehouse_Contact AS 仓库联系人,i.Quantity AS 库存数量 FROM Inventory AS i JOIN Warehouses AS w ON i.Warehouse_ID = w.Warehouse_ID WHERE i.Inventory_ID = '" + Product_ID.Text + "' AND i.Product_Name = '" + Product_Name.Text + "'";
                }
                if(Product_ID.Text != "" && Product_Name.Text == "" && Warehouse_ID.Text != "")
                {
                    sql = "SELECT i.Inventory_ID AS 产品号,i.Product_Name AS 商品名 ,w.Warehouse_Name AS 仓库名,w.Warehouse_Contact AS 仓库联系人,i.Quantity AS 库存数量 FROM Inventory AS i JOIN Warehouses AS w ON i.Warehouse_ID = w.Warehouse_ID WHERE i.Inventory_ID = '" + Product_ID.Text + "' AND i.Warehouse_ID = '" + Warehouse_ID.Text + "'";
                }
                if(Product_ID.Text == "" && Product_Name.Text != "" && Warehouse_ID.Text != "")
                {
                    sql = "SELECT i.Inventory_ID AS 产品号,i.Product_Name AS 商品名 ,w.Warehouse_Name AS 仓库名,w.Warehouse_Contact AS 仓库联系人,i.Quantity AS 库存数量 FROM Inventory AS i JOIN Warehouses AS w ON i.Warehouse_ID = w.Warehouse_ID WHERE i.Product_Name = '" + Product_Name.Text + "' AND i.Warehouse_ID = '" + Warehouse_ID.Text + "'";
                }
                if(Product_ID.Text != "" && Product_Name.Text == "" && Warehouse_ID.Text == "")
                {
                    sql = "SELECT i.Inventory_ID AS 产品号,i.Product_Name AS 商品名 ,w.Warehouse_Name AS 仓库名,w.Warehouse_Contact AS 仓库联系人,i.Quantity AS 库存数量 FROM Inventory AS i JOIN Warehouses AS w ON i.Warehouse_ID = w.Warehouse_ID WHERE i.Inventory_ID = '" + Product_ID.Text + "'";
                }
                if(Product_ID.Text == "" && Product_Name.Text != "" && Warehouse_ID.Text == "")
                {
                    sql = "SELECT i.Inventory_ID AS 产品号,i.Product_Name AS 商品名 ,w.Warehouse_Name AS 仓库名,w.Warehouse_Contact AS 仓库联系人,i.Quantity AS 库存数量 FROM Inventory AS i JOIN Warehouses AS w ON i.Warehouse_ID = w.Warehouse_ID WHERE i.Product_Name = '" + Product_Name.Text + "'";
                }
                if(Product_ID.Text == "" && Product_Name.Text == "" && Warehouse_ID.Text != "")
                {
                    sql = "SELECT i.Inventory_ID AS 产品号,i.Product_Name AS 商品名 ,w.Warehouse_Name AS 仓库名,w.Warehouse_Contact AS 仓库联系人,i.Quantity AS 库存数量 FROM Inventory AS i JOIN Warehouses AS w ON i.Warehouse_ID = w.Warehouse_ID WHERE i.Warehouse_ID = '" + Warehouse_ID.Text + "'";
                }
            }
            MySqlCommand cmd = new MySqlCommand(sql, conn);
            MySqlDataAdapter da = new MySqlDataAdapter(cmd);
            DataSet ds = new DataSet();
            da.Fill(ds);
            dataGridView1.DataSource = ds.Tables[0].DefaultView;
            conn.Close();
            Refresh();
        }
    }
}