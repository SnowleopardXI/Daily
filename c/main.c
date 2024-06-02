#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int goods_num = 0; // 商品数量
int found = 0;     // 是否找到商品
typedef struct goods
{
    char id[6];             // 商品编号
    char name[30];          // 商品名称
    double purchasingPrice; // 商品进价
    double sellerPrice;     // 商品卖价
    int numberOfGoods;      // 商品数量
} Goods;

typedef struct cartItem
{
    char id[6]; // 商品编号
    int quantity; // 数量
} CartItem;

typedef struct shoppingCart
{
    CartItem items[100];
    int itemCount;
} ShoppingCart;

struct chaxun // 查询时引用的商品信息
{
    char id[10];
    char name[10];
} cha;

struct xiaoshou // 销售时引用的商品编号
{
    char id[6];
} sell;

// 函数声明
int welcome();
void interface_seller();
void consumer(Goods goods[], int n, ShoppingCart *cart);
void seller(Goods goods[], int *n);
int addgoods(Goods goods[], int *pn);
void change(Goods goods[], int *pn);
int delete_goods(Goods goods[], int *pn);
void show_seller(Goods goods[]);
void show_consumer(Goods goods[]);
void Chaxun_seller(Goods goods[]);
void Chaxun_consumer(Goods goods[]);
void Xiaoshou(Goods goods[]);
int LoadGoods(Goods goods[], int n);
int SaveGoods(Goods goods[], int n);
void browseCart(ShoppingCart cart);
void addToCart(ShoppingCart *cart, char id[], int quantity);
void modifyCart(ShoppingCart *cart, char id[], int quantity);
void checkout(Goods goods[], int n, ShoppingCart *cart);

int main()
{
    const char *filename = "goods.txt";

    FILE *file = fopen(filename, "r");
    if (file) {
        // File exists
        fclose(file);
    } else {
        // File does not exist, create it
        file = fopen(filename, "w");
        if (file) {
            printf("已创建: %s\n", filename);
            fclose(file);
        } else {
            printf("无法创建: %s\n", filename);
            return 0;
        }
    }
    Goods mygoods[100];
    int usertype, n;
    printf("欢迎进入超市管理系统！\n");
    usertype = welcome();
    n = LoadGoods(mygoods, 100);
    printf("%d\n", n);
    printf("商品数量：%d\n", goods_num);
    if (1 == usertype)
    {
        ShoppingCart cart;
        consumer(mygoods, n, &cart);
    }
    else
    {
        seller(mygoods, &n);
    }
    SaveGoods(mygoods, n);
    return 0;
}

// 登录
int welcome()
{
    char consumer[] = "aaa", seller[] = "bbb";
    char user[80];
    while (1)
    {
        printf("请输入您的密码：");
        scanf("%s", user);
        if (0 == strcmp(seller, user))
        {
            return 2;
        }
        else if (0 == strcmp(consumer, user))
        {
            return 1;
        }
        else
        {
            printf("抱歉！密码错误。\n");
        }
    }
}

// 加载商品信息
int LoadGoods(Goods goods[], int n)
{
    FILE *fp;
    int i, fn;
    fp = fopen("goods.txt", "r");
    if (NULL == fp)
    {
        return 0;
    }
    else
    {
        fscanf(fp, "%d", &fn);
        fn = fn < n ? fn : n;
        for (i = 0; i < fn; i++)
        {
            fscanf(fp, "%s %s %lf %lf %d", goods[i].id, goods[i].name, &goods[i].purchasingPrice, &goods[i].sellerPrice, &goods[i].numberOfGoods);
            goods_num++;
        }
        fclose(fp); // Ensure the file is closed after reading
        return fn;
    }
}

// 保存商品信息
int SaveGoods(Goods goods[], int n)
{
    FILE *fp;
    int i;
    fp = fopen("goods.txt", "w");
    if (NULL == fp)
    {
        printf("无法打开文件保存数据。\n");
        return 0;
    }
    fprintf(fp, "%d\n", n);
    for (i = 0; i < n; i++)
    {
        fprintf(fp, "%s %s %lf %lf %d\n", goods[i].id, goods[i].name, goods[i].purchasingPrice, goods[i].sellerPrice, goods[i].numberOfGoods);
    }
    fclose(fp); // Ensure the file is closed after writing
    return 1;
}
// 浏览购物车
void browseCart(ShoppingCart cart)
{
    printf("购物车内容：\n");
    for (int i = 0; i < cart.itemCount; i++)
    {
        printf("商品编号：%s, 数量：%d\n", cart.items[i].id, cart.items[i].quantity);
    }
}

