import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

/*
ID: chaoswo1
LANG: JAVA
TASK: transform
*/
public class transform {
	
	static class transMethods{
		
		public boolean tr1(String[]org,String[]tar){
			for(int oj=0,ti=0;oj<org.length;++oj,++ti)
				for(int oi=org.length-1,tj=0;oi>=0;--oi,++tj)
					if(org[oi].charAt(oj)!=tar[ti].charAt(tj)) return false;
				
			return true;
		}
		public boolean tr2(String[]org,String[]tar){
			for(int oi=org.length-1,ti=0;oi>=0;oi--,ti++)
				for(int oj=org.length-1,tj=0;oj>=0;oj--,tj++)
					if(org[oi].charAt(oj)!=tar[ti].charAt(tj)) return false;
			return true;
		}
		public boolean tr3(String[]org,String[]tar){
			for(int oj=0,ti=0;oj<org.length;oj++,ti++)
				for(int oi=org.length-1,tj=0;oi>=0;oi--,tj++)
					if(org[oi].charAt(oj)!=tar[ti].charAt(tj)) return false;
			return true;
		}
		public boolean tr4(String[]org,String[]tar){
			for(int oi=0,ti=0;oi<org.length;oi++,ti++)
				for(int oj=org.length-1,tj=0;oj>=0;oj--,tj++)
					if(org[oi].charAt(oj)!=tar[ti].charAt(tj)) return false;
			return true;
		}
		public boolean tr5(String[]org,String[]tar){
			
			String[]tmp=new String[org.length];
			for(int i=0;i<org.length;++i)
				tmp[i]=new StringBuffer(org[i]).reverse().toString();
			
			if(tr1(tmp, tar)) return true;
			if(tr2(tmp, tar)) return true;
			if(tr3(tmp, tar)) return true;
			
			return false;
		}
		public boolean tr6(String[]org,String[]tar){
			for(int i=0;i<org.length;++i)
				if(!org[i].equals(tar[i])) return false;
			return true;
		}
		public int getMethods(String[]org,String[]tar){
			if(tr1(org, tar)) return 1;
			if(tr2(org, tar)) return 2;
			if(tr3(org, tar)) return 3;
			if(tr4(org, tar)) return 4;
			if(tr5(org, tar)) return 5;
			if(tr6(org, tar)) return 6;
			return 7;
		}
	}
	public static void main(String[]args) throws IOException{
		BufferedReader in=new BufferedReader(new FileReader("transform.in"));
		PrintWriter out=new PrintWriter(new BufferedWriter(new FileWriter("transform.out")));
		
		int n=Integer.parseInt(in.readLine());
		String[] org=new String[n];
		String[] tar=new String[n];
		
		for(int i=0;i<n;++i)
			org[i]=in.readLine();
		for(int i=0;i<n;++i)
			tar[i]=in.readLine();
		
		transMethods tm=new transMethods();
		out.println(tm.getMethods(org, tar));
		out.close();
		System.exit(0);
	}
}
