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
    public partial class WarehouseInfo : Form
    {
        public WarehouseInfo()
        {
            InitializeComponent();
        }

        private void add_Click(object sender, EventArgs e)
        {

        }

        private void delete_Click(object sender, EventArgs e)
        {

        }

        private void modify_Click(object sender, EventArgs e)
        {

        }

        private void query_Click(object sender, EventArgs e)
        {
            try
            {
                string sql = "";
                if(id.Text == "" && name.Text == "" && addr.Text == "" && contact.Text == "")
                sql= "select * from warehouses";
                else
                {
                    sql = "select * from warehouses where ";
                    if (id.Text != "")
                        sql += "id = '" + id.Text + "' and ";
                    if (name.Text != "")
                        sql += "name = '" + name.Text + "' and ";
                    if (addr.Text != "")
                        sql += "addr = '" + addr.Text + "' and ";
                    if (contact.Text != "")
                        sql += "contact = '" + contact.Text + "' and ";
                    sql = sql.Substring(0, sql.Length - 5);
                }
                MySqlConnection conn = new MySqlConnection(Program.str);
                conn.Open();
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                MySqlDataAdapter ada = new MySqlDataAdapter(cmd);
                DataSet ds = new DataSet();
                ada.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];
                conn.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}