// 添加商品到购物车
void addToCart(ShoppingCart *cart, char id[], int quantity)
{
    for (int i = 0; i < cart->itemCount; i++)
    {
        if (strcmp(cart->items[i].id, id) == 0)
        {
            cart->items[i].quantity += quantity;
            return;
        }
    }
    strcpy(cart->items[cart->itemCount].id, id);
    cart->items[cart->itemCount].quantity = quantity;
    cart->itemCount++;
}

// 修改购物车商品数量
void modifyCart(ShoppingCart *cart, char id[], int quantity)
{
    for (int i = 0; i < cart->itemCount; i++)
    {
        if (strcmp(cart->items[i].id, id) == 0)
        {
            cart->items[i].quantity = quantity;
            if (quantity == 0)
            {
                for (int j = i; j < cart->itemCount - 1; j++)
                {
                    cart->items[j] = cart->items[j + 1];
                }
                cart->itemCount--;
            }
            return;
        }
    }
}

// 结算
void checkout(Goods goods[], int n, ShoppingCart *cart)
{
    double total = 0.0;
    for (int i = 0; i < cart->itemCount; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (strcmp(cart->items[i].id, goods[j].id) == 0)
            {
                if (cart->items[i].quantity > goods[j].numberOfGoods)
                {
                    printf("商品 %s 库存不足。\n", goods[j].name);
                    return;
                }
                total += cart->items[i].quantity * goods[j].sellerPrice;
                goods[j].numberOfGoods -= cart->items[i].quantity;
            }
        }
    }
    printf("总金额：%.2f\n", total);
    cart->itemCount = 0;
}

// 消费者操作
void consumer(Goods goods[], int n, ShoppingCart *cart)
{
    int choice;
    while (1)
    {
        printf("消费者菜单：\n");
        printf("1. 浏览商品\n");
        printf("2. 查询商品\n");
        printf("3. 添加商品到购物车\n");
        printf("4. 修改购物车商品数量\n");
        printf("5. 浏览购物车\n");
        printf("6. 结算\n");
        printf("7. 退出\n");
        printf("请选择：");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            show_consumer(goods);
            break;
        case 2:
            Chaxun_consumer(goods);
            break;
        case 3:
        {
            char id[6];
            int quantity;
            printf("请输入商品编号：");
            scanf("%s", id);
            printf("请输入数量：");
            scanf("%d", &quantity);
            addToCart(cart, id, quantity);
            break;
        }
        case 4:
        {
            char id[6];
            int quantity;
            printf("请输入商品编号：");
            scanf("%s", id);
            printf("请输入新的数量：");
            scanf("%d", &quantity);
            modifyCart(cart, id, quantity);
            break;
        }
        case 5:
            browseCart(*cart);
            break;
        case 6:
            checkout(goods, n, cart);
            break;
        case 7:
            return;
        default:
            printf("无效选择，请重新输入。\n");
            break;
        }
    }
}
void Chaxun_consumer(Goods goods[]) // 查询输入的商品信息
{
    int c, i;
    printf("请选择查询方式\n1:编号查询\n2:名称查询\n请选择:");
    scanf("%d", &c);
    if (c == 1) // 选择编号查询
    {
        printf("请输入商品编号:");
        scanf("%s", cha.id);
        for (i = 0; i <= goods_num; i++) // 循环查询到输入的编号信息
        {
            if (strcmp(goods[i].id, cha.id) == 0)
            {
                found = 1;
                break;
            }
        }
    }
    if (c == 2) // 选择名称查询
    {
        printf("请输入商品名称:");
        scanf("%s", cha.name);
        for (i = 0; i <= goods_num; i++) // 循环查询到输入的名称信息
        {
            if (strcmp(goods[i].name, cha.name) == 0)
            {
                found = 1;
                break;
            }
        }
    }
    if (found)
    {
        printf("-------------------------------------------\n");
        printf("编号:%s\n", goods[i].id);
        printf("名称:%s\n", goods[i].name);
        printf("售价:%lf\n", goods[i].sellerPrice);
        printf("数量:%d\n", goods[i].numberOfGoods);
        printf("-------------------------------------------\n");
    }
    else
    {
        printf("没有找到商品，请按回车键返回。");
        getchar();
        getchar();
    }
    found = 0;
}

