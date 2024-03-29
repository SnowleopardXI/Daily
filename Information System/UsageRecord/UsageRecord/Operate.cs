﻿using MySql.Data.MySqlClient;
using System;
using System.Windows.Forms;

namespace UsageRecord
{
    public partial class Operate : Form
    {
        public Operate()
        {
            InitializeComponent();
        }

        private void book_Click(object sender, EventArgs e)
        {
            if (id.Text == "")
            {
                MessageBox.Show("请输入设备编号");
                return;
            }
            using (MySqlConnection conn = new MySqlConnection(Program.str))
            {
                conn.Open();
                string checkSql = "select count(*) from DeviceStatus where 设备ID = @id";
                string validSql = "select count(*) from DeviceStatus where 设备ID = @id and 设备状态 = '可用'";
                string bookSql = "insert into UsageRecords(DeviceID,UserID,StartTime,EndTime) values(@id,@uid,@st,@et)";
                MySqlCommand cmd = new MySqlCommand(checkSql, conn);
                cmd.Parameters.AddWithValue("@id", id.Text);
                int count = Convert.ToInt32(cmd.ExecuteScalar());
                if (count == 0)
                {
                    MessageBox.Show("设备不存在");
                    return;
                }
                cmd = new MySqlCommand(validSql, conn);
                cmd.Parameters.AddWithValue("@id", id.Text);
                count = Convert.ToInt32(cmd.ExecuteScalar());
                if (count == 0)
                {
                    MessageBox.Show("设备不可用");
                    return;
                }
                cmd = new MySqlCommand(bookSql, conn);
                cmd.Parameters.AddWithValue("@id", id.Text);
                cmd.Parameters.AddWithValue("@uid", Program.uid);
                cmd.Parameters.AddWithValue("@st", startDate.Value);
                cmd.Parameters.AddWithValue("@et", endDate.Value);
                int affectedRows = cmd.ExecuteNonQuery();
                if (affectedRows == 0)
                {
                    MessageBox.Show("租借失败");
                    return;
                }
                MessageBox.Show("租借成功\n设备编号：" + id.Text + "\n租借人：" + Program.uid + "\n开始时间：" + startDate.Value + "\n结束时间：" + endDate.Value);
            }
        }

        private void ReturnBtn_Click(object sender, EventArgs e)
        {
            using (MySqlConnection conn = new MySqlConnection(Program.str))
            {
                conn.Open();
                string checkSql = "select count(*) from UsageRecords where DATE(StartTime) = '" + startDate.Value.ToString("yyyy/MM/dd") + "' and DeviceID = " + id.Text + " and UserID = " + Program.uid + " and Status = 0";
                string returnSql = "update UsageRecords set EndTime = DATE(DATE_FORMAT(NOW(), '%Y/%m/%d %H:%i:%s')), Status =1 where DeviceID = " + id.Text + " and UserID = " + Program.uid + " and DATE(StartTime) = '" + startDate.Value.ToString("yyyy/MM/dd") + "'";
                MySqlCommand cmd = new MySqlCommand(checkSql, conn);
                String sd = startDate.Value.ToString("yyyy/MM/dd");
                String ed = endDate.Value.ToString("yyyy/MM/dd");
                cmd.Parameters.AddWithValue("@sd", "%" + sd + "%");
                MessageBox.Show(cmd.CommandText);
                int count = Convert.ToInt32(cmd.ExecuteScalar());
                if (count == 0)
                {
                    MessageBox.Show("未找到租借记录");
                    return;
                }
                cmd = new MySqlCommand(returnSql, conn);
                cmd.Parameters.AddWithValue("@sd", "%" + sd + "%");
                cmd.Parameters.AddWithValue("@et", DateTime.Now);
                int affectedRows = cmd.ExecuteNonQuery();
                if (affectedRows == 0)
                {
                    MessageBox.Show("归还失败");
                    return;
                }
                MessageBox.Show("归还成功\n设备编号：" + id.Text + "\n租借人：" + Program.uid + "\n开始时间：" + startDate.Value + "\n结束时间：" + endDate.Value);
            }
        }
    }
}