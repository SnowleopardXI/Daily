//输入一个英文句子，重新整理该句子，将其所有单词的首字母转为大写字母，其他字母都是小写字母，输出整理后的句子。
import java.util.Scanner;
public class word_convert {
    public static void main(String[] args) {
        System.out.println("请输入一个英文句子：");
        Scanner input = new Scanner(System.in);
        String str = input.nextLine();
        String[] str1 = str.split(" ");
        System.out.println("整理后的句子为：");
        for (int i = 0; i < str1.length; i++) {
            String str2 = str1[i].substring(0, 1).toUpperCase() + str1[i].substring(1).toLowerCase();
            System.out.print(str2 + " ");
        }
    }
}