// 购买商品
void Xiaoshou(Goods goods[])
{
    char sellid[6];
    int num, i;
    double totalPrice, amountReceived;

    found = 0; // 重置found变量

    printf("请输入销售商品的ID：");
    scanf("%s", sellid);
    printf("请输入销售数量：");
    scanf("%d", &num);

    for (i = 0; i < goods_num; i++)
    {
        if (strcmp(sellid, goods[i].id) == 0)
        {
            if (goods[i].numberOfGoods >= num)
            {
                totalPrice = goods[i].sellerPrice * num;

                // 输入应收金额
                printf("应收金额为：%.2lf\n", totalPrice);
                printf("请输入收到的金额：");
                scanf("%lf", &amountReceived);

                // 检查收到的金额是否正确
                if (amountReceived >= totalPrice)
                {
                    goods[i].numberOfGoods -= num;
                    printf("销售成功！找零为：%.2lf\n", amountReceived - totalPrice);
                    found = 1;
                }
                else
                {
                    printf("收到的金额不足，销售失败！\n");
                }
                break;
            }
            else
            {
                printf("库存不足！\n");
                found = 1;
                break;
            }
        }
    }

    if (!found)
    {
        printf("未找到该商品！\n");
    }
}

void show_consumer(Goods goods[])
{ // 买家
    int i;
    for (i = 0; i < goods_num; i++)
    {
        printf("-------------------------------------------\n");
        printf("ID  名称  卖价  数量\n");
        printf("%s %s %lf %d", goods[i].id, goods[i].name, goods[i].sellerPrice, goods[i].numberOfGoods);
        printf("-------------------------------------------\n");
    }
    return;
}

// 卖家模块
void seller(Goods goods[], int *n)
{
    int c = 0;
    while (6 != c)
    {
        interface_seller();
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            addgoods(goods, n);
            break;
        case 2:
            change(goods, n);
            break;
        case 3:
            Chaxun_seller(goods);
            break;
        case 4:
            show_seller(goods);
            break;
        case 5:
            delete_goods(goods, n);
            break;
        case 6:
            printf("感谢使用本系统，再见。\n");
            break;
        default:
            printf("输入错误，请重新输入。请按任意键继续。\n");
            getchar();
            getchar();
            break;
        }
    }
}

void interface_seller()
{
    printf("+-------------------------------+\n");
    printf("|          <管理员>              |\n");
    printf("|                               |\n");
    printf("|     *请通过数字键选择操作         |\n");
    printf("|       1.添加商品信息            |\n");
    printf("|       2.修改商品信息            |\n");
    printf("|       3.查询商品信息            |\n");
    printf("|       4.查询所有商品信息         |\n");
    printf("|       5.删除商品                |\n");
    printf("|       6.退出                   |\n");
    printf("|     *请输入您的选择：            |\n");
    printf("|                               |\n");
    printf("+-------------------------------+\n");
}

// 添加商品信息
int addgoods(Goods goods[], int *pn)
{
    char newid[6] = {0};
    int i, flag = 0;

    if (100 == *pn)
    {
        printf("货架已满，无法增加新商品.请按回车键返回。\n");
        getchar();
        getchar();
        return 0;
    }
    else
    {
        while (!flag)
        {
            printf("请输入新商品ID：");
            scanf("%s", newid);
            for (i = 0; i < *pn; i++)
            {
                if (0 == strcmp(newid, goods[i].id))
                {
                    break;
                }
            }
            if (i < *pn)
            {
                printf("此ID已被占用。请按回车键重新输入序号。\n");
                getchar();
                getchar();
            }
            else
            {
                flag = 1;
                strcpy(goods[*pn].id, newid);
                printf("请输入商品的名称：");
                getchar();
                gets(goods[*pn].name);
                printf("请输入商品的进价：");
                scanf("%lf", &goods[*pn].purchasingPrice);
                printf("请输入商品的卖价：");
                scanf("%lf", &goods[*pn].sellerPrice);
                printf("请输入商品的数量：");
                scanf("%d", &goods[*pn].numberOfGoods);
                *pn += 1;
                goods_num++;
            }
        }
    }
    return 1;
}

