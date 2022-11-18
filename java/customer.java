public class customer extends Thread//继承Thread类, 创建多个线程
{
    String name;
    static buy_tickets buy=new buy_tickets();
    public customer(String name) {
        this.name=name;
    }
    public void run() {
        synchronized(this.buy) {
        if(name=="Alpha") buy.chan(20,2);
        else if(name=="Beta") buy.chan(20,1);
        else if(name=="gamma") buy.chan(10,1);
        else if(name=="delta") buy.chan(10, 2);
        else if(name=="epilson") buy.chan(5,1);//调用上了互斥锁的方法来找Beta
        }
    }
   
}
