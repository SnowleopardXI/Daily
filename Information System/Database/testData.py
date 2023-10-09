#coding=utf-8
import requests
import time
import random
import faker as Faker
import pymysql

name_dict=["Ephraim", "Barnaby", "Preston", "Thaddeus", "Gideon", "Cornelius", "Horatio", "Ignatius", "Mordecai", "Alistair", "Phineas", "Reginald", "Clement", "Benedict", "Leopold", "Archibald", "Bartholomew", "Fitzgerald", "Theodorus", "Jebediah", "Montgomery", "Rutherford", "Algernon", "Humphrey", "Zebulon", "Cornelis", "Octavius", "Simeon", "Ezekiel", "Lysander", "Ferdinand", "Hezekiah", "Thelonius", "Nehemiah", "Wilberforce", "Demetrius", "Constantine", "Septimus", "Jeremiah", "Amadeus", "Eustace", "Josiah", "Malachy", "Tobias", "Barclay", "Solomon", "Roderick", "Lucius", "Ebenezer", "Augustus", "Dietrich", "Balthazar", "Hawthorne", "Maximilian", "Jedediah", "Napoleon", "Mortimer", "Harrison", "Wellington", "Zebedee", "Ulysses", "Orlando", "Fitzwilliam", "Oberon", "Quintus", "Seymour", "Ignatius", "Peregrine", "Thackeray", "Wolfgang", "Devereux", "Gulliver", "Ozymandias", "Balthasar", "Cornelius", "Barnabas", "Zachariah", "Jebediah", "Philemon", "Horace", "Leander", "Pendleton", "Cadwallader", "Maximilian", "Dionysius", "Leopold", "Roosevelt", "Hemingway", "Tiberius", "Augustine", "Beauregard", "Romulus", "Hadrian", "Sylvester", "Hamilton", "Tarquin"]
addr_dict=["Beijing","Tianjin","Hong Kong","Macau","Taiwan","Shanghai","Chongqing","Jiangsu","Zhejiang","Shandong","Guangdong","Fujian","Guangxi","Hainan","Liaoning","Jilin","Heilongjiang","Hebei","Shanxi","Shaanxi","Gansu","Qinghai","Xinjiang","Ningxia","Henan","Hubei","Hunan","Anhui","Jiangxi","Sichuan","Guizhou","Yunnan","Tibet","Inner Mongolia"]
inv_dict=["Paper","Water","Food","Medicine","Clothes","Electronic","Furniture","Car","Toy","Book","Pen","Pencil","Table","Chair","Bed","Pillow","Cup","Bowl","Spoon","Fork","Knife","Shoes","Hat","Socks","Shirt","Pants","Coat","Umbrella","Glasses","Towel","Sofa","Television","Computer","Phone","Clock","Watch","Bag","Shampoo","Soap","Toothbrush","Toothpaste","Razor","Comb","Tissue","Laptop","Keyboard","Mouse","Bookshelf","Cabinet","Draw"]

def add_admin(number):
    conn=pymysql.connect(host='10.40.172.1', port=3306, user='warehouse', password='87514813', database='warehouse', charset='utf8')
    cursor=conn.cursor()
    for i in range(number):
        type=random.randint(1,2)
        email=faker.email()
        password=faker.password()
        name=faker.name()
        phone=random.randint(13100000000,19320212368)
        sql="Insert into admins(Admin_Name,Admin_Type,Valid,Password,Email,Phone) values('%s','%s','%s',sha1('%s'),'%s','%s')"%(name,type,1,password,email,phone)
        cursor.execute(sql)
        conn.commit()
        #Print id ,password
        print('管理员名称：%s,密码：%s'%(name,password))
    print('插入成功')

def add_warehouse(number):
    conn=pymysql.connect(host='10.40.172.1', port=3306, user='warehouse', password='87514813', database='warehouse', charset='utf8')
    cursor=conn.cursor()
    sql="select Admin_ID from admins where Admin_Type=2"
    cursor.execute(sql)
    result=cursor.fetchall()
    admin_id=[]
    for i in result:
        admin_id.append(i[0])
    for i in range(number):
        location=faker.address()
        name=faker.name()
        contact=faker.name()
        sql="Call Add_Warehouse('%s','%s','%s','%s')"%(name,addr_dict[random.randint(0,len(addr_dict)-1)],contact,admin_id[random.randint(0,len(admin_id)-1)])
        cursor.execute(sql)
        conn.commit()
    print('插入成功')

