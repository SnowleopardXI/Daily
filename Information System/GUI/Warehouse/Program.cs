using System;
using System.Windows.Forms;

namespace Warehouse
{
    internal static class Program
    {
        public static string server = "127.0.0.1";
        public static string username = "root";
        public static string password = "87514813";
        public static string database = "warehouse";
        /// 定义连接字符串
        public static string str = "server=" + server + ";User Id=" + username + ";password=" + password + ";Database=" + database;
        public static string current= "";
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Login());
        }
    }
}