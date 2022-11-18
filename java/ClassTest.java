
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/**
 * @author 王庆华
 * @version 1.0
 * @date 2020/12/19 16:51
 * @Description TODO
 * @pojectname 算法代码
 */
public class ClassTest {
    public static void main(String[] args) {
        //先定义一个逆波兰表达式
        //（3+4）*5-6 ===》 3  4  +  5  *  6  -
        //为了方便，逆波兰表达式数字和符号用空格隔开
        String suffixExpression = "30 4 + 5 * 6 -";
        List<String> rpnList = getListString(suffixExpression);
        System.out.println(rpnList);
        int res = calculate(rpnList);
        System.out.println("计算结果是"+res);

    }
    //将逆波兰表达式，依次将数据和运算符放入到ArrayList中
    public static List<String> getListString(String suffixExpression){
        //分割逆波兰表达式
        String[] split = suffixExpression.split(" ");
        List<String> list = new ArrayList<>();
        for (String ele : split) {
            list.add(ele);
        }
        return list;
    }
    //将逆波兰表达式计算
    public static int calculate(List<String> ls){
        //创建一个栈 只需一个栈即可
        Stack<String> stack = new Stack<>();
        //遍历ls
        for (String item : ls) {
            //这里使用正则表达式取出数字
            if (item.matches("\\d+")){//匹配多位数
                //入栈
                stack.push(item);
            }else{
                //不是数字  pop出两个数并进行运算，在入栈
                //考虑顺序，先出来的是num2
                int num2 = Integer.parseInt(stack.pop());
                int num1 = Integer.parseInt(stack.pop());
                int res = 0;
                if (item.equals("+")){
                    res = num1 + num2;
                }else if (item.equals("-")){
                    res = num1 - num2;
                }else if (item.equals("*")){
                    res = num1 * num2;
                }else if (item.equals("/")){
                    res = num1/num2;
                }else {
                    throw new RuntimeException("运算符有误");
                }
                //把res入栈
                stack.push(res+"");
            }
        }
        //最后留在stack中的数据就是运算结果
        return Integer.parseInt(stack.pop());
    }
}