def add_supplier(number):
    conn=pymysql.connect(host='10.40.172.1', port=3306, user='warehouse', password='87514813', database='warehouse', charset='utf8')
    cursor=conn.cursor()
    sql="select Admin_ID from admins where Admin_Type=2"
    cursor.execute(sql)
    result=cursor.fetchall()
    admin_id=[]
    for i in result:
        admin_id.append(i[0])
    for i in range(number):
        sql="Call Add_Suppliers('%s','%s','%s','%s')"%(faker.name(),faker.phone_number(),addr_dict[random.randint(0,len(addr_dict)-1)],admin_id[random.randint(0,len(admin_id)-1)])
        cursor.execute(sql)
        conn.commit()
    print('插入成功')

def add_inventory(number):
    conn=pymysql.connect(host='10.40.172.1', port=3306, user='warehouse', password='87514813', database='warehouse', charset='utf8')
    cursor=conn.cursor()
    #从warehouses表中随机选取
    sql="select Warehouse_ID from warehouses"
    cursor.execute(sql)
    result=cursor.fetchall()
    warehouse_id=[]
    for i in result:
        warehouse_id.append(i[0])
    sql="select Admin_ID from admins where Admin_Type=2"
    cursor.execute(sql)
    result=cursor.fetchall()
    admin_id=[]
    for i in result:
        admin_id.append(i[0])
    sql="select Supplier_Name from suppliers"
    cursor.execute(sql)
    result=cursor.fetchall()
    supplier_name=[]
    for i in result:
        supplier_name.append(i[0])
    for i in range(number):
        warehouse=random.choice(warehouse_id)
        amount=random.randint(1,100)
        sql="Call Add_Inventory('%s','%s','%s','%s','%s')"%(inv_dict[random.randint(0,len(inv_dict)-1)],supplier_name[random.randint(0,len(supplier_name)-1)],warehouse,amount,admin_id[random.randint(0,len(admin_id)-1)])
        cursor.execute(sql)
        conn.commit()
    print('插入成功')

def update_Admin(number):
    conn=pymysql.connect(host='10.40.172.1', port=3306, user='warehouse', password='87514813', database='warehouse', charset='utf8')
    cursor=conn.cursor()
    sql="select Admin_ID from admins where Admin_Type=2"
    cursor.execute(sql)
    result=cursor.fetchall()
    superadmin_id=[]
    for i in result:
        superadmin_id.append(i[0])
    sql="select Admin_ID from admins where Admin_Type=1"
    cursor.execute(sql)
    result=cursor.fetchall()
    admin_id=[]
    for i in result:
        admin_id.append(i[0])
    for i in range(number):
        mod_id=random.randint(2,(len(superadmin_id)-1))
        sql="Call Update_Admin('%s','%s','%s','%s','%s','%s','%s')"%(superadmin_id[random.randint(2,(len(superadmin_id)-1))],mod_id,name_dict[random.randint(0,len(name_dict)-1)],random.randint(0,1),random.randint(1,2),faker.email(),random.randint(13100000000,19320212368))
        cursor.execute(sql)
        conn.commit()
    print('更新成功')

def update_Supplier(number):
    conn=pymysql.connect(host='10.40.172.1', port=3306, user='warehouse', password='87514813', database='warehouse', charset='utf8')
    cursor=conn.cursor()
    sql="select Admin_ID from admins where Admin_Type=2"
    cursor.execute(sql)
    result=cursor.fetchall()
    superadmin_id=[]
    for i in result:
        superadmin_id.append(i[0])
    sql="select Supplier_Name from suppliers"
    cursor.execute(sql)
    result=cursor.fetchall()
    supplier_name=[]
    for i in result:
        supplier_name.append(i[0])
    sql="select Supplier_ID from suppliers"
    cursor.execute(sql)
    result=cursor.fetchall()
    supplier_id=[]
    for i in result:
        supplier_id.append(i[0])
    for i in range(number):
        #在原始供应商名称后追加随机数
        id=random.randint(0,len(supplier_name)-1)
        mod_name=supplier_name[id]+str(random.randint(0,100))
        sql="Call Update_Supplier('%s','%s','%s','%s','%s')"%(supplier_id[id],mod_name,faker.phone_number(),addr_dict[random.randint(0,len(addr_dict)-1)],superadmin_id[random.randint(1,(len(superadmin_id)-1))])
        cursor.execute(sql)
        conn.commit()
    print('更新成功')

