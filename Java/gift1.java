import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Map.Entry;
import java.util.StringTokenizer;
import java.util.Vector;

/*
ID: chaoswo1
LANG: JAVA
TASK: gift1
*/
public class gift1 {
	
	private static HashMap<String, account> people=new HashMap<String, account>();
	Vector<String> names=new Vector<String>();
	
	/**
	 * class account store the original money and the list to give money to 
	 * @author huangchao
	 *
	 */
	class account{
		private int org;
		private int num;
		private Vector<String> friends;
		public account() {
			// TODO Auto-generated constructor stub
			org=0;
			num=0;
			friends=new Vector<String>();
		}
		public void setAcc(int n){
			org=num=n;
		}
		public void addFriend(String fnameString){
			friends.add(fnameString);
		}
		public void giveMoney(){
			if(friends.isEmpty()) return;
			int m=org/friends.size();
			num-=m*friends.size();
			for (String name : friends) {
				people.get(name).getMoney(m);
			}
		}
		public void getMoney(int m){
			num+=m;
		}
		public int ans(){
			return num-org;
		}
	}
	/**
	 * input data from file gift1.in
	 * @throws IOException
	 */
	void input() throws IOException{
		BufferedReader in=new BufferedReader(new FileReader("gift1.in"));
		
		
		int NP=Integer.parseInt(in.readLine());
		for(int i=0;i<NP;++i){
			String name=in.readLine();
			names.add(name);
			people.put(name,new account());
		}
		for(int i=0;i<NP;++i){
			String name=in.readLine();
			int money,n;
			StringTokenizer st=new StringTokenizer(in.readLine());
			money=Integer.parseInt(st.nextToken());
			n=Integer.parseInt(st.nextToken());
			people.get(name).setAcc(money);
			for(int j=0;j<n;++j){
				String fname=in.readLine();
				people.get(name).addFriend(fname);
			}
			
		}
	}
	/**
	 * solve problem
	 */
	void calc(){
		Iterator it=people.values().iterator();
		while(it.hasNext()){
			account ac=(account)it.next();
			
			ac.giveMoney();
		}
	}
	/**
	 * output the answer to gift1.out
	 * @throws IOException
	 */
	void output()throws IOException{
		PrintWriter out=new PrintWriter(new BufferedWriter(new FileWriter("gift1.out")));
		for(int i=0;i<names.size();++i){
			out.print(names.get(i)+" ");
			out.println(people.get(names.get(i)).ans());
		}
		out.close();
	}
	public static void main(String[]args) throws IOException{
		gift1 g=new gift1();
		g.input();
		g.calc();
		g.output();	
		
		System.exit(0);
	}

}
