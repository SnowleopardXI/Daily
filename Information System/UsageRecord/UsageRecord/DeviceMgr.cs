using MySql.Data.MySqlClient;
using System;
using System.Data;
using System.Windows.Forms;

namespace UsageRecord
{
    public partial class DeviceMgr : Form
    {
        public DeviceMgr()
        {
            InitializeComponent();
        }
        public void Refresh()
        {
            id.Text = "";
            name.Text = "";
            type.Text = "";
            addr.Text = "";
            using (MySqlConnection conn = new MySqlConnection(Program.str))
            {
                conn.Open();
                string sql = "select DeviceID as 设备ID, Name as 设备名称, Type as 设备类型, Location as 设备地点 from Devices";
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                MySqlDataAdapter adapter = new MySqlDataAdapter(cmd);
                DataSet ds = new DataSet();
                adapter.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];
            }
        }
        private void query_Click(object sender, EventArgs e)
        {
            using (MySqlConnection conn = new MySqlConnection(Program.str))
            {
                conn.Open();
                string sql = "select DeviceID as 设备ID, Name as 设备名称, Type as 设备类型, Location as 设备地点 from Devices";
                if (id.Text == "" && name.Text == "" && type.Text == "" && addr.Text == "")
                {
                    MySqlCommand cmd = new MySqlCommand(sql, conn);
                    MySqlDataAdapter adapter = new MySqlDataAdapter(cmd);
                    DataSet ds = new DataSet();
                    adapter.Fill(ds);
                    dataGridView1.DataSource = ds.Tables[0];
                }
                else if (type.Text != "")
                {
                    sql += " where Type = @type";
                    MySqlCommand cmd = new MySqlCommand(sql, conn);
                    cmd.Parameters.AddWithValue("@type", type.Text);
                    MySqlDataAdapter adapter = new MySqlDataAdapter(cmd);
                    DataSet ds = new DataSet();
                    adapter.Fill(ds);
                    dataGridView1.DataSource = ds.Tables[0];
                }
                else if (addr.Text != "")
                {
                    sql += " where Location = @addr";
                    MySqlCommand cmd = new MySqlCommand(sql, conn);
                    cmd.Parameters.AddWithValue("@addr", addr.Text);
                    MySqlDataAdapter adapter = new MySqlDataAdapter(cmd);
                    DataSet ds = new DataSet();
                    adapter.Fill(ds);
                    dataGridView1.DataSource = ds.Tables[0];
                }
                else
                {
                    MessageBox.Show("请输入设备类型或设备地点");
                    return;
                }
            }
        }

        private void add_Click(object sender, EventArgs e)
        {
            if (name.Text == "" || type.Text == "" || addr.Text == "")
            {
                MessageBox.Show("请输入完整信息");
                return;
            }
            using (MySqlConnection conn = new MySqlConnection(Program.str))
            {

                conn.Open();
                string sql = "insert into Devices(Name, Type, Location) values(@name, @type, @addr)";
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                cmd.Parameters.AddWithValue("@name", name.Text);
                cmd.Parameters.AddWithValue("@type", type.Text);
                cmd.Parameters.AddWithValue("@addr", addr.Text);
                cmd.ExecuteNonQuery();
                MessageBox.Show("添加成功");
                Refresh();
            }
        }

        private void delete_Click(object sender, EventArgs e)
        {
            if (id.Text == "")
            {
                MessageBox.Show("请输入设备ID");
                return;
            }
            using (MySqlConnection conn = new MySqlConnection(Program.str))
            {

                conn.Open();
                string Usagesql = "select count(*) from Devices where DeviceID = @id";
                string sql = "delete from Devices where DeviceID = @id and Status = 0";
                MySqlCommand cmd = new MySqlCommand(Usagesql, conn);
                cmd.Parameters.AddWithValue("@id", id.Text);
                if (int.Parse(cmd.ExecuteScalar().ToString()) != 0)
                {
                    MessageBox.Show("该设备正在使用中");
                    return;
                }
                cmd = new MySqlCommand(sql, conn);
                if (int.Parse(cmd.ExecuteNonQuery().ToString()) == 0)
                {
                    MessageBox.Show("设备ID不存在");
                    return;
                }
                string disable_check = "SET FOREIGN_KEY_CHECKS = 0";
                cmd = new MySqlCommand(disable_check, conn);
                cmd.ExecuteNonQuery();
                sql = "delete from Usages where DeviceID = @id";
                cmd = new MySqlCommand(sql, conn);
                cmd.Parameters.AddWithValue("@id", id.Text);
                cmd.ExecuteNonQuery();
                string enable_check = "SET FOREIGN_KEY_CHECKS = 1";
                MessageBox.Show("删除成功");
                Refresh();
            }
        }

        private void modify_Click(object sender, EventArgs e)
        {
            if (id.Text == "")
            {
                MessageBox.Show("请输入设备ID");
                return;
            }
            if (name.Text == "" && type.Text == "" && addr.Text == "")
            {
                MessageBox.Show("请输入完整信息");
                return;
            }
            using (MySqlConnection conn = new MySqlConnection(Program.str))
            {

                conn.Open();
                string sql = "update Devices set Name = @name, Type = @type, Location = @addr where DeviceID = @id";
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                cmd.Parameters.AddWithValue("@id", id.Text);
                cmd.Parameters.AddWithValue("@name", name.Text);
                cmd.Parameters.AddWithValue("@type", type.Text);
                cmd.Parameters.AddWithValue("@addr", addr.Text);
                if (int.Parse(cmd.ExecuteNonQuery().ToString()) == 0)
                {
                    MessageBox.Show("设备ID不存在");
                    return;
                }
                MessageBox.Show("修改成功");
                Refresh();
            }
        }
    }
}