def update_Warehouse(number):
    conn=pymysql.connect(host='10.40.172.1', port=3306, user='warehouse', password='87514813', database='warehouse', charset='utf8')
    cursor=conn.cursor()
    sql="select Admin_ID from admins where Admin_Type=2"
    cursor.execute(sql)
    result=cursor.fetchall()
    superadmin_id=[]
    for i in result:
        superadmin_id.append(i[0])
    sql="select Warehouse_ID from warehouses"
    cursor.execute(sql)
    result=cursor.fetchall()
    warehouse_id=[]
    for i in result:
        warehouse_id.append(i[0])
    sql="select Warehouse_Name from warehouses"
    cursor.execute(sql)
    result=cursor.fetchall()
    warehouse_name=[]
    for i in result:
        warehouse_name.append(i[0])
    for i in range(number):
        #在原始仓库名称后追加随机数
        id=random.randint(0,len(warehouse_name)-1)
        mod_name=warehouse_name[id]+str(random.randint(0,100))
        sql="Call Update_Warehouse('%s','%s','%s','%s','%s')"%(warehouse_id[id],mod_name,addr_dict[random.randint(0,len(addr_dict)-1)],faker.name(),superadmin_id[random.randint(1,(len(superadmin_id)-1))])
    print('更新成功')
    
def delete_Admin(number):
    conn=pymysql.connect(host='10.40.172.1', port=3306, user='warehouse', password='87514813', database='warehouse', charset='utf8')
    cursor=conn.cursor()
    sql="select Admin_ID from admins where Admin_ID>=2"
    cursor.execute(sql)
    result=cursor.fetchall()
    admin_id=[]
    for i in result:
        admin_id.append(i[0])
    for i in range(number):
        sql="Call Delete_Admin('%s','%s')"%(1,admin_id[random.randint(0,len(admin_id)-1)])
        cursor.execute(sql)
        conn.commit()
    print('删除成功')
        
def delete_Supplier(number):
    conn=pymysql.connect(host='10.40.172.1', port=3306, user='warehouse', password='87514813', database='warehouse', charset='utf8')
    cursor=conn.cursor()
    sql="select Admin_ID from admins where Admin_Type=2"
    cursor.execute(sql)
    result=cursor.fetchall()
    superadmin_id=[]
    for i in result:
        superadmin_id.append(i[0])
    sql="select Supplier_ID from suppliers"
    cursor.execute(sql)
    result=cursor.fetchall()
    supplier_id=[]
    for i in result:
        supplier_id.append(i[0])
    for i in range(number):
        sql="Call Delete_Supplier('%s','%s')"%(supplier_id[random.randint(0,len(supplier_id)-1)],superadmin_id[random.randint(1,(len(superadmin_id)-1))])
        cursor.execute(sql)
        conn.commit()
    print('删除成功')
        
def clear():
    conn=pymysql.connect(host='10.40.172.1', port=3306, user='warehouse', password='87514813', database='warehouse', charset='utf8')
    cursor=conn.cursor()
    sql="SET FOREIGN_KEY_CHECKS = 0"
    cursor.execute(sql)
    sql="TRUNCATE TABLE admins"
    cursor.execute(sql)
    sql="TRUNCATE TABLE suppliers"
    cursor.execute(sql)
    sql="TRUNCATE TABLE warehouses"
    cursor.execute(sql)
    sql="TRUNCATE TABLE inventory"
    cursor.execute(sql)
    sql="TRUNCATE TABLE stock_records"
    cursor.execute(sql)
    sql="TRUNCATE TABLE admin_actions"
    cursor.execute(sql)
    sql="INSERT INTO admins(Admin_Name,Admin_Type,Valid,Password,Email,Phone) VALUES('root',2,1,sha1('123456'),'root@localhost',13100000000)"
    cursor.execute(sql)
    sql="SET FOREIGN_KEY_CHECKS = 1"
    cursor.execute(sql)
    conn.commit()
    
if __name__ == "__main__":
    faker=Faker.Faker()
    clear()
    #连接数据库
    conn=pymysql.connect(host='10.40.172.1', port=3306, user='warehouse', password='87514813', database='warehouse', charset='utf8')
    cursor=conn.cursor()
    print('连接成功')
    print('开始插入数据')
    print('请选择类型：1.处理管理员    2.处理其他数据')
    if int(input())==1:
        print('请输入数量：')
        number=int(input())
        add_admin(number)
    else:
        print('即将开始插入数据')
        print('请输入范围：')
        min=int(input())
        max=int(input())
        add_admin(random.randint(min,max))
        add_warehouse(random.randint(min,max))
        add_supplier(random.randint(min,max))
        add_inventory(random.randint(min,max))
        update_Admin(random.randint(min,max))
        update_Supplier(random.randint(min,max))
        update_Warehouse(random.randint(min,max))
        delete_Admin(random.randint(min,max))