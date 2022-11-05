class buy_tickets
{
	public static void main(String[] args) {
		new customer("Alpha").start();
		new customer("Beta").start();
		new customer("gamma").start();
		new customer("delta").start();
		new customer("epilson").start();
		}
	private static int  fivenumber=1,tennumber=0,twentynumber=0;
	private int count = 0,money=0;
	public synchronized void chan(int money,int count) {
		if (money == 20 && count == 2) {
			twentynumber++;
			if(tennumber<1)
			{
				try {
					System.out.println("Alpha wait"+" current tickets left:5dollar had"+fivenumber+",10dollar had :"+tennumber+", 20dollar had :"+twentynumber);
					this.wait();
				} catch (InterruptedException e) {}
			}
			while(tennumber<1) {
				try {
					this.wait();
				} catch (InterruptedException e) {}
			}
			tennumber--;
			notify();
			System.out.println("Should exchange Alpha 1 10dollar, Alpha ends"+"   current tickets left:5dollar had"+fivenumber+",10dollar had :"+tennumber+", 20dollar had :"+twentynumber);

		} 
		//money == 20 && count == 1
		else if (money == 20 && count == 1) {
			twentynumber++;
			if(tennumber<1||fivenumber<1)
			{try {
				System.out.println("Beta wait"+" current tickets left:5dollar had"+fivenumber+",10dollar had :"+tennumber+", 20dollar had :"+twentynumber);
				this.wait();
			} catch (InterruptedException e) {}
			}
			while(tennumber<1||fivenumber<1) {
				try {
					this.wait();
				} catch (InterruptedException e) {}
			}
			tennumber--;
			fivenumber--;
			notify();
			System.out.println("Should exchange Beta 1 10dollar、1 5dollar, Beta ends"+"   current tickets left:5dollar had"+fivenumber+",10dollar had :"+tennumber+", 20dollar had :"+twentynumber
);
		}
		//money == 10 && count == 1
		else if (money == 10 && count == 1) {
			tennumber++;
			if(fivenumber<1)
			{
				try {

					System.out.println("gamma wait"+"   current tickets left:5dollar had"+fivenumber+",10dollar had :"+tennumber+", 20dollar had :"+twentynumber);
					this.wait();
				} catch (InterruptedException e) {}
			}
			while(fivenumber<1) {
				try {
					this.wait();
				} catch (InterruptedException e) {}
			}
			fivenumber--;
			notify();
			System.out.println("Should exchange gamma 1 5dollar, gammaends"+"   current tickets left:5dollar had"+fivenumber+",10dollar had :"+tennumber+", 20dollar had :"+twentynumber);
		}
		else if (money == 10 && count == 2) {
			tennumber++;
			System.out.println("delta ends"+"   current tickets left:5dollar had"+fivenumber+",10dollar had :"+tennumber+", 20dollar had :"+twentynumber);
			notify();
		}
		else if (money == 5 && count == 1) {
			fivenumber++;
			System.out.println("epilson ends"+"   current tickets left:5dollar had"+fivenumber+",10dollar had :"+tennumber+", 20dollar had :"+twentynumber);
			notify();
		}
	}
 }
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