// 修改商品信息
void change(Goods goods[], int *pn)
{
    char id[6];
    int i, choice;
    double newPurchasingPrice, newSellerPrice;
    int newNumberOfGoods;
    char newName[30];

    printf("请输入要修改的商品ID：");
    scanf("%s", id);

    for (i = 0; i < *pn; i++)
    {
        if (strcmp(goods[i].id, id) == 0)
        {
            printf("找到商品：%s\n", goods[i].name);
            printf("请选择要修改的内容：\n");
            printf("1. 修改商品名称\n");
            printf("2. 修改商品进价\n");
            printf("3. 修改商品卖价\n");
            printf("4. 修改商品数量\n");
            printf("请输入您的选择：");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                printf("请输入新的商品名称：");
                scanf("%s", newName);
                strcpy(goods[i].name, newName);
                break;
            case 2:
                printf("请输入新的商品进价：");
                scanf("%lf", &newPurchasingPrice);
                goods[i].purchasingPrice = newPurchasingPrice;
                break;
            case 3:
                printf("请输入新的商品卖价：");
                scanf("%lf", &newSellerPrice);
                goods[i].sellerPrice = newSellerPrice;
                break;
            case 4:
                printf("请输入新的商品数量：");
                scanf("%d", &newNumberOfGoods);
                goods[i].numberOfGoods = newNumberOfGoods;
                break;
            default:
                printf("无效的选择。\n");
                return;
            }

            printf("修改成功！\n");
            return;
        }
    }

    printf("未找到ID为%s的商品。\n", id);
}

// 查询商品信息
void Chaxun_seller(Goods goods[]) // 查询输入的商品信息
{
    int c, i;
    printf("请选择查询方式\n1:编号查询\n2:名称查询\n请选择:");
    scanf("%d", &c);
    if (c == 1) // 选择编号查询
    {
        printf("请输入商品编号:");
        scanf("%s", cha.id);
        for (i = 0; i <= goods_num; i++) // 循环查询到输入的编号信息
        {
            if (strcmp(goods[i].id, cha.id) == 0)
            {
                found = 1;
                break;
            }
        }
    }
    if (c == 2) // 选择名称查询
    {
        printf("请输入商品名称:");
        scanf("%s", cha.name);
        for (i = 0; i <= goods_num; i++) // 循环查询到输入的名称信息
        {
            if (strcmp(goods[i].name, cha.name) == 0)
            {
                found = 1;
                break;
            }
        }
    }
    if (found)
    {
        printf("-------------------------------------------\n");
        printf("编号:%s\n", goods[i].id);
        printf("名称:%s\n", goods[i].name);
        printf("进价:%lf\n", goods[i].purchasingPrice);
        printf("售价:%lf\n", goods[i].sellerPrice);
        printf("数量:%d\n", goods[i].numberOfGoods);
        printf("-------------------------------------------\n");
    }
    else
    {
        printf("没有找到商品，请按回车键返回。");
        getchar();
        getchar();
    }
    found = 0;
}

// 显示全部商品信息
void show_seller(Goods goods[])
{ // 卖家
    int i;
    for (i = 0; i < goods_num; i++)
    {
        printf("-------------------------------------------\n");
        printf("ID  名称  进价  卖价  数量\n");
        printf("%s %s %lf %lf %d", goods[i].id, goods[i].name, goods[i].purchasingPrice, goods[i].sellerPrice, goods[i].numberOfGoods);
        printf("-------------------------------------------\n");
    }
    return;
}

// 删除商品
int delete_goods(Goods goods[], int *pn)
{
    char newid[6];
    int flag = 0, c = 5, i, loc;
    while (!flag)
    {
        printf("请输入商品ID：");
        scanf("%s", newid);
        for (i = 0; i < *pn; i++)
        {
            if (0 == strcmp(newid, goods[i].id))
            {
                printf("ID  名称  进价  卖价  数量\n");
                printf("%s %s %lf %lf %d\n", goods[i].id, goods[i].name, goods[i].purchasingPrice, goods[i].sellerPrice, goods[i].numberOfGoods);
                break;
            }
        }
        if (i < *pn)
        {
            while (c > 2 || c < 1)
            {
                printf("是否删除上面的商品？\n");
                printf("1 删除\n2 不删除\n");
                printf("请输入数字确定您的选择：");
                scanf("%d", &c);
                switch (c)
                {
                case 1:
                    flag = 1;
                    loc = i;
                    for (; i < *pn - 1; i++)
                    {
                        goods[i] = goods[i + 1];
                    }
                    (*pn)--;
                    goods_num--;
                    printf("删除成功，请按回车键退出。");
                    getchar();
                    getchar();
                    return 1;
                case 2:
                    printf("删除失败，请按回车键退出。");
                    getchar();
                    getchar();
                    return 0;
                default:
                    printf("输入错误，请按回车键重新输入。");
                    getchar();
                    getchar();
                }
            }
        }
        else
        {
            printf("没有ID为%s的商品。请按回车键重新输入。\n", newid);
            getchar();
            getchar();
        }
    }
    return 0;
}