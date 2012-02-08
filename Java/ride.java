

/*
ID: chaoswo1
LANG: JAVA
TASK: ride
*/
import java.io.*;
import java.util.*;

public class ride {
	
	static int getMod(String str){
		
		int res=1;
		for(int i=0;i<str.length();++i){
			res*=str.charAt(i)-'A'+1;
			res%=47;
			System.out.println(res);
		}
		System.out.println();
		return res;		
	}
	public static void main (String [] args) throws IOException {
		// Use BufferedReader rather than RandomAccessFile; it's much faster
		BufferedReader f = new BufferedReader(new FileReader("ride.in"));
		// input file name goes above
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("ride.out")));
		
		String comet=f.readLine();
		String group=f.readLine();
		
		if(getMod(comet)!=getMod(group)){
			out.println("STAY");
		}
		else out.println("GO");
		
		out.close();
		System.exit(0);                               // don't omit this!
  }
}

