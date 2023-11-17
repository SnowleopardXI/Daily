using System;
using System.Windows.Forms;

namespace Users
{
    internal static class Program
    {
        public static string server = "10.40.172.1";
        public static string username = "user";
        public static string password = "123456";//678949
        public static string database = "users";
        public static string str = "server=" + server + ";User Id=" + username + ";password=" + password + ";Database=" + database;
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
