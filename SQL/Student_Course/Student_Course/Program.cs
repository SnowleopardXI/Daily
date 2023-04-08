using System;
using System.Windows.Forms;
namespace Student_Course
{
    static class Program
    {

        /// <summary>
        /// 应用程序的主入口点。
        /// </summary>
        
        /// 定义服务器，用户名，密码，数据库名
        public static string server = "localhost";
        public static string username = "root";
        public static string password = "87514813";
        public static string database = "test";
        [STAThread]

        static void Main()
        {

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Main());
        }
    }
}
